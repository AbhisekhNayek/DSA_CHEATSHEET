#include <bits/stdc++.h>

class node{

    public:

        int data;

        int row;

        int col;

 

        node(int data, int row, int col) : data(data), row(row), col(col) {}

};

class compare{

    public:

        bool operator()(node *a, node *b){

            return a->data > b->data;

        }

};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)

{

    priority_queue<node *, vector<node *>, compare> minHeap;

 

    if(k != 0) for(int i=0;i<k;i++) minHeap.push(new node(kArrays[i][0], i, 0));  

    vector<int> arr;

    while(!minHeap.empty()){

        node *temp = minHeap.top();

        arr.push_back(temp->data);

        minHeap.pop();

 

        int row = temp->row;

        int col = temp->col;  

        if(col+1 < kArrays[row].size()) minHeap.push(new node(kArrays[row][col+1], row, col+1));

    }

 

    return arr;

}

