#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    SpriteGo* spriteGo = new SpriteGo("graphics/player.png");
    spriteGo->SetOrigin(Origins::ML);

    TextGo* textGo = new TextGo("fonts/KOMIKAP_.ttf");
    textGo->SetString("Hello SFML!");
    textGo->SetCharacterSize(30);
    textGo->SetFillColor(sf::Color::White);
    textGo->SetPosition({ 640.f, 360.f });
    textGo->SetOrigin(Origins::MC);

    AddGameObject(spriteGo);
    AddGameObject(textGo);

    Scene::Init();
}
