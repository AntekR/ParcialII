#include "player.h"


Player::Player(string nick, char colorCard)
{
    name = nick;
    color = colorCard;
    score = 0;
}

char Player::getColor(){
    return color;
}

string Player:: getName(){
    return name;
}

void Player::setScore(int scoreAct){
    score = scoreAct;
}

int Player::getScore(){
    return score;
}
