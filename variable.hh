#pragma once
#include<string>
#include "domaine.hh"

class Variable{
public:
    Variable(std::string nom,Domaine dmn);
    Domaine     getdomaine(){return _dmn;}
    std::string getnom()    {return _nom;}
    bool setvaleur(int entree);
    int getvaleur(){return _valeur;}

private:
    std::string _nom;
    Domaine _dmn;
    int _valeur;
};
