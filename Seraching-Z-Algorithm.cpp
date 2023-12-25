vector<int> search(string s, string t) {

    vector<int> ans;

    int n = t.size();

    for(int i=0;i<s.size();i++){

        if(s.substr(i,n) == t){

            ans.push_back(i+1);

        }

    }

    return ans;

}
