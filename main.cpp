//Autor original: Juan Manuel Amores (Dingo) 2022.
using namespace std;
#include <iostream>
#include <ctime>
#include "library/mapa.h"

int main(){
    srand(time(NULL));
    Mapa m;
    string comando;
    string modoAtaque;
    Nodo *pos_actual = *m.obtenerRaiz(), *pos_aux;
    cout << "BIENVENIDO A LA FORTALEZA DE GONID!\n\n\n";
    cout << m.obtenerDescripcion(pos_actual);
    bool gamewin = false;
    if(m.obtenerTieneItems(pos_actual)){
        m.verItemsDelCasillero(pos_actual);
    }
    while(m.obtenerSaludJugador() > 0 && gamewin == false){
        cout << "\n> ";
        cin >> comando;
        cout << "\n";
        if(comando == "n"){
            pos_aux = *m.moverAlNorte(pos_actual);
            if(pos_aux != NULL){
                pos_actual = pos_aux;
                cout << m.obtenerDescripcion(pos_actual);
                if(m.obtenerTieneItems(pos_actual)){
                    m.verItemsDelCasillero(pos_actual);
                }
            } else {
                cout << "No podes ir en esa direccion.\n";
                cout << m.obtenerDescripcionCorta(pos_actual);
            }
        }
        if(comando == "s"){
            pos_aux = *m.moverAlSur(pos_actual);
            if(pos_aux != NULL){
                pos_actual = pos_aux;
                cout << m.obtenerDescripcion(pos_actual);
                if(m.obtenerTieneItems(pos_actual)){
                    m.verItemsDelCasillero(pos_actual);
                }
            } else {
                cout << "No podes ir en esa direccion.\n";
                cout << m.obtenerDescripcionCorta(pos_actual);
            }
        }
        if(comando == "e"){
            pos_aux = *m.moverAlEste(pos_actual);
            if(pos_aux != NULL){
                pos_actual = pos_aux;
                cout << m.obtenerDescripcion(pos_actual);
                if(m.obtenerTieneItems(pos_actual)){
                    m.verItemsDelCasillero(pos_actual);
                }
            } else {
                cout << "No podes ir en esa direccion.\n";
                cout << m.obtenerDescripcionCorta(pos_actual);
            };
        }
        if(comando == "o"){
            pos_aux = *m.moverAlOeste(pos_actual);
            if(pos_aux != NULL){
                if(m.tieneEnemigos(pos_actual)){
                    cout << "Hay un enemigo! No puedes avanzar, solo retroceder.\n\n";
                    if(m.tieneEnemigos(pos_actual)){
                        m.verEstatusDelEnemigo(pos_actual);
                        cout << "\nTu estatus:\n";
                        m.verEstatusDeljugador();
                    }
                } else {
                    pos_actual = pos_aux;
                    cout << m.obtenerDescripcion(pos_actual);
                    if(m.obtenerDescripcion(pos_actual) == "Lograste escapar de la fortaleza y destruiste al goblin. Felicidades has ganado! FIN DEL JUEGO.\n"){
                        gamewin = true;
                    }
                    if(m.obtenerTieneItems(pos_actual)){
                        m.verItemsDelCasillero(pos_actual);
                    }
                    if(m.tieneEnemigos(pos_actual)){
                        cout << m.presentacionEnemigo(pos_actual) << "\n";
                        m.verEstatusDelEnemigo(pos_actual);
                        cout << "\nTu estatus:\n";
                        m.verEstatusDeljugador();
                    }
                }
            } else {
                cout << "No podes ir en esa direccion.\n";
                cout << m.obtenerDescripcionCorta(pos_actual);
            }
        }
        if(comando == "mirar"){
            cout << m.obtenerDescripcionExtra(pos_actual);
        }
        if(comando == "agarrar"){
            if(m.obtenerTieneItems(pos_actual)){
                m.agregarItemsDelCasilleroAlJugador(pos_actual);
                cout << "Objetos guardados en el inventario.\n\n";
            } else {
                cout << "No hay items para agarrar! \n\n";
            }
        }
        if(comando == "inventario"){
            m.verInventarioDelJugador();
        }
        if(comando == "estatus"){
            m.verEstatusDeljugador();
        }
        if(comando == "atacar"){
            if(m.tieneEnemigos(pos_actual)){
                cout << "MODO ATAQUE: Atacar o curarte?\n\n";
                while(m.obtenerSaludEnemigo(pos_actual) > 0 && m.obtenerSaludJugador() > 0){
                    cin >> modoAtaque;
                    if(modoAtaque != "atacar" && modoAtaque != "curarme"){
                        cout << "Usa: 'atacar' o 'curarme' \n\n";
                    }
                    if(modoAtaque == "atacar"){
                        cout << "Has atacado!\n\n";
                        m.bajarPSAlEnemigo(pos_actual);
                        cout << "Salud del enemigo: " << m.obtenerSaludEnemigo(pos_actual) << "\n\n";
                        cout << "El enemigo ha atacado!\n\n";
                        m.bajarPSAlJugador(pos_actual);
                        cout << "Tu salud: " << m.obtenerSaludJugador() << "\n\n";
                    }
                    if(modoAtaque == "curarme"){
                        if(m.obtenerSaludJugador() == 100){
                            cout << "Tienes la vida llena, no puedes curarte mas.\n\n";
                        } else {
                            if(m.tieneElJugadorAlimentos()){
                                m.curarAlJugador();
                                cout << "Has sido curado! \n\n";
                                cout << "Tu salud: " << m.obtenerSaludJugador() << "\n\n";
                            } else {
                                cout << "No tienes alimentos para curarte! \n\n";
                            }
                        }
                    }
                }
                if(m.obtenerSaludEnemigo(pos_actual) <= 0){
                    cout << "Has matado al enemigo!\n\n";
                    m.quitarEnemigo(pos_actual);
                }
            } else {
                cout << "No hay enemigos aqui!\n\n";
            }
        }

        if( comando != "n" && comando != "s" && comando != "e" && comando != "o" && comando != "mirar" && comando != "agarrar" && comando != "inventario" && comando != "estatus" && comando != "atacar" && comando != "curarme" ){
            short int random = rand() % 4;
            if(random == 0){
                cout << "Leiste los comandos??\n\n";
            }
            if(random == 1){
                cout << "Estas seguro de eso??\n\n";
            }
            if(random == 2){
                cout << "Eso es imposible!!\n\n";
            }
            if(random == 3){
                cout << "Deberias probar otra palabra...\n\n";
            }
        }
    }

    if(m.obtenerSaludJugador() <= 0){
        cout << "\nTe han matado. FIN DEL JUEGO.\n";
    }
    return 0;
}
