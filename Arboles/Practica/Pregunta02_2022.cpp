#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct Nodo
{
    int fecha;
    int stock;
    Nodo *left;
    Nodo *right;
};

struct Arbol
{
    Nodo *root;
};

void construirArbol(Arbol &arbol){
    arbol.root = nullptr;
}

Nodo *createNodo(int fecha, int stock, Nodo *left, Nodo *right){
    Nodo *newNodo = new struct Nodo;

    newNodo->fecha = fecha;
    newNodo->stock = stock;
    newNodo->left = left;
    newNodo->right = right;
    return newNodo;
}

void insertElement(Nodo *&root, int fecha, int stock){
    if(root == nullptr){
        Nodo *newNodo = createNodo(fecha, stock, nullptr, nullptr);
        root = newNodo;
    }
    else{
        if(fecha > root->fecha){
            insertElement(root->right, fecha, stock);
        }
        else{
            insertElement(root->left, fecha, stock);
        }
    }
}

void print(Nodo *root){
    if(root!=nullptr){
        print(root->left);
        cout<<root->fecha<<" ";
        print(root->right);
    }
}

int main(){

    ifstream archivo("datos2.txt", ios::in);
    if(not archivo.is_open()){
        cout<<"ERROR"<<endl;
        exit(1);
    }

    Arbol tree;
    construirArbol(tree);
    int fecha, stock;

    while(true){
        archivo>>fecha;
        if(archivo.eof()) break;
        archivo>>stock;
        insertElement(tree.root, fecha, stock);
    }

    print(tree.root);

    return 0;
}