#pragma once

int collisionMur(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock);

bool Niveaureussi(std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape>& check);

void OpenFichier(std::ifstream &inputs,int &index, std::string nom);

int collisionTroue(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock);

void ouvrirSprite(sf::Texture& texture,std::string nom);

void boxEtTroue(std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape>& TroueV, std::vector<sf::RectangleShape>& boiteCheck,sf::IntRect& BCheck, std::vector<int>& level,int sizeBlock,sf::RenderWindow& window, int largeurBlock);

void placerTileMap(int hauteurBlock, int largeurBlock, int sizeBlock, sf::IntRect& typeBlock, sf::RectangleShape& mur,sf::Texture& textureMure, sf::RenderWindow& window,std::vector<int>& level, int& dir);