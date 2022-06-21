# Documentación
Indice:
1. Concepto.
2. Mecánicas del juego.
3. Salas del mapa.
    * Sala secreta.
4. Detalles del juego.
    * Jugador.
    * Enemigos.
    * Armas.
    * Items.
5. Informacion complementaria.
___
## 1. Concepto

Título: La fortaleza de Gonid.

Diseñador: Juan Manuel Amores (Dingo).

Género: Aventura, aventura conversacional.

Plataforma: PC.

Versión: Alpha 1.0

Sinopsis: El jugador se encuentra atrapado en una antigua fortaleza y deberá explorar el lugar para encontrar provisiones, y armas para poder desafiar al temible goblin dueño de la fortaleza y así poder escapar.

Licencia: GPL.

Tecnología: Programado en C++.

Público: Casual. 

___

## 2. Mecánicas del juego

El jugador interactua con el juego a través de comandos simples de una palabras.

Lista de comandos:
* **n**             ( Moverse al norte.) 
* **s**             ( Moverse al sur.) 
* **e**             ( Moverse al este.) 
* **o**             ( Moverse al oeste.) 
* **mirar**         ( Obtener otra descripción de la sala.) 
* **agarrar**       ( Agarrar los objetos de la sala.) 
* **inventario**    ( Ver inventario del jugador.) 
* **estatus**       ( Ver puntos de salud, ataque y blindaje del jugador.) 
* **atacar**        ( Entrar en "modo ataque" o atacar dentro del modo.) 
* **curarme**       ( Curarse dentro del "modo ataque".) 

El jugador se encuentra en una especie de fortaleza, empezando siempre en una sala en concreto. Su objetivo es lograr escapar y así ganar el juego.

La interfaz del juego se basa en una ventana con textos que le van dando al jugador informacion del lugar del mapa donde este se encuentra. El jugador puede solicitar ver su estatus como los puntos de vida o ataque, además puede ver su inventario si lo requiere.

___

## 3. Salas del mapa

El juego se establece sobre un mapa pre inicializado que consta de varias salas, 7 salas en el caso de la demo.

Las salas tienen una primer descripcion, una extra si el jugador solicita "mirar" y una descripcion corta cuando el jugador intenta moverse a una ubicación equivocada.

Cada sala puede contener un ilimitado numero de items y como máximo un enemigo.

El jugador puede moverse libremente entre las salas, tomar los items y atacar a los enemigos que bloqueen su camino. Es necesario eliminar al enemigo primero para poder seguir avanzando por esa ruta.

* ### **Sala secreta**: En la sala secreta se encuentran una bolsa de oro a modo de recompensa al jugado por encontrarla y también hay alimentos que necesitará utilizar para lograr matar al goblin más adelante.

___

## 4. Detalles del juego

**El jugador**: Inicia con 100 puntos de vida, 5 de puntos de ataque (sin armas) y 1 de blindaje (sin aramadura). Puede moverse libremente por la salas a menos que un enemigo le bloquee el camino. Puede agarrar objetos que pueden ayudarlo a completar el juego como un arma, armadura y alimentos. El inventario no tiene un limite máximo de items.

**Enemigos**: De momento hay un solo tipo de enemigo creado, que es el Goblin llamado "Gonid" quien es dueño de la fortaleza y bloquea el camino del jugador para que este pueda llegar a la salida. El goblin tiene 100 *PS,31 *PA, y 10 *PB.

**Armas y armaduras**: La espada de nivel 1, la unica arma en el juego disponible por ahora. Con 20 PA. Y la armadura de nivel 1, también única tiene 10 PB.

**Items**: Las armas estan incluidas entre los items, pero también las armaduras, alimentos y otros items genericos están incluidos en el juego. La idea es que estos sirvan para mejorar la capacidad del personaje, le permita curarse, o llevar una recompensa.

___
 
## 5. Informacion complementaria

Fecha de inicio del proyecto: 17/06/2022
Publicación de la demo: 21/06/2022

Definiciones:

* *PS: Puntos Salud.
* *PA: Puntos Ataque.
* *PB: Puntos Blindaje.


