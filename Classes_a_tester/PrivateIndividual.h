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

    string GetPrivateIndividual();
    string GetUserID();
    string GetSensorID();

    void AnalyserPrivateIndividual();
    void AfficherPrivateIndividual();

    int getFidelityPoints();
    bool getReliability();
//-------------------------------------------- Constructeurs - destructeur
    PrivateIndividual (string log, string pwd, string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateIndividual (string monUser);
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

string privateIndividual;

int fidelityPoints;
bool reliability;
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <PrivateIndividual>

#endif // XXX_H

