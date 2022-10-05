#include "Organism.h"
#include "World.h"

Organism::Organism(int x, int y) {
	this->x = x;
	this->y = y;
}

int Organism::getForce() { return force; }
int Organism::getAge() { return age; }
int Organism::getInitiative() { return initiative; }
int Organism::getX() { return x; }
int Organism::getY() { return y; }

void Organism::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

void Organism::kill() { alive = false; }

bool Organism::isAlive() { return alive; }

int Organism::getBabyCount() { return baby; }

bool Organism::hasBaby() { return (baby > 0) ? true : false; }

int Organism::randomPoint(int point, int max) {
	if (getRandomNumber(1, 2) == 1) {
		if (getRandomNumber(1, 2) == 1) {
			if (point - 1 >= 0) {
				point--;
			}
			else if (point + 1 < max) {
				point++;
			}
		}
	}
	else {
		if (getRandomNumber(1, 2) == 1) {
			if (point + 1 < max) {
				point++;
			}
			else if (point - 1 >= 0) {
				point--;
			}
		}
	}

	return point;
}

bool Organism::multiply(World* world) {
	baby--;

	if (x + 1 < world->getX() && world->getOrganism(x + 1, y) == nullptr) {
		world->addOrganism(getName(), x + 1, y);
		return true;
	}
	else if (x - 1 >= 0 && world->getOrganism(x - 1, y) == nullptr) {
		world->addOrganism(getName(), x - 1, y);
		return true;
	}
	else if (y + 1 < world->getY() && world->getOrganism(x, y + 1) == nullptr) {
		world->addOrganism(getName(), x, y + 1);
		return true;
	}
	else if (y - 1 >= 0 && world->getOrganism(x, y - 1) == nullptr) {
		world->addOrganism(getName(), x, y - 1);
		return true;
	}
	else if (y + 1 < world->getY() && x + 1 < world->getX() && world->getOrganism(x + 1, y + 1) == nullptr) {
		world->addOrganism(getName(), x + 1, y + 1);
		return true;
	}
	else if (y - 1 >= 0 && x + 1 < world->getX() && world->getOrganism(x + 1, y - 1) == nullptr) {
		world->addOrganism(getName(), x + 1, y - 1);
		return true;
	}
	else if (y + 1 < world->getY() && x - 1 >= 0 && world->getOrganism(x - 1, y + 1) == nullptr) {
		world->addOrganism(getName(), x - 1, y + 1);
		return true;
	}
	else if (y - 1 >= 0 && x - 1 >= 0 && world->getOrganism(x - 1, y - 1) == nullptr) {
		world->addOrganism(getName(), x - 1, y - 1);
		return true;
	}
	return false;
}

void Organism::setForce(int force) { this->force = force; }

void Organism::setAge(int age) { this->age = age; }

void Organism::setAlive(bool alive) { this->alive = alive; }

void Organism::setBabyCount(int count) { this->baby = count; }

int Organism::getRandomNumber(int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(a, b);

	return distr(gen);
}