#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, node*2, l, mid);
            build(arr, node*2+1, mid+1, r);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) { // not a leaf
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int l, int r, int L, int R, int val) {
        push(node, l, r);
        if (r < L || l > R) return; // no overlap
        if (L <= l && r <= R) {     // full overlap
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        updateRange(node*2, l, mid, L, R, val);
        updateRange(node*2+1, mid+1, r, L, R, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    long long queryRange(int node, int l, int r, int L, int R) {
        push(node, l, r);
        if (r < L || l > R) return 0; // no overlap
        if (L <= l && r <= R) return tree[node]; // full overlap
        int mid = (l + r) / 2;
        return queryRange(node*2, l, mid, L, R) +
               queryRange(node*2+1, mid+1, r, L, R);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    void update(int L, int R, int val) {
        updateRange(1, 0, n-1, L, R, val);
    }

    long long query(int L, int R) {
        return queryRange(1, 0, n-1, L, R);
    }
};


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree seg(arr);

    cout << seg.query(1, 3) << endl; // sum of arr[1..3] → 2+3+4 = 9

    seg.update(1, 3, 2);             // add 2 to arr[1..3]
    cout << seg.query(1, 3) << endl; // now → 4+5+6 = 15

    return 0;
}
