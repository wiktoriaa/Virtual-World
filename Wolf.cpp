#include "Wolf.h"
#include <iostream>

Wolf::Wolf(int x, int y) : Animal(x, y) {
	force = 9;
	initiative = 5;
}

void Wolf::draw() {
	std::cout << "W";
}

std::string Wolf::getName() const {
	return "Wolf";
}

bool Wolf::isReflectedAttack(Organism* attacker) { return false; }