#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    public:
    MaFenetre();
    MaFenetre(int largeur,int longeur);

    private:
    QPushButton *m_bouton;
    int lar;
    int lon;
};

#endif
