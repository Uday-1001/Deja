// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    bool hasUniquechars(string temp , string new_str)
    {
        vector<int>freq(26,0);
        for(auto ch : temp) freq[ch - 'a']++;
        for(auto ch : new_str) freq[ch - 'a']++;

        for(auto num : freq)
        {
            if(num > 1) return false;
        }
        return true;
    }

    int byrec(vector<string>& arr , string& temp , int i)
    {
        int n = arr.size();
        if(i >= n) return 0;

        int exclude = 0 + byrec(arr , temp , i+1);

        int include = 0;
        if(temp.empty() or hasUniquechars(temp , arr[i]))
        {
            temp += arr[i];
            include = arr[i].size() + byrec(arr , temp , i+1);
            temp.erase(temp.size() - arr[i].size());
        }

        return max(include , exclude);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return byrec(arr , temp , 0);
    }
};