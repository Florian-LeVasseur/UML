/*************************************************************************
                           PrivateIndividual  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <PrivateIndividual> (fichier PrivateIndividual.h) ----------------
#if ! defined ( PRIVATEINDIVIDUAL_H )
#define PRIVATEINDIVIDUAL_H

//--------------------------------TRAJET------------------- Interfaces utilisées
#include "User.h" 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateIndividual>
//
//
//------------------------------------------------------------------------

class PrivateIndividual : public User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :

    string GetUserID();
    string GetSensorID();

    void AfficherPrivateIndividual();
    void setReliability(bool update);
    int getFidelityPoints();
    bool getReliability();
//-------------------------------------------- Constructeurs - destructeur

    PrivateIndividual (const PrivateIndividual & unPrivateIndividual);

    PrivateIndividual (string UnPrivateIndividual);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PrivateIndividual ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
string userID;
string sensorID;

int fidelityPoints;
bool reliability;
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <PrivateIndividual>

#endif // XXX_H

