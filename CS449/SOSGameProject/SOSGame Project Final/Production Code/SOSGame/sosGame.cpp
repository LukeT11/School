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
    for (int row = 0; row < maxCellSize; row++)
    {
        for (int col = 0; col < maxCellSize; col++)
        {
            cell[row][col] = Cell(EMPTY);
        }
    }
    connectedSOS.clear();
    currentGameState = GameState(PLAYING);
    turn = Turn(P1);
}

//Resets Game board back to default state
void sosGame::restartGame() {
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cell[row][col] = Cell(EMPTY);
        }
    }
    currentGameMode = GameMode(NONE);
    currentGameState = GameState(NOTPLAYING);
    connectedSOS.clear();
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

//Get and return connected SOS
vector<vector<int>> sosGame::getSOSConnected() {
    return connectedSOS;
}

//Get and return vecor size of connected SOS
int sosGame::getSOSConnectedNum()
{
    return connectedSOS.size();
}

/*Take input row/column/letter, check validation of cell. If empty, set players
turn letter, change turns*/
void sosGame::makeMove(int row, int col, int letter)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols
                    && cell[row][col] == Cell(EMPTY))
    {
        cell[row][col] = Cell(letter);
        bool isSOSConnected = sosConnected(turn, row, col, letter);
        if (currentGameMode == GENERAL && isSOSConnected == true) {
            checkGeneralGameOver();
        }
        else {
            if (currentGameMode == SIMPLE) {
                checkSimpleGameOver();
            }
            else if (currentGameMode == GENERAL && isSOSConnected == false) {
                checkGeneralGameOver();
             }
            if (turn == Turn(P1))
            {
                turn = Turn(P2);
            }
            else if (turn == Turn(P2))
            {
                turn = Turn(P1);
            }
        }
    }
}

//Checks for SOSs Connected for current move made
bool sosGame::sosConnected(int currentTurn, int selRow, int selCol, int letter)
{
    int token = letter;
    int row = selRow;
    int col = selCol;
    int playerTurn = currentTurn;
    bool connectSOS = false;
    if (token == LETTERS) {
        if (cell[row-1][col-1] == LETTERO && cell[row-2][col-2] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row-1, col-1, row-2, col-2);
            connectSOS = true;
        }
        if (cell[row-1][col] == LETTERO && cell[row-2][col] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row-1, col, row-2, col);
            connectSOS = true;
        }
        if (cell[row-1][col+1] == LETTERO && cell[row-2][col+2] == LETTERS)
        {
            addSOSConnected(playerTurn, row, col, row-1, col+1, row-2, col+2);
            connectSOS = true;
        }
        if (cell[row][col-1] == LETTERO && cell[row][col-2] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row, col-1, row, col-2);
            connectSOS = true;
        }
        if (cell[row][col+1] == LETTERO && cell[row][col+2] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row, col+1, row, col+2);
            connectSOS = true;
        }
        if(cell[row+1][col-1] == LETTERO && cell[row+2][col-2] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row+1, col-1, row+2, col-2);
            connectSOS = true;
        }
        if (cell[row+1][col] == LETTERO && cell[row+2][col] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row+1, col, row+2, col);
            connectSOS = true;
        }
        if (cell[row+1][col+1] == LETTERO && cell[row+2][col+2] == LETTERS) {
            addSOSConnected(playerTurn, row, col, row+1, col+1, row+2, col+2);
            connectSOS = true;
        }
    }
    else if(token == LETTERO) {
        if (cell[row-1][col-1] == LETTERS && cell[row+1][col+1] == LETTERS) {
            addSOSConnected(playerTurn, row-1, col-1, row, col, row+1, col+1);
            connectSOS = true;
        }
        if (cell[row-1][col] == LETTERS && cell[row+1][col] == LETTERS) {
            addSOSConnected(playerTurn, row-1, col, row, col, row+1, col);
            connectSOS = true;
        }
        if (cell[row-1][col+1] == LETTERS && cell[row+1][col-1] == LETTERS)
        {
            addSOSConnected(playerTurn, row-1, col+1, row, col, row+1, col-1);
            connectSOS = true;
        }
        if (cell[row][col-1] == LETTERS && cell[row][col+1] == LETTERS) {
            addSOSConnected(playerTurn, row, col-1, row, col, row, col+1);
            connectSOS = true;
        }
    }
    return connectSOS;
}
//Add a connected sos to vector fo connectedSOS
void sosGame::addSOSConnected(int currentTurn, int row1, int col1, int row2, int col2, int row3, int col3)
{
    vector<int> sosConnect = {currentTurn, row1, col1, row2, col2, row3, col3};
    connectedSOS.push_back(sosConnect);
}

//Check if all cells have been filled with a valid move
bool sosGame::checkAllCellsFilled() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cell[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

//Check if simple game is over
void sosGame::checkSimpleGameOver()
{
    if (connectedSOS.size() != 0) {
        if (connectedSOS.at(0).at(0) == P1) {
            currentGameState = PLAYERONE_WON;
        }
        else if (connectedSOS.at(0).at(0) == P2) {
            currentGameState = PLAYERTWO_WON;
        }
    }
    else if (connectedSOS.size() == 0 && checkAllCellsFilled() == true) {
        currentGameState = DRAW;
    }
}

//Check if a general game is over
void sosGame::checkGeneralGameOver()
{
    bool cellEmpty = checkAllCellsFilled();
    if (cellEmpty == true) {
        int playerOneNumSOS = 0;
        int playerTwoNumSOS = 0;
        int sizeConnectedSOS = connectedSOS.size();
        for (int i = 0; i < sizeConnectedSOS; i++) {
            if (connectedSOS.at(i).at(0) == P1) {
                playerOneNumSOS += 1;
            }
            else if (connectedSOS.at(i).at(0) == P2) {
                playerTwoNumSOS += 1;
            }
        }
        if (playerOneNumSOS == playerTwoNumSOS) {
            currentGameState = DRAW;
        }
        else if(playerOneNumSOS > playerTwoNumSOS) {
            currentGameState = PLAYERONE_WON;
        }
        else if(playerOneNumSOS < playerTwoNumSOS) {
            currentGameState = PLAYERTWO_WON;
        }
    }
}

//Deconstructor
sosGame::~sosGame()
{
}
