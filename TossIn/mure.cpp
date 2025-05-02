#include<iostream>
#include<assert.h>
#include<vector>
#include<SFML/Graphics.hpp>
#include "mure.h"

using namespace std;
using namespace sf;

mure::mure()
{
	_blockPosX = 0;
	_blockPosY = 0;
	_size = 100;
	_couleurContours = sf::Color::White;
	_fillCouleur = sf::Color::Red;
}

mure::mure(int blockPositionX, int blockPositionY, int size, sf::Texture& textureMure)
{
	_mure.setPosition(blockPositionX, blockPositionY);
	_mure.setSize(Vector2f(size, size));
	_mure.setTexture(&textureMure);
}

void mure::setPosition(const int blockPositionX, const int blockPositionY)
{
	assert(blockPositionX >= 0 && blockPositionY >= 0);
	_mure.setPosition(blockPositionX, blockPositionY);
}

void mure::setBlockSize(const int size)
{
	assert(size >= 0);
	_mure.setSize(Vector2f(size, size));
}

int mure::getBlockPosX() const
{
	return _mure.getPosition().x;
}

int mure::getBlockPosY() const
{
	return _mure.getPosition().y;
}

int mure::getBlockSize() const
{
	return _size;
}

void mure::initialiserMure(int blockPositionX, int blockPositionY, int size, sf::Texture& textureMure)
{
	_mure.setPosition(blockPositionX, blockPositionY);
	_mure.setSize(Vector2f(size, size));
	_mure.setTexture(&textureMure);
}

void mure::draw(RenderWindow& window) const
{
	window.draw(_mure);
}
