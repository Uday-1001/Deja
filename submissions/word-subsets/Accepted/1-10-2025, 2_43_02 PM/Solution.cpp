// https://leetcode.com/problems/word-subsets

class Solution {
public:
    void SetMaxFreq (vector<int>&freq_words2 , vector<int>&freq){
        for(int i=0; i<26;i++)
        {
            freq_words2[i] = max(freq_words2[i] ,freq[i]);
        }
    }

    bool IsUniversal(vector<int>&freq_words1, vector<int>&freq_words2){
        for(int i=0 ; i<26 ; i++)
        {
            if(freq_words1[i] < freq_words2[i])
            {
                return false;
            }
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq_words2(26);
        for(string word : words2)
        {
            vector<int> freq(26);
            for(char ch : word)
            {
                freq[ch - 'a']++;
            }
            SetMaxFreq(freq_words2 , freq);
        }

        vector<string> universal;
        for(string word : words1)
        {
            vector<int> freq_words1(26);
            for(char ch : word)
            {
                freq_words1[ch-'a']++;
            }
            if(IsUniversal(freq_words1 , freq_words2))
            {
                universal.push_back(word);
            }
        }
    return universal;
    }
};