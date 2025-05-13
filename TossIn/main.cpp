#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<string>
#include<fstream>
#include"mesFonctions.h"

using namespace std;
using namespace sf;


int main() {
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

    int selection = 0; // le numéro du personnage
    sf::Sprite personnage;
    personnage.setTexture(texturesPersonnages[selection]);
    personnage.setPosition(420, 155);

    ///////////////////BACKGROUND DU MENU///////////////////

    sf::Texture mainMenu;
    if (!mainMenu.loadFromFile("image/BGMainMenu.png")) {
        std::cout << "Erreur de chargement de la texture du menu principal.\n";
        return 1;
    }
    sf::RectangleShape menu;
    menu.setSize({ 1200.f, 800.f });
    menu.setTexture(&mainMenu);

    sf::Texture selectionPersonnage;
    if (!selectionPersonnage.loadFromFile("image/BGCharacterSelect.png")) {
        std::cout << "Erreur de chargement de la texture du menu des personnages.\n";
        return 1;
    }
    sf::RectangleShape menuPersonnage;
    menuPersonnage.setSize({ 1200.f, 800.f });
    menuPersonnage.setTexture(&selectionPersonnage);

    sf::Texture chargerPartie;
    if (!chargerPartie.loadFromFile("image/BGCharacterSelect.png")) {
        std::cout << "Erreur de chargement de la texture du menu de chargement de la partie.\n";
        return 1;
    }
    sf::RectangleShape menuChargerPartie;
    menuChargerPartie.setSize({ 1200.f, 800.f });
    menuChargerPartie.setTexture(&chargerPartie);

    sf::Texture bgControles;
    if (!bgControles.loadFromFile("image/BGControle.png")) {
        std::cout << "Erreur de chargement de la texture du menu des controles.\n";
        return 1;
    }
    sf::RectangleShape menuControle;
    menuControle.setSize({ 1200.f, 800.f });
    menuControle.setTexture(&bgControles);

    sf::Texture bgHS;
    if (!bgHS.loadFromFile("image/BGHighScore.png")) {
        std::cout << "Erreur de chargement de la texture du menu des meilleurs score.\n";
        return 1;
    }
    sf::RectangleShape menuHS;
    menuHS.setSize({ 1200.f, 800.f });
    menuHS.setTexture(&bgHS);

    sf::Texture bgMap;
    if (!bgMap.loadFromFile("image/BGMap.png")) {
        std::cout << "Erreur de chargement de la texture du menu de la carte.\n";
        return 1;
    }
    sf::RectangleShape menuMap;
    menuMap.setSize({ 1200.f, 800.f });
    menuMap.setTexture(&bgMap);

    //////////////////BOUTONS DU MENU PRINCIPAL///////////

    sf::Texture menuJouer;
    if (!menuJouer.loadFromFile("image/Jouer.png")) {
        std::cout << "Erreur de chargement de la texture du bouton jouer.\n";
        return 1;
    }

    sf::RectangleShape mainJouer;
    mainJouer.setSize({ 237.f, 74.f });
    mainJouer.setPosition(10, 345);
    mainJouer.setTexture(&menuJouer);

    sf::Texture menuCharger;
    if (!menuCharger.loadFromFile("image/Charger.png")) {
        std::cout << "Erreur de chargement de la texture du bouton charger.\n";
        return 1;
    }

    sf::Texture menuChargerHover;
    if (!menuChargerHover.loadFromFile("image/ChargerHover.png")) {
        std::cout << "Erreur de chargement de la texture du bouton charger en surbrillance.\n";
        return 1;
    }

    sf::RectangleShape mainCharger;
    mainCharger.setSize({ 331.f, 75.f });
    mainCharger.setPosition(10, 445);
    mainCharger.setTexture(&menuCharger);

    sf::Texture menuControl;
    if (!menuControl.loadFromFile("image/Controles.png")) {
        std::cout << "Erreur de chargement de la texture du bouton controles.\n";
        return 1;
    }

    sf::Texture menuControlHover;
    if (!menuControlHover.loadFromFile("image/ControlesHover.png")) {
        std::cout << "Erreur de chargement de la texture du bouton controles en surbrillance.\n";
        return 1;
    }

    sf::RectangleShape mainControl;
    mainControl.setSize({ 407.f, 72.f });
    mainControl.setPosition(10, 545);
    mainControl.setTexture(&menuControl);

    sf::Texture menuBoutonHS;
    if (!menuBoutonHS.loadFromFile("image/HighScores.png")) {
        std::cout << "Erreur de chargement de la texture du bouton meilleurs scores.\n";
        return 1;
    }
    sf::Texture menuHSHover;
    if (!menuHSHover.loadFromFile("image/HighScoresHover.png")) {
        std::cout << "Erreur de chargement de la texture du bouton meilleurs scores en srubrillance.\n";
        return 1;
    }

    sf::RectangleShape mainHS;
    mainHS.setSize({ 475.f, 76.f });
    mainHS.setPosition(10, 645);
    mainHS.setTexture(&menuBoutonHS);


    //////////////BOUTON DANS LES SOUS-MENUS////////////

    sf::RectangleShape optionMenuJouer({ 237.f, 74.f });
    optionMenuJouer.setPosition(953, 716);
    optionMenuJouer.setTexture(&menuJouer);

    sf::Texture menuJouerHover;
    if (!menuJouerHover.loadFromFile("image/JouerHover.png")) {
        std::cout << "Erreur de chargement de la texture du bouton jouer en surbrillance.\n";
        return 1;
    }
    sf::Texture menuRetour;
    if (!menuRetour.loadFromFile("image/Retour.png")) {
        std::cout << "Erreur de chargement de la texture du bouton retour.\n";
        return 1;
    }

    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
    optionMenuRetour.setTexture(&menuRetour);
    optionMenuRetour.setPosition(10, 10);

    sf::Texture menuRetourHover;
    if (!menuRetourHover.loadFromFile("image/RetourHover.png")) {
        std::cout << "Erreur de chargement de la texture du bouton retour en surbrillance.\n";
        return 1;
    }

    ///////////////////// FLECHE PERSONNAGE /////////////////////////

    sf::Texture flecheGauche;
    if (!flecheGauche.loadFromFile("image/FlecheGauche.png")) {
        std::cout << "Erreur de chargement de la texture de la touche A.\n";
        return 1;
    }

    sf::Texture flecheDroite;
    if (!flecheDroite.loadFromFile("image/FlecheDroite.png")) {
        std::cout << "Erreur de chargement de la texture de la touche D.\n";
        return 1;
    }

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


        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente     itération
        Event event;


        while (windowMenu.pollEvent(event))
        {
            ///////////////DÉTECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
            sf::Vector2f optionsMenu = windowMenu.mapPixelToCoords(sf::Mouse::getPosition(windowMenu));
            ////////////////PERMET DE RESET LA TEXTURE QUAND SOURIS N'EST PLUS DESSUS////////////////
            mainJouer.setTexture(&menuJouer);
            mainCharger.setTexture(&menuCharger);
            mainControl.setTexture(&menuControl);
            mainHS.setTexture(&menuBoutonHS);

            // évènement "fermeture demandée" : on ferme la fenêtre
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
                    RenderWindow windowCharacter(VideoMode(1200, 800), "Sélection du personnage");




                    while (windowCharacter.isOpen())
                    {
                        Event characterEvent;

                        while (windowCharacter.pollEvent(characterEvent))
                        {
                            ///////////////DÉTECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
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
                                    //  music.stop();
                                    break;
                                }
                            }

                            if (characterEvent.type == Event::KeyPressed) {
                                if (characterEvent.key.code == sf::Keyboard::D) {
                                    selection = (selection + 1) % texturesPersonnages.size(); //peut pas faire selection++ sinon fait pas de boucle
                                    personnage.setTexture(texturesPersonnages[selection]);
                                    cout << "1";
                                }
                            }
                            if (characterEvent.type == Event::KeyPressed) {
                                if (characterEvent.key.code == sf::Keyboard::A) {
                                    selection--;
                                    cout << "2";
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
                                    RenderWindow windowMap(VideoMode(1200, 800), "Sélection d'un niveau");
                                    windowCharacter.close();

                                    sf::Texture menuRetour;
                                    if (!menuRetour.loadFromFile("image/Retour.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture menuRetourHover;
                                    if (!menuRetourHover.loadFromFile("image/RetourHover.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                                    optionMenuRetour.setTexture(&menuRetour);
                                    optionMenuRetour.setPosition(10, 10);

                                    sf::Texture boutonMap;
                                    if (!boutonMap.loadFromFile("image/BoutonNonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonMapHover;
                                    if (!boutonMapHover.loadFromFile("image/HoverBoutonNonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonComplete;
                                    if (!boutonComplete.loadFromFile("image/BoutonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonCompleteHover;
                                    if (!boutonCompleteHover.loadFromFile("image/HoverBoutonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonActuel;
                                    if (!boutonActuel.loadFromFile("image/BoutonActuel.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }
                                    sf::Texture boutonActuelHover;
                                    if (!boutonActuelHover.loadFromFile("image/BoutonActuelHover.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }


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
                                            ///////////////DÉTECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
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
                                                    //  music.stop();
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
                                                    /*windowMenu.close();
                                                    windowCharacter.close();
                                                    windowMap.close();*/
                                                    loadNiveau = true;
                                                    //break;
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
                                                    /*windowMenu.close();
                                                    windowCharacter.close();
                                                    windowMap.close();*/
                                                    loadNiveau = true;
                                                    //break;
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
                                                    /*windowMenu.close();
                                                    windowCharacter.close();
                                                    windowMap.close();*/
                                                    loadNiveau = true;
                                                    //break;

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
                                                    /*windowMenu.close();
                                                    windowCharacter.close();
                                                    windowMap.close();*/
                                                    loadNiveau = true;
                                                    //break;

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
                                                    //break;
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

                    sf::Texture menuRetour;
                    if (!menuRetour.loadFromFile("image/Retour.png")) {
                        std::cout << "Erreur de chargement de la texture du menu.\n";
                        return 1;
                    }

                    sf::Texture menuRetourHover;
                    if (!menuRetourHover.loadFromFile("image/RetourHover.png")) {
                        std::cout << "Erreur de chargement de la texture du menu.\n";
                        return 1;
                    }

                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                    optionMenuRetour.setTexture(&menuRetour);
                    optionMenuRetour.setPosition(10, 10);
                    while (windowControles.isOpen())
                    {
                        Event controleEvent;

                        while (windowControles.pollEvent(controleEvent))
                        {
                            ///////////////DÉTECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
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

                    sf::Texture menuRetour;
                    if (!menuRetour.loadFromFile("image/Retour.png")) {
                        std::cout << "Erreur de chargement de la texture du menu.\n";
                        return 1;
                    }

                    sf::Texture menuRetourHover;
                    if (!menuRetourHover.loadFromFile("image/RetourHover.png")) {
                        std::cout << "Erreur de chargement de la texture du menu.\n";
                        return 1;
                    }

                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                    optionMenuRetour.setTexture(&menuRetour);
                    optionMenuRetour.setPosition(10, 10);
                    while (windowHS.isOpen())
                    {
                        Event highscoreEvent;

                        while (windowHS.pollEvent(highscoreEvent))
                        {
                            ///////////////DÉTECTE LA POSITION DE LA SOURIS SUR LES BOUTONS////////////////
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
            ouvrirSprite(textureBonhomme, "image/renauTileSheet.png");
            IntRect rectBonhomme(0, 0, 100, 100);

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

                getEvent(window, event, dir, loadNiveau);

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

};