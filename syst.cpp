//Minimum Index Sum of Two Lists
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> indexMap;
        for(int i=0;i<list1.size();i++){
            indexMap[list1[i]]=i;
        }
        vector<string> result;
        int minSum=INT_MAX;
        for(int j=0;j<list2.size();j++){
            if(indexMap.find(list2[j])!=indexMap.end()){
                int sumIndex=j+indexMap[list2[j]];
                if(sumIndex<minSum){
                    minSum=sumIndex;
                    result.clear();
                    result.push_back(list2[j]);
                } else if(sumIndex==minSum){
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
int main(){
    Solution obj;
    vector<string> list1={"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2={"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> result=obj.findRestaurant(list1,list2);
    for(const auto& res:result){
        cout<<res<<endl; //Output: Shogun
    }
    return 0;
}