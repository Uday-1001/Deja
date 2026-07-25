// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:

    bool isPossible(vector<int>&bloomDay,int m,int k,int mid){
        int counter=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                counter++;
                }
                if(counter==k){
                    m--;
                    counter=0;
                if(m==0)
                break;
                }
            if(bloomDay[i]>mid)
            {
                counter=0;
            }
        }
        return (m==0);

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long req =(long long ) m *(long long) k ;
        if(bloomDay.size()<req){
            return -1;
        }      
        int s= *min_element(bloomDay.begin(),bloomDay.end());
        int e= *max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(isPossible(bloomDay,m,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};