#pragma once
#include <list>
#include <SFML/Window/Event.hpp>
#include <algorithm>
#include <iostream>



class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downkeys;
	static std::list<sf::Keyboard::Key> heldkeys;
	static std::list<sf::Keyboard::Key> upkeys;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);


};

