/*  Name    : Fonctions.h
 *  Purpose : Déclaration attributs et prototypes classe Fonctions
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2024 février
 */
#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>

class Fonctions
{
private:
    static int userId;
    static QString userPseudo;
    static int idProfil;
    static QString lbProfil;
public:
    Fonctions();
    static QString* getParametres();
    static bool dbConnection();
    static void setUser(int, QString, int);
    static void setLbProfil(QString);
    static int getUserId();
    static QString getUserPseudo();
    static int getIdProfil();
    static QString getLbProfil();
};

#endif // FONCTIONS_H
