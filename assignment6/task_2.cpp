#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

const int PORT = 8080;

class WebServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(const shared_ptr<Connection> &connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if (!ec) {
                                 // Retrieve message from client as string:
                                 istream read_stream(read_buffer.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back(); // Remove "\r" at the end of message

                                 // Close connection when "exit" is retrieved from client
                                 if (message == "exit") {
                                     return;
                                 }

                                 cout << "Message from a connected client: " << message << endl;

                                 std::string response = getResponse(message);

                                 auto write_buffer = make_shared<boost::asio::streambuf>();
                                 ostream write_stream(write_buffer.get());

                                 // Add message to be written to client:
                                 write_stream << response << "\r\n";

                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                                 // If not error:
                                                 if (!ec)
                                                     handle_request(connection);
                                                 // Close the socket
                                                 connection->socket.close();
                                             });
                             }
                         });
    }

    /**
     * Returns the response for the given message.
     */
    static string getResponse(const std::string &message) {
        if (message == "GET / HTTP/1.1") {
            return "Dette er hovedsiden";
        }
        else if (message == "GET /en_side HTTP/1.1") {
            return "Dette er en side";
        }
        else {
            return "HTTP/1.1 404 Not Found \r\n";
        }
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    WebServer() : endpoint(tcp::v4(), PORT), acceptor(io_service, endpoint) {};

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
    WebServer webServer;

    cout << "Starting the web server . . ." << endl;

    webServer.start();
}
