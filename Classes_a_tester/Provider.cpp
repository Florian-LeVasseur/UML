/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
***************************Provider*********************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

//------------------------------------------------------ Include personnel
#include "Provider.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Provider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Provider::GetProvider(){
    return provider;
}

string Provider::GetProviderID(){
    return providerID;
}

string Provider::GetCleanerID(){
    return cleanerID;
}

void Provider::AnalyserProvider(){

    // Séparation de la chaine Provider en sous-chaînes
    size_t debutProviderID = 0;
    size_t finProviderID = provider.find_first_of(';');

    size_t debutCleanerID = finProviderID + 1;
    size_t finCleanerID = provider.find_last_of(';');

    // Extraction des sous-chaînes
    providerID = provider.substr(debutProviderID, finProviderID - debutProviderID);
    cleanerID = provider.substr(debutCleanerID, finCleanerID - debutCleanerID);
}

void Provider::AfficherProvider(){
    cout << "ProviderID : " << providerID << endl;
    cout << "CleanerID : " << cleanerID << endl;
}

//-------------------------------------------- Constructeurs - destructeur


Provider::Provider (string log,string pwd,string id):User(log,pwd), providerID(id)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider

Provider::Provider (string NomProvider)
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif 
}

Provider::~Provider ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
