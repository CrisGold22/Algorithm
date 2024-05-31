#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Nodo
{
    int dato;
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

Nodo *createNodo(int elemento, Nodo *left, Nodo *right){
    Nodo *newNodo = new struct Nodo;

    newNodo->dato = elemento;
    newNodo->left = left;
    newNodo->right = right;
    return newNodo;
}

void searchNodo(Nodo *root, int element, bool &condition){

    if(root == nullptr){
        condition = false;
        return;
    }
    if(root->dato == element){
        condition = true;
        return;
    }

    if(element > root->dato){
        searchNodo(root->right, element, condition);
    }
    else{
        searchNodo(root->left, element, condition);
    }
    
}

void insert(Nodo *&root, int element){

    if(root == nullptr){
        Nodo *newNodo = createNodo(element, nullptr, nullptr);
        root = newNodo;
    }
    else{
        if(element > root->dato){
            insert(root->right, element);
        }
        else{
            insert(root->left, element);
        }
    }
}

void printInOrder(Nodo *root){
    if(root != nullptr){
        printInOrder(root->left);
        cout<<root->dato<<" ";
        printInOrder(root->right);
    }

}
Nodo* balancearArbol(Nodo* root){
    if(root==NULL){
        return NULL;
    }
    Nodo* arbol_balanceado_izq = balancearArbol(root->left);
    Nodo* arbol_balanceado_der = balancearArbol(root->right);
    
    if(arbol_balanceado_izq !=NULL){
        arbol_balanceado_izq->right = root;
        root->left = NULL;
    }
    if(arbol_balanceado_der !=NULL){
        root->right = arbol_balanceado_der;
        return arbol_balanceado_der;
    }
    return root;
}


int main(){

    ifstream archivo("datos.txt", ios::in);

    Arbol tree;
    construirArbol(tree);

    int num;
    bool condition = false;
    int max = 0;

    while(true){
        archivo>>num;
        if(archivo.eof()) break;
        if(num > max){
            max = num;
        }
        searchNodo(tree.root, num, condition);
        if(condition != true){
            insert(tree.root, num);
        }
        else{
            num += max;
            insert(tree.root, num);
            if(num > max){
                max = num;
            }
        }
    }
    printInOrder(tree.root);



    return 0;
}