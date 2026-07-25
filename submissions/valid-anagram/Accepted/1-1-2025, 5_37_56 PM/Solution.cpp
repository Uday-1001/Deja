// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hashTable[256] = {0};
        // incrementing the hash index of the s[i]
        for(auto letter1 : s){
                hashTable[letter1] ++;
            }
        // incrementing the hash index of the t[i]
        
        for(auto letter2 : t){
                hashTable[letter2] --;
            }
        
        //checking for any "0" has index which means same number of letters used and thus is anagram
        for(int i=0 ; i<256 ; i++){
            if(hashTable[i] != 0){
                return false;
            }
        }
        return true;
    }
};