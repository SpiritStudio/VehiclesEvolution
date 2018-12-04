//
// Created by SpiritStudio on 03.12.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
#define VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class GraphicalUserInterface {

public:
   explicit GraphicalUserInterface(sf::RenderWindow&);
   bool handleEvent(sf::Event);
   void draw();

private:
    tgui::Gui gui_;

};


#endif //VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
