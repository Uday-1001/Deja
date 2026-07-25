// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hashTable[256] = {0};

        for(auto letter1 : s){
                hashTable[letter1] ++;
            }
        
        
        for(auto letter2 : t){
                hashTable[letter2] --;
            }
        

        for(int i=0 ; i<256 ; i++){
            if(hashTable[i] != 0){
                return false;
            }
        }
        return true;
    }
};