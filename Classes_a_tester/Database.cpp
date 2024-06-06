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


/*void Database::AfficherTableau(int debut, int fin){
    int i = debut-1 ;
    for(i;i<fin;i++){
        Ligne a = tableau[i];
        a.AnalyserLigne();
        cout << "Voici la " << i+1 << "ieme ligne du fichier" << endl;
        a.AfficherLigne();
    }

} */

// type Database::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



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
        string sensor;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fic, sensor)) {
            Sensor maligne(sensor);
            maligne.AnalyserSensor();
            maligne.AfficherSensor();
            sensors.push_back(maligne);
            cerr << maligne.GetSensor() << endl ;
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
        string measurement;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fich, measurement)) {
            Measurement maligne(measurement);
            maligne.AnalyserMeasurement();
            maligne.AfficherMeasurement();
            measurements.push_back(maligne);
            cerr << maligne.GetMeasurement() << endl ;
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
        string attribute;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichi, attribute)) {
            Attribute maligne(attribute);
            maligne.AnalyserAttribute();
            maligne.AfficherAttribute();
            attributes.push_back(maligne);
            cerr << maligne.GetAttribute() << endl ;
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
        string cleaner;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichie, cleaner)) {
            Cleaner maligne(cleaner);
            maligne.AnalyserCleaner();
            maligne.AfficherCleaner();
            cleaners.push_back(maligne);
            cerr << maligne.GetCleaner() << endl ;
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
        string user;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichier, user)) {    //faut récuperer sensor id là nan ?
            PrivateIndividual maligne(user,"toto",user);
            maligne.AnalyserPrivateIndividual();
            maligne.AfficherPrivateIndividual();
            privateIndivs.push_back(maligne);
            cerr << maligne.GetPrivateIndividual() << endl ;
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
        string provider;
        // Lire le fichier ligne par ligne jusqu'à la fin du fichier
        while (getline(fichiers, provider)) {
            Provider maligne(provider);
            maligne.AnalyserProvider();
            maligne.AfficherProvider();
            providers.push_back(maligne);
            cerr << maligne.GetProvider() << endl ;
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