#include<iostream>
#include<vector>
#include <fstream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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

void ouvrirSprite(sf::Texture& texture, std::string nom)
{
	if (!texture.loadFromFile(nom))
	{
		cout << "L'ouverture du Fichier image ne fonctionne pas" << nom;
		system("Pause>0");
		exit(1);
	}
}

void boxEtTroue(std::vector<sf::RectangleShape>& boxes, std::vector<sf::RectangleShape>& TroueV, std::vector<sf::RectangleShape>& boiteCheck, sf::IntRect& BCheck, std::vector<int>& level, int sizeBlock, sf::RenderWindow& window, int largeurBlock)
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

void placerTileMap(int hauteurBlock, int largeurBlock, int sizeBlock, sf::IntRect& typeBlock, sf::RectangleShape& mur, sf::Texture& textureMure, sf::RenderWindow& window, std::vector<int>& level, int& dir)
{
	for (int j = 0; j < hauteurBlock; ++j) {
		for (int i = 0; i < largeurBlock; ++i) {
			int index = i + j * largeurBlock;
			int posX = i * sizeBlock;
			int posY = j * sizeBlock;
			typeBlock.top = 0;
			typeBlock.left = 0;

			switch (level[index]) {
			case 1:
				//Briques
				typeBlock.top = 0;
				typeBlock.left = 0;
				break;

			case 2:
				//Plancher
				typeBlock.top = 0;
				typeBlock.left = 100;
				break;

			case 3:
				//Troue
				typeBlock.top = 100;
				typeBlock.left = 0;
				break;

			case 4:
				//Cible
				typeBlock.top = 100;
				typeBlock.left = 100;
				break;
			case 7:
				typeBlock.left = 200;
				typeBlock.top = 0;
				break;
			default:
				break;
			}
			dir = 0;

			mur.setPosition(posX, posY);
			mur.setTextureRect(typeBlock);
			mur.setTexture(&textureMure);
			window.draw(mur);

		}
	}
}


void loadTextureMap(std::ifstream& fichier, char c, std::vector<int>& level, const int totalBlock, const int largeurBlock, const int sizeBlock, sf::RectangleShape &bonhomme, sf::Texture& textureBox, sf::IntRect bCheck, std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape> &boiteCheck, std::vector<sf::RectangleShape> &troueV, int count)
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

	if (level.size() != totalBlock) {
		cout << "Le fichier semble corrompu" << endl;
	}
	fichier.close();

}

void getEvent(int &compteur, sf::RenderWindow &window, sf::Event event, int& dir, bool& loadNiveau, sf::Sound &cliqueDeplacement)
{

	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) {
			loadNiveau = false;
			window.close();
		}

		else if (event.type == Event::KeyPressed) {
			switch (event.key.code) {
			case Keyboard::Escape:
				loadNiveau = false;
				window.close();
				break;

			case Keyboard::Up:
				cliqueDeplacement.play();
				dir = 1;
				compteur++;
				break;

			case Keyboard::Right:
				cliqueDeplacement.play();
				dir = 3;
				compteur++;
				break;

			case Keyboard::Down:
				cliqueDeplacement.play();
				dir = 2;
				compteur++;
				break;

			case Keyboard::Left:
				cliqueDeplacement.play();
				dir = 4;
				compteur++;
				break;

			case Keyboard::R:
				//RESTART NIVEAU
				window.close();
				window.display();
				break;

			default:
				break;
			}
		}
	}
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


std::ifstream openFichierHighScore(int highScore[6], int& indexNiveauChoisi, int& compteur)
{
	string nomHighScoreLevel[5]{
		"highScoreLevel1.txt",
		"highScoreLevel2.txt",
		"highScoreLevel3.txt",
		"highScoreLevel4.txt",
		"highScoreLevel5.txt"
	};

	ifstream fichierHighScore(nomHighScoreLevel[indexNiveauChoisi]);

	if (!fichierHighScore)
	{
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		fichierHighScore >> highScore[i];
	}

	highScore[5] = compteur;

	return fichierHighScore;
}

void trierHighScore(int highScore[6])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			if (highScore[i] > highScore[j]) {
				swap(highScore[i], highScore[j]);
			}
		}
	}
}

std::ifstream openFichierLevel(int& indexNiveau)
{
	string nomLevel[5]{
		"level1.txt",
		"level2.txt",
		"level3.txt",
		"level4.txt",
		"level5.txt"
	};

	ifstream fichier(nomLevel[indexNiveau]);

	if (!fichier) {
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
	}

	return fichier;
}

sf::IntRect spriteBonhomme(int dir, sf::Vector2f& prochainePosition, sf::IntRect& rectBonhomme)
{
	switch (dir) {

	case 1:
		prochainePosition.y -= 100;
		rectBonhomme.left = 100;
		rectBonhomme.top = 0;
		break;

	case 2:
		prochainePosition.y += 100;
		rectBonhomme.left = 0;
		rectBonhomme.top = 0;
		break;

	case 3:
		prochainePosition.x += 100;
		rectBonhomme.left = 0;
		rectBonhomme.top = 100;
		break;

	case 4:
		prochainePosition.x -= 100;
		rectBonhomme.left = 100;
		rectBonhomme.top = 200;
		break;
	}

	return rectBonhomme;
}

int collisionBox(std::vector<sf::RectangleShape>& boxes, sf::RectangleShape& box, sf::Vector2f& futureBoxPosition, bool collision)
{
	for (const auto& autreBox : boxes) {
		if (&autreBox != &box && autreBox.getPosition() == futureBoxPosition) {
			collision = true;
			break;
		}
	}
	return collision;
}

void deplacementBox(bool &collision, bool &aPousseUneBoite, bool &deplacementAutorise, sf::RectangleShape& box, sf::Vector2f& futureBoxPosition)
{
	if (!collision) {
		box.setPosition(futureBoxPosition);
		aPousseUneBoite = true;
	}
	else {
		deplacementAutorise = false;
	}
}

void deplacementBonhomme(bool& deplacementAutorise, bool& aPousseUneBoite, sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock, sf::RectangleShape& bonhomme)
{
	if ((deplacementAutorise || aPousseUneBoite) && !collisionMur(prochainePosition, level, sizeBlock, largeurBlock) && !collisionTroue(prochainePosition, level, sizeBlock, largeurBlock)) {
		bonhomme.setPosition(prochainePosition);
		
	}

}

void drawBonhomme(sf::RectangleShape& bonhomme, sf::RenderWindow& window, sf::Texture& textureBonhomme, sf::IntRect& rectBonhomme)
{
	bonhomme.setTexture(&textureBonhomme);
	bonhomme.setTextureRect(rectBonhomme);
	window.draw(bonhomme);

}

void updateFichier(std::ofstream& updateNiveau, int &indexNiveau, std::string nom, int &indexNiveauChoisi)
{
	updateNiveau.open(nom);

	if (!updateNiveau) {
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
		exit(1);
	}

	if (indexNiveau >= indexNiveauChoisi)
	{
		indexNiveau++;
		updateNiveau << indexNiveau;
		updateNiveau.close();
	}
	else
	{
		updateNiveau.close();
	}

}

void updateHighScore(std::ofstream& fichierScoreWrite, int highScore[6], int &indexNiveauChoisi)
{
	string nomHighScoreLevel[5]{
		"highScoreLevel1.txt",
		"highScoreLevel2.txt",
		"highScoreLevel3.txt",
		"highScoreLevel4.txt",
		"highScoreLevel5.txt"
	};

	fichierScoreWrite.open(nomHighScoreLevel[indexNiveauChoisi]);
	if (!fichierScoreWrite)
	{
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
		exit(1);
	}

	for (int i = 0; i < 5; i++)
	{
		fichierScoreWrite << highScore[i] << endl;
	}
	fichierScoreWrite.close();
}

