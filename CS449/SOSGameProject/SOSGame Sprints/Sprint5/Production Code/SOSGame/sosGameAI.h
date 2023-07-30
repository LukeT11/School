#ifndef SOSGAMEAI_H
#define SOSGAMEAI_H
#include <QtWidgets>
using namespace std;
#include <sosGame.h>
#include <string>
#include <vector>

class sosGameAI
{
public:
    sosGameAI();
    ~sosGameAI();
    vector<int> getAIMove(sosGame currentGame);

private:
    sosGame game;
    vector<int> calcGameMove();
};

#endif // SOSGAMEAI_H
