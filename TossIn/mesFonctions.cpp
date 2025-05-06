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