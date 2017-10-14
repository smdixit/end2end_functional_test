#include "BlinkManager.h"
#include "ui_BlinkManager.h"


 BlinkManager::BlinkManager(QWidget *parent) :
  QWidget(parent),
  uiBlinkManager(new Ui::BlinkManager)
 {
  uiBlinkManager->setupUi(this);
 }

 BlinkManager::~BlinkManager()
 {
  delete uiBlinkManager;
 }

  void BlinkManager::ShowForm_BlinkManager(void)
  {
    this->show();
  }
