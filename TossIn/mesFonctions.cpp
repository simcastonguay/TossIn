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

void OuvrirSprite(sf::Texture& texture, std::string nom)
{
	if (!texture.loadFromFile(nom))
	{
		cout << "L'ouverture du Sprite ne fonctionne pas";
		system("Pause>0");
		exit(1);
	}
}

void BoxetTroue(std::vector<sf::RectangleShape>& boxes, std::vector<sf::RectangleShape>& TroueV, std::vector<sf::RectangleShape>& boiteCheck, sf::IntRect& BCheck, std::vector<int>& level, int sizeBlock, sf::RenderWindow& window, int largeurBlock)
{

	for (auto& box : boxes) {
		for (auto& check : boiteCheck)
		{
			if (box.getPosition() == check.getPosition())
			{
				BCheck.left = 100;
				break;
			}
			else
			{
				BCheck.left = 0;
			}
		}

		int colonne = box.getPosition().x / sizeBlock;
		int ligne = box.getPosition().y / sizeBlock;
		int index = colonne + ligne * largeurBlock;

		for (auto& trou : TroueV)
		{

			if (box.getPosition() == trou.getPosition() && level.at(index) != 7)
			{
				BCheck.left = 200;
				level.at(index) = 7;
				box.setPosition(-100, -100);
				break;
			}
		}

		box.setTextureRect(BCheck);
		window.draw(box);
	}
}
