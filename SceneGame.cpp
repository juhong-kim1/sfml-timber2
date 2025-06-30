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
    texIds.push_back("graphics/bee.png");

    AddGameObject(new SpriteGo("graphics/background.png"));
    
    for (int i = 0; i < 3; ++i)
    {
        auto cloud = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png", "cloud"));
    }

    auto bee = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/bee.png", "bee"));

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