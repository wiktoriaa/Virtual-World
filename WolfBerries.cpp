#include "WolfBerries.h"
#include <iostream>

WolfBerries::WolfBerries(int x, int y) : Plant(x, y) {
	force = 99;
	initiative = 0;
}

void WolfBerries::draw() {
	std::cout << "x";
}

std::string WolfBerries::getName() const {
	return "WolfBerries";
}
