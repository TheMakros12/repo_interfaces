#ifndef DACERCADE_H_
#define DACERCADE_H_

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

class DAcercaDe : public QDialog {
Q_OBJECT

public:
    DAcercaDe(QDialog *parent = 0);
    QLabel *lblAcercaDe;
    QVBoxLayout *layoutPrincipal;
};

#endif
