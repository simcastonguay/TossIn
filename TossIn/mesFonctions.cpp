#include<iostream>
#include<vector>
#include <fstream>
#include<SFML/Graphics.hpp>
#include"mesFonctions.h"

using namespace std;
using namespace sf;

//Test

int collisionMur(Vector2f prochainePosition, const vector<int>& level, int sizeBlock, int largeurBlock) {
	int colonne = prochainePosition.x / sizeBlock;
	int ligne = prochainePosition.y / sizeBlock;

	if (colonne < 0 || colonne >= largeurBlock || ligne < 0 || ligne >= 10)
		return true;

	int index = colonne + ligne * largeurBlock;
	return level[index] == 1; 
}

bool Niveaureussi(std::vector<sf::RectangleShape>& boxes, std::vector<sf::RectangleShape>& check)
{
	int count = 0;
	for (auto& box : boxes) {
		for (auto& bcheck : check)
		{
			if (box.getPosition() == bcheck.getPosition())
			{
				count++;
			}
		}
	}
	
	if (count >= check.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void OpenFichier(std::ifstream& inputs, int& index,std::string nom)
{
	inputs.open(nom);

	if (!inputs) {
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
		exit(1);
	}

	inputs >> index;

	inputs.close();
}

int collisionTroue(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock)
{
	int colonne = prochainePosition.x / sizeBlock;
	int ligne = prochainePosition.y / sizeBlock;

	if (colonne < 0 || colonne >= largeurBlock || ligne < 0 || ligne >= 10)
		return true;

	int index = colonne + ligne * largeurBlock;
	return level[index] == 3;
}

void loadTextureMap(std::ifstream& fichier, char c, std::vector<int>& level, const int totalBlock, const int largeurBlock, const int sizeBlock, sf::RectangleShape bonhomme, sf::Texture& textureBox, sf::IntRect bCheck, std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape> &boiteCheck, std::vector<sf::RectangleShape> &troueV, int count)
{
	while (fichier >> c && level.size() < totalBlock) {

		if (c >= '0' && c <= '6') {
			int valeur = c - '0';
			level.push_back(valeur);

			int x = (count % largeurBlock) * sizeBlock;
			int y = (count / largeurBlock) * sizeBlock;

			if (valeur == 5) {
				bonhomme.setPosition(x, y);
				level.back() = 2;
			}
			else if (valeur == 6) {
				RectangleShape nouvelleBox;
				nouvelleBox.setSize(Vector2f(sizeBlock, sizeBlock));
				nouvelleBox.setPosition(x, y);
				nouvelleBox.setTexture(&textureBox);
				nouvelleBox.setTextureRect(bCheck);
				boxes.push_back(nouvelleBox);
				level.back() = 2;
			}
			else if (valeur == 4) {
				RectangleShape boxcheck;
				boxcheck.setPosition(x, y);
				boiteCheck.push_back(boxcheck);
			}
			else if (valeur == 3) {
				RectangleShape Troue;
				Troue.setPosition(x, y);
				troueV.push_back(Troue);
			}
			count++;
		}
	};
}

int getEvent(sf::RenderWindow &window, sf::Event event, int dir)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) {
			window.close();
		}

		else if (event.type == Event::KeyPressed) {
			switch (event.key.code) {
			case Keyboard::Escape:

				window.close();
				break;

			case Keyboard::Up:

				dir = 1;
				break;

			case Keyboard::Right:

				dir = 3;
				break;

			case Keyboard::Down:

				dir = 2;
				break;

			case Keyboard::Left:

				dir = 4;
				break;
			}
		}
	}
	return dir;
}

sf::Vector2f getFuturBoxPosition(sf::Vector2f futureBoxPosition, int dir)
{
	switch (dir) {
	case 1:
		futureBoxPosition.y -= 100;
		break;

	case 2:
		futureBoxPosition.y += 100;
		break;

	case 3:
		futureBoxPosition.x += 100;
		break;

	case 4:
		futureBoxPosition.x -= 100;
		break;
	}

	return futureBoxPosition;
}


