#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int maxradius =0;
        for(int house : houses){
            auto it = lower_bound(heaters.begin() , heaters.end() , house);
            int dist1 = INT_MAX;
            int dist2 = INT_MAX;
            if(it != heaters.end())
            dist1 =abs(*it-house);
            if(it != heaters.begin())
            {
                --it;
                dist2 = abs(*it-house);
            }
            int nearestDist = min(dist1, dist2);
            maxradius = max(maxradius , nearestDist);
        }
        return maxradius;
    }
};
int main(){
    Solution s;
    vector<int> houses={1,2,3,4};
    vector<int> heaters={1,4};
    cout<<s.findRadius(houses,heaters)<<endl;
}