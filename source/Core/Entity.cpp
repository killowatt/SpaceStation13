#include "Entity.h"

Entity::Entity()
{
	ReplState = Replication::ClientServer;
	ScriptName = "";
}
Entity::~Entity()
{
	for (std::pair<std::type_index, Component*> component : Components)
		delete component.second;

}