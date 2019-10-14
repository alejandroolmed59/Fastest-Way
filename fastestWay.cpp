#include <iostream>
using namespace std;


int main() {
  int n=4;
  int a[2][4]= {{8,9,11,4},{5,8,7,7}};
  int t[2][3]= {{4,2,1},{3,3,2}};
  int e[2]= {6,5};
  int x[2]={10,8};
  
  int f1[4];
  int f2[4];
  f1[0] = e[0]+ a[0][1];
  f2[0] = e[1]+ a[1][0];
  for(int i=1; i<n; i++){
    if(f1[i-1]+ a[0][i]<= f2[i-1]+t[1][i-1]+a[0][i]){
      f1[i]= f1[i-1]+ a[0][i];
    }else{
      f1[i] = f2[i-1]+t[1][i-1]+a[0][i];
    }

    if(f2[i-1]+ a[1][i]<= f1[i-1]+ t[0][i-1]+ a[1][i]){
      f2[i]= f2[i-1]+ a[1][i];
    }else{
       f2[i]= f1[i-1]+ t[0][i-1]+ a[1][i];
    }
  }
  if(f1[n-1]+x[0]<= f2[n-1]+x[1]){
    cout<<"Min: "<<f1[n-1]+x[0];

  }else{
    cout<<"Min: "<<f2[n-1]+x[1];
  }

}