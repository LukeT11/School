#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here
#include "sosGame.cpp"
#include "sosGUI.cpp"

class TestSOSSimpleGame : public QObject
{
    Q_OBJECT

public:
    TestSOSSimpleGame();
    ~TestSOSSimpleGame();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testEmptySimpleGame();
    void testMoveSimpleGame();
    void testInvalidRowSimpleGame();
    void testInvalidColumnSimpleGame();

private:
    sosGame testGame;

};

TestSOSSimpleGame::TestSOSSimpleGame()
{

}

TestSOSSimpleGame::~TestSOSSimpleGame()
{

}

void TestSOSSimpleGame::initTestCase()
{

}

void TestSOSSimpleGame::cleanupTestCase()
{

}

void TestSOSSimpleGame::testEmptySimpleGame()
{
    testGame.newGame(10, testGame.SIMPLE);
    QCOMPARE(testGame.getGameMode(), testGame.SIMPLE);
    for (int row = 0; row < testGame.getRows(); row++) {
        for (int col = 0; col < testGame.getCols(); col++) {
            QCOMPARE(testGame.getCell(row, col), testGame.EMPTY);
        }
    }
}

void TestSOSSimpleGame::testInvalidRowSimpleGame()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void TestSOSSimpleGame::testInvalidColumnSimpleGame()
{
    QCOMPARE(testGame.getCell(0, 10), NULL);
}

void TestSOSSimpleGame::testMoveSimpleGame()
{
    testGame.newGame(10, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);

    QCOMPARE(testGame.getGameMode(), testGame.SIMPLE);
    QCOMPARE(testGame.getCell(0, 0), testGame.LETTERS);
    QCOMPARE(testGame.getCell(1, 1), testGame.LETTERO);

    /*sosGUI testGUIEmpty;
    testGUIEmpty.newSOSGame(testGame);
    testGUIEmpty.show();
    QTest::qSleep(5000);*/
}

QTEST_MAIN(TestSOSSimpleGame)

#include "tst_testsossimplegame.moc"
