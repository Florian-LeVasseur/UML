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
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
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
    bool updateReliability(string UserId, bool isreliable);
    bool checkIfEfficient(string cleanerId);
    vector <Measurement> SensorDataPrivateUser(string UserId);
    bool checkIfReliable(string userID, string timeStart, string timeStop);
    
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
time_t stringToTimeT(string& dateStr);

bool compareDates(time_t date1, time_t date2);
vector<Measurement> getMeasurementsBetweenDates(vector<Measurement> Measurements, string sensorName, string attributeID, time_t startDate, time_t endDate);
vector<Sensor> sortSensorsByDistance( vector<Sensor> sensors,  Cleaner cleaner);
float CalculateAtmoIndex (float O3, float NO2, float SO2, float PM10);

//----------------------------------------------------- Attributs protégés
Database* db;
};
//-------------------------------- Autres définitions dépendantes de <Controler>

#endif // XXX_H

