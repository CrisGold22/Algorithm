#include <bits/stdc++.h>
using namespace std;

struct Nodo{
    int element;
    Nodo *next;
};

struct List
{
    Nodo *head;
    Nodo *tail;
};

Nodo *createNodo(int element, Nodo *next){
    Nodo *newNodo= new struct Nodo;
    newNodo->element = element;
    newNodo->next = next;
    return newNodo;
}

void createList(List &list){
    list.head = nullptr;
    list.tail = nullptr;
}

bool isListEmpty(List list){
    return list.head == nullptr;
}

void insertBack(List &list, int element){
    if(isListEmpty(list)){
        Nodo *newNodo = createNodo(element, nullptr);
        list.head = newNodo;
        list.tail = newNodo;
    }
    else{
        Nodo *newNodo = createNodo(element, nullptr);
        list.tail->next = newNodo;
        list.tail = newNodo;
    }
}

void insertFront(List &list, int element){
    if(isListEmpty(list)){
        Nodo *newNodo = createNodo(element, nullptr);
        list.head = newNodo;
        list.tail = newNodo;
    }
    else{
        Nodo *newNodo = createNodo(element, nullptr);
        newNodo->next = list.head;
        list.head = newNodo;
    }
}

void print(List list){

    Nodo *current = list.head;

    while(current != nullptr){
        cout<<current->element<<" ";
        current = current->next;
    }
    cout<<endl;
}

void orderedInsert(List &list, int element){
    if(isListEmpty(list)){
        Nodo *newNodo = createNodo(element, nullptr);
        list.head = newNodo;
        list.tail = newNodo;
    }
    else{
        Nodo *newNodo = createNodo(element, nullptr);
        Nodo *current = list.head, *preview = nullptr;

        while(true){
            if(preview == nullptr and element < current->element){
                newNodo->next = current;
                list.head = newNodo;
                break;
            }
            else if(current == nullptr){
                preview->next = newNodo;
                list.tail = newNodo;
                break;
            }
            else if(element < current->element){
                preview->next = newNodo;
                newNodo->next = current;
                break;
            }
            else{
                preview = current;
                current = current->next;
            }
        }

    }
}

int main(){

    List list, orderedList;
    createList(list);
    insertBack(list, 3);
    insertBack(list, 4);
    insertBack(list, 5);
    print(list);
    
    insertFront(list, 2);
    insertFront(list, 1);
    print(list);

    createList(orderedList);
    orderedInsert(orderedList, 3);
    orderedInsert(orderedList, 2);
    orderedInsert(orderedList, 1);
    orderedInsert(orderedList, 6);
    orderedInsert(orderedList, 5);
    orderedInsert(orderedList, 4);
    print(orderedList);


    return 0;
}