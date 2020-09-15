#include "boitedialogue.h"

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(230, 120);

    m_boutonDialogue = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_boutonDialogue->move(40, 50);

    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
}

void MaFenetre::ouvrirDialogue()
{
    //QMessageBox::information(this, "Titre de la fenêtre", "Bonjour et <strong>bienvenue à tous les Zéros !</strong>");
    //QMessageBox::question(this, "Titre de la fenêtre", "Dites voir, je me posais la question comme cela, êtes-vous vraiment un Zéro ?", QMessageBox::Yes | QMessageBox::No);

   /* int reponse = QMessageBox::question(this, "Interrogatoire", "Dites voir, je me posais la question comme cela, êtes-vous vraiment un Zéro ?", QMessageBox ::Yes | QMessageBox::No);

       if (reponse == QMessageBox::Yes)
       {
           QMessageBox::information(this, "Interrogatoire", "Alors bienvenue chezles Zéros !");
       }
       else if (reponse == QMessageBox::No)
       {
           QMessageBox::critical(this, "Interrogatoire", "Tricheur ! Menteur ! Voleur ! Ingrat ! Lâche ! Traître !\nSors d'ici ou j'appelle la police !");
       }
       */
    /*
       bool ok = false;
           QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?", QLineEdit::Normal, QString(), &ok);

           if (ok && !pseudo.isEmpty())
           {
               QMessageBox::information(this, "Pseudo", "Bonjour " + pseudo + ", ça va ?");
           }
           else
           {
               QMessageBox::critical(this, "Pseudo", "Vous n'avez pas voulu donner votre nom… snif.");
           }
           */
    bool ok = false;

       QFont police = QFontDialog::getFont(&ok, m_boutonDialogue->font(), this, "Choisissez une police");

       if (ok)
       {
           m_boutonDialogue->setFont(police);
       }

}

