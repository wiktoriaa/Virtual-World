#pragma once

#include "Animal.h"
#include <string>

class Fox : public Animal
{
public:
	Fox(int x, int y);
	void draw() override;
	std::string getName() const override;
	bool isReflectedAttack(Organism* attacker) override;
	void action(World* world) override;
};

