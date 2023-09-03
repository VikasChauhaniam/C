#include <iostream>
#include <vector>

using namespace std;

// Define the number of processes and resource types
const int numProcesses = 4;
const int numResources = 4;

// Define the maximum resource need for each process
//---------------------------------------------------------------------------------------------
int maxMatrix[numProcesses][numResources] = {
    {4,4,4,4},
    {3,3,3,3},
    {2,1,1,1},
    {2,2,2,2}
};

// Define the currently allocated resources for each process
int allocationMatrix[numProcesses][numResources] = {
    {2,4,3,0},
    {2,3,1,1},
    {2,0,0,0},
    {1,2,1,2}
};

// Define the available resources
int availableResources[numResources] = {1,1,1,1};






//---------------------------------------------------------------------------------------------
// int maxMatrix[numProcesses][numResources] = {
//     {7, 5, 3},
//     {3, 2, 2},
//     {9, 0, 2}
// };

// // Define the currently allocated resources for each process
// int allocationMatrix[numProcesses][numResources] = {
//     {0, 1, 0},
//     {2, 0, 0},
//     {3, 0, 2}
// };

// // Define the available resources
// int availableResources[numResources] = {3, 3, 2};

bool isSafe(int process, vector<bool>& finish) {
    // Check if the process can finish safely
    for (int i = 0; i < numResources; ++i) {
        if (maxMatrix[process][i] - allocationMatrix[process][i] > availableResources[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<bool> finish(numProcesses, false);
    int processesToRelease[numProcesses];
    int numProcessesToRelease = 0;
    bool deadlock = false;

    while (numProcessesToRelease < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; ++i) {
            if (!finish[i] && isSafe(i, finish)) {
                // Release resources of the process
                for (int j = 0; j < numResources; ++j) {
                    availableResources[j] += allocationMatrix[i][j];
                    allocationMatrix[i][j] = 0;
                }
                finish[i] = true;
                processesToRelease[numProcessesToRelease++] = i;
                found = true;
            }
        }
        if (!found) {
            cout << "System is in deadlock state." << endl;
            deadlock = true;
            break;
        }
    }

    if (deadlock) {
        // Resolve deadlock by terminating one process
        int processToTerminate = 0; // You can implement a strategy to choose which process to terminate
        cout << "Terminating Process P" << processToTerminate << " to resolve the deadlock." << endl;
    } else {
        cout << "System is in safe state. Safe sequence: ";
        for (int i = 0; i < numProcesses; ++i) {
            cout << "P" << processesToRelease[i];
            if (i < numProcesses - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}
