
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "game_objects.hpp"
#include "cannonball.hpp"
#include "random_function.hpp"

int main(int, char const**)
{
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
    int position_x = randomWithLimits(100, WIN_WIDTH - 100);
    std::cout << position_x;
    Target gameTarget(10, position_x);
    Cannon gameCannon;
    std::vector<Cannonball> cannonballs;
    
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
                            case sf::Keyboard::Up:
                                gameCannon.decrementAngle();
                                break;
                            case sf::Keyboard::Down:
                                gameCannon.incrementAngle();
                                break;
                            case sf::Keyboard::Left:
                                gameCannon.incrementVelocity();
                                break;
                            case sf::Keyboard::Right:
                                gameCannon.decrementVelocity();
                                break;
                            case sf::Keyboard::Space:
                                cannonballs.push_back(gameCannon.shoot());
                                break;
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
            gameCannon.update();
        }
        
        window.clear();
        // Draw Target and Cannon
        gameTarget.draw(window);
        gameCannon.draw(window);
        
        // Draw all Cannonballs
        for(std::vector<Cannonball>::iterator it = cannonballs.begin(); it != cannonballs.end(); ++it) {
            it->draw(window);
        }
        // Attempt to delete Cannonballs if they leave the screen
        for (int x = 0; x < cannonballs.size(); x++) {
            cannonballs.at(x).update();
            bool delete_me;
            if (cannonballs.at(x).hasLanded()) {
                delete_me = true;
            }
            if (delete_me) {
                std::cout << x << std::endl;
                //cannonballs.erase(cannonballs.begin());
            }
        }
        
        window.display();
    }
    return EXIT_SUCCESS;
}
