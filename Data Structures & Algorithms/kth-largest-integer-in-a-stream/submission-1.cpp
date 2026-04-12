
class KthLargest {
public:

    int k;
    priority_queue<int, std::vector<int>, std::greater<int>> q;
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(auto &i : nums) {
            if(q.size() < k) {
                q.push(i);
            } else {
                if(q.top() < i) {
                    q.pop();
                    q.push(i);
                }
            }
        }


    }

    int add(int val) {
        if(q.size() < k) {
            q.push(val);
        } else {
            if(q.top() < val) {
                q.pop();
                q.push(val);
            }
        }
        return q.top();
    }
};
