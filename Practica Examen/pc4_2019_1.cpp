#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Nodo
{
    int dato;
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

Nodo *createNodo(int elemento, int stock, Nodo *left, Nodo *right){
    Nodo *newNodo = new struct Nodo;

    newNodo->dato = elemento;
    newNodo->stock = stock;
    newNodo->left = left;
    newNodo->right = right;
    return newNodo;
}

void insertarElemento(Nodo *&nodo, int elemento, int stock){

    if(nodo == nullptr){
        Nodo *newNodo = createNodo(elemento, stock, nullptr, nullptr);
        nodo = newNodo;
    }
    else{
        if(elemento > nodo->dato){
            insertarElemento(nodo->right, elemento, stock);
        }
        else{
            insertarElemento(nodo->left, elemento, stock);
        }
    }

}

void insertLR(struct Nodo *& raiz, int elemento, int stock){
    if(raiz == nullptr){
        Nodo *newNodo = createNodo(elemento, stock, nullptr, nullptr);
        raiz = newNodo;
    }
    else{
        if (raiz->left==nullptr)
            insertarElemento(raiz->left, elemento, stock);
        else
            if(raiz->right==nullptr)
                insertarElemento(raiz->right, elemento, stock);
    }            
}

void printTree(Nodo *root){

    if(root != nullptr){
        printTree(root->left);
        cout<<root->dato<<"-"<<root->stock<<" ";
        printTree(root->right);
    }
}

Nodo *findOldest(Nodo *root){

    Nodo *current = root;

    if(current->left == nullptr){
        return current;
    }
    else{
        return findOldest(root->left);
    }
}

void deleteNodo(Nodo *&root, int element){
    if(root == nullptr){
        return;
    }
    if(root->dato == element){
        delete root;
        root = nullptr;
        return;
    }
    
    if(element > root->dato){
        deleteNodo(root->right, element);
    }
    else{
        deleteNodo(root->left, element);
    }

}

void despachando(Nodo *&root, int &stockWanted){

    if(stockWanted <= 0){
        return;
    }

    Nodo *nodo = findOldest(root);
    int aux = stockWanted;
    if(nodo->stock > stockWanted){
        nodo->stock -= stockWanted;
        stockWanted = 0;
    }
    else{
        stockWanted -= nodo->stock;
        deleteNodo(root, nodo->dato);
    }


    despachando(root, stockWanted);
}

int main(){

    Arbol tree;
    construirArbol(tree);

    ifstream archivo("pc4_2019_1_datos.txt", ios::in);
    if(not archivo.is_open()){
        cout<<"Error archivo.txt"<<endl;
        exit(1);
    }

    int date, stock;

    while(true){
        archivo>>date;
        if(archivo.eof()) break;
        archivo>>stock;
        insertarElemento(tree.root, date, stock);
    }

    printTree(tree.root);
    cout<<endl;
    Nodo *pacheco = findOldest(tree.root);
    cout<<pacheco->dato<<" "<<pacheco->stock<<endl;
    // deleteNodo(tree.root, 20170620);
    // printTree(tree.root);

    Arbol resultTree;
    construirArbol(resultTree);
    int cantidad = 35;
    despachando(tree.root, cantidad);
    printTree(tree.root);
    return 0;
}