#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 2;i<=n;i++){
        fact = fact*i;
    }
    return fact;
}
long long NCR(int n , int r){
    long long ncr = 1;
    for(int i = 0;i <  r;i++){
        ncr = ncr*(n-i);
        ncr = ncr/(i+1);
    }
    return ncr;
}

int f(int arr[] , int low ,int high){
    int pindex = low;
    int i = low;
    int j = high;
    while(i<j){
        while(i < high && arr[i] <= arr[pindex]){
            i++;
        }
        while(j > low && arr[j] > arr[pindex]){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;

}


int merge(vector<int> &arr ,int low,int mid ,int high){       // Pass by reference to avoid duplications
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] > arr[right]){               // Dont not use >= as it will count equal numbers also
            temp.push_back(arr[right]);
            cnt = cnt + mid - left + 1;
            right++;
        } 
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }  
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high;i++){  // IMPORTANT
        arr[i] = temp[i-low];
    }
    return cnt;
}
int mergesort(vector<int> &arr,int low,int high){
    int cnt = 0;
    if(low >= high){
        return cnt;
    }
    int mid = (low + high)/2;
    cnt += mergesort(arr,low,mid);        // cnt and add pair of each branch
    cnt += mergesort(arr,mid+1,high);     // cnt and add pair of each branch
    cnt += merge(arr,low,mid,high);       
    return cnt;
}


void quicksort(int arr[],int low,int high){
    if(low<high){
        int pindex = f(arr,low,high);
        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
    }
}

// int merje(vector <int> &arr,int low,int mid,int high){
//     int cnt = 0;
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;
//     while(left <= mid && right <= high){
//         if(arr[left] > arr[right]){
//             temp.push_back(arr[right]);
//             if(arr[left] > 2*arr[right]){
//                 cnt = cnt +  mid - left + 1;
//             }
//             right++;
//         }
//         else{
//             temp.push_back(arr[left]);
//             left++;
//         }
//     }
//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i = low;i<=high;i++){
//         arr[i] = temp[i-low];
//     }
//     return cnt;
// }

int merje(vector <int> &arr,int low,int mid,int high){
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){            // Comparison to be done before the actual merging 
                                                    // As merging changes the original array
        if(arr[left] > (long long)2*arr[right]){
            cnt += mid - left + 1;
            right++;
        }
        else { 
            left++;
        }
    }
     left = low;
     right = mid + 1;

    
    while(left <= mid && right <= high){
        if(arr[left] > arr[right]){
            temp.push_back(arr[right]);
            right++;
        }
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int rp(vector<int> &arr,int low,int high){
    int cnt = 0;
    if(low >= high){
        return cnt;
    }
    int mid = (low + high)/2;
    cnt += rp(arr,low,mid);
    cnt += rp(arr,mid+1,high);
    cnt += merje(arr,low,mid,high); 
    return cnt;
}
int main(){

    // Pascal's triangle
    //                       rows
    //        1               1  
    //       1 1              2
    //      1 2 1             3
    //     1 3 3 1            4
    //    1 4 6 4 1           5
    //   1 5 10 10 5 1        6
    //   1 2  3 4  5 6     <- columns
    
    // Q 1. Print the element on the given row and column number.
    
    // int row = 5;
    // int colm = 3;
    // int num ;
    // Method 1
    // TC O(N!) + O((N-1)!)....
    // num = factorial(row-1)/(factorial(colm -1)*factorial((row-1)-(colm-1)));
    // cout << num;

    // Method 2
    // TC O(R)  (R is the number of columns)
    // SC O(1)
    // num = NCR(row - 1,colm - 1);
    // cout << num;
    
    // Q 2. Print the row of a pascal's triangle.
    // int ele = 1;

    // Method 1
    // TC O(N*R)   (R is the number of columns , N is the numbers of rows)
    // for(int i = 1;i <= row;i++){
    //    cout << NCR(row -1 , i -1) << " ";
    // }
    
    // Method 2
    // TC O(N) (N is the number of rows)
    // for(int i = 1;i <= row;i++){
    //     cout << ele << " ";
    //     ele = ele*(row-i);
    //     ele = ele/(i);
    // } 

    // Q 3. Print the pascal;s triangle
    
    // Method 1  (by using the nCr formula)
    // Very huge TC 
    // for(int i = 1;i<=row;i++){
    //     for(int j = 1;j<=i;j++){
    //         num = factorial(i-1)/(factorial(j-1)*factorial(i-j));
    //         cout << num;
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    // Method 2
    // TC O(N^3)
    // vector<vector<long long>> ans ;
    // vector<long long> temp;
    // for(int i = 1;i<=row;i++){
    //     for(int j = 1;j<=i;j++){
    //         temp.push_back(NCR(row-1,colm-1));
    //     }
    //     ans.push_back(temp);
    // }

    // Method 3
    // TC O(N^2)
    // int ans = 1;
    // vector<int> a ;
    // vector<vector<int>> b;
    //     for(int i = 0;i < row;i++){
    //         for(int j = 0;j <= i;j++){
    //             cout << ans << " ";
    //             a.push_back(ans);
    //             ans = ans*(i-j);
    //             ans = ans/(j+1);
    //         }
    //         b.push_back(a);
    //         a.clear();
    //         cout << endl;
    //         ans = 1;
    //     }
    
    // for(int i = 0;i < 5;i++){
    //     for(int j = 0;j <= i ;j++){
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // Majority element 2 (>n/3)
    
    // int arr[] = {2,2};
    // int len = sizeof(arr)/sizeof(arr[0]);
    // int cnt = 0;
    // list <int> ls;

    // Method 1 (using loops to find the frequency of all the elements)
    // TC O(N^2)
    // SC (1)  (Required to store majority elements in the list)
    // for(int i = 0;i<len;i++){
    // cnt = 0;
    // if(ls.size() == 0 || *(ls.begin()) != arr[i]){
    //     for(int j = 0;j<len;j++){                    // Prevents taking same element again 
    //         if(arr[j] == arr[i]){
    //             cnt++; 
    //         }
    //     }
    //     if(cnt > len/3 ){
    //         ls.push_back(arr[i]);
    //         if(ls.size() == 2){
    //             break;
    //         }
    //     }
    // }         
    // }

    // Method 2 (Hashing)
    // TC O(N*log(N))
    // SC O(N)
    // code 1
    // map <int,int> mp ;
    // for(int i = 0;i < len;i++){
    //     mp[arr[i]]++;
    //     if(mp[arr[i]] > len/3){
    //         if(ls.size() == 0 || *(ls.begin()) != arr[i]){
    //             ls.push_back(arr[i]);
    //             if(ls.size() == 2){
    //                 break;
    //             }
    //         }
    //     }
    // } 
    // // code 2
    // for(int i = 0;i < len;i++){
    //     mp[arr[i]]++;
    //     if(mp[arr[i]] == len/3 + 1){   
    //         ls.push_back(arr[i]);
    //         if(ls.size() == 2){
    //             break;  
    //         }
    //     }
    // } 

    // Method 3 (Extended Boyer Moore’s Voting Algorithm)
    // vector <int> nums = {3,2,3};
    // vector <int> vec;
    // int cnt1 = 0,cnt2 = 0;
    // int ele1 = INT_MIN , ele2 = INT_MIN;
    // for(int i = 0;i < nums.size();i++){
    //     if(cnt1 == 0 && ele2 != nums[i]){           // Picking the element different from the 2nd element
    //         ele1 = nums[i];
    //         cnt1 = 1;
    //     }
    //     else if(cnt2 == 0 && ele1 != nums[i]){      // Picking the element different from the 2nd element
    //         ele2 = nums[i];
    //         cnt2 = 1;
    //     }
    //     else if(ele1 == nums[i]){                   // adding to count if found the same element
    //         cnt1++;
    //     }
    //     else if(ele2 == nums[i]){                    // adding to count if found the same element
    //         cnt2++;
    //     }
    //     else{                                        // subtracting from count if found different element
    //         cnt1--; 
    //         cnt2--;
    //     }
    // cnt1 = 0;
    // cnt2 = 0;
    // // Verifying the majority elements by calculating the sum
    // for(int i = 0;i < nums.size();i++){
    //     if(ele1 == nums[i]){
    //         cnt1++;
    //     }
    //     if(ele2 == nums[i]){
    //         cnt2++;
    //     }
    // }
    // for(int i = 0;i<vec.size();i++){
    //     if(ele1 == nums[i]){
    //         cnt1++;
    //     }
    //     if(ele2 == nums[i]){
    //         cnt2++;
    //     }
    // }
    // if(cnt1 > nums.size()/3){
    //     vec.push_back(ele1);
    // }
    // if(cnt2 > nums.size()/3){
    //     vec.push_back(ele2);        
    // }

    // 3Sum problem

    // vector <int> arr ={-2,-2,-2,-1,-1,0,0,0,2,1,1}; // {-4,-1,0,1,2}
   
    // Method 1 (3 pointer method )(set aur vector ka jhol hai isme )
    // TC O(N^3 * log(no. of unique triplets))
    // SC O(No. of triplets)
    //  set<vector <int>> vec;                         // Set of vector
    // sort(arr.begin(),arr.end());
    // for(int lp = 0;lp<arr.size();lp++){
    //     for(int mp =lp + 1;mp<arr.size();mp++){   
    //         for(int rp = mp+1;rp < arr.size();rp++){
    //             if(arr[lp] + arr[mp] + arr[rp] == 0 ){
    //                 vector<int> temp = {arr[lp],arr[mp],arr[rp]};
    //                 sort(temp.begin(),temp.end());
    //                 vec.insert(temp);      
    //             }
    //         }
    //     }
    // }
    // vector <vector<int>> ans(vec.begin(),vec.end());
    
    // Method 2 (Hashing) 
    // TC O(N^2 * log(Size of set))   (N^2 * 1 in te case of unordered set)
    // SC O(N) + O(Set of unique triplets)
//    set <vector <int>> vec;         
//     set <int> hash;
//     int rp, lp  , mp;
//     for(lp = 0;lp < arr.size();lp++){
//         for( rp = lp+1;rp < arr.size();rp++){
//             int rem = 0-(arr[lp] + arr[rp]);            // rem is the third element of the triplet
//             if(hash.find(rem) != hash.end()){
//                 vector <int> temp = {arr[lp],rem,arr[rp]};        
//                 sort(temp.begin(),temp.end());                 // sort temp vector 
//                 vec.insert(temp);                              // stores the unique sorted temp vector (removes the duplicates)
//             }
//              hash.insert(arr[rp]);                      // The element before the element pointed by the right pointer is added to the hash set (it is done to prevent duplicates)   
//                                                         // The elements between the right pointer and left pointer will be included in the hash set and then the rem is chosen from the hash set.   
//         }
//         hash.clear();
//     }   
//     vector <vector<int>> ans(vec.begin(),vec.end());  // A way to insert a set of vector into a vector of vector
    
    // Method 3 (2 Pointer approach)
    // TC O(N*log(N) + N^2)
    // SC 0(NO. OF unique triplets)
    // sort(arr.begin(),arr.end());
    // vector<vector<int>> ans;
    // for(int lp = 0;lp<arr.size();lp++){
    //     if(lp > 0 && arr[lp] == arr[lp-1]) continue;
    //     int mp = lp + 1;
    //     int rp = arr.size() - 1;
    //     while(mp < rp){
    //         int sum = arr[lp]+arr[mp]+arr[rp];
    //          if(sum < 0){              
    //             mp++;
    //         }
    //         else if( sum > 0){
    //             rp--; 
    //         }
    //         else{
    //             ans.push_back({arr[lp],arr[mp],arr[rp]});  
    //             while (mp < rp && arr[mp] == arr[mp+1]){
    //                 mp++;
    //             }
    //             while (mp < rp && arr[rp] == arr[rp-1]){
    //                 rp--;
    //             }
    //             rp--;
    //             mp++;
    //         }
    //     }
    // }
    
    // 4Sum problem

    // vector<int> nums = {2,2,2,2,2};

    // Method 1 (finding all possible combinations)
    // TC O(N^4 * log(No. of unique quads))
    // SC O(No. of quads *2)   (space taken ans and vec)
    // int target = 0;
    // set<vector<int>> vec;
    // for(int i = 0;i < nums.size() ;i++){
    //     for(int j = i+1;j < nums.size() ;j++){
    //         for(int k = j+1;k < nums.size() ;k++){
    //             for(int l = k+1;l < nums.size() ;l++){
    //                 long long sum = nums[i]+nums[j];
    //                 sum += nums[k] ;
    //                 sum += nums[l] ;
    //                 if(sum == target){
    //                     vector<int> temp ={nums[i],nums[j],nums[k],nums[l]};
    //                     sort(temp.begin(),temp.end());
    //                     vec.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    // }
    // vector <vector<int>> ans(vec.begin(),vec.end());
    
    // Method 2 (Hashing) 
    // TC O(N^3 * log(size of set))
    // SC O(2*No. of quads) + O(N)   (N for hash set)
    // int target = 0;
    // set<vector<int>> vec;
    // set<int> hash;
    // for(int p1 = 0;p1<nums.size()-3;p1++){
    //     for(int p2 = p1+1;p2 < nums.size()-2;p2++){
    //         for(int p3 = p2+1;p3<nums.size();p3++){
    //             int rem = target - (nums[p1]+nums[p2]+nums[p3]);
    //             if(hash.find(rem) != hash.end()){
    //                 vector<int> temp = {nums[p1],nums[p2],rem,nums[p3]};
    //                 sort(temp.begin(),temp.end());
    //                 vec.insert(temp);
    //             }
    //             hash.insert(nums[p3]);
    //         }
    //         hash.clear();
    //     }
    // }
    // vector<vector<int>> ans(vec.begin(),vec.end());

    // Method 3 (2 pointer approach)
    // TC O(N^3 + N*log(N))
    // SC O(No. of unique quads)    (To return the answer)
    // int target = 8;
    // set<vector<int>> vec;
    // set<int> hash;
    // vector<vector<int>> ans;
    // sort(nums.begin(),nums.end()); 
    // for(int p1 = 0;p1<nums.size();p1++){
    //     if(p1 > 0 && nums[p1] == nums[p1-1]) continue;
    //     for(int p2 = p1+1;p2 < nums.size();p2++){
    //         if(p2 > p1+1 && nums[p2] == nums[p2-1]) continue;
    //         int p3 = p2+1;
    //         int p4 = nums.size() - 1;
    //         while(p3 < p4){
    //            long long sum = nums[p1]+nums[p2];
    //             sum += nums[p3] ;
    //             sum += nums[p4];
    //             if( sum == target){
    //                 ans.push_back({nums[p1],nums[p2],nums[p3] , nums[p4]});
    //                 while(p4 > p3 && nums[p3+1] == nums[p3]) p3++;
    //                 while(p4 > p3 && nums[p4-1] == nums[p4]) p4--;
    //                 p3++;
    //                 p4--;}
    //             else if(sum < target){
    //                 p3++;
    //             }
    //             else if( sum > target){
    //                 p4--;
    //             }
    //         }
    //     }
    // }

    // Largest Subarray with 0 Sum

    // vector <int> arr = {15,-2, 2, -8, 1, 7, 10, 23};
    
    // Method 1 (trying all possible subarray)
    // TC O(N^2)
    // int sum = 0;
    // int len = 0;
    // int mlen = 0;
    // for(int i = 0;i < arr.size();i++){
    //     for(int j = i;j < arr.size();j++){
    //         sum += arr[j];
    //         len++;
    //         if(sum == 0){
    //         mlen = max(mlen,len);
    //         }
    //     }
    //     len = 0;
    //     sum = 0;
    // }
    // cout << mlen;

    // Method 2
    // int sum = 0;
    // int mlen = 0;
    // map<int,int> hash;
    // for(int i = 0;i<arr.size();i++){
    //     sum += arr[i];
    //     if(hash.find(sum) == hash.end()){      // Do not update the value of sum if value reapperas
    //         hash[sum] = i;
    //     }
    //     if(sum == 0){                         // If the sum is 0 store its length
    //         mlen = max(i+1,mlen);
    //     }
    //     else if(hash.find(sum) != hash.end()){          // Checking if net sum of 0 can be attained by removing certain sum from the array starting from i = 0 
    //                                                     // If the that sum is present in the hash array then find the length of the sub array starting after it
    //         mlen = max(mlen,i-hash[sum]);
    //     }
    // }
    // cout << mlen;
    
    // Count number of subarrays with given XOR K
       
    // vector<int> arr ={4,2,2,6,4};

    // Mehtod 1 (Checking all the possible subarrays)
    // TC O(N^2)
    // int k = 6;
    // int cnt = 0;   
    // for(int i = 0;i<arr.size();i++){
    //     int xorr = 0;
    //     for(int j = i;j < arr.size();j++){
    //         xorr = xorr^arr[j];
    //         if(xorr == k){
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt;
    
    // Method 2
    // TC O(N*log(N))
    // SC O(N)
    // int xorr = 0;
    // int k = 6;
    // int cnt = 0;
    // map<int,int> hash  = {{0,1}};           // Hash map will store front xor and count
    // for(int  i = 0;i < arr.size();i++){
    //     xorr = xorr^arr[i];
    //     hash[xorr]++;
    //     if(hash.find(xorr^k) != hash.end()){
    //         cnt = cnt + hash[xorr^k];
    //     }      
    // }
    // cout << cnt;

    // Merge Overlapping Intervals

    // Method 1 (sort the vector of vector and then compare last element of vector to first element of the next vector)
    // TC O(N + N*log(N))
    // SC O(N)
    // vector<vector<int>> intervals {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    // vector<vector<int>> intervals = {{1,4},{0,1}};
    // int j = 0;
    // sort(intervals.begin(),intervals.end());
    // vector<vector<int>> vec = {intervals[0]};
    //     for(int i = 1;i < intervals.size();i++){
    //     if(intervals[i][0] <= vec[j][1] ){
    //         vec[j][1] = max(intervals[i][1],vec[j][1]);
    //     }
    //     else {
    //         vec.push_back(intervals[i]);
    //         j++;
    //     }
    // }

    // Merge Sorted Arrays Without Extra Space 

    // int nums1[] = {1,3,4,7}; int n = 4;
    // int nums2[] = { 6,7,7,8,9}; int m = 5;
    // int i = 0,j = 0;

    // Method 1 (Create a new array and store the elements of bothe array in it in a sorted order)
    // TC O(N+M)
    // SC O(N+M)
    // int ans[n+m] ;
    // int k = 0;
    // while(i < n && j < m){            // Two pointer approach for storing elements in a sorted order
    //     if(nums1[i] > nums2[j]){
    //         ans[k] = nums2[j];
    //         k++;
    //         j++;
    //     }
    //     else if(nums1[i] < nums2[j]){
    //         ans[k] = nums1[i];
    //         k++;
    //         i++;
    //     }
    //     else{
    //         ans[k] = nums1[i];
    //         i++;k++;
    //         ans[k] = nums2[j];
    //         j++;k++;
    //     }
    // }
    // for(int i = 0;i < n;i++){         
    //     nums1[i] = ans[i];
    // }
    // for(int i = 0;i < m;i++){
    //     nums2[i] = ans[n+i];
    // }

    // Method 2 (optimal approach 1)
    // TC O(Min(N,M)) + O(N*log(N)) + O(M*log(M))
    // SC O(1)
    // while(nums1[n-i-1] > nums2[j]){       // Comparing elemments from end of one array to the front of other array
    //     if(nums1[n-i-1] > nums2[j]){
    //         swap(nums1[n-i-1],nums2[j]);
    //         j++;
    //         i++;
    //     }
    // }
    // quicksort(nums1,0,n-1);
    // quicksort(nums2,0,m-1);

    // Mehtod 3 (gap method)
    // TC O(log base 2 power (N + M)) * O(N + M)
    // when array is divided by 2 we use log base 2 in the TC     
    // SC O(1)
    // int len = n+m;
    // int gap = (len/2) + (len%2 ); // we need to find the ceil of the len/2
    // while(gap >  0){ 
    //     int left = 0;
    //     int right  = gap + left;
    //     while(right < len){
    //         if(left < n && right >= n){     // nums1 and nums2
    //             if(nums1[left] > nums2[right - n]){
    //                 swap(nums1[left],nums2[right - n]);
    //             }
    //         }
    //         else if(left >= n){            // nums2 and nums2
    //             if(nums2[left - n] > nums2[right - n]){
    //                 swap(nums2[left - n],nums2[right - n]);
    //             }
    //         }
    //         else {                         // nums1 and nums1
    //             if(nums1[left] > nums1[right]){
    //                 swap(nums1[left],nums1[right]);
    //             }
    //         }
    //         left++ ;
    //         right++;
    //     }
    //     if(gap == 1) break;
    //     gap = (gap/2 )+ (gap%2);
    // }
    // for(int i = 0;i < n;i++){
    //     cout << nums1[i] << " ";
    // }
    // for(int i = 0;i < m;i++){
    //     cout << nums2[i] << " ";
    // }
    
    // Find the Missing and Repeating Number

    // vector<int> arr = {4,3,2,5,1,3,6,7,8,10};
    // int n = arr.size();
    // vector<int> ans;
    
    // Method 1 (sorting and comparing the elements)
    // Find the repeating and missing number 
    // TC O(N*log(N) + N)
    // SC O(1)
    // ans = {0,1};
    // sort(arr.begin(),arr.end());
    // for(int i = 0;i < arr.size()-1;i++){
    //     if(arr[i] == arr[i+1]){
    //         ans[0] = arr[i];
    //     }
    //     else if(arr[i+1] != arr[i] + 1){
    //         ans[1] = arr[i] +1;
    //     }
    // }
    // if(arr[arr.size() -1] != arr.size()){
    //     ans[1] = arr.size();
    // }
    
    // Method 2 (OPTIMAL APPRAOCH)(mathematical approach)
    // TC O(N)
    // SC O(1)
    // long long n = arr.size();
    // long long x ;    // repeating number
    // long long y ;   // missing number
    // long long S = 0,S2 = 0;
    // long long Sn = (n*(n+1))/2;
    // long long S2n =  (n*(n+1)*(2*n+1))/6;
    // for(int i = 0;i < n;i++){
    //     S = S + arr[i];
    //     S2 = S2 + (long long)arr[i]*(long long)arr[i];
    // }
    // long long  a = S - Sn;
    // long long  b = S2 - S2n;
    // b = b/a;
    // x = (a+b)/2;
    // y = (b-a)/2;
    // ans = {(int)x,(int)y};

    // Method 3 (XOR)(DOUBT MAI HAI)
    // TC O(N)
    // SC O(1)
    // int xr = 0;
    // for(int i = 0;i < n;i++){
    //     xr = xr ^ arr[i];
    //     xr = xr ^ (i+1);    
    // }
    // int bitNo = 0;
    // while(1){
    //     if((xr & (1<<bitNo)) != 0){
    //         break;
    //     }
    //     bitNo++;
    // }
    // int zero = 0;
    // int one = 0;
    // for(int i = 0; i < n;i++){
    //     // part of the one club
    //     if((arr[i] & (1<<bitNo)) != 0){
    //         one = one^arr[i];
    //     }
    //     // part of zero club
    //     else {
    //         zero = zero^arr[i];
    //     }
    // }
    // for(int i = 1; i <= n;i++){
    //     // part of the one club
    //     if((i & (1<<bitNo)) != 0){
    //         one = one^i;
    //     }
    //     // part of zero club
    //     else {
    //         zero = zero^i;
    //     }
    // }
    // int cnt = 0;
    // for(int i =0;i < n;i++){
    //     if(arr[i]  == zero){
    //         cnt++;
    //     }
    // }
    // if(cnt == 2) ans = {zero,one};
    // else ans = {one,zero};

    // Count Inversions in an Array 
    
    // vector<int> arr = {5,3,2,1,4};

    // Method 1 (Using all the possible combination)
    // TC O(N^2)
    // for(int i = 0;i < arr.size();i++){
    //     for(int j = i + 1;j < arr.size();j++){
    //         if(arr[j] < arr[i]){
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt;

    // Method 2 (using the merge sort code)
    // TC O(N*log(N)) 
    // SC O(N)   (we created a temp array)
    // int n = arr.size();      
    // cout << mergesort(arr,0,n-1);

    // Reverse Pairs 

    // vector<int> nums = {1,3,2,3,1};
    
    // Method 1 (creating all possible combinations)

    // Method 2 (using merge sort code)
    // TC O((N+N)*log(N))
    // SC O(N)
    // int n = nums.size();
    // int ans = rp(nums,0,n-1);
    // cout << ans;

    // Largest product subarray

    // Method 1 (Generate all the subarrays)

    // Method 2 (By observation method)
    // TC O(N)
    // SC O(1)
    // vector <int> nums ={-2,3,4,-1,0,-2,3,1,4,0,4,6,-1,4};
    // int prefix = 1;
    // int mpro = INT_MIN;
    // int suffix = 1;
    // for(int i = 0;i < nums.size();i++){
    //     if(prefix == 0){
    //         prefix = 1;
    //     }
    //     if(suffix == 0){
    //         suffix = 1;
    //     }
    //     prefix = prefix * nums[i];
    //     cout << prefix << " ";
    //     suffix = suffix * nums[nums.size() - 1-i];
    //     cout << suffix << " ";
    //     mpro = max(mpro,max(prefix,suffix)); 
    // }
    // cout << mpro;
   

    // cout << endl;
    // for(auto it : hash){
    //     cout << it.first << " " << it.second;
    //     cout << endl;
    // }


    // Maximum product subarray












    // sort(arr.begin(),arr.end());
    // for(int i = 0;i<arr.size();i ++) {
    //     if(arr[lp] + arr[rp] == 0){
    //         while()          
    //     }
    // }





    // for(auto it : vec){
    //     cout << it[0] << " " << it[1];
    //     cout << endl;
    // }






    return 0;
     
}
