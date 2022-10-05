#include "Human.h"
#include <iostream>
#include <conio.h>
#include "World.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Human::Human(int x, int y) : Animal(x, y) {
	force = 9;
	initiative = 5;
}

void Human::draw() {
	std::cout << "H";
}

std::string Human::getName() const {
	return "Human";
}

/* immortal */
bool Human::isReflectedAttack(Organism* attacker) { return true; }
void Human::kill() {}

void Human::action(World* world) {
    int newX = x;
    int newY = y;

    std::cout << "Wcisnij strzalke aby poruszyc czlowiekiem" << "\n";
    switch (int c = _getch()) {
    case KEY_UP:
        newX--;
        break;
    case KEY_DOWN:
        newX++;
        break;
    case KEY_LEFT:
        newY--;
        break;
    case KEY_RIGHT:
        newY++;
        break;
    default:
        break;
    }

    if (newX >= 0 && newX < world->getX() && newY >= 0 && newY < world->getY()) {
        world->moveOrganism(this, x, y, newX, newY);
    }
    age++;
}
