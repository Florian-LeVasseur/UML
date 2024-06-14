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

void PrivateIndividual::AfficherPrivateIndividual(){
    cout << "UserID : " << userID << endl;
    cout << "SensorID : " << sensorID << endl;
}
//-------------------------------------------- Constructeurs - destructeur
PrivateIndividual::PrivateIndividual ( const PrivateIndividual & unPrivateIndividual )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateIndividual>" << endl;
#endif

userID = unPrivateIndividual.userID;
sensorID = unPrivateIndividual.sensorID;
fidelityPoints = unPrivateIndividual.fidelityPoints;
reliability = unPrivateIndividual.reliability;
} //----- Fin de PrivateIndividual (constructeur de copie)

PrivateIndividual::PrivateIndividual (string OnePrivateIndividual): User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif
// Séparation de la chaine OnePrivateIndividual en sous-chaînes
    size_t debutUserID = 0;
    size_t finUserID = OnePrivateIndividual.find_first_of(';');

    size_t debutSensorID = finUserID + 1;
    size_t finSensorID = OnePrivateIndividual.find_last_of(';');

    // Extraction des sous-chaînes
    userID = OnePrivateIndividual.substr(debutUserID, finUserID - debutUserID);
    sensorID = OnePrivateIndividual.substr(debutSensorID, finSensorID - debutSensorID);
    fidelityPoints = 0;
    reliability = true;

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
