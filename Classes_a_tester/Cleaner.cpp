/*************************************************************************
                           Cleaner  -  AttributeID
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
//------------------------------------------------------ Include personnel
#include "Cleaner.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Cleaner::GetCleanerID(){
    return cleanerID;
}

float Cleaner::GetLatitude(){
    return latitude;
}
float Cleaner::GetLongitude(){
    return longitude;
}

string Cleaner::GetTimestampStart(){
    return timestampStart;
}

string Cleaner::GetTimestampStop(){
    return timestampStop;
}

void Cleaner::AfficherCleaner(){
    cout << "CleanerID : " << cleanerID << endl;
    cout << "Latitude : " << latitude << endl;
    cout << "Longitude : " << longitude << endl;
    cout << "TimeStamp(start) : " << timestampStart << endl;
    cout << "TimeStamp(stop) : " << timestampStop << endl;
}

// type Cleaner::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif

cleanerID = unCleaner.cleanerID;
latitude = unCleaner.latitude;
longitude = unCleaner.longitude;
timestampStart = unCleaner.timestampStart;
timestampStop = unCleaner.timestampStop;
} //----- Fin de Cleaner (constructeur de copie)


Cleaner::Cleaner ( string OneCleaner)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
// Séparation de la chaine Cleaner en sous-chaînes
    size_t debutCleanerID = 0 ;
    size_t finCleanerID = OneCleaner.find_first_of(';');

    size_t debutLatitude = finCleanerID + 1;
    size_t finLatitude = OneCleaner.find(';', debutLatitude);

    size_t debutLongitude = finLatitude + 1;
    size_t finLongitude = OneCleaner.find(';', debutLongitude);

    size_t debutStart = finLongitude+1;
    size_t finStart = OneCleaner.find(';',debutStart);

    size_t debutStop = finStart+1;
    size_t finStop = OneCleaner.find(';',debutStop);

    // Extraction des sous-chaînes
    cleanerID = OneCleaner.substr(debutCleanerID, finCleanerID - debutCleanerID);
    latitude = stof(OneCleaner.substr(debutLatitude, finLatitude - debutLatitude));
    longitude = stof(OneCleaner.substr(debutLongitude, finLongitude - debutLongitude));
    timestampStart = OneCleaner.substr(debutStart, finStart - debutStart);
    timestampStop = OneCleaner.substr(debutStop, finStop - debutStop);
} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées