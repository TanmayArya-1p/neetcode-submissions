#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid;
        int i = 0;
        int j = matrix.size()-1;
        while(i<j) {
            mid = (i+j+1)/2;
            cout << mid << endl;
            if(target >= matrix[mid][0]){
                i = mid;
            } else {
                j = mid-1;
            }
        }
        auto it = lower_bound(matrix[i].begin() , matrix[i].end(), target);
        return (it != matrix[i].end() && *it == target);
    }
};

