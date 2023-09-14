#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "person.h"

class Player : public Person
{
      //Overload de << afin de pouvoir afficher un objet de la classe Person (une ref)
      friend std::ostream& operator<<(std::ostream& out, const Player& player);
    public:
      Player();
      Player(std::string game_param, std::string first_name_param, std::string last_name_param);
      //~Player(); //Destructor déclaré

    private:
     std::string m_game{"None"};

};
#endif


