#ifndef SOSGUI_H
#define SOSGUI_H

#include <QMainWindow>
#include <sosGame.h>
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

private:
    //Ui::sosGUI *ui;
    sosGame game;

    int const fixedWidthWindow = 700;
    int const fixedHeightWindow = 400;
    int const cellSize = 280;
    int const rectX = (fixedWidthWindow / 2) - (cellSize / 2); //200
    int const rectY = (fixedHeightWindow / 2) - (cellSize / 2);  //75
    int const penSizeDrawBoard = 3;
    int boardSize = 8;

    QVBoxLayout *layoutBluePlayer;
    QVBoxLayout *layoutRedPlayer;
    QHBoxLayout *layoutGameChoice;
    QHBoxLayout *layoutBoardSize;

    QWidget *holdBlueSO;
    QWidget *holdRedSO;
    QWidget *holdGameType;
    QWidget *holdBoardSize;

    QRadioButton *bluePlayerS;
    QRadioButton *bluePlayerO;
    QRadioButton *redPlayerS;
    QRadioButton *redPlayerO;
    QRadioButton *simpleGame;
    QRadioButton *generalGame;

    QLabel *bluePlayer;
    QLabel *redPlayer;
    QLabel *currentPlayerTurn;
    QLabel *title;
    QLabel *boardSizeLabel;

    QSpinBox *boardSizeSpinBox;

    void createSOSGameBoard();
    void setContentSOS();
    void radioButtons();
    void createInputWidgets();
    void createLabels();
    void updateStatus();
    void setGameStart();
    void drawGameGrid();
    void drawGameBoard();
    int getPlayerTurnLetter();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
};
#endif //SOSGUI_h
