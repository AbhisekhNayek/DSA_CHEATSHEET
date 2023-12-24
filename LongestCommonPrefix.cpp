string commonPrefix(vector<string>& arr,int n) {

    if(arr.size()==0) return "";

    sort(arr.begin(),arr.end());

    string ans="";

    int m=arr[0].size();

    for(int i=0;i<m;i++){

        if(arr[0][i]==arr[arr.size()-1][i]){

            ans+=arr[0][i];

        }else{

            break;

        }

    }

    return ans==""?"-1":ans;

}

