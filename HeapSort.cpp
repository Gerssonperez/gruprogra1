#include <iostream>
#define max 100

using namespace std;
 
int main()
{
    int padre[max],i,j,k,n,item,temp;
    
    cout<<"Ingresa la cantidad de numeros del areglo ordenar: ";
    cin>>n;
    
    system("cls");
    cout<<"Ingrese numeros:" <<endl;
    
    for(i=1;i<=n;i++) 
    cin >> padre[i];
    
    for(k=n;k>0;k--)
    {
        for(i=1;i<=k;i++)
        {
            item=padre[i];
            j=i/2;
            while(j>0 && padre[j]<item)
            {
                padre[i]=padre[j];
                i=j;
                j=j/2;
            }
            padre[i]=item;
        }
        temp=padre[1];
        padre[1]=padre[k];
        padre[k]=temp;
    }
    cout<<"El orden es:"<<endl;
    for(i=1;i<=n;i++)
    cout<<padre[i] << endl;
    return 0;
}


