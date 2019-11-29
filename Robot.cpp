//
// Created by francomeza on 29/11/2019.
//

#include <iostream>
#include "Instrucciones.cpp"
#include "Objeto.cpp"

using namespace std;

class Robot{
private:
    entero id;
    entero pos_x;
    entero pos_y;
    entero pos_x_home;
    entero pos_y_home;

public:

    Robot(entero _posx, entero _posy){
        pos_x = _posx;
        pos_y = _posy;
        pos_x_home = _posx;
        pos_y_home = _posy;
    }

    entero get_id(){
        return id;
    }

    void set_id(entero nueva){
        id=nueva;
    }

    entero get_posx(){
        return pos_x;
    }

    entero get_posy(){
        return pos_y;
    }

    void set_posx(entero nueva_pos){
        pos_x = nueva_pos;
    }

    void set_posy(entero nueva_pos){
        pos_y = nueva_pos;
    }

    void ejecutar_instrucciones(){
    }

    ~Robot(){}

};

