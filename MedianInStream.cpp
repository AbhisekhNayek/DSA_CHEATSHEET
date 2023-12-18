#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){

    

    // Write your code here 

    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> ans;

 

    for(int i=0; i<n; i++){

 

        // for inserting in heaps

        if(maxHeap.empty() || arr[i] < maxHeap.top()){

            maxHeap.push(arr[i]);

        }

        else{

            minHeap.push(arr[i]);

        }

 

        // for balancing both the heaps

        if(maxHeap.size() > minHeap.size()+1){

            minHeap.push(maxHeap.top());

            maxHeap.pop();

        }

        else if(minHeap.size() > maxHeap.size()+1){

            maxHeap.push(minHeap.top());

            minHeap.pop();

        }

        

 

        // storing median in ans array

        if(maxHeap.size() < minHeap.size()){

            ans.push_back(minHeap.top());

        }

        else if(maxHeap.size() > minHeap.size()){

            ans.push_back(maxHeap.top());

        }

        else{

            int temp = (minHeap.top()+maxHeap.top())/2;

            ans.push_back(temp);

        }

    }

    return ans;

}
