#include "TurtleHelper.h"
#include "DisWidget.h"

TurtleHelper::TurtleHelper(DisWidget *disWidget, QObject *parent) : QObject(parent){
	if(disWidget == nullptr){
		qDebug() << "diswidget is null.";
		return;
	}
	this->disWidget = disWidget;
	this->vaild = true;
}


