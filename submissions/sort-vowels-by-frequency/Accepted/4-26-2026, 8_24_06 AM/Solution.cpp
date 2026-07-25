// https://leetcode.com/problems/sort-vowels-by-frequency

class Solution {
public:
    unordered_map<char,int>freq;
    unordered_map<char,int>pos;

    string sortVowels(string s) {
        int n = s.size();
        
        for(int i = 0 ; i<n ; i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
                freq[s[i]]++;
                if(!pos.count(s[i])) pos[s[i]] = i;
            }      
        }

        vector<char>vowels = {'a' , 'e' , 'i' , 'o' , 'u'};
        sort(vowels.begin() , vowels.end() , [&](char &a , char &b)
         {
            if(freq[a] != freq[b]) return freq[a] > freq[b];
            return pos[a] < pos[b];
         });

        string temp = "";
        for(auto it : vowels) for(int i = 0 ; i<freq[it] ; i++) temp += it;
                                  
        int idx = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
                s[i] = temp[idx++];
        }
        return s;
    }
};