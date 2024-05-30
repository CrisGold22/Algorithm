#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct Nodo
{
    int element;
    char car;
    Nodo *left;
    Nodo *right;
};

struct Tree
{
    Nodo *root;
};

Nodo *createNodo(int element, char car, Nodo *left, Nodo *right){
    Nodo *newNodo = new struct Nodo;

    newNodo->element = element;
    newNodo->car = car;
    newNodo->left = left;
    newNodo->right = right;

    return newNodo;
}

void buildTree(Tree &tree){
    Nodo *newNodo = createNodo(0, 'a', nullptr, nullptr);
    tree.root = newNodo;
}

void plantingTree(Tree &tree, char car, int element, Nodo *left, Nodo *right){
    Nodo *newNodo = createNodo(element, car, nullptr, nullptr);

    tree.root = newNodo;
}

void plantingTrees(Tree &tree, char car, int element, Tree left, Tree right){
    Nodo *newNodo = createNodo(element, car, left.root, right.root);

    tree.root = newNodo;
}

void printInOrder(Nodo *root){

    if(root != nullptr){
        printInOrder(root->left);
        cout<<root->car<<" ";
        printInOrder(root->right);
    }

}

void printTree(Nodo *root){
    stack <Nodo*> pila;

    pila.push(root);

    while(!pila.empty()){
        Nodo *nodo = pila.top();
        pila.pop();

        if(nodo->right){
            pila.push(nodo->right);
        }
        cout<<nodo->element<<","<<nodo->element<<" ";
        if(nodo->left){
            pila.push(nodo->left);
        }

    }

} 

bool searchNodo(Nodo *root, char car, int num){
    
    stack<Nodo *> pila;
    pila.push(root);
    
    while(!pila.empty()){
        Nodo *nodo = pila.top();
        if(nodo->element == num and nodo->car == car){
            return true;
        }

        pila.pop();

        if(nodo->right){
            pila.push(nodo->right);
        }
        if(nodo->left){
            pila.push(nodo->left);
        }

    }
    return false;
}

int main(){

    Tree tree1, tree2, tree3, tree4, tree5, tree6, tree7, tree8, treeMain;
    Nodo *newNodo1, *newNodo2;

    buildTree(treeMain);

    // creating right side main tree
    newNodo1 = createNodo(100, 'S', nullptr, nullptr);
    newNodo2 = createNodo(200, 'E', nullptr, nullptr);
    plantingTree(tree7, 'S', 200, newNodo1, newNodo2);
    plantingTree(tree8, 'S', 150, nullptr, nullptr);
    plantingTrees(tree6, 'E', 200, tree7, tree8); // joining the branches

    //Now, let's gonna create left side tree
    newNodo1 = createNodo(50, 'E', nullptr, nullptr);
    newNodo2 = createNodo(100, 'E', nullptr, nullptr);
    plantingTree(tree4, 'S', 50, newNodo1, nullptr);
    plantingTree(tree5, 'Z', 200, newNodo2, nullptr);
    plantingTrees(tree3, 'E', 100, tree4, tree5); // joining the branches

    plantingTree(tree2, 'S', 50, nullptr, nullptr);
    plantingTrees(tree1, 'Z', 50, tree3, tree2);

    //joining left sub-tree and right sub-tree
    plantingTrees(treeMain, 'Z', 100, tree1, tree6); // declaration of the main tree

    //printing all the elements of the tree
    //printInOrder(treeMain.root);
    printTree(treeMain.root);
    cout<<endl;

    //making an interation function
    if(searchNodo(treeMain.root, 'S', 200)){
        cout<<"SkyNet is there >:)"<<endl;
    }
    else{
        cout<<"SkyNet doesn't exist"<<endl;
    }
    
    cout<<"Hola como estas xD"<<endl;

    return 0;
}