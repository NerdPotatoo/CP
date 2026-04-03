// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

/*
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> a(n,0);
        for(auto i: edges)
        {
                a[i[1]] = 1; 
            
        }

        vector<int> s;
        for(int i = 0; i<=n-1; i++)
        {
            if(a[i] == 0) s.push_back(i);
        }
        return s;
    }
};
*/