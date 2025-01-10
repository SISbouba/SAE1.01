#include <iostream>

#include "game.h"
#include "params.h"
#include "gridmanagement.h"

#include <map>

using namespace std;


void MoveToken (CMat & Mat, const char & Move, CPosition & Pos, const CPosition & PosMur, const CPosition & PosTp, const CPosition & PosTp2)
{
    char car = Mat [Pos.first][Pos.second];
    Mat [Pos.first][Pos.second] = KEmpty;

    //variable pour stocker les nouvelles position
    int ligne = Pos.first;
    int colonne = Pos.second;

    switch (Move)
    {
    case 'A':
        -- ligne;
        -- colonne;
        break;
    case 'Z':
        --ligne;
        break;
    case 'E':
        --ligne;
        ++colonne;
        break;
    case 'Q':
        --colonne;
        break;
    case 'D':
        ++colonne;
        break;
    case 'W':
        ++ligne;
        --colonne;
        break;
    case 'X':
        ++ligne;
        break;
    case 'C':
        ++ligne;
        ++colonne;
        break;
    }
    //ça vérifie les limite de la map de jeu
    if (ligne >= 0 && ligne < Mat.size() && colonne >= 0 && colonne < Mat[0].size())
    {
        // Vérifie si le joueur se déplace sur un mur
        if (Mat[ligne][colonne] == '=')
        {
            // Restaure la position précédente si c'est un mur
            Mat[Pos.first][Pos.second] = car; // Restaure la position précédente
            return; // Ne fait rien d'autre
        }

        // Vérifie si le joueur se déplace sur un téléporteur
        if (Mat[ligne][colonne] == 'T')
        {
            // Téléporte le joueur à l'autre téléporteur
            if (Pos == PosTp) // Si le joueur est sur le premier téléporteur
            {
                Pos.first = PosTp2.first;
                Pos.second = PosTp2.second;
            }
            else if (Pos == PosTp2) // Si le joueur est sur le deuxième téléporteur
            {
                Pos.first = PosTp.first;
                Pos.second = PosTp.second;
            }
        }
        else
        {
            // Déplace le jeton normalement
            Pos.first = ligne;
            Pos.second = colonne;
        }
        Mat[Pos.first][Pos.second] = car; // Déplace le jeton
    }
    else
    {
       // Si le mouvement est en dehors des limites, restaure la position précédente
        Mat[Pos.first][Pos.second] = car;
    }
} // MoveToken ()


int ppal (void)
{
    const unsigned KSize (10);
    unsigned PartyNum (1);
    const unsigned KMaxPartyNum (KSize * KSize);
    CMat Mat;

    bool Player1Turn (true);
    bool Victory (false);

    CPosition PosPlayer1, PosPlayer2, PosMur, PosTp, PosTp2;

    CMyParamV2 param;

    initParams (param);

    InitGrid(Mat, 20, 50, PosPlayer1, PosPlayer2, PosMur, PosTp, PosTp2);

    DisplayGrid(Mat, param);

    while (PartyNum <= KMaxPartyNum && !Victory)
    {
        cout << "Tour numéro : " << PartyNum << ", Joueur "
             << (Player1Turn ? '1' : '2') << ", Bonne chance : ";
        char Move;
        cin >> Move;
        // Vérifiez si le joueur a choisi d'abandonner
        if (toupper(Move) == 'S') {
            cout << "La partie est terminée par abandon." << endl;
            cout << "Félicitations Joueur " << (Player1Turn ? '2' : '1') << ", vous avez gagné !" << endl;
            return 0; // Terminez le programme
        }
        Move = toupper(Move);
        MoveToken(Mat, Move, (Player1Turn ? PosPlayer1 : PosPlayer2), PosMur, PosTp, PosTp2); // Passer les positions des téléporteurs
        ClearScreen();
        DisplayGrid(Mat, param);
        // Test de victoire
        if (PosPlayer1 == PosPlayer2) Victory = true;
        // Augmenter le nombre de parties
        ++PartyNum;
        // Changer de joueur
        Player1Turn = !Player1Turn;
    } // while (no victory)
    if (!Victory)
    {
        Color (KColor.find("KMAgenta")->second);
        cout << "Aucun vainqueur" << endl;
        return 1;
    }
    Color (KColor.find("KGreen")->second);
    cout << "Félicitations Joueur " << (Player1Turn ? '2' : '1')
         << " vous avez gagné :)" << endl;
    Color (KColor.find("KReset")->second);
    return 0;

} // ppal ()
