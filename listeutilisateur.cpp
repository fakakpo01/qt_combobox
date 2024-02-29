/*  Name    : ListeUtilisateur.cpp
 *  Purpose : Définitions méthode classe ListeUtilisateur
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */

#include <QHeaderView>
#include <QSqlError>
#include <QSqlRecord>
#include "utilisateur.h"
#include "ListeUtilisateur.h"

ListeUtilisateur::ListeUtilisateur(QWidget *parent) : QWidget(parent)
/*  But     : Constructeur des objets ListeUtilisateur
*  Auteurs : Equipe Les IT-DIS
*  Date    : 2015 Septembre
*/
{
    setWindowTitle(tr("Liste des fournisseurs"));
    lblTitle = new QLabel("<center>Liste des fournisseurs </center>");
    QFont oFnt("Georgia",16,QFont::Bold);
    lblTitle->setFont(oFnt);
    editSearch = new QLineEdit;
    editSearch->setMaximumWidth(150);
    QFormLayout *formSearch = new QFormLayout;
    formSearch->addRow("Filtre sur nom", editSearch);

    hbOperation = new QHBoxLayout;
    hbOperation->addSpacing(170);
    hbOperation->addLayout(formSearch);
    //    hbOperation->addSpacing(220);

    //Création du modèle
    modele = new QSqlTableModel(this);
    modele->setTable("users");
    modele->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modele->setSort(0,Qt::AscendingOrder);
    modele->setHeaderData(0, Qt::Horizontal, tr("id"));
    modele->setHeaderData(1, Qt::Horizontal, tr("id_profil"));
    modele->setHeaderData(2, Qt::Horizontal, tr("pseudo"));
    modele->setHeaderData(3, Qt::Horizontal, tr("ca"));
    //modele->setHeaderData(4, Qt::Horizontal, tr("Adresse"));
    //modele->setHeaderData(5, Qt::Horizontal, tr("Téléphone 1"));
    //modele->setHeaderData(6, Qt::Horizontal, tr("Téléphone 2"));
    //modele->setHeaderData(7, Qt::Horizontal, tr("Début livraison"));
    modele->select();

    //Création de la vue
    view = new QTableView;
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->setModel(modele);
    view->resizeColumnsToContents();
    view->verticalHeader()->hide();
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setAlternatingRowColors(true);
    view->setStyleSheet("alternate-background-color: lightgrey;");
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //view->setMinimumSize(480, 500);

    //Organisation des boutons
    btnAfficher = new QPushButton(tr("Afficher"));
    quitButton = new QPushButton(tr("Fermer"));
    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(btnAfficher, QDialogButtonBox::AcceptRole);
    //buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    //Organisation générale de la fenêtre
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(lblTitle);
    mainLayout->addLayout(hbOperation);
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox,0,Qt::AlignHCenter);

    QHBoxLayout *hboxPrincipal = new QHBoxLayout;
    hboxPrincipal->addLayout(mainLayout);
    setLayout(hboxPrincipal);

    //Mise en place des connexions pour les boutons
    connect(editSearch, SIGNAL(textChanged(QString)), this, SLOT(actFiltre(QString)));
    connect(btnAfficher, SIGNAL(clicked()), this, SLOT(actSelection()));
    //connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
}//ListeUtilisateur::ListeUtilisateur(QWidget *parent) : QWidget(parent)


ListeUtilisateur::~ListeUtilisateur()
{
    this->destroy(true, true);
}


void ListeUtilisateur::actFiltre(QString filtre)
/*  But     : Activer le filtre
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Octobre
 */
{
    modele->setFilter("pseudo LIKE '"+filtre+"%'");
    modele->setSort(2, Qt::AscendingOrder);
    modele->select();
}//void ListeUtilisateur::actFiltre(QString filtre)


void ListeUtilisateur::actSelection()
/*  But     : Appliquer la sélection
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Octobre
 */
{
    QModelIndex intIndex = view->selectionModel()->currentIndex();
    QSqlRecord record = modele->record(intIndex.row());
    QString currentValue = record.value(record.indexOf("id")).toString();
    close();
    qobject_cast<Utilisateur *>(this->parent())->refresh(currentValue);
    //this->destroy(true,true);
}//void ListeUtilisateur::actSelection()

