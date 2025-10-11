#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main(){
    //Q Counting the number of the digits in a integer and printing the number in reverse.
    // Time complexity is O(log 10 (n)).
    // Whenever the number of iterations(repetition) depends on division(or we are dividing a number) of number then the log comes in the time complexity.
    // The number with which division is happening comes at the base of log.
    // Eg -- if num was being divided by 2 then TC would be O(log 2 (n)).


    // int num1 = 0,num,count = 0;
    // cin >> num ;
    // cout << endl;
    // while(num != 0){
    //     //num1 = num%10 + 10*num1; // Used to read read the last digit of the number
    //     count += 1; 
    //     num = num/10;
    // }
    // cout << "the number in reverse" << num1 << "the number of digits in number is " << count;
     
    //##################################################################################################################################################################
    // Q  Example 1:
    // Input: x = 123 
    // Output: 321
    
    // Example 2:v
    // Input: x = -123
    // Output: -321
    
    // Example 3:
    // Input: x = 120
    // Output: 21

    // int rev = 0 , x;
    // cout << " enter the number \n";
    // cin >> x;
    // while(x != 0){
    //     rev = x%10 + rev*10;
    //     x = x/10;
    // }
    // cout << rev;

    // ##############################################################################################################
    // Q check if the number is palindrome or not

    // int num , rev =0;
    // cin >> num;
    // int num1 = num;
    // if (num < 0){
    //     cout << " the number is not palindrome";
    // }
    // while(num != 0){
    //     rev = num%10 + rev*10;
    //     num = num/10;
    // }
    // if(num1 == rev){
    //     cout << "The number is palindrome";
    // }
    // else 
    // cout << "The number is not palindrome";

    // ####################################################################################################################
    // Q Armstrong number
    // int num = 153,a =0;
    
    // while(num != 0){
    //     a = (num%10)*(num%10)*(num%10) + a;
    //     num = num/10;
    // }
    // cout << a;

    //#################################################################################################################3
    // Q Printing all the divisiors.
    // time complexity is O(N).

    // int num;
    // cout << "Enter the number \n";
    // cin >> num;
    // for(int i = 1;i<=num;i++){
    //     if(num%i == 0){
    //         cout << i << " ";
    //     }
    // }

    // Method 2 with less TC.
    // int num;
    // cout << "Enter the number \n";
    // cin >> num;
    // vector<int> vec;
    // // TC is O(sqrt(n))
    // for(int i = 1 ; i*i <= num;i++){  // can also use i <= sqrt(num) but it takes more time to call a function.
    //     if(num%i == 0){
    //         vec.emplace_back(i);
    //         if(i == num/i){
    //             cout << " ";
    //         }
    //         else
    //         vec.emplace_back(num/i);
    //     }

    // }
    // // O((no . of factors)*log (no . of factors))
    // sort(vec.begin(),vec.end());
    // // O(no. of factors)
    // for(auto it : vec){
    // cout << it << " ";
    // }

    // ##################################################################################################################3
    // Q Prime numbers
    // No. that has 2 factors 1 and no. itself.

    // TC of O(n)
    // int num,cnt = 0;
    // cin >> num;
    // for(int i = 1;i <= num;i++){
    //     if(num%i == 0){
    //         cnt++;
    //     }
        
    // }
    // if (cnt == 2)
    // cout << "It is a prime number";
    // else
    // cout << "It is a composite number";
    
    // shorter way
    
    // int num,cnt = 0;
    // cin >> num;
    // // O(sqrt(n))
    // for(int i = 1;i*i<=num;i++){
    //     if(num%i == 0){
    //         cnt++;
    //         if((num/i)%2 == 0)
    //         cnt++;
    //     }
    // }
    // if (cnt == 2)
    // cout << "It is a prime number";
    // else
    // cout << "It is a composite number";    

    //##################################################################################
    //Q GCD or HCF
    // TC O(min(n1,n2))
    // int n1,n2,gcd=1;
    // cin >> n1 >> n2;
    // for(int i = 1;i <= min(n1,n2);i++){
    //     if(n1%i == 0 && n2%i == 0){
    //         gcd = i;
    //     }                 
    // }
    // cout << gcd;

    // Method 2
    // TC O(min(n1,n2))
    // int n1,n2,gcd=1;
    // cin >> n1 >> n2;
    // for(int i = min(n1,n2);i >= 1 ;i--){
    //     if(n1%i == 0 && n2%i == 0){
    //         gcd = i;
    //         break;
    //     }                 
    // }
    // cout << gcd;

    //############################################################################################3

    //EUCLIDEAN ALGORITHM
    // GCD(n1,n2) = GCD(n1-n2,n2)    n1>n2
    // GCD(20,15) = GCD(5,15)
    // GCD(15,5) = GCD(10,5) = GCD(5,5) = GCD(0,5)
    // therefore GCD(20,15) = 5
    // We can reduce the length by using GCD(n1,n2) = GCD(n1%n2,n2)
    // When one of them become 0 the other number is the GCD 
    // TC -- O(log phi (min(n1,n2)))
    
    // int n1 , n2;
    // cin >> n1 >> n2;
    // while(n1 != 0 && n2 != 0){
    //     if(n1 > n2) {
    //         n1 = n1%n2;
    //     }
    //     else {
    //         n2 = n2%n1;
    //     }
    // }
    // cout << max(n1,n2);

    // Q LCM
    // int A = 17,B = 5,c;
    // int a = A, b = B;
    // while( A != 0 && B != 0){
    //     if(A > B){
    //         A = A%B;
    //     }
    //     else{ 
    //         B = B%A;
    //     }
        
            
    //     }
    //     cout << (a*b)/max(A,B);
    //     cout << " LCM is  " << (a*b)/max(A,B);

    

    return 0;
}