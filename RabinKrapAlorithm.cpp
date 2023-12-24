#include <bits/stdc++.h>

vector<int> stringMatch(string text, string pattern) {
    vector<int>ans;

    for(int i=0;i<text.size()-pattern.size()+1;i++){

        if(text.substr(i, pattern.size())==pattern)ans.push_back(i+1);
    }
    return ans;
}

