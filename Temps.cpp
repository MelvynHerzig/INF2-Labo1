/*
 -----------------------------------------------------------------------------------
 Laboratoire : 01
 Fichier     : Temps.cpp
 Auteur(s)   : Melvyn Herzig, Forestier Quentin, Logan Victoria
 Date        : 02.03.2020

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iomanip>
#include "Temps.h"

/* ------------------ FONCTIONS AMIES --------------------*/
std::ostream& operator<<(std::ostream& os, const Temps& temps)
{
    return os << std::setw(2) << std::setfill('0')
              << temps._heure << ':' << temps._minute << ':' << temps._seconde;
}


/* ------------------- CONSTRUCTEURS ---------------------*/
Temps::Temps() : _heure(0), _minute(0), _seconde(0)
{}

Temps::Temps(time_t temps)
{
    struct tm * ptm;
    ptm = gmtime(&temps);

    _heure   = (unsigned)ptm->tm_hour;
    _minute  = (unsigned)ptm->tm_min ;
    _seconde = (unsigned)ptm->tm_sec ;
}

Temps::Temps(unsigned heure, unsigned minute, unsigned seconde)
: _heure (heure), _minute(minute), _seconde(seconde)
{}


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


/* -------------------- SURCHAGE D'OPERATEURS ----------------------*/
// pré-incrémentation (d'une seconde)
Temps& Temps::operator++()
{
    if(++_seconde > 59){
        _seconde -= 60;
        if(++_minute > 59){
            _minute -= 60;
            if(++_heure > 23){
                _heure -= 24;
            }
        }
    }
    return *this;
}

// post-incrémentation (d'une seconde)
Temps  Temps::operator++(int)
{
    Temps temp(_heure, _minute, _seconde); // MANQUE LE CONSTRUCTEUR POUR QUE OK
    if(++_seconde > 59){
        _seconde -= 60;
        if(++_minute > 59){
            _minute -= 60;
            if(++_heure > 23){
                _heure -= 24;
            }
        }
    }
    return temp;
}
