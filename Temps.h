/*
 -----------------------------------------------------------------------------------
 Laboratoire : 01
 Fichier     : Temps.h
 Auteur(s)   : Melvyn Herzig, Forestier Quentin, Logan Victoria
 Date        : 02.03.2020

 But         : /

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO1_TEMPS_H
#define LABO1_TEMPS_H

#include <ctime>

class Temps
{
public:

    Temps();
    Temps(time_t temps);
    Temps(unsigned heure, unsigned minute, unsigned seconde = 0);

    //Accesseurs
    unsigned int getHeure() const;
    void setHeure(unsigned int heure);

    unsigned int getMinute() const;
    void setMinute(unsigned int minute);

    unsigned int getSeconde() const;
    void setSeconde(unsigned int seconde);

private:
    unsigned _heure  ;
    unsigned _minute ;
    unsigned _seconde;
};


#endif //LABO1_TEMPS_H
