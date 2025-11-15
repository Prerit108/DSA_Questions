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

// Divide 2 integers without using odd

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
int divide(int dividend, int divisor) {
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
            while(absDividend >= absDivisor<<(cnt+1)){     // // TC log base2 (N)
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
int main(){


    return 0;
}