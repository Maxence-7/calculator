#ifndef DEF_FRAME
#define DEF_FRAME

#include <vector>

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>

class Frame : public Gtk::Window {
    public :
        Frame();
        ~Frame();
        void on_button_numbered(const Glib::ustring& data);
    
    private :
        double numberMemory = 0;
        bool decimal = false;
        bool isMem = false;
        char operationMemory = '?';
        Gtk::Grid gridB;
        char symbols[16] = {'7','8','9','+','4','5','6','-','1','2','3','*','0','.','=','/'};
        std::vector<Gtk::Button*> buttons;
        Gtk::Entry entryField;
        Gtk::Label memText;
};

#endif