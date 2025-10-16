#include <QApplication>

#include "dtransferencia.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    DTransferencia dTransferencia;
    dTransferencia.show();

    return app.exec();

}
