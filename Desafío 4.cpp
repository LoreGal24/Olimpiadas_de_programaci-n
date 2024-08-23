#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int retrocedio=0;
bool retrocediendo;
int caminosError=0;

void printResult(bool resultado) {
    if(resultado){
        cout << "existe un camino para llegar a la meta que es:"<<endl;
    }else{
        cout << "no hay forma de llegar a la meta "<<endl;
    }
    
}

void printResultMapa(bool resultado, vector<vector<char>> mapaActualizado) {
    if(resultado){
        for(int x=0; x<mapaActualizado.size()-1;x++){
        cout << "{ ";
        for(int y=0; y<mapaActualizado[x].size();y++){
            cout <<mapaActualizado[x][y]<<", ";
        }
        cout << " }"<<endl;
       
    }
    }
    
    
}

bool findPath(vector<vector<char>>& values, int x, int y) {
    
    if (x < 0 || y < 0 || x >= values.size() || y >= values[0].size()) {
        return false;
    }
    
    if (values[x][y] == 'G') {
        return true;
    }

    if (values[x][y] == '#' || values[x][y] == '+') {
        return false;
    }

    if (values[x][y] == '.') {
        values[x][y]='+';
    }
    
    if(findPath(values, x, y + 1)){
        return true;
        if(retrocediendo){
            caminosError++;
            retrocediendo=false;
        }
    }
    
    if(findPath(values, x + 1, y)){
        return true;
        if(retrocediendo){
            caminosError++;
            retrocediendo=false;
        }
    }
    
    if(findPath(values, x, y - 1)){
        return true;
        if(retrocediendo){
            caminosError++;
            retrocediendo=false;
        }
    }
    
    if(findPath(values, x - 1, y)){
        return true;
        if(retrocediendo){
            caminosError++;
            retrocediendo=false;
        }
    }
    
   
    retrocediendo=true;
    values[x][y] = '.';
    retrocedio++;
    return false;
}

int main() {
    clock_t tiempo;
    bool confirmador;
    
    vector<vector<char>> mapa = {
        {'.', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', '.'},
        {'#', '.', '#', '.', '#', '#'},
        {'.', '#', '#', '.', '.', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', '.'},
        {'#', '.', '#', '.', '#', '.'},
        {'.', '#', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', '.'},
        {'#', '.', '#', '.', '.', '#'},
        {'.', '#', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', 'G'},
        {'#', '.', '#', '.', '#', '#'}
    };
    tiempo=clock();
    confirmador=findPath(mapa, 0, 0);
    printResult(confirmador);
    printResultMapa(confirmador, mapa);
    tiempo=clock()-tiempo;
    
    cout << "el timpo que tardo en encontrar el camino correcto fue: "<< (double(tiempo)/CLOCKS_PER_SEC)*1000<<" milisegundos" << endl;
    cout << "la cantidad de veces que tuvo que retroceder fue: "<<retrocedio<< " veces" << endl;
    cout << "la cantidad e caminos incorrectos que encontro fue de: "<< caminosError;
   // cout << "la cantidad de veces que entro: "<< vecesRetroceso(retrocedio) << endl;
    return 0;
}