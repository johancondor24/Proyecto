//
// Created by francomeza on 29/11/2019.
//


#include <iostream>
#include "funciones.cpp"

using namespace std;

class Instruccion{
protected:
    entero id_robot;
    cadena instruc;
    entero pos_x_dest;
    entero pos_y_dest;
    cadena object;
public:
    Instruccion(entero id,entero pos_dest_x, entero pos_dest_y,cadena &instru,cadena &cosa){
        id_robot = id;
        pos_x_dest = pos_dest_x;
        pos_y_dest = pos_dest_y;
        instruc = instru;
        object = cosa;
    }

    entero get_pos_dest_x(){
        return pos_x_dest;
    }

    entero get_pos_dest_y(){
        return pos_y_dest;
    }

    cadena get_objeto(){
        return object;
    }

    cadena get_instruccion(){
        return instruc;
    }
    entero get_id_rob(){
        return id_robot;
    }



    ~Instruccion(){}
};