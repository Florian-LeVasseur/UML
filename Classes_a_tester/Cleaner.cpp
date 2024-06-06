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

string Cleaner::GetCleaner(){
    return cleaner;
}

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



void Cleaner::AnalyserCleaner(){

    // Séparation de la chaine Cleaner en sous-chaînes
    size_t debutCleanerID = 0 ;
    size_t finCleanerID = cleaner.find_first_of(';');

    size_t debutLatitude = finCleanerID + 1;
    size_t finLatitude = cleaner.find(';', debutLatitude);

    size_t debutLongitude = finLatitude + 1;
    size_t finLongitude = cleaner.find(';', debutLongitude);

    size_t debutStart = finLongitude+1;
    size_t finStart = cleaner.find(';',debutStart);

    size_t debutStop = finStart+1;
    size_t finStop = cleaner.find(';',debutStop);

    // Extraction des sous-chaînes
    cleanerID = cleaner.substr(debutCleanerID, finCleanerID - debutCleanerID);
    latitude = stof(cleaner.substr(debutLatitude, finLatitude - debutLatitude));
    longitude = stof(cleaner.substr(debutLongitude, finLongitude - debutLongitude));
    timestampStart = cleaner.substr(debutStart, finStart - debutStart);
    timestampStop = cleaner.substr(debutStop, finStop - debutStop);
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
} //----- Fin de Cleaner (constructeur de copie)


Cleaner::Cleaner ( string nomFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
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