#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<string>
#include<fstream>
#include"mesFonctions.h"

using namespace std;
using namespace sf;


int main() {
	int width = 1600, height = 1000;
	RenderWindow window(VideoMode(width, height), "Toss in!");
	window.setFramerateLimit(60);

	RectangleShape fondEcran;
	fondEcran.setPosition(0, 0);
	fondEcran.setSize(Vector2f(width, height));
	fondEcran.setFillColor(Color::Black);

	//bonhomme
	RectangleShape bonhomme;
	bonhomme.setPosition(200, 200);
	bonhomme.setSize(Vector2f(100, 100));
	bonhomme.setFillColor(Color::White);

	Texture textureMure;
	if (!textureMure.loadFromFile("image/tileMap.png"))
	{
		cout << "Tile Map ne fonctionne pas";
		system("Pause>0");
		return 1;
	}
		

	IntRect typeBlock(0,0,100,100);

	const int largeurBlock = 16;
	const int hauteurBlock = 10;
	const int totalBlock = largeurBlock * hauteurBlock;
	const int sizeBlock = 100;

	//Vector maps
	vector<int> level;

	int indexNiveau = 0;

	//get le niveau dans updateNiveau.txt
	ifstream index;
	OpenFichier(index,indexNiveau,"updateNiveau.txt");

	string nomLevel[5]{
		"level1.txt",
		"level2.txt",
		"level3.txt",
		"level4.txt"
	};

	//Lecture fichier level
	ifstream fichier(nomLevel[indexNiveau]);

	if (!fichier) {
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
		return 1;
	}

	vector<RectangleShape> boxes;

	//Boite et initialisation
	std::vector<RectangleShape> boiteCheck;
	int countcheck = 0;
	Texture textureBox;
	if (!textureBox.loadFromFile("image/PenguinSheet.png")){
		cout << "Penguin sheet ne fonctionne pas !";
		return 1;
	}
		

	IntRect bCheck(0, 0, 100, 100);

	vector<RectangleShape> troueV;

	char c = '0';

	int count = 0;


	loadTextureMap(fichier, c, level, totalBlock, largeurBlock, sizeBlock, bonhomme, textureBox, bCheck, boxes, boiteCheck, troueV, count);

	if (level.size() != totalBlock) {
		cout << "Le fichier semble corrompu" << endl;
	}

	fichier.close();

	RectangleShape mur;
	mur.setSize(Vector2f(sizeBlock, sizeBlock));
	mur.setTexture(&textureMure);

	int dir = 0;

	while (window.isOpen()) {

		Event event{};

		dir = getEvent(window, event, dir);

		Vector2f prochainePosition = bonhomme.getPosition();


		switch (dir) {

		case 1: 
			prochainePosition.y -= 100; 
			break;

		case 2: 
			prochainePosition.y += 100; 
			break;

		case 3: 
			prochainePosition.x += 100; 
			break;

		case 4: 
			prochainePosition.x -= 100; 
			break;
		}

		bool deplacementAutorise = true;
		bool aPousseUneBoite = false;

		for (auto& box : boxes) {
			if (prochainePosition == box.getPosition()) {

				Vector2f futureBoxPosition = box.getPosition();

				futureBoxPosition = getFuturBoxPosition(futureBoxPosition, dir);

				bool collision = collisionMur(futureBoxPosition, level, sizeBlock, largeurBlock);
				

				for (const auto& autreBox : boxes) {
					if (&autreBox != &box && autreBox.getPosition() == futureBoxPosition) {
						collision = true;
						break;
					}
				}

				if (!collision) {
					box.setPosition(futureBoxPosition);
					aPousseUneBoite = true;
				}
				else {
					deplacementAutorise = false;
				}
			}
		}

		if ((deplacementAutorise || aPousseUneBoite) && !collisionMur(prochainePosition, level, sizeBlock, largeurBlock) && !collisionTroue(prochainePosition, level, sizeBlock, largeurBlock)) {
			bonhomme.setPosition(prochainePosition);
		}

		dir = 0; 	

		window.clear();
		window.draw(fondEcran);

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
		window.draw(bonhomme);
		int count = 0;
		for (auto& box : boxes) {
			for (auto& check : boiteCheck)
			{
				if (box.getPosition() == check.getPosition())
				{
					bCheck.left = 100;
					break;
				}
				else
				{
					bCheck.left = 0;
				}
			}

			int colonne = box.getPosition().x / sizeBlock;
			int ligne = box.getPosition().y / sizeBlock;
			int index = colonne + ligne * largeurBlock;

			for (auto& trou : troueV)
			{
				
				if (box.getPosition() == trou.getPosition() && level.at(index) != 7)
				{
					bCheck.left = 200;
					level.at(index) = 7;
					box.setPosition(-100,-100);
					break;
				}
				count++;
			}

			box.setTextureRect(bCheck);
			window.draw(box);
		}

		if (Niveaureussi)
		{
			indexNiveau++;
		}
		window.display();

	}
};