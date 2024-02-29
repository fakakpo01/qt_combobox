/*  Name    : ListeUtilisateur.h
 *  Purpose : Déclaration des attributs et prototypes des méthodes de la classe ListeUtilisateur
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */

#ifndef LISTEUTILISATEUR_H
#define LISTEUTILISATEUR_H
#include <QLabel>
#include <QSqlTableModel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QTableView>
#include <QHBoxLayout>

class ListeUtilisateur : public QWidget
{
    Q_OBJECT

private:
    QLabel *lblTitle;
    QLineEdit *editSearch;
    QPushButton *quitButton;
    QPushButton *btnAfficher;
    QHBoxLayout *hbOperation;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *modele;
    QTableView *view;

public:
    ListeUtilisateur(QWidget *parent = 0);
    virtual ~ListeUtilisateur();

private slots:
    void actSelection();
    void actFiltre(QString filtre);
    //    void close();
};

#endif // LISTEUTILISATEUR_H
