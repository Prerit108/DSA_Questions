#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursiom -> When a function calls itself until a specified condition is met.
// Stack Overflow -> When there are function calls , they are stored in a stack space until they are executed.
//                   When this stack fills up completely, function call after that could not be stored in the stack.
//                   This condition is called as stack overflow
// Base Condition -> The condition used to stop the recursion.

// void f(){
//     if(cnt == 3){
//         return ;    // Indicates that the function is over. Code below it will not be executed.
//     }
//     cnt++;
//     f();
// }

// Q Print name 5 times.
// TC - O(n)
// SC - O(n)
void print1(int N,int cnt = 1){
    if(cnt > N){
        return;
    }
    cout << "Name ";
    print1(N , cnt + 1);
}

// Q Printing no. 1 to N using recursion.
void print2(int n,int cnt =1){
    if(cnt > n){
        return;
    }
    cout << cnt << endl;
    
    print2(n,cnt + 1);
}

// Q Printing no. N to 1 using recursion.
void print3(int n,int cnt =1){
    if(n < cnt){
        return;
    }
    cout << n-cnt+1 << " ";
    print3(n,cnt + 1);
}

// Q Printing no. 1 to N by backtracking.
// backtracking explained in written notes.
void print4(int n,int cnt ){
    if(cnt < 1){
        return;
    }
    print4(n,cnt - 1);
    cout << cnt << " ";
}

// Q Printing N to 1 using backtracking.
void print5(int n , int cnt){
    if (cnt > n){
        return;
    }
    print5(n,cnt+1);
    cout << cnt <<" ";
    

}

// Q Sum of first N numbers.(Parametrized way)
void func1(int n,int cnt =0 ){
    if(n < 1){
        cout << cnt;
        return;
    }
    cnt = cnt + n;
    func1(n-1,cnt);
}

// Q Sum of first N numbers.(Functional way)
int func2(int n){
    if(n==0){
        return 0;
    }
    return n + func2(n-1);
}

// Q Factorial of N.
int func3(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return n*func3(n-1);
}

// Q Reverse an array.
void func4(int arr[],int s,int n=0){ // s is the length of the array
    
    if((s-1)/2 <= n){
        return;
    }

    swap(arr[s-n-1],arr[n]);
    func4(arr,s,n+1) ;
}
// Q Check if a string is palindrome or not.
void func5(string str,int ss , int i = 0){
    if((ss-1)/2 < i){
        cout << "Palindrome";
        return;
    }
    if(str[ss-1-i] != str[i]){
        cout << "Not Palindrome";
        return;
    }
    func5(str,ss,i+1);
}
// Q Reversing a string.
void func6(string &str, int ss, int i = 0) { 
    if ((ss - 1) / 2 < i) {
        return; 
    }
    swap(str[ss - 1 - i], str[i]); 
    func6(str, ss, i + 1);
}


// Multiple Recursion calls. 
// Q Fibonacci series
int func7(int n){
    if(n <= 1){
        return 1;
    }
    return func7(n-1) + func7(n-2);
}
// TC is O(2^n) 

// SUBQUENCE  
// TC - O((2^n)*n)
// SC - O(n)
void func8(int ind,vector<int> vec,int arr[],int n){
    if(ind >= n){
        for(auto it = vec.begin(); it != vec.end() ; it++){
            cout << *it << " ";
        }
        cout << "\n";
        return;
    }
    vec.push_back(arr[ind]);
    func8(ind + 1,vec,arr,n);                //used to take the index in the subsequence
    vec.pop_back();
    func8(ind + 1,vec,arr,n);                //used to not take the index in the subsequence


    // Another way 
    // func8(ind + 1,vec,arr,n);              
    // vec.push_back(arr[ind]);    
    // func8(ind + 1,vec,arr,n);
}

// Printing subsequence whose sum is k.
void func9(int ind,vector<int> vec,int arr[],int n,int k,int cnt){
    if(ind >= n){
        // for(auto it = vec.begin();it != vec.end();it++){
        //     cnt = cnt + *it;
        // }
        if(cnt == k){ 
            for(auto it : vec){
            cout << it << " ";
            }
            cout <<  "\n";
        }
        return;
    }
    func9(ind + 1,vec,arr,n,k,cnt); // not taking current element
    vec.push_back(arr[ind]);
    cnt += arr[ind];   
    func9(ind + 1,vec,arr,n,k,cnt);  // taking current element


} 

// Print any one subsequence whose sum is sum.
bool func10(int ind , vector<int> vec,int arr[],int n,int k,int cnt){
    if(ind >= n){
        if(cnt == k){
            for(auto it : vec){
            cout << it << " ";
            return true;
            }
        }
        else {
            return false;
        }
    }
    vec.push_back(arr[ind]);
    cnt += arr[ind];   
    
    // taking current element 
    if(func10(ind + 1,vec,arr,n,k,cnt) == true){     
        return true;
    }      
    vec.pop_back();
    cnt -= arr[ind];
    
    // not taking current element

    if(func10(ind + 1,vec,arr,n,k,cnt) == true){     
        return true;
    }  

    return false;
}

// Count the number of subsequence whose sum is k.
// TC - O(2^n)
int func11(int ind,int arr[],int n,int k,int cnt){
    if(ind >= n){
        // for(auto it = vec.begin();it != vec.end();it++){
        //     cnt = cnt + *it;
        // }
        if(cnt == k){ 
            return 1;

        }
        else return 0;
    }
    int l = func11(ind + 1,arr,n,k,cnt); // not taking current element
    cnt += arr[ind];   
    cnt = func11(ind + 1,arr,n,k,cnt);  // taking current element
    return l + cnt;
} 



int main(){
    // int arr[] = {1,2,3,4,5} ;
    // int s = sizeof(arr)/sizeof(arr[0]); 
    // func4(arr,s);
    // for(int i = 0;i < 5;i++){
    //     cout << arr[i] << " ";
    // }


    // string str = "madam";
    // int ss = str.size();
    // func5(str,ss);
    // return 0;

    vector<int> vec ;
    int arr[] = {7,5,6,5};
    cout << func11(0,arr,4,5,0);
     
}
