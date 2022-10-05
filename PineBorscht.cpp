#include "PineBorscht.h"
#include <iostream>
#include "World.h"

PineBorscht::PineBorscht(int x, int y) : Plant(x, y) {
	force = 10;
	initiative = 0;
}

void PineBorscht::draw() {
	std::cout << "#";
}

std::string PineBorscht::getName() const {
	return "PineBorscht";
}

void PineBorscht::action(World* world) {
	Organism *organism;

	if ((x + 1 < world->getX()) && ((organism = world->getOrganism(x + 1, y)) != nullptr) ) {
		world->killIfAnimal(organism);
	}
	if ((x + 1 < world->getX()) && (y + 1 < world->getY()) && ((organism = world->getOrganism(x + 1, y + 1)) != nullptr) ) {
		world->killIfAnimal(organism);
	}
	if ( (x + 1 < world->getX()) && (y - 1 >= 0) && ((organism = world->getOrganism(x + 1, y - 1)) != nullptr) ) {
		world->killIfAnimal(organism);
	}
	
	if ((x - 1 >= 0) && ((organism = world->getOrganism(x - 1, y)) != nullptr) ) {
		world->killIfAnimal(organism);
	}
	if ( (x - 1 >= 0) && (y + 1 < world->getY()) && ((organism = world->getOrganism(x - 1, y + 1)) != nullptr) ) {
		world->killIfAnimal(organism);
	}
	if ((x - 1 >= 0) && (y - 1 >= 0) && ((organism = world->getOrganism(x - 1, y - 1)) != nullptr) ) {
		world->killIfAnimal(organism);
	}

	Plant::action(world);
}