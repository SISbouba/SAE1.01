#include <iostream>

#include "game.h"
#include "params.h"
#include "gridmanagement.h"

#include <map>

using namespace std;


void MoveToken (CMat & Mat, const char & Move, CPosition & Pos, const CPosition & PosMur, const CPosition & PosTp, const CPosition & PosTp2, const CPosition & PosPiece)
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
        // Si le joueur va sur un mur
        if (Mat[ligne][colonne] == '=')
        {
            // Ancienne position si ya un mur
            Mat[Pos.first][Pos.second] = car; // Va a l'ancienne position
            return; 
        }
        // Si le joueur va sur un mur
        if (Mat[ligne][colonne] == 'I')
        {
            // Ancienne position si ya un mur
            Mat[Pos.first][Pos.second] = car; // Va a l'ancienne position
            return; 
        }


        // Si le joueur va sur un tp
        if (Mat[ligne][colonne] == 'T')
        {
            // Aller a l'autre téléporteur
            if (Pos == PosTp) // tp1
            {
                Pos.first = PosTp2.first;
                Pos.second = PosTp2.second;
            }
            else if (Pos == PosTp2) // tp2
            {
                Pos.first = PosTp.first;
                Pos.second = PosTp.second;
            }
        }
        else
        {
            // Deplacement joueur
            Pos.first = ligne;
            Pos.second = colonne;
        }
        Mat[Pos.first][Pos.second] = car; // Déplacement joueur
    }
    else
    {
       // Si on quitte le terrain alors on revient a notre ancienne position
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

    CPosition PosPlayer1, PosPlayer2, PosMur, PosTp, PosTp2, PosPiece;

    CMyParamV2 param;

    initParams (param);

    InitGrid(Mat, 10, 21, PosPlayer1, PosPlayer2, PosMur, PosTp, PosTp2, PosPiece);

    DisplayGrid(Mat, param);

    while (PartyNum <= KMaxPartyNum && !Victory)
    {
        cout << "Tour numéro : " << PartyNum << ", Joueur "
             << (Player1Turn ? '1' : '2') << ", Bonne chance : ";
        char Move;
        cin >> Move;
        // Le joueur abandonne ?
        if (toupper(Move) == 'S') {
            cout << "La partie est terminée par abandon." << endl;
            cout << "Félicitations Joueur " << (Player1Turn ? '2' : '1') << ", vous avez gagné !" << endl;
            return 0; // Fin du game
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

void Marteau (CMat & Mat, const CPosition & PosMur)
{
    //Utilisation du Mateau
    cout << "Activation du Marteau."<<endl;
    //Verifie si il y a un mur autour du joueur
    if(Mat[PosMur.first][PosMur.second] == '=' & Mat [PosMur.first][PosMur.second] = 'I'){
        Mat [PosMur.first][PosMur.second] =KEmpty;//Détruit le mur
        cout << "Mur détruit en position("<<PosMur.first<<", "<<PosMur.second<<")."<<endl;
    }
    else {
            cout << "Aucun mur à détruit en position("<<PosMur.first<<", "<<PosMur.second<<")."<<endl;
    }
}
