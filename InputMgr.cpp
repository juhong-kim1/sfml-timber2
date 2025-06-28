#include "InputMgr.h"

std::list<sf::Keyboard::Key> InputMgr::downkeys;
std::list<sf::Keyboard::Key> InputMgr::heldkeys;
std::list<sf::Keyboard::Key> InputMgr::upkeys;


void InputMgr::Init()
{

}
void InputMgr::Clear()
{
	downkeys.clear();
	upkeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldkeys, ev.key.code))
		{
			downkeys.push_back(ev.key.code);
			heldkeys.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		Remove(heldkeys, ev.key.code);
		upkeys.push_back(ev.key.code);
		break;
	}

}
void InputMgr::Update(float dt)
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downkeys, key);
}
bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upkeys, key);

}
bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldkeys, key);
}

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
