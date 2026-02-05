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