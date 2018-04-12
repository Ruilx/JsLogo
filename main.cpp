#include "MainW.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainW w;
	w.show();

	return a.exec();
}
