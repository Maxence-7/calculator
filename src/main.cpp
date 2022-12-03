#include <iostream>
#include <gtkmm/main.h>
#include "Frame.hpp"

/**
 * @brief Main function of the application
 * 
 * @param argc 
 * @param argv 
 * @return 0 if every thing was all right 
 */
int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Frame frame;
    Gtk::Main::run(frame);
    return 0;
}