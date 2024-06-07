/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------TRAJET------------------- Interfaces utilisées
#include "User.h" 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//------------------------------------------------------------------------

class Provider : public User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    
    string GetProviderID();
    string GetCleanerID();

    void AfficherProvider();
//-------------------------------------------- Constructeurs - destructeur
    Provider (string log, string pwd, string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Provider (string OneProvider);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Provider ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string providerID ;
string cleanerID;

//-------------------------------- Autres définitions dépendantes de <Provider>
};
#endif // XXX_H

