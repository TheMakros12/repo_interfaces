#include <QPushButton>
#include <QVBoxLayout>

#include "dtransferencia.h"
#include "dprincipal.h"
#include <QDebug>

DPrincipal::DPrincipal (QDialog *parent) : QDialog(parent) {

    dTransferencia = NULL;

    QPushButton *btnLanzarDialogo = new QPushButton("Lanzar Dialogo");
    lblTransferencia->setText("Preparado:");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(btnLanzarDialogo);
    layoutPrincipal->addWidget(lblTransferencia);

    setLayout(layoutPrincipal);

    connect(btnLanzarDialogo, SIGNAL(clicked()), this, SLOT(slotLanzarDialogoTransferencia()));

}

void DPrincipal::slotLanzarDialogoTransferencia() {

    if (dTransferencia == NULL) {
        dTransferencia = new DTransferencia;
        /*connect(dTransferencia, SIGNAL(accepted()), this, SLOT(slotTransferenciaAceptada()));*/
        connect(dTransferencia, SIGNAL(senyalTransferenciaAceptada(float)), this, SLOT(slotCantidadAceptada(float)));
        connect(dTransferencia, SIGNAL(senyalTransferenciaGorda()), this, SLOT(slotTransferenciaGorda()));
        connect(dTransferencia, SIGNAL(rejected()), this, SLOT(slotTransferenciaRechazada()));
    }
    dTransferencia->show();
}

void DPrincipal::slotTransferenciaAceptada() {
    lblTransferencia->setText("Transferencia de " + dTransferencia->leCantidad->text() + "€");
}

void DPrincipal::slotTransferenciaRechazada() {
    lblTransferencia->setText("Transferencia Rechazada");
}

void DPrincipal::slotCantidadAceptada(float monto) {

    QString texto;
    texto += "Tranferencia de ";
    texto += QString::number(monto);

    lblTransferencia->setText(texto);

}

void DPrincipal::slotTransferenciaGorda() {
    lblTransferencia->setText("Transferencia Gorda");
}
