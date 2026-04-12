#include <cassert>
class MedianFinder {
public:
    
    priority_queue<int> lower;
    priority_queue<int, vector<int>, std::greater<int>> upper;
    size_t n;
    MedianFinder() : n(0) {
        lower = {};
        upper = {};
    }
    
    void addNum(int num) {
        n++;
        if(upper.size() == 0 && lower.size() == 0) {
            upper.push(num);
            return;
        };


        if(num < upper.top()) {
            lower.push(num);
        } else {
            upper.push(num);
        }
        rebalance();
    }

    inline void rebalance() {
        while(lower.size() < upper.size()-1) {
            auto curr = upper.top();
            upper.pop();
            lower.push(curr);
        }

        while(upper.size() < lower.size()) {
            auto curr = lower.top();
            lower.pop();
            upper.push(curr);
        }

        assert(0 <= upper.size()-lower.size() <= 1);
    }
    
    double findMedian() {
        if(upper.size() > lower.size()) {
            return upper.top();
        } else {
            return (lower.top()+upper.top())/2.0;
        }
    }
};
