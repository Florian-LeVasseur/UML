/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if ! defined ( Measurement_H )
#define Measurement_H


//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip> 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
//
//------------------------------------------------------------------------

class Measurement 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
string GetTimestamp();
string GetSensorID();
string GetAttributeID();
float GetValue();
time_t GetDate();

void AfficherMeasurement();

//------------------------------------------------- Surcharge d'opérateurs
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Measurement ( const Measurement & unMeasurement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measurement (string OneMeasurement);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measurement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
time_t stringToTimeT(string& dateStr);
//----------------------------------------------------- Attributs protégés

string timestamp;
string sensorID;
string attributeID;
float value;
time_t date;



};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // Measurement_H