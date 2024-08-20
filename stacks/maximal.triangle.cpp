class Solution {

public:

    int maxInHistogram(vector<int>& arr) {

        int n = arr.size();

        int maxi = 0;

        stack<int> st;

        arr.push_back(0);  



        for (int i = 0; i < arr.size(); ++i) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {

                int height = arr[st.top()];

                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxi = max(maxi, height * width);

            }

            st.push(i);

        }

        return maxi;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int r = matrix.size();

        if(r == 0) return 0;

        int c = matrix[0].size();



        vector<int> ps(c,0);

        int maxi = 0;



        for(int i = 0; i < r; ++i){

            for(int j = 0; j < c; ++j){

                if(matrix[i][j] == '1') ps[j]++;

                if(matrix[i][j] == '0') ps[j] = 0;

            }

            maxi = max(maxi, maxInHistogram(ps));

        }

        return maxi;

    }







};
