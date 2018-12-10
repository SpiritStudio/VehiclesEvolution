//
// Created by SpiritStudio on 03.12.18.
//

#include <Graphics/GraphicalUserInterface.h>

GraphicalUserInterface::GraphicalUserInterface(sf::RenderWindow &window, const int interface_width,
                                               const int interface_height)
    : window_(window), interface_width_(interface_width), interface_height_(interface_height) {
    background_.setSize(sf::Vector2f(interface_width_, interface_height_));
    background_.setPosition(sf::Vector2f(0.0f, 0.0f));
    background_.setFillColor(sf::Color::Blue);
}

bool GraphicalUserInterface::handleEvent(sf::Event &event){
    return gui_.handleEvent(event);
}

void GraphicalUserInterface::setWindow() {
    gui_.setTarget(window_);
}

void GraphicalUserInterface::setView(sf::View &view) {
    background_.setSize(sf::Vector2f(interface_width_, view.getSize().y));
    gui_.setView(view);
}

void GraphicalUserInterface::addButton(const std::string &text) {
    auto button = tgui::Button::create(text);
    button->setSize(150, 50);
    button->setPosition(50, 50);
    gui_.add(button);
}

void GraphicalUserInterface::draw() {
    window_.draw(background_);
    gui_.draw();
}

const int GraphicalUserInterface::getInterfaceWidth() const {
    return interface_width_;
}