#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"


#include <iostream>
#include <cmath>
#include <limits>

int contador = 0 ;

void muestrea(list<Nodo*> camino) {
	auto it = camino.begin();
	while (it!=camino.end()) {
		cout << "{" << (*it)->getEstado().fila << "," << (*it)->getEstado().columna << "," << (*it)->getEstado().orientacion << "," << (*it)->getCoste() << "}" << endl;
		it++;
	}
}

void muestrea2(list<Nodo> camino) {
	auto it = camino.begin();
	while (it!=camino.end()) {
		cout << "{" << (*it).getEstado().fila << "," << (*it).getEstado().columna << "," << (*it).getEstado().orientacion << "}" << endl ;
		it++;
	}
}

void ComportamientoJugador::PintaPlan(list<Action> plan) {
	//cout << "dentro de PintaPlan" << endl;
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
	//cout << "salgo de PintaPlan" << endl;
}

bool ComportamientoJugador::pathFinding(const estado &origen, const estado &destino, list<Action> &plan) {
	//cerr << "entro a pathFinding" << endl ;
	//Borro la lista
	plan.clear();

	for (int i = 0 ; i < TAM ; i++) {
		for (int j = 0 ; j < TAM ; j++) {
			for (int k = 0 ; k < 4 ; k++) {
				nodos_cerrados[i][j][k] = false ;
				nodos_abiertos[i][j][k] = {false, std::numeric_limits<int>::max()} ;
			}
		}
	}



	if (esIgual(origen,destino))
		return true ;

	list<Nodo*> abiertos ; // priority_queue<Nodo> abiertos ; ???
	list<Nodo> cerrados ;
	list<Nodo*> mejorCamino ;
	Nodo inicial (origen, NULL, heuristica(origen, destino));
	int iteracion = 0 ;
	abiertos.push_back(&inicial);
	Nodo* actual ;
	int contador = 0 ;
	bool modifico = false ;

	while (abiertos.size()>0) {
		//cout << "iteracion = " << iteracion << endl ;
		//iteracion++;
		//cout << "ABIERTOS: " << endl ;
		//muestrea(abiertos);
		//cout << "CERRADOS: " << endl ;
		//muestrea2(cerrados);
		actual = abiertos.front();
		//cout << "nodo actua: {" << actual->getEstado().fila << "," << actual->getEstado().columna << "," << actual->getEstado().orientacion << "} con coste = " << actual->getCoste() << endl;
		//if (actual->getPadre() != NULL)
		//	cout << "padre del nodo actual: {" << actual->getPadre().getEstado().fila << "," << actual->getPadre().getEstado().columna << "," << actual->getPadre().getEstado().orientacion << "} con coste = " << actual->getCoste() << endl;

		//cerr << "estoy en el else del pathFinding" << endl ;
		cerrados.push_back(*actual);
		nodos_cerrados[actual->getEstado().fila][actual->getEstado().columna][actual->getEstado().orientacion] = true ;
		abiertos.pop_front();

		if (esIgual(actual->getEstado(), destino)) {
			//cout << "he encontrado el destino" << endl ;
			//cout << "ABIERTOS: " << endl ;
			//muestrea(abiertos);
			//cout << "CERRADOS: " << endl ;
			//muestrea2(cerrados);
			//cout << "MEJOR CAMINO:" << endl ;
			while (!esIgual(actual->getEstado(), origen) || actual->getEstado().orientacion != origen.orientacion) {
				//cout << "muestreo: " ;
				//muestrea2(mejorCamino);
				//cout << "voy a meter en mejorCamino un puntero al nodo: {" << actual->getEstado().fila << "," << actual->getEstado().columna << "," << actual->getEstado().orientacion << "}" << endl;
				mejorCamino.push_back(actual);
				actual = actual->getPadre();
			}
			mejorCamino.push_back(actual);
			//muestrea(mejorCamino);

			construyePlan(plan, mejorCamino);
			// Descomentar para ver el plan en el mapa
			VisualizaPlan(origen, plan);
			//cerr << "salgo de pathFinding" << endl ;
			return true ;
		}
		else {

		// ----------------------- VOY A INSERTAR AQUÍ ADYACENTES ---------------------------------------------------------------

			//actual.adyacentes(abiertos, destino);

			estado aux;
			bool introducido = false ;

			// izq
			aux = actual->getEstado();
			aux.orientacion = (actual->getEstado().orientacion+3)%4 ;


			Nodo* ni = new Nodo (aux, actual, actual->getCoste()+2+heuristica(aux, destino));
			//cout << "nodo izq: {" << aux.fila << "," << aux.columna << "," << aux.orientacion << "," << ni->getCoste() << "}" << endl;

			if (!esCerrado(*ni)){
				if (!esAbierto(*ni)) {
					nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, ni->getCoste()} ;

					auto it = abiertos.begin();
					introducido = false ;
					while (it!=abiertos.end()) {
						if (ni->getCoste() < (*it)->getCoste()){
							abiertos.insert(it, ni);
							introducido = true ;
							it = abiertos.end();
						}
						else
							it++;
					}
					if (introducido == false)
						abiertos.insert(abiertos.end(), ni);

					introducido = false ;


				}
				else {
					if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > ni->getCoste()) {
						nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = ni->getCoste() ;
						list<Nodo*>::iterator it ;
						for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
							if ( esIgual((*it)->getEstado(), aux) && (*it)->getEstado().orientacion == aux.orientacion) {
								(*it)->setCoste(ni->getCoste());
								(*it)->setPadre(actual);
								it = abiertos.end();
							}
						}
					}
				}

			}

			// der - ??? repito codigo
			aux.orientacion = (actual->getEstado().orientacion+1)%4 ;

			Nodo* nd = new Nodo (aux, actual, actual->getCoste()+2+heuristica(aux, destino));
			//	Nodo der(aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
			//cout << "nodo der: {" << aux.fila << "," << aux.columna << "," << aux.orientacion  << "," << nd->getCoste() << "}" << endl;

			if (!esCerrado(*nd)){
				if (!esAbierto(*nd)) {
					nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, nd->getCoste()} ;

					auto it = abiertos.begin();
					introducido = false ;
					while (it!=abiertos.end()) {
						if (nd->getCoste() < (*it)->getCoste()){
							abiertos.insert(it, nd);
							introducido = true ;
							it = abiertos.end();
						}
						else
							it++;
					}
					if (introducido == false)
						abiertos.insert(abiertos.end(), nd);

					introducido = false ;

				}
				else {
					if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > nd->getCoste()) {
						nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = nd->getCoste() ;
						list<Nodo*>::iterator it ;
						for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
							if (esIgual((*it)->getEstado(), aux) && (*it)->getEstado().orientacion == aux.orientacion) {
								(*it)->setCoste(nd->getCoste());
								(*it)->setPadre(actual);
								it = abiertos.end();
							}
						}
					}
				}

			}

			// adelante
			aux = actual->getEstado();
			switch (aux.orientacion) {
				case 0: aux.fila = aux.fila -1 ; break ;
				case 1: aux.columna = aux.columna +1 ; break ;
				case 2: aux.fila = aux.fila +1 ; break ;
				case 3:	aux.columna = aux.columna -1 ; break ;
			}

			Nodo* na = new Nodo(aux, actual, actual->getCoste()+1+heuristica(aux, destino));
			// Nodo avanti (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
			//cout << "nodo avanti: {" << aux.fila << "," << aux.columna << "," << aux.orientacion << "," << na->getCoste() << "}" << endl;


			if (mapa_transitable[aux.fila][aux.columna]) {
				if (!esCerrado(*na)){
					if (!esAbierto(*na)) {
						nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, na->getCoste()} ;

						auto it = abiertos.begin();
						introducido = false ;
						while (it!=abiertos.end()) {
							if (na->getCoste() < (*it)->getCoste()){
								abiertos.insert(it, na);
								introducido = true ;
								it = abiertos.end();
							}
							else
								it++;
						}
						if (introducido == false)
							abiertos.insert(abiertos.end(), na);

						introducido = false ;

					}
					else {
						if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > na->getCoste()) {
							nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = na->getCoste() ;
							list<Nodo*>::iterator it ;
							for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
								if (esIgual((*it)->getEstado(), aux) && (*it)->getEstado().orientacion == aux.orientacion) {
									(*it)->setCoste(na->getCoste());
									(*it)->setPadre(actual);
									it = abiertos.end();
								}
							}
						}
					}
				}
			}
		}

			//abiertos.sort();
	}


	delete actual ;
	//delete ni;
	//delete nd;
	//delete na;
	delete[] &abiertos ;
	delete[] &mejorCamino ;

	//cout << "salgo de pathFinding" << endl;
	return false ;
}

Action ComportamientoJugador::think(Sensores sensores) {
	//cerr << "entro a think" << endl ;

	// Si podemos saber nuestra posición (nivel 1 y 2) nos ubicamos
	//cout << "sensores: " << sensores.mensajeF << sensores.mensajeC << endl;
	bool localizado = (sensores.mensajeF != -1) && (sensores.mensajeC != -1) ;

  if (inicializado && localizado){
		fil = sensores.mensajeF; // o llamar a ubica (sensores);
		col = sensores.mensajeC;
		inicializado = true ;
	}
/*
	// NIVEL 3
	else { // inicializado == false (por defecto) y localizado == false (nivel 3)
		int fil_provisional = 100;
		int col_provisional = 100;

		while (localizado == false) {
			actualiza_mapa(fil_provisional, col_provisional, brujula);

		}

		fil = sensores.mensajeF;
		col = sensores.mensajeC;
		// AQUI ARREGLO EL MAPPA

	}
*/
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

	if (sensores.superficie[2] == 'a') {
		//cout << "aldeano delante, me espero" << endl;
		//return actIDLE;
		switch (brujula) {
			case 0: mapa_transitable[fil-1][col] = false ;
			case 1: mapa_transitable[fil][col+1] = false ;
			case 2: mapa_transitable[fil][col-1] = false ;
			case 3: mapa_transitable[fil+1][col] = false ;
		}
		estado origen;
		origen.fila = fil;
		origen.columna = col;
		origen.orientacion = brujula;

		destino.fila = sensores.destinoF;
		destino.columna = sensores.destinoC;

		hayPlan = pathFinding(origen,destino,plan);

		switch (brujula) {
			case 0: mapa_transitable[fil-1][col] = true ;
			case 1: mapa_transitable[fil][col+1] = true ;
			case 2: mapa_transitable[fil][col-1] = true ;
			case 3: mapa_transitable[fil+1][col] = true ;
		}

	}

/*	if (sensores.superficie[2] == 'a' && contador < 5) {
		cout << "aldeano delante, me espero" << endl;
		contador++;
		return actIDLE;
	}

	if (sensores.superficie[2] == 'a' && contador == 5) {
		contador = 0 ;
		hayPlan = false;
		estado actual;
		actual.fila = fil;
		actual.columna = col;
		actual.orientacion = brujula;
		mapa_transitable[fil][col] = false ;
		hayPlan = pathFinding(actual,destino,plan);
		mapa_transitable[fil][col] = true ;
		cout << "HE RECALCULADO RUTA" << endl;

	}
*/
	// Ejecutar el plan
	Action sigAccion;
	if (hayPlan and plan.size()>0){
		sigAccion = plan.front();
		plan.erase(plan.begin());
	}
	else {
		//cout << "no hago nada";
		sigAccion = actIDLE;
	}

	switch (sigAccion){
		case actTURN_R: gira_der(); break;
		case actTURN_L: gira_izq(); break;
		case actFORWARD: avanza(); break;
		cout << "fil: " << fil << "  col: " << col << " Or: " << brujula << endl;
	}


	//cerr << "salgo de think" << endl ;
	return sigAccion;
}

void ComportamientoJugador::construyePlan(list<Action> &plan, list<Nodo*> mejorCamino) {
	//cerr << "entro a construyePlan" << endl ;
	//cout << "mejorCamino en construyePlan: " << endl ;
	//muestrea(mejorCamino);
	Nodo n1 = *mejorCamino.back(); // el nodo origen
	mejorCamino.pop_back();
	//cout << "despues de sacar el nodo origen, mejor Camino es: " << endl ;
	//muestrea(mejorCamino);

	while (mejorCamino.size()>0) {
		Nodo n2 = *mejorCamino.back();

		//cout << "n1 = {" << n1.getEstado().fila << "," << n1.getEstado().columna << "," << n1.getEstado().orientacion << "}" << endl;
		//cout << "n2 = {" << n2.getEstado().fila << "," << n2.getEstado().columna << "," << n2.getEstado().orientacion << "}" << endl;


		if (n1.getEstado().orientacion != n2.getEstado().orientacion) {           // Cambia la orientación
		  if ((n1.getEstado().orientacion+3)%4 == n2.getEstado().orientacion) {
				//cout << "meto en plan: gira izq" << endl;
		    plan.push_back(actTURN_L);
	    }

	    if ((n1.getEstado().orientacion+1)%4 == n2.getEstado().orientacion) {
				//cout << "meto en plan: gira der" << endl;
		    plan.push_back(actTURN_R);
	    }
	  }

	  else {                  // No cambia la orientación
		  if ((n1.getEstado().fila != n2.getEstado().fila) || (n1.getEstado().columna != n2.getEstado().columna)) {
				//cout << "meto en plan: avanza" << endl;
		    plan.push_back(actFORWARD);
	    }

	    else {
				//cout << "meto en plan: nada" << endl;
	      plan.push_back(actIDLE);
			}
	  }

		mejorCamino.pop_back();
		n1 = n2 ;

	}
	//cout << "el plan resultante es: (antes de PintaPlan)" << endl;
	PintaPlan(plan);

	//cerr << "salgo de construyePlan" << endl ;

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

int ComportamientoJugador::heuristica(const estado &origen, const estado &destino){
	//cerr << "entro a heuristica" << endl ;
	int ejex, ejey, distancia ;

	ejex = destino.fila - origen.fila ;
	ejey = destino.columna - origen.columna ;
	distancia = abs(ejex)+abs(ejey) ;

	//cerr << "salgo de heuristica" << endl ;

	return distancia ;
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







/*
void Nodo::adyacentes (list<Nodo> &abiertos, const estado &destino) {
	//cerr << "entro a adyacentes" << endl ;
	estado aux;

	// izq
	aux = this->getEstado();
	aux.orientacion = (this->getEstado().orientacion+3)%4 ;


	Nodo ni (aux, this, this->getCoste()+1+heuristica(aux, destino));
	// Nodo izq (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
	cout << "nodo izq: {" << aux.fila << "," << aux.columna << "," << aux.orientacion << "," << ni.getCoste() << "}" << endl;


	if (!esCerrado(ni)){
		if (!esAbierto(ni)) {
			nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, ni.getCoste()} ;
			abiertos.push_back(ni);
			abiertos.sort();
		}
		else {
			if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > ni.getCoste()) {
				nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = ni.getCoste() ;
				list<Nodo>::iterator it ;
				for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
					if ( esIgual(it->getEstado(), aux) && it->getEstado().orientacion == aux.orientacion) {
						it->setCoste(ni.getCoste());
						it = abiertos.end();
					}
				}
				abiertos.sort(); // ??? como los ordena
			}
		}

	}

	// der - ??? repito codigo
	aux.orientacion = (this->getEstado().orientacion+1)%4 ;

	Nodo nd (aux, this, this->getCoste()+1+heuristica(aux, destino));
	//	Nodo der(aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
	cout << "nodo der: {" << aux.fila << "," << aux.columna << "," << aux.orientacion  << "," << nd->getCoste() << "}" << endl;


	if (!esCerrado(nd)){
		if (!esAbierto(nd)) {
			nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, nd.getCoste()} ;
			abiertos.push_back(nd);
			abiertos.sort();
		}
		else {
			if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > nd.getCoste()) {
				nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = nd.getCoste() ;
				list<Nodo>::iterator it ;
				for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
					if (esIgual(it->getEstado(), aux) && it->getEstado().orientacion == aux.orientacion) {
						it->setCoste(nd.getCoste());
						it = abiertos.end();
					}
				}
				abiertos.sort(); // ??? como los ordena
			}
		}

	}

	// adelante
	aux = this->getEstado();
	switch (aux.orientacion) {
		case 0: aux.fila = aux.fila -1 ; break ;
		case 1: aux.columna = aux.columna +1 ; break ;
		case 2: aux.fila = aux.fila +1 ; break ;
		case 3:	aux.columna = aux.columna -1 ; break ;
	}

	Nodo na (aux, this, this->getCoste()+1+heuristica(aux, destino));
	// Nodo avanti (aux, &actual, actual.getCoste()+1+heuristica(aux, destino));
	cout << "nodo avanti: {" << aux.fila << "," << aux.columna << "," << aux.orientacion << "," << na->getCoste() << "}" << endl;


	if (mapa_transitable[aux.fila][aux.columna]) {
		if (!esCerrado(na)){
			if (!esAbierto(na)) {
				nodos_abiertos[aux.fila][aux.columna][aux.orientacion] = {true, na.getCoste()} ;
				abiertos.push_back(na);
				abiertos.sort();
			}
			else {
				if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > na.getCoste()) {
					nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = na.getCoste() ;
					list<Nodo>::iterator it ;
					for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
						if (esIgual(it->getEstado(), aux) && it->getEstado().orientacion == aux.orientacion) {
							(*it)->setCoste(na.getCoste());
							it = abiertos.end();
						}
					}
					abiertos.sort(); // ??? como los ordena
				}
			}
		}
	}

	//cerr << "el tamaño de abiertos al salir de adyacentes es : " << abiertos.size() << endl;
	//cerr << "salgo de adyacentes" << endl ;

}
*/
