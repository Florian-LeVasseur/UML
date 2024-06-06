/*************************************************************************
                           GovAgency  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
***************************GovAgency*********************************************/

//---------- Réalisation de la classe <GovAgency> (fichier GovAgency.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "GovAgency.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GovAgency::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//-------------------------------------------- Constructeurs - destructeur


GovAgency::GovAgency(string log, string pwd):User(log,pwd)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GovAgency>" << endl;
#endif
} //----- Fin de GovAgency


GovAgency::~GovAgency ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GovAgency>" << endl;
#endif
} //----- Fin de ~GovAgency


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
