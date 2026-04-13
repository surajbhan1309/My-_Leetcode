class Solution {
public:
    const int N = 100005;
    vector<bool> sieve;

    void buildSieve() {
        sieve.assign(N, false);
        sieve[0] = sieve[1] = true;

        for (int i = 2; i * i < N; i++) {
            if (!sieve[i]) {
                for (int j = i * i; j < N; j += i) {
                    sieve[j] = true;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        buildSieve();

        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (i % 2 == 0) {
                // need prime
                while (sieve[x]) {
                    x++;
                    res++;
                }
            } else {
                // need non-prime
                while (!sieve[x]) {
                    x++;
                    res++;
                }
            }
        }

        return res;
    }
};