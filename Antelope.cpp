#include "Antelope.h"
#include <iostream>
#include "World.h"

Antelope::Antelope(int x, int y) : Animal(x, y) {
	force = 4;
	initiative = 4;
}

void Antelope::draw() {
	std::cout << "A";
}

std::string Antelope::getName() const {
	return "Antelope";
}

bool Antelope::isReflectedAttack(Organism* attacker) { return false; }

void Antelope::action(World* world) {
	int newX = randomPoint(x, world->getX());
	int newY = randomPoint(y, world->getY());
	/* zasiêg x2 */
	newX = randomPoint(newX, world->getX());
	newY = randomPoint(newY, world->getY());

	world->moveOrganism(this, x, y, newX, newY);

	age++;
}

bool Antelope::canEscape() {
	return getRandomNumber(0, 1);
}