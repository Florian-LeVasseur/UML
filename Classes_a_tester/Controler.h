/*************************************************************************
                           Controler  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Controler> (fichier Controler.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------TRAJET------------------- Interfaces utilisées
#include "Database.h"
//#include "TrajetCompose.h" (à mettre dans le make file aussi) + ajouter des const à son constr sur dep et arr
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controler>
//
//
//------------------------------------------------------------------------

class Controler
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void createDb();
    Database* getDb();

    int askPoint(string providerId);
    int askMeanSensor(string sensorId);
    
//-------------------------------------------- Constructeurs - destructeur

    
    Controler ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controler ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
Database* db;
};
//-------------------------------- Autres définitions dépendantes de <Controler>

#endif // XXX_H

