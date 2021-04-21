#include "models/ant.hpp"

//constructeur
Ant::Ant(/* args */)
{

}


//Return un bool en fonction de si la fourmie est en vie
bool Ant::inLife() const
{
    return lifePoint > 0;
}


//retourne un bool en fonction de si la fourmie porte un sucre
bool Ant::haveSugar() const
{
    return sugar > 0;
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


void Ant::takeSugar()
{

}


vois Ant::dropSugar()
{

}


void Ant::move(pos)
{

}


Coord Ant::coord() const
{
    return pos;
}