class Solution {
    unordered_map<int, vector<int>> graph;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);
        for(int i =0 ; i < numCourses ; i++ ){
            graph[i] = {};
        };

        for(auto p : prerequisites){
            graph[p[0]].push_back(p[1]);
        };

        for(int i =0 ; i < numCourses; i++){
            if(!vis[i]){
                if(cycleDFS(i, vis, recPath)){
                    return false;
                }
            }
        }
        return true;
    }

    bool cycleDFS(int cur, vector<bool>&vis,vector<bool>&recPath ){
        vis[cur] = true;
        recPath[cur] = true;

        for(auto g : graph[cur]){
            if(!vis[g]){
                if(cycleDFS(g, vis, recPath)){
                    return true;
                }
            }else if(recPath[g]){
                return true;
            }
        }

        recPath[cur] = false;

        return false;
    }
};