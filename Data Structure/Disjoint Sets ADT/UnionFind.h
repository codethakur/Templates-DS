//Fast UNION with Path Compression (Optimized Quick Union)
class UnionFind {
private:
    std::vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int x) {
        if (x != parent[x])
            parent[x] = Find(parent[x]); // Path Compression
        return parent[x];
    }
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


/*
Time Complexity (Almost Constant Time):

Find(x): O(α(n)), where α(n) is the inverse Ackermann function, which is nearly constant (≤ 5 for practical values).
Union(x, y): O(α(n)).
*/
