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
    void testMoveVacantCellSimpleGame();
    void testSimpleGameNonVacantCell();
    void testInvalidRowSimpleGame();
    void testInvalidColumnSimpleGame();
    void testSimpleGameSOSConnected();
    void testSimpleGameOverP1Wins();
    void testSimpleGameOverP2Wins();
    void testSimpleGameOverDraw();
    void testSimpleGameRestartGame();

private:
    sosGame testGame;
    sosGUI testGUI;
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
    testGUI.newSOSGame(testGame);
    testGUI.show();
    QTest::qSleep(2500);
}

void TestSOSSimpleGame::testInvalidRowSimpleGame()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void TestSOSSimpleGame::testInvalidColumnSimpleGame()
{
    QCOMPARE(testGame.getCell(0, 10), NULL);
}

void TestSOSSimpleGame::testMoveVacantCellSimpleGame()
{
    testGame.newGame(10, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSSimpleGame::testSimpleGameNonVacantCell()
{
    testGame.newGame(5, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    QCOMPARE(testGame.getCell(0, 0), testGame.LETTERS);
    QCOMPARE(testGame.getTurn(), testGame.P2);
    testGame.makeMove(0, 0, testGame.LETTERO);
    QCOMPARE(testGame.getCell(0, 0), testGame.LETTERS);
    QCOMPARE(testGame.getTurn(), testGame.P2);
}

void TestSOSSimpleGame::testSimpleGameSOSConnected()
{
    testGame.newGame(3, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    QCOMPARE(testGame.getSOSConnectedNum(), 0);
    testGame.makeMove(2, 2, testGame.LETTERS);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSSimpleGame::testSimpleGameOverP1Wins()
{
    testGame.newGame(3, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 2, testGame.LETTERS);
    QCOMPARE(testGame.getGameState(), testGame.PLAYERONE_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSSimpleGame::testSimpleGameOverP2Wins()
{
    testGame.newGame(3, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 1, testGame.LETTERS);
    testGame.makeMove(2, 2, testGame.LETTERS);
    QCOMPARE(testGame.getGameState(), testGame.PLAYERTWO_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSSimpleGame::testSimpleGameOverDraw()
{
    testGame.newGame(3, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(0, 1, testGame.LETTERS);
    testGame.makeMove(0, 2, testGame.LETTERS);
    testGame.makeMove(1, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERS);
    testGame.makeMove(1, 2, testGame.LETTERS);
    testGame.makeMove(2, 0, testGame.LETTERS);
    testGame.makeMove(2, 1, testGame.LETTERS);
    testGame.makeMove(2, 2, testGame.LETTERS);
    QCOMPARE(testGame.getGameState(), testGame.DRAW);
    QCOMPARE(testGame.getSOSConnectedNum(), 0);
    testGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSSimpleGame::testSimpleGameRestartGame()
{
    testGame.newGame(3, testGame.SIMPLE);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 2, testGame.LETTERS);
    QCOMPARE(testGame.getGameState(), testGame.PLAYERONE_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    QCOMPARE(testGame.getGameMode(), testGame.SIMPLE);
    testGame.restartGame();
    QCOMPARE(testGame.getGameMode(), testGame.NONE);
    QCOMPARE(testGame.getGameState(), testGame.NOTPLAYING);
    QCOMPARE(testGame.getSOSConnectedNum(), 0);
    for (int row = 0; row < testGame.getRows(); row++) {
        for (int col = 0; col < testGame.getCols(); col++) {
            QCOMPARE(testGame.getCell(row, col), testGame.EMPTY);
        }
    }
    testGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

QTEST_MAIN(TestSOSSimpleGame)

#include "tst_testsossimplegame.moc"
