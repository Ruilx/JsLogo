#ifndef UTILS_H
#define UTILS_H

#include <QtCore>

inline qreal qPi(){ return 3.14159265358979323846264338f; }
inline qreal deg2Rad(qreal deg){ return deg * (qPi() / 180.0f); }
inline qreal rad2Deg(qreal rad){ return rad * (180.0f / qPi()); }
inline qreal qSquare(qreal base){ return base * base; }

typedef struct QPolarF_t{
	qreal rho;
	qreal theta;
	bool valid = false;
	QPolarF_t(qreal rho, qreal theta){
		this->rho = rho;
		this->theta = theta;
		this->valid = true;
	}
	QPolarF_t() : QPolarF_t(0.0f, 0.0f){
		this->valid = false;
	}
}QPolarF;

QPolarF toPolarF(const QPoint &point);

QPointF toPointF(const QPolarF &polar);

qreal normDeg(qreal deg);

qreal normReg(qreal rad);

#endif // UTILS_H
