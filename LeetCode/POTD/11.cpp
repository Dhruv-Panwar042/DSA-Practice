class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;

        int sum = 0;
        int product = 1;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        n = original;  

        while(n > 0) {
            product *= n % 10;
            n /= 10;
        }

        int finalSum = sum + product;

        return original % finalSum == 0;
    }
};