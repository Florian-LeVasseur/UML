/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
//------------------------------------------------------ Include personnel
#include "Attribute.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Attribute::GetAttributeID(){
    return attributeID;
}

string Attribute::GetUnit(){
    return unit;
}
string Attribute::GetDescription(){
    return description;
}

void Attribute::AfficherAttribute(){
    cout << "AttributID : " << attributeID << endl;
    cout << "Unit : " << unit << endl;
    cout << "Description : " << description << endl;
}

// type Attribute::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute ( const Attribute & unAttribute )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribute>" << endl;
#endif
} //----- Fin de Attribute (constructeur de copie)


Attribute::Attribute ( string OneAttribute)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
 // Séparation de la chaine attribute en sous-chaînes
    size_t debutID = 0;
    size_t finID = OneAttribute.find_first_of(';');

    size_t debutUnit = finID + 1;
    size_t finUnit = OneAttribute.find(';', debutUnit);

    size_t debutDescription = finUnit + 1;
    size_t finDescription = OneAttribute.find_last_of(';');

    // Extraction des sous-chaînes
    attributeID = OneAttribute.substr(debutID, finID - debutID);
    unit = OneAttribute.substr(debutUnit, finUnit - debutUnit);
    description = OneAttribute.substr(debutDescription, finDescription - debutDescription);
} //----- Fin de Attribute


Attribute::~Attribute ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées