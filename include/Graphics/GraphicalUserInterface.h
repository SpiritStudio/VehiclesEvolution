//
// Created by SpiritStudio on 03.12.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
#define VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H

#include <string>
#include <functional>

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class GraphicalUserInterface {

public:
    explicit GraphicalUserInterface(sf::RenderWindow &window, const int interface_width, const int interface_height);
    void setWindow();
    void setView(sf::View &view);
    void addButtons();
    bool handleEvent(sf::Event &event);
    void draw();

    const int getInterfaceWidth() const;

private:
    void addButton(const std::string &text, std::function<void()> function);

    const int interface_width_, interface_height_;

    const sf::Color background_color_;

    sf::RenderWindow &window_;
    tgui::Gui gui_;
    sf::RectangleShape background_;
};


#endif //VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
