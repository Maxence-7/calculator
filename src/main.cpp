#include <iostream>
#include <gtkmm/main.h>
#include "Frame.hpp"

int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Frame fenetre;
    Gtk::Main::run(fenetre);
    return 0;
}