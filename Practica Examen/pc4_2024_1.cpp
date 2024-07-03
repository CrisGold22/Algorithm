#include <iostream>
#include <queue>
#include <fstream>
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

void printNodo(Nodo *root){

    if(root != nullptr){
        printNodo(root->left);
        cout<<root->dato<<" ";
        printNodo(root->right);
    }
}

void plantarArbolBinario(struct Arbol & arbol, struct Nodo * arbolIzquierdo,
                         int elemento, struct Nodo * arbolDerecho){
    
    struct Nodo * nuevoNodo = createNodo(elemento, arbolIzquierdo, arbolDerecho);
    arbol.root = nuevoNodo;
}

void plantarArbolBinario(struct Arbol & arbol, struct Arbol arbolIzquierdo,
                         int elemento, struct Arbol arbolDerecho){
    
    struct Nodo * nuevoNodo = createNodo(elemento, arbolIzquierdo.root, arbolDerecho.root);
    arbol.root = nuevoNodo;
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

void insertLR(struct Nodo *& raiz, int elemento){
    if(raiz == nullptr){
        Nodo *newNodo = createNodo(elemento, nullptr, nullptr);
        raiz = newNodo;
    }
    else{
        if (raiz->left==nullptr)
            insert(raiz->left, elemento);
        else
            if(raiz->right==nullptr)
                insert(raiz->right, elemento);
    }            
}

Nodo *aplicar_arbol(Nodo *packedRoot, Nodo *systemRoot){

    Arbol result;
    construirArbol(result);
    queue<Nodo*> cola1, cola2;
    cola1.push(packedRoot);
    cola2.push(systemRoot);

    while(!cola1.empty()){
        Nodo *actual1 = cola1.front();
        Nodo *actual2 = cola2.front(); 

        cola1.pop();
        cola2.pop();

        insertLR(result.root, actual1->dato + actual2->dato);

        if(packedRoot->left){
            cola1.push(actual1->left);
            cola2.push(actual2->left);
        }
        if(packedRoot->right){
            cola1.push(actual1->right);
            cola2.push(actual2->right);
        }

    }

    return result.root;
}

int main(){

    Arbol packedTree, systemTree;
    Arbol tree1, tree2;
    Arbol resultTree;

    construirArbol(packedTree);
    construirArbol(systemTree);
    construirArbol(tree1);
    construirArbol(tree2);
    construirArbol(resultTree);

    Nodo *leftNodo = createNodo(3, nullptr, nullptr);
    Nodo *rightNodo = createNodo(9, nullptr, nullptr);

    insert(packedTree.root, 5);
    insert(packedTree.root, 3);
    insert(packedTree.root,9);
    printNodo(packedTree.root);
    cout<<endl;

    leftNodo = createNodo(2, nullptr, nullptr);
    rightNodo = createNodo(3, nullptr, nullptr);
    plantarArbolBinario(tree2, leftNodo, 7, rightNodo);
    plantarArbolBinario(tree1, nullptr, 8, nullptr);

    plantarArbolBinario(systemTree, tree2, 1, tree1);
    printNodo(systemTree.root);
    cout<<endl;

    resultTree.root = aplicar_arbol(packedTree.root, systemTree.root);

    return 0;
}