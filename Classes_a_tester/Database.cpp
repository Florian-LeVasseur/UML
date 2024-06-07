/*************************************************************************
                           Database  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Database> (fichier Database.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "Database.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Sensor> Database::GetSensors(){
    return sensors ;
}

vector<Measurement> Database::GetMeasurements(){
    return measurements ;
}

vector<Attribute> Database::GetAttributes(){
    return attributes ;
}

vector<Cleaner> Database::GetCleaners(){
    return cleaners ;
}

vector<PrivateIndividual> Database::GetPrivateIndivs(){
    return privateIndivs ;
}

vector<Provider> Database::GetProviders(){
    return providers ;
}



//-------------------------------------------- Constructeurs - destructeur
Database::Database ( const Database & unDatabase )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Database>" << endl;
#endif
} //----- Fin de Database (constructeur de copie)


Database::Database (string nomFichierSensor, string nomFichierMeasurement, string nomFichierAttribute, string nomFichierCleaner, string nomFichierUser, string nomFichierProvider)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Database>" << endl;
#endif
//création du tableau de Sensors
ifstream fic ( nomFichierSensor );
     // Vérification si l'ouverture du fichier a réussi
    if (fic.is_open()) {
        string maligne;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fic, maligne)) {
            Sensor sensor(maligne);
            sensors.push_back(sensor);
            sensor.AfficherSensor();
        }
        // Fermer le fichier après la Database
        fic.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier : " << nomFichierSensor << endl;
    }

//création du tableau de Measurements
ifstream fich ( nomFichierMeasurement );
     // Vérification si l'ouverture du fichier a réussi
    if (fich.is_open()) {
        string maligne;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fich, maligne)) {
            Measurement measurement(maligne);
            measurements.push_back(measurement);
        }
        // Fermer le fichier après la Database
        fich.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier : " << nomFichierMeasurement << endl;
    }

//création du tableau de Attributes
ifstream fichi ( nomFichierAttribute );
     // Vérification si l'ouverture du fichier a réussi
    if (fichi.is_open()) {
        string maligne;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichi, maligne)) {
            Attribute attribute(maligne);
            attributes.push_back(attribute);
        }
        // Fermer le fichier après la Database
        fichi.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier : " << nomFichierAttribute << endl;
    }

    //création du tableau de Cleaners
ifstream fichie ( nomFichierCleaner );
     // Vérification si l'ouverture du fichier a réussi
    if (fichie.is_open()) {
        string maligne;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichie, maligne)) {
            Cleaner cleaner(maligne);
            cleaners.push_back(cleaner);
        }
        // Fermer le fichier après la Database
        fichie.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier : " << nomFichierCleaner << endl;
    }

//création du tableau de Users
ifstream fichier ( nomFichierUser );
     // Vérification si l'ouverture du fichier a réussi
    if (fichier.is_open()) {
        string maligne;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichier, maligne)) {
            PrivateIndividual privateIndiv(maligne);
            cout<< "UserID : "<<privateIndiv.GetUserID()<<endl;
            privateIndiv.AfficherPrivateIndividual();
            privateIndivs.push_back(privateIndiv);
        }
        // Fermer le fichier après la Database
        fichier.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier : " << nomFichierUser << endl;
    }

//création du tableau de Providers
ifstream fichiers ( nomFichierProvider );
     // Vérification si l'ouverture du fichier a réussi
    if (fichiers.is_open()) {
        string maligne;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichiers, maligne)) {
            Provider provider(maligne);
            providers.push_back(provider);
        }
        // Fermer le fichier après la Database
        fichiers.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier : " << nomFichierProvider << endl;
    }

} //----- Fin de Database

Database::~Database ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Database>" << endl;
#endif
} //----- Fin de ~Database


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées