#include <bits/stdc++.h>

class Kthlargest {

public:

    int largest=0;
    vector<int> ans;

    Kthlargest(int k, vector<int> &arr) {
     
     largest=k;
     ans=arr;
     sort(ans.begin(), ans.end());

    }

 
    int add(int num) {

       int position= upper_bound(ans.begin(), ans.end(), num)-ans.begin();

       ans.insert(ans.begin()+position,num);

        return ans[ans.size()-largest];

    }
};
