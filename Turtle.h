#pragma once

#include "Animal.h"
#include <string>

class Turtle : public Animal
{
public:
	Turtle(int x, int y);
	void draw() override;
	std::string getName() const override;
	bool isReflectedAttack(Organism* attacker) override;
	void action(World *world) override;
};

