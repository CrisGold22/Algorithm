#include <iostream>
#include <fstream>
#include <queue>
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
    printInOrder(tree.root); // unbalanced
    
    Nodo *number = findLCA(tree.root, 1, 4);
    cout<<number->dato<<endl;

    return 0;
}