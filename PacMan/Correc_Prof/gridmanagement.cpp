#include <iostream>
#include <iomanip>
#include "gridmanagement.h"

#include "type.h" //nos types


using namespace std;



void ClearScreen()
{
    cout << "\033[H\033[2J";
}// ClearScreen ()

void Color (const string & Col)
{
    cout << "\033[" << Col.c_str () <<"m";
} // Color ()

void DisplayGrid (const CMat & Mat, const CMyParamV2 & param)
{
    const unsigned KNbLine = Mat.size ();
    const unsigned KNbCol  = Mat[0].size ();
    cout << string (KNbCol + 2 , '-') << endl;
    for (unsigned i (0); i < KNbLine; ++i)
    {
        cout << '|';
        for (char c : Mat[i])
        {

            switch (c)
            {
            case KEmpty:
                cout << c;
                break;
            case 'X':
                Color (KColor.find("KBlue")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
                break;
            case 'O':
                Color (KColor.find("KRed")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
                break;
            case '=':
                Color (KColor.find("KMAgenta")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
                break;
            case 'I':
                Color (KColor.find("KMAgenta")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
                break;
            case 'T':
                Color (KColor.find("KCyan")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
                break;
            case '0':
                Color (KColor.find("KYellow")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
                break;
            }
        }
        cout << '|' << endl;
    }
    cout << string (KNbCol + 2 , '-') << endl;
}// ShowMatrix ()


void InitGrid (CMat & Mat, unsigned NbLine, unsigned NbColumn, CPosition & PosPlayer1, CPosition & PosPlayer2, CPosition & PosMur, CPosition & PosTp, CPosition & PosTp2, CPosition & PosPiece)
{
    Mat.resize (NbLine);
    const CVLine KLine (NbColumn, KEmpty);
    for (CVLine &ALine : Mat)
        ALine = KLine;

    PosPlayer1.first = 0;
    PosPlayer1.second = NbColumn - 1;
    Mat [PosPlayer1.first][PosPlayer1.second] = 'X';
    PosPlayer2.first = NbLine - 1;
    PosPlayer2.second =0;
    Mat [PosPlayer2.first][PosPlayer2.second]   = 'O';

    PosPiece.first = 0;
    PosPiece.second = NbColumn -20;
    Mat [PosPiece.first][PosPiece.second] = '0';
    PosPiece.first = 5;
    PosPiece.second = NbColumn -9;
    Mat [PosPiece.first][PosPiece.second] = '0';
    PosPiece.first = 9;
    PosPiece.second = NbColumn -1;
    Mat [PosPiece.first][PosPiece.second] = '0';

    PosTp.first = 5;
    PosTp.second = NbColumn -7;
    Mat [PosTp.first][PosTp.second] = 'T';

    PosTp2.first = 4;
    PosTp2.second = NbColumn -2;
    Mat [PosTp2.first][PosTp2.second] = 'T';

    PosMur.first = 2;
    PosMur.second = NbColumn -8;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 3;
    PosMur.second = NbColumn -8;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 4;
    PosMur.second = NbColumn -8;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 1;
    PosMur.second = NbColumn -1;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -2;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -3;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -4;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -5;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 1;
    PosMur.second = NbColumn -7;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -8;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 4;
    PosMur.second = NbColumn -12;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 0;
    PosMur.second = NbColumn -12;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 1;
    PosMur.second = NbColumn -12;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 2;
    PosMur.second = NbColumn -12;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 3;
    PosMur.second = NbColumn -12;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 4;
    PosMur.second = NbColumn -11;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 0;
    PosMur.second = NbColumn -11;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 1;
    PosMur.second = NbColumn -11;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 2;
    PosMur.second = NbColumn -11;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 3;
    PosMur.second = NbColumn -11;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 1;
    PosMur.second = NbColumn -14;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -15;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 1;
    PosMur.second = NbColumn -19;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -18;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -17;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -16;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 1;
    PosMur.second = NbColumn -20;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 3;
    PosMur.second = NbColumn -20;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -19;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -18;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -17;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -16;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 5;
    PosMur.second = NbColumn -16;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 6;
    PosMur.second = NbColumn -16;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 7;
    PosMur.second = NbColumn -16;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 2;
    PosMur.second = NbColumn -14;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 3;
    PosMur.second = NbColumn -14;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 4;
    PosMur.second = NbColumn -14;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 6;
    PosMur.second = NbColumn -14;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 7;
    PosMur.second = NbColumn -15;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 7;
    PosMur.second = NbColumn -14;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 7;
    PosMur.second = NbColumn -13;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 4;
    PosMur.second = NbColumn -20;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 5;
    PosMur.second = NbColumn -20;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 6;
    PosMur.second = NbColumn -20;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 3;
    PosMur.second = NbColumn -6;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -2;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -3;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -4;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 3;
    PosMur.second = NbColumn -5;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 4;
    PosMur.second = NbColumn -2;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 5;
    PosMur.second = NbColumn -2;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 6;
    PosMur.second = NbColumn -2;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 5;
    PosMur.second = NbColumn -6;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 6;
    PosMur.second = NbColumn -6;
    Mat [PosMur.first][PosMur.second] = 'I';
    PosMur.first = 7;
    PosMur.second = NbColumn -6;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 6;
    PosMur.second = NbColumn -8;
    Mat [PosMur.first][PosMur.second] = 'I';

    PosMur.first = 7;
    PosMur.second = NbColumn -7;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 7;
    PosMur.second = NbColumn -8;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 7;
    PosMur.second = NbColumn -9;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 8;
    PosMur.second = NbColumn -21;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 8;
    PosMur.second = NbColumn -20;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 8;
    PosMur.second = NbColumn -19;
    Mat [PosMur.first][PosMur.second] = '=';

    PosMur.first = 8;
    PosMur.second = NbColumn -1;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 8;
    PosMur.second = NbColumn -2;
    Mat [PosMur.first][PosMur.second] = '=';
    PosMur.first = 8;
    PosMur.second = NbColumn -3;
    Mat [PosMur.first][PosMur.second] = '=';
}//InitMat ()


