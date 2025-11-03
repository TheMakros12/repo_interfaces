#include "ventanaprincipal.h"
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QKeySequence>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>	
#include <QDebug>
#include <QFileDialog>
#include <QTextBlock>

#include "dacercade.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
		 QMainWindow(parent){

	QTextEdit *editorCentral = new QTextEdit();
	setCentralWidget(editorCentral);

	setWindowIcon(QIcon("./text-format.png"));
	setWindowTitle("Título Ventana");

	crearAcciones();
	crearMenus();
	
}

void VentanaPrincipal::crearAcciones() {

	//Accion Salir
	accionSalir = new QAction("Salir");
	accionSalir->setShortcut(QKeySequence::Quit);
	accionSalir->setIcon(QIcon("./text-format.png"));
	accionSalir->setStatusTip("Salir del programa");
	connect(accionSalir, SIGNAL(triggered()),
			this, SLOT(close()));

	//Accion AcercaDe
	accionAcercaDe = new QAction("Acerca De");
	accionAcercaDe->setShortcut(QKeySequence::WhatsThis);
	accionAcercaDe->setIcon(QIcon("./informacion.png"));
	accionAcercaDe->setStatusTip("Acerca De");
	connect(accionAcercaDe, SIGNAL(triggered()),
			this, SLOT(slotAcercaDe()));

	//Accion Guardar
	accionGuardar = new QAction("Guardar");
	accionGuardar->setShortcut(QKeySequence::Save);
	accionGuardar->setIcon(QIcon("./disquete.png"));
	accionGuardar->setStatusTip("Guardar");
	connect(accionGuardar, SIGNAL(triggered()),
			this, SLOT(slotGuardar()));

	//Accion Guardar Como
	accionGuardarComo = new QAction("Guardar Como");
	accionGuardarComo->setShortcut(QKeySequence::SaveAs);
	accionGuardarComo->setIcon(QIcon("./disqueteComo.png"));
	accionGuardarComo->setStatusTip("Guardar Como");
	connect(accionGuardarComo, SIGNAL(triggered()),
			this, SLOT(slotGuardarComo()));

}

void VentanaPrincipal::crearMenus() {
	QMenuBar *barra = menuBar();

	QMenu *menuFichero = barra->addMenu("Fichero");
	menuFichero->addAction(accionSalir);
	menuFichero->addAction(accionAcercaDe);
	menuFichero->addAction(accionGuardar);
	menuFichero->addAction(accionGuardarComo);
}

void VentanaPrincipal::slotAcercaDe() {
	DAcercaDe * dAcercaDe = new DAcercaDe();
	dAcercaDe->show();
}

void VentanaPrincipal::slotGuardar() {

}

void VentanaPrincipal::slotGuardarComo() {

	QString rutaArchivo;

	rutaArchivo = QFileDialog::getSaveFileName();

	qDebug() << "Ruta elegida para guardar " << rutaArchivo;

}
