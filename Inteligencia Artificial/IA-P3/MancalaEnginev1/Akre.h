/*
 * Akre.h
 *
 *   Author: Álvaro López Jiménez
 */

#include "Bot.h"

#ifndef MANUPCBOT_H_
#define MANUPCBOT_H_

#include<iostream>
using namespace std;


struct Nodo {

	GameState state;	// Estado del juego en este nodo del arbol
	Move accion ; 		// Acción que realizó el padre para llegar a este estado
	int valor ; 		// Valor (heurístico) del nodo
	int indiceMejorHijo;  	// Índice del mejor hijo en el árbol 
	

	Nodo(const GameState &game, const Move &movimiento){
		state = game ;
		accion = movimiento ;
		valor = -1 ; // Inicialmente no lo sabemos
		indiceMejorHijo = -1 ; // Inicialmente no lo sabemos
	}

	Nodo(const GameState &raiz){
		state = raiz ;
		accion = (Move) 0 ; // No es significativo el valor que pongamos, no sabemos o no hay movimiento inicial
		valor = -1 ; // Inicialmente no lo sabemos
		indiceMejorHijo = -1 ; // Inicialmente no lo sabemos
	}

};


class Akre:Bot {

	public:

		Akre();
		~Akre();

		void initialize();
		string getName();
		Move nextMove(const vector<Move> &adversary, const GameState &state);
		int AlfaBeta(vector<Nodo> &arbol, int nodoActual, int alfa, int beta, int profundidad);

	private:

		const int NIVEL=12;

};

#endif /* MANUPCBOT_H_ */
