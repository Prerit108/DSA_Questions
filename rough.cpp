#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int main(){

//    int arr[10]={0};
//    int n ;
//    cout<<"enter the number : ";
//    cin>>n;
//    while(n>0){
//    arr[n%10]++;
//    n=n/10;
//    }

//    cout<<endl;
//    for(int i =0;i<10;i++) {   cout<<i<<" -> "<<arr[i]<<endl;}

//    return 0;


// }


    

// #include <fstream> 
// #include <iostream> 
// #include <string>
// using namespace std;  
// int main () { 
//    char data[100]; 
//    // open a file in write mode. 
//    ofstream outfile; 
//    outfile.open("afile.dat"); 
//    cout << "Writing to the file" << endl; 
//    cout << "Enter your name: ";  
//    cin.getline(data, 100); 
 
//    // write inputted data into the file. 
//    outfile << data << endl; 
 
//    cout << "Enter your age: ";  
//    cin >> data; 
//    cin.ignore(); 
    
//    // again write inputted data into the file. 
//    outfile << data << endl; 
 
//    // close the opened file. 
//    outfile.close(); 
 
//    // open a file in read mode. 
//    ifstream infile;  
//    infile.open("afile.dat");  
  
//    cout << "Reading from the file" << endl;  
//    infile.getline(data, 200);  
 
//    // write the data at the screen. 
//    cout << data << endl; 
    
//    // again read the data from the file and display it. 
//    infile >> data;  
//    cout << data << endl;  
 
//    // close the opened file. 
//    infile.close(); 
 
//    return 0; 
// } 

void subseq(vector<vector<int>> &vec,int arr[],int n,int ind,vector<int> &vec1){
    if(ind >= n){
        vec.emplace_back(vec1);
        return;
    }
    subseq(vec,arr,n,ind+1,vec1);
    vec1.emplace_back(arr[ind]);
    subseq(vec,arr,n,ind+1,vec1);
    vec1.pop_back();
    
}


int main() 
{
    vector<int> vec1;
    vector<vector<int>> vec;
    int arr[] = {3,1,2};
    subseq(vec,arr,3,0,vec1);
    for(auto &v : vec) {
        for(int x : v) cout << x << " ";
        cout << endl;
    }

    return 0; 
} 