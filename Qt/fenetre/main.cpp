#include <QApplication>
#include "fenetre.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MaFenetre fenetre(500,300);
    fenetre.show();

    return app.exec();
}
