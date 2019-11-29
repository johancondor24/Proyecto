//
// Created by francomeza on 28/11/2019.
#include <iostream>
#include <iomanip>
#include <string>
#include "string.h"
#include <fstream>
#include <vector>
#include "Robot.cpp"

#define tamano_string 20

using namespace std;

#define total_inst 5

class Almacen{
protected:
    entero num_robots=0;
    caracter linea[tamano_string];
    boleano type_instruction;
    entero num_instruccions;
    vector<entero> rows;
    vector<entero> cols;
    vector<entero> rows_dest;
    vector<entero> cols_dest;
    vector<cadena> operacion;
    vector<entero> orden_instrucciones;
    vector<cadena> tipos;
    cadena archivo;
public:
    vector<Robot> Robots;
    vector<Instruccion> Instrucciones;
    vector<Objeto> objetos;

    Almacen(cadena archivo_from){
        archivo=archivo_from;
        fstream lecturas;
        lecturas.open(archivo);
        entero cont_lineas=0;
        while(!lecturas.eof()){
            lecturas>>linea;
            if(cont_lineas == 0){
                num_robots = atoi(linea);
            }
            else if(cont_lineas >=1 and cont_lineas<=num_robots*2) {
                if(cont_lineas%2 != 0)
                    rows.push_back(atoi(linea));
                else
                    cols.push_back(atoi(linea));
            }
            else if(cont_lineas == (num_robots*2+1)){
                num_instruccions = atoi(linea);
            }
            else if(cont_lineas >num_robots*2+1){
                if(atoi(linea)<=num_robots and atoi(linea)>0){
                    orden_instrucciones.push_back(atoi(linea));
                    for(entero i = 0 ; i < total_inst-1 ; i++) {
                        lecturas >> linea;
                        if(i==0){

                            if(linea[0] == 'I' or linea[0] == 'R')
                                operacion.push_back(linea);
                            else
                                num_instruccions--;
                            continue;
                        }
                        else if(i==1){
                            rows_dest.push_back(atoi(linea));
                        }
                        else if(i==2){
                            cols_dest.push_back(atoi(linea));
                        }
                        else if(i==3){
                            tipos.push_back(linea);
                        }

                    }
                }
            }
            cont_lineas+=1;

        }
        /*for(auto it=0 ; it < tipos){

        }*/
    }

    entero get_num_robots(){
        return num_robots;
    }

    entero get_num_instructions(){
        return num_instruccions;
    }

    void generarDatos(){

        entero contador_objetos =1;
        for(auto it = 0; it < num_robots ; it++){
            Robots.push_back(Robot(rows[it],cols[it]));
            Robots[it].set_id(it+1);
            //cout<<Robots[it].get_id()<<endl;
        }
        for(auto it = 0 ; it < num_instruccions; it++){
            Instrucciones.push_back(Instruccion(orden_instrucciones[it],rows_dest[it],cols_dest[it],operacion[it],tipos[it]));
            //cout<<Instrucciones[it].get_instruccion()<<" "<<Instrucciones[it].get_objeto()<<endl;
            objetos.push_back(Objeto(tipos[it],rows_dest[it],cols_dest[it]));

        }
        /*for(auto it=0 ; it< num_instruccions ;it++){
            if(Instrucciones[it].get_objeto()[0] == Instrucciones[it+1].get_objeto()[0]){
                objetos[it].set_cantidad(+2);
            }
            else{
                objetos.push_back(Objeto(tipos[it],rows_dest[it],cols_dest[it]));
                objetos[it].set_cantidad(1);
            }
        }*/
    }


    void Ejecutar_todas_instrucciones(cadena archivo_escritura , cadena archivo_slots){
        ofstream escritura;
        ofstream slots;
        entero secuencia = 0;
        escritura.open(archivo_escritura);
        slots.open(archivo_slots);
        for(entero it = 0 ; it < num_instruccions ; it++){
            if (Instrucciones[it].get_instruccion() == "Retiro" and num_instruccions ==0){
                //cout<<"Se cancela el turno";
            }
            else{
                if(Instrucciones[it].get_instruccion() == "Ingreso"){
                    entero id_del_turno= Instrucciones[it].get_id_rob();
                    for(entero i=1 ; i<= num_robots ; i++){
                        if(Robots[i].get_id() == id_del_turno){
                            Robots[i].set_posy(Instrucciones[it].get_pos_dest_y());
                            Robots[i].set_posx(Instrucciones[it].get_pos_dest_x());
                            for(auto it_two=objetos.begin(); it_two != objetos.end() ; it_two++){
                                if((*it_two).get_Nombre_objeto() == Instrucciones[i].get_objeto() and (*it_two).get_posy() == Instrucciones[i].get_pos_dest_y() and (*it_two).get_posx() == Instrucciones[i].get_pos_dest_x())
                                    objetos[i].set_cantidad(objetos[i].get_cantidad()+1);
                                else
                                    continue;
                            }
                            escritura<< "Secuencia #"<< secuencia+1 <<" -> Robot :  "<< Robots[i].get_id()-1<< " se dirige a ";
                            escritura<<" "<<Robots[i].get_posx()<<" "<<Robots[i].get_posy()<<" destino con "<< Instrucciones[it].get_objeto()<<"\n";
                            secuencia++;

                        }
                    }

                }
                else if(Instrucciones[it].get_instruccion() == "Retiro"){
                    entero id_del_turno= Instrucciones[it].get_id_rob();
                    for(entero i=1 ; i<=num_robots ; i++){
                        if(Robots[i].get_id() == id_del_turno){
                            Robots[i].set_posy(Instrucciones[it].get_pos_dest_y());
                            Robots[i].set_posx(Instrucciones[it].get_pos_dest_x());
                            for(auto it_two=objetos.begin(); it_two != objetos.end() ; it_two++){
                                if((*it_two).get_Nombre_objeto() == Instrucciones[i].get_objeto() and (*it_two).get_posy() == Instrucciones[i].get_pos_dest_y() and (*it_two).get_posx() == Instrucciones[i].get_pos_dest_x())
                                    if(objetos[i].get_cantidad() == 0){
                                        break;
                                    }
                                    else
                                        objetos[i].set_cantidad(objetos[i].get_cantidad()-1);
                                else
                                    continue;
                            }
                            escritura<< "Secuencia #"<< secuencia+1 <<" -> Robot :  "<< Robots[i].get_id()-1<< " se dirige a ";
                            escritura<<" "<<Robots[i].get_posx()<<" "<<Robots[i].get_posy()<<" destino con "<< Instrucciones[it].get_objeto()<<"\n";
                            secuencia++;

                        }
                    }
                }

            }
            escritura.close();
        }
        slots<<"******** POSICIONES ***********\n";
        for(auto it_objetos  = objetos.begin() ; it_objetos!= objetos.end() ; it_objetos++){
            slots<<(*it_objetos).get_Nombre_objeto()<<" esta en la " <<"Fila : "<<(*it_objetos).get_posx();
            slots<<" y en la Columna : "<<(*it_objetos).get_posy()<<" con cantidad de : "<<(*it_objetos).get_cantidad()<<endl;
        }

        slots.close();
    }

    ~Almacen(){}
};
