#ifndef BOITEDIALOGUE_H
#define BOITEDIALOGUE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFont>
#include <QFontDialog>


class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void ouvrirDialogue();

    private:
    QPushButton *m_boutonDialogue;
};
#endif // BOITEDIALOGUE_H
