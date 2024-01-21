#include<bits/stdc++.h>

bool isPlaim(int i, int j, string s){

    while(i<j){

        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

 

int f(int i, int n, string &str, vector<int>&dp){

    //Base case

    if(i==n) return 0;

    if(dp[i]!=-1) return dp[i];

 
    int mincost=INT_MAX;

    for(int j=i;j<n;j++){

        if(isPlaim(i,j,str)){

            int cost=1+f(j+1,n,str,dp);

            mincost=min(mincost,cost);

        }
    }
    return dp[i]=mincost;
}

 

int palindromePartitioning(string str)
{
    int n=str.size();

    vector<int> dp(n,-1);

    return f(0,n,str,dp)-1;
}

 
