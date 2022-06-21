//Autor original: Juan Manuel Amores (Dingo) 2022.
enum tipoItem {NO_ASIGNADO, ALIMENTO, ARMA, BLINDAJE, RECOMPENSA};

class Item{
private:
    tipoItem tipo;
    string nombre;
    unsigned char ItemPS; // Puntos salud.
    unsigned char ItemPA; // Puntos ataque.
    unsigned char ItemPB; // Puntos blindaje/armadura.

public:

    Item(){
        tipo = NO_ASIGNADO;
        nombre = "Por defecto.\n\n";
        ItemPS = 0;
        ItemPA = 0;
        ItemPB = 0;
    }

    Item(tipoItem t, string n, unsigned int Ips, unsigned int Ipa, unsigned int Ipb){
        this->tipo = t;
        this->nombre = n;
        this->ItemPS = Ips;
        this->ItemPA = Ipa;
        this->ItemPB = Ipb;
    }

    tipoItem getTipoItem(){
        return this->tipo;
    }

    string getItemNombre(){
        return this->nombre;
    }

    short int getItemPS(){
        return (this->ItemPS);
    }

    short int getItemPA(){
        return (this->ItemPA);
    }

    short int getItemPB(){
        return (this->ItemPB);
    }

    friend ostream& operator << (ostream& out, const Item &i){
        return out << i.nombre;
    }

};
