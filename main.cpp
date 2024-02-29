
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

#include "utilisateur.h"
#include "fonctions.h"
#include "utilisateur.h"

bool dbConnection();

int main(int argc, char *argv[])
{
    int finApplication = 0;
    QApplication app(argc, argv);

    if (Fonctions::dbConnection()){
        Utilisateur *win = new Utilisateur;
        win->showMaximized();
        finApplication = app.exec();
    }
    return finApplication;
}
