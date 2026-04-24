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

// less variable optimized version
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int blank_count = 0;
        int dist = 0;

        for (int i = 0; i < moves.size(); i++) {
            if(moves.at(i) == '_') {
                blank_count++;
            }else if(moves.at(i) == 'L') {
                dist--;
            } else {
                dist++;
            } 
        }

        return blank_count + abs(dist);
    }
};