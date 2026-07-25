// https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:

    bool isPossible(vector<int>& position, int m,int mid){
        int first = position[0];
        int c=1;
        for(int i=0;i<position.size();i++)
        {
            if(position[i]-first>=mid)
            {
                c++;
                first = position[i];
                if(c==m)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position .begin(),position.end());
        int s=0;
        int e=*max_element( position .begin(),position.end() );
        int ans=-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(isPossible(position,m,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};