#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct estado {
  int fila;
  int columna;
  int orientacion;
};

class Nodo {
  private:
    estado state ;
    Nodo * padre ;
    int coste ;

  public:
    Nodo (const estado &miestado, Nodo* mipadre, int micoste) {
      state = miestado ;
      padre = mipadre ;
      coste = micoste ;
    }

    Nodo (const Nodo &n) {
      state = n.getEstado();
      padre = n.getPadre();
      coste = n.getCoste();
    }

    estado getEstado() const {
      return state ;
    }

    int getCoste() const {
      return coste ;
    }

    Nodo* getPadre() const {
      return padre ;
    }

    void setCoste(int c) {
      coste = c ;
    }

};

/*
bool cmp(const Nodo* n1, const Nodo* n2) {
  return (n1->getCoste() < n2->getCoste());
}
*/

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      //inicializado = false ;
      ultimaAccion = actIDLE;
      hayPlan = false;
      /*
      for (int i = 0 ; i < TAM ; i++) {
        for (int j = 0 ; j < TAM ; j++) {
          for (int k = 0 ; k < 4 ; k++) {
            nodos_cerrados[i][j][k] = false ;
            nodos_abiertos[i][j][k] = {false, -1} ; // ?????
          }
        }
      }
    */
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      //inicializado = false ;
      ultimaAccion = actIDLE;
      hayPlan = false;
      mapa = mapaR ;
      for (int i = 0 ; i < mapaR.size() ; i++) {
	       for (int j = 0 ; j < mapaR.size() ; j++) {
	          if (mapa[i][j] == 'B' || mapa[i][j] == 'A' || mapa[i][j] == 'P' || mapa[i][j] == 'M')
			         mapa_transitable[i][j] = false ;
            else
			 	       mapa_transitable[i][j] = true ;
		      }
	    }

    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

    //void adyacentes (Nodo* actual, list<Nodo*> &abiertos);

  private:
    // Declarar Variables de Estado
    int fil, col, brujula;
    estado destino;
    list<Action> plan;

    // Nuevas Variables de Estado
    Action ultimaAccion;
    bool hayPlan;
    static const int TAM= 100 ;
    bool inicializado;
    vector< vector<unsigned char> > mapa ;
    bool mapa_transitable[TAM][TAM];
    bool nodos_cerrados[TAM][TAM][4] ;
    pair<bool, int> nodos_abiertos [TAM][TAM][4] ;

    bool pathFinding(const estado &origen, const estado &destino, list<Action> &plan);
    void PintaPlan(list<Action> plan);

    void avanza ();
    void gira_izq ();
    void gira_der ();
    //void ubica (Sensores sensores);
    bool esIgual(const estado &primero , const estado &segundo);
    bool esCerrado(Nodo n) ;
    bool esAbierto(Nodo n) ;
    int heuristica(const estado &origen, const estado &destino);
    void construyePlan(list<Action> &plan, list<Nodo*> mejorCamino); // Paso una copia para no romper el mejorCamino

};

#endif
