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

	Texture textureBonhomme;
	ouvrirSprite(textureBonhomme,"image/renauTileSheet.png");
	IntRect rectBonhomme(0,0,100,100);


	Texture textureMure;
	ouvrirSprite(textureMure,"image/tileMap.png");
		

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
		exit(1);
	}

	vector<RectangleShape> boxes;

	//Boite et initialisation
	std::vector<RectangleShape> boiteCheck;
	int countcheck = 0;

	Texture texturebox;
	ouvrirSprite(texturebox,"image/PenguinSheet.png");
		

	IntRect bCheck(0, 0, 100, 100);

	vector<RectangleShape> troueV;

	char c = '0';

	int count = 0;


	loadTextureMap(fichier, c, level, totalBlock, largeurBlock, sizeBlock, bonhomme, texturebox, bCheck, boxes, boiteCheck, troueV, count);

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

		window.clear();
		window.draw(fondEcran);

		placerTileMap(hauteurBlock,largeurBlock,sizeBlock,typeBlock,mur,textureMure,window,level,dir);


		bonhomme.setTexture(&textureBonhomme);
		bonhomme.setTextureRect(rectBonhomme);
		window.draw(bonhomme);

		dir = 0;

		boxEtTroue(boxes,troueV,boiteCheck,bCheck,level,sizeBlock,window,largeurBlock);

		if (Niveaureussi)
		{
			indexNiveau++;
		}
		window.display();

	}
};