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
#include <vector>
#include <ctime>

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

bool Controler::updateReliability(string UserId, bool isreliable){
    return db -> updatePrivateIndivReliability(UserId, isreliable);
}

vector <Measurement> Controler::SensorDataPrivateUser(string UserId)
{
    vector<Measurement> mesures; 
    //find PivateUser by Id
    vector <PrivateIndividual> pvUsers = db -> GetPrivateIndivs();
    PrivateIndividual * pvUser = NULL; 
    for (long unsigned int i=0; i<pvUsers.size(); i++)
    {
        if (pvUsers[i].GetUserID() == UserId) 
        {
            pvUser = &pvUsers[i];
            break; 
        }
    }
    if (pvUser == NULL)
    {
        cerr<<"pas de Private Individual trouvé pour cet id"<<endl; 
    }
    else 
    {
        //find sensorID
        string sensorIdPv = (*pvUser).GetSensorID();
        // find all measure related to the sensorId
        vector<Measurement> allMeasures = db -> GetMeasurements(); 
        for (long unsigned int i=0; i<allMeasures.size(); i++)
        {
            if (allMeasures[i].GetSensorID() == sensorIdPv)
            {
                mesures.push_back(allMeasures[i]); 
            }
        }
        if (mesures.empty()) cout<<"No measure for this private sensor"<<endl; 
    } 
    return mesures; 
}

bool Controler::checkIfReliable(string userID, string timeStart, string timeStop){

    time_t start = stringToTimeT(timeStart);
    time_t stop = stringToTimeT(timeStop);

    PrivateIndividual* monUser =NULL;
    Sensor* user_sensor = NULL;
    vector <PrivateIndividual> users = db->GetPrivateIndivs();
    vector <Sensor> sensors = db->GetSensors();
    vector<Measurement> measurements = db->GetMeasurements();

    for(size_t i=0; i<users.size(); ++i){
        if (users[i].GetUserID()==userID){
            monUser = &(users[i]);
            break;    
    }

    }
    if (monUser == NULL){
        cerr << "Could not find a User with that id"<<endl;
        return false;
    }

    for(size_t i=0; i<sensors.size(); ++i){
        if (sensors[i].GetSensorID()==monUser->GetSensorID()){
            user_sensor = &(sensors[i]);
            break;    
    }
    }

    monUser->AfficherPrivateIndividual();
    cout<<endl<<endl;
    user_sensor->AfficherSensor();
    cout<<endl<<endl;


    float O3 = 0 ,NO2 = 0, SO2 = 0, PM10 = 0;

    vector<Measurement> O3_measurement_in_range = getMeasurementsBetweenDates(measurements, user_sensor->GetSensorID(), "O3" , start, stop);
    vector<Measurement> NO2_measurement_in_range = getMeasurementsBetweenDates(measurements,user_sensor->GetSensorID(), "NO2" , start, stop);
    vector<Measurement> SO2_measurement_in_range = getMeasurementsBetweenDates(measurements, user_sensor->GetSensorID(), "SO2" , start, stop);
    vector<Measurement> PM10_measurement_in_range = getMeasurementsBetweenDates(measurements, user_sensor->GetSensorID(), "PM10" , start, stop);
    for(size_t j=0; j<O3_measurement_in_range.size()-1; j++){
            O3 += abs(O3_measurement_in_range[j].GetValue() - O3_measurement_in_range[j+1].GetValue());
            NO2 += abs(NO2_measurement_in_range[j].GetValue() - NO2_measurement_in_range[j+1].GetValue());
            SO2 += abs(SO2_measurement_in_range[j].GetValue() - SO2_measurement_in_range[j+1].GetValue());
            PM10 += abs(PM10_measurement_in_range[j].GetValue() - PM10_measurement_in_range[j+1].GetValue());
        }
    O3 = (float) O3/O3_measurement_in_range.size();
    NO2 = (float) NO2/NO2_measurement_in_range.size();
    SO2 = (float) SO2/SO2_measurement_in_range.size();
    PM10 = (float) PM10/PM10_measurement_in_range.size();
    cout << "O3 : "<<O3<<endl;
    cout << "NO2 : "<<NO2<<endl;
    cout << "SO2 : "<<SO2<<endl;
    cout << "PM10 : "<<PM10<<endl;

    bool isreliable = true;
    if (O3 >=10 || NO2 >=10 || SO2 >=10|| PM10 >=20)
        isreliable = false;
    return isreliable;

}

bool Controler::checkIfEfficient(string cleanerId){

    Cleaner* monCleaner =NULL;
    vector <Cleaner> cleaners = db->GetCleaners();
    vector<Measurement> measurements = db->GetMeasurements();
    time_t start;
    string timeStart;
    

    for(size_t i=0; i<cleaners.size(); ++i){
        cout<<cleaners[i].GetCleanerID()<<endl;
        if (cleaners[i].GetCleanerID()==cleanerId){
            monCleaner = &(cleaners[i]);
            timeStart = cleaners[i].GetTimestampStart();
            break;    
        }
    }
    
    start = stringToTimeT(timeStart)+86400;
    vector<Sensor> sensorsRank = sortSensorsByDistance(db->GetSensors(), *monCleaner);
    Sensor closeSensor = sensorsRank[0];

    monCleaner->AfficherCleaner();
    
    if (monCleaner == NULL){
        cerr << "Could not find a Cleaner with that id"<<endl;
        return false;
    }

    float O3 = 0 ,NO2 = 0, SO2 = 0, PM10 = 0;
    bool is_efficient = false;

    for(size_t i=0; i<measurements.size(); i++){
        if((measurements[i].GetAttributeID() == "O3" ) & (measurements[i].GetSensorID()==closeSensor.GetSensorID()) & (difftime( start, measurements[i].GetDate())==86400)){
            O3 = measurements[i].GetValue()-measurements[i-4].GetValue();
        }
        if((measurements[i].GetAttributeID() == "NO2" ) & (measurements[i].GetSensorID()==closeSensor.GetSensorID()) & (measurements[i].GetDate()==start-86400)){
            NO2 = measurements[i].GetValue()-measurements[i-4].GetValue();
        }
        if((measurements[i].GetAttributeID() == "SO2" ) & (measurements[i].GetSensorID()==closeSensor.GetSensorID()) & (measurements[i].GetDate()==start-86400)){
            SO2 = measurements[i].GetValue()-measurements[i-4].GetValue();
        }
        if((measurements[i].GetAttributeID() == "PM10" ) & (measurements[i].GetSensorID()==closeSensor.GetSensorID()) & (measurements[i].GetDate()==start-86400)){
            PM10 = measurements[i].GetValue()-measurements[i-4].GetValue();
        }
    }

    if ((O3 <(-10)) | (NO2<(-10)) | (SO2<(-10)) | (PM10<(-10))){
                is_efficient = true;
    }

    return is_efficient;
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
delete db;
} //----- Fin de ~Controler


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

time_t Controler::stringToTimeT(string& dateStr) {
    // Structure pour stocker la date et l'heure
    tm tm = {};
    istringstream ss(dateStr);
    
    // Lecture du string dans la structure tm
    ss >> std::get_time(&tm, "%Y-%m-%d");
    
    // Vérification si la lecture a réussi
    if (ss.fail()) {
        throw std::runtime_error("Échec de la conversion du string en std::tm");
    }
    
    // Conversion de std::tm en time_t
    time_t time = mktime(&tm);
    if (time == -1) {
        throw runtime_error("Échec de la conversion de tm en time_t");
    }
    
    return time;
}


bool Controler::compareDates(time_t date1, time_t date2) {
    return difftime(date1, date2) < 0;
}

vector<Measurement> Controler::getMeasurementsBetweenDates(vector<Measurement> Measurements, string sensorName, string attributeID, time_t startDate, time_t endDate) {
   
    vector<Measurement> filteredMeasurements;
    for(size_t i=0; i<(Measurements).size(); ++i){
        if((Measurements[i].GetAttributeID() == attributeID ) & (Measurements[i].GetSensorID()==sensorName)){
            if (compareDates(startDate, Measurements[i].GetDate()) && compareDates(Measurements[i].GetDate(), endDate)) {
                filteredMeasurements.push_back(Measurements[i]);
            }
        }
    }
    return filteredMeasurements;
}

// Fonction pour trier les capteurs par distance par rapport à un Cleaner donné
vector<Sensor> Controler::sortSensorsByDistance( vector<Sensor> sensors,  Cleaner cleaner) {
    
    vector<Sensor> sortedSensors = sensors;
    float calculateDistance (float lat1, float lon1, float lat2, float lon2);
    sort(sortedSensors.begin(), sortedSensors.end(), [&cleaner]( Sensor a,  Sensor b) {
        float distA = calculateDistance(a.GetLatitude(), a.GetLongitude(), cleaner.GetLatitude(), cleaner.GetLongitude());
        float distB = calculateDistance(b.GetLatitude(), b.GetLongitude(), cleaner.GetLatitude(), cleaner.GetLongitude());
        return distA < distB;
    });

    return sortedSensors;
}


float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    const float earthRadiusKm = 6371.0;

    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    float a = sin(dLat / 2) * sin(dLat / 2) +
               sin(dLon / 2) * sin(dLon / 2) * cos(lat1) * cos(lat2); 
    float c = 2 * atan2(sqrt(a), sqrt(1 - a)); 
    return earthRadiusKm * c;
}

float Controler::CalculateAtmoIndex(float O3, float NO2, float SO2, float PM10){

float level = 0;

if (50<=O3 && O3<100)
        level+=1;
else if (100<=O3 && O3<130)
        level+=2;
else if (130<=O3 && O3<240)
        level+=3;
else if (240<=O3 && O3<380)
        level+=4;
else if (O3 > 380)
        level+=5;

if (40<=NO2 && NO2<90)
        level+=1;
else if (90<=NO2 && NO2<120)
        level+=2;
else if (120<=NO2 && NO2<230)
        level+=3;
else if (230<=NO2 && NO2<340)
        level+=4;
else if (NO2>340)
        level+=5;

if (100<=SO2 && SO2<200)
        level+=1;
else if (200<=SO2 && SO2<350)
        level+=2;
else if (350<=SO2 && SO2<500)
        level+=3;
else if (500<=SO2 && SO2<750)
        level+=4;
else if (SO2 > 750)
        level+=5;

if (20<=PM10 && PM10<40)
        level+=1;
else if (40<=PM10 && PM10<50)
        level+=2;
else if (50<=PM10 && PM10<100)
        level+=3;
else if (100<=PM10 && PM10<150)
        level+=4;
else if (PM10 > 150)
        level+=5;

cout<<level<<endl;
level = level/4.0;
cout<<level<<endl;
return level;
}
