#include "models/ant.hpp"

//constructeur
Ant::Ant(
    int number,
    Coord pos) : _number(number),
                 _lifePoint(10),
                 _sugar(0),
                 _pos(pos)
{

}


//getter
Coord Ant::getCoord() const
{
    return _pos;
}


int Ant::getNumber() const
{
    return _number;
}

//fin des getters


//Return un bool en fonction de si la fourmie est en vie
bool Ant::inLife() const
{
    return _lifePoint > 0;
}


//retourne un bool en fonction de si la fourmie porte un sucre
bool Ant::haveSugar() const
{
    return _sugar > 0;
}


//Les fonctions suvante son suprimable blabla avec valéran

//Retourne True si la fourmie n'as pas de sucre
bool Ant::research() const
{
    return haveSugar();
}

//Retourne False si la fourmie possède du sucre
bool Ant::backHome() const
{
    return haveSugar();
}


//Ajoute un sucre a la fourmie
void Ant::takeSugar()
{
    _sugar += 1;
}


//Enlève tous les sucres que porte la fourmie
void Ant::dropSugar()
{
    _sugar = 0;
}


//Déplace la fourmie a la case la plus logique(blabla valéran)
void Ant::move(Coord _pos)
{

}