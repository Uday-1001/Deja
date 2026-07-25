// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool ispossible(vector<int>& piles, int h ,int k){
        double total_hr=0;
        for(int i=0;i<piles.size();i++)
        {
            total_hr += ceil(piles[i]/(double)k);
        }
    return (total_hr <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int ans=-1;
        
        while(s<=e){
            int k=s+(e-s)/2;
            if(ispossible(piles,h,k))
            {
                ans=k;
                e=k-1;
            }
            else{
                s=k+1;
            }
        }
        return ans;
    }
};