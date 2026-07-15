// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_set<string> Set;

//         set<string> ans;

//         if(s.length() <= 10) return vector<string> (ans.begin(), ans.end());;

//         for(int i=0; i<s.length(); i++) {
//             string curr = s.substr(i, 10);
//             if(Set.find(curr) != Set.end()) {
//                 ans.insert(curr);
//             } else {
//                 Set.insert(curr);
//             }
//         }

//         return vector<string> (ans.begin(), ans.end());
//     }
// };


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10) return {};

        int mask[26];
        mask['A' - 'A'] = 0; // 00
        mask['C' - 'A'] = 1; // 01
        mask['G' - 'A'] = 2; // 10
        mask['T' - 'A'] = 3; // 11

        unordered_set<int> seen;
        unordered_set<string> ans;
        
        int bitmask = 0;
        for (int i = 0; i < 9; i++) {
            bitmask = (bitmask << 2) | mask[s[i] - 'A'];
        }

        for (int i = 9; i < s.length(); i++) {
            bitmask = ((bitmask << 2) | mask[s[i] - 'A']) & 0xFFFFF;
            
            if (seen.count(bitmask)) {
                ans.insert(s.substr(i - 9, 10));
            } else {
                seen.insert(bitmask);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};