#include "Game.h"
#include <iostream> //Debug only

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application")
, mPlayer()
, playerTexture()
{
    if(!playerTexture.loadFromFile("Resources/Eagle.png"))
    {
        std::cout << "Failed to load texture!" << std::endl;
    }
    mPlayer.setTexture(playerTexture);
    mPlayer.setPosition(100.f, 100.f);
    inputDirection = sf::Vector2f(0.f, 0.f);
    mWindow.setKeyRepeatEnabled(false);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > frameTime)
        {
            timeSinceLastUpdate -= frameTime;
            processEvents();
            update();
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                std::cout << "Pressed: " << event.key.code << " direction: " << inputDirection.x << ", " << inputDirection.y << std::endl;
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
            default: break;
        }
    }
}

void Game::update()
{
    mPlayer.move(inputDirection);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key& key, bool isPressed)
{
    switch(key)
    {
        case sf::Keyboard::W: isPressed ? inputDirection.y -= mMovementSpeed : inputDirection.y += mMovementSpeed; break;
        case sf::Keyboard::S: isPressed ? inputDirection.y += mMovementSpeed : inputDirection.y -= mMovementSpeed; break;
        case sf::Keyboard::A: isPressed ? inputDirection.x -= mMovementSpeed : inputDirection.x += mMovementSpeed; break;
        case sf::Keyboard::D: isPressed ? inputDirection.x += mMovementSpeed : inputDirection.x -= mMovementSpeed; break;
        default: break;
    }
}
