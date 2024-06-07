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
#include <string>

//------------------------------------------------------ Include personnel
#include "Controler.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector <Measurement> Controler::SensorDataPrivateUser(string UserId)
{
    vector<Measurement> mesures; 
    //find PivateUser by Id
    vector <PrivateIndividual> pvUsers = db -> GetPrivateIndivs(); 
    PrivateIndividual * pvUser; 
    for (int i=0; i<pvUser.size(); i++)
    {
        if (pvUsers[i].GetUserID() == UserId) 
        {
            pvUser = new PrivateIndividual; 
            *pvUser=pvUsers[i];
            break; 
        }
    }
    if (pvUser == NULL)
    {
        cout<<"pas de Private Individual trouvé à cette adresse"<<endl; 
    }
    else 
    {
        //find sensorID
        string sensorIdPv = *pvUser.GetSensorID();
        // find all measure related to the sensorId
        vector<Measurement> allMeasures = db -> GetMeasurements(); 
        for (int i=0; i<allMeasures.size(); i++)
        {
            if (allMeasures[i].GetSensorID() == sensorIdPv)
            {
                mesures.push_back(allMeasures[i]); 
            }
        }
    }

    delete pvUser; 
    return mesures; 
}
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

