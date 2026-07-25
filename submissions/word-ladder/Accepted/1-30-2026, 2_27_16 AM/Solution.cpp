// https://leetcode.com/problems/word-ladder

class Solution {
public:
    set<string>st;
    unordered_map<string , bool>vis;

    vector<string> possiblewords(string &s)
    {
        vector<string>result;
        string original = s;
        for(int i = 0 ; i<original.size() ; i++)
        {
            for(char ch = 'a' ; ch <= 'z' ; ch++)
            {
                if(ch == original[i]) continue;
                string temp = original;
                temp[i] = ch;

                if(st.count(temp) and !vis[temp]) result.push_back(temp);
            }
        }
    return result;
    }

    int bfs(string &beginWord , string &endWord)
    {
        queue<pair<string , int>>q;
        q.push({beginWord , 1});
        vis[beginWord] = true;

        while(!q.empty())
        {
            auto[str , count] = q.front();
            q.pop();
            if(str == endWord) return count;

            vector<string> possible_nbr = possiblewords(str);
            for(auto &nbr : possible_nbr)
            {
                if(!vis[nbr])
                {
                    vis[nbr] = true;
                    q.push({nbr , count + 1});
                } 
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto it : wordList) st.insert(it);

        if(!st.count(endWord)) return 0; 

        return bfs(beginWord , endWord);
    }
};