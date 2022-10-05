#include "Plant.h"
#include "World.h"

Plant::Plant(int x, int y) : Organism(x, y) {}

void Plant::action(World* world) {
	if (getRandomNumber(1, 3) == 3) baby++;
}

void Plant::collision(Organism* organism, World* world) {}

bool Plant::isForceSuplement() { return false; }