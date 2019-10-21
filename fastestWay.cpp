#include <iostream>
#include <string> 
using namespace std;

int main() {
  int n=4;
  int a[2][4]= {{30,90,30,40},{1,1,5,200}};
  int t[2][4-1]= {{1,2,1},{3,3,2}};
  int e[2]= {2,1};
  int x[2]={10,8};
  //INICIA ALGORITMO ASEMBLY LINE 
  int f1[n];
  int f2[n];
  string pool1="";
  string pool2="";

  f1[0] = e[0]+ a[0][0];
  f2[0] = e[1]+ a[1][0];
  for(int i=1; i<n; i++){
    if(f1[i-1]+ a[0][i]<= f2[i-1]+t[1][i-1]+a[0][i]){
      f1[i]= f1[i-1]+ a[0][i];
      pool1+= "1-> ";
    }else{
      f1[i] = f2[i-1]+t[1][i-1]+a[0][i];
      pool1+= "2-> ";
    }
   
    if(f2[i-1]+ a[1][i]<= f1[i-1]+ t[0][i-1]+ a[1][i]){
      f2[i]= f2[i-1]+ a[1][i];
      pool2+= "2-> ";
    }else{
      f2[i]= f1[i-1]+ t[0][i-1]+ a[1][i];
      pool2+= "1-> ";
    }
    
  }
  if(f1[n-1]+x[0]<= f2[n-1]+x[1]){
    cout<<"Min: "<<f1[n-1]+x[0]<<endl;
    cout<<pool1<<"1"<<endl;
  }else{
    cout<<"Min: "<<f2[n-1]+x[1]<<endl;
    cout<<pool2<<"2"<<endl;
  }

}