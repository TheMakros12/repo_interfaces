#include <QPushButton>
#include <QVBoxLayout>

#include "dtransferencia.h"
#include "dprincipal.h"
#include <QDebug>

DPrincipal::DPrincipal (QDialog *parent) : QDialog(parent) {

    dTransferencia = NULL;

    QPushButton *btnLanzarDialogo = new QPushButton("Lanzar Dialogo");
    lblTransferencia->setText("Lanzar Transferencia:");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(btnLanzarDialogo);
    layoutPrincipal->addWidget(lblTransferencia);

    setLayout(layoutPrincipal);

    connect(btnLanzarDialogo, SIGNAL(clicked()), this, SLOT(slotLanzarDialogoTransferencia()));

}

void DPrincipal::slotLanzarDialogoTransferencia() {

    if (dTransferencia == NULL) {
        dTransferencia = new DTransferencia;
        connect(dTransferencia, SIGNAL(accepted()), this, SLOT(slotTransferenciaAceptada()));
        connect(dTransferencia, SIGNAL(rejected()), this, SLOT(slotTransferenciaRechazada()));
    }
    dTransferencia->show();
}

void DPrincipal::slotTransferenciaAceptada() {
    lblTransferencia->setText("Transferencia Aceptada");
}

void DPrincipal::slotTransferenciaRechazada() {
    lblTransferencia->setText("Transferencia Rechazada");
}
