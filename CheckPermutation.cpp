#include <bits/stdc++.h> 

bool areAnagram(string &str1, string &str2){

    unordered_map<char,int> mpp;

    if(str1.length() != str2.length())
        return 0;

    for(auto i = str1.begin() ; i != str1.end() ; i++)
    {
        mpp[*i]++;
    }

    for(auto i = str2.begin(); i!= str2.end() ; i++)
    {
        mpp[*i]--;
    }

    for(const auto&i : mpp)
    {
        if(i.second != 0) return 0;
    }
    return 1;

}
