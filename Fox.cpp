#include "Fox.h"
#include <iostream>
#include "World.h"

Fox::Fox(int x, int y) : Animal(x, y) {
	force = 3;
	initiative = 7;
}

void Fox::draw() {
	std::cout << "F";
}

std::string Fox::getName() const {
	return "Fox";
}

bool Fox::isReflectedAttack(Organism* attacker) { return false; }

void Fox::action(World* world) {
	int newX = randomPoint(x, world->getX());
	int newY = randomPoint(y, world->getY());

	Organism* enemy = world->getOrganism(newX, newY);

	if (enemy == nullptr || enemy->getForce() <= force) {
		world->moveOrganism(this, x, y, newX, newY);
	}

	age++;
}