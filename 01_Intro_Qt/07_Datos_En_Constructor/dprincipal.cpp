#include <QPushButton>
#include <QVBoxLayout>
#include <QStringList>
#include <QComboBox>

#include "dtransferencia.h"
#include "dprincipal.h"
#include <QDebug>

DPrincipal::DPrincipal (QDialog *parent) : QDialog(parent) {

    dTransferencia = NULL;

    QPushButton *btnLanzarDialogo = new QPushButton("Lanzar Dialogo");
    lblTransferencia->setText("Preparado:");
    QPushButton *btnActualizarCuentas = new QPushButton("Actualizar Cuentas");

    QStringList l = {"111111", "121212", "123123"};
    listaCuentas = l;

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(btnLanzarDialogo);
    layoutPrincipal->addWidget(lblTransferencia);
    layoutPrincipal->addWidget(btnActualizarCuentas);
    setLayout(layoutPrincipal);

    connect(btnLanzarDialogo, SIGNAL(clicked()), this, SLOT(slotLanzarDialogoTransferencia()));

    connect(btnActualizarCuentas, SIGNAL(clicked()), this, SLOT(slotActualizarCuentas()));

}

void DPrincipal::slotLanzarDialogoTransferencia() {

    if (dTransferencia == NULL) {
        dTransferencia = new DTransferencia(listaCuentas);
        /*connect(dTransferencia, SIGNAL(accepted()), this, SLOT(slotTransferenciaAceptada()));*/
        connect(dTransferencia, SIGNAL(senyalTransferenciaAceptada(float)), this, SLOT(slotCantidadAceptada(float)));
        connect(dTransferencia, SIGNAL(senyalTransferenciaGorda(bool)), this, SLOT(slotTransferenciaGorda(bool)));
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

void DPrincipal::slotTransferenciaGorda(bool gorda) {

    if (gorda){
    lblTransferencia->setText("Transferencia Gorda!!!");
    } else {
        lblTransferencia->setText("Transferencia normal");
    }

}

void DPrincipal::slotActualizarCuentas() {

    if (dTransferencia == NULL) return;
    QStringList listaNueva = {"999999", "898989", "789789"};
    dTransferencia->actualizarCuentas(listaNueva);
}
