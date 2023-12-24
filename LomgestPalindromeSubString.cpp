#include<bits/stdc++.h>

string expandAroundCenter(int left, int right, const string &s) {

    int n = s.length();

    while (left >= 0 && right < n && s[left] == s[right]) {

        left--;

        right++;

    }

    return s.substr(left + 1, right - left - 1);

}


string longestPalinSubstring(string s) {

    int n = s.length();

    string longest = "";

    for (int i = 0; i < n; i++) {

        string palindrome1 = expandAroundCenter(i, i, s); // Odd length palindrome

        string palindrome2 = expandAroundCenter(i, i + 1, s); // Even length palindrome

        if (palindrome1.length() > longest.length()) {

            longest = palindrome1;

        }

        if (palindrome2.length() > longest.length()) {

            longest = palindrome2;

        }

    }

    return longest;

}

