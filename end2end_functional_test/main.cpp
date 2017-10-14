#include <QApplication>
#include <QtWidgets>
#include "common_inputs.h"
#include "BlinkManager.h"
#include "widget.h"
#include "digitalclock.h"
#include <QTextBrowser>
#include <QHBoxLayout>
//#include "Qt_Test.h"

#include "Project_Types_MSVC.h"
#include "scheduler_if.hpp"

/* Exported If*/
uint32 Get_OsTick(void)
{
    uint32 i = 1;
   // return CounterMS;
    return i;
}

 int main(int argc, char *argv[])
 {
  QApplication a(argc, argv);
  Widget w, window;
  BlinkManager b;
  Common_Inputs CommonInputs;
  //Scheduler Sched;

  QTextStream cout(stdout);
  QHBoxLayout layout(&window);
     QTextEdit edit;
     QTextBrowser browser;
     layout.addWidget(&edit);
Scheduler();
  w.show();
  //QObject::connect( &w, SIGNAL( foo() ), &b, SLOT(ShowForm_BlinkManager(void) )  );
  QObject::connect( &w, SIGNAL( foo() ), &CommonInputs, SLOT(ShowForm_CommonInputs(void) )  );


  return a.exec();
 }

