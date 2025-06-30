#include "stdafx.h"
#include "Utils.h"
#include <ctime>
#include <cstdlib>

void Utils::Init()
{
    srand((int)time(0));
}


//random
inline float Utils::RandValue()
{
    Init();

    float value = (float)rand() / RAND_MAX;

    return value;
}

int Utils::RandRange(int min, int max)
{
    Init();

    int range = rand() % ((max - min) + min);

    std::cout << range << std::endl;;

    return range;
}

float Utils::RandRange(float min, float max)
{
    return 0.0;
}

sf::Vector2f Utils::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect rect)
{
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Shape& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}