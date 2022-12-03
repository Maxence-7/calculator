#ifndef DEF_FRAME
#define DEF_FRAME

#include <vector>

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>

/**
 * @file Frame.hpp
 * @brief Frame object
 * @date December 2022
 * @author Maxence Leguéry
 * @Maxence-7
 */
class Frame : public Gtk::Window {
    public :
        /**
         * @brief Construct a new Frame object
         */
        Frame();
        /**
         * @brief Destroy the Frame object
         * @brief Deleting the allocation for the buttons
         */
        ~Frame();
        /** 
        * @brief Function executed when a button is push
        * @param data Glib::ustring containing one of the char 0,1,2,3,4,5,6,7,8,9,+,-,*,/,=,.
        */
        void on_button_numbered(const Glib::ustring& data);
    
    private :
        /**
         * @brief Variable storing the first term of the calculation
         */
        double numberMemory = 0;
        /**
         * @brief Is the number decimal ?
         * 
         */
        bool decimal = false;
        /**
         * @brief Is their something important stored in numberMemory
         */
        bool isMem = false;
        /**
         * @brief Variable storing the operation to do
         */
        char operationMemory = '?';
        /**
         * @brief Gtk::Grid to place all the Gtk::Widget in the window
         */
        Gtk::Grid gridB;
        /**
         * @brief Array with all the possible symbols on button
         * @brief Order for proper layout
         */
        char symbols[16] = {'7','8','9','+','4','5','6','-','1','2','3','*','0','.','=','/'};
        /**
         * @brief std::vector storing the addresses of the 16 buttons
         */
        std::vector<Gtk::Button*> buttons;
        /**
         * @brief Text area for current term
         * @todo Add the possibility to modify it directly
         */
        Gtk::Entry entryField;
        /**
         * @brief Text area for the memory
         */
        Gtk::Label memText;
        /**
         * @brief Text area for the author
         */
        Gtk::Label author;
};

#endif