#include "Almacen.cpp"

using namespace std;

int main() {
    cadena arch;
    Almacen nuevo_almacen("");
    //cout<<nuevo_almacen.get_num_robots()<<endl<<nuevo_almacen.get_num_instructions()<<endl;
    nuevo_almacen.generarDatos();
    nuevo_almacen.Ejecutar_todas_instrucciones("","");

}