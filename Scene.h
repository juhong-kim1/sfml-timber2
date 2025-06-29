#pragma once

class Scene
{
protected:
	//게임오브젝츠 객체로 게임오브젝트 클래스의 이것저것 접근 가능 (포인터로 선언해서)
	std::list<GameObject*> gameObjects;

public:
	//이넘 클래스 객체 id를 선언
	const SceneIds Id;

	//초기화 할때는 씬id에 있는 이넘으로 초기화 가능
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);

	GameObject* FindGameObject(const std::string& name);
};

