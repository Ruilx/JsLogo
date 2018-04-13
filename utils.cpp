#include "utils.h"

QPolarF toPolarF(const QPoint &point){
	if(point.x() == 0 && point.y() == 0){
		return QPolarF(0, 0);
	}else if(point.x() == 0 && point.y() != 0){
		return QPolarF(qAbs(point.y()), point.y() > 0 ? qPi() / 2.0f : qPi() * 1.5f);
	}else if(point.x() != 0 && point.y() == 0){
		return QPolarF(qAbs(point.x()), point.x() > 0 ? 0 : qPi());
	}else if(point.x() != 0 && point.y() != 0){
		return QPolarF(qSqrt(qSquare(point.x()) + qSquare(point.y())), qAtan(point.y() / point.x()));
	}
	return QPolarF();
}

QPointF toPointF(const QPolarF &polar){
	qreal cosT = qCos(polar.theta);
	if(qAbs(cosT) < 0.00001f){
		cosT = qreal(0.0f);
	}else if(cosT > 0 && ((1.0f - cosT) < 0.00001f)){
		cosT = qreal(1.0f);
	}else if(cosT < 0 && ((1.0f + cosT) < 0.00001f)){
		cosT = qreal(-1.0f);
	}
	qreal sinT = qSin(polar.theta);
	if(qAbs(sinT) < 0.00001f){
		sinT = qreal(0.0f);
	}else if(sinT > 0 && ((1.0f - sinT) < 0.00001f)){
		sinT = qreal(1.0f);
	}else if(sinT < 0 && ((1.0f + sinT) < 0.00001f)){
		sinT = qreal(-1.0f);
	}
	return QPointF(polar.rho * cosT, polar.rho * sinT);
}

qreal normDeg(qreal deg){
//	qDebug() << __FUNCTION__ << ": normDeg:" << deg << " fmod():" << fmod(deg, 360.0f);
	qreal mod = fmod(deg, 360.0f);
	if(mod >= 0.0f){
		return mod;
	}else{
		return 360.0f + mod;
	}
	return deg;
}

qreal normReg(qreal rad){
	qreal mod = fmod(rad, qPi() * 2);
	if(mod >= 0.0f){
		return mod;
	}else{
		return qPi() * 2 + mod;
	}
}
