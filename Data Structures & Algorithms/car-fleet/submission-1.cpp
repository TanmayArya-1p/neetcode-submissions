class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 1;

        int n = position.size();

        vector<pair<int,int>> cars;
        cars.reserve(n);
        for(int i =0 ;i <n ;i++) cars.emplace_back(position[i],speed[i]);


        sort(cars.begin(), cars.end() , [](const auto &a, const auto&b) -> bool {
            return (a.first < b.first);
        });

        int term = n-1;
        for (int i = n-2; i>=0; i--) {
            // check if this car will reach the car ahead before target

            // B->    A->
            // (b-a)>0 && (b-a)*d > deltad*a

            // db/b <= da/a

            int db = target-cars[i].first;
            int a = cars[term].second;
            int b = cars[i].second;
            int da = target-cars[term].first;

            if (b<a || !(db*a <= da*b)) {
                ans+=1;
                term=i;
            }
        }
        return ans;
    }
};
