// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    const int mod = 1e9 + 7;

    vector<int> prevsmaller(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>prevans(arr.size() , -1);

        for(int i=0 ; i<arr.size() ; i++)
        {
            int element = arr[i];

            while(!st.empty() && st.top() != -1 && arr[st.top()] > element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            prevans[i] = st.top();
            st.push(i);
        }
    return prevans;   
    }

    vector<int> nextsmaller(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>nextans(arr.size() , -1);

        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int element = arr[i];

            while(!st.empty() && st.top() != -1 && arr[st.top()] >= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            nextans[i] = st.top();
            st.push(i);
        }
    return nextans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        auto prevans = prevsmaller(arr);
        auto nextans = nextsmaller(arr);

        int sum =0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            auto nexti = nextans[i] == -1 ? arr.size() : nextans[i];
            auto previ = prevans[i];

            int left = i - previ;
            int right = nexti - i;
            sum = (sum + ((((left * right)% mod)* arr[i]) % mod)) % mod;
        }
    return sum;
    }
};