// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        
        for(int i = 2; i<n; i++){
            if(islower(word[i]) && isupper(word[i-1])) {return false;}
            if(isupper(word[i]) && islower(word[i-1])) {return false;}
        }
    
        return true;
    }
};