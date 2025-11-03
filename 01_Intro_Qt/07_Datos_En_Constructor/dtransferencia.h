#ifndef DTRANSFERENCIA_H_
#define  DTRANSFERENCIA_H_

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

class DTransferencia : public QDialog {
Q_OBJECT

public:
    DTransferencia (QStringList, QDialog *parent = 0);
    int procesar(int);
    QPushButton *btnAceptar;
    QComboBox *cmbBoxCuentas;
    QLineEdit *leCantidad, *leDestino;
    bool senyalAnterior = false;

public slots:
    void activarBtn(const QString &);
    void rechazarDialogo();
    void slotAceptar();
    void slotCantidadModificada(const QString &);
    void actualizarCuentas(QStringList);

signals:
    void senyalTransferenciaAceptada(float);
    void senyalTransferenciaGorda(bool);

};

#endif
