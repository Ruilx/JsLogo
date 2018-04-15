#ifndef TURTLEHELPER_H
#define TURTLEHELPER_H

#include <QObject>
#include "DisWidget.h"

class DisWidget;
class TurtleHelper : public QObject
{
	Q_OBJECT

	bool vaild = false;

	DisWidget *disWidget;

	void checkDisWidget(){
		Q_ASSERT_X(this->disWidget, "DisWidget", "Diswidget passed nullptr.");
	}
public:
	explicit TurtleHelper(DisWidget *diswidget, QObject *parent = nullptr);

	bool setDisWidget(DisWidget *disWidget){
		if(disWidget == nullptr){
			qDebug() << __FUNCTION__ << "diswidget is nullptr";
			return false;
		}
		this->disWidget = disWidget;
	}

	Q_INVOKABLE bool forward(qreal length){
		this->checkDisWidget();
		return this->disWidget->doForward(length);
	}

	Q_INVOKABLE bool fd(qreal length){
		return this->forward(length);
	}

	Q_INVOKABLE bool backward(qreal length){
		this->checkDisWidget();
		return this->disWidget->doBackward(length);
	}

	Q_INVOKABLE bool bk(qreal length){
		return this->backward(length);
	}

	Q_INVOKABLE bool clear(){
		this->checkDisWidget();
		return this->disWidget->doClear();
	}

	Q_INVOKABLE bool cs(){
		return this->clear();
	}

	Q_INVOKABLE bool hideTurtle(){
		this->checkDisWidget();
		return this->disWidget->doHideTurtle();
	}

	Q_INVOKABLE bool ht(){
		return this->hideTurtle();
	}

	Q_INVOKABLE bool showTurtle(){
		this->checkDisWidget();
		return this->disWidget->doShowTurtle();
	}

	Q_INVOKABLE bool st(){
		return this->showTurtle();
	}

	Q_INVOKABLE bool home(){
		this->checkDisWidget();
		return this->disWidget->doHome();
	}

	Q_INVOKABLE bool left(qreal angle){
		this->checkDisWidget();
		return this->disWidget->doLeft(angle);
	}

	Q_INVOKABLE bool lt(qreal angle){
		return this->left(angle);
	}

	Q_INVOKABLE bool right(qreal angle){
		this->checkDisWidget();
		return this->disWidget->doRight(angle);
	}

	Q_INVOKABLE bool rt(qreal angle){
		return this->right(angle);
	}

	Q_INVOKABLE bool penUp(){
		this->checkDisWidget();
		return this->disWidget->doPenUp();
	}

	Q_INVOKABLE bool pu(){
		return this->penUp();
	}

	Q_INVOKABLE bool penDown(){
		this->checkDisWidget();
		return this->disWidget->doPenDown();
	}

	Q_INVOKABLE bool pd(){
		return this->penDown();
	}

	Q_INVOKABLE bool setBackground(int value){
		this->checkDisWidget();
		return this->disWidget->doSetBackground(value);
	}

	Q_INVOKABLE bool setBg(int value){
		return this->setBackground(value);
	}

	Q_INVOKABLE bool setPenColor(int value){
		this->checkDisWidget();
		return this->disWidget->doSetPenColor(value);
	}

	Q_INVOKABLE bool setPC(int value){
		return this->setPenColor(value);
	}

	Q_INVOKABLE bool setHead(qreal angle){
		this->checkDisWidget();
		return this->disWidget->doSetHead(angle);
	}

	Q_INVOKABLE bool setH(qreal angle){
		return this->setHead(angle);
	}

	Q_INVOKABLE bool setX(qreal x){
		this->checkDisWidget();
		return this->disWidget->doSetX(x);
	}

	Q_INVOKABLE bool setY(qreal y){
		this->checkDisWidget();
		return this->disWidget->doSetY(y);
	}

	Q_INVOKABLE bool setXY(qreal x, qreal y){
		this->checkDisWidget();
		return this->disWidget->doSetXY(x, y);
	}

	Q_INVOKABLE bool setSpeed(int speed){
		this->checkDisWidget();
		return this->disWidget->doSetSpeed(speed);
	}

	Q_INVOKABLE bool setWidth(int width){
		this->checkDisWidget();
		return this->disWidget->doSetWidth(width);
	}

	Q_INVOKABLE qreal Abs(qreal num){
		this->checkDisWidget();
		return this->disWidget->doAbs(num);
	}

	Q_INVOKABLE qreal Sin(qreal num){
		this->checkDisWidget();
		return this->disWidget->doSin(num);
	}

	Q_INVOKABLE qreal Cos(qreal num){
		this->checkDisWidget();
		return this->disWidget->doCos(num);
	}

	Q_INVOKABLE qreal Tan(qreal num){
		this->checkDisWidget();
		return this->disWidget->doTan(num);
	}

	Q_INVOKABLE qreal ArcSin(qreal num){
		this->checkDisWidget();
		return this->disWidget->doArcSin(num);
	}

	Q_INVOKABLE qreal ArcCos(qreal num){
		this->checkDisWidget();
		return this->disWidget->doArcCos(num);
	}

	Q_INVOKABLE qreal ArcTan(qreal num){
		this->checkDisWidget();
		return this->disWidget->doArcTan(num);
	}

	Q_INVOKABLE qreal Expn(qreal num){
		this->checkDisWidget();
		return this->disWidget->doExpn(num);
	}

	Q_INVOKABLE qreal Log(qreal num){
		this->checkDisWidget();
		return this->disWidget->doLog(num);
	}

	Q_INVOKABLE qreal Log10(qreal num){
		this->checkDisWidget();
		return this->disWidget->doLog10(num);
	}

	Q_INVOKABLE int Remainder(int first, int second){
		this->checkDisWidget();
		return this->disWidget->doRemainder(first, second);
	}

	Q_INVOKABLE int Random(int maxNum){
		this->checkDisWidget();
		return this->disWidget->doRandom(maxNum);
	}

	Q_INVOKABLE int Int(qreal num){
		this->checkDisWidget();
		return this->disWidget->doInt(num);
	}

	Q_INVOKABLE int Round(qreal num){
		this->checkDisWidget();
		return this->disWidget->doRound(num);
	}

	Q_INVOKABLE qreal Sqrt(qreal num){
		this->checkDisWidget();
		return this->disWidget->doSqrt(num);
	}

	Q_INVOKABLE qreal xCor(){
		this->checkDisWidget();
		return this->disWidget->doXCor();
	}

	Q_INVOKABLE qreal yCor(){
		this->checkDisWidget();
		return this->disWidget->doYCor();
	}

	Q_INVOKABLE qreal dot(qreal x, qreal y){
		this->checkDisWidget();
		return this->disWidget->doDot(x, y);
	}

	Q_INVOKABLE qreal heading(){
		this->checkDisWidget();
		return this->disWidget->doHeading();
	}

	Q_INVOKABLE bool draw(){
		this->checkDisWidget();
		return this->disWidget->doDraw();
	}

signals:

public slots:
};

#endif // TURTLEHELPER_H
