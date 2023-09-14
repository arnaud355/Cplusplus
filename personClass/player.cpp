#include "person.h"
#include "player.h"

Player::Player(std::string game_param, std::string first_name_param, std::string last_name_param)
{
     m_game = game_param;
     m_first_name = first_name_param;
     m_last_name = last_name_param;
}
std::ostream& operator<<(std::ostream& out, const Player& player){
    out << "Player : [ game : " << player.m_game
    << " ,name  :" << player.GetFirstName()<< " " << player.GetLastName() << "]";
    return out;
}
