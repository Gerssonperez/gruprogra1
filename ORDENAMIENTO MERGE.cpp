#include<iostream>
#include<conio.h>
using namespace std;
int a[20];
void merge(int,int,int);

void merge(int izquierda,int medio,int derecha){
    int h,i,l,b[20],s;
    h=izquierda;
    i=izquierda;
    l=medio+1;
    
    while((h<=medio)&&(l<=derecha)){
        if(a[h]<=a[l]){
            b[i]=a[h];
            h++;
        }
        else
            {
                b[i]=a[l];
                l++;
            }
        i++;
    }
    if(h>medio){
        for(s=l;s<=derecha;s++){
            b[i]=a[s];
            i++;
        }
    }
    else
        {
            for(s=h;s<=medio;s++){
                b[i]=a[s];
                i++;
            }
        }
    for(s=izquierda;s<=derecha;s++){
        a[s]=b[s];
        }
}
void merge_sort(int izquierda,int derecha){
    int medio;
    if(izquierda<derecha){
        medio=(izquierda+derecha)/2;
        merge_sort(izquierda,medio);
        merge_sort(medio+1,derecha);
        merge(izquierda,medio,derecha);
    }
}
int main(){
    int num,i;
    cout<<"Ingrese la cantidad de columnas"<<endl;
    cin>>num;
    cout<<endl;
    cout<<"Las variables serian:"<<endl;
    for(i=1;i<=num;i++){
        cin>>a[i] ;
    }
    merge_sort(1,num);
    cout<<endl;
    cout<<endl<<endl;
    cout<<"Este seria el nuevo orden:"<<endl;
    for(i=1;i<=num;i++){
        cout<<a[i]<<"   ";
    }
    return 0;
}
