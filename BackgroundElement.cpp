#include "stdafx.h"
#include "BackgroundElement.h"

BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void BackgroundElement::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	switch (side)
	{
	case Sides::Left:
		direction = { 1.f, 0.f };
		SetScale({ -1.f, 1.f });
		SetPosition({ -150.f, 0.f });
		break;
	case Sides::Right:
		direction = { -1.f, 0.f };
		SetScale({ 1.f, 1.f });
		SetPosition({ bounds.width + 150.f, 0.f });
		break;
	}
	speed = 200.f;
}

void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	SetOrigin(Origins::MC);
	SetSide(Sides::Right);
	SetPosition({ 500.f, 0.f });
}

void BackgroundElement::Update(float dt)
{
	sf::Vector2f pos = GetPosition();
	pos += direction * speed * dt;
	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		SetSide(Sides::Right);
	}
}