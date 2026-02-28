//Course Schedule
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }
        
        vector<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.push_back(i);
            }
        }
        
        int count = 0;
        while (!queue.empty()) {
            int course = queue.back();
            queue.pop_back();
            count++;
            
            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    queue.push_back(nextCourse);
                }
            }
        }
        
        return count == numCourses;
    }
};
int main() {
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool result = solution.canFinish(numCourses, prerequisites);
    cout << "Can finish courses: " << (result ? "Yes" : "No") << endl; // Output: Yes
    return 0;
}
