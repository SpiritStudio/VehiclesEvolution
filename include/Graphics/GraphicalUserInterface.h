//
// Created by SpiritStudio on 03.12.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
#define VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H

#include <string>

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class GraphicalUserInterface {

public:
   explicit GraphicalUserInterface() = default;
   void setWindow(sf::RenderWindow &window);
   void addButton(const std::string &text);
   bool handleEvent(sf::Event &event);
   void draw();

private:
    tgui::Gui gui_;

};


#endif //VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
