#include <bits/stdc++.h> 

int solve(vector<int> &arr, int n){
	vector<int> pres(n+1, 0);
	vector<int> next(n+1, 0);

	for(int curr = n-1; curr >= 0; curr--){
		for(int prev = curr-1; prev >= -1; prev--){
			int take = 0;
			if(prev == -1 || arr[curr] > arr[prev]){
				take = arr[curr] + next[curr+1];
			}

			int skip = next[prev+1];

			pres[prev+1] = max(take, skip);
		}
		next = pres;
	}

	return next[0];
}

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	return solve(arr, n);
}
