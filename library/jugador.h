//Autor original: Juan Manuel Amores (Dingo) 2022.
#include <list>
class Jugador{
private:
    short int PS; // Puntos salud.
    short int PA; // Puntos ataque.
    short int PB; // Puntos blindaje.
    bool boolAddPA = false;
    bool boolAddPB = false;
    list<Item> inventario;

    void addPAjugador(){
        Item i;
        if(boolAddPA == false){
            for(std::list<Item>::iterator it = inventario.begin(); it!= inventario.end(); ++it){
                i = *it;
                if(i.getTipoItem() == ARMA){
                    this->PA = this->PA + i.getItemPA();
                    boolAddPA = true;
                }
            }
        }
    }

    void addPBjugador(){
        Item i;
        if(boolAddPB == false){
            for(std::list<Item>::iterator it = inventario.begin(); it!= inventario.end(); ++it){
                i = *it;
                if(i.getTipoItem() == BLINDAJE){
                    this->PB = this->PB + i.getItemPB();
                    boolAddPB = true;
                }
            }
        }
    }

public:
    Jugador(){
        PS = 100;
        PA = 5;
        PB = 1;
    }

    short int getPSjugador(){
        return (this->PS);
    }

    short int getPAjugador(){
        return (this->PA);
    }

    void bajarVida(short int ataque){
        if(ataque > this->PB){
            this->PS = this->PS - (ataque - this->PB);
        }
    }

    void addPSjugador(){
        Item i;
        short int calc_aux = 0;
        for(std::list<Item>::iterator it = this->inventario.begin(); it!= this->inventario.end(); ++it){
            i = *it;
            if(i.getTipoItem() == ALIMENTO){
                calc_aux = (this->PS + i.getItemPS() ) - 100;
                this->PS = (this->PS + i.getItemPS() ) - calc_aux;
                it = inventario.erase(it);
            }
        }

    }

    void agregarItems(list<Item> &in){
        while(!in.empty()){
            this->inventario.push_back(in.front());
            in.pop_front();
        }
        addPAjugador();
        addPBjugador();
    }

    void verInventario(){
        for(std::list<Item>::iterator it = inventario.begin(); it!= inventario.end(); ++it)
            std::cout << *it;
    }

    void verEstatus(){
        std::cout << "Salud: " << (int)this->PS << "\n";
        std::cout << "Ataque: " << (int)this->PA << "\n";
        std::cout << "Blindaje: " << (int)this->PB << "\n";
    }

    bool tieneAlimentos(){
        bool tiene = false;
        Item i;
        for(std::list<Item>::iterator it = this->inventario.begin(); it!= this->inventario.end(); ++it){
            i = *it;
            if(i.getTipoItem() == ALIMENTO){
                tiene = true;
            }
        }
        return tiene;
    }

};
