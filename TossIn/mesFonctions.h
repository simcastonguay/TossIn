#pragma once

int collisionMur(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock);

bool Niveaureussi(std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape>& check);

void OpenFichier(std::ifstream &inputs,int &index, std::string nom);