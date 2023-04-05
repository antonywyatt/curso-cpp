#include<iostream>

using namespace std;

int main(){
    //hacer una matriz identidad nxn
    int n;
    cout<<"Ingrese el valor de n: ";
    cin>>n;
    int matriz[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                matriz[i][j] = 1;
            }else{
                matriz[i][j] = 0;
            }
        }
    }
    cout<<"La matriz identidad es: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;   
}