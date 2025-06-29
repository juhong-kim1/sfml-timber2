#include "stdafx.h"
#include "SceneGame.h"

int main()
{

    //게임 창, 이름 생성
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    
    // 컨테이너 클래스에 주소 넣기
    std::vector<std::string> texIds = {
        "graphics/player.png",
        "graphics/background.png"
    };

    //싱클톤 리소스 매니저에 컨테이너 넣어서 이미지 및 폰트 로드시키기
    TEXTURE_MGR.Load(texIds);
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");

    //게임 씬 생성 및 초기화
    SceneGame sceneGame;
    sceneGame.Init();
    sceneGame.Enter();

    while (window.isOpen())
    {
        InputMgr::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            InputMgr::UpdateEvent(event);
        }

        // Update
        InputMgr::Update(0.f);

        sceneGame.Update(0.f);

        // Draw
        window.clear();
        sceneGame.Draw(window);
        window.display();
    }

    sceneGame.Release();
    return 0;
}