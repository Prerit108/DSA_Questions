#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// IMP NOTE - FOR BINARY SEARCH ON ANSWERS , ALWAYS USE "<=" AND ">" CASES
// if(hr <= h){
//     ans = mid;
//     low = mid + 1;                         
// } 
// else {
//     high = mid - 1;
// }

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


// Minimum days to make M bouquets
int Bouquets(vector<int> bloomDay,int mid,int k,int m){           // it will return the no. of bouquets that can be formed on a certain day mid
    int contflower = 0;       // continous flower
    int bouquets = 0;         // no. of bouquets
    for(int i = 0;i < bloomDay.size();i++){
        if(bloomDay[i] <= mid){
            contflower++;
            if(contflower == k){           // if we get k no. of flowers, then we can make 1 bouquet 
                bouquets++;
                contflower = 0;
            }
        }
        else{
            contflower = 0;
        }
    }
    return bouquets;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if((long long)m*k > bloomDay.size()){       // if number of require flowers are greaterr than then available flowers 
        return -1;
    }
    int ans = -1;
    int low = *min_element(bloomDay.begin(),bloomDay.end());      // min no. days will be equal to the min element of bloomDay
    int mid; 
    int high = *max_element(bloomDay.begin(),bloomDay.end());     // max no. days will be equal to the max element of bloomDay
    while(low <= high){
        mid = low + (high-low)/2;
        int bouquets = Bouquets(bloomDay,mid,k,m);                        
        // It measns we have more bouquets than required therefore we can eliminate right half to find the min days required
        // But it can be a possible answer therefore storing it as an ans
        if(m <= bouquets){                                      
            ans = mid;
            high = mid - 1;               
        }
        // It measns we have less bouquets than required therefore we can eliminate left half 
        else{
            low = mid + 1;  
        }
    }
    return ans;
}

// Find the Smallest Divisor Given a Threshold (same as KOKO eat banana problem)
// TC O(log(max(arr[]))*N)
int Divisor_Sum(vector<int> nums,int num){  // TC O(N)
    int divsum = 0;
    for(int i = 0;i < nums.size(); i++){
        divsum = divsum + (nums[i] + num - 1)/num;
    }
    return divsum;
}

int smallestDivisor(vector<int>& nums, int threshold) {    //TC O(log(max{arr[]}))
    int low = 1;
    int high = *max_element(nums.begin(),nums.end());
    int mid;
    int divsum;
    while(low <= high){
        mid = low + (high - low)/2;
        divsum = Divisor_Sum(nums,mid);
        if(divsum <= threshold){
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return low;
}

// Capacity to Ship Packages within D Days
// TC O(log(sum - max + 1) * N)
int days_taken(vector<int>& weights, int mid){     // TC O(N)
    int daystaken = 0;
    int sum_weights = 0;
    for(int i = 0;i < weights.size();i++){
        sum_weights += weights[i];
        if(sum_weights > mid){            // if weight is more than the max capacity of ship
            daystaken++;                  
            sum_weights = weights[i];     // move the last added weight to next day
        }
    }
    if(sum_weights <= mid){        // if some weights which under the max capacity are left at the end.
        daystaken++;             // carry them by making one more round.
    }
    return daystaken;
}

int shipWithinDays(vector<int>& weights, int days) {     // TC O(log(sum - max + 1))
    int low = *max_element(weights.begin(), weights.end());   // ship should be able to carry every element, there minimun capaacity should be the max weight
    int high = 0;           // at max load ship can carry all weights at once                                     
    for(int i = 0; i < weights.size();i++){
        high += weights[i];
    }
    int mid;
    int daystaken;
    while(low <= high){
        mid = low + (high - low)/2;
        daystaken = days_taken(weights,mid);
        if(daystaken <= days){         
            high = mid - 1;          // as the mid decreases daystaken increases
        }
        else{
            low = mid + 1;
        }
       
    }
    return low;
    
}

// 	Kth Missing Positive Number

// Method 1 
// TC O(N)
// SC O(1)
int findKthPositive(vector<int>& arr, int k) {
    for(int i = 0;i < arr.size();i++){
        if(arr[i] <= k){              // If the element of the array is less than k 
            k++;               // move k by one
        }
       else break;
    }
    return k;
}

// Method 2 (Binary search)
// TC O(log(N))
int findKthPositive2(vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k) low = mid + 1;
        else high = mid - 1 ;
    }
    return low + k;
}

// Aggressive cows
// TC O(N * log(max - min element)) + O(Nlog(N)) for sorting
int spaceing_possible(vector<int> stalls,int k, int mid){
    int last_cow = 0;         //index of the last cow placed
    int cnt = 1;              // counter of number of cows placed
    for(int i = 1;i < stalls.size();i++){        
        if(stalls[i] - stalls[last_cow] >= mid){         // comapring the distance between the stall of last cow and the current cow from the mid
            last_cow = i;              
            cnt++;
            if(cnt >= k){                // if we placed all cows return 1
                return 1;
            }
        }
    }
    return 0;                          // if some cows are left then return 0
}

int aggressiveCows(vector<int> &stalls, int k) {   // k is the number of cows
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = *max_element(stalls.begin(),stalls.end()) - *min_element(stalls.begin(),stalls.end());
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(spaceing_possible(stalls,k,mid) == 1){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

// Book Allocation

// Method 1(linear search)
// TC O ((SUM - MAX + 1)*N) 
// CODE HAS SOME ISSUES

int cntstud(vector<int> &arr,int pages){
    int stud_cnt = 1;
    int sum_pages = 0;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] + sum_pages <= pages){
            sum_pages += arr[i];
        }
        else{
            stud_cnt++;
            sum_pages = arr[i];
        }
    }
    return stud_cnt;
}
int bookallocation(vector<int> &arr , int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for(int i = low;i<=high;i++){
        int cnt_students = cntstud(arr,i);
        if(cnt_students == k){
            return i;
        }
    }
    return low;
}

// Method 2 ( binary search )
// TC O(Log base 2 (sum - max + 1) * N)
int book_allocation(vector<int> arr,int mid){
    int cnt = 1;     // number of student among which books are distrubted
    int sum = 0;     // total sum of pages which the current student has
    for(int i = 0;i < arr.size();i++){
        if(sum + arr[i] <= mid){        // giving pages to the student until mid value is reached
            sum += arr[i];
        }
        else{                 // if giving more pages exceeds the value of mid , then give pages to next student
            sum = arr[i];
            cnt++;
        }
    }
    return cnt;
}
int findPages(vector<int> &arr, int k) {
    if(arr.size() < k){         // if number of books less than number of students
        return -1;
    }
    // in the worst case when number of students and number of books are equal the min valus of max pages is 
    int low = *max_element(arr.begin(),arr.end());    
    
    // if there is only one student then the max numbers of pages he can take is
    int high = accumulate(arr.begin(),arr.end(),0);
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(book_allocation(arr,mid) > k){
            low = mid + 1;
        }
        else{
            high = mid  - 1;
        }
    }
    return low;
}

// Split array - Largest Sum
int divider(vector<int> nums,int mid){
    int sum = 0;
    int cnt = 1;
    for(int i = 0;i < nums.size();i++){
        if(sum + nums[i] <= mid){
            sum += nums[i]; 
        }
        else{
            cnt++;
            sum = nums[i];
        }
    }
    return cnt;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(divider(nums,mid) <= k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

// Minimize Max Distance to Gas Station

// Method 1(Brute force)
//  TC O(K*N + N)
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {             
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }
    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

// Method 2( Priority queue)
// TC O(N*log(N) + k*log(N))
// SC O(N-1)
long double findSmallestMaxDist2(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> how_many(n-1,0);
    priority_queue<pair<long double,int>> pq;
    // Pushing the elements in priority queue
    for(int i = 0;i < n-1;i++){                       // TC O(N*log(N))
        pq.push({(long double)(arr[i+1]-arr[i]),i});
    }
    for(int gas_stations = 0;gas_stations < k;gas_stations++){
        auto tq = pq.top();
        pq.pop();
        how_many[tq.second]++;
        // new section length = (original difference between gas stations)/(no. of gas stations added + 1) 
        long double section_len = (long double)(arr[tq.second + 1]-arr[tq.second])/(long double)(how_many[tq.second] + 1);            
        pq.push({section_len ,tq.second});       
    }
    return round(pq.top().first * 100.0) / 100.0;   // rounding off the answer
}

// Method 3 (Binary search)
// TC O(N + N*log(N))
// code 1 not working
int no_of_req_station(long double dist,vector<int> arr){
    int cnt = 0;
    for(int i = 1; i<arr.size() ;i++){
        int stationsinbetween = ((long double)(arr[i]-arr[i-1])/dist);
        if( (arr[i] - arr[i - 1]) == (dist * stationsinbetween)){
            stationsinbetween --;
        }
        cnt += stationsinbetween;
    }
    return cnt;
}
long double findSmallestMaxDist4(vector<int> &arr, int k) {
    long double low = 0;
    long double high = 0;
    for(int i = 0;i < arr.size() - 1;i++){
        high = max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double mid;
    int diff = 1e-6;
    while(high - low > diff){
        mid = low + (high-low)/2.0;
        int cnt = no_of_req_station(mid,arr);
        if(cnt > k){
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return round(high * 100.0) / 100.0;
}


//  code 2 working
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
long double findSmallestMaxDist3(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return round(high * 100.0) / 100.0;;
}

// Median of 2 sorted arrays
// Mehtod 1 
// TC O(N+M)
// SC O(N+M)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> merged(n+m);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m){           
        if(nums1[i] > nums2[j]){
            merged[k] = nums2[j];
            k++;
            j++;
        }
        else{
            merged[k] = nums1[i];
            k++;
            i++;
        }
    }
    while(i<n){
        merged[k] = nums1[i];
        k++;i++; 
    }
    while(j < m){
        merged[k] = nums2[j];
        k++;j++; 
    }
    double median = 0;
    int l = merged.size();
    if(merged.size()%2 == 0){          // if array hai even no. of elements 
        median = ((double)merged[l/2] + (double)merged[l/2 -1])/2.0;
        return median;
    }
    return (double)merged[l/2];
}

// Method 2 (Optimized the space complexity of method 1)
// TC O(N+M)
// SC O((N+M)/2)
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    vector<int> merged(n+m);
    int i = 0;
    int j = 0;
    int k = 0;
    int ind1 = (n+m)/2 ; int ind2 = (n+m)/2 -1;  // index of the middle elements of the merged array
    int ele1 ;int ele2;
    while(i < n && j < m){
        if(nums1[i] > nums2[j]){
            merged[k] = nums2[j];
            if(ind1 == k) ele1 = merged[k];
            if(ind2 == k) ele2 = merged[k];
            k++;
            j++;
        }
        else{
            merged[k] = nums1[i];
            if(ind1 == k) ele1 = merged[k];
            if(ind2 == k) ele2 = merged[k];
            k++;
            i++;
        }
    }
    while(i<n){
        merged[k] = nums1[i];
        if(ind1 == k) ele1 = merged[k];
            if(ind2 == k) ele2 = merged[k];
        k++;i++; 
    }
    while(j < m){
        merged[k] = nums2[j];
        if(ind1 == k) ele1 = merged[k];
        if(ind2 == k) ele2 = merged[k];
        k++;j++; 
    }
    // In case of odd length of the merged array there will only be one middle element
    if((n+m)%2 != 0){
        return ele1;
    }
    return (ele1+ele2)/2.0;
}

//  Mehtod 3 (Binary search)
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1 > n2) return findMedianSortedArrays3(nums2,nums1);
    int low = 0 ; int high = n1;
    int left = (n1 + n2 + 1)/2;
    int n = n1 + n2;
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            if(n%2 == 1) return max(l1,l2);
            return ((double)(max(l1,l2) + min(r1,r2))/2.0);
        }
        else if(l1 > r2) high = mid1 -1 ;
        else low = mid1 + 1; 
    }
    return 0;
}

int main(){

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

    // Minimum days to make M bouquets
    // cout << minDays(vector,m,k)


    






    return 0; 
}