#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;


struct Job {
    Job() : nums(0), last_run(-1) {}
    size_t nums;
    int last_run;
};

struct JobComparator {
    constexpr bool operator()(const Job& lhs, const Job& rhs) const {
        return lhs.nums < rhs.nums;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<Job> wait_q;
        priority_queue<Job, vector<Job>, JobComparator> rq;

        map<char, Job> jobs;

        for(auto& c: tasks) {
            jobs[c].nums++;
        }

        for(auto& j: jobs) {
            rq.push(j.second);
        }

        int time = 0;
        while(!rq.empty() || !wait_q.empty()) {
            while(!wait_q.empty() && time - wait_q.front().last_run >= n) {
                auto waiting = wait_q.front();
                wait_q.pop();
                rq.push(waiting);
            }


            if(rq.empty()) {
                auto waiting = wait_q.front();
                wait_q.pop();
                time+= max(n - (time - waiting.last_run),0);
                rq.push(waiting);
            }

            auto curr = rq.top();
            rq.pop();
            time += 1;
            curr.nums--;
            if(curr.nums) {
                curr.last_run = time;
                wait_q.push(curr);
            }
        }
        return time;
    }
};
