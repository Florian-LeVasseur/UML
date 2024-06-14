using namespace std;
#include <iostream>
#include <cstring>
#include <string>

#include "Controler.h"

int main(){
    int Action = -1;
    
    Controler controler;
   
    controler.createDb(); 
    controler.getDb()->GetSensors()[0].AfficherSensor();
    
    while (Action!=0)
    {
        cout<< "Do you want to connect as :"<< endl;
        cout<<"1: Agence"<<endl;
        cout<<"2: Provider"<< endl;
        cout<<"3: Private individual"<<endl;
        cout<<"0: Quitter"<<endl;
        if (!(cin >> Action)) {
            // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
            cin.clear();
            cin.ignore(1000, '\n');
        }
        switch(Action){
        
        case 0: {   // Quitter
            break;
        }
        case 1: {   // Charger Menu Agence
            int ActionAgence = -1;
            while (ActionAgence!=0)
            {
                cout<< "Select :"<< endl;
                cout<<"1: Analyse air quality"<<endl;
                cout<<"2: Identify areas with similar air quality"<<endl;
                cout<<"3: Analyze air quality around air cleaner (mean) at a given moment"<<endl;
                cout<<"4: Analyze air quality around air cleaner (mean) for a specified period of time"<<endl;
                cout<<"5: Ask for private individual's sensor informations"<<endl; 
                cout<<"6: Identify a malicious personal user"<<endl; 
                cout<<"7: Exclude a privateIndividual"<<endl; 
                cout<<"0: Deconnexion"<< endl;
                if (!(cin >> ActionAgence)) {
                    // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                switch(ActionAgence){
                
                case 0: {   // Quitter
                    cout<<"Déconnexion"<<endl; 
                    break;
                }
                case 1: {   // 
                    cout<<"Choice : Analyse air quality"<<endl; 
                    break;
                }
                case 2:{    // 
                    cout<<"Choice : Identify areas with similar air quality"<<endl; 
                    break;
                }
                case 3: {   //
                    cout<<"Choice : Analyze air quality around air cleaner"<<endl; 
                    break;
                }
                case 4: {   //
                    cout<<"Choice : Analyze private individual's sensor"<<endl; 
                    break;
                }
                case 5: { //private individual's sensor information
                    cout<<"Choice : Ask for private individual's sensor informations"<<endl; 
                    string indivId; 
                    cout<<"Enter the individual ID : "; 
                    cin >> indivId; 

                    vector <Measurement> privateMeasure = controler.SensorDataPrivateUser(indivId); 
                    if (! privateMeasure.empty())
                    {
                        for (int i = 0 ; i < privateMeasure.size() ; i++)
                            privateMeasure[i].AfficherMeasurement(); 
                    }
                    break; 
                }

                case 6 : { 
                    cout<<"Choice : Identify a malicious personal user"<<endl;
                    break; 
                }

                case 7 : { 
                    cout<<"Choice : Exclude a privateIndividual"<<endl;
                    string indivId; 
                    cout<<"Enter the individual ID : "; 
                    cin >> indivId; 

                    vector <Measurement> privateMeasure = controler.SensorDataPrivateUser(indivId); 
                    if (! privateMeasure.empty())
                    {
                        for (int i = 0 ; i < privateMeasure.size() ; i++)
                            privateMeasure[i].AfficherMeasurement(); 
                    }
                    break; 
                }

                default: {  // Si la saisie n'est pas correcte
                    cout<<"Veuillez selectionner une des options proposées"<<endl;
                    cin.clear();
                    continue;
                }
                }
                cout<<endl<<endl;
            }
            break;
        }
        case 2: {   // Charger Menu Provider
            int ActionProvider = -1;
            while (ActionProvider!=0)
            {
                cout<< "Select :"<< endl;
                cout<<"1: Analyze air quality around air cleaner"<<endl;
                cout<<"0: Deconnexion"<< endl;
                if (!(cin >> ActionProvider)) {
                    // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                switch(ActionProvider){
                
                case 0: {   // Quitter
                    cout<<"Deconnexion"<<endl; 
                    break;
                }
                case 1: {   // 
                    cout<<"Choice : Analyze air quality around air cleaner"<<endl; 
                    break;
                }
                default: {  // Si la saisie n'est pas correcte
                    cout<<"Veuillez selectionner une des options proposées"<<endl;
                    cin.clear();
                    continue;
                }
                }
                cout<<endl<<endl;
            }
            break;
        }
        case 3: {   // Charger Menu Provider
            int ActionPrivateIndividual = -1;
            while (ActionPrivateIndividual!=0)
            {
                cout<< "Que voulez vous faire :"<< endl;
                cout<<"1: Afficher données de ses capteurs"<<endl;
                cout<<"2: Afficher points de fidélité"<<endl;
                cout<<"0: Deconnnexion"<< endl;
                if (!(cin >> ActionPrivateIndividual)) {
                    // En cas d'échec de la saisie, on vide le tampon et on ignore la ligne
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                switch(ActionPrivateIndividual){
                
                case 0: {   // Quitter
                    cout<<"Deconnexion"<<endl; 
                    break;
                }
                case 1: {   // 
                    cout << "Choice : Afficher données de ses capteurs "<<endl; 
                    break;
                }
                case 2:{    // 
                    //int points = controler.askPoint();
                    //cout<<"Vous avez "<<points<<" points de fidélité."<<endl;
                    cout << "Choice : Afficher points de fidélité"<<endl; 
                    break;
                }
                default: {  // Si la saisie n'est pas correcte
                    cout<<"Veuillez selectionner une des options proposées"<<endl;
                    cin.clear();
                    continue;
                }
                }
                cout<<endl<<endl;
            }
            break;
        }
        default: {  // Si la saisie n'est pas correcte
            cout<<"Veuillez selectionner une des options proposées"<<endl;
            cin.clear();
            continue;
        }
        }
    cout<<endl<<endl;
    }
    return 0; 
}


