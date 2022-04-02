#include<iostream>
#include<conio.h>

using namespace std;
int Ordenamiento[50];
void Shell(int Numero);
void EscribirOrdenamiento(int Numero);
void LeerOrdenamiento(int Numero);


int main(){
    int Num;
    cout<<"Coloque la cantidad de columnas que tendra el arreglo: ";
    cin>>Num;
    LeerOrdenamiento(Num);
    Shell(Num);
    cout<<endl;
    EscribirOrdenamiento(Num);
    return 0;
}

void LeerOrdenamiento(int Numero){
    int i;
    for(i=1;i<=Numero;i++)
    {
        cout<<"Ordenamiento["<<i<<"]=";
        cin>>Ordenamiento[i];
    }
}

void EscribirOrdenamiento(int Numero){
    int i;
    cout<<"elementos ordenados por metodo Shell sort"<<endl;
    for(i=1;i<=Numero;i++)
    {
        
        cout<<"\t"<<Ordenamiento[i];
    }
}

void Shell(int Numero){
    int i,m,f,aumento,aux;
    
    aumento=Numero/2;
    
    while(aumento>0){
        for(i=aumento+1;i<=Numero;i++){
            m=i-aumento;
            while(m>0){
                if(Ordenamiento[m]>=Ordenamiento[m+aumento]){
                    aux = Ordenamiento[m];
                    Ordenamiento[m] = Ordenamiento[m+aumento];
                    Ordenamiento[m+aumento] = aux;
                }
                else{
                        m=0;
                    }
                m=m-aumento;
            }
        }
        aumento=aumento/2;
    }
}
