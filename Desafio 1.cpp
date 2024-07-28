#include <iostream>
using namespace std;

int zetadieta(int C, int P, int G){
    int resultado;
    double cantidadC=C/27;
    double cantidadP=P/30;
    int cantidadG=G;

    if(C >= 0 && P >= 0 && G >= 0 ){ //esto verifica que los valores sean menores o iguales a 0
        if((C && P && G) < 1000*1000*1000){ //esto verifica que sea menor que 10**9
                if(C%27 != 0){
                     cantidadC++;
                    // estoy agregando +1 si es un decimal (osea redondear para arriba)
                 }
    
                 if(P%30 != 0){
                    cantidadP++;
                    // estoy agregando +1 si es un decimal (osea redondear para arriba)
                 }
 
                resultado= cantidadC*105 + cantidadP*120 + cantidadG*9; //calcula la cantidad de calorias que se consume
    
        }
    }
    
    else{
        resultado = 0;
        cout << "0 porque tenes que poner un numero positivo y menor a 1000000000";
        }
    
    
    
    
    return resultado;
}

int main(){
    
    cout <<"la cantida de calorias que consumiras sera: " <<  zetadieta(88, 90, 50) << endl;
    cout <<"en la subtarea 1 la cantida de calorias que consumiras sera: " <<  zetadieta(0, 0, 999) << endl;
    cout <<"en la subtarea 2 la cantida de calorias que consumiras sera: " <<  zetadieta(0, 0, 3000) << endl;
    cout <<"en la subtarea 3 la cantida de calorias que consumiras sera: " <<  zetadieta(0, 999, 0) << endl;
    cout <<"en la subtarea 4 la cantida de calorias que consumiras sera: " <<  zetadieta(0, 3000, 0) << endl;
    cout <<"en la subtarea 5 la cantida de calorias que consumiras sera: " <<  zetadieta(999, 0, 0) << endl;
    cout <<"en la subtarea 6 la cantida de calorias que consumiras sera: " <<  zetadieta(3000, 0, 0) << endl;
    cout <<"en la subtarea 7 la cantida de calorias que consumiras sera: " <<  zetadieta(9, 99, 999) << endl;
    cout <<"en la subtarea 8 la cantida de calorias que consumiras sera: " <<  zetadieta(1001, 2000, 3000) << endl;
    //aca testeo las subtareas en mi funcion zetadieta
    
    
   
}