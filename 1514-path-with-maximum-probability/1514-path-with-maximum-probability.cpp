class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        // Priority queue for the Dijkstra-like traversal
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currNode == end_node) {
                return currProb;
            }

            for (auto& neighbor : graph[currNode]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currProb * edgeProb;

                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        return 0.0;
        
    }
};