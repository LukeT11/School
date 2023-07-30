#ifndef SOSGAME_H
#define SOSGAME_H
#include <QtWidgets>

class sosGame
{
public:
    sosGame();
    ~sosGame();

    int getRows();
    int getCols();
    int getGameState();
    int getGameMode();
    int getTurn();
    int getCell(int row, int col);

    void newGame(int boardSize, int gameMode);
    void makeMove(int row, int col, int letter);
    void setBoardSize(int boardSize);
    void setBoardMode(int boardMode);

    enum GameMode{NONE, SIMPLE, GENERAL};
    enum GameState{NOTPLAYING, PLAYING, DRAW, CROSS_WON, NOUGHT_WON};
    enum Cell{EMPTY, LETTERS, LETTERO};
    enum Turn{P1, P2};

private:
    int rows;
    int cols;
    int letter;
    int cell[25][25];
    int turn;
    GameState currentGameState;
    GameMode currentGameMode;

    void initGameBoard();
};

#endif // SOSGAME_H
