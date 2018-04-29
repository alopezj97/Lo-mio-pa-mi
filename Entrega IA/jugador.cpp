#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"


#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h> // para el rand
#include <time.h> // para el rand

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

	list<Nodo*> abiertos ;
	list<Nodo> cerrados ;
	list<Nodo*> mejorCamino ;
	Nodo inicial (origen, NULL, heuristica(origen, destino));
	abiertos.push_back(&inicial);
	Nodo* actual ;
	bool modifico = false ; // ???

	while (abiertos.size()>0) {
		//cout << "entro al while" << endl;
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
			//cout << "en el else de pathFinding" << endl;

			estado aux;
			bool introducido = false ;

			// izq
			aux = actual->getEstado();
			aux.orientacion = (actual->getEstado().orientacion+3)%4 ;

			Nodo* ni = new Nodo (aux, actual, actual->getCoste()+2+heuristica(aux, destino));

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
					if (introducido == false) {
						abiertos.insert(abiertos.end(), ni);
					}

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
								//it = abiertos.end();
							}
						}
					}
				}

			}

			// der
			aux.orientacion = (actual->getEstado().orientacion+1)%4 ;

			Nodo* nd = new Nodo (aux, actual, actual->getCoste()+2+heuristica(aux, destino));

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
					if (introducido == false) {
						abiertos.insert(abiertos.end(), nd);
					}

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
								//it = abiertos.end();
							}
						}
					}
				}

			}

			// adelante
			//cout << "empiezo na" << endl;
			aux = actual->getEstado();
			switch (aux.orientacion) {
				case 0: aux.fila = aux.fila -1 ; break ;
				case 1: aux.columna = aux.columna +1 ; break ;
				case 2: aux.fila = aux.fila +1 ; break ;
				case 3:	aux.columna = aux.columna -1 ; break ;
			}

			Nodo* na = new Nodo(aux, actual, actual->getCoste()+1+heuristica(aux, destino));

			if (aux.fila < mapaResultado.size() and aux.columna < mapaResultado.size()) {
				if (mapaResultado[aux.fila][aux.columna] != 'B' and mapaResultado[aux.fila][aux.columna] != 'A' and mapaResultado[aux.fila][aux.columna] != 'P' and mapaResultado[aux.fila][aux.columna] != 'M') { // CAMBIAR
					//cout << "es transitable" << endl;
					if (!esCerrado(*na)){
						//cout << "no es cerrado" << endl;
						if (!esAbierto(*na)) {
							//cout << "no es abierto" << endl;
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
							if (introducido == false) {
								abiertos.insert(abiertos.end(), na);
							}
							introducido = false ;

						}
						else {
							//cout << "ya era abierto" << endl;
							if (nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second > na->getCoste()) {
								nodos_abiertos[aux.fila][aux.columna][aux.orientacion].second = na->getCoste() ;
								list<Nodo*>::iterator it ;
								//cout << "antes del for" << endl;
								for (it = abiertos.begin(); it!= abiertos.end(); ++it) {
									if (esIgual((*it)->getEstado(), aux) && (*it)->getEstado().orientacion == aux.orientacion) {
										(*it)->setCoste(na->getCoste());
										(*it)->setPadre(actual);
										//it = abiertos.end();
									}
								}
								//cout << "termino el for" << endl;
							}
						}
					} //if (!esCerrado)
				} // if (mapa_transitable)
				//cout << "termino na" << endl;
			}

		} // else -> no tenemos el destino
		//cout << "salgo del else" << endl;

	} // while

	//abiertos.clear();
	//cerrados.clear();
	//mejorCamino.clear();

	delete actual ;
	delete[] &abiertos ;
	delete[] &mejorCamino ;

	//cout << "salgo de pathFinding" << endl;
	return false ;
}

Action ComportamientoJugador::think(Sensores sensores) {
	//cerr << "entro a think" << endl ;

	// ¿Sé donde estoy?
	bool localizado = (sensores.mensajeF != -1) && (sensores.mensajeC != -1) ;
	bool estoy_en_PK = (sensores.terreno[0] == 'K');

  if (localizado){
		fil = sensores.mensajeF; // o llamar a ubica (sensores);
		col = sensores.mensajeC;
		inicializado = true ;
		cout << "estoy en PK" << endl;
		actualiza_mapa(sensores);
		return actIDLE;

	}

	// NIVEL 3
	if (!localizado and !hayPlan) { // inicializado == false (por defecto) y localizado == false (nivel 3)
		//cout << "nivel 3.1" << endl ;
		if (!inicializado) {
			//cout << "nivel 3.2" << endl;
			if (!hayPlan) {
				//cout << "nivel 3.3" << endl;
				//int fil_provisional = 100;
				//int col_provisional = 100;
				bool PK_encontrado = false ;

				while (estoy_en_PK == false) {
					//cout << "nivel 3-while" << endl;
					//actualiza_mapa(sensores);

					//if (!PK_encontrado) {
/*
						for (int i = 0 ; i < 16 ; i++) {
							if (sensores.terreno[i] == 'K'){
								cout << "nivel 3 he encontrado PK" << endl;
								PK_encontrado = true;
								//estado origen ;
								//origen.fila = fil_provisional ;
								//origen.columna = col_provisional ;
								//origen.orientacion = brujula ;

								//destino.fila = fila_PK(fil_provisional, brujula, i) ;
								//destino.columna = columna_PK(fil_provisional, brujula, i) ;

								//cout << "nivel 3 llamo a pathFinding para ir al PK" << endl;
								//hayPlan = pathFinding(origen, destino, plan);
								//cout << "tengo plan: " << hayPlan << endl;
								//cout << "hola?" << endl;

							}
						}

						//cout << "nivel 3 aún no he encontrado PK" << endl;
*/
						if (sensores.terreno[2] == 'B' or sensores.terreno[2] == 'A' or sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M' or sensores.superficie[2] == 'a') {
							//cout << "nivel 3 no puedo avanzar luego giro" << endl;
							srand(time(NULL));
							int num = rand() %2 ;
							if (num == 0) {
								gira_der();
								return actTURN_R;
							}
							if (num == 1) {
								gira_izq();
								return actTURN_L;
							}
						}
						else {
							//cout << "nivel 3 avanzo" << endl;
							avanza();
							return actFORWARD;
						}
					//} // if (!PK_encontrado)
					estoy_en_PK = (sensores.terreno[0] == 'K');
				} // while
			} // if (!hayPlan)
		} // if (!inicializado)
	} // else

	//cout << "fuera del nivel 3" << endl;


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

		//cout << "entro al pathFinding" << endl;
  	hayPlan = pathFinding(origen,destino,plan);
		//cout << "salgo al pathFinding" << endl;
	}

	// Ejecutar el plan
	Action sigAccion;
	if (hayPlan and plan.size()>0){
		sigAccion = plan.front();
		if (sigAccion == actFORWARD and sensores.superficie[2] == 'a') {
			//cout << "hay alguien delante" << endl ;
			/*switch (brujula) {
				case 0: mapa_transitable[fil-1][col] = false ;
				case 1: mapa_transitable[fil][col+1] = false ;
				case 2: mapa_transitable[fil+1][col] = false ;
				case 3: mapa_transitable[fil][col-1] = false ;
			}
			estado origen;
			origen.fila = fil;
			origen.columna = col;
			origen.orientacion = brujula;

			destino.fila = sensores.destinoF;
			destino.columna = sensores.destinoC;
		//	cerr << "core2" << endl;
			hayPlan = pathFinding(origen,destino,plan);
			//cerr << "core3" << endl;

			switch (brujula) {
				case 0: mapa_transitable[fil-1][col] = true ;
				case 1: mapa_transitable[fil][col+1] = true ;
				case 2: mapa_transitable[fil+1][col] = true ;
				case 3: mapa_transitable[fil][col-1] = true ;
			}
			*/
			sigAccion = actIDLE;
			//cout << "no hago nada" << endl ;
			//sigAccion = plan.front();
			//plan.erase(plan.begin());

		} // if (sigAccion == actFORWARD and sensores.superficie[2] == 'a')

		else {
			if (sigAccion == actFORWARD and (sensores.terreno[2] == 'B' or sensores.terreno[2] == 'A' or sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M')) {
				cout << "recalculo ruta" << endl;
				estado origen;
				origen.fila = fil;
				origen.columna = col;
				origen.orientacion = brujula;

				destino.fila = sensores.destinoF;
				destino.columna = sensores.destinoC;

				hayPlan = false ;
				return actIDLE;

			}
			else
				plan.erase(plan.begin());

		}

	}
	else {
		//cout << "no hago nada";
		sigAccion = actIDLE;
	}

	//cout << "antes de actualizar" << endl;
	actualiza_mapa(sensores);
	//cout << "ddespues de actualizar" << endl;

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
	//cout << "avanzo" << endl ;
	//cout << "en la casilla de delante (" << fil << "," << col << ") hay"  << mapa[fil][col] << endl;
}

void ComportamientoJugador::gira_der() {
	brujula = (brujula+1)%4 ;
	//cout << "giro a la derecha" << endl ;
}

void ComportamientoJugador::gira_izq() {
	brujula = (brujula+3)%4 ;
	//cout << "giro a la izquierda" << endl ;
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
int ComportamientoJugador::fila_PK(int fil_actual, int brujula, int i) {

	switch (brujula) {
		case 0:
			switch (i) {
				case 1: case 2: case 3: return fil_actual-1 ; break;
				case 4: case 5: case 6: case 7: case 8: return fil_actual-2 ; break;
				case 9: case 10: case 11: case 12: case 13: case 14: case 15: return fil_actual-3 ; break;
			}
			break;

		case 1:
			switch (i) {
				case 1: return fil_actual-1 ; break;
				case 2: return fil_actual; break;
				case 3: return fil_actual+1; break;
				case 4: return fil_actual-2; break;
				case 5: return fil_actual-1; break;
				case 6: return fil_actual; break;
				case 7: return fil_actual+1; break;
				case 8: return fil_actual+2; break;
				case 9: return fil_actual+3; break;
				case 10: return fil_actual+2; break;
				case 11: return fil_actual+1; break;
				case 12: return fil_actual; break;
				case 13: return fil_actual-1; break;
				case 14: return fil_actual-2; break;
				case 15: return fil_actual-3; break;
			}
			break;

		case 2:
			switch (i) {
				case 1: case 2: case 3: return fil_actual+1 ; break;
				case 4: case 5: case 6: case 7: case 8: return fil_actual+2 ; break;
				case 9: case 10: case 11: case 12: case 13: case 14: case 15: return fil_actual+3 ; break;
			}
			break;

		case 3:
			switch (i) {
				case 1: return fil_actual-1 ; break;
				case 2: return fil_actual; break;
				case 3: return fil_actual+1; break;
				case 4: return fil_actual-2; break;
				case 5: return fil_actual-1; break;
				case 6: return fil_actual; break;
				case 7: return fil_actual+1; break;
				case 8: return fil_actual+2; break;
				case 9: return fil_actual+3; break;
				case 10: return fil_actual+2; break;
				case 11: return fil_actual+1; break;
				case 12: return fil_actual; break;
				case 13: return fil_actual-1; break;
				case 14: return fil_actual-2; break;
				case 15: return fil_actual-3; break;
			}
			break;
	}
}

int ComportamientoJugador::columna_PK(int col_actual, int brujula, int i) {

	switch (brujula) {
		case 0:
			switch (i) {
				case 1: return col_actual-1 ; break;
				case 2: return col_actual; break;
				case 3: return col_actual+1; break;
				case 4: return col_actual-2; break;
				case 5: return col_actual-1; break;
				case 6: return col_actual; break;
				case 7: return col_actual+1; break;
				case 8: return col_actual+2; break;
				case 9: return col_actual-3; break;
				case 10: return col_actual-2; break;
				case 11: return col_actual-1; break;
				case 12: return col_actual; break;
				case 13: return col_actual+1; break;
				case 14: return col_actual+2; break;
				case 15: return col_actual+3; break;
			}
			break;

		case 1:
			switch (i) {
				case 1: case 2: case 3: return col_actual+1 ; break;
				case 4 : case 5: case 6: case 7: case 8: return col_actual+2; break;
				case 9: case 10: case 11: case 12: case 13: case 14: case 15: return col_actual+3; break;
			}
			break;

		case 2:
			switch (i) {
				case 1: return col_actual+1 ; break;
				case 2: return col_actual; break;
				case 3: return col_actual-1; break;
				case 4: return col_actual+2; break;
				case 5: return col_actual+1; break;
				case 6: return col_actual; break;
				case 7: return col_actual-1; break;
				case 8: return col_actual-2; break;
				case 9: return col_actual+3; break;
				case 10: return col_actual+2; break;
				case 11: return col_actual+1; break;
				case 12: return col_actual; break;
				case 13: return col_actual-1; break;
				case 14: return col_actual-2; break;
				case 15: return col_actual-3;	break;
			}
			break;


		case 3:
			switch (i) {
				case 1: case 2: case 3: return col_actual-1 ; break;
				case 4: case 5: case 6: case 7: case 8: return col_actual-2; break;
				case 9: case 10: case 11: case 12: case 13: case 14: case 15: return col_actual-3; break;
			}
			break;
	}

}
*/

void ComportamientoJugador::actualiza_mapa(Sensores &sensores) {

	int cont = 0 ;

	//cout << "posicion del jugador = {" << fil << "," << col << "," << brujula << "}" << endl;

	if (brujula==0) {
		//cout << "mirando al norte" << endl;
		for (int i = 0 ; i >-4 ; i--) {
			for (int j = i ; j <=-i; j++) {
				if (mapaResultado[fil+i][col+j] == '?')
					mapaResultado[fil+i][col+j] = sensores.terreno[cont] ;
				//cout << "fila= " << fil+i << ", col= " << col+j << ", terreno= " << sensores.terreno[cont] << endl;
				cont++;
			}
		}
	}

	if (brujula==1) {
		//cout << "mirando al este" << endl;
		for (int j = 0 ; j < 4 ; j++) {
			for (int i = -j ; i <=j; i++) {
				if (mapaResultado[fil+i][col+j] == '?')
					mapaResultado[fil+i][col+j] = sensores.terreno[cont] ;
				//cout << "fila= " << fil+i << ", col= " << col+j << ", terreno= " << sensores.terreno[cont] << endl;
				cont++;
			}
		}
	}

	if (brujula==2) {
		//cout << "mirando al sur" << endl;
		for (int i = 0 ; i < 4 ; i++) {
			for (int j = i ; j >=-i; j--) {
				if (mapaResultado[fil+i][col+j] == '?')
					mapaResultado[fil+i][col+j] = sensores.terreno[cont] ;
				//cout << "fila= " << fil+i << ", col= " << col+j << ", terreno= " << sensores.terreno[cont] << endl;
				cont++;
			}
		}
	}

	if (brujula==3) {
		//cout << "mirando al oeste" << endl;
		for (int j = 0 ; j >-4 ; j--) {
			for (int i = -j ; i >=j; i--) {
				if (mapaResultado[fil+i][col+j] == '?')
					mapaResultado[fil+i][col+j] = sensores.terreno[cont] ;
				//cout << "fila= " << fil+i << ", col= " << col+j << ", terreno= " << sensores.terreno[cont] << endl;
				cont++;
			}
		}
	}

}

/*
void ComportamientoJugador::actualiza_mapa(int fil_actual, int col_actual, int brujula, Sensores sensores, bool uso_mapa3) {

	if (uso_mapa3) {
		switch (brujula) {
			case 0:
				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 1: mapa3[fil_actual-1][col_actual-1] = sensores.terreno[1] ; break;
						case 2: cout << "fil=" << fil_actual << " , col =" << col_actual << " , terreno =" << sensores.terreno[2] << endl ;mapa3[fil_actual-1][col_actual] = sensores.terreno[2] ; break;
						case 3: mapa3[fil_actual+1][col_actual+1] = sensores.terreno[3] ; break;
						case 4: mapa3[fil_actual-2][col_actual-2] = sensores.terreno[4] ; break;
						case 5: mapa3[fil_actual-2][col_actual-1] = sensores.terreno[5] ; break;
						case 6: mapa3[fil_actual-2][col_actual] = sensores.terreno[6] ; break;
						case 7: mapa3[fil_actual-2][col_actual+1] = sensores.terreno[7] ; break;
						case 8: mapa3[fil_actual-2][col_actual+2] = sensores.terreno[8] ; break;
						case 9: mapa3[fil_actual-3][col_actual-3] = sensores.terreno[9] ; break;
						case 10: mapa3[fil_actual-3][col_actual-2] = sensores.terreno[10] ; break;
						case 11: mapa3[fil_actual-3][col_actual-1] = sensores.terreno[11] ; break;
						case 12: mapa3[fil_actual-3][col_actual] = sensores.terreno[12] ; break;
						case 13: mapa3[fil_actual-3][col_actual+1] = sensores.terreno[13] ; break;
						case 14: mapa3[fil_actual-3][col_actual+2] = sensores.terreno[14] ; break;
						case 15: mapa3[fil_actual-3][col_actual+3] = sensores.terreno[15] ; break;
					}
				}
				break;

			case 1:
				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 1: mapa3[fil_actual-1][col_actual+1] = sensores.terreno[1] ; break;
						case 2: mapa3[fil_actual][col_actual+1] = sensores.terreno[2] ; break;
						case 3: mapa3[fil_actual+1][col_actual+1] = sensores.terreno[3] ; break;
						case 4: mapa3[fil_actual-2][col_actual+2] = sensores.terreno[4] ; break;
						case 5: mapa3[fil_actual-1][col_actual+2] = sensores.terreno[5] ; break;
						case 6: mapa3[fil_actual][col_actual+2] = sensores.terreno[6] ; break;
						case 7: mapa3[fil_actual+1][col_actual+2] = sensores.terreno[7] ; break;
						case 8: mapa3[fil_actual+2][col_actual+2] = sensores.terreno[8] ; break;
						case 9: mapa3[fil_actual-3][col_actual+3] = sensores.terreno[9] ; break;
						case 10: mapa3[fil_actual-2][col_actual+3] = sensores.terreno[10] ; break;
						case 11: mapa3[fil_actual-1][col_actual+3] = sensores.terreno[11] ; break;
						case 12: mapa3[fil_actual][col_actual+3] = sensores.terreno[12] ; break;
						case 13: mapa3[fil_actual+1][col_actual+3] = sensores.terreno[13] ; break;
						case 14: mapa3[fil_actual+2][col_actual+3] = sensores.terreno[14] ; break;
						case 15: mapa3[fil_actual+3][col_actual+3] = sensores.terreno[15] ; break;
					}
				}
				break;

			case 2:

				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 1: mapa3[fil_actual+1][col_actual+1] = sensores.terreno[1] ; break;
						case 2: mapa3[fil_actual+1][col_actual] = sensores.terreno[2] ; break;
						case 3: mapa3[fil_actual+1][col_actual-1] = sensores.terreno[3] ; break;
						case 4: mapa3[fil_actual+2][col_actual+2] = sensores.terreno[4] ; break;
						case 5: mapa3[fil_actual+2][col_actual+1] = sensores.terreno[5] ; break;
						case 6: mapa3[fil_actual+2][col_actual] = sensores.terreno[6] ; break;
						case 7: mapa3[fil_actual+2][col_actual-1] = sensores.terreno[7] ; break;
						case 8: mapa3[fil_actual+2][col_actual-2] = sensores.terreno[8] ; break;
						case 9: mapa3[fil_actual+3][col_actual+3] = sensores.terreno[9] ; break;
						case 10: mapa3[fil_actual+3][col_actual+2] = sensores.terreno[10] ; break;
						case 11: mapa3[fil_actual+3][col_actual+1] = sensores.terreno[11] ; break;
						case 12: mapa3[fil_actual+3][col_actual] = sensores.terreno[12] ; break;
						case 13: mapa3[fil_actual+3][col_actual-1] = sensores.terreno[13] ; break;
						case 14: mapa3[fil_actual+3][col_actual-2] = sensores.terreno[14] ; break;
						case 15: mapa3[fil_actual+3][col_actual-3] = sensores.terreno[15] ; break;
					}
				}
				break;

			case 3:

				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 1: mapa3[fil_actual-1][col_actual-1] = sensores.terreno[1] ; break;
						case 2: mapa3[fil_actual][col_actual-1] = sensores.terreno[2] ; break;
						case 3: mapa3[fil_actual+1][col_actual-1] = sensores.terreno[3] ; break;
						case 4: mapa3[fil_actual-2][col_actual-2] = sensores.terreno[4] ; break;
						case 5: mapa3[fil_actual-1][col_actual-2] = sensores.terreno[5] ; break;
						case 6: mapa3[fil_actual][col_actual-2] = sensores.terreno[6] ; break;
						case 7: mapa3[fil_actual+1][col_actual-2] = sensores.terreno[7] ; break;
						case 8: mapa3[fil_actual+2][col_actual-2] = sensores.terreno[8] ; break;
						case 9: mapa3[fil_actual-3][col_actual-3] = sensores.terreno[9] ; break;
						case 10: mapa3[fil_actual-2][col_actual-3] = sensores.terreno[10] ; break;
						case 11: mapa3[fil_actual-1][col_actual-3] = sensores.terreno[11] ; break;
						case 12: mapa3[fil_actual][col_actual-3] = sensores.terreno[12] ; break;
						case 13: mapa3[fil_actual+1][col_actual-3] = sensores.terreno[13] ; break;
						case 14: mapa3[fil_actual+2][col_actual-3] = sensores.terreno[14] ; break;
						case 15: mapa3[fil_actual+3][col_actual-3] = sensores.terreno[15] ; break;
					}
				}
				break;

		}
	}

	else {

		switch (brujula) {
			case 0:
				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 0: mapaResultado[fil_actual][col_actual] = sensores.terreno[0] ; break;
						case 1: mapaResultado[fil_actual-1][col_actual-1] = sensores.terreno[1] ; break;
						case 2: mapaResultado[fil_actual-1][col_actual] = sensores.terreno[2] ; break;
						case 3: mapaResultado[fil_actual+1][col_actual+1] = sensores.terreno[3] ; break;
						case 4: mapaResultado[fil_actual-2][col_actual-2] = sensores.terreno[4] ; break;
						case 5: mapaResultado[fil_actual-2][col_actual-1] = sensores.terreno[5] ; break;
						case 6: mapaResultado[fil_actual-2][col_actual] = sensores.terreno[6] ; break;
						case 7: mapaResultado[fil_actual-2][col_actual+1] = sensores.terreno[7] ; break;
						case 8: mapaResultado[fil_actual-2][col_actual+2] = sensores.terreno[8] ; break;
						case 9: mapaResultado[fil_actual-3][col_actual-3] = sensores.terreno[9] ; break;
						case 10: mapaResultado[fil_actual-3][col_actual-2] = sensores.terreno[10] ; break;
						case 11: mapaResultado[fil_actual-3][col_actual-1] = sensores.terreno[11] ; break;
						case 12: mapaResultado[fil_actual-3][col_actual] = sensores.terreno[12] ; break;
						case 13: mapaResultado[fil_actual-3][col_actual+1] = sensores.terreno[13] ; break;
						case 14: mapaResultado[fil_actual-3][col_actual+2] = sensores.terreno[14] ; break;
						case 15: mapaResultado[fil_actual-3][col_actual+3] = sensores.terreno[15] ; break;
					}
				}
				break;

			case 1:
				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 0: mapaResultado[fil_actual][col_actual] = sensores.terreno[0] ; break;
						case 1: mapaResultado[fil_actual-1][col_actual+1] = sensores.terreno[1] ; break;
						case 2: mapaResultado[fil_actual][col_actual+1] = sensores.terreno[2] ; break;
						case 3: mapaResultado[fil_actual+1][col_actual+1] = sensores.terreno[3] ; break;
						case 4: mapaResultado[fil_actual-2][col_actual+2] = sensores.terreno[4] ; break;
						case 5: mapaResultado[fil_actual-1][col_actual+2] = sensores.terreno[5] ; break;
						case 6: mapaResultado[fil_actual][col_actual+2] = sensores.terreno[6] ; break;
						case 7: mapaResultado[fil_actual+1][col_actual+2] = sensores.terreno[7] ; break;
						case 8: mapaResultado[fil_actual+2][col_actual+2] = sensores.terreno[8] ; break;
						case 9: mapaResultado[fil_actual-3][col_actual+3] = sensores.terreno[9] ; break;
						case 10: mapaResultado[fil_actual-2][col_actual+3] = sensores.terreno[10] ; break;
						case 11: mapaResultado[fil_actual-1][col_actual+3] = sensores.terreno[11] ; break;
						case 12: mapaResultado[fil_actual][col_actual+3] = sensores.terreno[12] ; break;
						case 13: mapaResultado[fil_actual+1][col_actual+3] = sensores.terreno[13] ; break;
						case 14: mapaResultado[fil_actual+2][col_actual+3] = sensores.terreno[14] ; break;
						case 15: mapaResultado[fil_actual+3][col_actual+3] = sensores.terreno[15] ; break;
					}
				}
				break;

			case 2:

				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 0: mapaResultado[fil_actual][col_actual] = sensores.terreno[0] ; break;
						case 1: mapaResultado[fil_actual+1][col_actual+1] = sensores.terreno[1] ; break;
						case 2: mapaResultado[fil_actual+1][col_actual] = sensores.terreno[2] ; break;
						case 3: mapaResultado[fil_actual+1][col_actual-1] = sensores.terreno[3] ; break;
						case 4: mapaResultado[fil_actual+2][col_actual+2] = sensores.terreno[4] ; break;
						case 5: mapaResultado[fil_actual+2][col_actual+1] = sensores.terreno[5] ; break;
						case 6: mapaResultado[fil_actual+2][col_actual] = sensores.terreno[6] ; break;
						case 7: mapaResultado[fil_actual+2][col_actual-1] = sensores.terreno[7] ; break;
						case 8: mapaResultado[fil_actual+2][col_actual-2] = sensores.terreno[8] ; break;
						case 9: mapaResultado[fil_actual+3][col_actual+3] = sensores.terreno[9] ; break;
						case 10: mapaResultado[fil_actual+3][col_actual+2] = sensores.terreno[10] ; break;
						case 11: mapaResultado[fil_actual+3][col_actual+1] = sensores.terreno[11] ; break;
						case 12: mapaResultado[fil_actual+3][col_actual] = sensores.terreno[12] ; break;
						case 13: mapaResultado[fil_actual+3][col_actual-1] = sensores.terreno[13] ; break;
						case 14: mapaResultado[fil_actual+3][col_actual-2] = sensores.terreno[14] ; break;
						case 15: mapaResultado[fil_actual+3][col_actual-3] = sensores.terreno[15] ; break;
					}
				}
				break;

			case 3:

				for (int i = 0 ; i < 16 ; i++) {
					switch (i) {
						case 0: mapaResultado[fil_actual][col_actual] = sensores.terreno[0] ; break;
						case 1: mapaResultado[fil_actual-1][col_actual-1] = sensores.terreno[1] ; break;
						case 2: mapaResultado[fil_actual][col_actual-1] = sensores.terreno[2] ; break;
						case 3: mapaResultado[fil_actual+1][col_actual-1] = sensores.terreno[3] ; break;
						case 4: mapaResultado[fil_actual-2][col_actual-2] = sensores.terreno[4] ; break;
						case 5: mapaResultado[fil_actual-1][col_actual-2] = sensores.terreno[5] ; break;
						case 6: mapaResultado[fil_actual][col_actual-2] = sensores.terreno[6] ; break;
						case 7: mapaResultado[fil_actual+1][col_actual-2] = sensores.terreno[7] ; break;
						case 8: mapaResultado[fil_actual+2][col_actual-2] = sensores.terreno[8] ; break;
						case 9: mapaResultado[fil_actual-3][col_actual-3] = sensores.terreno[9] ; break;
						case 10: mapaResultado[fil_actual-2][col_actual-3] = sensores.terreno[10] ; break;
						case 11: mapaResultado[fil_actual-1][col_actual-3] = sensores.terreno[11] ; break;
						case 12: mapaResultado[fil_actual][col_actual-3] = sensores.terreno[12] ; break;
						case 13: mapaResultado[fil_actual+1][col_actual-3] = sensores.terreno[13] ; break;
						case 14: mapaResultado[fil_actual+2][col_actual-3] = sensores.terreno[14] ; break;
						case 15: mapaResultado[fil_actual+3][col_actual-3] = sensores.terreno[15] ; break;
					}
				}
				break;

		}

	}


}

*/
