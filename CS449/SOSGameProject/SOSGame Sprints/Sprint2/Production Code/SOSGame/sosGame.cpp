#include "sosGame.h"

//SOSGame Constructor, initialize variables to zero
sosGame::sosGame()
{
    rows = 0;
    cols = 0;
    letter = 0;
    turn = Turn(P1);
    currentGameMode = GameMode(NONE);
    currentGameState = GameState(NOTPLAYING);
}

//Sets new game, takes board size and game mode input, sets variables
void sosGame::newGame(int boardSize, int gameMode)
{
    rows = boardSize;
    cols = boardSize;
    currentGameMode = GameMode(gameMode);
    initGameBoard();
}

//Initiate new game board, set col and rows size to empty, gamestate to playing
void sosGame::initGameBoard()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cell[row][col] = Cell(EMPTY);
        }
    }
    currentGameState = GameState(PLAYING);
    turn = Turn(P1);
}

//Return Rows
int sosGame::getRows()
{
    return rows;
}

//Return Columns
int sosGame::getCols()
{
    return cols;
}

//Return Game State
int sosGame::getGameState()
{
    return currentGameState;
}

//Return Game Mode
int sosGame::getGameMode()
{
    return currentGameMode;
}

//Return Turn
int sosGame::getTurn()
{
    return turn;
}

//Return game board cell status
int sosGame::getCell(int row, int col)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return cell[row][col];
    }
    else
    {
        return 0;
    }
}

//Get and Set board size rows and columns
void sosGame::setBoardSize(int boardSize)
{
    rows = boardSize;
    cols = boardSize;
}

//Get and Set Game Board Mode
void sosGame::setBoardMode(int boardMode)
{
    currentGameMode = GameMode(boardMode);
}

/*Take input row/column/letter, check validation of cell. If empty, set players
turn letter, change turns*/
void sosGame::makeMove(int row, int col, int letter)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols
                    && cell[row][col] == Cell(EMPTY))
    {
            if (turn == Turn(P1))
            {
                cell[row][col] = Cell(letter);
                turn = Turn(P2);
            }
            else if (turn == Turn(P2))
            {
                cell[row][col] = Cell(letter);
                turn = Turn(P1);
            }
    }
}
sosGame::~sosGame()
{
}
