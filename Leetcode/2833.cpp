class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l_count = 0;
        int r_count = 0;

        for (int i = 0; i < moves.size(); i++) {
            if(moves.at(i) == 'L') l_count++;
            if(moves.at(i) == 'R') r_count++;         
        }
        
        char least = l_count < r_count ? 'L' : 'R';

        int dist = 0;
        for (int i = 0; i < moves.size(); i++) {
            if(moves.at(i) == least) {
                dist--;
            } else {
                dist++;
            }      
        }

        return dist;
    }
};