#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        double d = (double)n/2;
        
        if (d == 2 || (double)n == 1){
            return true;
        }
        
        if (d != (int)d || d == 0){ 
            return false;
        }
        
        return isPowerOfTwo(n/2);
    }
};
