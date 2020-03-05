/*
 -----------------------------------------------------------------------------------
 Laboratoire : 01
 Fichier     : Temps.h
 Auteur(s)   : Melvyn Herzig, Forestier Quentin, Logan Victoria
 Date        : 02.03.2020

 But         : Fournir un objet temps pour stocker les heures minutes secondes
               de 00:00:00 à 23:59:59.

 Remarque(s) : Aucune vérification des données passées en paramètre n'est faite.
               Il est par exemple possible de faire setSeconde(70)

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO1_TEMPS_H
#define LABO1_TEMPS_H

#include <ctime>   // time_t, struct tm *, gmtime.
#include <ostream> //std::ostream

class Temps
{
    const static unsigned SECONDE_MAX_DANS_JOUR;

    friend std::ostream& operator<<(std::ostream& os, const Temps& temps);

    // Opérateurs de comparaisons
    friend bool operator< (const Temps& temps1, const Temps& temps2);
    friend bool operator> (const Temps& temps1, const Temps& temps2);
    friend bool operator<=(const Temps& temps1, const Temps& temps2);
    friend bool operator>=(const Temps& temps1, const Temps& temps2);
    friend bool operator==(const Temps& temps1, const Temps& temps2);
    friend bool operator!=(const Temps& temps1, const Temps& temps2);

    friend Temps operator+(Temps temps1, const Temps& temps2);
    friend Temps operator-(Temps temps1, const Temps& temps2);

public:

    Temps();
    Temps(time_t temps); //Convertit au format UTC
    Temps(unsigned heure, unsigned minute, unsigned seconde = 0);
    Temps(unsigned secondes);

    //Accesseurs
    unsigned int getHeure() const;
    void setHeure(unsigned int heure);

    unsigned int getMinute() const;
    void setMinute(unsigned int minute);

    unsigned int getSeconde() const;
    void setSeconde(unsigned int seconde);
    
    //Surcharges d'opérateurs
    Temps& operator+=(const Temps& temps);
    Temps& operator++();    // pré  incrémentation (d'une seconde)
    Temps  operator++(int); // post incrémentation (d'une seconde)

    Temps& operator-=(const Temps& temps);
    Temps& operator--();    // pré   décrémentation (d'une seconde)
    Temps  operator--(int); // post  décrémentation (d'une seconde)

    operator double() const; //Comvertit le temps courant en heures

    unsigned enSeconde() const; //Retourne le temps courant en secondes

private:
    unsigned _heure  ;
    unsigned _minute ;
    unsigned _seconde;
};


#endif //LABO1_TEMPS_H
