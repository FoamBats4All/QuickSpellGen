#include "stdafx.h"
#include "quickspellgenerator.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QuickSpellGenerator w;
	w.show();
	return a.exec();
}
