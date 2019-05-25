#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab9.h"

class lab9 : public QMainWindow
{
	Q_OBJECT

public:
	lab9(QWidget *parent = Q_NULLPTR);

private:
	Ui::lab9Class ui;
};
