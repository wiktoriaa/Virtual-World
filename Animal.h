#pragma once

#include "Organism.h"

class World;

class Animal : public Organism
{
public:
	Animal(int x, int y);
	void action(World *world) override;
	void collision(Organism* organizm, World* world) override;
	virtual void draw() = 0;
	virtual std::string getName() const = 0;
	virtual bool isReflectedAttack(Organism* attacker) = 0;
	virtual bool canEscape();
private:
	bool identical(Animal* animal);
};

