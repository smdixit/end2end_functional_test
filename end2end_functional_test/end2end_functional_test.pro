#-------------------------------------------------
#
# Project created by QtCreator 2017-10-14T17:09:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = end2end_functional_test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += C:\GIT\end2end_functional_test\end2end_functional_test\sqlite\Rte \
               C:\GIT\end2end_functional_test\end2end_functional_test\sqlite\Services \
               C:\GIT\end2end_functional_test\end2end_functional_test\sqlite \
               C:\GIT\end2end_functional_test\end2end_functional_test

QMAKE_CXXFLAGS_WARN_OFF -= -fno-permissive

HEADERS  += BlinkManager.h widget.h digitalclock.h \
    sqlite/ComponentFactory.hpp \
    sqlite/Depop_BlinkManager.hpp \
    sqlite/DepopBuses.hpp \
    sqlite/DumpFromProgram.hpp \
    sqlite/Tables.hpp \
    sqlite/Generic_DB_Connector.hpp \
    sqlite/Pop_BlinkerManager.hpp \
    sqlite/PopulateItems.hpp \
    sqlite/Rte/Rte_BlinkerManager.h \
    sqlite/Services/Adc.h \
    sqlite/Services/BlinkManager_Mock.h \
    sqlite/Services/Digital_IO.h \
    sqlite/Project_Types_MSVC.h \
    sqlite/sqlite3.h \
    sqlite/sqlite3ext.h \
    sqlite/Timer.h \
    Scheduler.hpp \
    scheduler_if.hpp \
    common_inputs.h \
    tablegui_if.h \
    tablegui_if_const.h



SOURCES += BlinkManager.cpp main.cpp digitalclock.cpp widget.cpp \
    common_inputs.cpp \
    sqlite/Blinker_CplxDrv.cpp \
    sqlite/Blinker_CplxDrv_Mock.cpp \
    sqlite/BlinkerControl_Left.cpp \
    sqlite/BlinkerControl_Right.cpp \
    sqlite/main_sched.cpp \
    sqlite/Rte.cpp \
    sqlite/Rte_Emulation.cpp \
    sqlite/stdafx.cpp \
    sqlite/Timer.cpp \
    sqlite/Rte/Rte_BlinkerManager.cpp \
    sqlite/Services/BlinkManager_Mock.cpp \
    sqlite/sqlite3.c \
    sqlite/BlinkManager_sq.cpp \
    Scheduler.cpp



FORMS    += widget.ui \
    BlinkManager.ui \
    common_inputs.ui

