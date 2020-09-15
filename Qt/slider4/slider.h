#ifndef SLIDER_H
#define SLIDER_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>

class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();


    public slots:
    void changerLargeur(int largeur);
    void changerLongueur(int longueur);

    signals:
    void agrandissementMax();

    private:
    QSlider *m_slider;
    QSlider *m_sliderV;
   /* QLCDNumber *m_lcd;
    QProgressBar *m_barre;
    QPushButton *m_bouton;*/
};

#endif // SLIDER_H
