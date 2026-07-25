// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    const int mod = 1e9 + 7;
    void prevsmaller(vector<int>& arr , vector<int>&nextans)
    {
        stack<int>st;
        st.push(-1);

        for(int i=0 ; i<arr.size() ; i++)
        {
            int element = arr[i];

            while(st.top() != -1 && arr[st.top()] >= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            nextans.push_back(st.top());
            st.push(i);
        }
    }

    void nextsmaller(vector<int>& arr , vector<int>&prevans)
    {
        stack<int>st;
        st.push(-1);

        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int element = arr[i];

            while(st.top() != -1 && arr[st.top()] >= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            prevans.push_back(st.top());
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int>prevans;
        vector<int>nextans;

        nextsmaller(arr , nextans);
        reverse(begin(nextans) , end(nextans));

        for(int i=0 ; i<nextans.size() ; i++)
        {
            if(nextans[i] == -1)
            {
                nextans[i] = arr.size();
            }
        }

        prevsmaller(arr , prevans);

        int sum =0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            int right = nextans[i] - i;
            int left = i - prevans[i];

            sum += ((right * left) % mod * arr[i]) % mod;
        }
    return sum;
    }
};