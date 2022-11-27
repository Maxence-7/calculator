#include <iostream>
#include <gtkmm/main.h>
#include "Frame.hpp"

int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Frame frame;
    Gtk::Main::run(frame);
    return 0;
}