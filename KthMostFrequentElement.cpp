#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int>mpp;
    typedef pair<int,int>pi;
    priority_queue<pi>pq;
    for(auto i:arr) mpp[i]++;
    
    for(auto i:mpp) pq.push({i.second,i.first});
    
    vector<int>ans;
    while(k)
    {
    ans.push_back(pq.top().second);
       pq.pop();
       k--;
    }
    return ans;
}
