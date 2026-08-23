class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int leftUnknown = 0;
        int rightUnknown = 0;

        // Calculate the current digit difference and count unknowns.
        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') {
                ++leftUnknown;
            } else {
                diff += num[i] - '0';
            }
        }

        for (int i = half; i < n; ++i) {
            if (num[i] == '?') {
                ++rightUnknown;
            } else {
                diff -= num[i] - '0';
            }
        }

        // If the numbers of unknowns are unequal, the unmatched move
        // gives Alice an advantage. The extra unknowns affect the score
        // by at least 9, while paired moves cancel around an average of 4.5.
        if ((leftUnknown - rightUnknown) % 2 != 0) {
            return true;
        }

        // Normalize the difference based on the extra unknown positions.
        int remaining = leftUnknown - rightUnknown;
        diff += (remaining / 2) * 9;

        // Alice wins unless Bob can make the final sums equal.
        return diff != 0;
    }
};