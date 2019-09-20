//
// Created by SpiritStudio on 03.12.18.
//

#include <Graphics/GraphicalUserInterface.h>
#include <Physics/Physics.h>

GraphicalUserInterface::GraphicalUserInterface(sf::RenderWindow &window, const int interface_width,
                                               const int interface_height)
    : window_(window)
    , interface_width_(interface_width)
    , interface_height_(interface_height)
    , background_color_(255, 153, 0, 50)
    , generation_number_(-1)
{
    background_.setSize(sf::Vector2f(interface_width_, interface_height_));
    background_.setPosition(sf::Vector2f(0.0f, 0.0f));
    background_.setFillColor(background_color_);

    status_ = tgui::Label::create("Cars alive: 0 / 0 \nGeneration: 0");

    status_->setPosition((interface_width_ - BUTTON_WIDTH_PIXELS_) / 2, interface_height - 50);
    gui_.add(status_);
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

void GraphicalUserInterface::addWidgets() {
    const float left_side_offset = (interface_width_ - BUTTON_WIDTH_PIXELS_)/2;
    float vertical_distance = FIRST_BUTTON_VERTICAL_DISTANCE_PIXELS_;

    auto button = addButton(sf::Vector2f(left_side_offset, vertical_distance), "Exit");
    button->connect("pressed", [&](){ window_.close(); });
    vertical_distance += BUTTONS_VERTICAL_DISTANCE_PIXELS_;

    std::vector<CarParameters> params_example = EvolutionaryAlgorithm::getInstance().generateNewPopulation();

    button = addButton(sf::Vector2f(left_side_offset, vertical_distance), "Generate new population");
    button->connect("pressed", &Physics::makeCars, &Physics::getInstance(), params_example);
    button->connect("pressed", [&](){ generation_number_ = 1; });
    vertical_distance += BUTTONS_VERTICAL_DISTANCE_PIXELS_;

    auto checkbox = addCheckbox(sf::Vector2f(left_side_offset, vertical_distance), "Follow the leader");
    checkbox->connect("checked", [&](){ follow_the_leader_checked_ = true; });
    checkbox->connect("unchecked", [&](){ follow_the_leader_checked_ = false; });
    vertical_distance += SLIDERS_VERTICAL_DISTANCE_PIXELS_;

    generateParameterSliders(left_side_offset, vertical_distance);
}

void GraphicalUserInterface::generateParameterSliders(float offset_x, float offset_y) {
    auto generateSlider = [&](const std::string &text, tgui::Label::Ptr &label,
                              tgui::Slider::Ptr &slider, std::pair<double, double> range, double value) {
        label = tgui::Label::create(text + ": " + std::to_string(value));
        label->setPosition(offset_x, offset_y);
        gui_.add(label);
        offset_y += SLIDERS_VERTICAL_DISTANCE_PIXELS_;

        slider = addSlider({offset_x, offset_y}, range, value);
        offset_y += SLIDERS_VERTICAL_DISTANCE_PIXELS_;
    };

    generateSlider("Crossover probability", crossover_probability_l_, crossover_probability_, {0.0, 1.0}, 0.4);
    crossover_probability_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setCrossoverProbability_(crossover_probability_->getValue());
        crossover_probability_l_->setText("Crossover probability: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getCrossoverProbability()));
    });
    generateSlider("Mutation probability", mutation_probability_l_, mutation_probability_, {0.0, 1.0}, 0.03);
    mutation_probability_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setMutationProbability_(mutation_probability_->getValue());
        mutation_probability_l_->setText("Mutation probability: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getMutationProbability()));
    });
    generateSlider("Wheel radius sigma", wheel_sigma_l_, wheel_sigma_, {0.0, 1.0}, 0.15);
    wheel_sigma_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setWheelSigma_(wheel_sigma_->getValue());
        wheel_sigma_l_->setText("Wheel radius sigma: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getWheelSigma()));
    });
    generateSlider("Wheel radius avg value", wheel_expected_value_l_, wheel_expected_value_, {0.0, 3.0}, 0.5);
    wheel_expected_value_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setWheelExpectedValue_(wheel_expected_value_->getValue());
        wheel_expected_value_l_->setText("Wheel radius avg value: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getWheelExpectedValue()));
    });
    generateSlider("Min body point radius", min_car_body_point_radius_l_, min_car_body_point_radius_, {0.0, 2.0}, 0.3);
    min_car_body_point_radius_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setMinCarBodyPointRadius_(min_car_body_point_radius_->getValue());
        min_car_body_point_radius_l_->setText("Min body point radius: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getMinCarBodyPointRadius()));
    });
    generateSlider("Max body point radius", max_car_body_point_radius_l_, max_car_body_point_radius_, {0.0, 5.0}, 2);
    max_car_body_point_radius_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setMaxCarBodyPointRadius_(max_car_body_point_radius_->getValue());
        max_car_body_point_radius_l_->setText("Max body point radius: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getMaxCarBodyPointRadius()));
    });
    generateSlider("Body point XY sigma", car_body_point_cartesian_sigma_l_, car_body_point_cartesian_sigma_, {0.0, 2.0}, 0.3);
    car_body_point_cartesian_sigma_->connect("ValueChanged", [&](){
        EvolutionaryAlgorithm::getInstance().setCrossoverProbability_(car_body_point_cartesian_sigma_->getValue());
        car_body_point_cartesian_sigma_l_->setText("Body point XY sigma: " +
                std::to_string(EvolutionaryAlgorithm::getInstance().getCarBodyPointCartesianSigma()));
    });
}

std::shared_ptr<tgui::Button> GraphicalUserInterface::addButton(const sf::Vector2f &position, const std::string &text) {
    auto button = tgui::Button::create(text);
    button->setSize(BUTTON_WIDTH_PIXELS_, BUTTON_HEIGHT_PIXELS_);
    button->setPosition(position);
    gui_.add(button);

    return button;
}

std::shared_ptr<tgui::CheckBox> GraphicalUserInterface::addCheckbox(const sf::Vector2f &position,
                                                                    const std::string &text) {
    auto checkbox = tgui::CheckBox::create(text);
    checkbox->setSize(CHECKBOX_SIZE_PIXELS_, CHECKBOX_SIZE_PIXELS_);
    checkbox->setPosition(position);
    gui_.add(checkbox);

    return checkbox;
}

std::shared_ptr<tgui::Slider> GraphicalUserInterface::addSlider(const sf::Vector2f &position,
                                                                const std::pair<double, double> &range,
                                                                double default_value) {
    auto slider = tgui::Slider::create();
    slider->setPosition(position);
    slider->setSize(SLIDER_WIDTH_PIXELS_, SLIDER_HEIGHT_PIXELS_);
    slider->setMinimum(range.first);
    slider->setMaximum(range.second);
    slider->setStep(0.01f);
    slider->setValue(default_value);
    gui_.add(slider);
    return slider;
}

void GraphicalUserInterface::draw() {
    window_.draw(background_);
    gui_.draw();
}

const int GraphicalUserInterface::getInterfaceWidth() const {
    return interface_width_;
}

const bool GraphicalUserInterface::isFollowingTheLeader() const {
    return follow_the_leader_checked_;
}

void GraphicalUserInterface::setStatus(size_t alive, size_t all) {
    std::ostringstream ss;
    ss << "Cars alive: " << alive << " / " << all << "\nGeneration: " << generation_number_;

    status_->setText(ss.str());
}

void GraphicalUserInterface::increaseGenerationNumber() {
    ++generation_number_;
}