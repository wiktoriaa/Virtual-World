#include <iostream>
#include "World.h"

int main()
{
	int x, y;
	std::string input;
	World world;

	std::cout << "Czy chcesz wczytac ostani zapis swiata? (t/N) ";
	std::cin >> input;

	if (input == "t") { if (!world.loadWorldFromFile()) return 1; }
	else {
		std::cout << "Podaj wymiar swiata (x): ";
		std::cin >> x;
		std::cout << "Podaj wymiar swiata (y): ";
		std::cin >> y;

		world.createBoard(x, y);

		world.addOrganism("Wolf", 9, 9);
		world.addOrganism("Wolf", 9, 8);
		world.addOrganism("Wolf", 7, 9);
		world.addOrganism("Fox", 4, 4);
		world.addOrganism("Fox", 0, 9);
		world.addOrganism("Sheep", 5, 10);
		world.addOrganism("Sheep", 2, 0);
		world.addOrganism("Turtle", 11, 20);
		world.addOrganism("Turtle", 11, 18);
		world.addOrganism("Wolf", 15, 15);
		//world.addOrganism("WolfBerries", 12, 18);
		//world.addOrganism("Dandelion", 9, 13);

		//world.addOrganism("Antelope", 5, 9);
		//world.addOrganism("Antelope", 6, 9);
		world.addOrganism("Human", 5, 11);

	}

	while (1) {
		system("cls");
		world.drawWorld();
		world.round();
		std::cin.ignore();
		system("cls");
		world.drawWorld();
		std::cout << "s - zapisz swiat\n";
		std::cout << "e - wyjscie\n";
		std::cout << "ENTER- nastepna runda\n";
		std::getline(std::cin, input);
		if (input == "s") world.saveWorld();
		else if (input == "e") break;
	}
	
}
