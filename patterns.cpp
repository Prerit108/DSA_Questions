#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// pattern 1
// ****
// ****
// ****
// ****
// int main(){
//     int a =4;
//     for(int i = 1 ; i <= a;i++){
//         for(int j = 0; j < a;j++){
//             cout << "*";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 2
// *
// **
// ***
// ****
// *****
// int main(){
//     int a =5;
//     for(int i = 1 ; i <= a;i++){
//         for(int j = 0; j < i;j++){
//             cout << "*";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 3
// 1
// 12
// 123
// 1234
// 12345
// int main(){
//     int a =5;
//     for(int i = 1 ; i <= a;i++){
//         for(int j = 1; j <= i;j++){
//             cout << j;
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 4
// 1
// 22
// 333
// 4444
// 55555
// int main(){
//     int a =5;
//     for(int i = 1 ; i <= a;i++){
//         for(int j = 1; j <= i;j++){
//             cout << i;
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 5
// *****
// ****
// ***
// **
// *
// int main(){
//     int a =5;
//     for(int i = a ; i >= 1;i--){
//         for(int j = 1; j <= i;j++){
//             cout << "*";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 6
// 12345
// 1234
// 123
// 12
// 1
// int main(){
//     int a =5;
//     for(int i = a ; i >= 1;i--){
//         for(int j = 1; j <= i;j++){
//             cout << j;
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 7
//      *
//     ***
//    *****
//   *******
//  *********

// int main(){
//     int a =5;
//     for(int i = 0 ; i < a;i++){
//         for(int k = a; k > i;k--){
//             cout << " ";
//         }
//         for(int j = 1; j <= 2*i + 1 ;j++){
//             cout << "*";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// pattern 8
//  *********
//   *******
//    *****
//     ***
//      *
// int main(){
//     int a = 5;
//     for (int i = a; i > 0;i--){
//         for(int k = a; k >= i ;k--){
//             cout << " ";
//         }
//         for(int j = 0; j < (2*i - 1);j ++){
//             cout << "*";
//         }
//         cout << "\n";
//     }
// }

// pattern 9
//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *

// int main(){
//     int a  = 10;
//     for(int i = 0 ;i < a/2; i++){
//         for(int k = 1; k < a/2-i;k++){
//             cout << " ";
//         }
//         for(int j = 0;j < 2*i + 1;j++){
//             cout << "*";
//         }cout << "\n";
//     }
//     for(int i = 0;i < a/2;i++){
//         for(int k = 0 ; k < i;k++){
//             cout << " ";
//         }
//         for (int j = 0 ; j < a-1-2*i;j++){
//             cout << "*";
//         }
//         cout<< "\n";
//     }
//     return 0;
// }

// pattern 10
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
// int main(){
//     int a  = 9;
//     for(int i = 0 ;i < (a/2 +1);i++){
//         for(int j = 0 ;j<=i;j++){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     for(int i = 0;i < a/2;i++){
//         for(int j = 0;j < a/2 - i;j++){
//             cout << "*";
//         }
//         cout << "\n";
//         }
// }

// pattern 11
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1
// 0 1 0 1 0 1
// 1 0 1 0 1 0 1
// 0 1 0 1 0 1 0 1
// 1 0 1 0 1 0 1 0 1
// int main(){
//     int a = 9;
//     for(int i = 1 ;i <= a;i++){
//         for (int j = 0;j < i;j++){
//             cout << (i-j)%2 << " ";
//         }
//         cout << "\n";
//     }
// }

// pattern 12
// 1      1
// 12    21
// 123  321
// 12344321
// int main(){
//     int a =4;
//     for(int i = 1; i<= a;i++){
//         for(int j =1;j<=i;j++){
//             cout << j;
//         }
//         for(int k = 0; k < (a-i); k++ ){
//             cout << "  ";
//         }
//         for(int j =1;j<=i;j++){
//             cout << i-j+1;
//         }
//         cout << endl;
//     }
// }

// pattern 13
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
// int main(){
//     int a = 5,c = 1;
//     for(int i = 1; i <= 5;i++){
//         for(int j = 1; j <= i ; j++){
//             cout << c++ << " ";
//         }
//         cout << "\n";
//     }
// }

// pattern 14
// A
// AB
// ABC
// ABCD
// ABCDE
// int main(){
//     int a = 5;
//     for(int i = 1;i <= a;i++){
//         for(char c = 'A';c < 'A' + i;c++){
//             cout << c;
//         }
//         cout << "\n";
//     }

//     return 0;
// }

// pattern 15
// ABCDE
// ABCD
// ABC
// AB
// A
// int main(){
//     int a = 5;
//     for (int i = a;i > 0;i--){
//         for(char j = 'A';j < 'A' + i;j++){
//             cout << j;
//         }
//         cout << endl;
//     }
// }

// pattern 16
// A
// BB
// CCC
// DDDD
// EEEEE
// int  main(){
//     int a = 5;
//     for (int i =0;i < a;i++){
//         for(int c = 0;c <= i;c++){
//             char b = 'A';
//             b =  b + i;
//             cout << b;
//         }
//         cout << "\n";
//     }
// }

// pattern 17
//    A
//   ABA
//  ABCBA
// ABCDCBA
// int main()
// {
//     int a = 4;
//     char d;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 0; j < a - i; j++)
//         {
//             cout << " ";
//         }
//         for (char c = 'A'; c < 'A' + i; c++)
//         {
//             cout << c;
//             d = c;
//         }
//         for(char c = d-1 ; c >='A' ; c--){
//             cout << c;
//         }
//     cout << "\n";
//     }  
// }

// pattern 18


// pattern 19
// * * * * * *
// * *     * *
// *         *
// *         *
// * *     * *
// * * * * * *

// void symmetry(int n) {
//   for (int i = 0; i < 2 * n; i++) {

//     if (i < n) {
//       for (int j = 0; j < n - i; j++) {
//         cout << "* ";
//       }
//       for (int k = 0; k < 4 * i; k++) {
//         cout << " ";
//       }
//       for (int j = 0; j < n - i; j++) {
//         cout << "* ";
//       }

//     } else {
//         for (int j = 0; j <= i - n ; j++) {
//         cout << "* ";
//       }

//       for (int k = 0; k < 4 * (2 * n - i - 1); k++) {
//         cout << " ";
//       }
//       for (int j = 0; j <= i - n; j++) {
//         cout << "* ";
//       }

//     }
//     cout << endl;
//   }
// }

// int main()
// {
//     int a = 3;
//     symmetry(a);
// }

// pattern 20
//*         *
//* *     * *
//* * * * * *
//* *     * *
//*         *
//  void symmetry1(int n) {
//      for(int i = 1;i < 2*n;i++){
//          if (i <= n){
//              for(int j = 0 ;j < i ;j++){
//                  cout << "* ";
//              }
//              for(int j = 0 ;j <4*(n-i) ; j++){
//                  cout << " ";
//              }
//              for(int j = 0 ;j < i ;j++){
//                  cout << "* ";
//              }

//         }
//         else {
//             for(int j = 0 ;j < 2*n - i ;j++){
//                 cout << "* ";
//             }
//             for(int j = 0 ;j <4*(i - n) ; j++){
//                 cout << " ";
//             }
//             for(int j = 0 ;j < 2*n - i ;j++){
//                 cout << "* ";
//             }

//         }
//         cout << endl;

//     }
// }
// int main()
// {
//     int a = 3;
//     symmetry1(a);
// }

// pattern 21
// ***
// * *
// ***
// void getStarPattern(int n) {
//     for(int i = 1; i <= n;i++){
//         if( i == 1  || i == n){
//             for(int j = 0 ;j < n;j++){
//                 cout << "*";
//             }
//         }
//         else {
//             cout << "*";
//             for(int j =0;j < n-2;j++){
//                 cout << " ";
//             }
//             cout << "*";

//         }
//         cout << endl;
//     }

// }
// int main(){
//     int a = 3;
//     getStarPattern(a);
//     return 0;
// }

// pattern 22
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

// int main(){
//     int n = 4;
//     for(int i = 0;i < 2*n-1;i++){
//         for(int j = 0;j < 2*n-1;j++){
//             int top = i;
//             int left = j;
//             int right = (2*n -2) - j;
//             int bottom = (2*n - 2) - i;
//             cout << (n-min(min(top,bottom),min(left,right)));
//         }
//         cout << "\n";
//     }
//     return 0;
// }