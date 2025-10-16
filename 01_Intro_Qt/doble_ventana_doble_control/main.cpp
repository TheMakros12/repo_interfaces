#include <QApplication>
#include  <QHBoxLayout>
#include  <QVBoxLayout>
#include  <QSlider>
#include  <QSpinBox>
#include <QPushButton>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *windowBotones = new QWidget;
    QWidget *windowControl = new QWidget;
    windowBotones->setWindowTitle("Controladores");
    windowControl->setWindowTitle("Consola");

    QPushButton *btnUpSpinBox = new QPushButton("UP");
    QPushButton *btnDownSpinBox = new QPushButton("DOWN");
    QPushButton *btnUpSlider = new QPushButton("UP");
    QPushButton *btnDownSlider = new QPushButton("DOWN");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);
    spinBox->setValue(65);
    slider->setValue(65);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    QObject::connect(btnUpSpinBox, SIGNAL(clicked()), spinBox, SLOT(stepUp()));
    QObject::connect(btnDownSpinBox, SIGNAL(clicked()), spinBox, SLOT(stepDown()));

    QObject::connect(btnUpSlider, SIGNAL(clicked()), slider, SLOT());
    QObject::connect(btnDownSlider, SIGNAL(clicked()), slider, SLOT());

    QVBoxLayout *layoutIzq = new QVBoxLayout;
    layoutIzq->addWidget(btnUpSpinBox);
    layoutIzq->addWidget(btnDownSpinBox);
    QVBoxLayout *layoutDer = new QVBoxLayout;
    layoutDer->addWidget(btnUpSlider);
    layoutDer->addWidget(btnDownSlider);
    QHBoxLayout *layoutBtns = new QHBoxLayout;
    layoutBtns->addLayout(layoutIzq);
    layoutBtns->addLayout(layoutDer);

    QHBoxLayout *layoutControl = new QHBoxLayout;
    layoutControl->addWidget(spinBox);
    layoutControl->addWidget(slider);

    windowBotones->setLayout(layoutBtns);
    windowControl->setLayout(layoutControl);

    windowBotones->show();
    windowControl->show();

    return app.exec();

}
