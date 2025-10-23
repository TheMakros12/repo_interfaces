#include <QPushButton>
#include <QVBoxLayout>

#include "dtransferencia.h"
#include "dprincipal.h"
#include <QDebug>

DPrincipal::DPrincipal (QDialog *parent) : QDialog(parent) {

    dTransferencia = NULL;

    QPushButton *btnLanzarDialogo = new QPushButton("Lanzar Dialogo");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(btnLanzarDialogo);

    setLayout(layoutPrincipal);

    connect(btnLanzarDialogo, SIGNAL(clicked()), this, SLOT(slotLanzarDialogoTransferencia()));

}

void DPrincipal::slotLanzarDialogoTransferencia() {

    if (dTransferencia == NULL) {
        dTransferencia = new DTransferencia;
    }
    dTransferencia->show();
}
