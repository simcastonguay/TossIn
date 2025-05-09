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
	OuvrirSprite(textureMure,"image/tileMap.png");
		

	IntRect typeBlock(0,0,100,100);

	const int largeurBlock = 16;
	const int hauteurBlock = 10;
	const int totalBlock = largeurBlock * hauteurBlock;
	const int sizeBlock = 100;

	//Vector maps
	vector<int> level;

	int indexNiveau = 0;

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
	if (!texturebox.loadFromFile("image/PenguinSheet.png")){
		cout << "Penguin sheet ne fonctionne pas !";
		return 1;
	}
		

	IntRect BCheck(0, 0, 100, 100);

	vector<RectangleShape> TroueV;

	char c;

	int count = 0;
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
				nouvelleBox.setTexture(&texturebox);
				nouvelleBox.setTextureRect(BCheck);
				boxes.push_back(nouvelleBox);
				level.back() = 2;
			}
			else if(valeur == 4){
				RectangleShape boxcheck;
				boxcheck.setPosition(x,y);
				boiteCheck.push_back(boxcheck);
			}
			else if (valeur == 3) {
				RectangleShape Troue;
				Troue.setPosition(x,y);
				TroueV.push_back(Troue);
			}
			count++;
		}
	};

	if (level.size() != totalBlock) {
		cout << "Le fichier semble corrompu" << endl;
	}

	fichier.close();

	RectangleShape mur;
	mur.setSize(Vector2f(sizeBlock, sizeBlock));
	mur.setTexture(&textureMure);

	int dir = 0;

	while (window.isOpen()) {

		Event event;

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

		bool noBlock = false;

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
					//noBlock = true;
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

		BoxetTroue(boxes,TroueV,boiteCheck,BCheck,level,sizeBlock,window,largeurBlock);

		if (Niveaureussi)
		{
			indexNiveau++;
		}
		window.display();

	}
};