#include <iostream>
#include <vector>

using namespace std;

void printResult(bool resultado) {
    if(resultado){
        cout << "existe un camino para llegar a la meta";
    }else{
        cout << "no hay forma de llegar a la meta";
    }
}

bool findPath(vector<vector<char>> values, int x, int y) {
    
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
    }
    
    if(findPath(values, x + 1, y)){
        return true;
    }
    
    if(findPath(values, x, y - 1)){
        return true;
    }
    
    if(findPath(values, x - 1, y)){
        return true;
    }
    
    values[x][y] = '.';
    return false;
}

int main() {
    
    vector<vector<char>> mapa = {
        {'.', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', 'G'},
        {'#', '.', '#', '.', '#', '#'}
    };

    printResult(findPath(mapa, 0, 0));

    return 0;
}