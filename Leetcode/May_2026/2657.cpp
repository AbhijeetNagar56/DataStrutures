class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> a;
        unordered_map<int, int> b;

        vector<int> C(A.size(), 0);

        if(A[0] == B[0]) {
            C[0] = 1;
        } else {
            a[A[0]]++;
            b[B[0]]++;
        }

        for(int i = 1; i < A.size(); i++) {
            int com = 0;

            if(b.find(A[i]) != b.end() && b[A[i]] != 0) {
                com++;
                b[A[i]]--;
            } else {
                a[A[i]]++;
            }

            if(a.find(B[i]) != a.end() && a[B[i]] != 0) {
                com++;
                a[B[i]]--;
            } else {
                b[B[i]]++;
            }


            C[i] = C[i - 1] + com;
        }

        return C;
    }
};