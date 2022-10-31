#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector orig = s;
        
        for (int x = 0; x < s.size(); x++){
            if (x != 0){
                s[x] = orig[s.size()-(x+1)];
            } else {
                s[x] = s[s.size()-1];
            }
        }
    }
};
