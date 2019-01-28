#include "State.h"
#include "Transition.h"

// 1a) Implanter le constructeur
//     N'oubliez pas d'initialiser la variable membre mAccepting

// 1b) Implanter le destructeur
//     N'oubliez pas de d�truire les transitions contenues dans la liste

// 2) Accesseur, retourner la valeur mAccepting 

// 3) Mutateur, r�gler la valeur de mAccepting

// 4) Ajouter une transition dans l'�tat
//    Note 1: EMP�CHER deux transitions identiques d'�tre
//            dans la liste de transitions
//    Note 2: Utiliser la technique de l'ajout d'un symbole dans la
//            liste des symboles d'un comparateur pour r�aliser cette
//            fonction membre

// 5) Retourner la transition dont les conditions de
//    transition sont satisfaites. Sinon, retourner nullptr
