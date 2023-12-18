#include <bits/stdc++.h> 

void insert(vector<int> &pq, int element) {

    pq.push_back(element);

 

    int childIndex = pq.size()-1;

    //upHeapify

    while(childIndex > 0) {

        int parentIndex = (childIndex-1)/2;

        if(pq[childIndex] < pq[parentIndex]) {

            int temp = pq[childIndex];

            pq[childIndex] = pq[parentIndex];

            pq[parentIndex] = temp;

        }

        else {

            break;

        }

        childIndex = parentIndex;

    }

}

 

int remove(vector<int> &pq) {

    if(pq.size() == 0)

        return 0;

    

    int ans = pq[0];

    pq[0] = pq[pq.size()-1];

    pq.pop_back();

 

    //down Heapify

    int parentIndex = 0;

    int minIndex = parentIndex;

    int leftChildIndex = 2*parentIndex+1;

    int rightChildIndex = 2*parentIndex+2;

 

    while(leftChildIndex < pq.size()) {

        if(pq[leftChildIndex] < pq[minIndex]) {

            minIndex = leftChildIndex;

        }

        if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {

            minIndex = rightChildIndex;

        }

        if(minIndex == parentIndex) {

            break;

        }

        //swazp

        int temp = pq[minIndex];

        pq[minIndex] = pq[parentIndex];

        pq[parentIndex] = temp;

 

        parentIndex = minIndex;

        leftChildIndex = 2*parentIndex + 1;

        rightChildIndex = 2*parentIndex + 2;

    }

    return ans;

}

 

vector<int> minHeap(int n, vector<vector<int>>& q) {

    // Write your code here.

    vector<int> pq;

    vector<int> ans;

 

    for(int i = 0; i < q.size(); i++) {

        if(q[i][0] == 0) 

            insert(pq, q[i][1]);

        else {

            int minElement = remove(pq);

            ans.push_back(minElement);

        }

    }

    return ans;

}
