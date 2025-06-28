#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "InputMgr.h"
#include "ResourceMgr.h"
#include <iostream>
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ResourceMgr<sf::Texture>::Instance().Load({ "graphics/player.png",
        "graphics/bee.png",
        "graphics/tree.png",
        "graphics/background.png" }
    );



    sf::Sprite sprite;

    sprite.setTexture(ResourceMgr<sf::Texture>::Instance().Get( "graphics/player.png"));

    while (window.isOpen())
    {
        InputMgr::Clear();

        //Event
        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            InputMgr::UpdateEvent(event);

        }


        //update
        InputMgr::Update(0.f);

        if (InputMgr::GetKeyDown(sf::Keyboard::A))
        {
            std::cout << "Key Down: A" << std::endl;
        }

        if (InputMgr::GetKeyUp(sf::Keyboard::A))
        {
            std::cout << "Key Up: A" << std::endl;
        }

        if (InputMgr::GetKey(sf::Keyboard::A))
        {
            std::cout << "Key Held: A" << std::endl;
        }



        //draw
        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}