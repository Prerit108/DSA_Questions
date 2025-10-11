/* #include<iostream>

int main(){
    std::cout << "hello world \n";
    std::cout << "hello" << std::endl <<"world" ;
    std::cout<<"\n" <<"world";

}*/

#include <bits/stdc++.h> //includes all the cpp libraries
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}
int func1(int &n){
    n = n + 10;
    cout << n << "\n";
}

int main()
{
    // for the output >>>>>>>>>>>>>>>>>>>>>>>>>>>
    // cout << "hello world \n";
    // cout << "hello" << endl <<"world" ;
    // cout<<"\n" <<"world";

    // for taking the input>>>>>>>>>>>>>>>>>>>>>>>

    // int x ,y;
    // cin >> x >> y;
    // cout << "value of x is " << x << "\n" << "value of y is " << y;
    // int z = 90;
    // long v = 8978868;
    // float flo = 89.43;

    // for taking string as input >>>>>>>>>>>>>>>>>>>>>>>
    // we have 2 functions string and getline >>>>>>>

    // string s1 , s2;
    // cin >> s1 >> s2;  //could only take one word as input, after the space input value is stored in the next variable
    // cout << s1 << " " << s2;

    // getline func

    // string str;
    // getline(cin ,str); // stores the whole line , until the user presses the enter
    // cout<< str ;

    // character

    // char ch , cha = 'u';
    // cin >> ch;
    // cout << ch ;

    // if else statement #########################################

    // int age ;
    // cout << "enter the age ";
    // cin >> age;
    // if(age < 18){
    //     cout << "not an adult\n";
    // }
    // else
    // {
    //     cout << "adult";
    // }

    // int age;
    // cin >> age;
    // if(age < 18 ){
    //     cout << "not eligibe for the job";

    // }
    // else if (age < 55){
    //     cout << "eligibe for job \n";
    // }
    // else if (age <= 57){
    //     cout << "eligible for the job but retirement soon";
    // }
    // else{
    //     cout << "retirement soon";
    // }

    // sitch case statemetnt #######################################3

    // int num ;
    // cin >> num;
    // switch (num)
    // {
    // case 1:
    //     cout << "the value of num is 1";
    //     break;
    // case 4:
    //     cout << "the value of num is 4";
    //     break;

    // case 9:
    //     cout << "the value of the num s 9";
    //     break;
    // default :
    //     cout<< "not a valid int";
    // }

    // arrays %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // arrays are a continous block of memory store can be 1D 2D and so on.

    // int arr[5];
    // cin >> arr[0] >>  arr[1] >> arr[2] >> arr[3] >> arr[4];
    // arr[4] = 90;
    // cout << arr[4];

    // strings $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    // string s = "strings";
    // int len = s.size();
    // s[len - 1] = 'z';
    // cout << s[len - 1];

    // for loop &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

    // for(int i =0 ; i <= 10 ; i++){
    //     cout << "hello world \n";
    // }

    // while loop &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

    // int j = 0;
    // while(j < 5){
    //     cout << j << "\n";
    //     j++;
    // }

    // do while loop #################################################

    // int j = 5;
    // do{
    //     cout << j << "\n";
    //     j++;

    // }while(j<4);

    // functions %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // void -- func returns nothing

    // int a, b;
    // cout << "enter 2 numbers";
    // cin >> a >> b;
    // cout << add(a,b);
    
    // pass by value ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //when a parameter is given to a function it takes the copy of the original value.
    //This copy of the num is used by the function to give the final result while the original nuumber(argument) passed remain unchanged .

    // pass by reference
    // changes are done on the real argument given of the function. 
    // work with every data type.
    // arrays are always passed by reference , no need to add "&"
    // int num = 10;
    // func1(num);
    // cout << num;


    return 0;
}
