// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using ti = tuple<int,int,char>;
    unordered_map<int,vector<ti>>adjlist;
    unordered_map<int,int>parent;
    unordered_map<int,char>parentDirection;

    void fillingadjlist(TreeNode* root)
    {
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto front = q.front();
                q.pop();

                if(front->left) 
                {
                    q.push(front->left);
                    adjlist[front->val].push_back({1 , front->left->val , 'L'});
                    adjlist[front->left->val].push_back({1 , front->val , 'U'});
                }
                if(front->right) 
                {
                    q.push(front->right);
                    adjlist[front->val].push_back({1 , front->right->val , 'R'});
                    adjlist[front->right->val].push_back({1 , front->val , 'U'});
                }
            }
        }
    }

    void dijkstra(int src , int dest)
    {
        unordered_set<int>vis;
        unordered_map<int,int>dist;
        
        parent[src] = -1;

        priority_queue<ti , vector<ti> , greater<>>pq;
        pq.push({0 , src , 'N'});

        while(!pq.empty())
        {
            auto[currdist , node , dr] = pq.top(); 
            pq.pop();

            vis.insert(node);

            //reached the destination node of the tree
            if(node == dest) break;

            for(auto &it : adjlist[node])
            {
                auto[nbrdist , nbr , nbrdr] = it;
                if(!vis.count(nbr) and (!dist.count(nbr) or (currdist + nbrdist < dist[nbr])))
                {
                    dist[nbr] = currdist + nbrdist;
                    parent[nbr] = node;
                    parentDirection[nbr] = nbrdr;
                    pq.push({dist[nbr] , nbr , nbrdr});
                }
            }
        }
    }

    string getDirections(TreeNode* root, int src, int dest) {
        fillingadjlist(root);
        dijkstra(src , dest);
        string ans;
        int d = dest;

        while(parent[d] != -1)
        {
            ans.push_back(parentDirection[d]);
            d = parent[d];
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};