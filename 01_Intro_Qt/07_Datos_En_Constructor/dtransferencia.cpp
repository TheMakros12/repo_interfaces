#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QComboBox>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "dtransferencia.h"
#include <QDebug>

DTransferencia::DTransferencia (QStringList listaCuentas, QDialog *parent) : QDialog(parent) {

    QLabel *lblDestino = new QLabel("Destino:  ");
    QLabel *lblCantidad = new QLabel("Cantidad:");
    QLabel *lblComision = new QLabel("Comisión: ");

    cmbBoxCuentas = new QComboBox;
    cmbBoxCuentas->addItems(listaCuentas);

    leDestino = new QLineEdit;
    leCantidad = new QLineEdit;
    btnAceptar = new QPushButton("Aceptar");
    btnAceptar->setEnabled(false);
    QPushButton *btnCancelar = new QPushButton("Cancelar");

    QHBoxLayout *layoutTextoDestino = new QHBoxLayout;
    layoutTextoDestino->addWidget(lblDestino);
    //layoutTextoDestino->addWidget(leDestino);
    layoutTextoDestino->addWidget(cmbBoxCuentas);
    layoutTextoDestino->addWidget(btnAceptar);

    QHBoxLayout *layoutTextoCantidad = new QHBoxLayout;
    layoutTextoCantidad->addWidget(lblCantidad);
    layoutTextoCantidad->addWidget(leCantidad);
    layoutTextoCantidad->addWidget(btnCancelar);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutTextoDestino);
    layoutPrincipal->addLayout(layoutTextoCantidad);
    layoutPrincipal->addWidget(lblComision);

    setLayout(layoutPrincipal);

    /*connect(btnAceptar, SIGNAL(clicked()), this, SLOT(accept()));*/
    connect(btnAceptar, SIGNAL(clicked()), this, SLOT(slotAceptar()));
    connect(btnCancelar, SIGNAL(clicked()), this, SLOT(rechazarDialogo()));

    connect(leCantidad, SIGNAL(textChanged(const QString &)), this, SLOT(activarBtn(const QString &)));
    connect(leDestino, SIGNAL(textChanged(const QString &)), this, SLOT(activarBtn(const QString &)));
    connect(leCantidad, SIGNAL(textChanged(const QString &)), this, SLOT(slotCantidadModificada(const QString &)));

}

void DTransferencia::activarBtn(const QString & textoCantidad) {

    QString txtCantidad = leCantidad->text();
    QString txtNumCuenta = leDestino->text();

    QRegularExpression reCantidad("^\\d+$");
    QRegularExpression reNumCuenta("^\\d{6}$");

    QRegularExpressionMatch mCantidad = reCantidad.match(txtCantidad);
    QRegularExpressionMatch mNumCuenta = reNumCuenta.match(txtNumCuenta);

    if (mCantidad.hasMatch() && mNumCuenta.hasMatch()) {
        btnAceptar->setEnabled(true);
    } else {
        btnAceptar->setEnabled(false);
    }

}

int DTransferencia::procesar(int algo) {

    if (algo == 8) {
        return 10;
    } else {
        return 11;
    }

}

void DTransferencia::slotAceptar() {

    float cantidad = leCantidad->text().toFloat();
    emit senyalTransferenciaAceptada(cantidad);
    this->accept();
}

void DTransferencia::slotCantidadModificada(const QString & texto) {

    QString nuevaCantidad = leCantidad->text();
    nuevaCantidad = texto;

    float cantidad = nuevaCantidad.toFloat();

    if (cantidad > 100000 && senyalAnterior == false) {
        emit senyalTransferenciaGorda(true);
        senyalAnterior = true;
    }

    if (cantidad < 100000 && senyalAnterior == true) {
        emit senyalTransferenciaGorda(false);
        senyalAnterior = false;
    }

}

void DTransferencia::rechazarDialogo() {

    if (!(btnAceptar->isEnabled()))
        reject();

}

void DTransferencia::actualizarCuentas(QStringList nuevaLista) {
    cmbBoxCuentas->clear();
    cmbBoxCuentas->addItems(nuevaLista);
}
