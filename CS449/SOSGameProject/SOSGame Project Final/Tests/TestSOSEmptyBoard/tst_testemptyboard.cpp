#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here
#include "sosGame.cpp"
#include "sosGUI.cpp"
#include "sosGameAI.cpp"

class testEmptyBoard : public QObject
{
    Q_OBJECT

public:
    testEmptyBoard();
    ~testEmptyBoard();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testNewBoard();
    void testInvalidRow();
    void testInvalidColumn();

private:
    sosGame testGame;
};

testEmptyBoard::testEmptyBoard()
{

}

testEmptyBoard::~testEmptyBoard()
{

}

void testEmptyBoard::initTestCase()
{

}

void testEmptyBoard::cleanupTestCase()
{

}

void testEmptyBoard::testNewBoard()
{
    testGame.newGame(10, testGame.SIMPLE);
    for (int row = 0; row < testGame.getRows(); row++) {
        for (int col = 0; col < testGame.getCols(); col++) {
            QCOMPARE(testGame.getCell(row, col), testGame.EMPTY);
        }
    }
}

void testEmptyBoard::testInvalidRow()
{
    QCOMPARE(testGame.getCell(10, 0), NULL);
}

void testEmptyBoard::testInvalidColumn()
{
    QCOMPARE(testGame.getCell(0, 10), NULL);
}

QTEST_MAIN(testEmptyBoard)

#include "tst_testemptyboard.moc"
