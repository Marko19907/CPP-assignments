#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Label nameLabel;
    Gtk::Entry nameEntry;
    Gtk::Label lastNameLabel;
    Gtk::Entry lastNameEntry;
    Gtk::Button button;
    Gtk::Label resultLabel;

    /**
     * Enables/disables the button based on the name and last name inputs.
     */
    void updateButton() {
        if (nameEntry.get_text().empty() || lastNameEntry.get_text().empty()) {
            button.set_sensitive(false);
        }
        else {
            button.set_sensitive(true);
        }
    }

    Window() {
        button.set_label("Combine names");
        button.set_sensitive(false);
        nameLabel.set_text("First name");
        lastNameLabel.set_text("Last name");

        vbox.pack_start(nameLabel);
        vbox.pack_start(nameEntry);
        vbox.pack_start(lastNameLabel);
        vbox.pack_start(lastNameEntry);
        vbox.pack_start(button);
        vbox.pack_start(resultLabel);

        Window::add(vbox);
        show_all();

        nameEntry.signal_changed().connect([this]() {
            updateButton();
        });

        lastNameEntry.signal_changed().connect([this]() {
            updateButton();
        });

        button.signal_clicked().connect([this]() {
            resultLabel.set_text(nameEntry.get_text() + " " + lastNameEntry.get_text());
        });
    }
};

int main() {
    Gtk::Main gtk_main;
    Window window;
    window.set_title("Øving 4");
    Gtk::Main::run(window);
}
