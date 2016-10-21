#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


class Game
{
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update();
        void render();
        void handlePlayerInput(sf::Keyboard::Key& key, bool isPressed);

    private:
        sf::RenderWindow mWindow;
        sf::Sprite mPlayer;
        sf::Texture playerTexture;
        sf::Vector2f inputDirection;
        float mMovementSpeed{1.f};
        const sf::Time frameTime = sf::seconds(1.f/60.f);
};

#endif // GAME_H
