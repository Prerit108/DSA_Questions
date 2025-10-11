#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int f(int arr[], int low, int high)
{
  int pindex = low;
  int i = low;
  int j = high;
  while (i < j)
  {
    while (i < high && arr[i] <= arr[pindex])
    {
      i++;
    }
    while (j > low && arr[j] > arr[pindex])
    {
      j--;
    }
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[j], arr[low]);
  return j;
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pindex = f(arr, low, high);
    quicksort(arr, low, pindex - 1);
    quicksort(arr, pindex + 1, high);
  }
}

int main()
{

  // Largest element
  // TC O(n)
  // int arr[5] = {3,2,1,5,2};
  // int max = arr[0];
  // for(int i = 0;i <= (5-1);i++){
  //     if(max <= arr[i]){
  //         max = arr[i];
  //     }
  // }
  // cout << max;

  // Second largest element without sorting
  // int arr[5] = {1,4,8,6,2};
  // int max = arr[0];
  // int max2 = INT_MIN;
  // Method 1
  // TC O(2N)
  // for(int i = 0;i < 5-1;i++){
  //     if(arr[i] > max ){
  //         max = arr[i];
  //     }
  // }
  // for(int i =0;i < 5-1;i++){
  //     if(arr[i]< max && max2 < arr[i]){
  //         max2 = arr[i];
  //     }
  // }
  // cout << max2;

  // Method 2 (More optimized)
  // TC O(N)
  // for(int i = 0;i < 5;i++){
  //     if(arr[i] > max ){
  //         max2 = max;
  //         max = arr[i];
  //     }
  //     else if (arr[i] > max2 && arr[i] < max){
  //         max2 = arr[i];
  //     }
  // }

  // Second smallest
  // int min = arr[0];
  // int min2 = INT_MAX;
  // for(int i = 1;i<5;i++){
  //     if(arr[i] < min){
  //         min2 = min;
  //         min = arr[i];
  //     }
  //     else if(arr[i] > min && arr[i] < min2){
  //         min2 = arr[i];
  //     }
  // }
  // cout << min2;

  // int arrr[] = {1,2,3,4,5};
  // for(int i = 0;i<5-1;i++){
  //     if(arrr[i] > arrr[i+1]){
  //         cout << "Unsorted";
  //         break;
  //     }
  // }

  // Removing Duplicates from a sorted array

  // TC O(N*log(N) + N)
  // SC O(N)
  // int arr1[] ={1,1,2,2,3,3,3};
  // set<int> set ;
  // for(int i = 0; i<7 ;i++){
  //     set.insert(arr1[i]);        // set takes TC O(log(N))
  // }
  // int index = 0;
  // for(auto it :set){
  //     arr1[index] = it;
  //     index++;
  // }

  // TC O(N)
  // SC O(1)
  // int cnt = 0;
  // int element = arr1[0];
  // for(int i =1; i < 7;i++){
  //     if(element != arr1[i]){
  //         cnt++;
  //         element = arr1[i];
  //         arr1[cnt] = arr1[i];
  //     }
  //     else {
  //         arr1[i] = 0;
  //     }
  // }
  // for(int i =0;i<7;i++){
  //     cout << arr1[i] << " ";
  // }

  // Left rotate an array by 1 place.
  // TC O(N)
  // int arr2[] ={1,2,3,4,5,6,7,8};
  // int len = sizeof(arr2)/sizeof(arr2[0]);
  // int a = arr2[0];
  // for(int i = 1;i < len;i++){
  //     arr2[i-1] = arr2[i];
  // }
  // arr2[len-1] = a;
  // for(int i =0;i<len;i++){
  //     cout << arr2[i];
  //     cout << " ";
  // }

  // Left rotate an array by D places

  // Method 1
  // TC O(N + D)
  //  SC O(D)
  //  cout << "Enter d";
  //  int d;
  //  cin >>  d;
  //  if(d >= len){
  //      d = d%(len);
  //  }
  //  int arr3[d];
  //  for(int i=0;i <d;i++){
  //      arr3[i]=arr2[i];
  //  }
  //  for(int j = d ; j<len; j++){
  //      arr2[j-d] = arr2[j];
  //  }
  //  for(int i =0;i<d;i++){
  //      arr2[len - d + i] = arr3[i];
  //  }

  // Method 2
  // TC O(2N)
  // SC O(1)
  // cout << "Enter d";
  // int d;
  // cin >>  d;
  // if(d >= len){
  //     d = d%(len);
  // }
  // for(int i =0 ; i<d/2;i++){       // Reversing the array upto d index
  //     swap(arr2[i],arr2[d-i-1]);
  // }
  // for(int j =d ;j<len/2; j++){     // Reversing the array from d to end
  //    swap(arr2[j],arr2[len/2+j-d]);
  // }
  // for(int i =0 ; i<len/2;i++){       // Reversing the whole array
  //     swap(arr2[i],arr2[len-i-1]);
  // }

  // Moving all the zeroes to the end of the array
  // TC O(2N)  worst case if whole array is 0
  // int arr4[] = {0,2,0,0,3,0,4,0};
  // int len1 = sizeof(arr4)/sizeof(arr4[0]);
  // int cnt = 0;
  // for(int i = 0;i<len1;i++){
  //     if(arr4[i] != 0){
  //         arr4[cnt] = arr4[i];
  //         cnt++;
  //     }
  // }
  // if(cnt != 0){
  //     for(int i = cnt+1;i < len1;i++){
  //         arr4[i] = 0;
  //     }
  // }

  // Union of 2 arrays

  // Method 1
  // TC O(n1*log(n)+n2*log(n)+n1+n2)
  // here n = size of set
  // SC O(n1 + n2)[space used by set] + O(n1 + n2)[space used by array]

  // int arr[] =  {1,1,2,2,3,4,4,5,8};
  // int arr1[] = {1,2,3,3,4,4,5,7,7};
  // int len = sizeof(arr) / sizeof(arr[0]);
  // int len1 = sizeof(arr1) / sizeof(arr1[0]);
  // vector<int> uni;

  // set<int> s;
  // for(int i =0;i<len;i++){        // let the loop runs n1 time
  //     s.insert(arr[i]);
  // }
  // for(int i = 0;i<len1;i++){      // let the loop runs n2 time
  //     s.insert(arr1[i]);
  // }
  // int i = 0;
  // for(auto it :s){                // this space is used to return the output in form of array
  //    uni[i] = it;
  //    i++;
  // }

  // Method 2
  // TC O(n1 + n2)
  // SC O(n1 + n2)    Used only for returning the answer
  // int i =0;
  // int j = 0;
  // while(i<len && j < len1){
  //     if(arr[i] <= arr1[j]){
  //         if(uni.size() == 0 || uni.back() != arr[i]){
  //             uni.push_back(arr[i]);
  //         }
  //         i++;
  //     }
  //     else
  //     {
  //         if(uni.size() == 0 || uni.back() != arr[i]){
  //             uni.push_back(arr[i]);
  //         }
  //         j++;
  //     }
  // }
  // while(j<len1){
  //     if(uni.back() != arr1[j]){
  //             uni.push_back(arr1[j]);
  //         }
  //         j++;
  // }
  // while(i<len){
  //     if(uni.back() != arr[i]){
  //             uni.push_back(arr[i]);
  //         }
  //         i++;
  // }

  // Intersection of sorted arays

  // Method 1
  // TC O(n1 * n2)
  // SC O(n2)
  // n2 is the space taken by the smallest array

  // vector<int> inter;
  // int arr2[len1]={0};
  // int i = 0;
  // int j = 0;
  // for(int k = 0;k<len;k++){
  //     for(int l = 0;l<len1;l++){
  //         if(arr[k] == arr1[l] && arr2[l] == 0){      // finding same number and taking it only if the number was not taken before
  //             arr2[l]++;                              // marking the element used once
  //             inter.push_back(arr1[l]);               // pushing the elements in the intersection array
  //             break;
  //         }
  //         if(arr1[l]>arr[k]){                         // skipping the smaller element and moving to the next element
  //             break;
  //         }
  //     }
  // }

  // Method 2
  // TC O(n1 + n2)
  // SC O(1)
  // while(i<len && j < len1){
  //     if(arr[i] < arr1[j]){           // skipping the smaller element
  //         i++;
  //     }
  //     else if(arr[i] == arr1[j]){     // adding the same elements in the intersection vector
  //         inter.push_back(arr[i]);
  //         i++;
  //         j++;
  //     }
  //     else{                              // skipping the smaller element
  //         j++;
  //     }
  // }

  // Missing number in an array

  // Method 1 (By comparing each element of both arrays)
  // TC O(N * N)   it is a hypothetical case
  // SC O(1)
  // int arr[7] = {5,1,2,3,4,6};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // for(int i = 1;i <= len;i++){
  //     int flag = 0;
  //     for(int j = 0;j < len;j++){
  //         if(i == arr[j]){
  //             flag = 1;
  //             break;
  //         }
  //     }
  //     if(flag == 0){
  //         cout << "missing number is " << i << "\n";
  //     }
  // }

  // Method 2 (By creating a hash array)
  // TC O(N + N)
  // SC O(N + 1)

  // int hash[len+1] = {0};
  // for(int i = 0;i<len ;i++){
  //     hash[arr[i]] += 1;
  // }
  // for(int j = 0;j<= len+1 ; j++){
  //     if(hash[j] == 0){
  //         cout << "Then missing number is " << j;
  //     }
  // }

  // Method 3 (By sum)
  // TC O(N)
  // SC O(1)

  // int c = 0;
  // int sum = (len*(len+1))/2;
  // for(int i = 0;i<len ;i++){
  //     c = c + arr[i];
  // }
  // cout << "The missing number is" << sum - c;

  // Method 4 (XOR method)( slightly better than the sum method)
  // XOR(^)
  // 0^0 = 0, 2^2 = 0
  // 2^2^2 = 0^2 = 2
  // 2^2^5^5 = 0^0 = 0
  // TC O()

  // int XOR1 = 0;
  // int XOR2 = 0;
  // for(int i = 0;i < len;i++){
  //     XOR1 = XOR1^arr[i];       // Creating a XOR of all elements in the array
  //     XOR2 = XOR2^(i+1);        // Creating a XOR of N natural numbers
  // }
  //
  // (1^2^3^4^5) ^ (1^2^4^5)
  // 	= (1^1)^(2^2)^(3)^(4^4)^(5^5)
  // 	= 0^0^3^0^0 = 0^3 = 3.
  // Hence the missing number in this case is 3
  //
  // cout << "The missing number is " << (XOR1 ^ XOR2);

  //  Maximum consecutive ones

  // int arr[] = {1,1,0,1,1,1,0,1,1};
  // int len = sizeof(arr) / sizeof(arr[0]);
  // int cnt = 0;
  // int maxi = 0;
  // for(int i = 0;i<len;i++){
  //     if(arr[i] == 1){
  //         cnt++;
  //         maxi = max(cnt,maxi);
  //     }
  //     else{
  //         cnt = 0;
  //     }
  // }
  // cout << maxi;

  // Find the number that appears once, and other numbers twice.

  // Method 1 (by comparing all elements)
  // TC O(N * N)
  // SC O(1)
  // int arr[] = {1,1,2,2,3,4,4,5,5};
  // int cnt =0 ;
  // int len = sizeof(arr)/sizeof(arr[0]);

  // for(int i = 1; i<=len;i++){
  //     for(int j = 0;j < len; j++){
  //         if(i == arr[j]){
  //             cnt++;
  //         }
  //     }
  //     if(cnt == 1){
  //         cout << "number appeared once" << i;
  //     }
  //     cnt = 0;
  // }

  // Method 2
  // TC O(3N)
  // SC O(maximum element of array)

  // int maxi = 0;
  // for(int i = 0;i<len;i++){         // Finding the max element to create the hash array
  //     maxi = max(arr[i],maxi);
  // }
  // int hash[maxi + 1] = {0};
  // for(int i = 0 ; i< len; i++){     // Filling the hash array
  //     hash[arr[i]]++;
  // }
  // for(int i = 0 ; i<= len; i++){
  //     if(hash[i] == 1){
  //         cout << "answer is " << i;
  //     }
  // }

  // Method 3
  // // Can't use hash array if number of elements exceed 10^6.
  // // In that case "map" or "unordered map" datatype can be used  (map<long long , int>)

  map<long long, int> mp;
  // // for the first for loop
  // // TC O(N*log(M)) where N is the length of the array,  M is the size of the map
  // /*The time complexity will be changed depending on which map data structure we are using.
  //  If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM).
  //  But in the worst case(which rarely happens), it will be nearly O(N2).*/

  // for(int i =0; i<len;i++){
  //     mp[arr[i]]++;                 // this creates a map with key being the elements of array and value of map will be the frequency of the element in the array
  // }

  // for(auto it:mp){                 // TC O(N/2 + 1) since every element appeared twice in array so no. of elements stored in the map will be N/2
  //     if(it.second == 1){
  //         cout << it.first << " has a frequency of 1";
  //     }
  // }
  // // Total TC of the code is O(N*log(M) + N/2 + 1)
  // // SC O(N/2 + 1)  used by the map.

  // Method 4
  // TC O(N)
  // SC O(1)
  // int xorr = 0;
  // for(int i = 0;i<len;i++){

  //     xorr = xorr^arr[i];
  // }
  // cout << xorr;

  // Longest subarray with given sum K(positives)

  // Method 1 (creating all possible  sub arrays and finding the require one)
  // TC O(N * N)

  // int arr[] = {1,2,3,1,1,1};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int k = 3;
  // int sum = 0;
  // int longest = 0;
  // for(int i = 0;i<len;i++){
  //     for(int j = i;j< len;j++){
  //         sum = arr[j] + sum;
  //     if(sum == k){
  //         longest = max(longest,j-i+1);
  //     }
  //     }
  //     sum = 0;
  // }
  // cout << "longest lenght of sub array " << longest;

  // Method 2 (hashing)(only for natural numbers)
  // TC O(N * log(N)) in case of map
  // TC O(N^2) in the worst case of the unordered map
  // SC O(N)

  // map <int, int> hash;
  // for(int i = 0;i<len;i++){
  //     sum = sum + arr[i];
  //     hash.insert({sum,i});
  //     if(sum == k){                            // checking if the subarray including the first element has sum k
  //         longest = max(longest,i+1);
  //     }
  //     int remaining = sum - k;
  //     if(hash.find(remaining) != hash.end()){                    // checking if the remaining portion of the array has the sum k
  //         longest = max(longest,(i - hash[remaining] ));
  //     }
  // }
  // cout << longest;
  
  // Method 3 (hashing)(for all integers)
  // TC O(N * log(N)) in case of map
  // TC O(N^2) in the worst case of the unordered map
  // SC O(N)
  // for(int i = 0;i<len;i++){
  //     sum = sum + arr[i];
  //     if(hash.find(sum) == hash.end()){     // if the sum previously exist in the map then do not update
  //         hash.insert({sum,i});
  //     }
  //     if(sum == k){                            // checking if the subarray including the first element has sum k
  //         longest = max(longest,i+1);
  //     }
  //     int remaining = sum - k;
  //     if(hash.find(remaining) != hash.end()){                    // checking if the remaining portion of the array has the sum k
  //         longest = max(longest,(i - hash[remaining] ));
  //     }
  // }
  // cout << longest;

  // Method 4 (most optimal approach if array only contains positive integers)
  // TC O(2N)  (The outer for loop runs for N times and the inner while loop can also run  N times (to reach the right pointer))
  // SC O(1)
  // int n = 0;           // (left pointer) it stores the index of the first element of the subarray
  // for(int i = 0 ; i< len ;i++){      // i is the right pointer
  //     sum = sum + arr[i];            // sum the elements of the array
  //     if(sum > k){                   // if the sum exceeds "k" then start removing the elements at the starting until sum is reached or sum becomes less than k.
  //         while(sum > k){
  //             sum = sum - arr[n];
  //             n++;
  //             if(sum == k){
  //                 longest = max(longest,i - n + 1);
  //             }
  //         }
  //     }
  //     else if(sum == k){
  //         longest = max(longest,i-n + 1);
  //     }
  // }
  // cout << longest;

  // 2 Sum problem (given - integer array , number; find 2 numbers from the array whose sum is equal to the number and also find their indexes)

  // Method 1 (checking all possible pairs)
  // TC O (N^2)
  // SC O(1)
  // int arr[] = {6,5,11,4,8};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int target = 14;             // the targeted value
  // int sum = 0;
  // for(int i = 0;i < len;i++){
  //     for(int j = i+1;j<len;j++){
  //         sum = arr[i] + arr[j];
  //         if(sum == target){
  //             cout << "target achieved, indexes are " << i << " " << j;
  //             cout << "\n" ;
  //         }
  //     }
  // }

  // Method 2  (Hashing)
  // TC O(N * log(N))  if we take map
  // TC O(N^2) in the worst case of unordered map
  // SC O(N)
  // map <int,int> mpp;
  // for(int i = 0;i<len;i++){            // Storing elements along with their index in the hashmap
  //     mpp[arr[i]] = i;                 // TC O(N * log(N))
  // }
  // for(int i = 0;i < len;i++){          // TC O(N * log(N))
  //     if(mpp.find(target - arr[i]) != mpp.end()){              // checking for a required  number in the map
  //         cout << "target achieved, indexes are " << i << " " ;
  //         cout << mpp[target - arr[i]];
  //         break;
  //     }
  // }

  // Method 3 (2 pointer approach) (only for finding if number exist not the indexes of number)
  // TC O(N^2 + N)    (can use merge sort to reduce TC for sorting to O(N*log(N)))
  // SC O(1)
  // for(int i = 0;i<len;i++){            // TC O(N^2)
  //     for(int j = 0;j<len-i-1;j++)
  //     if(arr[j]>arr[j+1]){
  //         swap(arr[j],arr[j+1]);
  //     }
  // }
  // int lp = 0;       // left pointer
  // int rp = len-1;   // right pointer
  // for(int i = 0;i<len;i++){
  //     if(arr[lp] + arr[rp] < target){
  //         lp++;
  //     }
  //     else if(arr[lp] + arr[rp] > target){
  //         rp--;
  //     }
  //     else {
  //         cout << "target achieved";
  //         cout << "\n" ;
  //     }
  //     if(lp == rp){
  //         break;
  //     }
  // }

  // Sort an array of 0's 1's and 2's

  // Method 1 (using the merge sort)
  // TC O(N*log(N))
  // SC O(N)

  // Method 2 (hashing)
  // TC O (2N)
  // SC O(3)
  // int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int index = 0;

  // int arr1[3] = {0};        // hash array
  // for(int i = 0;i < len;i++){            // TC O (N)
  //     arr1[arr[i]]++;
  // }
  // for(int i = 0;i<=2;i++){               // TC O (N)
  //     for(int j = 0;j < arr1[i];j++){
  //         arr[index] = i;
  //         index++;
  //     }
  // }

  // Method 3 (DNF Algorithm)
  // TC O(N)
  // SC O(3)
  // int low = 0,mid = 0,high=len-1;
  // while (mid <= high)
  // {
  //     if(arr[mid] == 0){
  //         swap(arr[low],arr[mid]);
  //         low++;
  //         mid++;
  //     }
  //     else if(arr[mid] == 1){
  //         mid++;
  //     }
  //     else {
  //         swap(arr[mid],arr[high]);
  //         high--;
  //     }
  // }

  // Majority Element (>n/2 times)

  // METHOD 1 (pikup an element and compare with all other elements to find the frequency)
  // TC O(N^2)
  // SC O(1)

  // int arr[] = {7,7,7,2,2,7,1,7,1};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int freq = 0;
  // for(int i = 0;i<len;i++){
  //     for(int j = 0; j < len ;j++){
  //         if(arr[i] == arr[j]){
  //             freq++;
  //         }
  //     }
  //     if(freq > len/2){
  //         cout << "Majority element is " << arr[i];
  //         break;
  //     }
  // }

  // Method 2  (hashing)
  // TC O(N*log(N) + N)
  // SC O(N)
  // map <int, int> hash;
  // for(int i = 0 ;i < len;i++){           // TC O(N*log(N))
  //     hash[arr[i]]++;
  // }
  // for(int i =0;i < hash.size();i++){       // TC O(N)
  //     if(hash[i] > len/2){
  //         cout << "Majority element is " << i;
  //     }
  // }

  // Method 3 (Moore's voting algorithm)
  // int cnt = 0;
  // int element;
  // for(int i = 0;i<len;i++){
  //     if( cnt == 0 ){
  //         cnt++;
  //         element = arr[i];
  //     }
  //     else if(arr[i] == element){
  //         cnt++;
  //     }
  //     else{
  //         cnt--;
  //     }
  // }
  // int cnt1 = 0;
  // for(int j = 0;j<len;j++){
  //     if(element == arr[j]){
  //         cnt1++;
  //     }
  // }
  // if(cnt1 > len/2){
  //     cout << element;
  // }

  // Maximum Subarray Sum

  // Method 1 (By finding the sum of all possible sub arrrays and then finding the max sum)
  // TC O(N^2)
  // int arr[] = {-2,-2,4,-1,-2,1,5,-3};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int sum = 0;
  // int msum = INT_MIN;

  // for(int i = 0;i < len;i++){
  //     for(int j = i;j<len;j++){
  //         sum += arr[j];
  //         msum = max(msum,sum);
  //     }
  //     sum = 0;
  // }
  // cout << msum;

  // Method 2 (Kadane's Algorithm )
  // TC O(N)
  // SC O(1)
  // for(int i = 0;i < len;i++){
  //     sum += arr[i];
  //     if(sum <= 0){
  //         sum = 0;
  //     }
  //     else if(sum > msum){
  //         msum = sum;
  //     }
  // }
  // if(msum < 0){
  //     cout << 0;
  // }
  // else cout << msum;

  //  Method 2 (modified to also find the subarray)
  // TC O(N)
  // SC O(1)
  // int ansstart = -1,ansend = -1;        // This will contain the atart and end index of the subarray
  // int start;
  // for(int i = 0;i < len;i++){
  //     sum += arr[i];
  //     if(sum <= 0){
  //         sum = 0;
  //         start = i;
  //     }
  //     else if(sum > msum){
  //         msum = sum;
  //         ansstart = start ;
  //         ansend = i;
  //     }
  // }
  // if(msum < 0){
  //     cout << 0;
  // }
  // else cout << msum;

  // Best Time to Buy and Sell Stock (buy and sell can't be done on the same day)

  // Method 1 (checking every possible value of profit)
  // TC O(N^2)

  // int arr[] =  {2,1,2,1,0,1,2};    // This array contains the stock price on all 6 days
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int buy , sell = 0;
  // int profit = 0;
  // int mprofit = 0;

  // for(int i = 0;i<len;i++){
  //     for(int j = i ;j< len;j++){
  //         profit = arr[j] - arr[i];
  //         if(profit > mprofit){
  //             mprofit = profit;
  //             buy = i;
  //             sell = j;
  //         }
  //     }
  // }
  // cout << buy << " " << sell;

  // Method 2
  // TC O(N)
  // buy = 0;
  // for(int i = 1;i < len;i++){
  //     profit = arr[i] - arr[buy];
  //     if(profit > mprofit){
  //         mprofit = profit;
  //         sell = i;
  //     }
  //     else if(profit <= 0){
  //         buy = i;
  //     }
  //     cout << profit << " " << buy << " " << sell << endl;
  // }
  // if(mprofit == 0){
  //     cout << "no stock bought";
  // }
  // else cout << buy << " " << sell << endl;
  // cout << mprofit;

  // Rearrange the array in alternating positive and negative items
  // (no. of positive terms is equal to the no. of negative terms)

  // Method 1 (store elements in separate arrays and combine them)
  // TC O(N + N/2)
  // SC O(N)
  // int arr[] = {3,1,8,-2,-4,-6,-9,7,-6,-3};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int p = 0,n = 0;
  // int pos[len/2] = {};
  // int neg[len/2] = {};

  // for(int i = 0;i < len ; i++){
  //     if(arr[i] >= 0){
  //         pos[p] = arr[i];
  //         p++;
  //     }
  //     else{
  //         neg[n] = arr[i];
  //         n++;
  //     }
  // }
  // for(int i = 0;i<len/2;i++){
  //     arr[2*i] = pos[i];
  //     arr[2*i+1] = neg[i];
  // }

  // Method 2      (create a new array and store the elements in it in the required order)
  // TC O(N)
  // SC O(N)
  // int arr1[len];
  // for(int i = 0;i<len;i++){
  //     if(arr[i] >= 0){
  //         arr1[2*p] = arr[i];
  //         p++;
  //     }
  //     else{
  //         arr1[2*n+1] = arr[i];
  //         n++;
  //     }
  // }

  //  Rearrange the array in alternating positive and negative items
  // (no. of positive terms is not equal to the no. of negative terms)
  // TC O(2N)
  // SC O(N)
  // int posi[len];
  // int negi[len];
  // for(int i = 0; i < len; i++)
  // {
  //     if(arr[i] > 0){
  //         posi[p] = arr[i];
  //         p++;
  //     }
  //     else {
  //         negi[n] = arr[i];
  //         n++;
  //     }
  // }
  // for(int i = 0;i < min(n,p);i++){
  //     arr[2*i] = posi[i];
  //     arr[2*i+1] = negi[i];
  // }
  // for(int i = 2*min(n,p) ;i < max(n,p)  ;i++){
  //     arr[i] = posi[i];
  // }

  // Next permutation

  // Method 1 (by Recursion)

  // int arr[] = {2,1,5,4,3};
  // int len = sizeof(arr)/sizeof(arr[0]);

  // Method 2 (by using the STL)
  // vector <int> A;
  // next_permutation(A.begin() , A.end());

  // Method 3
  // TC O(3N)
  // int ind = -1;
  // for(int i = len - 2;i >= 0;i--){               // Find the first decreasing element from the end:
  //     if(arr[i] < arr[i+1]){
  //         ind = i;                               // Break point
  //     }
  // }
  // if(ind == -1){                                 // If no breakpoint found then reverse the array and return it as the answer
  //     for(int i = 0;i<len/2;i++){
  //         swap(arr[i],arr[len-i-1]);
  //     }
  // }
  // else {
  //     for(int i = len - 1;i >= ind;i-- ){         // Find the element least greater than arr[ind] and then swap it.
  //         if(arr[i]>arr[ind]){
  //             swap(arr[i] , arr[ind]);
  //             break;
  //         }
  //     }
  //     for(int i = ind + 1; i < (len + ind)/2;i++ ){       // Swap the right half of the array (from ind + 1 to len -1).
  //         swap(arr[i],arr[len - ind -1 + i -1]);
  //     }
  // }

  // Leaders in an array (element in the array greater than all the elements in it's right)

  // Method 1 (iterating the array from the end and storing the max element int a separate array )
  // TC O(N)
  // SC O(N)
  // int arr[] = {10,22,12,3,0,6};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int arr1[len];
  // int j = 0;
  // int max = INT_MIN;
  // for(int i = len - 1;i >= 0;i--){
  //     if(arr[i] > max){                    // if the arr[i] is greater than max of right, then it will be a leader
  //         max = arr[i];
  //         arr1[j] = max;
  //         j++;
  //     }
  // }

  // Longest consecutive sequence
  // int arr[] = {102,4,100,101,102,1,101,3,3,3,5,2,1,1};
  // int len = sizeof(arr)/sizeof(arr[0]);
  // int cnt = 1;
  // int mcnt = 0;

  // Method 1 (pick an element and run a loop to find it's succesor in the array)
  // TC O(N^2)

  // Method 2
  // TC O(N*log(N) + N)
  // quicksort(arr , 0 , len-1);
  // for(int i = 0;i < len -1;i++){
  //     if(arr[i+1] - arr[i] == 1){           // checks if the next element is a successor or not
  //         cnt++;
  //     }
  //     else if(arr[i+1] != arr[i]){          // if next element is the same element or not a successor
  //         cnt = 1;                          // it start storing a new sequence
  //     }
  //     mcnt = max(cnt,mcnt);
  // }
  // cout << mcnt;

  // Method 3     (Store the element in an unordered set)
  // TC O(N) + O(N + N)    // if we take the best case of set O(1) for each set function
  // SC O(N)
  // unordered_set<int> uset;
  // for(int i = 0;i<len;i++){             // TC O(N)
  //     uset.insert(arr[i]);
  // }
  // TC O(N + N)
  // for(int i = 0;i<uset.size();i++){                   // Traverse the unordered set
  //     if(uset.find(arr[i] - 1) == uset.end()){        // Find the smallest element of any sequence
  //         int x = arr[i];
  //         while(uset.find(x+1) != uset.end()){        // Find the number of elements of the sequence starting from smallest element of the sequence
  //             cnt++;
  //             x++;                                    // incresing the element each time to find the next successor
  //         }
  //         mcnt = max(mcnt , cnt);
  //     }
  //     else {
  //         cnt = 1;
  //     }
  // }
  // cout << mcnt;

  //  Set Matrix Zeroes

  // int arr[4][4] = {{1,1,1,1},
  //                  {1,0,0,1},
  //                  {1,1,0,1},
  //                  {1,1,1,1}
  //                  };
  // int arr1[4][4] = {};
  // int arr[1][2] = {{1,0}};
  // int rows = sizeof(arr)/sizeof(arr[0]);
  // int colm = (sizeof(arr)/sizeof(arr[0][0]))/rows;

  // Method 1 (find the elements which will be converted to 0 and replace them by some other number(-1 in this case))
  // TC O((M*N)*(M*N) + M*N)  N and M are the rows and column of the matrix
  // for(int i = 0;i < rows;i++){                     // TC O((M*N)*(M*N))
  //     for(int j = 0;j < colm;j++){
  //         if(arr[i][j] == 0){
  //             for(int k = 0;k < rows;k++){
  //                 if(arr[k][j] == 0){
  //                     arr[k][j] = 0;
  //                 }
  //                 else {
  //                     arr[k][j] = -1;
  //                 }
  //             }
  //             for(int k = 0;k < colm;k++){
  //                 if(arr[i][k] == 0){
  //                     arr[i][k] = 0;
  //                 }
  //                 else{
  //                     arr[i][k] = -1;
  //                 }
  //             }
  //         }
  //     }
  // }
  // // TC O(M*N)
  // for(int i = 0;i < rows;i++){                   // Changing the -1 to 0  to get the required answer
  //     for(int j = 0;j < colm;j++){
  //         if(arr[i][j] == -1){
  //             arr[i][j] = 0;
  //         }
  //     }
  // }

  // Method 2   (mark the rows and column which contain a zero and then convert the whole row and column to zero)
  // TC O(N*M + N*M )
  // SC O(N + M)
  // int rowarr[rows] = {0};         // Store the rows which has a 0
  // int clmarr[colm] = {0};         // Store the columns which has a 0
  // for(int i = 0;i < rows;i++){           // Finding the rows and column with 0
  //     for(int j = 0;j < colm;j++){
  //         if(arr[i][j] == 0){
  //             rowarr[i] = 1;
  //             clmarr[j] = 1;
  //         }
  //     }
  // }
  // for(int i = 0;i < rows;i++){              // Converting the whole row and column to 0
  //     for(int j = 0;j < colm;j++){
  //         if(rowarr[i] == 1 || clmarr[j] == 1){
  //                 arr[i][j] = 0;
  //         }
  //     }
  // }

  // Mehtod 3 (Using the first row and column to marks thee presence of 0 in that row or column)
  // TC O(2*M*N)
  // SC O(1)
  // int col0 = 1;
  // for(int i = 0;i<rows;i++){      // if any element of first column is 0 then mark col0 as 0.
  //     if(arr[i][0] == 0){
  //         col0 = 0;
  //     }
  // }
  // for(int i = 0;i < rows;i++){    // marking the the first row and column as 0 if any element is found 0
  //   for(int j = 1;j < colm;j++){
  //     if(arr[i][j] == 0){
  //         arr[0][j] = 0;
  //         arr[i][0] = 0;
  //     }
  //   }
  // }
  // for(int i = 1;i < rows;i++){              // Converting the whole row and column to 0
  //     for(int j = 1;j < colm;j++){
  //         if(arr[i][j] != 0){
  //             // check for column and row
  //             if(arr[0][j] == 0 || arr[i][0] == 0){
  //                 arr[i][j] = 0;
  //             }
  //         }
  //     }
  // }
  // if(arr[0][0] == 0){
  //     for(int j = 0;j < colm;j++){
  //         arr[0][j] = 0;
  //     }
  // if(col0 == 0){
  //     for(int i = 0;i < rows;i++){
  //         arr[i][0] = 0;
  //     }
  // }

  // Rotate a matrix by 90 degree  (Also called as rotate image problem)
  // Given matrix is square matrix.

  // int matrix[4][4] = {{1,2,3,4},
  //                     {5,6,7,8},
  //                     {9,10,11,12},
  //                     {13,14,15,16}};
  // int rows = sizeof(matrix)/sizeof(matrix[0]);
  // int colm = (sizeof(matrix)/sizeof(matrix[0][0]))/rows;

  // Method 1 (Creating a new matrix and storing the elements in required order)
  //  TC O(N^2)
  //  SC O(N^2)
  //  int matrix1[4][4];
  //  for(int i = 0;i < rows;i++){
  //      for(int j = 0;j < colm;j++){
  //          matrix1[j][rows-1-i] = matrix[i][j];
  //      }
  //  }

  // Method 2
  // TC O((N^2)/2 + (N^2)/2)
  // for(int i = 0;i < rows;i++){                   // Transpose of the matrix . TC O((N/2)*N)
  //     for(int j = i;j < colm;j++){
  //         swap(matrix[i][j],matrix[j][i]);
  //     }
  // }
  // for(int j = 0;j < colm/2;j++){                 // Reversing each row of the matrix
  //     for(int i = 0;i < rows;i++){
  //         swap(matrix[i][j],matrix[i][colm-j-1]);
  //     }
  // }

  // Spiral Traversal of a Matrix

  // int matrix[6][6] = { {1, 2, 3, 4, 5, 6},
  // 	                 {20,21,22,23,24,7},
  // 	                 {19,32,33,34,25,8},
  //                      {18,31,36,35,26,9} ,
  //                      {17,30,29,28,27,10},
  //                      {16,15,14,13,12,11}
  //                     };
  // int matrix[5][4] =  {{1,2,3,4},
  //                      {5,6,7,8},
  //                      {9,10,11,12},
  //                      {13,14,15,16},
  //                      {17,18,19,20}};
  // int matrix[1][5] = {{1,2,3,4,5}};

  // int matrix[3][4] = {
  //     {1, 2, 3, 4},
  //     {5, 6, 7, 8},
  //     {9, 10, 11, 12},
  // };

  //   // Works everywhere

  //  int n = sizeof(matrix) / sizeof(matrix[0]); // Number of rows
  //  int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);

  // // Initialize the pointers reqd for traversal.
  // int top = 0, left = 0, bottom = n - 1, right = m - 1;

  // // Loop until all elements are not traversed.
  // while (top <= bottom && left <= right) {

  //   // For moving left to right
  //   for (int i = left; i <= right; i++)
  //    cout << (matrix[top][i]);

  //   top++;

  //   // For moving top to bottom.
  //   for (int i = top; i <= bottom; i++)
  //     cout << (matrix[i][right]);

  //   right--;

  //   // For moving right to left.
  //   if (top <= bottom) {
  //     for (int i = right; i >= left; i--)
  //      cout <<(matrix[bottom][i]);

  //     bottom--;
  //   }

  //   // For moving bottom to top.
  //   if (left <= right) {
  //     for (int i = bottom; i >= top; i--)
  //       cout <<(matrix[i][left]);

  //     left++;
  //   }
  // }

  // REQUIRE CORRECTION (WORKS ONLY FOR SQUARE MATRIX)
  // int i = 0,j = 0;
  // int rows = sizeof(matrix)/sizeof(matrix[0]);
  // int colm = (sizeof(matrix)/sizeof(matrix[0][0]))/rows;
  // for(i = 0;i < rows;i++){
  //     for(j = i ;j < colm - i;j++){          // left to right
  //         cout << matrix[i][j] << " ";
  //     }
  //     for(j = 1 + i;j < rows -1 -i; j++){         // top to bottom
  //         cout << matrix[j][colm - i - 1] << " ";
  //     }
  //     for(j = colm - i - 1 ; j > i ; j--){        // right to left
  //         cout << matrix[rows - i -1][j] << " ";
  //     }
  //     for(j = rows - 1 - i ; j >= i+1 ; j-- ){    // bottom to top
  //         cout << matrix[j][i] << " ";
  //     }
  // }

  // Count Subarray sum Equals K

  // int arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
  // int k = 3;
  // int len = sizeof(arr) / sizeof(arr[0]);
  // unordered_map<int, int> hash;
  // int sum = 0;
  // int count = 0;
  
  // Method 1    (Generate all the subarrays)
  // TC O(N^2)
  // for(int i = 0;i<len;i++){
  //   for(int j = i;j < len;j++){
  //     sum = arr[j] + sum;
  //     if(sum == k){
  //       count++;
  //     }
  //   }
  //   sum = 0;
  // }

  // Method 2 (Using a hashmap to store the prefix sum and their count) 
  // TC O(N*Log(N))
  // SC O(N)
  // hash = {{0,1}};
  // for (int i = 0; i < len; i++){
  //   sum = sum + arr[i];                 // Adding the elements to find sum
  //   count = count + hash[sum-k];        // Adding the number of prefix sum having the value sum - k
                                           // No. of sum - k will be equal to the number of subarrays with the sum k
  //   hash[sum]++;                        // updating the prefix sum , it will help us to check how many times a particular value of sum appeared
  // }
  // cout << count;













  // for(int i = 0;i < rows;i++){
  //     for(int j = 0;j < colm;j++){
  //         cout << arr[i][j] << " ";
  //     }
  //     cout << endl;
  // }

  // for(int i = 0;i < len;i++){
  //     cout << arr[i] << " ";
  // }

  // for (auto it : inter)
  // {
  //     cout << it;
  //     cout << " ";
  // }
  
  
  
  return 0;
}