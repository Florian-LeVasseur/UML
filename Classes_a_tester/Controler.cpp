/*************************************************************************
                           Controler  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
***************************Controler*********************************************/

//---------- Réalisation de la classe <Controler> (fichier Controler.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Controler.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Controler::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Controler::createDb(){
    db = new Database("./DataBase/sensors.csv", "./DataBase/measurements.csv", "./DataBase/attributes.csv", "./DataBase/cleaners.csv", "./DataBase/users.csv", "./DataBase/providers.csv");
}

Database* Controler::getDb(){
    return db;
}

int Controler::askPoint(string providerId){ 
    return 0;
}

int Controler::askMeanSensor(string sensorId){
    
    return 0;
}


//-------------------------------------------- Constructeurs - destructeur

Controler::Controler ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Controler>" << endl;
#endif         
} //----- Fin de Controler

Controler::~Controler ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controler>" << endl;
#endif
} //----- Fin de ~Controler


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

