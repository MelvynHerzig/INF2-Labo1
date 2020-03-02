/*
 -----------------------------------------------------------------------------------
 Laboratoire : 01
 Fichier     : Temps.cpp
 Auteur(s)   : Melvyn Herzig, Forestier Quentin, Logan Victoria
 Date        : 02.03.2020

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "Temps.h"

/* ------------------- CONSTRUCTEURS ---------------------*/
Temps::Temps() : _heure(0), _minute(0), _seconde(0)
{}

Temps::Temps(const time_t& temps)
{
    _heure   = (temps / 3600) % 24;
    _minute  = (temps / 60)   % 60;
    _seconde = temps % 60;
}


/* -------------------- ACCESSEURS ----------------------*/
unsigned int Temps::getHeure() const
{
    return _heure;
}

void Temps::setHeure(unsigned int heure)
{
    _heure = heure;
}

unsigned int Temps::getMinute() const
{
    return _minute;
}

void Temps::setMinute(unsigned int minute)
{
    _minute = minute;
}

unsigned int Temps::getSeconde() const
{
    return _seconde;
}

void Temps::setSeconde(unsigned int seconde)
{
    _seconde = seconde;
}
