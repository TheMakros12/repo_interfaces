#ifndef DPRINCIPAL_H_
#define DPRINCIPAL_H_
#include "dtransferencia.h"

#include <QDialog>
#include <QLabel>

class DPrincipal : public QDialog {
Q_OBJECT

public:
    DPrincipal (QDialog *parent = NULL);
    DTransferencia *dTransferencia;
    QLabel *lblTransferencia = new QLabel;

public slots:
    void slotLanzarDialogoTransferencia();
    void slotTransferenciaAceptada();
    void slotTransferenciaRechazada();

};

#endif
