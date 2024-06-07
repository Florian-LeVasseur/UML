/*************************************************************************
                           Sensor  -  Longitude
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
//------------------------------------------------------ Include personnel
#include "Sensor.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Sensor::GetSensorID(){
    return sensorID;
}

float Sensor::GetLatitude(){
    return latitude;
}
float Sensor::GetLongitude(){
    return longitude;
}

void Sensor::AfficherSensor(){
    cout << "SensorID : " << sensorID << endl;
    cout << "Latitude : " << latitude << endl;
    cout << "Longitude : " << longitude << endl;
}

// type Sensor::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
sensorID = unSensor.sensorID;
latitude = unSensor.latitude;
longitude = unSensor.longitude;

} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor ( string OneSensor)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
// Séparation de la chaine Sensor en sous-chaînes
    size_t debutSensorID = 0;
    size_t finSensorID = OneSensor.find_first_of(';');

    size_t debutLatitude = finSensorID + 1;
    size_t finLatitude = OneSensor.find(';', debutLatitude);

    size_t debutLongitude = finLatitude + 1;
    size_t finLongitude = OneSensor.find_last_of(';');

    // Extraction des sous-chaînes
    sensorID = OneSensor.substr(debutSensorID, finSensorID - debutSensorID);
    latitude = stof(OneSensor.substr(debutLatitude, finLatitude - debutLatitude));
    longitude = stof(OneSensor.substr(debutLongitude, finLongitude - debutLongitude));
} //----- Fin de Sensor


Sensor::~Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées