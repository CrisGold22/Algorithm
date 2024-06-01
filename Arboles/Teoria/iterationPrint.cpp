#include <iostream>
#include <stack>
#include <algorithm>
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

void insertarElemento(Nodo *&nodo, int elemento){

    if(nodo == nullptr){
        Nodo *newNodo = createNodo(elemento, nullptr, nullptr);
        nodo = newNodo;
    }
    else{
        if(elemento > nodo->dato){
            insertarElemento(nodo->right, elemento);
        }
        else{
            insertarElemento(nodo->left, elemento);
        }
    }

}

void preOrderPrint(Nodo *root){
    if(root == nullptr){
        return ;
    }
    else{
        stack <Nodo *> pila;
        pila.push(root);

        while(!pila.empty()){
            Nodo *nodo = pila.top();
            pila.pop();
            
            if(nodo->right){
                pila.push(nodo->right);
            }
            cout<<nodo->dato<<" ";
            if(nodo->left){
                pila.push(nodo->left);
            }

        }
    }
}

void inOrderPrint(Nodo *root){

    stack <Nodo*> pila;
    Nodo *actual = root;

    while(!pila.empty() or actual != nullptr){

        while(actual!= nullptr){
            pila.push(actual);
            actual = actual->left;
        }

        actual = pila.top();
        pila.pop();
        cout<< actual->dato << " ";
        actual = actual->right;
    }

}

void posOrderPrint(Nodo *root){

    stack <Nodo *>pila1, pila2;
    pila1.push(root);

    while(!pila1.empty()){
        Nodo *nodo = pila1.top();
        pila1.pop();
        pila2.push(nodo);

        if(nodo->left){
            pila1.push(nodo->left);
        }
        if(nodo->right){
            pila1.push(nodo->right);
        }
    }

    while(!pila2.empty()){
        Nodo *nodo = pila2.top();
        pila2.pop();
        cout<< nodo->dato <<" ";
    }

}

void postorderTraversal(Nodo* root) {
    if (root == nullptr) return;

    stack<Nodo*> s;
    Nodo* current = root;
    Nodo* lastVisited = nullptr;

    while (current || !s.empty()) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            Nodo* nodo = s.top();
            if (nodo->right && lastVisited != nodo->right) {
                current = nodo->right;
            } else {
                cout << nodo->dato << " ";
                lastVisited = nodo;
                s.pop();
            }
        }
    }
}

void printPosOrder(Nodo *root){
    if(root != nullptr){
        printPosOrder(root->left);
        printPosOrder(root->right);
        cout<<root->dato<<" ";
    }
}

int main(){
    Arbol arbol;

    construirArbol(arbol);

    insertarElemento(arbol.root, 5);
    insertarElemento(arbol.root, 3);
    insertarElemento(arbol.root, 6);
    insertarElemento(arbol.root, 2);
    insertarElemento(arbol.root, 4);
    insertarElemento(arbol.root, 7);
    insertarElemento(arbol.root, 1);

    preOrderPrint(arbol.root);
    cout<<endl;
    inOrderPrint(arbol.root);
    cout<<endl;
    posOrderPrint(arbol.root);
    cout<<endl;
    postorderTraversal(arbol.root);
    cout<<endl;
    printPosOrder(arbol.root);

    return 0;
}