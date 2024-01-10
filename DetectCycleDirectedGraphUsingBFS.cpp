#include<bits/stdc++.h>

 

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

// Write your code here.

unordered_map<int,list<int>>adj;

vector<int>indegree(n,0);

for(int i=0;i<edges.size();i++){

int u=edges[i].first-1;

int v=edges[i].second-1;

adj[u].push_back(v);

indegree[v]++;

}

 

queue<int>q;

for(int i=0;i<n;i++){

if(indegree[i]==0){

q.push(i);

}

}

int cnt=0;

while(!q.empty()){

int front=q.front();

q.pop();

cnt++;

for(auto i:adj[front]){

indegree[i]--;

if(indegree[i]==0){

q.push(i);

}

}

}

if(cnt==n){

return false;

}

else{

return true;

}

}

