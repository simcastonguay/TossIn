#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"mesFonctions.h"

using namespace std;
using namespace sf;

int collisionMur(Vector2f prochainePosition, const vector<int>& level, int sizeBlock, int largeurBlock) {
	int colonne = prochainePosition.x / sizeBlock;
	int ligne = prochainePosition.y / sizeBlock;

	if (colonne < 0 || colonne >= largeurBlock || ligne < 0 || ligne >= 10)
		return true;

	int index = colonne + ligne * largeurBlock;
	return level[index] == 1; 
}