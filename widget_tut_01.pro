#-------------------------------------------------
#
# Project created by QtCreator 2017-04-02T22:09:01
#
#-------------------------------------------------

DEFINES += "TOP_DIR=C:\\apps\\RTC602\\13.10x"
#TOP_DIR += \"C:\apps\RTC602\13.10x\"

QT       += core gui widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widget_tut_01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:\apps\RTC602\13.10x\harness\sqlite_trial\Rte \
               C:\apps\RTC602\13.10x\harness\sqlite_trial\Services \
               C:\apps\RTC602\13.10x\harness\sqlite_trial \
               C:\apps\RTC602\13.10x\harness

QMAKE_CXXFLAGS_WARN_OFF -= -fno-permissive

HEADERS  += BlinkManager.h widget.h digitalclock.h \
    sqlite_trial/ComponentFactory.hpp \
    sqlite_trial/Depop_BlinkManager.hpp \
    sqlite_trial/DepopBuses.hpp \
    sqlite_trial/DumpFromProgram.hpp \
    sqlite_trial/Tables.hpp \
    sqlite_trial/Generic_DB_Connector.hpp \
    sqlite_trial/Pop_BlinkerManager.hpp \
    sqlite_trial/PopulateItems.hpp \
    sqlite_trial/Rte/Rte_BlinkerManager.h \
    sqlite_trial/Services/Adc.h \
    sqlite_trial/Services/BlinkManager_Mock.h \
    sqlite_trial/Services/Digital_IO.h \
    sqlite_trial/Project_Types_MSVC.h \
    sqlite_trial/sqlite3.h \
    sqlite_trial/sqlite3ext.h \
    sqlite_trial/Timer.h \
    Scheduler.hpp \
    scheduler_if.hpp \
    common_inputs.h \
    tablegui_if.h \
    tablegui_if_const.h



SOURCES += BlinkManager.cpp main.cpp digitalclock.cpp widget.cpp \
    common_inputs.cpp \
    sqlite_trial/Blinker_CplxDrv.cpp \
    sqlite_trial/Blinker_CplxDrv_Mock.cpp \
    sqlite_trial/BlinkerControl_Left.cpp \
    sqlite_trial/BlinkerControl_Right.cpp \
    sqlite_trial/main_sched.cpp \
    sqlite_trial/Rte.cpp \
    sqlite_trial/Rte_Emulation.cpp \
    sqlite_trial/stdafx.cpp \
    sqlite_trial/Timer.cpp \
    sqlite_trial/Rte/Rte_BlinkerManager.cpp \
    sqlite_trial/Services/BlinkManager_Mock.cpp \
    sqlite_trial/sqlite3.c \
    sqlite_trial/BlinkManager_sq.cpp \
    Scheduler.cpp



FORMS    += widget.ui \
    BlinkManager.ui \
    common_inputs.ui
