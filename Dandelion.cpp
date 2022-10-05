#include "Dandelion.h"
#include <iostream>

Dandelion::Dandelion(int x, int y) : Plant(x, y) {
	force = 0;
	initiative = 0;
}

void Dandelion::draw() {
	std::cout << "*";
}

std::string Dandelion::getName() const {
	return "Dandelion";
}

void Dandelion::action(World* world) {
	for (int i = 0; i < 3; i++) Plant::action(world);
}
