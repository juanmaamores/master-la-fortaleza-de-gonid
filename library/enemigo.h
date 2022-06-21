//Autor original: Juan Manuel Amores (Dingo) 2022.

enum tipoEnemigo {SIN_DEFINIR, GOBLIN, ARANIA, LOBO, ARBOL_V, VANDIDO, KOBOLD, DRAGON};

class Enemigo{
private:
    char PS; // Puntos salud.
    unsigned char PA; // Puntos ataque.
    unsigned char PB; // Puntos blindaje.
    string presentacion;
    tipoEnemigo tipo;

public:
    Enemigo(){
        PS = 100;
        PA = 0;
        PB = 0;
        presentacion = "Soy un enemigo generico\n";
        tipo = SIN_DEFINIR;
    }

    Enemigo(tipoEnemigo t, char PSc, unsigned char PAc, unsigned char PBc, string s){
        this->PS = PSc;
        this->PA = PAc;
        this->PB = PBc;
        this->presentacion = s;
        this->tipo = t;
    }

    void setPSEnemigo(short int ataque){
        if(ataque > this->PB){
            this->PS = this->PS - (ataque - this->PB);
        }
    }

    void estatusEnemigo(){
        std::cout << "Estatus del enemigo:\n";
        std::cout << "Salud: " << (int)PS << "\n";
        std::cout << "Ataque: " << (int)PA << "\n";
        std::cout << "Blindaje: " << (int)PB << "\n";
    }

    short int vidaEnemigo(){
        return (this->PS);
    }

    string presentacionDelEnemigo(){
        return presentacion;
    }

    short int getPAEnemigo(){
        return (this->PA);
    }

};
