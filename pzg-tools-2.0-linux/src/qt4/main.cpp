#include <QApplication>
#include "pzgtools.h"

int main(int argc, char *argv[] )
{
	QApplication app(argc, argv);
	pzgtools *dialog = new pzgtools;

	dialog->show();
	return app.exec();
}

