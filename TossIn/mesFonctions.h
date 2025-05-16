#pragma once

int collisionMur(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock);

bool Niveaureussi(std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape>& check);

void OpenFichier(std::ifstream &inputs,int &index, std::string nom);

int collisionTroue(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock);

void ouvrirSprite(sf::Texture& texture,std::string nom);

void boxEtTroue(std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape>& TroueV, std::vector<sf::RectangleShape>& boiteCheck,sf::IntRect& BCheck, std::vector<int>& level,int sizeBlock,sf::RenderWindow& window, int largeurBlock);

void placerTileMap(int hauteurBlock, int largeurBlock, int sizeBlock, sf::IntRect& typeBlock, sf::RectangleShape& mur,sf::Texture& textureMure, sf::RenderWindow& window,std::vector<int>& level, int& dir);

int collisionTroue(sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock);

void loadTextureMap(std::ifstream& fichier, char c, std::vector<int>& level, const int totalBlock, const int largeurBlock, const int sizeBlock, sf::RectangleShape &bonhomme, sf::Texture& textureBox, sf::IntRect bCheck, std::vector<sf::RectangleShape> &boxes, std::vector<sf::RectangleShape> &boiteCheck, std::vector<sf::RectangleShape> &troueV, int count);

void getEvent(int &compteur, sf::RenderWindow &window, sf::Event event, int& dir, bool& loadNiveau, sf::Sound& cliqueDeplacement);

sf::Vector2f getFuturBoxPosition(sf::Vector2f futureBoxPosition, int dir);

std::ifstream openFichierHighScore(int highScore[6], int& indexNiveau, int&compteur);

void trierHighScore(int highScore[6]);

std::ifstream openFichierLevel(int& indexNiveau);

sf::IntRect spriteBonhomme(int dir, sf::Vector2f& prochainePosition, sf::IntRect& rectBonhomme);

int collisionBox(std::vector<sf::RectangleShape> &boxes, sf::RectangleShape &box, sf::Vector2f &futureBoxPosition, bool collision);

void deplacementBox(bool &collision, bool &aPousseUneBoite, bool &deplacementAutorise, sf::RectangleShape& box, sf::Vector2f& futureBoxPosition);

void deplacementBonhomme(bool& deplacementAutorise, bool& aPousseUneBoite, sf::Vector2f prochainePosition, const std::vector<int>& level, int sizeBlock, int largeurBlock, sf::RectangleShape &bonhomme);

void drawBonhomme(sf::RectangleShape& bonhomme, sf::RenderWindow& window, sf::Texture& textureBonhomme, sf::IntRect& rectBonhomme);

void updateFichier(std::ofstream& updateNiveau, int &indexNiveau, std::string nom);

void updateHighScore(std::ofstream& fichierScoreWrite, int highScore[6], int indexNiveau);