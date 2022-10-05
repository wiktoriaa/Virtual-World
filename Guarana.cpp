#include "Guarana.h"
#include <iostream>

Guarana::Guarana(int x, int y) : Plant(x, y) {
	force = 0;
	initiative = 0;
}

void Guarana::draw() {
	std::cout << "&";
}

std::string Guarana::getName() const {
	return "Guarana";
}

bool Guarana::isForceSuplement() { return true; }