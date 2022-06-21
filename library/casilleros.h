//Autor original: Juan Manuel Amores (Dingo) 2022.
#include <string>
#include <list>
#include "enemigo.h"
#include "item.h"
#include "jugador.h"

class Casilla{
private:
    list<Item> items;
    string descripcion = "\0";
    string descripcionextra = "\0";
    string descripcionCorta = "\0";
    Enemigo goblin;
    bool boolHayEnemigo = false;

public:
    Casilla(){ }

    void setDescripcion(string s){
        this->descripcion = s;
    }

    string getDescripcion(){
        return descripcion;
    }

    void setDescripcionCorta(string s){
        this->descripcionCorta = s;
    }

    string getDescripcionCorta(){
        return descripcionCorta;
    }

    void setDescripcionExtra(string s){
        this->descripcionextra = s;
    }

    string getDescripcionExtra(){
        return descripcionextra;
    }

    void agregarItem(Item i){
        this->items.push_back(i);
    }

    bool tieneItems(){
        return(!items.empty()); // Sin items = 0, con items = 1;
    }

    void imprimirLista(){
        cout << "Items en la habitacion: \n\n";
        for(std::list<Item>::iterator it = items.begin(); it!= items.end(); ++it)
            std::cout << *it;
    }

    void agregarItemsAlJugador(Jugador &ju){
        ju.agregarItems(items);
    }

    void agregarEnemigo(Enemigo &g){
        this->goblin = g;
        this->boolHayEnemigo = true;
    }

    unsigned int getSaludEnemigo(){
        return (this->goblin.vidaEnemigo() );
    }

    void quitarEnemigoDelCasillero(){
        boolHayEnemigo = false;
    }

    string getDescripcionEnemigo(){
        return (this->goblin.presentacionDelEnemigo());
    }

    bool hayEnemigo(){
        return (this->boolHayEnemigo);
    }

    void getEstatusEnemigo(){
        goblin.estatusEnemigo();
    }

    void bajarPSEnemigo(short int atq){
        goblin.setPSEnemigo(atq);
    }

    short int getPAEnemigo(){
        return (goblin.getPAEnemigo() );
    }

};
