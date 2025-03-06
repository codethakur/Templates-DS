class QuickFindUF {
private:
    std::vector<int> id;
public:
    QuickFindUF(int n) {
        id.resize(n);
        for (int i = 0; i < n; i++) id[i] = i;
    }
    int Find(int x) { return id[x]; }
    void Union(int x, int y) {
        int oldID = id[y], newID = id[x];
        for (int i = 0; i < id.size(); i++)
            if (id[i] == oldID) id[i] = newID;
    }
};
/*
    Time Complexity:
    Find(x): O(1)
    Union(x, y): O(n)
*/
