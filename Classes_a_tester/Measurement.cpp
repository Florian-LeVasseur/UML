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
//------------------------------------------------------ Include personnel
#include "Measurement.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Measurement::GetMeasurement(){
    return measurement;
}

string Measurement::GetTimestamp(){
    return timestamp;
}

string Measurement::GetSensorID(){
    return sensorID;
}

string Measurement::GetAttributeID(){
    return attributeID;
}
string Measurement::GetValue(){
    return value;
}

void Measurement::AnalyserMeasurement(){

    // Séparation de la chaine Measurement en sous-chaînes
    size_t debutDate = 0;
    size_t finDate = measurement.find_first_of(';');

    size_t debutSensorID = finDate + 1;
    size_t finSensorID = measurement.find(';', debutSensorID);

    size_t debutAttributeID = finSensorID + 1;
    size_t finAttributeID = measurement.find(';',debutAttributeID);

    size_t debutValue= finAttributeID + 1;
    size_t finValue = measurement.find_last_of(';');

    // Extraction des sous-chaînes
    timestamp = measurement.substr(debutDate, finDate - debutDate);
    sensorID = measurement.substr(debutSensorID, finSensorID - debutSensorID);
    attributeID = measurement.substr(debutAttributeID, finAttributeID - debutAttributeID);
    value = measurement.substr(debutValue, finValue - debutValue);
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
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement ( string nomFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
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