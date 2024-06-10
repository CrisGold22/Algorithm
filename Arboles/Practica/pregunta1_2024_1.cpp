#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Nodo{
    int element;
    Nodo *left;
    Nodo *right;
};

struct Tree{
    Nodo *root;
};

void buildTree(Tree &tree){
    tree.root = nullptr;
}

Nodo *createNodo(int element, Nodo *left, Nodo *right){
    Nodo *nodo = new struct Nodo;

    nodo->element = element;
    nodo->left = left;
    nodo->right = right;

    return nodo;
}

void insert(Nodo *&root, int element){
    if(root == nullptr){
        Nodo *newNodo = createNodo(element, nullptr, nullptr);
        root = newNodo;
    }
    else{
        if(element > root->element){
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
        cout<<root->element<<" ";
        printInOrder(root->right);
    }
}

void plantarArbolBinario(struct Tree & arbol, struct Nodo * arbolIzquierdo,
                         int elemento, struct Nodo * arbolDerecho){
    
    struct Nodo * nuevoNodo = createNodo(elemento, arbolIzquierdo, arbolDerecho);
    arbol.root = nuevoNodo;
}

void plantarArbolBinario(struct Tree & arbol, struct Tree arbolIzquierdo,
                         int elemento, struct Tree arbolDerecho){
    
    struct Nodo * nuevoNodo = createNodo(elemento, arbolIzquierdo.root, arbolDerecho.root);
    arbol.root = nuevoNodo;
}

int leafsTree(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    else if (root->left == nullptr and root->right == nullptr){
        return 1;
    }
    else{
        return leafsTree(root->left) + leafsTree(root->right);
    }
}

int nodosCounter(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    return 1 + nodosCounter(root->left) + nodosCounter(root->right);
}

void aplicarArbolNodo(Nodo *sistema, Nodo *paquete, Nodo *resultado){

    queue <Nodo*> cola1, cola2;

    cola1.push(sistema);
    cola2.push(paquete);

    while(!cola1.empty() or !cola2.empty()){
        Nodo *nodoSistema = cola1.front();
        Nodo *nodoPaquete = cola2.front();

        cola1.pop();
        cola2.pop();

        int cantLeafs = leafsTree(nodoSistema);
        int cantNodos = nodosCounter(nodoSistema);

        insert(resultado, nodoPaquete->element + cantNodos - cantLeafs);

        if(nodoSistema->left and nodoPaquete->left){
            aplicarArbolNodo(sistema->left, paquete->left, resultado);
        }
        if(nodoSistema->right and nodoPaquete->right){
            aplicarArbolNodo(sistema->right, paquete->right, resultado);
        }
        
    }

}

void aplicarArbol(Tree sistema, Tree paquete, Tree &resultado){
   aplicarArbolNodo(sistema.root, paquete.root, resultado.root);
}

int main(){

    Tree systemTree, packedTree, tree1, tree2, resultTree;
    buildTree(systemTree);
    buildTree(packedTree);
    buildTree(resultTree);
    buildTree(tree1);
    buildTree(tree2);

    insert(systemTree.root, 5);
    insert(systemTree.root, 3);
    insert(systemTree.root, 9);

    printInOrder(systemTree.root);
    cout<<endl;

    Nodo *leftNodo = createNodo(2, nullptr, nullptr);
    Nodo *rightNodo = createNodo(3, nullptr, nullptr);

    plantarArbolBinario(tree1, leftNodo, 7, rightNodo);

    plantarArbolBinario(tree2, nullptr, 8, nullptr);
    plantarArbolBinario(packedTree, tree1, 1, tree2);

    printInOrder(packedTree.root);

    aplicarArbol(systemTree, packedTree, resultTree);

    return 0;
}