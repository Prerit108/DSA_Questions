#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Merge sort 
//TC is O(N*log(base 2) power N)
// SC is O(N)
void merge(int arr[] ,int low,int mid ,int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] >= arr[right]){
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
    for(int i = low; i <= high;i++){  // IMPORTANT
        arr[i] = temp[i-low];
    }

}

void mergesort(int arr[],int low,int high){
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}  

// Quick Sort
// TC O(N*log(N))  
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

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pindex = f(arr,low,high);
        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
    }

}

int main()
{
    // Selection sort
    // // TC O(N^2)
    // int arr[6] = {13 ,45,24,52,20,9};
    // for(int i = 0;i < 5;i++){
    //     int mini=i;
    //     for(int j = i+1;j < 6;j++){
    //         if(arr[j]<arr[mini]){
    //             mini = j;
    //         }
    //     }
    //     swap(arr[mini],arr[i]);
    // }

    // BUBBLE SORT
    // TC O(N^2) worst case
    // TC O(N) best case (when array is sorted)
    // int arr[6] = {13,42,24,53,20,9};
    // int n = 6, c = 0;
    // for (int j = n - 2; j >= 0; j--)
    // {
    //     for (int i = 0; i <= j; i++)
    //     {
    //         if (arr[i] > arr[i + 1])
    //         {
    //             swap(arr[i], arr[i + 1]);
    //             c = 1;
    //         }
    //     }
    //     if (c == 0)
    //     {
    //         cout << "sorted array" << "\n";
    //         break;
    //     }
    // }

    // Insertion Sort
    // TC O(N^2) worst case
    // TC O(N) best case (when array is sorted)
    // int arr[6] = {13, 42, 24, 53, 20, 9};
    // int n = 6;
    //     for (int i = 1; i <= n - 1; i++)
    //     {
    //         int j = i;
    //         while (j > 0 && arr[j-1] > arr[j])   
    //         {
    //         swap(arr[j - 1], arr[j]);
    //         j--;
    //         }
    //     }

    int arr[9] = {3,1,2,4,1,5,6,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }


    return 0; 
}
