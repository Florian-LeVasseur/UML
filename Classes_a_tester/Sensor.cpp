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

string Sensor::GetSensor(){
    return sensor;
}

string Sensor::GetSensorID(){
    return sensorID;
}

float Sensor::GetLatitude(){
    return latitude;
}
float Sensor::GetLongitude(){
    return longitude;
}

void Sensor::AnalyserSensor(){

    // Séparation de la chaine Sensor en sous-chaînes
    size_t debutSensorID = 0;
    size_t finSensorID = sensor.find_first_of(';');

    size_t debutLatitude = finSensorID + 1;
    size_t finLatitude = sensor.find(';', debutLatitude);

    size_t debutLongitude = finLatitude + 1;
    size_t finLongitude = sensor.find_last_of(';');

    // Extraction des sous-chaînes
    sensorID = sensor.substr(debutSensorID, finSensorID - debutSensorID);
    latitude = stof(sensor.substr(debutLatitude, finLatitude - debutLatitude));
    longitude = stof(sensor.substr(debutLongitude, finLongitude - debutLongitude));
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
} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor ( string nomSensor)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
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