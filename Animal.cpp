#include "Animal.h"
#include "World.h"
#include "Plant.h"
#include <iostream>

Animal::Animal(int x, int y) : Organism(x, y) {}

bool Animal::identical(Animal* animal) {
	if (this->getName() == animal->getName()) {
		return true;
	}

	return false;
}

void Animal::action(World *world) {
	int newX = randomPoint(x, world->getX());
	int newY = randomPoint(y, world->getY());

	//std::cout << this->getName() << " lat "<< getAge() << " idzie na x=" << newX << ", y=" << newY << "\n";
	world->moveOrganism(this, x, y, newX, newY);

	age++;
}

void Animal::collision(Organism* organism, World *world) {

	if (this->getForce() > organism->getForce()) {
		if (Animal* a = dynamic_cast<Animal*>(organism)) {
			if (a->isReflectedAttack(this)) {
				std::cout << a->getName() << " odbija atak " << getName() << "\n";
				return;
			}
			if (a->canEscape()) {
				std::cout << a->getName() << " udalo sie uciec przed " << getName() << "\n";
				return;
			}
		}
		if (Plant* p = dynamic_cast<Plant*>(organism)) {
			if (p->isForceSuplement()) {
				force += 3;
				std::cout << "sila " << getName() << " zwieksza sie do " << force << "\n";
			}
		}
		std::cout << getName() << " pokonuje/zjada " << organism->getName() << "\n";
		organism->kill();

		world->removeFromBoard(organism);
		world->removeFromBoard(this);

		this->x = organism->getX();
		this->y = organism->getY();
		world->addToBoard(this);
		return;
	}
	else if (this->getForce() < organism->getForce()) {
		if (Animal* a = dynamic_cast<Animal*>(organism)) {
			if (this->isReflectedAttack(a)) {
				std::cout << getName() << " odbija atak " << a->getName() << "\n";
				return;
			}
			if (this->canEscape()) {
				std::cout << getName() << " udalo sie uciec przed " << a->getName() << "\n";
				return;
			}
		}
		this->kill();
		if (!this->isAlive()) {
			std::cout << organism->getName() << " pokonuje/zjada " << getName() << "\n";
			world->removeFromBoard(this);
		}
		return;
	}

	if (this->getName() == organism->getName()) {
		if (organism->hasBaby() || this->hasBaby() || organism->getAge() < 3 || this->getAge() < 3)
		{
			return;
		}
		//std::cout << "X: " << x << ", Y: " << y << " rozmnaza sie z X: " << organism->getX() << ", Y: " << organism->getY() << "\n";
		baby = 1;
	}
	
}

bool Animal::canEscape() { return false; }
