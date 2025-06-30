#include "stdafx.h"
#include "BackgroundElement.h"

BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void BackgroundElement::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	float y = (name == "bee") ? 750.f : Utils::RandRange(100.f, 400.f);

	switch (side)
	{
	case Sides::Left:
		direction = { 1.f, 0.f };
		SetScale({ -1.f, 1.f });
		SetPosition({ -150.f, y});
		break;
	case Sides::Right:
		direction = { -1.f, 0.f };
		SetScale({ 1.f, 1.f });
		SetPosition({ bounds.width + 150.f, y });
		break;
	}
	if (name == "bee")
	{
		speed = Utils::RandRange(400.f, 600.f);
	}
	else
	{
		speed = Utils::RandRange(200.f, 400.f);
	}
}

void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	SetOrigin(Origins::MC);

	if (Utils::RandValue() > 0.5f)
	{
		SetSide(Sides::Left);
	}
	else
	{
		SetSide(Sides::Right);
	}

}

void BackgroundElement::Update(float dt)
{
	sf::Vector2f pos = GetPosition();
	pos += direction * speed * dt;
	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		if (Utils::RandValue() > 0.5f)
		{
			SetSide(Sides::Left);
		}
		else
		{
			SetSide(Sides::Right);
		}
	}
}