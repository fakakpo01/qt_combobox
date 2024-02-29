/*  Name    : utilitaire.cpp
 *  Purpose : Définitions des méthode classe Utilitaire
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2015 septembre
 */
#include <QtSql/QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QDateTime>

bool dbConnection(){
 /*But : Etablir la connexion à la base de données
 * Renvoi : TRUE si la connexion a réussi, sinon FALSE
 * */
    bool bReturn;//Variable pour valeur de retour
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("toor");
    db.setPort(3306);
    db.setDatabaseName("c_qt_sql");
    if (db.open()){
        QMessageBox::information(0,"Information", "Vous êtes maintenant connecté !");
        bReturn=true;
        QString msg;
        QSqlDriver *driver = QSqlDatabase::database().driver();
        if (driver->hasFeature(QSqlDriver::Transactions)){
            msg = "SGBD transactionnel !";
        }else{
            msg = "SGBD on transactionnel !";
        }
        QMessageBox::information(0, "Database status", msg);
    }else{
        QMessageBox::critical(0, "Database Error", db.lastError().text());
        bReturn=false;
    }


    return bReturn;
}// End func dbConnection()


int pageFoot(QPainter * painter, int pageWidth, int pageHeight,
             int letterWidth, int letterHeight, int nuPage, bool status){
/*  But : Imprimer le pied de page général
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 octobre
 * */
    int nbFootLine = 3;//Nombre de lignes occupées par le pied de page
    if(pageWidth != 0){
        QDateTime dJour = QDateTime::currentDateTime();
        QString txtPage = QString("Référence : ADMM version 1.5 %1 Page %2").
                arg(dJour.toString("dd/MM/yyyy h:m:ss")).arg(nuPage, 3, 10, QChar('0'));
        txtPage += (status ? " <=":" =>");
        int intX = (pageWidth - txtPage.length()*letterWidth)/2;
        int intY = pageHeight - letterHeight*(nbFootLine-1);
        painter->drawText(intX, intY, txtPage);
    }
    return nbFootLine;
}

