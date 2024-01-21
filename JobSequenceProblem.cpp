#include<bits/stdc++.h>

using namespace std;

static bool cmp(vector<int>&a,vector<int>&b)

{

    return a[2]>b[2];

}

vector<int> jobScheduling(vector<vector<int>> &jobs)

{

    vector<int>ans;

    int n=jobs.size();

    //first we need to sort the jobs vector 

    sort(jobs.begin(),jobs.end(),cmp);

    

    //once we have sorted

    int maxi=jobs[0][1]; //taking the maximum deadline

 

    //now check if the deadline is max only

    for(int i=1;i<n;i++)

    {

        maxi=max(maxi,jobs[i][1]);

    } 

 

    int slot[maxi+1];

  

    //mark all slots as -1

     for(int i=0;i<=maxi;i++)

     {

         slot[i]=-1;

     }

    int countjobs=0,profit=0;

    for(int i=0;i<n;i++)

    {

        //now hum peeche se check karenge

        for(int j=jobs[i][1];j>0;j--)

        {

            if(slot[j]==-1)

            {

                slot[j]=i;

                countjobs++;

                profit+=jobs[i][2];

                break;

            }

        }

    } 

   ans.push_back(countjobs);

   ans.push_back(profit);

   return ans;

}
