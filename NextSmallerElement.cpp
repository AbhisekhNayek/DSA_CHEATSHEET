#include<bits/stdc++.h>

void immediateSmaller(vector<int>& a)
{
    int n=a.size();
    int x=a[n-1];

    for(int i=n-1;i>=0;i--)
    {   
        if(a[i]>x)
        {   
            int h=a[i];
            a[i]=x;
            x=h;
        }
        else
        {
            x=a[i];
            a[i]=-1;
        }
    }
}
