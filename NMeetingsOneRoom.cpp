#include<bits/stdc++.h>
struct meeting{
    int _start;
    int _end;
};
static bool cmp(const meeting &m1,const meeting &m2){
    return m1._end < m2._end;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n=start.size();
    int ans =1;
    vector<meeting> meetings(n);
    for(int i=0;i<n;i++){
        meetings[i]._start=start[i];
        meetings[i]._end=end[i];
    }
    sort(meetings.begin(),meetings.end(),cmp);
    int limit=meetings[0]._end;
    for(int i=1;i<n;i++){
        if(meetings[i]._start > limit){
            ans++;
            limit = meetings[i]._end;
        }
    }
    return ans;
}
