/*************************************************************************
                           Measurement  -  AttributeID
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
//------------------------------------------------------ Include personnel
#include "Measurement.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Measurement::GetTimestamp(){
    return timestamp;
}

string Measurement::GetSensorID(){
    return sensorID;
}

string Measurement::GetAttributeID(){
    return attributeID;
}
float Measurement::GetValue(){
    return value;
}

time_t Measurement::GetDate(){
    return date;
}


void Measurement::AfficherMeasurement(){
    cout << "TimeStamp : " << timestamp << endl;
    cout << "SensorID : " << sensorID << endl;
    cout << "AttributeID : " << attributeID << endl;
    cout << "Value : " << value << endl;
}

// type Measurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement ( const Measurement & unMeasurement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif

timestamp = unMeasurement.timestamp;
sensorID = unMeasurement.sensorID;
attributeID = unMeasurement.attributeID;
value = unMeasurement.value;
date = unMeasurement.date;
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement ( string OneMeasurement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
// Séparation de la chaine Measurement en sous-chaînes
    size_t debutDate = 0;
    size_t finDate = OneMeasurement.find_first_of(';');

    size_t debutSensorID = finDate + 1;
    size_t finSensorID = OneMeasurement.find(';', debutSensorID);

    size_t debutAttributeID = finSensorID + 1;
    size_t finAttributeID = OneMeasurement.find(';',debutAttributeID);

    size_t debutValue= finAttributeID + 1;
    size_t finValue = OneMeasurement.find_last_of(';');

    size_t debutTime = 0 ;
    size_t finTime = OneMeasurement.find_first_of(' ');

    // Extraction des sous-chaînes
    timestamp = OneMeasurement.substr(debutDate, finDate - debutDate);
    sensorID = OneMeasurement.substr(debutSensorID, finSensorID - debutSensorID);
    attributeID = OneMeasurement.substr(debutAttributeID, finAttributeID - debutAttributeID);
    value = stof(OneMeasurement.substr(debutValue, finValue - debutValue));
    string date_phrase = OneMeasurement.substr(debutTime, finTime - debutTime);

    date = stringToTimeT(date_phrase);
} //----- Fin de Measurement


Measurement::~Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
time_t Measurement::stringToTimeT(string& dateStr) {
    // Structure pour stocker la date et l'heure
    tm tm = {};
    istringstream ss(dateStr);
    
    // Lecture du string dans la structure tm
    ss >> std::get_time(&tm, "%Y-%m-%d");
    
    // Vérification si la lecture a réussi
    if (ss.fail()) {
        throw std::runtime_error("Échec de la conversion du string en std::tm");
    }
    
    // Conversion de std::tm en time_t
    time_t time = mktime(&tm);
    if (time == -1) {
        throw runtime_error("Échec de la conversion de tm en time_t");
    }
    
    return time;
}