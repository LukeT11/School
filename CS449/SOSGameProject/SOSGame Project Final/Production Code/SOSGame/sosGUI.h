#ifndef SOSGUI_H
#define SOSGUI_H

#include <QMainWindow>
#include <sosGame.h>
#include <sosGameAI.h>
#include <QtWidgets>
#include <string>

QT_BEGIN_NAMESPACE
//namespace Ui { class sosGUI; }
QT_END_NAMESPACE

class sosGUI : public QMainWindow, public sosGame
{
    Q_OBJECT

public:
    sosGUI(QWidget *parent = nullptr);
    void newSOSGame(sosGame newGame);
    ~sosGUI();

private slots:
    void onBoardSizeSpinBoxValueChange(int);
    void onNewGameButtonClicked();
    void onReplayGameButtonClicked();

private:
    //Ui::sosGUI *ui;
    sosGame game;
    sosGameAI gameAI;
    int const fixedWidthWindow = 700;
    int const fixedHeightWindow = 400;
    int const cellSize = 280;
    int const rectX = (fixedWidthWindow / 2) - (cellSize / 2);
    int const rectY = (fixedHeightWindow / 2) - (cellSize / 2);
    int const penSizeDrawBoard = 3;
    int boardSize = 8;
    enum PlayerType{HUMAN, COMPUTER};
    const QString outputSimpleGameModeText = "SIMPLE";
    const QString outputGeneralGameModeText = "GENERAL";
    const QString outputHumanPlayerTypeText = "HUMAN";
    const QString outputComputerPlayerTypeText = "COMPUTER";
    const QString outputBluePlayerText = "BLUEPLAYER";
    const QString outputRedPlayerText = "REDPLAYER";
    const QString outputLetterSText = "S";
    const QString outputLetterOText = "O";
    const QString outputDrawWinnerText = "DRAW";
    const QString outputPlayerOneWinnerText = "BLUEPLAYER";
    const QString outputPlayerTwoWinnerText = "REDPLAYER";
    vector<vector<int>> vecRecordGameData;
    QVBoxLayout *layoutBluePlayer;
    QVBoxLayout *layoutRedPlayer;
    QVBoxLayout *layoutBlueHumanComputer;
    QVBoxLayout *layoutRedHumanComputer;
    QHBoxLayout *layoutGameChoice;
    QHBoxLayout *layoutBoardSize;
    QWidget *holdBlueSO;
    QWidget *holdRedSO;
    QWidget *holdBlueHumanComputer;
    QWidget *holdRedHumanComputer;
    QWidget *holdGameType;
    QWidget *holdBoardSize;
    QRadioButton *bluePlayerS;
    QRadioButton *bluePlayerO;
    QRadioButton *bluePlayerHuman;
    QRadioButton *bluePlayerComputer;
    QRadioButton *redPlayerS;
    QRadioButton *redPlayerO;
    QRadioButton *redPlayerHuman;
    QRadioButton *redPlayerComputer;
    QRadioButton *simpleGame;
    QRadioButton *generalGame;
    QLabel *bluePlayer;
    QLabel *redPlayer;
    QLabel *currentPlayerTurn;
    QLabel *title;
    QLabel *boardSizeLabel;
    QSpinBox *boardSizeSpinBox;
    QPushButton *newGame;
    QPushButton *replayGame;
    QCheckBox *recordGame;
    void createSOSGameBoard();
    void setContentSOS();
    void radioButtons();
    void createInputWidgets();
    void createLabels();
    void pushButtons();
    void checkButtons();
    void updateStatus();
    void newGameStart();
    void setGameStart();
    void drawGameGrid();
    void drawGameBoard();
    int getPlayerTurnLetter();
    void recordGameBoardSizeMode(int inBoardSize, int inGameMode, int inPlayerTypeP1, int inPlayerTypeP2);
    void recordGameMove(int inPlayerTurn, int inRow, int inCol, int inLetter);
    void outputRecordGameDataTextFile(int inPlayerWinner);
    void replayGameFromDataTextFile();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
};
#endif //SOSGUI_h

