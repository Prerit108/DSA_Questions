#include <bits/stdc++.h> //includes all the cpp libraries
#include <iostream>
using namespace std;

    bool comp(pair<int,int> p1 ,pair<int,int> p2){
        if(p1.second < p2.second){
            return true;
        }
        if(p1.second > p2.second){
            return false;
        }
        // if they are equal

        if(p1.first > p2.first) return true;
        return false;
    }


int main(){

    // STL(standard template library)
    // Algorithms
    // Containers
    // Iterators
    // Functions

    // PAIRS are present in the utility library

    // pair<int,char> p = {12,'o'};
    // cout << p.second;
    // pair<int,pair<int,int>> pa = {3,{7,8}};
    // cout << pa.second.first << " " << pa.second.second;

    // pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    // cout << arr[1].first;
    
    //VECTORS
    // dynamic in nature , not a fixed length
    // type of container
    // They are pass by value.##########

    // vector<int> v; // creates an empty container
    // v.push_back(20);
    // v.emplace_back(10); // works faster than push_back, automatically increases the size of the vector
    // v = {20,10,15,6,7}; 

    // vector <pair<int,int>> vec;
    // vec.push_back({1,2});
    // vec.emplace_back(5,10);

    // vector<int> v1(5,100); // creates a vector {100,100,100,100,100} like this

    // //vector<int> v1(5); // creates a empty vector with 5 places with garbage value in it

    // vector<int> v2(v1); // creates a copy of v1 in form of v2

    // cout << v[0];

    // //ITERATORS 
    // // points to the memory address
    // // * used for dereferencing
    // // let v be a vector containing the value {20,10,15,6,7}

    // vector<int>::iterator it = v.begin(); //syntax
    // // begin starts from the starting value of the datatype

    // it++;
    // cout << *(it) << " "; // will print the value 10

    // it = it + 2;
    // cout << *(it) << " ";

    // vector<int>::iterator t = v.end(); // points to the memory location just after the last value.
    // // vector<int>::iterator it = v.rend();
    // // vector<int>::iterator it = v.rbegin();

    // cout << *(t) << " ";  // garbage value
    
    // t--;
    // cout << *(t) << " "; // last element  of the vector

    // cout << v.back() << " "; // the value of last element

    // for (vector<int>::iterator it = v.begin() ; it != v.end() ; it++){
    //     cout << *(it) << " ";
    // } // can be written in short form by using 'auto'.
    // // 'auto' is used to automatically assigned the data type.
 
    // for (auto it = v.begin() ; it != v.end() ; it++){
    //     cout << *(it) << " ";
    // }

    // for(auto it : v) {
    //     cout << it << " ";
    // }

    // // Deletion in a vector

    // //{20,10,15,6,7}
    // v.erase(v.begin()+1); // delete the second element from the beginning,{20,15,6,7}

    // v.erase(v.begin()+1,v.begin()+3); // syntax is like [start , end) , end element is not included.
    // // deletes the 2nd and 3rd element.{20,6,7}

    // // INSERT function
    // // takes a lot of time

    // vector<int>vc(2,100); // {100,100}
    // vc.insert(v.begin(),300); // {300,100,100}
    // v.insert(v.begin() + 1, 2,10); // {300,10,10,100,100}

    // vector<int>copy(2,50);
    // v.insert(v.begin(),copy.begin(),copy.end()); //{50,50,300,10,10,100,100}

    // cout << vc.size();

    // vc.pop_back(); //deletes the last element
    
    // v.clear(); // clear the entire vector

    // cout << v.empty(); // conditional check

    // LISTS
    // dynamic in nature

    // list<int> ls;
    // ls.push_back(2); //{2}
    // ls.emplace_back(4); //{2,4}
    
    // ls.push_front(5); //{5,2,4}

    // ls.emplace_front(6); //{6,5,2,4}
    // // rest functions are same as vectors
    // // begin, end, rebegin, rend, clear,insert, size, swap

    // // DEQUE

    // deque<int>dq;
    // dq.push_back(1); //{1}
    // dq.emplace_back(2); // {1,2}
    // dq.push_front(3); //{3,1,2}
    // dq.emplace_front(4); //{4,3,1,2}

    // dq.pop_back(); // (4,3,1)
    // dq.pop_front(); //{3,1}

    // dq.back(); // prints last element
    // dq.front(); // prints the first element

    // // rest functions are same as vectors
    // // begin, end, rebegin, rend, clear,insert, size, swap

    // // STACK
    // // follows LIFO(last in first out)

    // stack<int> st;
    // st.push(1); //{1}
    // st.push(2); //{2,1}
    // st.push(3); //{3,2,1}
    // st.push(4); //{4.3.2.1}
    // st.emplace(5); //{5,4,3,2,1}

    // cout << st.top(); // prints 5 '
    // st.pop();
    // cout << st.top(); // prints 4
    // cout << st.size(); // prints 4
    // cout << st.empty(); // conditinal statement

    // stack<int>st1,st2;
    // st1.swap(st2);

    // //QUEUE 
    // //based on FIFO(first in first out)

    // queue<int> q;
    // q.push(1); // {1}
    // q.push(2); //{1,2}
    // q.emplace(4); //{1,2,4}

    // q.back() += 5;  //{1,2,9}

    // cout << q.back(); //prints 9

    // cout <<q.front(); //prints 1
    // q.pop() ; //{2,9}

    // cout << q.front() ; // prints 2

    // //PRIORITY_QUEUE 
    // // the largest element stays at the top
    // // also called as max heap

    // priority_queue<int>pq;
    
    // pq.push(5);// {5}
    // pq.push(2); //{5,2}
    // pq.push(8); //{8,5,2}
    // pq.emplace(10); //{10,8,5,2}

    // cout <<pq.top(); // prints 10
    // pq.pop(); // {8,5,2}

    // cout << pq.top(); // prints 8
    // //size swap empty functions are same as others

    // //Minimum heap
    // priority_queue<int,vector<int>,greater<int>> pqr;
    // pqr.push(5); //{5}
    // pqr.push(2); //{2.5}
    // pqr.push(8); //{2,5,8}
    // pqr.emplace(10); //{2,5,8,10}

    // cout << pq.top(); // prints 2

    //SET 
    // stores in sorted order
    // unique elements
    // everything happens in a logarithmic time complexity

    // set<int>set;
    // set.insert(1); //{1}
    // set.emplace(2); //{1,2}
    // set.insert(2); //{1,2}
    // set.insert(4); // {1,2,4}
    // set.insert(3); // {1,2,3,4}
    // set.insert(5);

    // // Functionality of insert in vector
    // // can be used also, that only increases efficiency

    // // begin() , end() , rbegin() , rend() , size()
    // // empty() and swap() are the same as above

    // auto ite = set.find(3); //returns an iterator which points to 3

    // cout << *(ite);

    // auto ite = set.find(6); //this will give a iterator after the last element, just like set.end().

    // set.erase(5); // erases 5 from set .Takes logarithmic time.

    // int cnt = set.count(1); // returns 0 or 1

    // auto it = set.find(3);
    // set.erase(it); // it takes constant time
    
    // set = {1,2,3,4,5};
    // auto it1 = set.find(2);
    // auto it2 = set.find(4);
    // set.erase(it1,it2); // after erase {1,4,5} [first,last)

    // // all the other functions work same as vector.
    // // lower_bound() and upeer_bound() function works in the same way
    // // as in vector it does

    // //syntax 
    //auto it = set.lower_bound(2);

    // // lowerbound 
    // // works with complexity of log(n)
    // // returns the first occurenc  e of the element if it occurs, if it doesn't occur
    // // then it returns the iterator of the next bigger element.
    // int a[] = {1,4,5,6,9,9};
    // int ind = lower_bound(a,a+6,4) - a; // lower_bound always returns the iterator 
    // // of the element, but by subtracting a ,it returns the indexing of the number
    // int ind = lower_bound(a,a+6,7) - a; // since 7 is not in the array , it will return the index of immediate greater number 4 in this case

    // int ind = lower_bound(a,a+6,10) - a;// since 10 is not present, returns the indexing after the last element 6 in this case
    // // running lowerbound on vector
    // //int ind = lower_bound(a.begin(),a.end(),number) - a.begin();


    // // upper_bound 
    // // works with complexity of log(n)
    // // returns the iterator that points to the next big element 
    // //auto it = set.upper_bound(3);

    // int ind = upper_bound(a,a+6,4) - a; // return 2
    
    // int ind = upper_bound(a,a+6,7) - a; // return 4

    // int ind = upper_bound(a,a+6,10) - a; // return 6

    // // running upperbound on vector
    // //int ind = upper_bound(a.begin(),a.end(),number) - a.begin();



    // // MULTISET
    // // sortes the data in a sorted manner
    // // But does not stores unique elements like the set 

    // multiset<int> ms;
    // ms.insert(1); //{1}
    // ms.insert(1); //{1,1}
    // ms.insert(1); //{1,1,1}

    // ms.erase(1); // all 1 wil be erased.

    // // to erase only a single 1
    // ms.erase(ms.find(1));
    
    // ms.erase(ms.find(1),ms.find(3));


    //UNORDERED SET
    
    // randomized order of storing 
    // stores only unique element
    // time complexity is O(1) in mostly every cases.
    // In some worst cases the time complexity is O(N).
    // unordered_set<int> ust;
    // lower_bound and upper_bound functions  doesnot work
    // Rest all functions are same as above.
    // It has a better complexity than set in most cases
    // Except some when collision happens


    // MAPS
    // stores data in form of {key, value}
    // key can be of any datdatype.
    // Stores unique key in sorted order. 
    // works in logathrimic of time

    // map<int,int> mpp;
    // map<pair<int,int>,int> mpp;
    // map<int,pair<int,int>> mpp;

    // mpp[1] = 2;
    // mpp.emplace(3,1);
    // mpp.insert({2,4});

    // {
    //     {1,2}
    //     {2,4}
    //     {3,1}
    // }

    // if the key is in pair form
    //mp[{2,3}] = 10;

    // for(auto it : mpp){
    //     cout << it.first << " " << it.second << "\n";
    // }

    // cout << mpp[1]; // prints 2
    // cout << mpp[5];  // prints 0 if key is not defined

    // auto itt = mpp.find(3);
    // cout << (*itt).second;

    // auto itt = mpp.find(5); // since key is not defined iterator points to mpp.end()

    // auto itt = mpp.lower_bound(2);
    // auto itt = mpp.upper_bound(3);

    // erase , swap ,size , empty are same as the above


    //MULTIMAP 
    // Everything same as a map , only it can store multiple keys.
    // Only mpp[keys] is not used here.
    // Can store duplicate keys.

    // UNORDERED MAP
    // Works in constant time O(1)
    // In worst case it goes to O(n). 
    // same as maps , but keys are stored in random manner.
    // no duplicate keys.
    // same as set and unordered_set difference.

    // ALGORITHM
    
    // this command directly sorts any value in a datatype (except map).
    // TC of internal sorting func is O((no. of values)*log (no. of values))
    // list<int> as ;
    // as = {1,5,3,2,9,7};
    // as.sort();
    // cout << *as.begin();


    
    // int arr[] = {1,4,2,3};
    // sort(arr,arr + 4); // [start,end)
    
    // vector<int> v;
    // v= {10,3,4,6};
    // sort(v.begin(),v.end()); // If v is a vector , then use this.

    // sort(arr+2 , arr+4); // used for sorting a part of array
    
    // sort(arr,arr + 4,greater<int>()); // sort in descending order

    // pair<int,int> a[] = {{1,2},{2,1},{4,1}};    
    // // sort it according to second element
    // // if the second element is same , then sort
    // // it according to first element but in descending
        

    // // bool comp(pair<int,int> p1 ,pair<int,int> p2){
    // //     if(p1.second < p2.second){
    // //         return true;
    // //     }
    // //     if(p1.second > p2.second){
    // //         return false;
    // //     }
    // //     // if they are equal

    // //     if(p1.first > p2.first) return true;
    // //     return false;
    // // }
    // int n = sizeof(a) / sizeof(a[0]);
    // sort(a,a + n,comp); //comp is a self written comparator



    // int num1 = 6;
    // int cnt = __builtin_popcount(num1); // tells us the no. of set bits

    // long long num = 134852138758237;
    // int cnt = __builtin_popcountll(num);

    // string s = "123";
    // sort(s.begin(),s.end());
    // do{ 
    //     cout << s << "\n";
    // }while(next_permutation(s.begin(),s.end())); // if there is no more permutation , it returns false
    
    // // to print all the permutation of the string start from the sorted string.
    // // Since next_permutation() function works in ascending order.

    // int arr[] = {2,6,1,3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int maxe = *max_element(arr,arr+n);
    
    // BINARY SEARCH USING STL
    int A[] = {1,4,5,8,9};
    bool res = binary_search(A,A+5,3); // Returns false

    bool res = binary_search(A,A+5,4); // Return true


    
    return 0;

}