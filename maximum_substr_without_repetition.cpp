#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char,int> hash;
    int j = 0;
    int ans = 0;
    for(int i=0;i<input.size();i++)
    {
        hash[input[i]]++;
        while(hash[input[i]] > 1) //while repeat characters are there, remove elements from the beginning.
        {
            hash[input[j]]--;
            j++;
        }
        ans = max(ans,i-j+1); //calc max
    }
    return ans;
}
