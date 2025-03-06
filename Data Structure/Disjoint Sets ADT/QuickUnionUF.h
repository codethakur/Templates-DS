class QuickUnionUF {
private:
    std::vector<int> parent;
public:
    QuickUnionUF(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) parent[rootY] = rootX;
    }
};


/*
Time Complexity:

Find(x): O(n) (in the worst case, the tree can be skewed)
Union(x, y): O(1)
*/
