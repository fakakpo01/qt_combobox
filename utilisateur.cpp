/*  Name    : Utilisateur.cpp
 *  Purpose : Définitions des méthode classe Utilisateur
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2024 février
 */

#include <QSqlError>
#include <QPrintPreviewDialog>
#include <QSqlRecord>
#include <QList>
#include <QTableView>
#include <QSqlRelationalDelegate>
#include <QColor>
#include <QMessageBox>
#include "utilisateur.h"
#include "listeutilisateur.h"
#include "utilitaire.h"
#include "fonctions.h"

Utilisateur::Utilisateur(QWidget * parent) : QWidget(parent)
/*  But     : Constructeur des objets Utilisateur
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2024 janvier
 */
{
    setWindowTitle(tr("Mise À Jour des Utilisateurs"));
    lbTitre = new QLabel("<center>Mise à jour des Utilisateurs</center>");
    QFont css("Georgia",16,QFont::Bold);
    lbTitre->setFont(css);

    //Les différents zones de saisie
    edId = new QLineEdit;
    edProfil = new QComboBox;
    edCa = new QLineEdit;
    edPseudo = new QLineEdit;
    edPassWord = new QLineEdit;
    edConfirmat = new QLineEdit;
    edEtat = new QLineEdit;

    //Boutons présents dans la fenêtre
    btnPrev = new QPushButton("Précédent");
    btnNext = new QPushButton("Suivant");
    btnSave = new QPushButton("Enregistrer");
    btnCancel = new QPushButton("Annuler");
    btnNew = new QPushButton("Nouveau");
    btnUpdate = new QPushButton("Modifier");
    btnDelete = new QPushButton("Supprimer");
    btnQuit = new QPushButton("Quitter");
    btnListe = new QPushButton("Liste");
    btnPrn = new QPushButton("Imprimer Liste");

    //Le formulaire de saisie des données
    formSaisie = new QFormLayout;
    formSaisie->addRow("N° Utilisateur", edId);
    formSaisie->addRow("Profil", edProfil);
    formSaisie->addRow("Pseudo", edPseudo);
    formSaisie->addRow("Code d'accès", edCa);
    formSaisie->addRow("Mot de passe", edPassWord);
    formSaisie->addRow("Confirmation", edConfirmat);

    //Création du modèle
    model = new QSqlRelationalTableModel(this);
    model->setTable("users");
    model->setRelation(model->fieldIndex("id_profil"), QSqlRelation("profils", "id", "nom"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //model->setJoinMode(QSqlRelationalTableModel::LeftJoin);
    model->select();
    edProfil->setModel(model);
    edProfil->setModelColumn(model->fieldIndex("nom"));
    connect(edProfil, SIGNAL(currentIndexChanged(int)), this, SLOT(showCurrProfil(int)));
    //Création de la vue
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(model));
    mapper->addMapping(edId, model->fieldIndex("id"));
    mapper->addMapping(edProfil, model->fieldIndex("id_profil"));
    mapper->addMapping(edPseudo, model->fieldIndex("pseudo"));
    mapper->addMapping(edCa, model->fieldIndex("ca"));
    mapper->addMapping(edPassWord, model->fieldIndex("mp"));
    mapper->addMapping(edEtat, model->fieldIndex("etat"));
    //mapper->setItemDelegate(new QSqlRelationalDelegate(edProfil));
    mapper->toFirst();
    actReadOnly(true);

    //Arrangement des boutons
    gridBoutton = new QGridLayout;
    gridBoutton->addWidget(btnPrev,  0,0);
    gridBoutton->addWidget(btnNext,  0,1);
    gridBoutton->addWidget(btnListe, 0,2);
    gridBoutton->addWidget(btnPrn,   0,3);
    gridBoutton->addWidget(btnNew,   1,0);
    gridBoutton->addWidget(btnUpdate,1,1);
    gridBoutton->addWidget(btnSave,  1,2);
    gridBoutton->addWidget(btnDelete,1,3);

    //Organisation générale du formulaire
    principalLayout = new QVBoxLayout;
    principalLayout->addWidget(lbTitre);
    principalLayout->addSpacing(20);
    principalLayout->addLayout(formSaisie);
    principalLayout->addSpacing(20);
    principalLayout->addLayout(gridBoutton);
    setLayout(principalLayout);

    //Mise en place des connexions pour les boutons
    connect(btnPrev, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(btnNext, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(btnListe, SIGNAL(clicked()), this, SLOT(actListe()));
    connect(btnPrn, SIGNAL(clicked()), this, SLOT(actPreview()));
    connect(btnNew, SIGNAL(clicked()), this, SLOT(addNewRecord()));
    connect(btnUpdate, SIGNAL(clicked()), this, SLOT(updateRecord()));
    connect(btnSave, SIGNAL(clicked()), this, SLOT(saveRecord()));
    connect(btnDelete, SIGNAL(clicked()), this, SLOT(deleteRecord()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
}//Utilisateur::Utilisateur(QWidget * parent) : QWidget(parent)

Utilisateur::~Utilisateur()
{
    this->destroy(true, true);
}

void Utilisateur::clearEditZone()
/*  But     : Effacer les zones de saisie
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    edId->clear();
    edProfil->clear();
    edCa->clear();
    edPseudo->clear();
    edPassWord->clear();
    edConfirmat->clear();
    edEtat->clear();
}//void Utilisateur::clearEditZone()


void Utilisateur::actReadOnly(bool etat)
/*  But     : Activer ou non le mode readOnly pour les zones de saisie
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    QPalette *paletteNorm = new QPalette();
    paletteNorm->setColor(QPalette::Base,QColor(252, 252, 252));

    edId->setReadOnly(true);
    //edProfil->setReadOnly(etat);
    edPseudo->setReadOnly(etat);
    edPseudo->setPalette(*paletteNorm);
    edCa->setPalette(*paletteNorm);
    edPassWord->setReadOnly(etat);
    edConfirmat->setReadOnly(etat);
    edEtat->setReadOnly(etat);
}//void Utilisateur::actReadOnly(bool etat)


void Utilisateur::refresh(QString currentValue)
/*  But     : Rafraîchir le formulaire de saisie
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Octobre
 */
{
    if(!currentValue.isNull()){
        QModelIndexList list = model->match(model->index(0,0), Qt::DisplayRole, QVariant(currentValue));
        int intNbTrouve = list.count();
        if ( intNbTrouve> 0){
            mapper->setCurrentIndex(list.at(0).row());
        }
    }
}//void Utilisateur::refresh(QString currentValue)

//----- Les slots --------

void Utilisateur::updateButtons(int row)
/*  But     : Actualiser les boutons sur le formulaire de Utilisateur
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    btnPrev->setEnabled(row > 0);
    btnNext->setEnabled(row < model->rowCount() - 1);
    btnUpdate->setEnabled(true);
    btnNew->setEnabled(true);
    btnSave->setEnabled(false);
    //    btnCancel->setEnabled(false);
} //void Utilisateur::updateButtons(int row)


void Utilisateur::addNewRecord()
/*  But     : Ajouter un nouvel enregistrement vierge
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    int row = model->rowCount();//mapper->currentIndex();
    //QMessageBox::information(this,"Test",QString::number(row));
    model->insertRow(row);
    mapper->setCurrentIndex(row);
    actReadOnly(false);
    clearEditZone();
    btnPrev->setEnabled(false);
    btnNext->setEnabled(false);
    btnSave->setEnabled(true);
    //    btnCancel->setEnabled(true);
    btnUpdate->setEnabled(false);
    edPseudo->setFocus();
} //void Utilisateur::addNewRecord()


void Utilisateur::updateRecord()
/*  But     : Activer la possibilité de modifier les données
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    actReadOnly(false);
    btnPrev->setEnabled(false);
    btnNext->setEnabled(false);
    btnSave->setEnabled(true);
    //    btnCancel->setEnabled(true);
    btnNew->setEnabled(false);
    edPseudo->setFocus();
} //void Utilisateur::actUpdate()


void Utilisateur::saveRecord()
/*  But     : Enregistrer dans la table les données courantes (ajoutées ou modifiées)
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    if(checkInputs()){
        int row = model->rowCount();
        int currIndex = mapper->currentIndex();
        model->database().transaction();
        if (model->submitAll()) {
            model->database().commit();
            mapper->submit();
            QString msg = "Opération effectuée avec succès";
            //Piste d'audit
            int recoId = model->record(currIndex).value(0).toInt();
            QSqlQuery qry;
            qry.prepare("UPDATE Utilisateurs SET pa1=? WHERE id=?");
            qry.addBindValue(Fonctions::getUserId());
            qry.addBindValue(recoId);
            if(qry.exec()){
                msg.append(" et signée !");
            }else{
                msg.append(" non signée !");
            }
            QMessageBox::information(this,"Exécution", msg);
        } else {
            model->removeRow(row);
            mapper->setCurrentIndex(row-1);
            model->database().rollback();
            QMessageBox::warning(this, tr("Cached Table"),
                                 tr("The database reported an error: %1")
                                     .arg(model->lastError().text()));
        }
        actReadOnly(true);
        //mapper->toFirst();
        mapper->setCurrentIndex(currIndex);
    }
} //void Utilisateur::saveRecord()


void Utilisateur::actListe()
/*  But     : Activer l'affichage de la liste
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    ListeUtilisateur *liste = new ListeUtilisateur();
    liste->setWindowModality(Qt::ApplicationModal);
    liste->setParent(this, Qt::Window);
    liste->showNormal();
    liste->activateWindow();
} //void Utilisateur::actListe()


void Utilisateur::deleteRecord()
/*  But     : Supprimer l'enregistrement courant
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Septembre
 */
{
    int rep = QMessageBox::question(this,"Suppression"," Voulez vous vraiment supprimer le Utilisateur en cours ?");
    if(rep == QMessageBox::Yes)
    {
        int row = mapper->currentIndex();
        model->removeRow(row);
        mapper->setCurrentIndex(row);
        saveRecord();
        mapper->toFirst();
    }
}//void Utilisateur::deleteRecord()


void Utilisateur::actPreview()
/*  But     : Activer l'aperçu avant impression
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Octobre
 */
{
    QPrintPreviewDialog * edition = new QPrintPreviewDialog(this);
    connect(edition, SIGNAL(paintRequested(QPrinter *)), this, SLOT(prnListe(QPrinter *)));
    edition->exec();
}//void Utilisateur::actPreview()


void Utilisateur::prnListe(QPrinter * printer)
/*  But     : Remplir les pages d'impression de la liste des Utilisateur
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 octobre
 */
{
 /*   QString phL1;
    bool pageStatus;
    QPainter * painter = new QPainter(printer);
    painter->setFont(QFont("Georgia", 7, QFont::Bold));

    qreal pageWidth = printer->pageRect(QPrinter::DevicePixel).width();
    qreal pageHeight = printer->pageRect(QPrinter::DevicePixel).height();
    int letterWidth = painter->fontMetrics().maxWidth()*0.50;//Ajustement avec 50%
    int letterHeight = painter->fontMetrics().height();
    int intColPadding = letterWidth * 1;
    //QMessageBox::warning(this, tr("Test"), QString::number(pageWidth)+"/"+QString::number(pageHeight));
    //QMessageBox::warning(this, tr("Test"), QString::number(letterWidth)+"/"+QString::number(letterHeight));
    QList<recField*> lstField;// un recField = {QString name, int length, int position)
    lstField.append(new recField("id", 3, 0));
    lstField.append(new recField("id_profil", 6, 0));
    lstField.append(new recField("pseudo", 25, 0));
    lstField.append(new recField("ca", 25, 0));
    lstField.append(new recField("mp", 50, 0));
    lstField.append(new recField("etat", 5, 0));
    int nbField = lstField.size();
    //Calcul et fixation de la position de chaque field
    lstField[0]->pos = 1;
    for(int i=1; i<nbField; i++){
        lstField[i]->pos = lstField[i-1]->pos + intColPadding + lstField[i-1]->len * letterWidth;
        //QMessageBox::warning(this, tr("Test"), QString::number(lstField[i]->pos));
    }
    //Calcul de la largeur réelle des lignes
    int intLineWidthRequired = lstField[nbField-1]->pos + lstField[nbField-1]->len * letterWidth;
    //Calcul de la marge gauche des pages
    int intMargin = (pageWidth - intLineWidthRequired)/2;
    //Ajustement de la position de chaque field
    for(int i=0; i<nbField; i++){
        lstField[i]->pos += intMargin;
    }
    //QMessageBox::warning(this, tr("Test"), QString::number(intLineWiddthRequired)+"/"+QString::number(intMargin));

    QSqlQuery *query = new QSqlQuery;
    QString qryTxt = QString("SELECT * FROM users");
    query->prepare(qryTxt);
    query->exec();
    if (query->isActive()){
        QSqlRecord record = query->record();
        int nuPage = 0;
        query->next();
        pageStatus = true;
        //========== Début Boucle pour la liste
        while(pageStatus){
            nuPage++;
            int intLineNumb  = 10;
            int intLineSpace = letterHeight;
            int intPageFootHeight = pageFoot(painter)*letterHeight;
            painter->drawText(10, intLineNumb, "En-tête");
            //            intLineNumb += intLineSpace;
            //            painter->drawText(10, intLineNumb, phL1);
            intLineNumb += intLineSpace*2;
            QString ttr = "Liste des Utilisateur";
            int intCol = (pageWidth - letterWidth*ttr.length())/2;
            painter->drawText(intCol, intLineNumb, ttr);
            intLineNumb += intLineSpace;
            //========== Début Boucle pour une page
            while(pageStatus && intLineNumb<pageHeight-intPageFootHeight){
                for(int i=0; i<nbField; i++){
                    painter->drawText(lstField[i]->pos,intLineNumb,
                                      query->value(record.indexOf(lstField[i]->name)).toString());
                }
                query->next();
                pageStatus = query->isValid();
                intLineNumb += intLineSpace;
            }//while(query->next() && intLineNumb<pageHeight-intPageFoot)
            //========== Fin Boucle pour une page
            //La fonction suivante est définie dans utilitaire.cpp
            pageFoot(painter, pageWidth, pageHeight, letterWidth, letterHeight, nuPage, !pageStatus );
            if(pageStatus){
                printer->newPage();
            }
        }//while(query->next())
        //========== Fin Boucle pour la liste
        painter->end();
    }else{//if (query->isActive())
        QMessageBox::warning(this, tr("Database Error"), query->lastError().text());
    }//if (query->isActive())
    delete query;*/
}//End of void Utilisateur::prnListe(QPrinter * printer)


void Utilisateur::close()
/*  But     : Fermer la fenêtre de Mise A Jour des Utilisateur
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Octobre
 */
{
    //this->destroy(true, true);
    //this->close();
}//void Utilisateur::close()


bool Utilisateur::checkInputs()
/*  But     : Contrôler les saisies avant de les enregistrer
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2024 février
 */
{
    bool rnv(true);
    QPalette *paletteError = new QPalette();
    QPalette *paletteValid = new QPalette();
    paletteError->setColor(QPalette::Base,QColor(252, 150, 100));
    paletteValid->setColor(QPalette::Base,QColor(3, 252, 69));
    //edId->setReadOnly(true);
    if(edPseudo->text().isEmpty())
    {
        edPseudo->setPalette(*paletteError);
        rnv = false;
    }else{
        edPseudo->setPalette(*paletteValid);
    }
    if(edCa->text().isEmpty())
    {
        edCa->setPalette(*paletteError);
        rnv = false;
    }else{
        edCa->setPalette(*paletteValid);
    }
    /*edPrenoms->setReadOnly(etat);
    edAdresse->setReadOnly(etat);
    edTelephone1->setReadOnly(etat);
    edTelephone2->setReadOnly(etat);
    edDebutLivraison->setReadOnly(true);*/
    return rnv;
}//void Utilisateur::checkInputs()


void Utilisateur::showCurrProfil(int currentIndex)
{
    model->setFilter(QString("id_profil = %1").arg(currentIndex));
}
