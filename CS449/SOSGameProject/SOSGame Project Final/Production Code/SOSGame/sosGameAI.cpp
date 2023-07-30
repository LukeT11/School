#include "sosGameAI.h"

sosGameAI::sosGameAI()
{

}

//Current SOS Game Board passed to function, returns a vector with a move to make.
vector<int> sosGameAI::getAIMove(sosGame currentGame) {
    vector<int> moveAIItems;
    game = currentGame;
    moveAIItems = calcGameMove();
    return moveAIItems;
}

//Computer finds a move to make on the board
vector<int> sosGameAI::calcGameMove() {
    vector<int> vecMoveAI;
    vector<int> tempVecMoveAI;
    bool completeSOSMove = false;
    bool nonCompleteSOSMoveSafe = false;
    for(int i = 0; i < game.getRows(); i++) {
        for (int j = 0; j < game.getCols(); j++) {
        //Checks to see if the cell is empty for a playable move
            if (game.getCell(i, j) == game.EMPTY) {
                tempVecMoveAI.clear();
            //First Checks to see if an SOS can be completed
                if (game.getCell(i-1, j-1) == game.LETTERO && game.getCell(i-2, j-2) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i-1, j) == game.LETTERO && game.getCell(i-2, j) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i-1, j+1) == game.LETTERO && game.getCell(i-2, j+2) == game.LETTERS)
                {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i, j-1) == game.LETTERO && game.getCell(i, j-2) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i, j+1) == game.LETTERO && game.getCell(i, j+2) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if(game.getCell(i+1, j-1) == game.LETTERO && game.getCell(i+2, j-2) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i+1, j) == game.LETTERO && game.getCell(i+2, j) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i+1, j+1) == game.LETTERO && game.getCell(i+2, j+2) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i-1, j-1) == game.LETTERS && game.getCell(i+1, j+1) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERO);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i-1, j) == game.LETTERS && game.getCell(i+1, j) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERO);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i-1, j+1) == game.LETTERS && game.getCell(i+1, j-1) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERO);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
                else if (game.getCell(i, j-1) == game.LETTERS && game.getCell(i, j+1) == game.LETTERS) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERO);
                    completeSOSMove = true;
                    vecMoveAI = tempVecMoveAI;
                    break;
                }
            //Then checks to make sure the move its making doesn't create an SOS for the opponent
                else if ((nonCompleteSOSMoveSafe != true) && (game.getCell(i-1, j-1) != game.LETTERO &&
                game.getCell(i-1, j) != game.LETTERO && game.getCell(i-1, j+1) != game.LETTERO &&
                game.getCell(i, j-1) != game.LETTERO && game.getCell(i, j+1) != game.LETTERO &&
                game.getCell(i+1, j-1) != game.LETTERO && game.getCell(i+1, j) != game.LETTERO &&
                game.getCell(i+1, j+1) != game.LETTERO && game.getCell(i-2, j-2) != game.LETTERS &&
                game.getCell(i-2, j) != game.LETTERS && game.getCell(i-2, j+2) != game.LETTERS &&
                game.getCell(i, j-2) != game.LETTERS && game.getCell(i, j+2) != game.LETTERS &&
                game.getCell(i+2, j-2) != game.LETTERS && game.getCell(i+2, j) != game.LETTERS &&
                game.getCell(i+2, j+2) != game.LETTERS)) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    nonCompleteSOSMoveSafe = true;
                    vecMoveAI = tempVecMoveAI;
                }
                else if ((nonCompleteSOSMoveSafe != true) && (game.getCell(i-1, j-1) != game.LETTERS &&
                game.getCell(i-1, j) != game.LETTERS && game.getCell(i-1, j+1) != game.LETTERS &&
                game.getCell(i, j-1) != game.LETTERS && game.getCell(i, j+1) != game.LETTERS &&
                game.getCell(i+1, j-1) != game.LETTERS && game.getCell(i+1, j) != game.LETTERS &&
                game.getCell(i+1, j+1) != game.LETTERS)) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERO);
                    nonCompleteSOSMoveSafe = true;
                    vecMoveAI = tempVecMoveAI;
                }
            /*Lastly, if the cell is empty and no move has been selected, then it will automatically
              store this move as the default move as an 'S' unless a better move can be found.*/
                else if (game.getCell(i, j) == game.EMPTY && vecMoveAI.empty()) {
                    tempVecMoveAI.push_back(i);
                    tempVecMoveAI.push_back(j);
                    tempVecMoveAI.push_back(game.LETTERS);
                    vecMoveAI = tempVecMoveAI;
                }
            }   
        }
        if (completeSOSMove == true) {
            break;
        }
    }
    return vecMoveAI;
}

sosGameAI::~sosGameAI()
{
}
