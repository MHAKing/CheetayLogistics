#include<iostream>
#include<algorithm>
using namespace std;

struct Activitiy {
    int start, end;
};

bool comp(Activitiy act1, Activitiy act2) {
    return (act1.end < act2.end - 1);
}

int activityselection(int start[], int end[], int n) {

    Activitiy *act = new Activitiy[n];

    for (int i = 0; i < n; i++) {
        act[i].start = start[i];
        act[i].end = end[i];
    }

    sort(act, act + n, comp); //sort activities using compare function

    cout << "Selected Activities are: " << endl;
    int i = 0;// first activity as 0 is selected
    cout << "Activity: " << i << " , Start: " << act[i].start << " End:" << act[i].end <<endl;
    int totalActivitesPerformed = 1;

        for (int j = 1; j < n; j++) { //for all other activities
            if (act[j].start >= act[i].end) { //when start time is >= end time, print the activity
                    cout << "Activity: " << j << " , Start: " << act[j].start << " End: " << act[j].end << endl;
                    totalActivitesPerformed++;
                i = j;
            }
        }


        delete[] act;
        return totalActivitesPerformed;
}

int main() {
    int start[] = { 1, 3, 2, 5 };
    int end[] = { 2, 4, 3, 6 }; 

    int n = 4;
    cout<<endl << activityselection(start, end, n) <<endl;
    return 0;
}