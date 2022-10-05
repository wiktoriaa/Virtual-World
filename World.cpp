#include "World.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Animal.h"
#include "Plant.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Human.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "WolfBerries.h"
#include "PineBorscht.h"

World::World() {}

World::~World() {
	for (auto& organism : organismList)
	{
		delete organism;
		organism = nullptr;
	}
	organismList.erase(std::remove(organismList.begin(), organismList.end(), nullptr), organismList.end());
}

void World::createBoard(int x, int y) {
	for (int i = 0; i < x; i++)
	{
		board.push_back(std::vector<Organism*>());
		for (int j = 0; j < y; j++)
		{
			board[i].push_back(nullptr);
		}
	}

	this->x = x;
	this->y = y;
}

int World::getX() { return x; }
int World::getY() { return y; }

Organism* World::getOrganism(int x, int y) { return board[x][y]; }

void World::sortOrganisms() {
	std::sort(organismList.begin(), organismList.end(), ComparatorByForceAge());
}

void World::round() {
	int babies = 0;
	std::cout << "Wynik rundy: " << "\n";

	/* obs³uga rozmna¿ania */
	std::vector<Organism>::size_type size = organismList.size();
	for (std::vector<Organism>::size_type i = 0; i < size; ++i)
	{
		while (organismList[i]->getBabyCount() > 0) {
			if (organismList[i]->multiply(this)) ++size;
		}
	}
	sortOrganisms();

	/* poruszanie siê po planszy */
	for (Organism *organism : organismList) {
		if (organism->isAlive()) organism->action(this);
	}

	/* usuwanie zabitych */
	for (auto& organism : organismList)
	{
		if (!organism->isAlive())
		{
			delete organism;
			organism = nullptr;
		}
	}
	organismList.erase(std::remove(organismList.begin(), organismList.end(), nullptr), organismList.end());

	std::cout << "Koniec rundy\n";
}

void World::drawWorld() {
	std::cout << "Symulator autorstwa Wiktorii Lewickiej 184915\n\n";

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++) {
			if (j == 0) {
				std::cout << "|";
			}
			if (board[i][j] == nullptr) {
				std::cout << " ";
			}
			else {
				board[i][j]->draw();
			}
			if (j == y - 1) {
				std::cout << "|";
			}
		}
		std::cout << "\n";
	}
}

void World::addOrganism(std::string name, int x, int y) {
	if (name == "Wolf") {
		board[x][y] = new Wolf(x, y);
	}
	else if (name == "Sheep") {
		board[x][y] = new Sheep(x, y);
	}
	else if (name == "Fox") {
		board[x][y] = new Fox(x, y);
	}
	else if (name == "Turtle") {
		board[x][y] = new Turtle(x, y);
	}
	else if (name == "Antelope") {
		board[x][y] = new Antelope(x, y);
	}
	else if (name == "Human") {
		board[x][y] = new Human(x, y);
	}
	else if (name == "Grass") {
		board[x][y] = new Grass(x, y);
	}
	else if (name == "Dandelion") {
		board[x][y] = new Dandelion(x, y);
	}
	else if (name == "Guarana") {
		board[x][y] = new Guarana(x, y);
	}
	else if (name == "WolfBerries") {
		board[x][y] = new WolfBerries(x, y);
	}
	else if (name == "PineBorscht") {
		board[x][y] = new PineBorscht(x, y);
	}
	organismList.push_back(board[x][y]);
}

void World::moveOrganism(Organism* organism, int x, int y, int newX, int newY) {
	if (x == newX && y == newY) return;

	if (board[newX][newY] == nullptr) {
		if (Animal* animal = dynamic_cast<Animal*>(organism)) {
			board[x][y] = nullptr;
			board[newX][newY] = organism;
			animal->setXY(newX, newY);
		}
	}
	else {
		organism->collision(getOrganism(newX, newY), this);
	}
}

void World::removeFromBoard(Organism* organism) {
	board[organism->getX()][organism->getY()] = nullptr;
}

void World::addToBoard(Organism* organism) {
	board[organism->getX()][organism->getY()] = organism;
}

void World::killIfAnimal(Organism* organism) {
	if (Animal* a = dynamic_cast<Animal*>(organism)) {
		a->kill();
		if (!a->isAlive()) {
			std::cout << a->getName() << " nie zyje\n";
			removeFromBoard(organism);
		}
	}
}

void World::saveWorld() {
	std::ofstream file;
	file.open("simulation.save");
	file << getX() << " ";
	file << getY() << "\n";
	
	file << organismList.size() << "\n";

	for (Organism *organism : organismList) {
		file << organism->getName() << " ";
		file << organism->getX() << " ";
		file << organism->getY() << " ";
		file << organism->getForce() << " ";
		file << organism->getAge() << " ";
		file << organism->isAlive() << " ";
		file << organism->getBabyCount() << "\n";
	}

	file.close();
}

bool World::loadWorldFromFile() {
	std::ifstream file;
	file.open("simulation.save");

	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Error: nie udalo sie znalezc pliku z zapisem\n";
		return false;
	}

	file >> x;
	file >> y;

	createBoard(x, y);

	int organismsCount;
	file >> organismsCount;

	std::string name;
	int organismX, organismY, data;
	Organism* organism;

	for (int i = 0; i < organismsCount; i++) {
		file >> name;
		file >> organismX;
		file >> organismY;
		addOrganism(name, organismX, organismY);
		organism = getOrganism(organismX, organismY);

		file >> data;
		organism->setForce(data);

		file >> data;
		organism->setAge(data);

		file >> data;
		organism->setAlive(data);

		file >> data;
		organism->setBabyCount(data);
	}
	return true;
}