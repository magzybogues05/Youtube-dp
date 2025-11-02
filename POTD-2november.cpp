class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int totalEdgesPossible=(V*(V-1))/2;
        int alreadyEdges=edges.size();
        int edgesToAdd=totalEdgesPossible - alreadyEdges;
        return edgesToAdd;
    }
};
