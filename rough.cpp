#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){

   int arr[10]={0};
   int n ;
   cout<<"enter the number : ";
 cin>>n;
 while(n>0){
    arr[n%10]++;
   n=n/10;}

cout<<endl;
for(int i =0;i<10;i++) {   cout<<i<<" -> "<<arr[i]<<endl;}

return 0;





    return 0;
}


    

