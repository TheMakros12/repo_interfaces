#include  <QApplication>
#include  <QHBoxLayout>
#include  <QVBoxLayout>
#include  <QSlider>
#include  <QSpinBox>
#include <QLCDNumber>
#include <QLabel>

int main (int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("Introduce tu edad:");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QLCDNumber *qLCDNumber = new  QLCDNumber();
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), qLCDNumber, SLOT(display(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), qLCDNumber, SLOT(display(int)));

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    QHBoxLayout *layoutSuperior = new QHBoxLayout;
    QHBoxLayout *layoutInferior = new QHBoxLayout;
    layoutSuperior->addWidget(spinBox);
    layoutSuperior->addWidget(slider);
    layoutInferior->addWidget(new QLabel("Valor:"));
    layoutInferior->addWidget(qLCDNumber);
    layoutPrincipal->addLayout(layoutSuperior);
    layoutPrincipal->addLayout(layoutInferior);
    window->setLayout(layoutPrincipal);

    window->show();

    return app.exec();

}
