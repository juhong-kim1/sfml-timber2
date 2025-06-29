#pragma once

class Scene
{
protected:
	//���ӿ������� ��ü�� ���ӿ�����Ʈ Ŭ������ �̰����� ���� ���� (�����ͷ� �����ؼ�)
	std::list<GameObject*> gameObjects;

public:
	//�̳� Ŭ���� ��ü id�� ����
	const SceneIds Id;

	//�ʱ�ȭ �Ҷ��� ��id�� �ִ� �̳����� �ʱ�ȭ ����
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

