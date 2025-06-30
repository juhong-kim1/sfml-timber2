#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");

    AddGameObject(new SpriteGo("graphics/background.png"));
    
    auto element = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png"));
    element->speed = 100.f;
    element->direction = { 1.f, 0.f };

    AddGameObject(new Tree());

    Scene::Init();
}

void SceneGame::Enter()
{
    Scene::Enter();
}

void SceneGame::Exit()
{
    Scene::Exit();
}