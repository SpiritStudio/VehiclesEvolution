//!  A GraphicalUserInterface class.
/*!
  A class designed in order to create GUI.
  It consists information about widgets, buttons and background.
*/

#ifndef VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
#define VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H

#include <string>
#include <functional>

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class GraphicalUserInterface {

public:
    //!  An explicit constructor of class.
    explicit GraphicalUserInterface(sf::RenderWindow &window, const int interface_width, const int interface_height);
    //!  A method for setting the application window.
    void setWindow();
    //!  A method for setting the displaying background.
    void setView(sf::View &view);
    //!  A method for setting and creating the button widgets.
    void addWidgets();
    //!  A method for handling on-running events, like mouse-click.
    bool handleEvent(sf::Event &event);
    //!  A method for drawing widget on window.
    void draw();

    //!  Store the information about width of the displayed interface.
    const int getInterfaceWidth() const;

    //!  A method for checking whether the following leather button is checked.
    const bool isFollowingTheLeader() const;

    //!  A Method for setting number of alive cars.
    void setStatus(size_t alive, size_t all);

    //! A method for increasing generation number.
    void increaseGenerationNumber();

private:
    //!  A method for generating and initializing sliders for algorithm parameters changing.
    void generateParameterSliders(float offset_x, float offset_y);
    //! Private pointer
    /*!
        Creates and stores the pointer to button specifying its text and position
    */
    std::shared_ptr<tgui::Button> addButton(const sf::Vector2f &position, const std::string &text);
    //! Private pointer
    /*!
        Creates and stores the pointer to checkbox specifying its text and position
    */
    std::shared_ptr<tgui::CheckBox> addCheckbox(const sf::Vector2f &position, const std::string &text);
    //! Private pointer
    /*!
        Creates and stores the pointer to slider specifying its position, range and default value
    */
    std::shared_ptr<tgui::Slider> addSlider(const sf::Vector2f &position,
                                            const std::pair<double, double> &range,
                                            double default_value);

    //! Static constant expression
    /*!
        A attribute consists of information about height of the button widgets in pixels
    */
    static constexpr int BUTTON_HEIGHT_PIXELS_ = 25;
    //! Static constant expression
    /*!
        A attribute consists of information about width of the button widgets in pixels
    */
    static constexpr int BUTTON_WIDTH_PIXELS_ = 200;
    //! Static constant expression
    /*!
        A attribute consists of information about height of the slider widgets in pixels
    */
    static constexpr int SLIDER_HEIGHT_PIXELS_ = 10;
    //! Static constant expression
    /*!
        A attribute consists of information about width of the slider widgets in pixels
    */
    static constexpr int SLIDER_WIDTH_PIXELS_ = 200;
    //! Static constant expression
    /*!
        A attribute consists of information about distance of the button widgets from another button widgets in pixels
    */
    static constexpr float FIRST_BUTTON_VERTICAL_DISTANCE_PIXELS_ = 20;
    //! Static constant expression
    /*!
        A attribute consists of information about distance of the button widgets from another button widgets in pixels
    */
    static constexpr int BUTTONS_VERTICAL_DISTANCE_PIXELS_ = 30;
    //! Static constant expression
    /*!
        A attribute consists of information about distance of the slider widgets from another slider widgets in pixels
    */
    static constexpr int SLIDERS_VERTICAL_DISTANCE_PIXELS_ = 30;
    //! Static constant expression
    /*!
        A attribute consists of information about size of the checkbox widgets in pixels
    */
    static constexpr int CHECKBOX_SIZE_PIXELS_ = 20;

    //! Constant expression
    /*!
        A attribute consists of information about width of the interface in pixels
    */
    const int interface_width_;
    //! Constant expression
    /*!
        A attribute consists of information about width height of the interface in pixels
    */
    const int interface_height_;

    //! Constant expression
    /*!
        A attribute consists of information color of the interface's background
    */
    const sf::Color background_color_;

    //! Private object
    /*!
        An object representing an application window
    */
    sf::RenderWindow &window_;
    //! Private object
    /*!
        An object representing an interface
    */
    tgui::Gui gui_;
    //! Private objects
    /*!
        Sliders for parameters
    */
    tgui::Slider::Ptr crossover_probability_, mutation_probability_, wheel_sigma_, wheel_expected_value_,
                      min_car_body_point_radius_, max_car_body_point_radius_, car_body_point_cartesian_sigma_;
    //! Private objects
    /*!
        Labels for sliders
    */
    tgui::Label::Ptr crossover_probability_l_, mutation_probability_l_, wheel_sigma_l_, wheel_expected_value_l_,
                     min_car_body_point_radius_l_, max_car_body_point_radius_l_, car_body_point_cartesian_sigma_l_;
    //! Private object
    /*!
        An object representing background of interface
    */
    sf::RectangleShape background_;
    //! Private variable.
    /*!
        Stores the information about current generation status.
    */
    tgui::Label::Ptr status_;
    //! Private variable.
    /*!
        Stores the information about current generation number.
    */
    int generation_number_;
    //! Private variable.
    /*!
        Store the information about whether the Follow The Leader checkbox is checked.
    */
    bool follow_the_leader_checked_{false};
};


#endif //VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
