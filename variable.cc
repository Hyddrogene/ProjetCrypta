#include "variable.hh"


Variable::Variable(std::string nom,Domaine dmn):
    _nom(nom),_dmn(dmn){}


bool Variable::setvaleur(int entree){
    if((entree>_dmn.getposx() &&entree <_dmn.getposx1() )||)
}
