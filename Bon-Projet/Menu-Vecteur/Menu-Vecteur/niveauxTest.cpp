//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <fstream>
//#include <iostream>
//
//using namespace std;
//using namespace sf;
//
//// ce que j'ai compris, permet a tout les niveaux d'Avoir la même strcuture comme une classe, mais peut être utiliser dans un vecteur//
//struct Niveau {  
//    std::string nomNiveau;
//    bool debloquer;
//    sf::RectangleShape iconeNiveau;
//};
//
////  https://cplusplus.com/doc/tutorial/structures/ // https://www.geeksforgeeks.org/cpp-vector-of-structs/ //
//
//vector<Niveau> lvl;
//
//struct Niveau niveau1 = {"Niveau 1", true, /*texture*/};
//struct Niveau niveau2 = { "Niveau 2", false, /*texture*/ };
//struct Niveau niveau3 = { "Niveau 3", false, /*texture*/ };
//struct Niveau niveau4 = { "Niveau 4", false, /*texture*/ };
//struct Niveau niveau5 = { "Niveau 5", false, /*texture*/ };
//
//
//
//void nouvellePartie()
//{
//    // mettre tout les niveaux un a la suite de l'autre donc facile -> pushback
//    lvl.push_back(niveau1);
//    lvl.push_back(niveau2);
//    lvl.push_back(niveau3);
//    lvl.push_back(niveau4);
//    lvl.push_back(niveau5);
//}
//
//void niveauDebloquer(int index=0)
//{
//    if (index + 1 < lvl.size())
//    {
//        // si lvl 0 + 1 (donc lvl 2) est plus petit que le nombre de niveau, on débloquer le prochain(+1 donc le 1 qui est le lvl 2)
//        lvl[index + 1].debloquer = true;
//        // strcu niveau niveau 2 devient true
//    }
//}
//
//void sauvegarde() // je ne sais pas si cela focntionne, j'y suis alle rau mieux de mes connaissance
//{
//    fstream fichier("saveFile.txt");
//    if(!fichier.is_open())
//    {
//        cout << "Échec de la sauvegarde.";
//    }
//    else
//    {
//        fichier << niveau1.nomNiveau << " " << niveau1.debloquer <<"\n";
//        fichier << niveau2.nomNiveau << " " << niveau2.debloquer << "\n";
//        fichier << niveau3.nomNiveau << " " << niveau3.debloquer << "\n";
//        fichier << niveau4.nomNiveau << " " << niveau4.debloquer <<"\n";
//        fichier << niveau5.nomNiveau << " " << niveau5.debloquer << "\n";
//       
//    }
//    fichier.close();
//}
//
//void chargerPartie()
//{
//    fstream fichier("saveFile.txt");
//    if (!fichier.is_open())
//    {
//        cout << "Échec du chargement de la partie.";
//    }
//    else
//    {
//        lvl.clear(); // s'assure que ya pas de "reste" comme quand on window clear
//        std::string nomNiveau;
//        bool débloquer;
//        while (fichier >> nomNiveau >> débloquer) //tant qu'il y a des nom de nbiveau et true/false
//        {
//            lvl.push_back({nomNiveau, débloquer });
//         }
//    }
//    fichier.close();
//}
//
//void boutonNiveau()
//{
// 
//    for (int i = 0; i < lvl.size(); i++)
//    {
//        lvl[i].iconeNiveau.setPosition(300, 300 + i * 30);
//       // lvl[i].iconeNiveau.setTexture();
//    }
//}
//
//// Main = lvl[i].iconeNiveau.globalbound(....) --- if niveau debloquer, lance niveau, sinon "niveau verrouiel"