//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
class Solution {
public:
    int aa[100][100];
    int totalcost(vector<vector<int>>& costs, int n, int a, int b)
    {
        if (a == 0 && b == 0 && n == 0)
            return 0;
        if (a < 0 || b < 0)
            return 100000;
        if (aa[a][b] != -1)
            return aa[a][b];
        else
            return aa[a][b] = min(costs[n - 1][0] + totalcost(costs, n - 1, a - 1, b),
                                  costs[n - 1][1] + totalcost(costs, n - 1, a, b - 1));
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        memset(aa, -1, sizeof(aa));
        return totalcost(costs, n, n / 2, n / 2);
    }
};
