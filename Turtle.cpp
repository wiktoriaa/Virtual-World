#include "Turtle.h"
#include <iostream>

Turtle::Turtle(int x, int y) : Animal(x, y) {
	force = 2;
	initiative = 1;
}

void Turtle::draw() {
	std::cout << "T";
}

std::string Turtle::getName() const {
	return "Turtle";
}

bool Turtle::isReflectedAttack(Organism* attacker) { return (attacker->getForce() < 5); }

void Turtle::action(World *world) {
	if (getRandomNumber(1, 4) == 3) {
		Animal::action(world);
	}
}