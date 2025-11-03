#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QCloseEvent>
#include <QVector>
#include <QStringList>
#include <QLabel>

#define MAX_FICHEROS_RECIENTES 5 

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:

	VentanaPrincipal(QWidget *parent = NULL);
	void crearAcciones();
	void crearMenus();

	QAction *accionSalir, *accionAcercaDe, *accionGuardar, *accionGuardarComo;

public slots:
	void slotAcercaDe();
	void slotGuardar();
	void slotGuardarComo();

};

#endif
