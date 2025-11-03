#include "dacercade.h"
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

DAcercaDe::DAcercaDe(QDialog *parent): QDialog(parent) {

    lblAcercaDe = new QLabel("Dialgo hecho por Marcos");

    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->addWidget(lblAcercaDe);

    setLayout(layoutPrincipal);

}
