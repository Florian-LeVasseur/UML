/*************************************************************************
                           Database  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Database> (fichier Database.h) ----------------
#if ! defined ( Database_H )
#define Database_H


//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <vector>

#include "Sensor.h"
#include "Measurement.h"
#include "Attribute.h"
#include "Cleaner.h"
#include "PrivateIndividual.h"
#include "Provider.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Database>
//
//
//------------------------------------------------------------------------

class Database 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
//void AfficherTableau(int debut, int fin);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

vector<Sensor> GetSensors();
vector<Measurement> GetMeasurements();
vector<Attribute> GetAttributes();
vector<Cleaner> GetCleaners();
vector<PrivateIndividual> GetPrivateIndivs();
vector<Provider> GetProviders();

//------------------------------------------------- Surcharge d'opérateurs
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Database ( const Database & unDatabase );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Database (string nomFichierSensor, string nomFichierMeasurement, string nomFichierAttribute, string nomFichierCleaner, string nomFichierUser, string nomFichierProvider);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Database ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

vector<Sensor> sensors;
vector<Measurement> measurements;
vector<Attribute> attributes;
vector<Cleaner> cleaners;
vector<PrivateIndividual> privateIndivs;
vector<Provider> providers;

};

//-------------------------------- Autres définitions dépendantes de <Database>

#endif // Database_H
