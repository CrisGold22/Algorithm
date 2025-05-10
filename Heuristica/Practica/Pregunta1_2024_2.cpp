#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct proyecto{
    int id;
    int costo;
    int ganancia;
    int beneficio;
    vector <int> predecesores;
};

bool compara(proyecto a,proyecto b){
    double f1=1.0*a.beneficio*a.ganancia/a.costo;
    double f2=1.0*b.beneficio*b.ganancia/b.costo;
    
    return f1>f2;
}

bool verifica(proyecto proy,vector<proyecto>solu){
    int cont=0;
    
    if(!proy.predecesores.size()) return true; 
    for(int i=0;i<proy.predecesores.size();i++)
       for(int j=0;j<solu.size();j++)
           if(proy.predecesores[i]==solu[j].id)
               cont++;  
    return cont==proy.predecesores.size();    
}

int selecciona(proyecto *proy, int n,int p){
    int i=0,total=0,ganancia=0;
    vector<proyecto>solu;
    vector<proyecto>cart;
    
    sort(proy,proy+n,compara);
    cart.insert(cart.begin(),proy,proy+n);
    
    while(cart.size()>0 and total<p and i<cart.size()){
        if(verifica(cart[i],solu) and total+cart[i].costo<=p){
            total+=cart[i].costo;
            ganancia+=cart[i].ganancia;
            solu.push_back(cart[i]);
            cart.erase(cart.begin()+i);
            i=0;
        }
        else
            i++;
    }
    for(int i=0;i<solu.size();i++)
        cout << solu[i].id << " ";
    
    return ganancia;
}


int main(int argc, char** argv) {
    proyecto cartera[]={
        {1,80,150,2,{}},
        {2,20,80,4,{4}},
        {3,100,300,1,{1,2}},
        {4,100,150,4,{}},
        {5,50,80,2,{}},
        {6,10,50,1,{2}},
        {7,50,120,2,{6}},
        {8,50,150,4,{6}}};
    int presu=250;
    int n=sizeof(cartera)/sizeof(cartera[0]);
    
    cout << endl<<"Ganancia:"<< selecciona(cartera,n,presu);
    
    return 0;
}
