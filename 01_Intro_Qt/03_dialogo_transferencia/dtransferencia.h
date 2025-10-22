#include <QDialog>
#include <QLineEdit>

class DTransferencia : public QDialog {
Q_OBJECT

public:
    DTransferencia (QDialog *parent = NULL);
    int procesar(int);
    QPushButton *btnAceptar;
    QLineEdit *leCantidad, *leDestino;

public slots:
    void activarBtn(const QString &);
    void rechazarDialogo();

};
