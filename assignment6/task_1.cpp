#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

/**
 * The row of letters for the chess board console printout.
 */
const string ROW_LETTERS = "a b c d e f g h";

class ChessBoard {
public:
    enum class Color {
        WHITE,
        BLACK,
    };

    class Piece {
    public:
        explicit Piece(Color color) : color(color) {}

        virtual ~Piece() = default;

        const Color color;

        std::string color_string() const {
            return color == Color::WHITE ? "white" : "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        /**
         * Returns the string to display in the console printout.
         */
        virtual std::string display() const = 0;
    };

    class King : public Piece {
    public:
        explicit King(Color color) : Piece(color) {}

        string type() const override {
            return color_string() + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            const int dxLength = max(from_x, to_x) - min(from_x, to_x);
            const int dyLength = max(from_y, to_y) - min(from_y, to_y);

            if (dxLength > 1 || dyLength > 1) {
                return false;
            }
            return true;
        }

        string display() const override {
            switch (color) {
                case Color::WHITE:
                    return "♔";
                case Color::BLACK:
                    return "♚";
                default:
                    return "?";
            }
        }
    };

    class Knight : public Piece {
    public:
        explicit Knight(Color color) : Piece(color) {}

        string type() const override {
            return color_string() + " knight";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            const int dxLength = max(from_x, to_x) - min(from_x, to_x);
            const int dyLength = max(from_y, to_y) - min(from_y, to_y);

            if (dxLength == 0 || dyLength == 0) {
                return false;
            }
            if (dxLength > 2 || dyLength > 2) {
                return false;
            }
            if (dxLength + dyLength > 3) {
                return false;
            }

            return true;
        }

        string display() const override {
            switch (color) {
                case Color::WHITE:
                    return "♘";
                case Color::BLACK:
                    return "♞";
                default:
                    return "?";
            }
        }
    };

    class ChessBoardPrint {
        public:
            explicit ChessBoardPrint(ChessBoard &board) {

                board.on_piece_move = [](const Piece &piece, const string &from, const string &to) {
                    cout << piece.type() << " is moving from " << from << " to " << to << endl;
                };

                board.on_piece_removed = [](const Piece &piece, const string &to) {
                    cout << piece.type() << " is being removed from " << to << endl;
                };

                board.on_lost_game = [](Color color) {
                    cout << (color == ChessBoard::Color::BLACK ? "black" : "white");
                    cout << " lost the game" << endl;
                };

                board.on_piece_move_invalid = [](const Piece &piece, const string &from, const string &to) {
                    cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
                };

                board.on_piece_move_missing = [](const string &from) {
                    cout << "no piece at " << from << endl;
                };

                board.after_piece_move = [](auto &_squares) {
                    cout << "  " << ROW_LETTERS << endl;
                    auto i = _squares.size();
                    while (i > 0) {
                        cout << i << " ";
                        for (size_t j = 0; j < _squares[i - 1].size(); j++) {
                            const auto &piece = _squares[j][i - 1];
                            if (piece) {
                                cout << piece -> display() << " ";
                            }
                            else {
                                cout << "- ";
                            }
                        }
                        cout << " " << i << endl;
                        i--;
                    }
                    cout << "  " << ROW_LETTERS << endl;
                };
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column: squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    /// Prints the chess board to the console.
    function<void(vector<vector<unique_ptr<Piece>>> &squares)> after_piece_move;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                if (on_piece_move) {
                    on_piece_move(*piece_from, from, to);
                }
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (on_piece_removed) {
                            on_piece_removed(*piece_to, to);
                        }
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (on_lost_game) {
                                on_lost_game(king->color);
                            }
                        }
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        if (on_piece_move_invalid) {
                            on_piece_move_invalid(*piece_from, from, to);
                        }
                        return false;
                    }
                }
                piece_to = std::move(piece_from);
                if (after_piece_move) {
                    after_piece_move(squares);
                }
                return true;
            } else {
                if (on_piece_move_invalid) {
                    on_piece_move_invalid(*piece_from, from, to);
                }
                return false;
            }
        } else {
            if (on_piece_move_missing) {
                on_piece_move_missing(from);
            }
            return false;
        }
    }
};

int main() {
    ChessBoard board;
    ChessBoard::ChessBoardPrint print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");

    return 0;
}

/*
Correct printout:
Invalid moves:
no piece at e3
can not move white king from e1 to e3
can not move white knight from b1 to b2

A simulated game:
white king is moving from e1 to e2
black knight is moving from g8 to h6
white knight is moving from b1 to c3
black knight is moving from h6 to g8
white knight is moving from c3 to d5
black knight is moving from g8 to h6
white knight is moving from d5 to f6
black knight is moving from h6 to g8
white knight is moving from f6 to e8
black king is being removed from e8
black lost the game
*/
