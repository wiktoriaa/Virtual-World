#pragma once

#include "Animal.h"
#include <string>

class Human : public Animal
{
public:
	Human(int x, int y);
	void draw() override;
	std::string getName() const override;
	bool isReflectedAttack(Organism* attacker) override;
	void action(World* world) override;
	void kill() override;
};

