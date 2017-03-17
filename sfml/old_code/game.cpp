#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "GameObjects.h"
#include "cannonball.h"
#include "utilities.h"

int main () {
    srand(time(nullptr));

    // window size
    const double WIN_HEIGHT = 600;
    const double WIN_WIDTH = 1200;

    // create a window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // "smoother" edges - not necessary
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TargetPractice", sf::Style::Close, settings);
    window.setFramerateLimit(30);

    // flip coordinates to make (0, 0) in lower left corner
    // in order to simplify simulation
    sf::View view(window.getView());
    view.setSize(WIN_WIDTH, -WIN_HEIGHT);
    window.setView(view);

    // start the clock
    sf::Clock clock;

    // variable indicating if the player has hit the target
    bool gameOver = false;

    // create game objects here ****


    // main loop
    while (window.isOpen()) {
        sf::Event event;
        // while there are still unhandled events
        while (window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                case sf::Keyboard::Escape:
                case sf::Keyboard::Q:
                    window.close();
                    break;
                default:
                    break;
                }
                // all events that only should be handled
                // while the game is not over, should
                // be placed here inside this if
                // (ex: moving the cannon, shooting)
                if (!gameOver) {
                    switch(event.key.code) {
                    // add case for new keyboard events here!
                    default:
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }

        // add checks for landed cannonballs here,
        // also check for cannonballs hitting the target


        // only update if game is not over
        if (!gameOver) {
            // update objects here
        }

        window.clear();
        // draw objects here


        window.display();
    }
}

