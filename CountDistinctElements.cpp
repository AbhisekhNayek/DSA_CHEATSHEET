#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    map<int,int> mp1;
    vector<int>ans;
    for(int i=0;i<k;i++) mp1[arr[i]]++;
    ans.push_back(mp1.size());

    int i=0,j=k,t=0;
    while(j<arr.size()){
        mp1[arr[i]]--;
        if(mp1[arr[i]]==0) mp1.erase(arr[i]);
        mp1[arr[j]]++;
        ans.push_back(mp1.size());
        i++;
        j++;
    }
    return ans;
}
