#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include "type.h"  // Inclusion du fichier type.h
#include "params.h" // Inclusion des paramètres
#include "gridmanagement.h" // Fonctions de gestion de grille

using namespace std;

CMyParamV2 gameParams;
const size_t KNbLine = gameParams.NbRow;
const size_t KNbCol = gameParams.NbColumn;
int ppal (void);

using CMat = vector<vector<char>>;

// Fonction pour initialiser la grille
void InitGrid(CMat& Mat, size_t rows, size_t cols, CPosition PosPlayer1, CPosition PosPlayer2) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            Mat[i][j] = KEmpty;
        }
    }
    Mat[PosPlayer1.first][PosPlayer1.second] = 'P'; // 'P' pour Policier
    Mat[PosPlayer2.first][PosPlayer2.second] = 'V'; // 'V' pour Voleur
}

// Fonction pour afficher la grille
void DisplayGrid(const CMat& Mat) {
    for (const auto& row : Mat) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

// Classe de base pour les capacités
class Ability {
public:
    virtual void activate(CPosition userPos, CMat& Mat) = 0;
};

// Taser (Seulement Policier)
class Taser : public Ability {
public:
    void activate(CPosition PosPlayer1, CMat& Mat) override {
        cout << "Activation du Taser..." << endl;
        for (int i = PosPlayer1.first - 2; i <= PosPlayer1.first + 2; ++i) {
            for (int j = PosPlayer1.second - 2; j <= PosPlayer1.second + 2; ++j) {
                if (i >= 0 && i < KNbLine && j >= 0 && j < KNbCol && j < KNbCol) {
                    if (Mat[i][j] == gameParams.tokenP2) { // Vérifie la position du voleur
                        cout << "Voleur étourdi en position (" << i << ", " << j << ") pendant 2 tours!" << endl;
                        return;
                    }
                }
            }
        }
        cout << "Aucun voleur dans la zone de tir." << endl;
    }
};

// Botte (Peuvent être utilisée par les deux)
class Botte : public Ability {
public:
    void activate(CPosition userPos, CMat& Mat) override {
        cout << "Bottes équipées! Vous pouvez maintenant effectuer 2 pas dans n'importe quelle direction pendant 3 tours." << endl;
    }
};

// Piège à ours
class Piège : public Ability {
public:
    void activate(CPosition userPos, CMat& Mat) override {
        cout << "Pose d'un piège à ours à une position aléatoire." << endl;
        CPosition trapPos = {rand() % KNbLine, rand() % KNbCol};
        Mat[trapPos.first][trapPos.second] = 'T'; // 'T' pour Piège
        cout << "Piège posé en position (" << trapPos.first << ", " << trapPos.second << ")." << endl;
    }
};

// Esquive (Seulement Voleur)
class Esquive : public Ability {
public:
    void activate(CPosition PosPlayer2, CMat& Mat) override {
        cout << "Esquive activée!" << endl;
        CPosition newPos = {PosPlayer2.first + (rand() % 7 - 3), PosPlayer2.second + (rand() % 7 - 3)}; // Déplacement aléatoire de 3 carreaux
        if (newPos.first >= 0 && newPos.first < KNbLine && newPos.second >= 0 && newPos.second < KNbCol) {
            cout << "Le voleur s'est esquivé à la position (" << newPos.first << ", " << newPos.second << ")." << endl;
        } else {
            cout << "Esquive échouée, hors des limites du terrain." << endl;
        }
    }
};

// Marteau (Peuvent être utilisée par les deux)
class Marteau : public Ability {
public:
    void activate(CPosition userPos, CMat& Mat) override {
        cout << "Utilisation du marteau pour détruire un mur." << endl;
        CPosition PosMur = {rand() % KNbLine, rand() % KNbCol};
        if (Mat[PosMur.first][PosMur.second] == 'M') { // 'M' pour Mur
            Mat[PosMur.first][PosMur.second] = KEmpty; // Détruire le mur
            cout << "Mur détruit en position (" << PosMur.first << ", " << PosMur.second << ")." << endl;
        } else {
            cout << "Aucun mur à détruire en position (" << PosMur.first << ", " << PosMur.second << ")." << endl;
        }
    }
};

int main() {
    srand(time(0));

    CMat Mat(KNbLine, vector<char>(KNbCol, KEmpty)); // Initialisation de la grille avec des cases vides
    CPosition PosPlayer1 = {0, 0};
    CPosition PosPlayer2 = {5, 5};

    InitGrid(Mat, KNbLine, KNbCol, PosPlayer1, PosPlayer2);

    Taser taser;
    Botte botte;
    Piege piege;
    Esquive esquive;
    Marteau marteau;

    cout << "Terrain initial :" << endl;
    DisplayGrid(Mat);

    // Exemple d'utilisation des capacités
    /*
    taser.activate(PosPlayer1, Mat);
    bearTrap.activate(policeman, Mat);
    dodge.activate(thief, Mat);
    hammer.activate(policeman, Mat);
    */

    cout << "Terrain après activation des capacités :" << endl;
    DisplayGrid(Mat);

    return 0;
}
