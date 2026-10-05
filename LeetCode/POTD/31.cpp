class Solution {
public:
    int scoreOfParentheses(string s) {
        /* stack<char> st;
        int cnt = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }

            if(s[i] == ')' && st.top() == '(') {
                cnt++;
            }

            else {
                continue;
            }


        }

        return cnt; */

        stack<int> st;
        st.push(0);  // score of current level

        for(char ch : s) {
            if(ch == '(') {
                // Start a new nested level
                st.push(0);
            }

            else {
                int inner = st.top();
                st.pop();

                int score;

                if(inner == 0) {
                    // ()
                    score = 1;
                }

                else {
                    // (A)
                    score = 2 * inner;
                }

                st.top() += score;
            }
        }

        return st.top();
    }
};