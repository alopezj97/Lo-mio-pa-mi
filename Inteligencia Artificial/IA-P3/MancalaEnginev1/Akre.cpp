/*
 * Akre.cpp
 *
 *   Author: Álvaro López Jiménez
 */

#include "Akre.h"

#include <string>
#include <cstdlib>
#include <iostream>
#include <climits>
using namespace std;

Akre::Akre() {
	// Inicializar las variables necesarias para ejecutar la partida
}

Akre::~Akre() {
	// Liberar los recursos reservados (memoria, ficheros, etc.)
}

void Akre::initialize() {
	// Inicializar el bot antes de jugar una partida
}

string Akre::getName() {
	return "Akre"; // Sustituir por el nombre del bot
}

int Akre::AlfaBeta(vector<Nodo> &arbol, int nodoActual, int alfa, int beta, int profundidad){

	if (profundidad==NIVEL || arbol[nodoActual].state.isFinalState()) {																				// CASO BASE
		//return arbol[nodoActual].state.getScore(arbol[nodoActual].state.getCurrentPlayer());

		int mejorOpcion = 0 ;
		int valores[6] = {0,0,0,0,0,0};

		for (int i = 1 ; i <= 6 ; i++) {
			if (arbol[nodoActual].state.getSeedsAt(getPlayer(), (Position) i) == i)
				valores[i-1] = arbol[nodoActual].state.getScore(getPlayer()) + 1 + i;
		}

		for (int i = 0 ; i < 6 ; i++) {
			if (valores[i] > mejorOpcion)
				mejorOpcion = valores[i];
		}

		if (mejorOpcion != 0){
			//cerr << "se devuelve la mejor opción" << endl;
			return mejorOpcion ;
		}
		else
			return arbol[nodoActual].state.getScore(getPlayer());

	}

	for (int i=1 ; i<=6 ; i++){																																								// CASO GENERAL
		if (arbol[nodoActual].state.getSeedsAt(arbol[nodoActual].state.getCurrentPlayer(), (Position) i)){

			GameState new_state = arbol[nodoActual].state.simulateMove((Move) i);

			Nodo hijo(new_state, (Move) i);

			arbol.push_back(hijo);

			int posHijo = arbol.size()-1;

			//Búsqueda en profundidad para saber el valor del hijo
			int valorHijo = AlfaBeta(arbol, posHijo, alfa, beta, profundidad+1);

			if(arbol[nodoActual].state.getCurrentPlayer()==getPlayer()){   // Nodo MAX

				if(alfa<valorHijo){
					alfa=valorHijo;
					arbol[nodoActual].indiceMejorHijo= posHijo;
					arbol[nodoActual].valor=alfa;
				}
				if(alfa>=beta)
					return beta;
			}

			else {   																											// Nodo MIN
				if(beta>valorHijo){
					beta=valorHijo;
					arbol[nodoActual].indiceMejorHijo= posHijo;
					arbol[nodoActual].valor=beta;

				}
				if(beta<=alfa)
					return alfa;
			}

		}	// if getSeedsAt
	}	// for

	if(arbol[nodoActual].state.getCurrentPlayer()==getPlayer())				// Nodo MAX
		return alfa;
	else																															// Nodo MIN
		return beta;

}


Move Akre::nextMove(const vector<Move> &adversary, const GameState &state) {

	// Player turno= this->getPlayer();
	// long timeout= this->getTimeOut();

	Nodo raiz(state);  //Generamos la raíz, contiene el juego actual

	//Declaramos las variables
	int alfa = INT_MIN ;
	int beta = INT_MAX ;
	int profundidad=0;

	vector<Nodo> arbol;
	arbol.push_back(raiz);

	AlfaBeta(arbol, 0, alfa, beta, profundidad);

	return arbol[arbol[0].indiceMejorHijo].accion;

}
