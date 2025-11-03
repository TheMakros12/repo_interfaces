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

    QStringList listaCuentas;

public slots:
    void slotLanzarDialogoTransferencia();
    void slotTransferenciaAceptada();
    void slotTransferenciaRechazada();
    void slotCantidadAceptada(float);
    void slotTransferenciaGorda(bool);
    void slotActualizarCuentas();

};

#endif
