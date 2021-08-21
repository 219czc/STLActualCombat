#ifndef SPEECHPLAYER_H
#define SPEECHPLAYER_H
#include<string>
#include<iostream>
using namespace std;

class speechPlayer
{
public:
    speechPlayer();
    speechPlayer(string name,float score=0);
    float getScore() const;
    void setScore(float newScore);

    const string &getName() const;
    void setName(const string &newName);

private:
    float score;
    string name;
};

#endif // SPEECHPLAYER_H
