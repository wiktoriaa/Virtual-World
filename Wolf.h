#pragma once

#include "Animal.h"
#include <string>

class Wolf : public Animal
{
public:
	Wolf(int x, int y);
	void draw() override;
	std::string getName() const override;
	bool isReflectedAttack(Organism* attacker) override;
};

