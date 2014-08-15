#include <stdio.h>
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_map>
using namespace std;
#define LEETCODE
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> flat;
        if (matrix.size() == 0 || matrix[0].size() == 0) return flat;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int t = 0, l = 0, b = m-1, r = n-1;
        int moves[8] = {1, 0,   0, 1,   -1, 0,  0, -1};
        int *turn[8] = {&r,&t,     &r,&b,    &l,&b,    &l,&t};
        int x = 0, y = 0, v = 0;
        if (n == 1)
			v = 1;
        for (int i = 0; i < m * n; ++i) {
            flat.push_back(matrix[y][x]);
            
            x += moves[v*2];
            y += moves[v*2+1];
            
            if (x == *turn[v*2] && y == *turn[v*2+1]) {
                int v2 = (v+1)%4;
                *turn[v*2] += moves[v2*2];
                *turn[v*2+1] += moves[v2*2+1];
				v = v2;
            }
        }
        return flat;
    }
};