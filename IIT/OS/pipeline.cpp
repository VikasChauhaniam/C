#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.first < b.first;
}

int main() {
    queue<pair<string, int>> chassis, tyre, door, engine;
    bool lock1 = true, lock2 = true, lock3 = true;

    int time = 0, duration = 10, completedCar = 0, n;
    cout << "Enter the number of car: ";
    cin >> n;
    vector<pair<string,int>> chassisCompTime, tyreCompTime, doorCompTime, engineCompTime;

    for(int i = 0; i < n; i++) {
        string temp = "Car" + to_string(i+1);
        chassis.push({temp, duration});
    }

    while(completedCar < n) {
        #pragma omp parallel
        {
            int thread_num = omp_get_thread_num();
            if(thread_num == 0) {
                if(!chassis.empty()) {
                    if(chassis.front().second) chassis.front().second--;

                    while(lock1);
                    lock1 = true;

                    if(!chassis.front().second) {
                        tyre.push({chassis.front().first, duration});
                        chassisCompTime.push_back({chassis.front().first, time+1});
                        chassis.pop();
                    }
                }
            }
            if(thread_num == 1) {
                if(!tyre.empty()) {
                    if(tyre.front().second) tyre.front().second--;

                    lock1 = false;

                    while(lock2);
                    lock2 = true;

                    if(!tyre.front().second) {
                        door.push({tyre.front().first, duration});
                        tyreCompTime.push_back({tyre.front().first, time+1});
                        tyre.pop();
                    }
                } else {
                    lock1 = false;
                }
            }
            if(thread_num == 2) {
                if(!door.empty()) {
                    if(door.front().second) door.front().second--;

                    lock2 = false;

                    while(lock3);
                    lock3 = true;

                    if(!door.front().second) {
                        engine.push({door.front().first, duration});
                        doorCompTime.push_back({door.front().first, time+1});
                        door.pop();
                    }
                } else {
                    lock2 = false;
                }
            }
            if(thread_num == 3) {
                if(!engine.empty()) {
                    if(engine.front().second) engine.front().second--;

                    lock3 = false;

                    if(!engine.front().second) {
                        engineCompTime.push_back({engine.front().first, time+1});
                        engine.pop();
                        completedCar++;
                    }
                } else {
                    lock3 = false;
                }
            }
        }
        #pragma omp barrier
        time++;
    }

    sort(chassisCompTime.begin(), chassisCompTime.end(), comp);
    sort(tyreCompTime.begin(), tyreCompTime.end(), comp);
    sort(doorCompTime.begin(), doorCompTime.end(), comp);
    sort(engineCompTime.begin(), engineCompTime.end(), comp);

    for(int i = 0; i < n; i++) {
        cout << chassisCompTime[i].first << " Chassi :" << chassisCompTime[i].second << endl;
        cout << tyreCompTime[i].first << " Tyre :" << tyreCompTime[i].second << endl;
        cout << doorCompTime[i].first << " Door :" << doorCompTime[i].second << endl;
        cout << engineCompTime[i].first << " Engine :" << engineCompTime[i].second << endl;

        cout << endl;
    }
    cout << endl;

    return 0;
}

