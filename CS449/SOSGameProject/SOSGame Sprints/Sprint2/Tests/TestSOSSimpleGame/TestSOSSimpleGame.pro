QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testsossimplegame.cpp

HEADERS += \
    ..\..\SOSGame\sosGUI.h \
    ..\..\SOSGame\sosGame.h

INCLUDEPATH += ..\..\SOSGame