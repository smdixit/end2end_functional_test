#ifndef COMMON_INPUTS_H
#define COMMON_INPUTS_H

#include <QWidget>

namespace Ui {
class Common_Inputs;
}

class Common_Inputs : public QWidget
{
    Q_OBJECT

public:
    explicit Common_Inputs(QWidget *parent = 0);
    ~Common_Inputs();
    void notifyIgnStatus(int IgnStatus);

signals:
      void Ign_Status(int IgnStatus);
public slots:
    void emit_signal_IgnAcc(void);
    void ShowForm_CommonInputs(void);
    void onIgnOff(void);
    void onIgnOn(void);

private:
    Ui::Common_Inputs *ui;
};

#endif // COMMON_INPUTS_H
