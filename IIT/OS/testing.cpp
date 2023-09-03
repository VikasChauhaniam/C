#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Structure to represent a resource
struct Resource {
    int id;
    int instances;
};

// Structure to represent a process
struct Process {
    int id;
    vector<int> allocated_resources;
};

class DeadlockDetector {
private:
    vector<Process> processes;
    vector<Resource> resources;
    unordered_map<int, int> available_resources;

public:
    DeadlockDetector(vector<Process> processes, vector<Resource> resources) 
        : processes(processes), resources(resources) {
        for (const auto& resource : resources) {
            available_resources[resource.id] = resource.instances;
        }
    }

    bool isSafe() {
        vector<bool> finished(processes.size(), false);
        vector<int> work = available_resources;

        while (true) {
            bool found = false;
            for (int i = 0; i < processes.size(); ++i) {
                if (!finished[i]) {
                    bool canExecute = true;
                    for (const int& res_id : processes[i].allocated_resources) {
                        if (work[res_id] <= 0) {
                            canExecute = false;
                            break;
                        }
                    }

                    if (canExecute) {
                        for (const int& res_id : processes[i].allocated_resources) {
                            work[res_id] += resources[res_id].instances;
                        }
                        finished[i] = true;
                        found = true;
                    }
                }
            }

            if (!found) {
                for (bool finish : finished) {
                    if (!finish) {
                        return false;  // Deadlock detected
                    }
                }
                return true;  // No deadlock detected
            }
        }
    }

    void applyDeadlockResolution(int process_id) {
        cout << "Terminating Process " << process_id << " to resolve deadlock." << endl;
        for (int& res_id : processes[process_id].allocated_resources) {
            available_resources[res_id] += resources[res_id].instances;
        }
        processes.erase(processes.begin() + process_id);
    }
};

int main() {
    // Define resources and processes
    vector<Resource> resources = { {0, 1}, {1, 1}, {2, 2} };
    vector<Process> processes = {
        {0, {0, 1}},
        {1, {2}},
        {2, {2}},
    };

    // Initialize the deadlock detector
    DeadlockDetector detector(processes, resources);

    // Check for deadlock
    if (detector.isSafe()) {
        cout << "No deadlock detected." << endl;
    } else {
        cout << "Deadlock detected. Applying resolution strategy." << endl;
        // In this simplified example, we terminate the first process.
        detector.applyDeadlockResolution(0);
        cout << "Resolution completed." << endl;
    }

    return 0;
}
