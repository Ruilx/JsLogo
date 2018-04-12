#ifndef DISWIDGET_H
#define DISWIDGET_H

#include <QtWidgets>
#include <QVector2D>
#include <QGraphicsView>
#include <QGraphicsScene>

class DisWidget : public QWidget
{
	Q_OBJECT

	QGraphicsView *view = new QGraphicsView(this);
	QGraphicsScene *scene = new QGraphicsScene(this);

	QGraphicsPixmapItem *turtle = new QGraphicsPixmapItem(nullptr);

	const QPixmap turtlePixmap = QPixmap(":/data/image/turtle.png");

	QPointF oldPoint = QPointF(0, 0);
	QPointF newPoint = QPointF(0, 0);

	void backupLoc(){
		this->oldPoint = this->newPoint;
	}

	bool penDown = false;


public:
	explicit DisWidget(QWidget *parent = 0) : QWidget(parent){
		this->view->setScene(scene);

		QVBoxLayout *lay = new QVBoxLayout;
		this->setLayout(lay);
		lay->addWidget(this->view);
		lay->setMargin(0);

		this->resize(400, 400);

		this->turtle->setPixmap(this->turtlePixmap);
		this->turtle->setPos(-this->turtlePixmap.width() / 2.0f, -this->turtlePixmap.height() / 2.0f);

		QTimer::singleShot(1000, [this](){
			this->scene->setSceneRect((-this->view->width() / 2.0f), (-this->view->height() / 2.0f), this->view->width() -2, this->view->height() -2);
			this->scene->addItem(this->turtle);
		});
	}

signals:

public slots:
};

#endif // DISWIDGET_H
