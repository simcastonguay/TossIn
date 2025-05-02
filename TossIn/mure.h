#pragma once
class mure
{
private:
	int _blockPosX;
	int _blockPosY;
	int _size;
	sf::Texture _textureMure;
	sf::RectangleShape _mure;
	sf::Color _couleurContours;
	sf::Color _fillCouleur;

public:
	mure();
	mure(int blockPositionX, int blockPositionY, int size, sf::Texture& textureMure);

	//Setteur
	void setPosition(const int blockPositionX, const int blockPositionY);
	void setBlockSize(const int size);

	//Getteur
	int getBlockPosX() const;
	int getBlockPosY() const;
	int getBlockSize() const;


	void initialiserMure(int blockPositionX, int blockPositionY, int size, sf::Texture& textureMure);

	void draw(sf::RenderWindow& window) const;

};

