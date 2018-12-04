//
// Created by SpiritStudio on 03.12.18.
//

#include <Graphics/GraphicalUserInterface.h>

bool GraphicalUserInterface::handleEvent(sf::Event &event){
    return gui_.handleEvent(event);
}

void GraphicalUserInterface::setWindow(sf::RenderWindow &window) {
    gui_.setTarget(window);
}

void GraphicalUserInterface::addButton(const std::string &text) {
    auto button = tgui::Button::create(text);
    button->setSize({"20%", "5%"});
    button->setPosition({"5%", "5%"});
    gui_.add(button);
}

void GraphicalUserInterface::draw() {
    gui_.draw();
}