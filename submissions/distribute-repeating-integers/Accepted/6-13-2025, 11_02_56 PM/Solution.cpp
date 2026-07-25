// https://leetcode.com/problems/distribute-repeating-integers

class Solution {
public:
    bool recursion(vector<int>&count, vector<int>&quantity , int index)
    {
        //base case 
        if(index == quantity.size())
        {
            return true;
        }

        //ek case hum solve karenge baaki ka recursion kardega
        for(int i=0 ; i<count.size() ; i++)
        {
            if(count[i] >= quantity[index])
            {
                count[i] -= quantity[index];

                bool ans = recursion(count , quantity , index+1);
                if(ans == true) return true;
                   
                //backtrack kar jana 
                count[i] += quantity[index];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;

        sort(rbegin(quantity) , rend(quantity));

        for(auto i: nums)
        {
            mp[i]++;
        }
        vector<int>count;
        for(auto it: mp)
        {
            count.push_back(it.second);
        }

        return recursion(count , quantity , 0);
    }
};