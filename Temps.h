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

#include <ctime> // time_t, struct tm *, gmtime.
#include <ostream>

class Temps
{
    friend std::ostream& operator<<(std::ostream& os, const Temps& temps);

    // Operateur de comparaisons
    friend bool operator< (const Temps& temps1, const Temps& temps2);
    friend bool operator> (const Temps& temps1, const Temps& temps2);
    friend bool operator<=(const Temps& temps1, const Temps& temps2);
    friend bool operator>=(const Temps& temps1, const Temps& temps2);
    friend bool operator==(const Temps& temps1, const Temps& temps2);
    friend bool operator!=(const Temps& temps1, const Temps& temps2);

    friend Temps operator+(Temps temps1, const Temps& temps2);
public:

    Temps();
    Temps(time_t temps); //Convertit au format UTC
    Temps(unsigned heure, unsigned minute, unsigned seconde = 0);

    //Accesseurs
    unsigned int getHeure() const;
    void setHeure(unsigned int heure);

    unsigned int getMinute() const;
    void setMinute(unsigned int minute);

    unsigned int getSeconde() const;
    void setSeconde(unsigned int seconde);
    
    //Surcharges d'opérateurs
//    Temps& operator--();    // pré  décrémentation (d'une seconde)
//    Temps  operator--(int); // post décrémentation (d'une seconde)
    Temps& operator+=(const Temps& temps);
    Temps& operator++();    // pré  incrémentation (d'une seconde)
    Temps  operator++(int); // post incrémentation (d'une seconde)
    operator double() const;

private:
    unsigned _heure  ;
    unsigned _minute ;
    unsigned _seconde;
};


#endif //LABO1_TEMPS_H
