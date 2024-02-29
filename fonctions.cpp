/*  Name    : fonctions.cpp
 *  Purpose : Définitions des méthode classe Fonctions
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2015 septembre
 */
#include "fonctions.h"

Fonctions::Fonctions() {

}

QString Fonctions::userPseudo;
int Fonctions::userId;
int Fonctions::idProfil;
QString Fonctions::lbProfil;

QString *Fonctions::getParametres(){
    QString *tabParam = new QString[5];
    tabParam[0] = "hostname:";
    tabParam[1] = "username:";
    tabParam[2] = "password:";
    tabParam[3] = "port:";
    tabParam[4] = "dbname:";
    QString ligne;
    QFile file("param.cfg");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr, "Erreur", "Configuration de base manquante !");
        tabParam = nullptr;
    }else{
        QTextStream learner(&file);
        int i=0;
        while(! learner.atEnd() && i < 5) {
            ligne = learner.readLine();
            tabParam[i] = ligne.mid(tabParam[i].size());
            i++;
        }
        file.close();
    }
    return tabParam;
}   //QString *Fonctions::getParametres()


bool Fonctions::dbConnection(){
    /* But : Etablir la connexion à la base de données
 * Renvoi : TRUE si la connexion a réussi, sinon FALSE
 * */
    bool bReturn;//Variable pour valeur de retour
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    /*QString *tabCon = Fonctions::getParametres();
    if (tabCon == nullptr) {
        //writeInFile(fonctions::getNomLogFile(),"Erreur de connexion à la DB, fichier de connexion non trouvé");
        //QMessageBox::critical(0, "Database Error", "Erreur d'ouverture du fichier de configuration");
        bReturn = false;
    } else {*/
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("toor");
        db.setPort(3306);
        db.setDatabaseName("samrestau");
        if (db.open()){
            QString msg;
            QSqlDriver *driver = QSqlDatabase::database().driver();
            if (driver->hasFeature(QSqlDriver::Transactions)){
                msg = "SGBD transactionnel !";
            }else{
                msg = "SGBD non transactionnel !";
            }
            //QMessageBox::information(0, "Database status", msg);
            bReturn=true;
        }else{
            //fonctions::writeInFile(fonctions::getNomLogFile(),"Erreur de connexion à la DB : "+db.lastError().text());
            QMessageBox::information(0, "Database Error", db.lastError().text()+" veuillez vérifier la configuration puis réessayer SVP");
            bReturn=false;
        }
    //}
    return bReturn;
} //bool Fonctions::dbConnection()


void Fonctions::setUser(int id, QString pseudo, int nuProfil){
    /* But : Conserver l'identité de l'utilisateur
 * Renvoi :  Néant
 * */
    userId = id;
    userPseudo = pseudo;
    idProfil = nuProfil;
} //void Fonctions::setUser(int id, QString pseudo){


void Fonctions::setLbProfil(QString lbProf){
    /* But : Conserver le lbProfil de l'utilisateur connecté
 * Renvoi :  Néant
 * */
    lbProfil = lbProf;
} //void Fonctions::setLbProfil(int id, QString pseudo){


int Fonctions::getUserId(){
    /* But   : Fournir l'id de l'utilisateur connecté
* Renvoi :  userId
* Date   : 2024/02/22
* */
    return userId;
} //int Fonctions::getUserId()


QString Fonctions::getUserPseudo(){
    /* But    : Fournir le pseudo de l'utilisateur connecté
 * Renvoi : userPseudo
 * Date   : 2024/02/22
 * */
    return userPseudo;
} //QString Fonctions::getUserPseudo()


int Fonctions::getIdProfil(){
    /* But   : Fournir l'idProfil de l'utilisateur connecté
* Renvoi :  idProfil
* Date   : 2024/02/24
* */
    return idProfil;
} //int Fonctions::getIdProfil()


QString Fonctions::getLbProfil(){
    /* But    : Fournir le lbProfil de l'utilisateur connecté
 * Renvoi : userPseudo
 * Date   : 2024/02/24
 * */
    return lbProfil;
} //QString Fonctions::getLbProfil()
