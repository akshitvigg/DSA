class MyCalendarTwo {
    vector<pair<int,int>> doublebookings;
    vector<pair<int,int>> bookings;
public:
    bool checkOverlap(int start1,int end1, int start2, int end2){
        return max(start1, start2) < min(end1, end2);
    }
    pair<int, int> findoverlapregion(int start1,int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {}

    bool book(int start, int end) {
        for(pair<int, int>region : doublebookings){
            if(checkOverlap(region.first, region.second, start, end)){
                return false;
            }
        }

        for(pair<int,int>bookin : bookings){
            if(checkOverlap(bookin.first, bookin.second, start, end)){
                doublebookings.push_back(findoverlapregion(bookin.first, bookin.second, start, end));
            }
           
        }
         bookings.push_back({start,end});
            return true;
    }
};

