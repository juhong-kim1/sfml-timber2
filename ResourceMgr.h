#pragma once
#include <unordered_map>
#include <string>
#include "Singleton.h"
#include <vector>
#include <iostream>

template <typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;

protected:
	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		for (auto pair : resources)
		{
			delete pair.second;
		}
		resources.clear();
	}

	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr* operator=(const ResourceMgr&) = delete;

	std::unordered_map<std::string, T*> resources;

	static T Empty;

public:

	bool Load(const std::string& id)
	{
			auto it = resources.find(id);
			if (it != resources.end())
			{

				return false;
			}

			T* res = new T;
			bool success = res->loadFromFile(id);
			if (!success)
			{
				return false;
			}

			resources.insert({ id, res});
	}

	void Load(const std::vector<std::string>& ids)
	{
		for (auto id : ids)
		{
			Load(id);
		}
	}


	bool Unload(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return false;
		}

		delete it->second;
		resources.erase(it);
		return true;
	}

	void Unload(const std::vector<std::string>& ids)
	{
		for (auto id : ids)
		{
			Unload(id);
		}
	}

	T& Get(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return Empty;
		}
		return *(it->second);
	}



};

template<typename T>
T ResourceMgr<T>::Empty;