#include <iostream>
#include <cmath>
#include <queue>
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

//inserta sin criterio de izquierda a derecha
void insertLR(struct Nodo *& raiz, int elemento){
    if(raiz == nullptr){
        Nodo *newNodo = createNodo(elemento, nullptr, nullptr);
        raiz = newNodo;
    }
    else{
        if (raiz->left==nullptr)
            insertarElemento(raiz->left, elemento);
        else
            if(raiz->right==nullptr)
                insertarElemento(raiz->right, elemento);
    }            
}

void printTree(Nodo *root){

    if(root != nullptr){
        printTree(root->left);
        cout<<root->dato<<" ";
        printTree(root->right);
    }
}

//Funciones de arboles mas complejas 

void searchElement(Nodo *root, int element, bool &condition){
    if(root == nullptr){
        condition = false;
        return;
    }

    if(root->dato == element){
        condition = true;
        return;
    }

    if(element > root->dato){
        searchElement(root->right, element, condition);
    }
    else{
        searchElement(root->left, element, condition);
    }
}

int heightTree(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    else if(root->left == nullptr and root->right == nullptr){
        return 0;
    }
    else{
        return 1 + max(heightTree(root->left), heightTree(root->right));
    }
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

bool isBalancedTree(Nodo *root){
    if(root == nullptr){
        return true;
    }
    else{
        int leftTree = heightTree(root->left);
        int rightTree = heightTree(root->right);

        if(leftTree == rightTree){
            return true;
        }
        else{
            return false;
        }
    }
}

Nodo *findLCA(Nodo *root, int num1, int num2){

    if(root == nullptr){
        return 0;
    }

    if(root->dato > num1 and root->dato > num2){
        return findLCA(root->left, num1, num2);
    }

    if(root->dato < num1 and root->dato < num2){
        return findLCA(root->right, num1, num2);
    }

    return root;
}

void goThroughLevels(Nodo *root){
    if(root == nullptr){
        return ;
    }

    queue <Nodo *> cola;
    cola.push(root);

    while(!cola.empty()){
        Nodo *nodo = cola.front();
        cola.pop();

        cout<<nodo->dato<<" ";
        if(nodo->left != nullptr){
            cola.push(nodo->left);
        }
        if(nodo->right != nullptr){
            cola.push(nodo->right);
        }
    }
}

int findingNodoLevel(Nodo *root, int element, int level){
    if(root == nullptr){
        return -1;
    }
    
    if(root->dato == element){
        return level;
    }

    if(element > root->dato){
        return findingNodoLevel(root->right, element, level + 1);
    }
    else{
        return findingNodoLevel(root->left, element, level + 1);
    }

}

int nodosTree(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    return 1 + nodosTree(root->left) + nodosTree(root->right);
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

Nodo *leftRotation(Nodo *root){
    Nodo *newNodo = root->right;
    root->right = newNodo->left;
    newNodo->left = root;
    return newNodo;
}

Nodo *rightRotation(Nodo *root){
    Nodo *newNodo = root->left;
    root->left = newNodo->right;
    newNodo->right = root;
    return newNodo;
}

Nodo *doubleRightRotation(Nodo *root){
    root->left = leftRotation(root->left);
    return rightRotation(root);    
}

Nodo *doubleLeftRotation(Nodo *root){
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Nodo *balancedNodo(Nodo *root){

    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    int diference = leftHeight - rightHeight;

    if(diference > 1){
        if(heightTree(root->left->left) >= heightTree(root->left->right)){
            root = rightRotation(root);    
        }
        else{
            root = doubleRightRotation(root);
        }
    }
    
    if(diference < -1){
        if(heightTree(root->left->left) >= heightTree(root->left->right)){
            root = leftRotation(root);    
        }
        else{
            root = doubleLeftRotation(root);
        }
    }

    return root;
}

Nodo *balancedTree(Nodo *root){
    if(root == nullptr){
        return nullptr;
    }

    root->left = balancedTree(root->left);
    root->right = balancedTree(root->right);

    root = balancedNodo(root);

    return root;
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
    // insertarElemento(arbol.root, 2);
    // insertarElemento(arbol.root, 1);
    // insertarElemento(arbol.root, 3);
    printTree(arbol.root);
    cout<<endl;

    bool condition;
    searchElement(arbol.root, 8, condition);

    if(condition == true){
        cout<<"The element exist"<<endl;
    }
    else{
        cout<<"The element doesn't exist"<<endl;
    }   

    int height = heightTree(arbol.root);
    cout<<"Height: "<<height<<endl;
    cout<<"Number of leafs: "<<leafsTree(arbol.root)<<endl;
    cout<<"Is it balanced?: "<<isBalancedTree(arbol.root)<<endl;
    cout<<"What level is 4?: "<<findingNodoLevel(arbol.root, 4, 0)<<endl;
    cout<<"Number of Nodos: "<<nodosTree(arbol.root)<<endl;

    return 0;
}
