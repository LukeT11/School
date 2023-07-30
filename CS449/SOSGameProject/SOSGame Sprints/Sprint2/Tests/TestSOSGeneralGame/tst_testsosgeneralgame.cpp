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
    void testMoveGeneralGame();
    void testInvalidRowGeneralGame();
    void testInvalidColumnGeneralGame();

private:
    sosGame testGame;
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
}

void TestSOSGeneralGame::testInvalidRowGeneralGame()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void TestSOSGeneralGame::testInvalidColumnGeneralGame()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void TestSOSGeneralGame::testMoveGeneralGame()
{
    testGame.newGame(10, testGame.GENERAL);
    testGame.makeMove(0, 0, testGame.LETTERS);
    testGame.makeMove(1, 1, testGame.LETTERO);

    QCOMPARE(testGame.getGameMode(), testGame.GENERAL);
    QCOMPARE(testGame.getCell(0, 0), testGame.LETTERS);
    QCOMPARE(testGame.getCell(1, 1), testGame.LETTERO);

    /*sosGUI testGUIEmpty;
    testGUIEmpty.newSOSGame(testGame);
    testGUIEmpty.show();
    QTest::qSleep(5000);*/
}

QTEST_MAIN(TestSOSGeneralGame)

#include "tst_testsosgeneralgame.moc"
