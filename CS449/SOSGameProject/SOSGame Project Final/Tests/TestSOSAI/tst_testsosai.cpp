#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here
#include "sosGame.cpp"
#include "sosGUI.cpp"
#include "sosGameAI.cpp"

class testSOSAI : public QObject
{
    Q_OBJECT

public:
    testSOSAI();
    ~testSOSAI();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAIMovesEmptyBoard();
    void testAICompleteSOSAvailableMoveOnBoardSimpleGame();
    void testAICompletesMoveThatDoesntSetupSOSForOpponentGeneralGame();

private:
    sosGame testGame;
    sosGUI testSOSGUI;
    sosGameAI testAI;
};

testSOSAI::testSOSAI()
{

}

testSOSAI::~testSOSAI()
{

}

void testSOSAI::initTestCase()
{

}

void testSOSAI::cleanupTestCase()
{

}

void testSOSAI::testAIMovesEmptyBoard()
{
    testGame.newGame(6, testGame.GENERAL);
    vector<int> computerMove = testAI.getAIMove(testGame);
    testGame.makeMove(computerMove.at(0), computerMove.at(1), computerMove.at(2));
    computerMove = testAI.getAIMove(testGame);
    testGame.makeMove(computerMove.at(0), computerMove.at(1), computerMove.at(2));
    testSOSGUI.newSOSGame(testGame);
    testSOSGUI.show();
    QTest::qSleep(2500);
}

void testSOSAI::testAICompleteSOSAvailableMoveOnBoardSimpleGame()
{
    testGame.newGame(6, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    vector<int> computerMove = testAI.getAIMove(testGame);
    testGame.makeMove(computerMove.at(0), computerMove.at(1), computerMove.at(2));
    QCOMPARE(testGame.getGameState(), testGame.PLAYERONE_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testSOSGUI.newSOSGame(testGame);
    testSOSGUI.show();
    QTest::qSleep(2500);
}

void testSOSAI::testAICompletesMoveThatDoesntSetupSOSForOpponentGeneralGame()
{
    testGame.newGame(5, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERO);
    testGame.makeMove(0, 1, testGame.LETTERO);
    testGame.makeMove(0, 2, testGame.LETTERS);
    testGame.makeMove(0, 4, testGame.LETTERO);
    testGame.makeMove(2, 0, testGame.LETTERO);
    testGame.makeMove(2, 3, testGame.LETTERS);
    vector<int> computerMove = testAI.getAIMove(testGame);
    testGame.makeMove(computerMove.at(0), computerMove.at(1), computerMove.at(2));
    QCOMPARE(testGame.getSOSConnectedNum(), 0);
    testSOSGUI.newSOSGame(testGame);
    testSOSGUI.show();
    QTest::qSleep(2500);
}

QTEST_MAIN(testSOSAI)

#include "tst_testsosai.moc"
