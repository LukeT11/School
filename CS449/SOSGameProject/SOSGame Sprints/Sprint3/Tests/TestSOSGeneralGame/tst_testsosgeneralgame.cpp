#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here
#include "sosGame.cpp"
#include "sosGUI.cpp"

class TestSOSGeneralGame : public QObject
{
    Q_OBJECT

public:
    TestSOSGeneralGame();
    ~TestSOSGeneralGame();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testEmptyGeneralGame();
    void testMoveVacantCellGeneralGame();
    void testGeneralGameNonVacantCell();
    void testInvalidRowGeneralGame();
    void testInvalidColumnGeneralGame();
    void testGeneralGameSOSConnected();
    void testGeneralGameOverP1Wins();
    void testGeneralGameOverP2Wins();
    void testGeneralGameOverDrawNoSOS();
    void testGeneralGameOverDrawWithSOS();
    void testGeneralGameRestartGame();

private:
    sosGame testGame;
    sosGUI testSOSGUI;
};

TestSOSGeneralGame::TestSOSGeneralGame()
{

}

TestSOSGeneralGame::~TestSOSGeneralGame()
{

}

void TestSOSGeneralGame::initTestCase()
{

}

void TestSOSGeneralGame::cleanupTestCase()
{

}

void TestSOSGeneralGame::testEmptyGeneralGame()
{
    testGame.newGame(10, testGame.GENERAL);
    QCOMPARE(testGame.getGameMode(), testGame.GENERAL);
    for (int row = 0; row < testGame.getRows(); row++) {
        for (int col = 0; col < testGame.getCols(); col++) {
            QCOMPARE(testGame.getCell(row, col), testGame.EMPTY);
        }
    }
    testSOSGUI.newSOSGame(testGame);
    testSOSGUI.show();
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testInvalidRowGeneralGame()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void TestSOSGeneralGame::testInvalidColumnGeneralGame()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void TestSOSGeneralGame::testMoveVacantCellGeneralGame()
{
    testGame.newGame(10, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testSOSGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testGeneralGameNonVacantCell()
{
    testGame.newGame(5, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    QCOMPARE(testGame.getCell(0, 0), testGame.LETTERS);
    QCOMPARE(testGame.getTurn(), testGame.P2);
    testGame.makeMove(0, 0, testGame.LETTERO);
    QCOMPARE(testGame.getCell(0, 0), testGame.LETTERS);
    QCOMPARE(testGame.getTurn(), testGame.P2);
}

void TestSOSGeneralGame::testGeneralGameSOSConnected()
{
    testGame.newGame(3, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    QCOMPARE(testGame.getSOSConnectedNum(), 0);
    testGame.makeMove(2, 2, testGame.LETTERS);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testSOSGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testGeneralGameOverP1Wins()
{
    testGame.newGame(3, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 2, testGame.LETTERS);
    testGame.makeMove(0, 1, testGame.LETTERO);
    testGame.makeMove(0, 2, testGame.LETTERO);
    testGame.makeMove(1, 0, testGame.LETTERO);
    testGame.makeMove(2, 1, testGame.LETTERO);
    testGame.makeMove(1, 2, testGame.LETTERO);
    testGame.makeMove(2, 0, testGame.LETTERO);
    QCOMPARE(testGame.getGameState(), testGame.PLAYERONE_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testSOSGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testGeneralGameOverP2Wins()
{
    testGame.newGame(3, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 1, testGame.LETTERO);
    testGame.makeMove(2, 2, testGame.LETTERS);
    testGame.makeMove(0, 1, testGame.LETTERS);
    testGame.makeMove(0, 2, testGame.LETTERS);
    testGame.makeMove(2, 0, testGame.LETTERO);
    testGame.makeMove(1, 0, testGame.LETTERO);
    testGame.makeMove(1, 2, testGame.LETTERS);
    QCOMPARE(testGame.getGameState(), testGame.PLAYERTWO_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    testSOSGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testGeneralGameOverDrawNoSOS()
{
    testGame.newGame(3, testGame.GENERAL);
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
    testSOSGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testGeneralGameOverDrawWithSOS()
{
    testGame.newGame(3, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 2, testGame.LETTERS);
    testGame.makeMove(0, 1, testGame.LETTERO);
    testGame.makeMove(0, 2, testGame.LETTERO);
    testGame.makeMove(2, 0, testGame.LETTERS);
    testGame.makeMove(1, 0, testGame.LETTERO);
    testGame.makeMove(1, 2, testGame.LETTERS);
    testGame.makeMove(2, 1, testGame.LETTERS);
    QCOMPARE(testGame.getGameState(), testGame.DRAW);
    QCOMPARE(testGame.getSOSConnectedNum(), 2);
    testSOSGUI.newSOSGame(testGame);
    QTest::qSleep(2500);
}

void TestSOSGeneralGame::testGeneralGameRestartGame()
{
    testGame.newGame(3, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);
    testGame.makeMove(2, 2, testGame.LETTERS);
    testGame.makeMove(0, 1, testGame.LETTERO);
    testGame.makeMove(0, 2, testGame.LETTERO);
    testGame.makeMove(1, 0, testGame.LETTERO);
    testGame.makeMove(2, 1, testGame.LETTERO);
    testGame.makeMove(1, 2, testGame.LETTERO);
    testGame.makeMove(2, 0, testGame.LETTERO);
    QCOMPARE(testGame.getGameState(), testGame.PLAYERONE_WON);
    QCOMPARE(testGame.getSOSConnectedNum(), 1);
    QCOMPARE(testGame.getGameMode(), testGame.GENERAL);
    testGame.restartGame();
    QCOMPARE(testGame.getGameMode(), testGame.NONE);
    QCOMPARE(testGame.getGameState(), testGame.NOTPLAYING);
    QCOMPARE(testGame.getSOSConnectedNum(), 0);
    for (int row = 0; row < testGame.getRows(); row++) {
        for (int col = 0; col < testGame.getCols(); col++) {
            QCOMPARE(testGame.getCell(row, col), testGame.EMPTY);
        }
    }
}

QTEST_MAIN(TestSOSGeneralGame)

#include "tst_testsosgeneralgame.moc"
