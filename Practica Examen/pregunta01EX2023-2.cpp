#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
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

void printTree(Nodo *root){
    
    if(root != nullptr){
        printTree(root->left);
        cout<<root->dato<<" ";
        printTree(root->right);
    }
}

int heightTree(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    else if (root->left == nullptr and root->right == nullptr){
        return 0;
    }
    else{
        return 1 + max(heightTree(root->left), heightTree(root->right));
    }
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

bool isBalanced(Nodo *root){
    if(root == nullptr){
        return true;
    }
    else{
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);

        if(fabs(rightHeight - leftHeight) <= 1){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){

    int array[] = {2, 5, 2, 1, 5, 6, 3, 4};
    bool condition = false;
    int num, sum, maxNum = 0;

    Arbol tree;
    construirArbol(tree);

    for(int i=0 ; i < 8 ; i++){
        num = array[i];
        if(num > maxNum){
            maxNum = num;
        }
        searchNodo(tree.root, num, condition);
        if(condition){
            num += maxNum;
            insert(tree.root, num);
            if(num > maxNum){
                maxNum = num;
            }
        }
        else{
            insert(tree.root, num);
        }
    }

    printTree(tree.root);
    cout<<endl;
    cout<<"Height: "<<heightTree(tree.root)<<endl;
    cout<<"Is balanced?: "<<isBalanced(tree.root)<<endl;
    tree.root = balancedTree(tree.root);
    cout<<"Height: "<<heightTree(tree.root)<<endl;
    cout<<"Is balanced?: "<<isBalanced(tree.root)<<endl;

    return 0;
}