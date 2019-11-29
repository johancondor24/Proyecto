//
// Created by francomeza on 29/11/2019.
//

#include <string>
#include "funciones.cpp"

using namespace std;

class Objeto{
private:
    cadena name;
    entero pos_x;
    entero pos_y;
    entero cantidad=0;
public:

    Objeto(string &nombre,entero _posx, entero _posy){
        name = nombre;
        pos_x = _posx;
        pos_y = _posy;
    }

    entero get_cantidad(){
        return cantidad;
    }

    void set_cantidad(entero nueva_cantidad){
        cantidad=nueva_cantidad;
    }

    entero get_posx(){
        return pos_x;
    }

    void set_posx(entero nueva_pos){
        pos_x = nueva_pos;
    }

    entero get_posy(){
        return pos_y;
    }

    void set_posy(entero nueva_posy){
        pos_y=nueva_posy;
    }

    string get_Nombre_objeto(){
        return name;
    }


    ~Objeto(){}

};
