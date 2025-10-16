#include "dtransferencia.h"

DTransferencia::DTransferencia (QDialog *parent) {

}

int DTransferencia::procesar(int algo) {

    if (algo == 8) {
        return 10;
    } else {
        return 11;
    }

}
