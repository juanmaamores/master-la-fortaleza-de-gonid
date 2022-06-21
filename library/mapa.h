//Autor original: Juan Manuel Amores (Dingo) 2022.
#include "casilleros.h"

struct Nodo {
public:
    Casilla c;
    Nodo *norte;
    Nodo *sur;
    Nodo *este;
    Nodo *oeste;
};

class Mapa{
private:
    typedef Nodo *posicion;
    posicion raiz, nodo_actual;
    //inicializo al jugador.
    Jugador j;

public:
    Mapa(){
        //creo los items.
        Item alimentos(ALIMENTO, "Alimentos.\n", 25, 0, 0);
        Item espada(ARMA, "Espada nivel 1: ---)======>\n", 0, 20, 0);
        Item armadura(BLINDAJE, "Armadura nivel 1.\n", 0, 0, 10);
        Item bolsaDeOro(RECOMPENSA, "Bolsa de oro.\n", 0, 0, 0);
        Enemigo goblin(GOBLIN, (char)100, (unsigned char)31, (unsigned char)10, "Te has encontrado con un goblin hostil bloqueando tu camino... atacar o huir?\n");
        // Inicializacion del mapa.
        // Casillero inicial.
        raiz = new Nodo;
        raiz->norte = NULL;
        raiz->sur = NULL;
        raiz->este = NULL;
        raiz->oeste = NULL;
        raiz->c.setDescripcion("Estas en una habitacion en ruinas, la luz es tenue y sientes un ligero olor a humedad.\n");
        raiz->c.setDescripcionExtra("Tienes la sensacion de que debes seguir avanzando.\n");
        raiz->c.setDescripcionCorta("Estas en una habitacion en ruinas.\n");
        // Sala norte.
        agregarNodoNorte(raiz);
        nodo_actual = *moverAlNorte(raiz);
        nodo_actual->c.setDescripcion("Las paredes de este pasillo estan resquebrejadas y con un poco de moho, ves una interseccion al fondo.\n");
        nodo_actual->c.setDescripcionExtra("Un pasillo ordinario... con algunas pinturas viejas sin valor.\n");
        nodo_actual->c.setDescripcionCorta("Estas en un pasillo deteriorado.\n");
        // Sala T.
        agregarNodoNorte(nodo_actual);
        nodo_actual = *moverAlNorte(nodo_actual);
        nodo_actual->c.setDescripcion("Llegas a una T, hay dos puertas, una de cada lado. Debes tomar una decision.\n");
        nodo_actual->c.setDescripcionExtra("Una simple interseccion sin nada interesante.\n");
        nodo_actual->c.setDescripcionCorta("Hay dos caminos posibles, izquierda o derecha.\n");
        // Sala goblin.
        agregarNodoOeste(nodo_actual);
        nodo_actual = *moverAlOeste(nodo_actual);
        nodo_actual->c.setDescripcion("Has entrado en la sala del goblin\n");
        nodo_actual->c.setDescripcionExtra("La salida esta en esta sala.\n");
        nodo_actual->c.setDescripcionCorta("No hay mucho que decir...\n");
        nodo_actual->c.agregarEnemigo(goblin);
        // Salida!
        agregarNodoOeste(nodo_actual);
        nodo_actual = *moverAlOeste(nodo_actual);
        nodo_actual->c.setDescripcion("Lograste escapar de la fortaleza. Felicidades has ganado! FIN DEL JUEGO.\n");
        //Vuelvo atras.
        nodo_actual = *moverAlEste(nodo_actual);
        nodo_actual = *moverAlEste(nodo_actual);
        // Sala de armas.
        agregarNodoEste(nodo_actual);
        nodo_actual = *moverAlEste(nodo_actual);
        nodo_actual->c.setDescripcion("Estas en lo que parece ser una sala de armas. Si aun no lo has hecho toma algo con que defenderte.\n");
        nodo_actual->c.setDescripcionExtra("Decides mirar bien tu alrededor y descubres una puerta secreta al Este.\n");
        nodo_actual->c.setDescripcionCorta("Estas en la armeria.\n");
        nodo_actual->c.agregarItem(espada);
        nodo_actual->c.agregarItem(armadura);
        // Sala secreta.
        agregarNodoEste(nodo_actual);
        nodo_actual = *moverAlEste(nodo_actual);
        nodo_actual->c.setDescripcion("Has logrado entrar a la habitacion secreta! y hay algo sobre la mesa...\n");
        nodo_actual->c.setDescripcionExtra("Decides investigar un poco la habitacion y no encuentras nada mas.\n");
        nodo_actual->c.setDescripcionCorta("Sigues en la habitacion secreta.\n");
        nodo_actual->c.agregarItem(alimentos);
        nodo_actual->c.agregarItem(bolsaDeOro);
    }

    Nodo **obtenerRaiz(){
        return &(raiz);
    }

    void agregarNodoNorte(Nodo *&p){
        Nodo *aux;
        p->norte = new Nodo;
        aux = p->norte;
        aux->sur = p;
        aux->este = NULL;
        aux->oeste = NULL;
    }

    void agregarNodoSur(Nodo *&p){
        Nodo *aux;
        p->sur = new Nodo;
        aux = p->sur;
        aux->norte = p;
        aux->este = NULL;
        aux->oeste = NULL;
    }

    void agregarNodoEste(Nodo *&p){
        Nodo *aux;
        p->este = new Nodo;
        aux = p->este;
        aux->oeste = p;
        aux->norte = NULL;
        aux->sur = NULL;
    }

    void agregarNodoOeste(Nodo *&p){
        Nodo *aux;
        p->oeste = new Nodo;
        aux = p->oeste;
        aux->este = p;
        aux->norte = NULL;
        aux->sur = NULL;
    }

    Nodo **moverAlNorte(Nodo *p){
        return &(p->norte);
    }

    Nodo **moverAlSur(Nodo *p){
        return &(p->sur);
    }

    Nodo **moverAlEste(Nodo *p){
        return &(p->este);
    }

    Nodo **moverAlOeste(Nodo *p){
        return &(p->oeste);
    }

    string obtenerDescripcion(Nodo *p){
        return(p->c.getDescripcion());
    }

    string obtenerDescripcionCorta(Nodo *p){
        return(p->c.getDescripcionCorta());
    }

    string obtenerDescripcionExtra(Nodo *p){
        return(p->c.getDescripcionExtra());
    }

    bool obtenerTieneItems(Nodo *p){
        return(p->c.tieneItems());
    }

    void verItemsDelCasillero(Nodo *p){
        p->c.imprimirLista();
    }

    void agregarItemsDelCasilleroAlJugador(Nodo *p){
        p->c.agregarItemsAlJugador(j);
    }

    void verInventarioDelJugador(){
        j.verInventario();
    }

    void verEstatusDeljugador(){
        j.verEstatus();
    }

    short int obtenerSaludJugador(){
        return (j.getPSjugador() );
    }

    short int obtenerSaludEnemigo(Nodo *p){
        return (p->c.getSaludEnemigo() );
    }

    void quitarEnemigo(Nodo *p){
        p->c.quitarEnemigoDelCasillero();
    }

    string presentacionEnemigo(Nodo *p){
        return (p->c.getDescripcionEnemigo() );
    }

    bool tieneEnemigos(Nodo *p){
        return (p->c.hayEnemigo() );
    }

    void verEstatusDelEnemigo(Nodo *p){
        p->c.getEstatusEnemigo();
    }

    void curarAlJugador(){
        j.addPSjugador();
    }

    void bajarPSAlEnemigo(Nodo *p){
        p->c.bajarPSEnemigo(j.getPAjugador());
    }

    void bajarPSAlJugador(Nodo *p){
        short int atqEnemigo = p->c.getPAEnemigo();
        j.bajarVida(atqEnemigo);
    }

    bool tieneElJugadorAlimentos(){
        return (j.tieneAlimentos());
    }
};
