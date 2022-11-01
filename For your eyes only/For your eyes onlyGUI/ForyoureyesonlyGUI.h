#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ForyoureyesonlyGUI.h"

class ForyoureyesonlyGUI : public QMainWindow
{
	Q_OBJECT

public:
	ForyoureyesonlyGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::ForyoureyesonlyGUIClass ui;
};
