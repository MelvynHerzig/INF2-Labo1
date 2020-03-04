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
    const char FILL = '0';
    const unsigned WIDTH = 2;

    return os << std::setw(WIDTH) << std::setfill(FILL)
              << temps._heure << ':'
              << std::setw(WIDTH) << std::setfill(FILL)
              << temps._minute << ':'
              << std::setw(WIDTH) << std::setfill(FILL)
              << temps._seconde;
}

bool operator<(const Temps &temps1, const Temps &temps2)
{
    return temps1._heure < temps2._heure
        || (temps1._heure == temps2._heure
            && temps1._minute < temps2._minute)
        || (temps1._heure == temps2._heure
            && temps1._minute < temps2._minute
            &&  temps1._seconde < temps2._seconde);
}

bool operator>(const Temps &temps1, const Temps &temps2)
{
    return temps2 < temps1;
}

bool operator<=(const Temps &temps1, const Temps &temps2)
{
    return !(temps1 > temps2);
}

bool operator>=(const Temps &temps1, const Temps &temps2)
{
    return !(temps1 < temps2);
}

bool operator==(const Temps &temps1, const Temps &temps2)
{
    return temps1._heure   == temps2._heure
        && temps1._minute  == temps2._minute
        && temps1._seconde == temps2._seconde;
}

bool operator!=(const Temps &temps1, const Temps &temps2)
{
    return !(temps1 == temps2);
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
: _heure(heure), _minute(minute), _seconde(seconde)
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

//// pré-incrémentation (d'une seconde)
//Temps& Temps::operator++()
//{
//    if(++_seconde > 59){
//        _seconde -= 60;
//        if(++_minute > 59){
//            _minute -= 60;
//            if(++_heure > 23){
//                _heure -= 24;
//            }
//        }
//    }
//    return *this;
//}
//
//// post-incrémentation (d'une seconde)
//Temps  Temps::operator++(int)
//{
//    Temps temp = *this;
//    ++(*this);
//    return temp;
//}
//
//
//// pré décrémentation (d'une seconde)
//Temps& Temps::operator--()
//{
//    if(_seconde == 0){
//    _seconde = 60;
//    }
//    return *this;
//}

//// post décrémentation (d'une seconde)
//Temps Temps::operator--(int)
//{
//
//}
    
Temps& Temps::operator+=(const Temps& temps)
{
    if(_seconde += temps._seconde > 59){
        _seconde -= 60;
        ++_minute;
    }
    if(_minute += temps._minute > 59) {
        _minute -= 60;
        ++_heure;
    }
    if(_heure += temps._heure > 23){
        _heure -= 24;
    }
    return *this;
}

Temps::operator double() const
{
    return _heure + (60. * _minute + _seconde) / 3600;
}

