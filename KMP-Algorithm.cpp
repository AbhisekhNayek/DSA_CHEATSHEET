#include <bits/stdc++.h>

vector<int> stringMatch(string text, string pat) {

    // Write your code here.

    int ind = -1;

    int n = pat.size(); 

    vector<int> v;

    for(int i=0;i<text.size();i++){

        if(text[i]==pat[0]){

            ind = i;

            int flag = 0;

            string str = text.substr(i,n);

            if(str == pat){

                v.push_back(i+1);

            }

        }

    }

    return v;

}
