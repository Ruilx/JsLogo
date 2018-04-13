#ifndef DISWIDGET_H
#define DISWIDGET_H

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "utils.h"

class DisWidget : public QWidget
{
	Q_OBJECT

	QGraphicsView *view = new QGraphicsView(this);
	QGraphicsScene *scene = new QGraphicsScene(this);

	QGraphicsPixmapItem *turtle = new QGraphicsPixmapItem(nullptr);

	const QPixmap turtlePixmap = QPixmap(":/data/image/turtle.png");
	QPointF adjustToLeftTop(const QPointF &centerPoint, const QSizeF &size){
		return QPointF(centerPoint.x() - (size.width() / 2.0f), centerPoint.y() - (size.height() / 2.0f));
	}
	QPointF adjustToLeftTop(const QPointF &centerPoint){
		return this->adjustToLeftTop(centerPoint, QSizeF(this->turtlePixmap.size()));
	}
	QPointF turtlePos(){
		qDebug() << (this->turtle->pos() + QPointF(this->turtlePixmap.width() / 2.0f, this->turtlePixmap.height() / 2.0f));
		return this->turtle->pos() + QPointF(this->turtlePixmap.width() / 2.0f, this->turtlePixmap.height() / 2.0f);
	}
	void debugTurtlePos(){
		qDebug() << "Current Turtle:" << this->turtlePos();
	}
	void debugTurtleRolation(){
		qDebug() << "Current Turtle Angle:" << this->turtle->rotation();
	}
	QPointF setTurtlePos(const QPointF &location){
		qDebug() << __FUNCTION__ << "location:" << location;
		this->turtle->setPos(this->adjustToLeftTop(location));
		this->backupLoc();
		debugTurtlePos();
		this->penDownDraw();
		return this->turtlePos();
	}
	QPointF moveTurtlePos(const QPointF &vector){
		qDebug() << __FUNCTION__ << "move vector:" << vector;
		this->turtle->setPos(this->adjustToLeftTop(this->turtlePos() + vector));
		this->backupLoc();
		debugTurtlePos();
		this->penDownDraw();
		return this->turtlePos();
	}
	QPointF moveTurtlePos(const QPolarF &polar){
		qDebug() << __FUNCTION__ << "move polar:" << "(" << polar.rho << "," << polar.theta << ")";
		this->turtle->setPos(this->adjustToLeftTop(this->turtlePos() + toPointF(polar)));
		this->backupLoc();
		debugTurtlePos();
		this->penDownDraw();
		return this->turtlePos();
	}
	QPointF moveTutleAngle(qreal deg){
		qDebug() << __FUNCTION__ << "move angle:" << deg;
		this->currentDegree = normDeg(this->currentDegree + deg);
		this->turtle->setRotation(this->currentDegree - 270.0f);
		debugTurtleRolation();
		return this->turtlePos();
	}
	QPointF setTutleAngle(qreal deg){
		deg = deg + 270.0f;
		qDebug() << __FUNCTION__ << "set angle:" << deg;
		this->currentDegree = normDeg(deg);
		this->turtle->setRotation(this->currentDegree - 270.0f);
		debugTurtleRolation();
		return this->turtlePos();
	}
	void setTurtleVisible(bool visible){
		this->turtle->setVisible(visible);
	}

	QPointF oldPoint = QPointF(0, 0);
	QPointF newPoint = QPointF(0, 0);

	qreal currentDegree = 270.0f;

	inline void backupLoc(){
		qDebug() << "BackupLoc: Using:" << this->newPoint << "replace to OLD:" << this->oldPoint;
		this->oldPoint = this->newPoint;
		this->newPoint = this->turtlePos();
	}

	bool penDown = true;
	QPen currentPen = QPen(QColor(Qt::black));

	void penDownDraw(){
		if(!this->penDown){
			return;
		}
//		if(this->newPoint != this->oldPoint){
//			this->polygon->polygon().append(this->newPoint);
//		}
		if(this->newPoint != this->oldPoint){
			QGraphicsLineItem *i = new QGraphicsLineItem(QLineF(this->oldPoint, this->newPoint), nullptr);
			i->setPen(this->currentPen);
			this->scene->addItem(i);
		}
	}

	void setPenDown(bool down){
		this->penDown = down;
	}

	QColor stdColor(int index){
		switch(index){
			case 0:
				return QColor(Qt::black); break;
			case 1:
				return QColor(Qt::blue); break;
			case 2:
				return QColor(Qt::green); break;
			case 3:
				return QColor(Qt::cyan); break;
			case 4:
				return QColor(Qt::red); break;
			case 5:
				return QColor(Qt::magenta); break;
			case 6:
				return QColor("#804000"); break; //brown
			case 7:
				return QColor(Qt::lightGray); break;
			case 8:
				return QColor(Qt::gray); break; // "dark" gray
			case 9:
				return QColor(Qt::blue).lighter(); break; // light blue
			case 10:
				return QColor(Qt::green).lighter(); break; // light green
			case 11:
				return QColor(Qt::cyan).lighter(); break; // light cyan
			case 12:
				return QColor(Qt::red).lighter(); break; // light red
			case 13:
				return QColor(Qt::magenta).lighter(); break; // light magenta
			case 14:
				return QColor("#804000").lighter(); break; // light brown
			case 15:
				return QColor(Qt::white); break;
			default:
				return QColor();
		}
	}

public:
	explicit DisWidget(QWidget *parent = 0) : QWidget(parent){
		this->view->setScene(scene);

		QVBoxLayout *lay = new QVBoxLayout;
		this->setLayout(lay);
		lay->addWidget(this->view);
		lay->setMargin(0);

		this->resize(400, 400);
		this->view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
//		this->view->horizontalScrollBar()->hide();
//		this->view->verticalScrollBar()->hide();
		this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		this->turtle->setPixmap(this->turtlePixmap);
		this->turtle->setTransformOriginPoint(this->turtlePixmap.width() / 2.0f, this->turtlePixmap.height() / 2.0f);
		this->turtle->setPos(-this->turtlePixmap.width() / 2.0f, -this->turtlePixmap.height() / 2.0f);
		qDebug() << "this->turtle.pos()" << this->turtle->pos();
		this->turtle->setTransformationMode(Qt::SmoothTransformation);
		//this->polygon->setPos(0, 0);

		this->currentPen.setWidth(1);

		//this->scene->addLine(-1000, 0, 1000, 0, QPen(QColor(Qt::blue)));
		//this->scene->addLine(0, -1000, 0, 1000, QPen(QColor(Qt::blue)));

		QTimer::singleShot(1000, [this](){
			this->scene->setSceneRect((-this->view->width() / 2.0f), (-this->view->height() / 2.0f), this->view->width() -2, this->view->height() -2);
			this->scene->addItem(this->turtle);
		});
	}

	Q_INVOKABLE bool doForward(qreal length){
		return this->moveTurtlePos(QPolarF(length, deg2Rad(this->currentDegree))).isNull() ? false : true;
	}

	Q_INVOKABLE bool doBackward(qreal length){
		return this->moveTurtlePos(QPolarF(-length, deg2Rad(this->currentDegree))).isNull() ? false : true;
	}

	Q_INVOKABLE bool doClear(){
		for(QGraphicsItem *i: this->scene->items()){
			if(i && i != this->turtle){
				this->scene->removeItem(i);
				delete i;
			}
		}
		this->setTurtlePos(QPoint(0.0f, 0.0f));
		this->setTutleAngle(0);
		return this->setTurtlePos(QPointF(0, 0)).isNull() ? false : true;
	}

	Q_INVOKABLE bool doHideTurtle(){
		this->setTurtleVisible(false);
		return true;
	}

	Q_INVOKABLE bool doShowTurtle(){
		this->setTurtleVisible(true);
		return true;
	}

	Q_INVOKABLE bool doHome(){
		this->setTurtlePos(QPointF(0.0f, 0.0f));
		this->setTutleAngle(0.0f);
		return true;
	}

	Q_INVOKABLE bool doLeft(qreal deg){
		return this->moveTutleAngle(-deg).isNull() ? false : true;
	}

	Q_INVOKABLE bool doRight(qreal deg){
		return this->moveTutleAngle(deg).isNull() ? false : true;
	}

	Q_INVOKABLE bool doPenUp(){
		this->penDown = false;
		return true;
	}

	Q_INVOKABLE bool doPenDown(){
		this->penDown = true;
		return true;
	}

	Q_INVOKABLE bool doSetBackground(int value){
		QColor color = this->stdColor(value);
		if(!color.isValid()){
			return false;
		}
		this->scene->setBackgroundBrush(QBrush(color));
		return true;
	}

	Q_INVOKABLE bool doSetHead(qreal angle){
		return this->setTutleAngle(angle).isNull() ? false : true;
	}

	Q_INVOKABLE bool doSetX(qreal x){
		return this->setTurtlePos(QPointF(x, this->turtlePos().y())).isNull() ? false : true;
	}

	Q_INVOKABLE bool doSetY(qreal y){
		return this->setTurtlePos(QPointF(this->turtlePos().x(), y)).isNull() ? false : true;
	}

	Q_INVOKABLE bool doSetXY(qreal x, qreal y){
		return this->setTurtlePos(QPointF(x, y)).isNull() ? false : true;
	}

	Q_INVOKABLE bool doSetPenColor(int value){
		QColor color = this->stdColor(value);
		if(!color.isValid()){
			return false;
		}
		this->currentPen.setColor(color);
		return true;
	}

	Q_INVOKABLE bool doSetSpeed(int speed){
		if(speed > 100 || speed < 1){
			return false;
		}
		return true;
	}

	Q_INVOKABLE bool doSetWidth(int width){
		this->currentPen.setWidth(width);
		return true;
	}

	Q_INVOKABLE qreal doAbs(qreal num){
		return qAbs(num);
	}

	Q_INVOKABLE qreal doSin(qreal num){ // deg
		return qSin(deg2Rad(num));
	}

	Q_INVOKABLE qreal doCos(qreal num){ // deg
		return qCos(deg2Rad(num));
	}

	Q_INVOKABLE qreal doTan(qreal num){ // deg
		return qTan(deg2Rad(num));
	}

	Q_INVOKABLE qreal doArcSin(qreal num){ // deg
		return rad2Deg(qAsin(num));
	}

	Q_INVOKABLE qreal doArcCos(qreal num){ // deg
		return rad2Deg(qAcos(num));
	}

	Q_INVOKABLE qreal doArcTan(qreal num){ // deg
		return rad2Deg(qAtan(num));
	}

	Q_INVOKABLE qreal doExpn(int num){
		return qPow(M_E, num);
	}

	Q_INVOKABLE qreal doLog(qreal n){
		if(n < 0){
			return false;
		}
		return log(n);
	}

	Q_INVOKABLE qreal doLog10(qreal n){
		if(n < 0){
			return 0.0f;
		}
		return log10(n);

	}

	Q_INVOKABLE int doRandom(int maxNum){
		return (QRandomGenerator::global()->generate() % maxNum) + 1;
	}

	Q_INVOKABLE int doRemainder(int first, int second){
		return first % second;
	}

	Q_INVOKABLE int doRound(qreal num){
		return qRound(num);
	}

	Q_INVOKABLE qreal doSqrt(qreal num){
		if(num < 0){
			return 0.0f;
		}
		return qSqrt(num);
	}

	Q_INVOKABLE qreal doXCor(){
		return this->turtlePos().x();
	}

	Q_INVOKABLE qreal doYCor(){
		return this->turtlePos().y();
	}

	Q_INVOKABLE bool doDot(qreal x, qreal y){
		QGraphicsLineItem *i = new QGraphicsLineItem(QLineF(x, y, x, y), nullptr);
		i->setPen(this->currentPen);
		this->scene->addItem(i);
		return true;
	}

	Q_INVOKABLE qreal doHeading(){
		return this->turtle->rotation();
	}

	Q_INVOKABLE bool doDraw(){
		this->doClear();
		this->setTurtlePos(QPointF(0.0f, 0.0f));
		this->setTurtleVisible(true);
		this->setPenDown(true);
		this->doSetPenColor(0);
		this->doSetBackground(15);
		this->doSetWidth(1);
		return true;
	}

signals:

public slots:
};

#endif // DISWIDGET_H
