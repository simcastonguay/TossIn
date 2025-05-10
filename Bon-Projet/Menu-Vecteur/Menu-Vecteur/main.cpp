#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "mesFonctions.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1200, 800), "Main Menu"); //Menu Principal

    /////////////////TEXTURE PERSONNAGES////////////////////
    vector<sf::Texture> texturesPersonnages;

    sf::Texture Renau;
    if (!Renau.loadFromFile("RenauMenu.png")) {
        std::cout << "Erreur de chargement de la texture Renau.\n";
    }
    texturesPersonnages.push_back(Renau);

   /* sf::Texture Stamp;
    if (!Stamp.loadFromFile("STAMP.png")) {
        std::cout << "Erreur de chargement de la texture STAMP.\n";
    }
    texturesPersonnages.push_back(Stamp);*/

    sf::Texture Cats;
    if (!Cats.loadFromFile("Cats.png")) {
        std::cout << "Erreur de chargement de la texture Cats.\n";
    }
    texturesPersonnages.push_back(Cats);

    int selection = 0; // le numéro du personnage
    sf::Sprite personnage;
    personnage.setTexture(texturesPersonnages[selection]); 
    personnage.setPosition(420, 155);
   
    ////////////////////////////////////////////////////////////////////////


    /////////////////////////////info niveau////////////////////////////////
    
    int indexNiveau = 0;
    ifstream fichier;

    ////////////////////////////////TEXTURE BOUTON////////////////////

    ///////////////////BACKGROUND DU MENU///////////////////
    sf::Texture MainMenu;
    if (!MainMenu.loadFromFile("BGMainMenu.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::RectangleShape Menu;
    Menu.setSize({ 1200.f, 800.f });
    Menu.setTexture(&MainMenu);

    sf::Texture SelectionPersonnage;
    if (!SelectionPersonnage.loadFromFile("BGCharacterSelect.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::RectangleShape MenuPersonnage;
    MenuPersonnage.setSize({ 1200.f, 800.f });
    MenuPersonnage.setTexture(&SelectionPersonnage);

    sf::Texture ChargerPartie;
    if (!ChargerPartie.loadFromFile("BGCharacterSelect.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::RectangleShape MenuChargerPartie;
    MenuChargerPartie.setSize({ 1200.f, 800.f });
    MenuChargerPartie.setTexture(&ChargerPartie);

    sf::Texture BGControles;
    if (!BGControles.loadFromFile("BGControle.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::RectangleShape MenuControle;
    MenuControle.setSize({ 1200.f, 800.f });
    MenuControle.setTexture(&BGControles);

    sf::Texture BGhs;
    if (!BGhs.loadFromFile("BGHighScore.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::RectangleShape menuHS;
    menuHS.setSize({ 1200.f, 800.f });
    menuHS.setTexture(&BGhs);

    sf::Texture BGMap;
    if (!BGMap.loadFromFile("BGMap.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::RectangleShape menuMap;
    menuMap.setSize({ 1200.f, 800.f });
    menuMap.setTexture(&BGMap);


    //////////////////BOUTTONS DU MENU PRINCIPAL///////////
    sf::Texture menuJouer;
    if (!menuJouer.loadFromFile("Jouer.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::RectangleShape mainJouer;
    mainJouer.setSize({ 237.f, 74.f });
    mainJouer.setPosition(10, 345);
    mainJouer.setTexture(&menuJouer);

    sf::Texture menuCharger;
    if (!menuCharger.loadFromFile("Charger.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::Texture menuChargerHover;
    if (!menuChargerHover.loadFromFile("ChargerHover.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::RectangleShape mainCharger;
    mainCharger.setSize({ 331.f, 75.f });
    mainCharger.setPosition(10, 445);
    mainCharger.setTexture(&menuCharger);

    sf::Texture menuControl;
    if (!menuControl.loadFromFile("Controles.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::Texture menuControlHover;
    if (!menuControlHover.loadFromFile("ControlesHover.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::RectangleShape mainControl;
    mainControl.setSize({ 407.f, 72.f });
    mainControl.setPosition(10, 545);
    mainControl.setTexture(&menuControl);

    sf::Texture menuBoutonHS;
    if (!menuBoutonHS.loadFromFile("HighScores.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::Texture menuHSHover;
    if (!menuHSHover.loadFromFile("HighScoresHover.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::RectangleShape mainHS;
    mainHS.setSize({ 475.f, 76.f });
    mainHS.setPosition(10, 645);
    mainHS.setTexture(&menuBoutonHS);

  


    //////////////BOUTTON DANS LES SOUS-MENUS////////////
    sf::RectangleShape optionMenuJouer({ 237.f, 74.f });
    optionMenuJouer.setPosition(953, 716);
    optionMenuJouer.setTexture(&menuJouer);

    sf::Texture menuJouerHover;
    if (!menuJouerHover.loadFromFile("JouerHover.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
    sf::Texture menuRetour;
    if (!menuRetour.loadFromFile("Retour.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
    optionMenuRetour.setTexture(&menuRetour);
    optionMenuRetour.setPosition(10, 10);
    
    sf::Texture menuRetourHover;
    if (!menuRetourHover.loadFromFile("RetourHover.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }
   
    ///////////////////// FLECHE PERSONNAGE /////////////////////////

    sf::Texture flecheGauche;
    if (!flecheGauche.loadFromFile("FlecheGauche.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::Texture flecheDroite;
    if (!flecheDroite.loadFromFile("FlecheDroite.png")) {
        std::cout << "Erreur de chargement de la texture du menu.\n";
        return 1;
    }

    sf::RectangleShape optionPersoGauche({ 125.f, 124.f });
    optionPersoGauche.setTexture(&flecheGauche);
    optionPersoGauche.setPosition(240, 280);

    sf::RectangleShape optionPersoDroite({ 125.f, 124.f });
    optionPersoDroite.setTexture(&flecheDroite);
    optionPersoDroite.setPosition(840, 280);

    ///////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {


        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente     itération
        Event event;


        while (windowMenu.pollEvent(event))
        {
            sf::Vector2f optionsMenu = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            // sf::Vector2f optionsQuitter = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            mainJouer.setTexture(&menuJouer);
            mainCharger.setTexture(&menuCharger);
            mainControl.setTexture(&menuControl);
            mainHS.setTexture(&menuBoutonHS);

             // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case Keyboard::Escape:
                    window.close();
                    //  music.stop();
                    break;
                }
            }
            else if (mainJouer.getGlobalBounds().contains(optionsMenu))
            {

                mainJouer.setTexture(&menuJouerHover); // Hover   

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    RenderWindow windowCharacter(VideoMode(1200, 800), "Sélection du personnage");
                    

                    
                   
                    while (windowCharacter.isOpen())
                    {
                        Event characterEvent;
       
                        while (windowCharacter.pollEvent(characterEvent))
                        {
                            sf::Vector2f optionsRetourPerso = windowCharacter.mapPixelToCoords(sf::Mouse::getPosition(windowCharacter));
                            sf::Vector2f optionsJouerPerso = windowCharacter.mapPixelToCoords(sf::Mouse::getPosition(windowCharacter));
                            
 
   
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
                                    if(selection < 0)
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
                                    if (!menuRetour.loadFromFile("Retour.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture menuRetourHover;
                                    if (!menuRetourHover.loadFromFile("RetourHover.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::RectangleShape optionMenuRetour({ 284.f, 74.f });
                                    optionMenuRetour.setTexture(&menuRetour);
                                    optionMenuRetour.setPosition(10, 10);

                                    sf::Texture boutonMap;
                                    if (!boutonMap.loadFromFile("BoutonNonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonMapHover;
                                    if (!boutonMapHover.loadFromFile("HoverBoutonNonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonComplete;
                                    if (!boutonComplete.loadFromFile("BoutonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonCompleteHover;
                                    if (!boutonCompleteHover.loadFromFile("HoverBoutonComplete.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }

                                    sf::Texture boutonActuel;
                                    if (!boutonActuel.loadFromFile("BoutonActuel.png")) {
                                        std::cout << "Erreur de chargement de la texture du menu.\n";
                                        return 1;
                                    }
                                    sf::Texture boutonActuelHover;
                                    if (!boutonActuelHover.loadFromFile("BoutonActuelHover.png")) {
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

                                    while (windowMap.isOpen())
                                    {
                                        Event mapEvent;

                                        while (windowMap.pollEvent(mapEvent))
                                        {
                                            sf::Vector2f optionsRetourMap = windowMap.mapPixelToCoords(sf::Mouse::getPosition(windowMap));
                                            sf::Vector2f optionsBoutonMap = windowMap.mapPixelToCoords(sf::Mouse::getPosition(windowMap));

                                            optionBoutonMap1.setTexture(&boutonActuel);
                                            optionBoutonMap2.setTexture(&boutonMap);
                                            optionBoutonMap3.setTexture(&boutonMap);
                                            optionBoutonMap4.setTexture(&boutonMap);
                                            optionBoutonMap5.setTexture(&boutonMap);
                                            optionMenuRetour.setTexture(&menuRetour);

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
        
                        


                        windowCharacter.clear();
                        windowCharacter.draw(MenuPersonnage);
                        windowCharacter.draw(personnage);
                        windowCharacter.draw(optionPersoDroite);
                        windowCharacter.draw(optionPersoGauche);
                        windowCharacter.draw(optionMenuRetour);
                        windowCharacter.draw(optionMenuJouer);
                        windowCharacter.display();
            
                    }
                }
             }
            
             /////////////////// FIN BOUTTON JOUER ///////////////////
            else if (mainCharger.getGlobalBounds().contains(optionsMenu))
            {
                mainCharger.setTexture(&menuChargerHover);

            }
            //////////////////FIN BOUTON CHARGER////////////////////

            else if (mainControl.getGlobalBounds().contains(optionsMenu))
            {
                mainControl.setTexture(&menuControlHover);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    RenderWindow windowControles(VideoMode(1200, 800), "Comment jouer ?");
                   
                    sf::Texture menuRetour;
                    if (!menuRetour.loadFromFile("Retour.png")) {
                        std::cout << "Erreur de chargement de la texture du menu.\n";
                        return 1;
                    }

                    sf::Texture menuRetourHover;
                    if (!menuRetourHover.loadFromFile("RetourHover.png")) {
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
                            sf::Vector2f optionsRetour = windowControles.mapPixelToCoords(sf::Mouse::getPosition(windowControles));
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
                            windowControles.draw(MenuControle);
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
                    if (!menuRetour.loadFromFile("Retour.png")) {
                        std::cout << "Erreur de chargement de la texture du menu.\n";
                        return 1;
                    }

                    sf::Texture menuRetourHover;
                    if (!menuRetourHover.loadFromFile("RetourHover.png")) {
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
                            sf::Vector2f optionsRetour = windowHS.mapPixelToCoords(sf::Mouse::getPosition(windowHS));
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
         windowMenu.draw(Menu);
         windowMenu.draw(mainJouer);
         windowMenu.draw(mainCharger);
         windowMenu.draw(mainControl);
         windowMenu.draw(mainHS);
         windowMenu.display();

     }
    return 0;

}

