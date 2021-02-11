// Given a signed 32 bit integer, reverse it. 
// If the process verflows 32 bits, return 0
// O(logn) time, constant space, where n is thr number of digits in x, roughly
#include <limits>

int reverse(int x) {
        int res = 0;

        while(abs(x) > 0) {
            
            int smallest = x % 10;
            x /= 10;
                
            if(res > INT_MAX/10) {
                //std::cout << "Halting" << std::endl;
                return 0;
            }
            if(res < INT_MIN/10) {
                //std::cout << "Halting" << std::endl;
                return 0;
            }
            
            res *= 10;
            res += smallest;
        }
        
        return res;
    }