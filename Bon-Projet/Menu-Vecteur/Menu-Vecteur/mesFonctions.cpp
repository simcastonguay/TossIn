#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<SFML/Graphics.hpp>
#include "mesFonctions.h"

using namespace std;
using namespace sf;


void levelChoice(sf::RenderWindow& windowMap, sf::Event& mapEvent, sf::RectangleShape& optionBoutonMap1)
{
}

ifstream openFichierLevel(int& indexNiveau)
{
	string nomLevel[5]{
		"level1.txt",
		"level2.txt",
		"level3.txt",
		"level4.txt"
	};

	ifstream fichier(nomLevel[indexNiveau]);

	if (!fichier) {
		cout << "Le fichier n'a pas pu ouvrir!" << endl;
	}

	return fichier;
}

if (mapEvent.type == Event::Closed)
{
    windowMap.close();
}
else if (mapEvent.type == Event::KeyPressed)
{
    switch (mapEvent.key.code)
    {
    case Keyboard::Escape:
        windowMap.close();
        //  music.stop();
        break;
    }
}
else if (optionBoutonMap1.getGlobalBounds().contains(optionsBoutonMap))
{
    optionBoutonMap1.setTexture(&boutonActuelHover);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        indexNiveau = 0;
        fichier = openFichierLevel(indexNiveau);

    }
}
else if (optionBoutonMap2.getGlobalBounds().contains(optionsBoutonMap))
{
    optionBoutonMap2.setTexture(&boutonMapHover);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        cout << "3";

    }
}
else if (optionBoutonMap3.getGlobalBounds().contains(optionsBoutonMap))
{
    optionBoutonMap3.setTexture(&boutonMapHover);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        cout << "4";

    }
}
else if (optionBoutonMap4.getGlobalBounds().contains(optionsBoutonMap))
{
    optionBoutonMap4.setTexture(&boutonMapHover);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        cout << "5";

    }
}
else if (optionBoutonMap5.getGlobalBounds().contains(optionsBoutonMap))
{
    optionBoutonMap5.setTexture(&boutonMapHover);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        cout << "6";

    }
}
else if (optionMenuRetour.getGlobalBounds().contains(optionsRetourMap))
{
    optionMenuRetour.setTexture(&menuRetourHover);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        cout << "1";
        windowMap.close();
    }
}