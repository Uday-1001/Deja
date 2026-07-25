// https://leetcode.com/problems/distribute-repeating-integers

class Solution {
public:
    bool recursion(vector<int>& count, vector<int>& quantity , int index)
    {
        //base case 
        if(index >= quantity.size())
        {
            return true;
        }

        //ek case hum solve karenge baaki ka recursion kardega
        bool ans = false;
        for(int i=0 ; i<count.size() ; i++)
        {
            if(count[i] >= quantity[index])
            {
                count[i] -= quantity[index];

                ans = recursion(count , quantity , index+1);   
            }
            //backtrack kar jana 
            count[i] += quantity[index];
        }
        return ans;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;

        sort(rbegin(quantity) , rend(quantity));
        
        for(auto i: nums)
        {
            mp[i]++;
        }
        vector<int>count;
        for(auto &it: mp)
        {
            count.push_back(it.second);
        }

        return recursion(count , quantity , 0);
    }
};