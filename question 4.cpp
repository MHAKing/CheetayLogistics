#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;


struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(meeting m1, meeting m2)
{
    return (m1.end < m2.end);
}

// Function for finding maximum meeting in one room
int maxMeeting(int s[], int f[], int n)
{
    meeting *meet = new meeting[n];

    for (int i = 0; i < n; i++)
    {
        // Starting time of meeting i.
        meet[i].start = s[i];

        // Finishing time of meeting i
        meet[i].end = f[i];

        // Original position/index of meeting
        meet[i].pos = i + 1;
    }

    // Sorting of meeting according to their finish time.
    sort(meet, meet + n, comparator);

    // Vector for storing selected meeting.
    vector<int> m;

    // Initially select first meeting.
    m.push_back(meet[0].pos);

    // time_limit to check whether new
    // meeting can be conducted or not.
    int time_limit = meet[0].end;

    // Check for all meeting whether it
    // can be selected or not.
    for (int i = 1; i < n; i++) {
        if (meet[i].start >= time_limit)
        {
            // Push selected meeting to vector
            m.push_back(meet[i].pos);

            // Update time limit.
            time_limit = meet[i].end;
        }
    }

    // Print final selected meetings.
    int totalmeeting = 0;

    totalmeeting = m.size();
    delete[] meet;
    return totalmeeting;
}


int main()
{
    // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };

    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };

    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);

    // Function call
    cout <<endl << maxMeeting(s, f, n) <<endl;

    return 0;
}