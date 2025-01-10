#include <string>
#include "params.h"
#include "game.h"

using namespace std;



void initParams (CMyParamV2 & Param)
{//Move Keys
    Param.KeyUp = 'z';
    Param.KeyDown = 's';
    Param.KeyLeft = 'q';
    Param.KeyRight = 'd';

    Param.tokenP1 = 'A';
    Param.tokenP2 = 'X';

    //Size of grid — suppose to be a rectangle
    Param.NbColumn = 10;
    Param.NbRow = 10;

    //Display Colors
    Param.ColorP1 = KColor.find("KRed")->second ;
    Param.ColorP2 = KColor.find("KBlue")->second;
}

Params::Params() {}
