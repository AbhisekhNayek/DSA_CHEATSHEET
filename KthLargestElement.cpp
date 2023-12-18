#include <queue>

int kthLargest(vector<int> &arr,int size,int k){

    priority_queue<int,vector<int>,greater<int>> pq;

       for(int i = 0;i<k;i++){

           pq.push(arr[i]);

       }

       for(int i = k;i<size;i++){

           if(arr[i]>pq.top()){

               pq.pop();

               pq.push(arr[i]);

           }

       }

        int ans = pq.top();

        return ans;

}

int kthsmallest(vector<int> &arr,int n,int k){

    priority_queue<int> pq;

    for(int i = 0;i<k;i++){

        pq.push(arr[i]);

    }

    for(int i = k;i<n;i++){

        if(arr[i]<pq.top()){

            pq.pop();

            pq.push(arr[i]);

        }

    }

    int ans = pq.top();

    return ans;

}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)

{

    vector<int> ans;

    ans.push_back(kthsmallest(arr,n,k));

    ans.push_back(kthLargest(arr,n,k));

    return ans;

}
