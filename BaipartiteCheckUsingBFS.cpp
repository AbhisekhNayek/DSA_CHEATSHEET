#include<bits/stdc++.h>

bool bfs(int start,int col,vector<int> adj[],int color[],vector<vector<int>> &edges){

    color[start]=col;

    queue<int> q;

    q.push(start);

    while(!q.empty()){

        int node=q.front();

        q.pop();

        for(auto it : adj[node]){

            if(color[it]==-1){

                color[it]=!color[node];

                q.push(it);

            }

            else if(color[it]==color[node]) return false;

        }

    }

    return true;

 

}

 

bool isGraphBirpatite(vector<vector<int>> &edges) {

    int n=edges.size();

    vector<int> adj[n];

 

    for(int i=0;i<edges.size();i++){

        for(int j=0;j<edges.size();j++){

        

        if(edges[i][j]==1){

            adj[i].push_back(j);

            adj[j].push_back(i);

        }

        }

    }

 

    int color[n];

    for(int i=0;i<n;i++) color[i]=-1;

       

       for(int i=0;i<n;i++){

           if(color[i]==-1){

               if(bfs(i,0,adj,color,edges)==false){

                   return false;

               }

           }

       }

       return  true;
}
