class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true) {
            int x = n;
            int productt = 1;

            while(x > 0) {
                productt *= (x % 10);
                x /= 10;
            }

            if(productt % t == 0)
                return n;

            n++;
        }

    }
};