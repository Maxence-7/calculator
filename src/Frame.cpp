#include <iostream>
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
    gridB.attach_next_to(entryField,*buttons[0],Gtk::PositionType::POS_TOP,4,1);
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
    entryField.set_text(data);
    switch (data.data()[0]) {
    case '=':
        break;
    case '+':
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
        break;
    case '.':
        break;
    default:
        break;
    }
}