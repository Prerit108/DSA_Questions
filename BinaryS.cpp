#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarysearch(vector<int> &vec, int t,int low,int high){
    int ans;
    if(low > high)
    return -1;
    int mid = (high+low)/2;
    if(vec[mid] == t){
        ans = mid;
        return mid;
    }
    else if(vec[mid] > t){
        binarysearch(vec, t,low,mid-1);
    }
    else{
        binarysearch(vec, t,mid+1,high);
    }

}

int singleeleinarr(vector<int>& nums){
    int ans;
    int low = 0;
    int n = nums.size();
    int high = nums.size() - 1;
    int mid;
    if(nums.size() == 1){      
        ans = nums[0]; 
        return ans;
    }
    if(nums[0] != nums[1]){          // checking if the first element is the single element
            low++;
            return nums[0];
        }
    else if(nums[n-1] != nums[n-2]){     // checking if the last element is the single element
            high--;
            return nums[n-1];
        }
    while(low <= high){
        mid = low + (high - low)/2;

        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid - 1]){       // checking if mid is the single element
            ans = nums[mid];
            return ans;
        }
        else if((nums[mid] == nums[mid-1]  && mid%2 == 1) || (nums[mid] == nums[mid+1]  && mid%2 == 0)){
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    return ans;
}

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int ans = -1;
    int low = 0;
    int high = n-1;
    int mid;
    if(n == 1){            // if array has only one element return that element
        return 0;
    }
    // Reducing the edge cases

    // if first element is greater than the 2nd element, then it's a peak element
    if(nums[low] > nums[low+1]){      
        return low;
    }
    // if the last element is greater the second last then, it is the peak 
    else if (nums[high] > nums[high - 1]){
        return high;
    }
    // Since edge case are taken we will change the value of low and high by 1
    low++;
    high++;
    while(low <= high){
        mid = (low + high)/2;
        if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
            return mid;
        } 
        else if(nums[mid] < nums[mid+1] ){      // It tell us that left half is sorted 
            low = mid + 1;                      // Skipping left half
        }
        else {                                  // It tell us that elements on right half are in decreasing order  
            high = mid - 1;
        }
    }
    return ans;
}

int floorSqrt(int n) {
    // Considering n as a array of numbers from 1 to n , considering 1 as low and n as high .
    // Applying the binary search in this imaginary aray n will give the square root.
    int low = 1;
    int high = n;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if( mid*mid == n){     // if mid is a perfect square
            return mid;
        }
        else if(mid*mid > n){     // if mid^2 is greater than the n, eliminate the right half 
            high = mid - 1;
        }
        else {                    // if mid^2 is less than the n, eliminate the left half 
            low = mid + 1;
        }
    }
    if(mid*mid > n){              // rechecking the value of mid.
        return mid - 1;
    }
    return mid;
}

//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;     // If any power of the mid surpasses m then break the loop and return 2
    }
    if (ans == m) return 1;        // If mid^n is equals to m return 1
    return 0;                      // else case
}
// TC O(N log base 2 (M))
int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
// TC O(N log base 2 (M))
int nthRoot(int n, int m) {
    // Considering m as a array of numbers from 1 to m , considering 1 as low and m as high .
    // Applying the binary search in this imaginary aray m will give the nth root.
    int low = 1;
    int high = m;
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        
        // If the mid^n is equal to m then mid is nth root of m.
        // Can use any method to find mid^2, preffered is the exponential method.
        if(pow(mid,n) == m){    
            return mid;
        }
        else if(pow(mid,n) < m){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;                // if nth root is not integer then return -1.
}


int minEatingSpeed(vector<int>& piles, int h) {
    sort(piles.begin(),piles.end());              // Has no use in actual code, done only to find the max element in the array
    int high = piles[piles.size() - 1];           // max value of speed
    int low = 1;                                  // least value of speed
    int ans;                                       
    long long hr = 0;                             // total hours
    while(low <= high){                           
        hr = 0;                                   
        int mid = low + (high-low)/2;       
        for(int i = 0;i < piles.size();i++){                 // calculating the total hours taken
            hr = hr + (mid + piles[i] -1)/mid;               // ceil(piles[i]/(float)mid);
        }
        if(hr <= h){                             // if hours taken are less than the required hours 
            ans = mid;                // answer can be the mid value but we have to continue the search to find required speed
            high = mid - 1;           // eliminate the right half
        } 
        else {
            low = mid + 1;            // if time taken is more than the given time than eliminate the left half
        }
    }
    return ans; 
}

int main(){
    

    // Binary Search
    // TC O(log base 2 (N))
    // vector <int> nums = {0,3,5,9,12};
    // int target = 9;
    // int low = 0;
    // int high = nums.size() - 1;
    // int a = binarysearch(nums,target,low,high);
    // int mid;
    // int ans;
    // while(low <= high){
    //     mid = (high + low)/2;
    //     if(nums[mid] == target){
    //         ans = mid;
    //         break;
    //     }
    //     else if(nums[mid] > target){
    //         high = mid - 1;
    //     }
    //     else{
    //         low = mid + 1;
    //     }
    //     ans = -1;
    // }
    // cout << binarysearch(nums,target,0,nums.size()-1);

    // Lower Bound 
    
    // vector<int> arr = {1,2,3,3,7,8,9,9,9,11};
    // int arr1[] = {1,2,3,3,7,8,9,9,9,11};
    // int n = 7;
    
    // Method 1 (By comparing elements)(Using the binary search for less TC)
    // TC O( log base 2 (N))
    // int low = 0;
    // int high = arr.size()-1;
    // int mid ;
    // int  ans = arr.size();      // If there no element greater than n .
    // while(low <= high){
    //     mid = low + (high - low)/2;
    //     if(arr[mid] >= n){            // If element greater equal to n 
    //         high = mid - 1;           // Shrinking the array 
    //         ans = mid;                // It might be the answer 
    //     } 
    //     else {
    //         low = mid + 1;
    //     }
    // }
    // cout << ans;

    // Method 2 (Inbuilt func)
    // auto lb = lower_bound(arr.begin(),arr.end(),n) - arr.begin();
    // auto ind = lower_bound(arr1 + 2,arr1 + 6,n) - arr1;           // To search in the specific part of the array
    // auto ind = lower_bound(arr1 ,arr1 + arr.size(),n) - arr1;     // to tranverse the whole array
    // cout << ind;

    // Upper bound
    
    // vector<int> arr = {1,2,3,3,7,8,9,9,9,11};
    // int n = 7;

    // Method 1
    // int low = 0;
    // int high = arr.size()-1;
    // int mid ;             
    // int  ans = arr.size();      // If there no element greater than n .
    // while(low <= high){
    //     mid = low + (high-low)/2;
    //     if(arr[mid] > n){
    //         high = mid - 1;
    //         ans = mid;
    //     }
    //     else {
    //         low = mid + 1;
    //     }
    // }
    // cout << ans;

    // Method 2 (STL)
    // auto it = upper_bound(arr.begin(),arr.end(),n);

    // Search Insert Position
    // Exact same code as of lower bound

    // Ceil and Floor

    vector<int> a;
    //  int n;  // Size of array
    //  int x;  // Number to compare

    // int low = 0;
    // int high = n-1;
    // int mid ;
    // int flr = -1;
    // int ceil = -1;
    // pair <int,int> ans;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(a[mid] <= x){
    //         flr = a[mid];
    //         low = mid +1;
    //     }
    //     else {
    //         high = mid - 1;
    //     }
    // }
    //  low = 0;
    // high = n-1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(a[mid] >= x){
    //         ceil = a[mid];
    //         high = mid - 1;
    //     }
    //     else {
    //         low = mid +1;
    //     }
    // }
    // ans = {flr,ceil};

    // Find the first or last occurrence of a given number in a sorted array

    // vector<int> nums = {5,7,7,8,8,10}; 
    // int target = 8;

    // Mehtod 1 (Linear Searching)
    // int first = -1;
    // int last = -1;
    // vector<int> temp;           //It is the final answer array
    // for(int i = 0;i < nums.size(); i++){
    //     if(nums[i] == target){
    //         if(first == -1)  first = i;
    //         last = i;
    //     } 
    // }
    // temp.push_back(first);
    // temp.push_back(last);
   
    // Method 2 
    // TC O(2*log base 2 (N))
    // SC O(1 )
    // vector<int> ans;
    // int low = 0;
    // int high = nums.size() - 1;
    // int mid ;
    // int first = -1;
    // int last = -1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(nums[mid] >= target){
    //         high = mid - 1;
    //         if(nums[mid] == target){
    //         first = mid;
    //         }
    //     }
    //     else low = mid + 1;
    // }
    // low = 0;
    // high = nums.size() - 1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(nums[mid] <= target){
    //         low = mid + 1;
    //         if(nums[mid] == target){
    //         last = mid;}
    //     }
    //     else high = mid -1;
    // }
    // ans.push_back(first);
    // ans.push_back(last);
   
    // 	Count occurrences of a number in a sorted array with duplicates
    
    // vector<int> nums = {5,7,7,8,8,10}; 
    // int target = 8;
    // int ans;
    // int low = 0;
    // int high = nums.size() - 1;
    // int mid ;
    // int first = -1;
    // int last = -1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(nums[mid] >= target){
    //         high = mid - 1;
    //         if(nums[mid] == target){
    //         first = mid;
    //         }
    //     }
    //     else low = mid + 1;
    // }
    // low = 0;
    // high = nums.size() - 1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(nums[mid] <= target){
    //         low = mid + 1;
    //         if(nums[mid] == target){
    //         last = mid;}
    //     }
    //     else high = mid -1;
    // }
    // if(first == -1 && last == -1){
    //     ans = 0;
    // }
    // else ans = last - first +1;
    
    // Search Element in Rotated Sorted Array - I  (without duplicates)

    // vector <int> nums;
    // int target;
    // Method 1 (Linear search)

    // Method 2 (Binary search)
    // TC O(log base 2 (N))
    // int low = 0;
    // int high = nums.size() - 1;
    // int mid;
    // int ans = -1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(nums[mid] == target){
    //         ans = mid;
    //     }
    //     // Left Sorted
    //     if(nums[mid] >= nums[low]){
    //         if(nums[mid] >= target && target >= nums[low]){
    //             high = mid - 1;
    //         }
    //         else {
    //             low = mid + 1;
    //         }
    //     }
    //  // Right sorted
    //     else{
    //         if(nums[mid] <= target && target <= nums[high]){
    //             low = mid + 1;
    //         }
    //         else {
    //             high = mid - 1;
    //         }
    //     }
    // }

    // Search Element in Rotated Sorted Array II  (with duplicates)

    // vector <int> nums;
    // int target;

    // TC O(N/2)
    // int low = 0;
    // int high = nums.size() - 1;
    // int mid;
    // int ans = -1;
    // while(low <= high){
    //     mid = (low + high)/2;
    //     if(nums[mid] == target){
    //         ans = mid;
    //     }
    //     if(nums[mid] == nums[low]  ){
    //         low++;
    //         continue;
    //     }
    //     else if(nums[mid] == nums[high]){
    //          high--;
    //         continue;
    //     }
    //     // Left Sorted
    //     if(nums[mid] >= nums[low]){
    //         if(nums[mid] >= target && target >= nums[low]){
    //             high = mid - 1;
    //         }
    //         else {
    //             low = mid + 1;
    //         }
    //     }
    // // Right sorted
    //     else{
    //         if(nums[mid] <= target && target <= nums[high]){
    //             low = mid + 1;
    //         }
    //         else {
    //             high = mid - 1;
    //         }
    //     }
    // }
    // if(ans == -1)
    // return false;
    // else return true;

    // 	Find minimum in Rotated Sorted Array
    // TC O(log base 2 (N))
    // vector<int> nums ;
    // int low = 0;
    // int high = nums.size() - 1;
    // int mid;
    // int ans = INT_MAX;
    // while(low <= high){
    //     mid = (low+high)/2;
    //     ans = min(ans,nums[mid]);
    //     if(nums[mid] >= nums[low] && nums[mid] >= nums[high]){      // By observation we can say that 
    //             low = mid + 1;
    //     } 
    //     else {
    //         high = mid - 1;
    //     }
    // }

    // Find the index at which array is rotated

    // vector<int> nums ;
    // int low = 0;
    // int high = nums.size() - 1;
    // int mid;
    // int ans = INT_MAX;
    // int ind;
    // while(low <= high){
    //     mid = (low+high)/2;
    //     if(nums[mid] < ans){
    //         ans = nums[mid];
    //         ind = mid;
    //     }
    //     if(nums[mid] >= nums[low] && nums[mid] >= nums[high]){
    //             low = mid + 1;
    //     }
    //     else {
    //         high = mid - 1;
    //     }
    // }
    
    // Single Element in Sorted Array
    // vector<int> nums = {1,1,2,3,3,4,4,8,8};
    // int ans;

    // Method 1 
    // int n = nums.size();
    // for(int i = 0;i < n - 1;i++){
    //     if(nums[i] == nums[i+1]){     // check if current element is equal to next element
    //         i++;                      // moving i by one so that we can compare next pair of same elements in the next loop.
    //     }
    //     else{                         // It will show the singlew element
    //         ans = nums[i];            
    //         break;
    //     }
    // }
    // cout << ans;

    // Mehtod 2(Binary search)
    // TC O(log base 2 (N))

    // cout << singleeleinarr(nums);

    // Find the peak element

    // vector<int> nums = {1,5,1,2,1};
    // int ans;
    // int  n = nums.size();

    // Method 1
    // TC O(N)
    // SC O(1)
    // for(int i = 0; i < n;i++){
    //     if((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i] > nums[i+1])){
    //         ans = i;
    //         return ans;
    //     }
    // }
    // return ans;

    // Method 2 (Binary search)
    // TC O(log base 2 (N))
    // cout << findPeakElement(nums);

    // Find square root of a number in log n

    // int n = 90;

    // Method 1 (Linear search)
    // TC( Square root(N))
    // int ans; 
    // for(int i = 0;i*i <= n; i++){
    //     ans = i;
    // }
    // cout << ans;
 
    // Method 2 (Binary search)
    // TC O(log base 2 (N))
    // cout << floorSqrt(n);

    // Find nth root of m

    // Method 1 (Binary search concept)
    // TC O(N log base 2 (M))
    // int n = 2;
    // int m = 9;
    // cout << nthRoot(n,m);
    // cout << NthRoot(n,m);

    // KOKO eating bananas

    // Method 1(Not useful , Give time limit exceeded error)
    // TC O(max(piles) * N)
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int k = 1;
    //     long long hr = 0;
    //     while(hr != h){
    //         hr = 0;
    //         for(int i = 0;i < piles.size();i++){
    //             hr += ceil(piles[i]/(float)k);
    //             if(hr > h){
    //                 break;
    //             }
    //         }
    //         if(hr <= h){
    //             return k;
    //         }
    //         k++;
    //     }
    //     return k;
    // }

    // Method 2 (Using Binary search on answers)
    // vector <int> arr = {3,6,7,11};
    // int h = 8;
    // cout << minEatingSpeed(arr,h);


    
    
    






    return 0; 
}