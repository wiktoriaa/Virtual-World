#include "Sheep.h"
#include <iostream>

Sheep::Sheep(int x, int y) : Animal(x, y) {
	force = 4;
	initiative = 4;
}

void Sheep::draw() {
	std::cout << "S";
}

std::string Sheep::getName() const {
	return "Sheep";
}

bool Sheep::isReflectedAttack(Organism* attacker) { return false; }