//Car Fleet
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) {
            double time = static_cast<double>(target - position[i]) / speed[i];
            cars.emplace_back(position[i], time);
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0.0;

        for (const auto& car : cars) {
            if (car.second > lastTime) {
                ++fleets;
                lastTime = car.second;
            }
        }

        return fleets;
    }
};
int main(){
    Solution obj;
    int target=12;
    vector<int> position={10,8,0,5,3};
    vector<int> speed={2,4,1,1,3};
    cout<<obj.carFleet(target,position,speed)<<endl; //Output: 3
    return 0;
}
