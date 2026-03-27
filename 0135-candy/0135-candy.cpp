class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int candy = 1; // first child gets 1 candy

        while (i < n) {
            // Case 1: equal ratings
            if (ratings[i] == ratings[i - 1]) {
                candy += 1;
                i++;
                continue;
            }

            // Case 2: increasing (peak)
            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candy += (1 + peak);
                i++;
            }

            // Case 3: decreasing (dip)
            int dip = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                dip++;
                candy += (1 + dip);
                i++;
            }

            // adjust overlap
            candy -= min(peak, dip);
        }

        return candy;
    }
};