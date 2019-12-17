#pragma once
#include<vector>

class Domaine{
public:
    Domaine(int x,int x1);
    int     getposx() {return _posx;}
    int     getposx1(){return _posx1;}
    std::vector<int> valeurpossible(){return valeur;}
private:
    std::vector<int> valeur;
    int _posx;
    int _posx1;
};
