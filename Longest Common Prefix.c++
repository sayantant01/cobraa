// Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string.

// Problem Link: https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &str)
{
    int n = str.size();
    if (n == 0)
        return "";

    string ans = "";
    sort(begin(str), end(str));
    string a = str[0];
    string b = str[n - 1];

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            ans = ans + a[i];
        }
        else
        {
            break;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    string lcp = longestCommonPrefix(v);
    cout << lcp << endl;
    return 0;
}