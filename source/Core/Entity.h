#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include <typeindex>

enum class Replication // for net
{
	ClientOnly,
	ServerOnly,
	ClientServer
};

class Component
{
	Replication ReplState;

public:

	virtual ~Component() {}

	virtual void Update() {}
	virtual void Render() {}
};

class Entity
{
	std::unordered_map<std::type_index, Component*> Components;
	Replication ReplState;

public:
	Entity();
	~Entity();

	template<typename T>
	T* GetComponent();

	template <typename T>
	void AddComponent(Component* component);
};

template<typename T>
T* Entity::GetComponent()
{
	auto search = Components.find(typeid(T));
	if (search != Components.end())
		return dynamic_cast<T*>(search->second);
	return nullptr;
}

template <typename T>
void Entity::AddComponent(Component* component)
{
	Components[typeid(T)] = component;
}

