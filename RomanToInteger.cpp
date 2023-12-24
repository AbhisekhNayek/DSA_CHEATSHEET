int romanToInt(string s) {

    map<char,int> mpp;

    mpp['I']=1;

    mpp['V']=5;

    mpp['X']=10;

    mpp['L']=50;

    mpp['C']=100;

    mpp['D']=500;

    mpp['M']=1000;

    int sum=0;

    for(int i=0;i<s.length();i++){

        if((i<s.length()-1) && mpp[s[i+1]]>mpp[s[i]]){

            sum+=mpp[s[i+1]];

            sum-=mpp[s[i]];

            i++;
        }

        else sum+=mpp[s[i]];
    }
    return sum;
}
