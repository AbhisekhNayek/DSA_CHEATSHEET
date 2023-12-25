#include <bits/stdc++.h> 

int compareVersions(string a, string b) 
{

    int n1 = a.size();
    int n2 = b.size();
    int i = 0; 
    int j = 0;

    while(i < n1 || j < n2){

        long num1 = 0; // use long to avoid failed test case for large test case
        long num2 = 0; // use long to avoid failed test case for large test case

        while(i < n1 && a[i] != '.' ){
            num1 = num1*10 + (a[i] - '0');
            i++; 
        }

        while(j < n2 && b[j] != '.' ){
            num2 = num2*10 + (b[j] - '0');
            j++; 
        }

        if(num1>num2) return 1;
        else if(num1<num2) return -1;
        i++;
        j++;
    }
    return 0;
}
