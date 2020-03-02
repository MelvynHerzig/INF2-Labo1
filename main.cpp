/*
 -----------------------------------------------------------------------------------
 Laboratoire : 01
 Fichier     : main.cpp
 Auteur(s)   : Melvyn Herzig, Forestier Quentin, Logan Victoria
 Date        : 02.03.2020

 But         : Tester les fonctionnalités mises à disposition par la classe Temps

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>  //EXIT_SUCCESS
#include "Temps.h"

int main()
{

    time_t maintenant = time(NULL);

    //Tests constructeurs
    Temps t0;
    Temps t1(maintenant);
    const Temps t2(15,30,10);
    Temps t3(10,50);

    std::cout << "t0 : " << t0 << std::endl
              << "t1 : " << t1 << std::endl
              << "t2 : " << t2 << std::endl
              << "t3 : " << t3 << std::endl;

    std::cout << std::endl;

    //Tests Accesseurs (Get - Set)
    t0.setHeure(10);
    std::cout << "setHeure t0: " << t0 << std::endl;

    t0.setMinute(20);
    std::cout << "setMinute t0: " << t0 << std::endl;

    t0.setSeconde(30);
    std::cout << "setSeconde t0: " << t0 << std::endl;

    std::cout << "getHeure t2: " << t2.getHeure() << std::endl;

    std::cout << "getMinute t2: " << t2.getMinute() << std::endl;

    std::cout << "getSeconde t2: " << t2.getSeconde() << std::endl;

    std::cout << std::endl;

    //Comparaisons
    const Temps t5 = Temps(11,12,13);
    const Temps t6 = Temps(12,0,0);

    std::cout << std::boolalpha << t5 << " <  " << t6 << ' ' << (t5 <  t6) << std::endl
              << std::boolalpha << t5 << " <  " << t5 << ' ' << (t5 <  t5) << std::endl
              << std::boolalpha << t6 << " <  " << t5 << ' ' << (t6 <  t5) << std::endl;

    std::cout << std::endl;

    std::cout << std::boolalpha << t5 << " <= " << t6 << ' ' << (t5 <= t6) << std::endl
              << std::boolalpha << t5 << " <= " << t5 << ' ' << (t5 <= t5) << std::endl
              << std::boolalpha << t6 << " <= " << t5 << ' ' << (t6 <= t5) << std::endl;

    std::cout << std::endl;

    std::cout << std::boolalpha << t5 << " >  " << t6 << ' ' << (t5 >  t6) << std::endl
              << std::boolalpha << t5 << " >  " << t5 << ' ' << (t5 >  t5) << std::endl
              << std::boolalpha << t6 << " >  " << t5 << ' ' << (t6 >  t5) << std::endl;

    std::cout << std::endl;

    std::cout << std::boolalpha << t5 << " >= " << t6 << ' ' << (t5 >= t6) << std::endl
              << std::boolalpha << t5 << " >= " << t5 << ' ' << (t5 >= t5) << std::endl
              << std::boolalpha << t6 << " >= " << t5 << ' ' << (t6 >= t5) << std::endl;

    std::cout << std::endl;

    std::cout << std::boolalpha << t5 << " == " << t6 << ' ' << (t5 == t6) << std::endl
              << std::boolalpha << t5 << " == " << t5 << ' ' << (t5 == t5) << std::endl
              << std::boolalpha << t6 << " == " << t5 << ' ' << (t6 == t5) << std::endl;

    std::cout << std::endl;

    std::cout << std::boolalpha << t5 << " != " << t6 << ' ' << (t5 != t6) << std::endl
              << std::boolalpha << t5 << " != " << t5 << ' ' << (t5 != t5) << std::endl
              << std::boolalpha << t6 << " != " << t5 << ' ' << (t6 != t5) << std::endl;

    //Incréments et décréments post-prefixés

    /*
    std::cout << "pré  ++ de " << t0 << " = " << ++t0 << std::endl
              << "Post ++ de  "<< t0 << " = " << t0++ << std::endl
              << "valeur finale de " << t0 << " = " << t0 << std::endl;

    std::cout << "pré  -- de " << t0 << " = " << --t0 << std::endl
              << "Post -- de " << t0 << " = " << t0-- << std::endl
              << "valeur finale de " << t0 << " = " << t0 << std::endl;

    std::cout << std::endl;*/

    //Addition et soustraction
    /*Temps t7 = Temps(23,30,30);
    Temps t8 = Temps(2 ,16,15);
    const Temps t9  = (23,30,30);
    const Temps t10 = (2,16,15);
    const Temps t11 = (2,45,45);

    std::cout << t9  << " +  "  << t11 << " = " << t9  +   t11 << std::endl
              << t7  << " += "  << t11 << " = " << t7  +=  t11 << std::endl
              << t10 << " -  "  << t11 << " = " << t10  -  t11 << std::endl
              << t8  << " -= "  << t11 << " = " << t8  -=  t11 << std::endl;

    std::cout << std::endl;*/

    //Affichage
    const Temps t12(23,05,55);
    std::cout << "Affichage de t12 " << t2 << std::endl;

    std::cout << std::endl;

    //Operateur de conversion
    double heure = t12;
    std::cout << "Conversion de " << t12 << " en double = " << heure << std::endl;

    return EXIT_SUCCESS;
}
