//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    struct Meeting{
        int start;
        int end ;
        int pos;
        
    };
    // bool meetingcomp(Meeting m1, Meeting m2){
    //     if(m1.end<m2.end){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }
    
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector <Meeting> meet(n);
        for(int i = 0; i<n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        
        }
        sort(meet.begin(), meet.end(), [](Meeting m1, Meeting m2) {
            return m1.end < m2.end;
        });
        int freetime = meet[0].end;
          int cnt = 1;
       
        for(int i = 1; i<n; i++){
            if(meet[i].start>freetime){
                cnt ++;
                freetime = meet[i].end;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
