#ifndef SOSGAME_H
#define SOSGAME_H
#include <QtWidgets>
using namespace std;
#include <vector>

class sosGame
{
public:
    sosGame();
    ~sosGame();
    enum GameMode{NONE, SIMPLE, GENERAL};
    enum GameState{NOTPLAYING, PLAYING, DRAW, PLAYERONE_WON, PLAYERTWO_WON};
    enum Cell{EMPTY, LETTERS, LETTERO};
    enum Turn{P1, P2};
    int getRows();
    int getCols();
    int getGameState();
    int getGameMode();
    int getTurn();
    int getCell(int row, int col);
    vector<vector<int>> getSOSConnected();
    int getSOSConnectedNum();
    void newGame(int boardSize, int gameMode);
    void restartGame();
    void makeMove(int row, int col, int letter);

private:
    int maxCellSize = 25;
    int rows;
    int cols;
    int letter;
    int cell[25][25];
    int turn;
    vector<vector<int>> connectedSOS;
    GameState currentGameState;
    GameMode currentGameMode;
    void initGameBoard();
    bool sosConnected(int currentTurn, int selRow, int selCol, int letter);
    void addSOSConnected(int currentTurn, int row1, int col1, int row2, int col2, int row3, int col3);
    bool checkAllCellsFilled();
    void checkSimpleGameOver();
    void checkGeneralGameOver();
};

#endif // SOSGAME_H
