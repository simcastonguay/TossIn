#include<iostream>
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<vector>
#include<string>
#include<fstream>
#include"mesFonctions.h"
#include "Game.h"

using namespace std;
using namespace sf;

void Game::play()
{
    RenderWindow windowMenu(VideoMode(1200, 800), "Menu Principal"); //Menu Principal

    int indexNiveau = 0;
    ifstream fichier;

    bool loadNiveau = false;

    /////////////////VECTEUR ET TEXTURE PERSONNAGES////////////////////

    vector<sf::Texture> texturesPersonnages;

    sf::Texture renau;
    if (!renau.loadFromFile("image/RenauMenu.png")) {
        std::cout << "Erreur de chargement de la texture Renau.\n";
    }
    texturesPersonnages.push_back(renau);

    sf::Texture genevieve;
    if (!genevieve.loadFromFile("image/GenevieveMenu.png")) {
        std::cout << "Erreur de chargement de la texture de Genevieve.\n";
    }
    texturesPersonnages.push_back(genevieve);

    sf::Texture josianne;
    if (!josianne.loadFromFile("image/JosianneMenu.png")) {
        std::cout << "Erreur de chargement de la texture de Josianne.\n";
    }
    texturesPersonnages.push_back(josianne);

    int selection = 0; // le num�ro du personnage
    sf::Sprite personnage;
    personnage.setTexture(texturesPersonnages[selection]);
    personnage.setPosition(420, 155);

    ////////////////////////MUSIQUES////////////////////////

    sf::Music musicMenu;
    musicMenu.openFromFile("menu.wav");
    musicMenu.setLoop(true);
    musicMenu.play();

    sf::SoundBuffer deplacement;
    deplacement.loadFromFile("deplacement.wav");
    sf::Sound cliqueDeplacement;
    cliqueDeplacement.setBuffer(deplacement);

    sf::SoundBuffer goodPlacing;
    goodPlacing.loadFromFile("placing.wav");
    sf::Sound bonEmplacement;
    bonEmplacement.setBuffer(goodPlacing);


    ///////////////////BACKGROUND DU MENU///////////////////

    sf::Texture mainMenu;
    ouvrirSprite(mainMenu,"image/BGMainMenu.png");

    sf::RectangleShape menu;
    menu.setSize({ 1200.f, 800.f });
    menu.setTexture(&mainMenu);

    sf::Texture selectionPersonnage;
    ouvrirSprite(selectionPersonnage,"image/BGCharacterSelect.png");

    sf::RectangleShape menuPersonnage;
    menuPersonnage.setSize({ 1200.f, 800.f });
    menuPersonnage.setTexture(&selectionPersonnage);

    sf::Texture chargerPartie;
    ouvrirSprite(chargerPartie, "image/BGCharacterSelect.png");
    sf::RectangleShape menuChargerPartie;
    menuChargerPartie.setSize({ 1200.f, 800.f });
    menuChargerPartie.setTexture(&chargerPartie);

    sf::Texture bgControles;
    ouvrirSprite(bgControles, "image/BGControle.png");
    sf::RectangleShape menuControle;
    menuControle.setSize({ 1200.f, 800.f });
    menuControle.setTexture(&bgControles);

    sf::Texture bgHS;
    ouvrirSprite(bgHS, "image/BGHighScore.png");

    sf::RectangleShape menuHS;
    menuHS.setSize({ 1200.f, 800.f });
    menuHS.setTexture(&bgHS);

    sf::Texture bgMap;
    ouvrirSprite(bgMap, "image/BGMap.png");

    sf::RectangleShape menuMap;
    menuMap.setSize({ 1200.f, 800.f });
    menuMap.setTexture(&bgMap);

    //////////////////BOUTONS DU MENU PRINCIPAL///////////

    sf::Texture menuJouer;
    ouvrirSprite(menuJouer, "image/Jouer.png");

    sf::RectangleShape mainJouer;
    mainJouer.setSize({ 237.f, 74.f });
    mainJouer.setPosition(10, 345);
    mainJouer.setTexture(&menuJouer);

    sf::Texture menuCharger;
    ouvrirSprite(menuCharger, "image/Charger.png");

    sf::Texture menuChargerHover;
    ouvrirSprite(menuChargerHover, "image/ChargerHover.png");
    
    sf::RectangleShape mainCharger;
    mainCharger.setSize({ 331.f, 75.f });
    mainCharger.setPosition(10, 445);
    mainCharger.setTexture(&menuCharger);

    sf::Texture menuControl;
    ouvrirSprite(menuControl, "image/Controles.png");

    sf::Texture menuControlHover;
    ouvrirSprite(menuControlHover, "image/ControlesHover.png");

    sf::RectangleShape mainControl;
    mainControl.setSize({ 407.f, 72.f });
    mainControl.setPosition(10, 545);
    mainControl.setTexture(&menuControl);

    sf::Texture menuBoutonHS;
    ouvrirSprite(menuBoutonHS, "image/HighScores.png");

    sf::Texture menuHSHover;
    ouvrirSprite(menuHSHover, "image/HighScoresHover.png");

    sf::RectangleShape mainHS;
    mainHS.setSize({ 475.f, 76.f });
    mainHS.setPosition(10, 645);
    mainHS.setTexture(&menuBoutonHS);


    //////////////BOUTON DANS LES SOUS-MENUS////////////

    sf::RectangleShape optionMenuJouer({ 237.f, 74.f });
    optionMenuJouer.setPosition(953, 716);
    optionMenuJouer.setTexture(&menuJouer);

    sf::Texture menuJouerHover;
    ouvrirSprite(menuJouerHover, "image/JouerHover.png");

    sf::Texture menuRetour;
    ouvrirSprite(menuRetour, "image/Retour.png");

    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
    optionMenuRetour.setTexture(&menuRetour);
    optionMenuRetour.setPosition(10, 10);

    sf::Texture menuRetourHover;
    ouvrirSprite(menuRetourHover, "image/RetourHover.png");

    ///////////////////// FLECHE PERSONNAGE /////////////////////////

    sf::Texture flecheGauche;
    ouvrirSprite(flecheGauche, "image/FlecheGauche.png");

    sf::Texture flecheDroite;
    ouvrirSprite(flecheDroite, "image/FlecheDroite.png");

    sf::RectangleShape optionPersoGauche({ 125.f, 124.f });
    optionPersoGauche.setTexture(&flecheGauche);
    optionPersoGauche.setPosition(240, 280);

    sf::RectangleShape optionPersoDroite({ 125.f, 124.f });
    optionPersoDroite.setTexture(&flecheDroite);
    optionPersoDroite.setPosition(840, 280);

    /////////////////////////SAUVEGARDE DE NIVEAU////////////////////////////

    ifstream index;
    OpenFichier(index, indexNiveau, "updateNiveau.txt");

    ////////////////////////COMPTEUR HIGH-SCORE////////////////////////////

    ifstream meilleursScores;
    //vector<sf::> compteur;


    while (windowMenu.isOpen())
    {


        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente     it�ration
        Event event;


        while (windowMenu.pollEvent(event))
        {
            ///////////////D�TECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
            sf::Vector2f optionsMenu = windowMenu.mapPixelToCoords(sf::Mouse::getPosition(windowMenu));
            ////////////////PERMET DE RESET LA TEXTURE QUAND SOURIS N'EST PLUS DESSUS////////////////
            mainJouer.setTexture(&menuJouer);
            mainCharger.setTexture(&menuCharger);
            mainControl.setTexture(&menuControl);
            mainHS.setTexture(&menuBoutonHS);

            // �v�nement "fermeture demand�e" : on ferme la fen�tre
            if (event.type == Event::Closed)
            {
                windowMenu.close();
            }
            else if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case Keyboard::Escape:
                    windowMenu.close();
                    //  music.stop();
                    break;
                }
            }
            else if (mainJouer.getGlobalBounds().contains(optionsMenu))
            {

                mainJouer.setTexture(&menuJouerHover); // Hover   

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !loadNiveau)
                {
                    RenderWindow windowCharacter(VideoMode(1200, 800), "S�lection du personnage");




                    while (windowCharacter.isOpen())
                    {
                        Event characterEvent;

                        while (windowCharacter.pollEvent(characterEvent))
                        {
                            ///////////////D�TECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
                            sf::Vector2f optionsRetourPerso = windowCharacter.mapPixelToCoords(sf::Mouse::getPosition(windowCharacter));
                            sf::Vector2f optionsJouerPerso = windowCharacter.mapPixelToCoords(sf::Mouse::getPosition(windowCharacter));
                            ////////////////PERMET DE RESET LA TEXTURE QUAND SOURIS N'EST PLUS DESSUS////////////////
                            optionMenuJouer.setTexture(&menuJouer);
                            optionMenuRetour.setTexture(&menuRetour);

                            if (characterEvent.type == Event::Closed)
                            {

                                windowCharacter.close();
                            }
                            else if (characterEvent.type == Event::KeyPressed)
                            {
                                switch (characterEvent.key.code)
                                {
                                case Keyboard::Escape:
                                    windowCharacter.close();
                                    break;
                                }
                            }

                            if (characterEvent.type == Event::KeyPressed) {

                                if (characterEvent.key.code == sf::Keyboard::D) {
                                    cliqueDeplacement.play();

                                    selection = (selection + 1) % texturesPersonnages.size(); //peut pas faire selection++ sinon fait pas de boucle
                                    personnage.setTexture(texturesPersonnages[selection]);

                                }
                            }
                            if (characterEvent.type == Event::KeyPressed) {

                                if (characterEvent.key.code == sf::Keyboard::A) {
                                    cliqueDeplacement.play();

                                    selection--;
                                    if (selection < 0)
                                    {
                                        selection = texturesPersonnages.size() - 1; //vas au dernier (ici le 3e)
                                    }
                                    personnage.setTexture(texturesPersonnages[selection]);

                                }
                            }
                            else if (optionMenuJouer.getGlobalBounds().contains(optionsJouerPerso))
                            {

                                optionMenuJouer.setTexture(&menuJouerHover);

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                {
                                    RenderWindow windowMap(VideoMode(1200, 800), "S�lection d'un niveau");
                                    windowCharacter.close();

                                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                                    optionMenuRetour.setTexture(&menuRetour);
                                    optionMenuRetour.setPosition(10, 10);

                                    sf::Texture boutonMap;
                                    ouvrirSprite(boutonMap, "image/BoutonNonComplete.png");

                                    sf::Texture boutonMapHover;
                                    ouvrirSprite(boutonMapHover, "image/HoverBoutonNonComplete.png");

                                    sf::Texture boutonComplete;
                                    ouvrirSprite(boutonComplete, "image/BoutonComplete.png");

                                    sf::Texture boutonCompleteHover;
                                    ouvrirSprite(boutonCompleteHover, "image/HoverBoutonComplete.png");

                                    sf::Texture boutonActuel;
                                    ouvrirSprite(boutonActuel, "image/BoutonActuel.png");

                                    sf::Texture boutonActuelHover;
                                    ouvrirSprite(boutonActuelHover, "image/BoutonActuelHover.png");


                                    sf::RectangleShape optionBoutonMap1({ 136.f, 89.f });
                                    optionBoutonMap1.setPosition(111, 351);
                                    optionBoutonMap1.setTexture(&boutonActuel);

                                    sf::RectangleShape optionBoutonMap2({ 136.f, 89.f });
                                    optionBoutonMap2.setPosition(413, 327);
                                    optionBoutonMap2.setTexture(&boutonMap);

                                    sf::RectangleShape optionBoutonMap3({ 136.f, 89.f });
                                    optionBoutonMap3.setPosition(731, 205);
                                    optionBoutonMap3.setTexture(&boutonMap);

                                    sf::RectangleShape optionBoutonMap4({ 152.f, 100.f });
                                    optionBoutonMap4.setPosition(701, 490);
                                    optionBoutonMap4.setTexture(&boutonMap);

                                    sf::RectangleShape optionBoutonMap5({ 136.f, 89.f });
                                    optionBoutonMap5.setPosition(1016, 358);
                                    optionBoutonMap5.setTexture(&boutonMap);

                                    while (windowMap.isOpen() && !loadNiveau)
                                    {
                                        Event mapEvent;

                                        while (windowMap.pollEvent(mapEvent))
                                        {
                                            ///////////////D�TECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
                                            sf::Vector2f optionsRetourMap = windowMap.mapPixelToCoords(sf::Mouse::getPosition(windowMap));
                                            sf::Vector2f optionsBoutonMap = windowMap.mapPixelToCoords(sf::Mouse::getPosition(windowMap));


                                            switch (indexNiveau) {
                                            case 0:
                                                optionBoutonMap1.setTexture(&boutonActuel);
                                                optionBoutonMap2.setTexture(&boutonMap);
                                                optionBoutonMap3.setTexture(&boutonMap);
                                                optionBoutonMap4.setTexture(&boutonMap);
                                                optionBoutonMap5.setTexture(&boutonMap);
                                                optionMenuRetour.setTexture(&menuRetour);
                                                break;

                                            case 1:
                                                optionBoutonMap1.setTexture(&boutonComplete);
                                                optionBoutonMap2.setTexture(&boutonActuel);
                                                optionBoutonMap3.setTexture(&boutonMap);
                                                optionBoutonMap4.setTexture(&boutonMap);
                                                optionBoutonMap5.setTexture(&boutonMap);
                                                optionMenuRetour.setTexture(&menuRetour);
                                                break;

                                            case 2:
                                                optionBoutonMap1.setTexture(&boutonComplete);
                                                optionBoutonMap2.setTexture(&boutonComplete);
                                                optionBoutonMap3.setTexture(&boutonActuel);
                                                optionBoutonMap4.setTexture(&boutonActuel);
                                                optionBoutonMap5.setTexture(&boutonMap);
                                                optionMenuRetour.setTexture(&menuRetour);
                                                break;

                                            case 3:
                                                optionBoutonMap1.setTexture(&boutonComplete);
                                                optionBoutonMap2.setTexture(&boutonComplete);
                                                optionBoutonMap3.setTexture(&boutonActuel);
                                                optionBoutonMap4.setTexture(&boutonActuel);
                                                optionBoutonMap5.setTexture(&boutonMap);
                                                optionMenuRetour.setTexture(&menuRetour);
                                                break;

                                            case 4:
                                                optionBoutonMap1.setTexture(&boutonComplete);
                                                optionBoutonMap2.setTexture(&boutonComplete);
                                                optionBoutonMap3.setTexture(&boutonComplete);
                                                optionBoutonMap4.setTexture(&boutonComplete);
                                                optionBoutonMap5.setTexture(&boutonActuel);
                                                optionMenuRetour.setTexture(&menuRetour);
                                                break;
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
                                                    break;
                                                }
                                            }
                                            else if (optionBoutonMap1.getGlobalBounds().contains(optionsBoutonMap))
                                            {
                                                if (indexNiveau == 0) {
                                                    optionBoutonMap1.setTexture(&boutonActuelHover);

                                                }
                                                else if (indexNiveau > 0) {
                                                    optionBoutonMap1.setTexture(&boutonCompleteHover);
                                                }
                                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                                {
                                                    indexNiveau = 0;
                                                    fichier = openFichierLevel(indexNiveau);
                                                    loadNiveau = true;

                                                }
                                            }
                                            else if (optionBoutonMap2.getGlobalBounds().contains(optionsBoutonMap))
                                            {
                                                if (indexNiveau == 1) {
                                                    optionBoutonMap2.setTexture(&boutonActuelHover);

                                                }
                                                else if (indexNiveau > 1) {
                                                    optionBoutonMap2.setTexture(&boutonCompleteHover);
                                                }

                                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                                {
                                                    indexNiveau = 1;
                                                    fichier = openFichierLevel(indexNiveau);
                                                    loadNiveau = true;
                                                }
                                            }
                                            else if (optionBoutonMap3.getGlobalBounds().contains(optionsBoutonMap))
                                            {
                                                if (indexNiveau == 2) {
                                                    optionBoutonMap3.setTexture(&boutonActuelHover);

                                                }
                                                else if (indexNiveau > 2) {
                                                    optionBoutonMap3.setTexture(&boutonCompleteHover);
                                                }
                                                else if (indexNiveau < 2) {
                                                    optionBoutonMap3.setTexture(&boutonMapHover);
                                                }

                                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                                {
                                                    indexNiveau = 2;
                                                    fichier = openFichierLevel(indexNiveau);
                                                    loadNiveau = true;

                                                }
                                            }
                                            else if (optionBoutonMap4.getGlobalBounds().contains(optionsBoutonMap))
                                            {
                                                if (indexNiveau == 3) {
                                                    optionBoutonMap4.setTexture(&boutonActuelHover);

                                                }
                                                else if (indexNiveau > 3) {
                                                    optionBoutonMap4.setTexture(&boutonCompleteHover);
                                                }
                                                else if (indexNiveau < 3) {
                                                    optionBoutonMap4.setTexture(&boutonMapHover);
                                                }

                                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                                {
                                                    indexNiveau = 3;
                                                    fichier = openFichierLevel(indexNiveau);
                                                    loadNiveau = true;

                                                }
                                            }
                                            else if (optionBoutonMap5.getGlobalBounds().contains(optionsBoutonMap))
                                            {
                                                if (indexNiveau == 4) {
                                                    optionBoutonMap5.setTexture(&boutonActuelHover);

                                                }
                                                else if (indexNiveau > 4) {
                                                    optionBoutonMap5.setTexture(&boutonCompleteHover);
                                                }
                                                else if (indexNiveau < 4) {
                                                    optionBoutonMap5.setTexture(&boutonMapHover);
                                                }

                                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                                {
                                                    indexNiveau = 4;
                                                    fichier = openFichierLevel(indexNiveau);
                                                    loadNiveau = true;
                                                }
                                            }
                                            else if (optionMenuRetour.getGlobalBounds().contains(optionsRetourMap))
                                            {
                                                optionMenuRetour.setTexture(&menuRetourHover);

                                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                                {
                                                    windowMap.close();
                                                }
                                            }
                                            windowMap.clear();
                                            windowMap.draw(menuMap);
                                            windowMap.draw(optionBoutonMap1);
                                            windowMap.draw(optionBoutonMap2);
                                            windowMap.draw(optionBoutonMap3);
                                            windowMap.draw(optionBoutonMap4);
                                            windowMap.draw(optionBoutonMap5);
                                            windowMap.draw(optionMenuRetour);
                                            windowMap.display();

                                        }
                                    }

                                }
                            }


                            else if (optionMenuRetour.getGlobalBounds().contains(optionsRetourPerso))
                            {
                                optionMenuRetour.setTexture(&menuRetourHover);
                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                {
                                    windowCharacter.close();
                                }
                            }

                        }

                        if (!loadNiveau) {
                            windowCharacter.clear();
                            windowCharacter.draw(menuPersonnage);
                            windowCharacter.draw(personnage);
                            windowCharacter.draw(optionPersoDroite);
                            windowCharacter.draw(optionPersoGauche);
                            windowCharacter.draw(optionMenuRetour);
                            windowCharacter.draw(optionMenuJouer);
                            windowCharacter.display();
                        }
                    }
                }
            }

            /////////////////// FIN BOUTTON JOUER ///////////////////
            else if (mainCharger.getGlobalBounds().contains(optionsMenu))
            {
                mainCharger.setTexture(&menuChargerHover);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    loadNiveau = true;
                }

            }
            //////////////////FIN BOUTON CHARGER////////////////////

            else if (mainControl.getGlobalBounds().contains(optionsMenu))
            {
                mainControl.setTexture(&menuControlHover);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    RenderWindow windowControles(VideoMode(1200, 800), "Comment jouer ?");

                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                    optionMenuRetour.setTexture(&menuRetour);
                    optionMenuRetour.setPosition(10, 10);
                    while (windowControles.isOpen())
                    {
                        Event controleEvent;

                        while (windowControles.pollEvent(controleEvent))
                        {
                            ///////////////D�TECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
                            sf::Vector2f optionsRetour = windowControles.mapPixelToCoords(sf::Mouse::getPosition(windowControles));
                            ////////////////PERMET DE RESET LA TEXTURE QUAND SOURIS N'EST PLUS DESSUS////////////////
                            optionMenuRetour.setTexture(&menuRetour);

                            if (controleEvent.type == Event::Closed)
                            {
                                windowControles.close();
                            }
                            else if (controleEvent.type == Event::KeyPressed)
                            {
                                switch (controleEvent.key.code)
                                {
                                case Keyboard::Escape:
                                    windowControles.close();
                                    //  music.stop();
                                    break;
                                }
                            }
                            else if (optionMenuRetour.getGlobalBounds().contains(optionsRetour))
                            {
                                optionMenuRetour.setTexture(&menuRetourHover);

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                {
                                    cout << "1";
                                    windowControles.close();
                                }
                            }


                            windowControles.clear();
                            windowControles.draw(menuControle);
                            windowControles.draw(optionMenuRetour);
                            windowControles.display();
                        }
                    }
                }

            }
            ///////////////////FIN BOUTON CONTROLE////////////////
            else if (mainHS.getGlobalBounds().contains(optionsMenu))
            {
                mainHS.setTexture(&menuHSHover);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {

                    RenderWindow windowHS(VideoMode(1200, 800), "Meilleurs Scores");


                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                    optionMenuRetour.setTexture(&menuRetour);
                    optionMenuRetour.setPosition(10, 10);
                    while (windowHS.isOpen())
                    {
                        Event highscoreEvent;

                        while (windowHS.pollEvent(highscoreEvent))
                        {
                            ///////////////D�TECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
                            sf::Vector2f optionsRetour = windowHS.mapPixelToCoords(sf::Mouse::getPosition(windowHS));
                            ////////////////PERMET DE RESET LA TEXTURE QUAND SOURIS N'EST PLUS DESSUS////////////////
                            optionMenuRetour.setTexture(&menuRetour);
                            if (highscoreEvent.type == Event::Closed)
                            {
                                windowHS.close();
                            }
                            else if (highscoreEvent.type == Event::KeyPressed)
                            {
                                switch (highscoreEvent.key.code)
                                {
                                case Keyboard::Escape:
                                    windowHS.close();
                                    //  music.stop();
                                    break;
                                }
                            }
                            else if (optionMenuRetour.getGlobalBounds().contains(optionsRetour))
                            {
                                optionMenuRetour.setTexture(&menuRetourHover);

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                                {
                                    cout << "1";
                                    windowHS.close();
                                }
                            }

                            windowHS.clear();
                            windowHS.draw(menuHS);
                            windowHS.draw(optionMenuRetour);
                            windowHS.display();
                        }
                    }
                }
            }
            ////////////////////FIN BOUTON HIGH-SCORE/////////////
        }

        windowMenu.clear();
        windowMenu.draw(menu);
        windowMenu.draw(mainJouer);
        windowMenu.draw(mainCharger);
        windowMenu.draw(mainControl);
        windowMenu.draw(mainHS);
        windowMenu.display();

        if (loadNiveau == true) {
            musicMenu.stop();
            int width = 1600, height = 1000;
            RenderWindow window(VideoMode(width, height), "Toss in!");
            window.setFramerateLimit(60);

            RectangleShape fondEcran;
            fondEcran.setPosition(0, 0);
            fondEcran.setSize(Vector2f(width, height));
            fondEcran.setFillColor(Color::Black);


            //TEXTURE BONHOMME
            RectangleShape bonhomme;
            bonhomme.setPosition(200, 200);
            bonhomme.setSize(Vector2f(100, 100));
            bonhomme.setFillColor(Color::White);

            Texture textureBonhomme;
            IntRect rectBonhomme(0, 0, 100, 100);
            if (selection == 0) {
                ouvrirSprite(textureBonhomme, "image/renauTileSheet.png");

            }
            else if (selection == 1)
            {
                ouvrirSprite(textureBonhomme, "image/GenevieveTileSheet.png");

            }
            else if (selection == 2)
            {
                ouvrirSprite(textureBonhomme, "image/JosianneTileSheet.png");

            }

            //TEXTURE DES MURS//
            Texture textureMure;
            ouvrirSprite(textureMure, "image/tileMap.png");


            IntRect typeBlock(0, 0, 100, 100);

            const int largeurBlock = 16;
            const int hauteurBlock = 10;
            const int totalBlock = largeurBlock * hauteurBlock;
            const int sizeBlock = 100;

            //Vector maps
            vector<int> level;

            //int indexNiveau = 0;

            //get le niveau dans updateNiveau.txt

            //ifstream fichier;

            fichier = openFichierLevel(indexNiveau);


            vector<RectangleShape> boxes;

            //Boite et initialisation
            std::vector<RectangleShape> boiteCheck;
            int countcheck = 0;

            Texture texturebox;
            ouvrirSprite(texturebox, "image/PenguinSheet.png");


            IntRect bCheck(0, 0, 100, 100);

            vector<RectangleShape> troueV;

            char c = '0';

            int count = 0;


            loadTextureMap(fichier, c, level, totalBlock, largeurBlock, sizeBlock, bonhomme, texturebox, bCheck, boxes, boiteCheck, troueV, count);

            RectangleShape mur;
            mur.setSize(Vector2f(sizeBlock, sizeBlock));
            mur.setTexture(&textureMure);

            int dir = 0;

            while (window.isOpen()) {

                Event event{};

                getEvent(window, event, dir, loadNiveau, cliqueDeplacement);

                Vector2f prochainePosition = bonhomme.getPosition();

                rectBonhomme = spriteBonhomme(dir, prochainePosition, rectBonhomme);

                bool deplacementAutorise = true;
                bool aPousseUneBoite = false;

                for (auto& box : boxes) {
                    if (prochainePosition == box.getPosition()) {

                        Vector2f futureBoxPosition = box.getPosition();

                        futureBoxPosition = getFuturBoxPosition(futureBoxPosition, dir);

                        bool collision = collisionMur(futureBoxPosition, level, sizeBlock, largeurBlock);

                        collision = collisionBox(boxes, box, futureBoxPosition, collision);

                        deplacementBox(collision, aPousseUneBoite, deplacementAutorise, box, futureBoxPosition);

                    }
                }

                deplacementBonhomme(deplacementAutorise, aPousseUneBoite, prochainePosition, level, sizeBlock, largeurBlock, bonhomme);

                window.clear();
                window.draw(fondEcran);

                placerTileMap(hauteurBlock, largeurBlock, sizeBlock, typeBlock, mur, textureMure, window, level, dir);

                drawBonhomme(bonhomme, window, textureBonhomme, rectBonhomme);

                dir = 0;

                boxEtTroue(boxes, troueV, boiteCheck, bCheck, level, sizeBlock, window, largeurBlock);

                if (Niveaureussi(boxes, boiteCheck))
                {
                    ofstream updateNiveau;
                    updateFichier(updateNiveau, indexNiveau, "updateNiveau.txt");
                    loadNiveau = false;

                    window.close();

                }
                window.display();

            }
        }

    }

}
