class Solution {
private:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        unordered_map<int, vector<int>> graph;
        
        for (const auto& cond : conditions) {
            graph[cond[0]].push_back(cond[1]);
            ++inDegree[cond[1]];
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for (int neighbor : graph[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (order.size() != k) {
            return {};
        }
        
        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPos, colPos;
        
        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }
        
        for (int num = 1; num <= k; ++num) {
            matrix[rowPos[num]][colPos[num]] = num;
        }
        
        return matrix;
        
    }
};