#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"


#include <iostream>
#include <cmath>

void muestrea(list<Nodo> camino) {
	auto it = camino.begin();
	while (it!=camino.end()) {
		cout << "{" << (*it).getEstado().fila << "," << (*it).getEstado().columna << "," << (*it).getEstado().orientacion << "}" << endl ;
		it++;
	}
}

void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}

bool ComportamientoJugador::pathFinding(const estado &origen, const estado &destino, list<Action> &plan) {
	cerr << "entro a pathFinding" << endl ;
	//Borro la lista
	plan.clear();
	//mejorCamino.clear();

if (esIgual(origen,destino))
		return true ;

	list<Nodo*> abiertos ; // priority_queue<Nodo> abiertos ; ???
	list<Nodo> cerrados ;
	list<Nodo*> mejorCamino ;
	Nodo inicial (origen, NULL, heuristica(origen, destino));
	int iteracion = 0 ;
	abiertos.push_back(inicial); // ??? - push_front

	while (abiertos.size()>0) {
		cout << "iteracion = " << iteracion << endl ;
		iteracion++;
		Nodo actual = abiertos.front(); // ??? que función back() o front()
		cout << "nodo actua: {" << actual.getEstado().fila << "," << actual.getEstado().columna << "," << actual.getEstado().orientacion << "} con coste = " << actual.getCoste() << endl;
		if (esIgual(actual.getEstado(), destino)) {
			cout << "he encontrado el destino" << endl ;
			cout << "ABIERTOS: " << endl ;
			muestrea(abiertos);
			cout << "CERRADOS: " << endl ;
			muestrea(cerrados);
			cout << "MEJOR CAMINO:" << endl ;
			while (!esIgual(actual.getEstado(), origen)) {
				cout << "muestreo: " ;
				muestrea(mejorCamino);
				mejorCamino.push_back(actual);
				actual = actual.getPadre();
			}
			cout << "he salido del while" << endl ;

			construyePlan(plan, mejorCamino);
			// Descomentar para ver el plan en el mapa
			VisualizaPlan(origen, plan);
			cerr << "salgo a pathFinding" << endl ;
			return true ;
		}
		else {
			cerrados.push_back(actual);
			adyacentes(actual, abiertos);
			abiertos.pop_front();

		}

	}
	cerr << "salgo a pathFinding" << endl ;
	return false ;
}

Action ComportamientoJugador::think(Sensores sensores) {
	cerr << "entro a think" << endl ;
/*
	Action siguiente_accion ;

	// Si no sabemos donde estamos nos ubicamos
	if (!inicializado) {
		ubica(sensores);
		inicializado=true;
	}

	// Si no hay plan o hay que cambiarlo establecemos uno llamando a pathFinding
	if (!hayPlan) {
		estado origen ;
		origen.fila = fil;
		origen.columna = col;
		origen.orientacion = brujula;
		destino.fila = sensores.destinoF;
		destino.columna = sensores.desticoC;
		hayPlan = pathFinding(origen, destino, plan);

	}

	// Si hay plan entonces cogemos la primera acción introducida hasta que no queden.
	if (hayPlan & plan.size()>0) {
		siguiente_accion = plan.front();
		plan.pop_front();
	}
	else
		siguiente_accion = actIDLE ;

	switch (siguiente_accion) {
		case actFORWARD:
			avanza();
			break;
		case actTURN_L:
			gira_izq();
			break;
		case actTURN_R:
			gira_der();
			break;
		case actIDLE:
			break;
	}

  return siguiente_accion;
*/

	// Si podemos saber nuestra posición (nivel 1 y 2) nos ubicamos
bool inicializado = (sensores.mensajeF != -1) && (sensores.mensajeC != -1) ;

  if (inicializado){
		fil = sensores.mensajeF; // o llamar a ubica (sensores);
		col = sensores.mensajeC;
	}

	// Determinar si ha cambiado el destino desde la ultima planificacion
	if (hayPlan and (sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)){
		cout << "El destino ha cambiado\n";
		hayPlan = false;
	}

	// Determinar si tengo que construir un plan
	if (!hayPlan){
		estado origen;
		origen.fila = fil;
		origen.columna = col;
		origen.orientacion = brujula;

		destino.fila = sensores.destinoF;
		destino.columna = sensores.destinoC;

  	hayPlan = pathFinding(origen,destino,plan);
	}

	// Ejecutar el plan
	Action sigAccion;
	if (hayPlan and plan.size()>0){
		sigAccion = plan.front();
		plan.erase(plan.begin());
	}
	else {
		sigAccion = actIDLE;
	}

	switch (sigAccion){
		case actTURN_R: gira_der(); break;
		case actTURN_L: gira_izq(); break;
		case actFORWARD: avanza(); break;
		cout << "fil: " << fil << "  col: " << col << " Or: " << brujula << endl;
	}


	cerr << "salgo de think" << endl ;
	return sigAccion;
}


void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}

void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}

void ComportamientoJugador::avanza (){
	switch (brujula) {
		case 0: fil-- ; break ;
		case 1: col++ ; break ;
		case 2: fil++ ; break ;
		case 3: col-- ; break ;
	}
	cout << "avanzo" << endl ;
}

void ComportamientoJugador::gira_der() {
	brujula = (brujula+1)%4 ;
	cout << "giro a la derecha" << endl ;
}

void ComportamientoJugador::gira_izq() {
	brujula = (brujula+3)%4 ;
	cout << "giro a la izquierda" << endl ;
}

/*
void ComportamientoJugador::ubica(Sensores sensores) {
	fil = sensores.mensajeF ;
	col = sensores.mensajeC ;
}
*/

bool ComportamientoJugador::esIgual(const estado &primero, const estado &segundo) {
		//cout << "esIgual" << endl ;
	return (primero.fila == segundo.fila && primero.columna == segundo.columna);
}


void ComportamientoJugador::construyePlan(list<Action> &plan, list<Nodo> mejorCamino) {
	cerr << "entro a construyePlan" << endl ;
	Nodo n1 = mejorCamino.front();
	mejorCamino.pop_front();

	while (mejorCamino.size()>0) {
		Nodo n2 = mejorCamino.front();

		if (n1.getEstado().orientacion != n2.getEstado().orientacion) {           // Cambia la orientación

	    if ((n2.getEstado().orientacion+1)%4 == n1.getEstado().orientacion) {
	      plan.push_front(actTURN_R);
	    }

	    if ((n2.getEstado().orientacion-1)%4 == n1.getEstado().orientacion) {
	      plan.push_front(actTURN_L);
	    }
	  }

	  else {                  // No cambia la orientación

	    if ((n1.getEstado().fila != n2.getEstado().fila) || (n1.getEstado().columna != n2.getEstado().columna)) {
	      plan.push_front(actFORWARD);
	    }

	    else
	      plan.push_front(actIDLE);

	  }

		mejorCamino.pop_front();
		n1 = n2 ;

	}
	cerr << "salgo de construyePlan" << endl ;

}



int ComportamientoJugador::heuristica(const estado &origen, const estado &destino){
	//cerr << "entro a heuristica" << endl ;
	int ejex, ejey, distancia ;

	ejex = destino.fila - origen.fila ;
	ejey = destino.columna - origen.columna ;
	distancia = abs(ejex)+abs(ejey) ;

	//cerr << "salgo de heuristica" << endl ;

	return distancia ;
}



void ComportamientoJugador::adyacentes (Nodo actual, list<Nodo> &abiertos) {
	//cerr << "entro a adyacentes" << endl ;
	estado aux;

	// izq
	aux = actual.getEstado();
	aux.orientacion = (actual.getEstado().orientacion+3)%4 ;

	Nodo * ni = new Nodo (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
	// Nodo izq (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));

	if (!esCerrado(*ni)){
		if (!esAbierto(*ni)) {
			nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, ni->getCoste()} ;
			abiertos.push_back(*ni);
			abiertos.sort();
		}
		else {
			if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > ni->getCoste()) {
				nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = ni->getCoste() ;
				list<Nodo*>::iterator it ;
				for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
					if ( esIgual(*(*it).getEstado(), aux) && *(*it).getEstado().orientacion == aux.orientacion) {
						*(*it).setCoste(ni->getCoste());
						it = abiertos.end();
					}
				}
				abiertos.sort(); // ??? como los ordena
			}
		}

	}

	// der - ??? repito codigo
	aux.orientacion = (actual.getEstado().orientacion+1)%4 ;

	Nodo * nd = new Nodo(aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
	//	Nodo der(aux, &actual, actual.getCoste()+1+heuristica(aux, destino));

	if (!esCerrado(*nd)){
		if (!esAbierto(*nd)) {
			nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, nd->getCoste()} ;
			abiertos.push_back(*nd);
			abiertos.sort();
		}
		else {
			if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > nd->getCoste()) {
				nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = nd->getCoste() ;
				list<Nodo*>::iterator it ;
				for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
					if (esIgual(*(*it).getEstado(), aux) && *(*it).getEstado().orientacion == aux.orientacion) {
						*(*it).setCoste(nd->getCoste());
						it = abiertos.end();
					}
				}
				abiertos.sort(); // ??? como los ordena
			}
		}

	}

	// adelante
	aux = actual.getEstado();
	switch (aux.orientacion) {
		case 0: aux.fila = aux.fila -1 ; break ;
		case 1: aux.columna = aux.columna +1 ; break ;
		case 2: aux.fila = aux.fila +1 ; break ;
		case 3:	aux.columna = aux.columna -1 ; break ;
	}

	Nodo * na = new Nodo (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
	// Nodo avanti (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));

	if (mapa_transitable[aux.fila][aux.columna]) {
		if (!esCerrado(*na)){
			if (!esAbierto(*na)) {
				nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, (*na)->getCoste()} ;
				abiertos.push_back(avanti);
				abiertos.sort();
			}
			else {
				if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > (*na)->getCoste()) {
					nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = (*na)->getCoste() ;
					list<Nodo*>::iterator it ;
					for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
						if (esIgual(*(*it).getEstado(), aux) && *(*it).getEstado().orientacion == aux.orientacion) {
							*(*it).setCoste(na->getCoste());
							it = abiertos.end();
						}
					}
					abiertos.sort(); // ??? como los ordena
				}
			}
		}
	}

	//cerr << "salgo de adyacentes" << endl ;

}

bool ComportamientoJugador::esCerrado(Nodo n) {
	//cerr << "entro a esCerrado" << endl ;

	int fila = n.getEstado().fila ;
	int columna = n.getEstado().columna ;
	int orientacion = n.getEstado().orientacion ;
	//cerr << "salgo de esCerrado" << endl ;

	return nodos_cerrados[fila][columna][orientacion];
}

bool ComportamientoJugador::esAbierto(Nodo n) {
	//cerr << "entro a esAbierto" << endl ;

	int fila = n.getEstado().fila ;
	int columna = n.getEstado().columna ;
	int orientacion = n.getEstado().orientacion ;
	//cerr << "salgo a esAbierto" << endl ;

	return nodos_abiertos[fila][columna][orientacion].first;
}
