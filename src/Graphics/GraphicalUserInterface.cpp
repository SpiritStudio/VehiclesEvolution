//
// Created by SpiritStudio on 03.12.18.
//

#include <Graphics/GraphicalUserInterface.h>

GraphicalUserInterface::GraphicalUserInterface(sf::RenderWindow &window) : gui_(window) {
    // example of adding gui elements
    auto button = tgui::Button::create("CLICK");
    button->setSize({"50%", "16.67%"});
    button->setPosition({"25%", "70%"});
    gui_.add(button);
//    example callback function connection
//    button->connect("pressed", login, editBoxUsername, editBoxPassword);
}

bool GraphicalUserInterface::handleEvent(sf::Event event){
    return gui_.handleEvent(event);
}

void GraphicalUserInterface::draw() {
    gui_.draw();
}