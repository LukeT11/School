#include "sosGUI.h"
//#include "sosGame.h"

//sosGUI class Constructor, calls to create SOS GUI and sets the mainWindow
sosGUI::sosGUI(QWidget *parent): QMainWindow(parent)
    //ui(new Ui::sosGUI)
{
    //ui->setupUi(this);
    createSOSGameBoard();
    setWindowTitle("SOS Game");
    setFixedSize(fixedWidthWindow, fixedHeightWindow);
    setStyleSheet("background-color: white;");
    setVisible(true);
}

//Creates SOS Game GUI, calls to set GUI
void sosGUI::createSOSGameBoard()
{
    setContentSOS();
}

//Creates visual widgets of the SOS GUI
void sosGUI::setContentSOS()
{
    radioButtons();
    createLabels();
    createInputWidgets();
    pushButtons();
    newGameStart();
}

//Sets a New SOS Game for the GUI and calls to set GUI to Start of a New Game
void sosGUI::newSOSGame(sosGame newGame)
{
    game = newGame;
    setGameStart();
}

//Paints and draws parts for the GUI
void sosGUI::paintEvent(QPaintEvent *)
{
    drawGameGrid();
    drawGameBoard();
}

//Draws the SOS Game Board
void sosGUI::drawGameGrid()
{
        QPainter drawBoard(this);
        QPen pen;
        pen.setWidth(penSizeDrawBoard);
        drawBoard.setPen(pen);
        double cellSizeAdj = cellSize / boardSize;
        drawBoard.drawRect(rectX, rectY,
            (cellSize), (cellSize));

        for(int col = 0; col < boardSize; col++)
        {
            drawBoard.drawLine(rectX + (cellSizeAdj * col), rectY,
                rectX + (cellSizeAdj * col),
                rectY + (cellSizeAdj * boardSize));
        }
        for(int row = 1; row < boardSize; row++)
        {
            drawBoard.drawLine(rectX, rectY + (cellSizeAdj * row),
                rectX + (cellSizeAdj * boardSize),
                rectY + (cellSizeAdj * row));
        }
}

//Draws SOS game moves for the current game
void sosGUI::drawGameBoard()
{
    if (game.getGameState() != game.NOTPLAYING) {
        QPainter drawBoard(this);
        QPen pen;
        pen.setWidth(penSizeDrawBoard);
        drawBoard.setPen(pen);
        double cellSizeAdj = cellSize / boardSize;
        drawBoard.setFont(QFont("Times", (cellSizeAdj / 2.2), QFont::Bold));
        for (int row = 0; row < game.getRows(); ++row)
        {
            for (int col = 0; col < game.getCols(); ++col)
            {
                int x = (col * (cellSizeAdj) + rectX + (cellSizeAdj / 3.5));
                int y = (row * (cellSizeAdj) + rectY + (cellSizeAdj / 1.4));

                if (game.getCell(row, col) == game.LETTERS)
                {
                    drawBoard.drawText(x, y, "S");
                }
                else if (game.getCell(row, col) == game.LETTERO)
                {
                    drawBoard.drawText(x, y, "O");
                }
            }
        }
        vector<vector<int>> SOSconnected = game.getSOSConnected();
        int numConnectedSOS = SOSconnected.size();
        for (int i = 0; i < numConnectedSOS; i++) {
            if (SOSconnected.at(i).at(0) == Turn(P1)) {
                pen.setColor("blue");
            }
            else if (SOSconnected.at(i).at(0) == Turn(P2)) {
                pen.setColor("red");
            }
            drawBoard.setPen(pen);
            drawBoard.drawLine((SOSconnected.at(i).at(2) * (cellSizeAdj) + rectX + (cellSizeAdj)/2),
                (SOSconnected.at(i).at(1) * (cellSizeAdj) + rectY + (cellSizeAdj)/2),
                (SOSconnected.at(i).at(6) * (cellSizeAdj) + rectX + (cellSizeAdj)/2),
                (SOSconnected.at(i).at(5) * (cellSizeAdj) + rectY + (cellSizeAdj)/2));
        }
    }
}

//Creates SOS GUI Radio Buttons (Blue SO, Red SO, Simple/General Game)
void sosGUI::radioButtons()
{
    holdBlueSO = new QWidget(this);
    holdRedSO = new QWidget(this);
    holdGameType = new QWidget(this);
    layoutRedPlayer= new QVBoxLayout;
    layoutGameChoice = new QHBoxLayout;
    layoutBluePlayer = new QVBoxLayout;
    bluePlayer = new QLabel("Blue Player", this);
    redPlayer = new QLabel("Red Player", this);
    title = new QLabel("SOS   ", this);
    bluePlayerS = new QRadioButton("S", this);
    bluePlayerO = new QRadioButton("O", this);
    redPlayerS = new QRadioButton("S", this);
    redPlayerO = new QRadioButton("O", this);
    simpleGame = new QRadioButton("Simple Game", this);
    generalGame = new QRadioButton("General Game", this);
    layoutBluePlayer->addWidget(bluePlayer);
    layoutBluePlayer->addWidget(bluePlayerS);
    layoutBluePlayer->addWidget(bluePlayerO);
    holdBlueSO->setLayout(layoutBluePlayer);
    holdBlueSO->adjustSize();
    holdBlueSO->move((rectX/2)-(holdBlueSO->size().width()/2),
                     ((fixedHeightWindow/2)-(holdBlueSO->size().height()/2)));
    layoutRedPlayer->addWidget(redPlayer);
    layoutRedPlayer->addWidget(redPlayerS);
    layoutRedPlayer->addWidget(redPlayerO);
    holdRedSO->setLayout(layoutRedPlayer);
    holdRedSO->adjustSize();
    holdRedSO->move((((fixedWidthWindow+((fixedWidthWindow/2)+(cellSize/2)))/2)-(holdRedSO->size().width()/2)),
                    ((fixedHeightWindow/2)-(holdRedSO->size().height()/2)));
    layoutGameChoice->addWidget(title);
    layoutGameChoice->addWidget(simpleGame);
    layoutGameChoice->addWidget(generalGame);
    holdGameType->setLayout(layoutGameChoice);
    holdGameType->adjustSize();
    holdGameType->move(((fixedWidthWindow/2)-(holdGameType->size().width()/2)),
                       ((rectY/2)-(holdGameType->size().height()/2)));
}

//Creates SOS GUI Labels (Player Turn)
void sosGUI::createLabels()
{
    currentPlayerTurn = new QLabel("Blue Player goes first. Place a Letter to Start.", this);
    currentPlayerTurn->adjustSize();
    currentPlayerTurn->move((fixedWidthWindow/2)-(currentPlayerTurn->size().width()/2),
        (((rectY+cellSize)+fixedHeightWindow)/2)-(currentPlayerTurn->size().height()));
}

//Creates SOS GUI Input Widgets (Board Size)
void sosGUI::createInputWidgets() {
    holdBoardSize = new QWidget(this);
    layoutBoardSize = new QHBoxLayout;
    boardSizeLabel = new QLabel("Board Size ", this);
    boardSizeLabel->adjustSize();
    boardSizeSpinBox = new QSpinBox(this);
    boardSizeSpinBox->setMaximumSize(35, 20);
    boardSizeSpinBox->setAlignment(Qt::AlignCenter);
    boardSizeSpinBox->adjustSize();
    boardSizeSpinBox->setRange(3, 10);
    boardSizeSpinBox->setValue(boardSize);
    layoutBoardSize->addWidget(boardSizeLabel);
    layoutBoardSize->addWidget(boardSizeSpinBox);
    holdBoardSize->setLayout(layoutBoardSize);
    holdBoardSize->adjustSize();
    holdBoardSize->move((((fixedWidthWindow+((fixedWidthWindow/2)+(cellSize/2)))/2)-(holdBoardSize->size().width()/2)),
                           ((rectY/2)-(holdBoardSize->size().height()/2)));
    connect(boardSizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onBoardSizeSpinBoxValueChange(int)));
}

//Creates SOS GUI Push Buttons (New Game)
void sosGUI::pushButtons() {
    newGame = new QPushButton(this);
    newGame->setText("New Game");
    newGame->setStyleSheet("background-color: rgb(203, 203, 203);" "Font: 12pt");
    newGame->resize(125, 32);
    newGame->move(535, 325);
    connect(newGame, SIGNAL(clicked()), this, SLOT(onNewGameButtonClicked()));
}

//Signal for Board Size Spin Box, updates board Size from selected number, updates UI
void sosGUI::onBoardSizeSpinBoxValueChange(int num)
{
    boardSize = num;
    repaint();
}

//Signal for New Game Button, resests board back to new game state
void sosGUI::onNewGameButtonClicked() {
    game.restartGame();
    newGameStart();
    newGame->hide();
}

//Set SOS UI components to select and start a new game (Board Size, Game Mode, Players SO, Update)
void sosGUI::newGameStart() {
    boardSizeSpinBox->setValue(8);
    boardSizeSpinBox->setEnabled(true);
    simpleGame->setChecked(true);
    simpleGame->setEnabled(true);
    generalGame->setEnabled(true);
    bluePlayerS->setChecked(true);
    redPlayerS->setChecked(true);
    newGame->hide();
    updateStatus();
    repaint();
}

//Set SOS UI components for game start (Board size, Game Mode, Update)
void sosGUI::setGameStart()
{
    boardSize = game.getRows();
    boardSizeSpinBox->setValue(boardSize);
    boardSizeSpinBox->setEnabled(false);
    if (game.getGameMode() == game.GENERAL) {
        generalGame->setEnabled(true);
        generalGame->setChecked(true);
        simpleGame->setChecked(false);
        simpleGame->setEnabled(false);
    }
    else
    {
        simpleGame->setEnabled(true);
        simpleGame->setChecked(true);
        generalGame->setChecked(false);
        generalGame->setEnabled(false);
    }
    newGame->hide();
    updateStatus();
    repaint();
}

//Get Current Players Turn Letter thats checked
int sosGUI::getPlayerTurnLetter()
{
    int letter;
    if ((game.getTurn() == game.P1 && bluePlayerS->isChecked() == true)
           || (game.getTurn() == game.P2 && redPlayerS->isChecked() == true))
    {
        letter = game.LETTERS;
    }
    else
    {
        letter = game.LETTERO;
    }
    return letter;
}

//Mouse Pressed
/*Within parameters of the board location, if game not playing the get game mode and
board size and start new game. If playing or not, get x and y for col and row and letter
selected for for the current player turn and to check for valid move*/
void sosGUI::mousePressEvent(QMouseEvent *event)
{
    if ((event->pos().x() >= rectX && event-> pos().y() >= rectY)
            && (event->pos().x() < (rectX + cellSize) && event->pos().y() < (rectY + cellSize)))
    {
        if (game.getGameState() == game.NOTPLAYING)
        {
            if (generalGame->isChecked() == true) {
                game.newGame(boardSize, game.GENERAL);
            }
            else if (simpleGame->isChecked() == true)
            {
                game.newGame(boardSize, game.SIMPLE);
            }
            newSOSGame(game);
        }
        if (game.getGameState() == game.PLAYING || game.getGameState() == game.NOTPLAYING)
        {
            int rowSelected = (event->pos().y() - rectY) / (cellSize / game.getRows());
            int colSelected = (event->pos().x() - rectX) / (cellSize / game.getCols());
            int letterSelected = getPlayerTurnLetter();
            game.makeMove(rowSelected, colSelected, letterSelected);
            updateStatus();
        }
    }
    repaint();
}

//Update Text Status for Game (Move to start game, current players turn or winner)
void sosGUI::updateStatus()
{
    if (game.getGameState() == NOTPLAYING) {
        currentPlayerTurn->setText("Blue Player goes first. Place a Letter to Start.");
    }
    else if (game.getGameState() == PLAYING) {
        if (game.getTurn() == game.P2)
        {
            currentPlayerTurn->setText("Current Turn: Red Player");
        }
        else if (game.getTurn() == game.P1)
        {
            currentPlayerTurn->setText("Current Turn: Blue Player");
        }
    }
    else {
        newGame->show();
        if (game.getGameState() == DRAW) {
            currentPlayerTurn->setText("Draw");
        }
        else if (game.getGameState() == PLAYERONE_WON) {
            currentPlayerTurn->setText("Blue Player Wins");
        }
        else if (game.getGameState() == PLAYERTWO_WON) {
            currentPlayerTurn->setText("Red Player Wins");
        }
    }
    currentPlayerTurn->adjustSize();
    currentPlayerTurn->move((fixedWidthWindow/2)-(currentPlayerTurn->size().width()/2),
        (((rectY+cellSize)+fixedHeightWindow)/2)-(currentPlayerTurn->size().height()));
}

sosGUI::~sosGUI()
{
    //delete ui;
}
