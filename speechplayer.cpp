#include "speechplayer.h"

speechPlayer::speechPlayer()
{
    this->name = "\0";
    this->num = 0;
    this->score = new float;
    *(this->score) = 0;
}

speechPlayer::speechPlayer(string name, float score)
{
    this->name = name;
    this->num = 0;
    this->score = new float;
    *(this->score) = score;
}

float* speechPlayer::getScore() const
{
    return score;
}

void speechPlayer::setScore(float newScore)
{
    float* fl = new float[num + 1];
    for (int i = 0; i < num ; i++) {
        *(fl + i) = *(score + i);
    }
    *(fl + num) = newScore;
    if (score != NULL) {
        delete[] score;
    }
    score = fl;

    num++;
    //return score;
}

const string& speechPlayer::getName() const
{
    return name;
}

void speechPlayer::setName(const string& newName)
{
    name = newName;
}

int speechPlayer::getNum() const
{
    return num;
}
