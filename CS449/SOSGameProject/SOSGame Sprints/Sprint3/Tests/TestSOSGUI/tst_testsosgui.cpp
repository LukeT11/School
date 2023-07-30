#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here
//#include "sosGUI.h"
//#include "sosGame.h"
#include "sosGame.cpp"
#include "sosGUI.cpp"

class TestSOSGUI : public QObject
{
    Q_OBJECT

public:
    TestSOSGUI();
    ~TestSOSGUI();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testGUI();
    void testNewGameBoardGUI();
    void testBoardSizeGUI();
    void testBoardSizeGameModeGUI();
    void testBoardMoveGUI();
    void testSOSConnected();
    void testSOSSimpleGameOver();
    void testSOSSetUpNewGame();

private:
    sosGame testSOSGame;
    sosGUI testSOSGUI;
};

TestSOSGUI::TestSOSGUI()
{

}

TestSOSGUI::~TestSOSGUI()
{

}

void TestSOSGUI::initTestCase()
{

}

void TestSOSGUI::cleanupTestCase()
{

}

void TestSOSGUI::testGUI()
{
    testSOSGUI.show();
    QTest::qSleep(2500);
}

void TestSOSGUI::testBoardSizeGUI()
{
    sosGame newGame;
    newGame.newGame(6, newGame.SIMPLE);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
}

void TestSOSGUI::testBoardSizeGameModeGUI()
{
    sosGame newGame;
    newGame.newGame(6, newGame.GENERAL);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
}

void TestSOSGUI::testNewGameBoardGUI()
{
    sosGame newGame;
    newGame.newGame(5, newGame.GENERAL);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
}

void TestSOSGUI::testBoardMoveGUI()
{
    sosGame newGame;
    newGame.newGame(5, newGame.GENERAL);
    newGame.makeMove(0, 0, newGame.LETTERS);
    newGame.makeMove(1, 1, newGame.LETTERO);
    testSOSGUI.newSOSGame(newGame);;
    QTest::qSleep(2500);
}

void TestSOSGUI::testSOSConnected()
{
    sosGame newGame;
    newGame.newGame(5, newGame.GENERAL);
    newGame.makeMove(0, 0, newGame.LETTERS);
    newGame.makeMove(1, 1, newGame.LETTERO);
    newGame.makeMove(2, 2, newGame.LETTERS);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
}

void TestSOSGUI::testSOSSimpleGameOver()
{
    sosGame newGame;
    newGame.newGame(3, newGame.SIMPLE);
    newGame.makeMove(0, 0, newGame.LETTERS);
    newGame.makeMove(1, 1, newGame.LETTERO);
    newGame.makeMove(2, 2, newGame.LETTERS);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
}

void TestSOSGUI::testSOSSetUpNewGame()
{
    sosGame newGame;
    newGame.newGame(3, newGame.SIMPLE);
    newGame.makeMove(0, 0, newGame.LETTERS);
    newGame.makeMove(1, 1, newGame.LETTERO);
    newGame.makeMove(2, 2, newGame.LETTERS);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
    newGame.newGame(3, newGame.SIMPLE);
    testSOSGUI.newSOSGame(newGame);
    QTest::qSleep(2500);
}

QTEST_MAIN(TestSOSGUI)

#include "tst_testsosgui.moc"
