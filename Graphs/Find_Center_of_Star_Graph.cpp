// https://leetcode.com/problems/find-center-of-star-graph/description/

/*

class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        int n = ed.size();
        int m = n+1;
        vector<vector<int>> a(n+1);
        int node  = 0;
        for(int i = 1; i<=n; i++)
        {
            a[ed[i-1][0]-1].push_back(ed[i-1][1]-1);
            a[ed[i-1][1]-1].push_back(ed[i-1][0]-1);
        }

        for(int i = 0; i<=n; i++)
        {
            if(a[i].size()>1)
            {
                node = i+1;
            }
        }
        return node;
    }
};

*/