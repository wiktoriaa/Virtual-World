#include "Grass.h"
#include <iostream>

Grass::Grass(int x, int y) : Plant(x, y) {
	force = 0;
	initiative = 0;
}

void Grass::draw() {
	std::cout << ".";
}

std::string Grass::getName() const {
	return "Grass";
}
