#ifndef UI_BLINK_MGR
 #define UI_BLINK_MGR

 #include <QWidget>
#include <QLCDNumber>


 namespace Ui {
  class BlinkManager;
 }

 class BlinkManager : public QWidget
 {
  Q_OBJECT

 public:
explicit BlinkManager(QWidget *parent = 0);

  ~BlinkManager();
#if 0
 void setName(const QString &name);
  QString name() const;
#endif
 public slots:
void ShowForm_BlinkManager(void);

 private:
  Ui::BlinkManager *uiBlinkManager;
  //BlinkManager *uiBlinkManager;
 };

 #endif // UI_BLINK_MGR
