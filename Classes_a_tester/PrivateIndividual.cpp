/*************************************************************************
                           PrivateIndividual  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
***************************PrivateIndividual*********************************************/

//---------- Réalisation de la classe <PrivateIndividual> (fichier PrivateIndividual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

//------------------------------------------------------ Include personnel
#include "PrivateIndividual.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PrivateIndividual::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string PrivateIndividual::GetPrivateIndividual(){
    return privateIndividual;
}

string PrivateIndividual::GetUserID(){
    return userID;
}

string PrivateIndividual::GetSensorID(){
    return sensorID;
}

int PrivateIndividual::getFidelityPoints(){
    return fidelityPoints;
}

bool PrivateIndividual::getReliability(){
    return reliability;
}

void PrivateIndividual::AnalyserPrivateIndividual(){

    // Séparation de la chaine PrivateIndividual en sous-chaînes
    size_t debutUserID = 0;
    size_t finUserID = privateIndividual.find_first_of(';');

    size_t debutSensorID = finUserID + 1;
    size_t finSensorID = privateIndividual.find_last_of(';');

    // Extraction des sous-chaînes
    userID = privateIndividual.substr(debutUserID, finUserID - debutUserID);
    sensorID = privateIndividual.substr(debutSensorID, finSensorID - debutSensorID);
}

void PrivateIndividual::AfficherPrivateIndividual(){
    cout << "UserID : " << userID << endl;
    cout << "SensorID : " << sensorID << endl;
}
//-------------------------------------------- Constructeurs - destructeur


PrivateIndividual::PrivateIndividual (string log, string pwd,string id): User(log,pwd), userID(id), fidelityPoints(0), reliability(true)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif
} //----- Fin de PrivateIndividual

PrivateIndividual::PrivateIndividual (string id): User(), userID(id), fidelityPoints(0), reliability(true)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif
} //----- Fin de PrivateIndividual


PrivateIndividual::~PrivateIndividual ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateIndividual>" << endl;
#endif
} //----- Fin de ~PrivateIndividual


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
