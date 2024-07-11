/*#include "ArbolBinario.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesArbolesBinarios.h"
#include "funciones.h"
#include <iostream>
#include <cstring>

using namespace std;

void encontrarPalabraEnArbolBinario(ArbolBinario &arbol,const char *palabra,bool &existePalabra);
void encontrarPalabraEnArbolBinarioRecursivo(struct NodoArbol *&nodo,Lista &lista,bool &existePalabra);
char **cargarHoja();
void imprimeMensajeOculto(ArbolBinario &arbol,char **hojaConPalabras);

int main(int argc, char** argv) {
    ArbolBinario arbol,arbolesAux[14];
    
    construir(arbol);
    
    for(int i=0;i<14;i++)
        construir(arbolesAux[i]);
        
    plantarArbolBinario(arbolesAux[2],nullptr,'E',nullptr);
    plantarArbolBinario(arbolesAux[6],nullptr,'R',nullptr);
    plantarArbolBinario(arbolesAux[10],nullptr,'T',nullptr);
    plantarArbolBinario(arbolesAux[11],nullptr,'O',nullptr);
    plantarArbolBinario(arbolesAux[12],nullptr,'F',nullptr);
    plantarArbolBinario(arbolesAux[13],nullptr,'T',nullptr);
    
    plantarArbolBinario(arbolesAux[9],arbolesAux[12],'A',arbolesAux[13]);
    plantarArbolBinario(arbolesAux[8],arbolesAux[11],'C',nullptr);
    plantarArbolBinario(arbolesAux[7],arbolesAux[10],'G',nullptr);
    plantarArbolBinario(arbolesAux[4],arbolesAux[8],'C',nullptr);
    plantarArbolBinario(arbolesAux[5],arbolesAux[9],'N',nullptr);
    
    plantarArbolBinario(arbolesAux[3],arbolesAux[6],'E',arbolesAux[7]);
    plantarArbolBinario(arbolesAux[0],arbolesAux[2],'D',arbolesAux[3]);
    plantarArbolBinario(arbolesAux[1],arbolesAux[4],'I',arbolesAux[5]);
    
    plantarArbolBinario(arbol,arbolesAux[0],'L',arbolesAux[1]);
    
    
    char **hojaConPalabras=cargarHoja();
    imprimeMensajeOculto(arbol,hojaConPalabras);
    
    return 0;
}

void encontrarPalabraEnArbolBinario(ArbolBinario &arbol,const char *palabra,bool &existePalabra){
    Lista lista;
    construir(lista);
    
    for(int i=0;palabra[i];i++)
        insertarAlInicio(lista,palabra[i]);
    
    encontrarPalabraEnArbolBinarioRecursivo(arbol.raiz,lista,existePalabra);
}

void encontrarPalabraEnArbolBinarioRecursivo(NodoArbol *&nodo,Lista &lista,bool &existePalabra){
    char elemento=raiz(nodo);
    bool eliminarLetra=eliminarLetraLista(lista,elemento);
    
    if(esListaVacia(lista)){
        existePalabra=true;
        return;
    }
    
    if(eliminarLetra){
        if(nodo->izquierda!=nullptr)
            if(buscarLetraLista(lista,raiz(nodo->izquierda)))
                encontrarPalabraEnArbolBinarioRecursivo(nodo->izquierda,lista,existePalabra);
        if(nodo->derecha!=nullptr)
            if(buscarLetraLista(lista,raiz(nodo->derecha)))
                encontrarPalabraEnArbolBinarioRecursivo(nodo->derecha,lista,existePalabra);
    }
}

char **cargarHoja(){
    char **palabras=new char*[6];
    
    palabras[0]=new char[5];
    strcpy(palabras[0],"HIJO");
    palabras[1]=new char[6];
    strcpy(palabras[1],"FINAL");
    palabras[2]=new char[6];
    strcpy(palabras[2],"MUNDO");
    palabras[3]=new char[4];
    strcpy(palabras[3],"DEL");
    palabras[4]=new char[4];
    strcpy(palabras[0],"DIA");
    palabras[5]=new char[6];
    strcpy(palabras[5],"CICLO");
    
    return palabras;
}

void imprimeMensajeOculto(ArbolBinario &arbol,char **hojaConPalabras){
    for(int i=0;i<6;i++){
        bool existePalabra=false;
        encontrarPalabraEnArbolBinario(arbol,hojaConPalabras[i],existePalabra);
        if(existePalabra==true)
            cout<<hojaConPalabras[i]<<' ';
    }
}

bool eliminarLetraLista(Lista &lista,char letra){
    struct Nodo *temp=lista.cabeza,*anterior=nullptr;
    
    while(temp){
        if(temp->elemento==letra)
            break;
        
        anterior=temp;
        temp=temp->siguiente;
    }
    
    if(temp==nullptr)
        return false;
    
    if(anterior==nullptr){//la letra esta al inicio
        lista.cabeza=temp->siguiente;
        delete temp;
    }else if(temp->siguiente==nullptr){//la letra esta al final de la lista
        delete temp;
        anterior->siguiente=nullptr;
    }else{//la letra esta en el medio
        anterior->siguiente=temp->siguiente;
        delete temp;
    }
    
    return true;
}

bool buscarLetraLista(Lista &lista,char letra){
    struct Nodo *temp=lista.cabeza;
    
    while(temp){
        if(temp->elemento==letra)
            return true;
        
        temp=temp->siguiente;
    }
    return false;
}


*/