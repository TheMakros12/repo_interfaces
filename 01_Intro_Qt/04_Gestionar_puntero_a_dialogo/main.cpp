#include <QApplication>

#include "dprincipal.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    DPrincipal dPrincipal;
    dPrincipal.show();

    return app.exec();

}
