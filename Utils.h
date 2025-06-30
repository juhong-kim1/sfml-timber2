#pragma once
class Utils
{
public:
	static void Init();


	//random
	static float RandValue();
	static int RandRange(int min, int max);
	static float RandRange(float min, float max);




	// Origin
	static sf::Vector2f SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect bound);
	static sf::Vector2f SetOrigin(sf::Shape& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
};

