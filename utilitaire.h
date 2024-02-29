/*  Name    : utilitaire.h
 *  Purpose : Déclaration attributs et prototypes classe Utilitaire
 *  Authors : Equipe Les IT-DIS
 *  Date    : 2024 février
 */
#ifndef UTILITAIRE_H
#define UTILITAIRE_H
#include <QString>
#include <QPainter>

struct recField {
    QString name;
    int len;
    int pos;
    recField(QString xName, int xLen, int xPos){
        name = xName;
        len = xLen;
        pos = xPos;
    }
};


int pageFoot(QPainter *painter=0, int pageWidth=0, int pageHeight=0,
             int letterWidth=0, int letterHeigh=0, int nuPage=0, bool status=false);

//int pageFoot();

#endif // UTILITAIRE_H

