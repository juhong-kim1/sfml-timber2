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
		SetPosition({ -150.f, Utils::RandRange(200.f, 900.f)});
		break;
	case Sides::Right:
		direction = { -1.f, 0.f };
		SetScale({ 1.f, 1.f });
		SetPosition({ bounds.width + 150.f, 0.f });
		break;
	}
	speed = Utils::RandRange(200.f, 500.f);
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

	SetPosition({ Utils::RandRange(200.f, 900.f), Utils::RandRange(200.f, 900.f) });
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