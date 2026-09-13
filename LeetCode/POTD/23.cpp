class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int answer = 0;

        // Try every possible row shift
        for (int rowShift = -(n - 1);
             rowShift <= n - 1;
             rowShift++) {

            // Try every possible column shift
            for (int colShift = -(n - 1);
                 colShift <= n - 1;
                 colShift++) {

                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        int x = i + rowShift;
                        int y = j + colShift;

                        // Check whether the shifted position
                        // is inside img2
                        if (x >= 0 && x < n &&
                            y >= 0 && y < n) {

                            if (img1[i][j] == 1 &&
                                img2[x][y] == 1) {

                                overlap++;
                            }
                        }
                    }
                }

                answer = max(answer, overlap);
            }
        }

        return answer;
    }
};