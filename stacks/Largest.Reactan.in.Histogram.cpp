class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        s.push(-1);
        int max_area=0;

        for(int i=0; i<n; i++){
            while(s.top()!=-1 && heights[i]<= heights[s.top()]){
                int height = heights[s.top()];
                s.pop();
                int width = i-s.top()-1;
                max_area = max(max_area,height * width);
            }
            s.push(i);
        }
        while(s.top()!=-1){
            int height = heights[s.top()];
            s.pop();
            int width = heights.size()-s.top()-1;
            max_area = max(max_area,height* width);
        }
        return max_area;

    }
};
