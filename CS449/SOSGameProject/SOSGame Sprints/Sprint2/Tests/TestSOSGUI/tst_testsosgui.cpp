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


private:
    sosGame sosTestGame; 
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
    //sosGUI testGUI;
    //testGUI.show();
    //QTest::qSleep(2500);
    //testGUI.show();
    //QTest::qSleep(2500);
    //testGUI.close();
}

void TestSOSGUI::testBoardSizeGUI()
{
    sosGame newGame;
    newGame.setBoardSize(6);
    QCOMPARE(newGame.getRows(), 6);

    /*sosGUI testGUIEmpty;
    testGUIEmpty.newSOSGame(newGame);
    testGUIEmpty.show();
    QTest::qSleep(5000);*/
}

void TestSOSGUI::testBoardSizeGameModeGUI()
{
    sosGame newGame;
    newGame.setBoardSize(6);
    newGame.setBoardMode(newGame.GENERAL);
    QCOMPARE(newGame.getRows(), 6);
    QCOMPARE(newGame.getGameMode(), newGame.GENERAL);

    /*sosGUI testGUIEmpty;
    testGUIEmpty.newSOSGame(newGame);
    testGUIEmpty.show();
    QTest::qSleep(5000);*/
}

void TestSOSGUI::testNewGameBoardGUI()
{
    sosGame newGame;
    newGame.newGame(5, newGame.GENERAL);
    QCOMPARE(newGame.getRows(), 5);
    QCOMPARE(newGame.getGameMode(), newGame.GENERAL);
    for (int row = 0; row < newGame.getRows(); row++) {
        for (int col = 0; col < newGame.getCols(); col++) {
            QCOMPARE(newGame.getCell(row, col), newGame.EMPTY);
        }
    }

    /*sosGUI testGUIEmpty;
    testGUIEmpty.newSOSGame(newGame);
    testGUIEmpty.show();
    QTest::qSleep(5000);*/
}

void TestSOSGUI::testBoardMoveGUI()
{
    sosGame newGame;
    newGame.newGame(5, newGame.GENERAL);
    newGame.makeMove(0, 0, newGame.LETTERS);
    newGame.makeMove(1, 1, newGame.LETTERO);
    QCOMPARE(newGame.getGameMode(), newGame.GENERAL);
    QCOMPARE(newGame.getCell(0, 0), newGame.LETTERS);
    QCOMPARE(newGame.getCell(1, 1), newGame.LETTERO);

    /*sosGUI testGUIEmpty;
    testGUIEmpty.newSOSGame(newGame);
    testGUIEmpty.show();
    QTest::qSleep(5000);*/
}


QTEST_MAIN(TestSOSGUI)

#include "tst_testsosgui.moc"
