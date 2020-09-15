#include "fenetre.h"

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(300, 150);

    // Construction du bouton
    m_bouton = new QPushButton("Pimp mon bouton !", this);

    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->setIcon(QIcon("smiley.png"));
    m_bouton->move(60, 50);
}

MaFenetre::MaFenetre(int largeur,int longeur) : QWidget(),lar(largeur),lon(longeur)
{
    setFixedSize(lar,lon);

    // Construction du bouton
    m_bouton = new QPushButton("Quitter", this);

    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->setIcon(QIcon("smiley.png"));
   m_bouton->move(60, 50);
    QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
}
