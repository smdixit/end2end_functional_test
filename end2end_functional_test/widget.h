#ifndef WIDGET_H
 #define WIDGET_H

 #include <QWidget>
#include <QLCDNumber>
#include <QTextBrowser>
#include <QTime>
#include <QPushButton>
#include <QLineEdit>

 namespace Ui {
  class Widget;
 }

 class Widget : public QWidget
 {
  Q_OBJECT

 public:
     QLCDNumber *m_LcdPanel;
     QPushButton *m_button_MS;
     QTime n;
     QLineEdit *m_RunForMs;
     int RunForMs;

     QPushButton *test;
    friend void func_slot(void);
  explicit Widget(QWidget *parent = 0);
  ~Widget();
#if 0
 void setName(const QString &name);
  QString name() const;
#endif
 signals:
  void foo(void);

 public slots:
     void showTime(QTime m_n_till);
     void handleButton();
     void RunFor_LineEditText(QString RunFor_str);
     void emit_signal_foo(void);

 private:
  Ui::Widget *ui;
 };

 #endif // WIDGET_H
