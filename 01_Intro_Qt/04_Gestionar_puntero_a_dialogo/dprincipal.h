#ifndef DPRINCIPAL_H_
#define DPRINCIPAL_H_
#include "dtransferencia.h"

#include <QDialog>

class DPrincipal : public QDialog {
Q_OBJECT

public:
    DPrincipal (QDialog *parent = NULL);
    DTransferencia *dTransferencia;

public slots:
    void slotLanzarDialogoTransferencia();

};

#endif
