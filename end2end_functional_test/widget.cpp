#include "widget.h"
 #include "ui_widget.h"

#include "Scheduler_if.hpp"

 Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
 {
  ui->setupUi(this);

  m_LcdPanel = (ui->MS_Elapsed);
  m_button_MS = ui->MS;
  m_RunForMs = ui->RunFor;
  connect(m_button_MS, SIGNAL (released()), this, SLOT (handleButton()));
  QTime TimeZero(0, 0, 0, 0);
   n = TimeZero;
   RunForMs = 0;
   connect(m_RunForMs, SIGNAL(textChanged(QString)),this, SLOT(RunFor_LineEditText(QString)));

   //Test
   test = ui->test;
   connect(test, SIGNAL(clicked()),this, SLOT(emit_signal_foo()));

 }

 Widget::~Widget()
 {
  delete ui;
 }

 void Widget::emit_signal_foo(void)
 {
     emit foo();
 }

 void func_slot(int ms)
 {
    SchedulerRun(ms);
 }

 void Widget::showTime(QTime m_n_till)
 {
     QLCDNumber *DispLcd = m_LcdPanel;
     QTime time = n;
     QTime TimeZero(0, 0, 0, 0);
     int TimeElapsed = m_n_till.msecsTo(TimeZero);
     TimeElapsed = TimeElapsed * -1;

     QString text = time.toString("mm:ss:zzz");

     DispLcd->setFixedSize(100, 30);
     DispLcd->setDigitCount(12);
    func_slot(TimeElapsed);
     DispLcd->display(TimeElapsed);

}

 void Widget::handleButton()
 {
    QTime n_till = n; //.addMSecs(RunForMs)

     for(n_till = n.addMSecs(1) ; n_till <= n.addMSecs(RunForMs); n_till = n_till.addMSecs(1) ) {
        showTime(n_till);
     }
    n = n_till.addMSecs(-1); //n_til will be incremented to n.addMSecs(RunForMs) + 1, when loop breaks.
     RunForMs = 1;
     m_RunForMs->setText(QString::number(RunForMs));
 }

 void Widget::RunFor_LineEditText(QString RunFor_str)
 {
    RunForMs = RunFor_str.toInt(NULL, 10);
 }
