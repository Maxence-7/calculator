#include <iostream>
#include <string>
#include "Frame.hpp"

using namespace std;

Frame::Frame() {
    set_title("Calculator");
    set_border_width(10);
    add(gridB);

    int i = 0;
    int j = -1;
    for (int k=0;k<16;k++) {
        Gtk::Button* button = new Gtk::Button(Glib::ustring(1,symbols[k]));
        (*button).signal_clicked().connect(sigc::bind( sigc::mem_fun(*this, &Frame::on_button_numbered), Glib::ustring(1,symbols[k])));
        (*button).set_can_focus(false);
        i=k%4;
        if (i==0) { j++; }
        gridB.attach(*button,i,j);
        (*button).show();

        buttons.push_back(button);
    }
    entryField.show();
    entryField.set_text("");
    memText.show();
    gridB.attach_next_to(entryField,*buttons[0],Gtk::PositionType::POS_TOP,4,1);
    gridB.attach_next_to(memText,entryField,Gtk::PositionType::POS_TOP,4,1);
    gridB.show();
}

Frame::~Frame() {
    auto it = buttons.begin();
    for (;it!=buttons.end();it++) {
        delete *it;
    }
}

void Frame::on_button_numbered(const Glib::ustring& data) {
    std::cout << data << " was pressed" << std::endl;
    //entryField.set_text(data);
    switch (data.data()[0]) {
    case '=':
        if (operationMemory != '?' && entryField.get_text() != "") {
            switch (operationMemory) {
            case '+':
                numberMemory += stod(std::string(entryField.get_text()));
                break;
            case '-':
                numberMemory -= stod(std::string(entryField.get_text()));
                break;
            case '*':
                numberMemory *= stod(std::string(entryField.get_text()));
                break;
            case '/':
                numberMemory /= stod(std::string(entryField.get_text()));
                break;
            
            default:
                break;
            }
            memText.set_text(std::to_string(numberMemory));
            entryField.set_text("");
            isMem = true;
        }
        break;
    case '+':
    case '-':
    case '*':
    case '/':
        if (isMem && entryField.get_text() == "") {
            operationMemory = data.data()[0];
            memText.set_text(std::to_string(numberMemory)+operationMemory);
        } else if (entryField.get_text() != "") {
            operationMemory = data.data()[0];
            numberMemory = stod(std::string(entryField.get_text()));
            memText.set_text(entryField.get_text()+operationMemory);
            entryField.set_text("");
        } else {
            break;
        }
        break;
    case '.':
        if (!decimal) {
            decimal = true;
            entryField.set_text(entryField.get_text() + ",");
        }
        break;
    default:
        entryField.set_text(entryField.get_text() + data);
        break;
    }
}