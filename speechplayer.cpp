#include "speechplayer.h"

speechPlayer::speechPlayer()
{
    this->name="\0";
    this->score=0;
}

speechPlayer::speechPlayer(string name, float score)
{
    this->name=name;
    this->score=score;
}

float speechPlayer::getScore() const
{
    return score;
}

void speechPlayer::setScore(float newScore)
{
    score = newScore;
}

const string &speechPlayer::getName() const
{
    return name;
}

void speechPlayer::setName(const string &newName)
{
    name = newName;
}
