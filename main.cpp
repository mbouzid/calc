#include <QtGui/QApplication>
#include <QtGui/QWidget>

#include "view.hpp"
#include "engine.hpp"
#include "translator.hpp"

int main( int argc , char * argv[] )
{

	QApplication app(argc,argv);
    translator t;
 
	return app.exec();

}
