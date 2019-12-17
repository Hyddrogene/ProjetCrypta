#include <iostream>
#include <string>
#include "variable.hh"
#include <vector>
#include "node.h"

#include <algorithm>
#include <cctype>

using namespace std;

//===================================================================
//===================================================================

int main(int argc, char *argv[])
{
//==========================================
//============== Declaration ===============
//==========================================

    std::vector<std::string> stockString;
    std::string output="";

//==========================================
//======== Traitement de la casse ==========
//==========================================

    std::cout <<std::endl;
    //lecture entrée, et traitement de la casse
    for(int i=1;i<argc;i++){
         std::string val(argv[i]);
         //traitement de la cahine val pour la casse
             std::transform(val.begin(), val.end(), val.begin(),
                            [](unsigned char c) -> unsigned char { return static_cast<unsigned char>(std::toupper(c)); });

             //On stock les differentes entrée dasn cette string
        stockString.push_back(val);

        //debug
       // std::cout << stockString.at(static_cast<unsigned int>(i-1)) <<std::endl;
    }
//==========================================
//============== Squelette =================
//==========================================


    Domaine d1(0,1);
    Domaine d2(0,9);
    Variable r1("r1",d1);
    Variable d("d",d2);
    Variable e("e",d2);
    Variable y("y",d2);
    std::string salut="Thomas le RAGEUX";
    //Retenue sont 0 et nboperateur-1
   /* Contrainte e+d=y+10*r1;*/
   std::cout << salut <<std::endl;
    return 0;
}
