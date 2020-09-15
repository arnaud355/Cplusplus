#include "slider.h"


MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(200, 100);


   /* m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(50, 20);*/

   /* m_bouton = new QPushButton("reset", this);
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->move(5, 20);*/

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setRange(200, 600);
    m_slider->setGeometry(10, 60, 150, 20);

    m_sliderV = new QSlider(Qt::Vertical, this);
    m_sliderV->setRange(200, 600);
    m_sliderV->setGeometry(10, 60, 150, 20);
    m_sliderV->move(100, 20);

    //QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));

   /* m_barre = new QProgressBar(this);
    m_barre->setOrientation(Qt::Horizontal);
    m_barre->setGeometry(20, 30, 150, 20);
    m_barre->move(100, 20);*/

   // QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_barre, SLOT(setValue(int)));
    //QObject::connect(m_bouton, SIGNAL(clicked()), m_barre, SLOT(reset()));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    QObject::connect(m_sliderV, SIGNAL(valueChanged(int)), this, SLOT(changerLongueur(int)));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));
}



void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(largeur, height());

    if (largeur == 600)
        {
            emit agrandissementMax();
        }
}
void MaFenetre::changerLongueur(int longueur)
{
    setFixedSize(width(), longueur);
}
