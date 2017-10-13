#include "common_inputs.h"
#include "ui_common_inputs.h"
#include "scheduler_if.hpp"
#include "tablegui_if.h"
#include "tablegui_if_const.h"


Common_Inputs::Common_Inputs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Common_Inputs)
{
    ui->setupUi(this);
    ui->IGN_OFF->setChecked(true);
    connect( ui->IGN_OFF, SIGNAL( clicked() ),this, SLOT(onIgnOff() ) );
    connect( ui->IGN_ON, SIGNAL( clicked() ),this, SLOT(onIgnOn() ) );
   // connect( ui->IGN_ON, SIGNAL( clicked() ),this, SLOT(onIgnAcc() ) );
}

Common_Inputs::~Common_Inputs()
{
    delete ui;
}

void Common_Inputs::ShowForm_CommonInputs(void)
{
    this->show();
}

void Common_Inputs::emit_signal_IgnAcc(void)
{
    ui->IGN_OFF->setChecked(true);
    emit Ign_Status(0);
}

void Common_Inputs::onIgnOff(void)
{
    notifyIgnStatus(0);
}
void Common_Inputs::onIgnOn(void)
{
    notifyIgnStatus(2);
}
#if 0
void Common_Inputs::onIgnAcc(void)
{
    notifyIgnStatus(1);
}
#endif

void Common_Inputs::notifyIgnStatus(int IgnStatus)
{
    DataFromGui_t DataFromGui;

    ui->IGN_OFF->setChecked( (0 == IgnStatus) ? true : false);
    ui->IGN_ON->setChecked( (2 == IgnStatus) ? true : false);
    ui->IGN_ACC->setChecked( (1 == IgnStatus) ? true : false);
    printf("notifyIgnStatus %d\n" , IgnStatus);

    DataFromGui.intData = IgnStatus;
    DataFromGui.strData = "";
    DataFromGui.requestedInputMethod = "GUI";
    thisFeeder(DataFromGui, cStaticTables[0]);

    SomeSignal();
}
