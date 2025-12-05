#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Power of 2

bool isPowerOfTwo(int n) {
    if(n <= 0){
        return false;
    }
    if((n&(n-1)) == 0){
        return true;
    }
    return false;
}

// Divide two integers without using multiplication, division and mod operator

// Method 1
// TC O(INT_MAX)
// SC 0(1)
int divide(int dividend, int divisor) {
if (divisor == 0) {
    return INT_MAX;
}

if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX; // prevent overflow
}
if (dividend == INT_MIN && divisor == 1) {
    return INT_MIN; // prevent overflow
}

long long absDividend = abs((long long)dividend);
long long absDivisor  = abs((long long)divisor);

int quotient = 0;

    while (absDividend >= absDivisor) {
        absDividend = absDividend - absDivisor;
        quotient += 1; 
    
    }
    if(divisor < 0 && dividend < 0)
        return quotient;
    else if(divisor < 0 || dividend < 0)
        return -quotient; 
    return quotient;
}

// Method 2
// find the greatest power of 2 which when multipied by the divisor is less than the dividend and subtract it from dividend,
// add the power of 2 to the quotient
// TC O(log(N) ^2)
// SC O(1)
int Divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        if (divisor == 0) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // prevent overflow
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN; // prevent overflow
        }
        long long absDividend = abs((long long)dividend);   // Since -2^31 cannot be stored in int after applying absolute , it will become 2^31 out of int.
        long long absDivisor  = abs((long long)divisor);

        int quotient = 0;

        while(absDividend >= absDivisor){      // TC log base2 (N)
            int cnt = 0;
            while(absDividend >= absDivisor<<(cnt+1)){      // TC log base2 (N)
                cnt++;
            }
            absDividend -= (absDivisor<<cnt);
            quotient += 1<<cnt ;
        }
        if(divisor < 0 && dividend < 0)
            return quotient;
        else if(divisor < 0 || dividend < 0)
            return -quotient; 
        return quotient;
    }

// Count number of bits to be flipped to convert A to B
// Use xor operator
// TC O(31)
// SC O(1)

int minBitFlips(int start, int goal) {
    int diff = start^goal;
    int cnt = 0;
    for(int i = 0;i <=31; i++){
        if(diff & (1<<i)){
            cnt++;
        }
    }
    return cnt;
}

// TC O(log(start^goal))
// SC O(1)
int minBitFlips(int start, int goal) {
    int diff = start^goal;
    int cnt = 0;
    while(diff != 0){
        if(diff%2 == 1){
            cnt++;
        }
        diff = diff/2;
    }
    return cnt;
}

// Find the number that appears odd number of times

// Method 1
// Hash array
// TC O(N) n is the size of nums
// SC O(60001)
// Use unordered map not vector
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> hash(60001,0);
    for(int i = 0;i < n ;i++){
        int ele = nums[i]+30000;
        hash[ele]++;
    }
    for(int i = 0;i < hash.size() ;i++){
        if(hash[i]%2 == 1){
            return i - 30000;
        }
    }
    return -1;

}

// Method 2
// XOR
// TC O(N)
// SC O(1)
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int single = 0;
    for(int i = 0;i<n;i++){
        single = single^nums[i];
    }
    return single;

}

int main(){
    
    int a = minBitFlips(10,7);
    cout << a;


    return 0;
}