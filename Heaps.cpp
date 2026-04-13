




// Nearly sorted

void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> minh;
        int j = 0;
        for(int i = 0;i < arr.size();i++){
            minh.push(arr[i]);
            if(arr.size() >= k){     
                arr[j] = minh.top();
                minh.pop();
                j++;
            }  
        }
        while(!minh.empty()){
            arr[j] = minh.top();
            minh.pop();
        }
    }

// Find K Closest Elements
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        vector<int> vec;
        for(int i = 0;i < arr.size();i++){
            maxh.push({abs(arr[i] - x),arr[i]});
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        // int j = 0;
        while(!maxh.empty()){
            vec.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(vec.begin(),vec.end());
        return vec;

    }