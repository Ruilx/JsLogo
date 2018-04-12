#ifndef MATH_H
#define MATH_H

#include <QtMath>
#include <QtCore>

inline qreal deg2Rad(qreal deg){ return qDegreesToRadians(deg); }
inline qreal rad2Deg(qreal rad){ return qDegreesToRadians(rad); }
inline qreal qPi() const{ return 3.14159265358979323846264338f; }
inline qreal qSquare(qreal base){ return base * base; }

typedef struct Polar{
	qreal rho;
	qreal theta;
	Polar(qreal rho, qreal theta){
		this->rho = rho;
		this->theta = theta;
	}
}QPolar, QPolarF;

QPolarF toPolarF(const QPoint &point){
	if(point.x() == 0 && point.y() == 0){
		return QPolar(0, 0);
	}else if(point.x() == 0 && point.y() != 0){
		return QPolar(qAbs(y), y > 0 ? qPi() / 2.0f : qPi() * 1.5f);
	}else if(point.x() != 0 && point.y() == 0){
		return QPolar(qAbs(x), x > 0 ? 0 : qPi());
	}else if(point.x() != 0 && point.y() != 0){
		return QPolar(qSqrt(qSquare(x) + qSquare(y)), qAtan(y / x));
	}
}

QPointF toPointF(const QPolar &polar){
	return QPointF(polar.rho * qCos(polar.theta), polar.rho * qSin(polar.theta));
}

#endif // MATH_H
