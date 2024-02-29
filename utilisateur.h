/*  Name    : Utilisateur.h
 *  Purpose : Déclaration attributs et prototypes classe Utilisateur
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2024 février
 */

#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QFormLayout>
#include <QSqlRelationalTableModel>
#include <QLabel>
#include <QSqlQuery>
#include <QLineEdit>
#include <QCompleter>
#include <QComboBox>
#include <QItemSelectionModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QDataWidgetMapper>

class Utilisateur : public QWidget
{
    Q_OBJECT

private:
    QLabel *lbTitre;
    QLineEdit *edId;
    QComboBox *edProfil;
    QLineEdit *edCa;
    QLineEdit *edPseudo;
    QLineEdit *edPassWord;
    QLineEdit *edConfirmat;
    QLineEdit *edEtat;

    QPushButton *btnPrev;
    QPushButton *btnNext;
    QPushButton *btnNew;
    QPushButton *btnUpdate;
    QPushButton *btnSave;
    QPushButton *btnDelete;
    QPushButton *btnCancel;
    QPushButton *btnListe;
    QPushButton *btnPrn;
    QPushButton *btnQuit;

    QCompleter *compDenree;

    QFormLayout *formSaisie;
    QHBoxLayout *hBoxSaisie;
    QGridLayout *gridBoutton;

    QVBoxLayout *principalLayout;

    QSqlRelationalTableModel *model;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapper;

    //Méthode privée
    bool checkInputs();

public:
    Utilisateur(QWidget *parent = 0);
    virtual ~Utilisateur();
    void clearEditZone();
    void actReadOnly(bool etat);
    void refresh(QString currentValue);

private slots:
    void updateButtons(int row);
    void addNewRecord();
    void updateRecord();
    void saveRecord();
    void deleteRecord();
    void actListe();
    void actPreview();
    void prnListe(QPrinter * printer);
    void close();
    void showCurrProfil(int);

};

#endif // UTILISATEUR_H

