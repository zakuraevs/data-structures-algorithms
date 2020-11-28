// Given a meeting Class
// and a bunch of unordered meetings
// merge the overlapped ones

#include <iostream>
#include <vector>


using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};

bool compareMeetingsByStartTime(
    const Meeting& firstMeeting,
    const Meeting& secondMeeting)
{
    return firstMeeting.getStartTime() < secondMeeting.getStartTime();
}

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    // merge meeting ranges
    std::vector<Meeting> res;
    int len = meetings.size();
    
    // O(n) space
    std::vector<Meeting> temp(meetings);
    
    // O(nlogn time)
    std::sort(temp.begin(), temp.end(), compareMeetingsByStartTime);
    
    for(int i=0; i<len;i++){
        unsigned int current_end = temp[i].getEndTime();
        int initial_end = current_end;
        int j=i;
        while(j<len&&temp[j].getStartTime() <= current_end){
            unsigned int new_end = temp[j].getEndTime();
            current_end = max(current_end, new_end);
            j++;
        }
        int latest_end = temp[j-1].getEndTime();
        res.push_back(Meeting(temp[i].getStartTime(), max(latest_end, initial_end)));
        i=j-1;
    }
    
    return res;
}