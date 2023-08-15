#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void FCFS_Scheduling(int num_processes, int arrival_times[], int cpu_burst_times[][3], int io_burst_times[][2]) {
    queue<Process> ready_queue;
    int current_time = 0;

    Process processes[num_processes];

    for (int i = 0; i < num_processes; i++) {
        processes[i].process_id = i + 1;
        processes[i].arrival_time = arrival_times[i];
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
        processes[i].response_time = -1; // Initialize response time as -1

        while (current_time < arrival_times[i]) {
            cout << "Time " << current_time << ": Idle" << endl;
            current_time++;
        }

        if (processes[i].response_time == -1) {
            processes[i].response_time = current_time - processes[i].arrival_time;
        }

        cout << "Time " << current_time << ": Process " << i + 1 << " started" << endl;

        for (int j = 0; j < 3; j++) { // Assuming each process has 3 CPU and I/O bursts
            current_time += cpu_burst_times[i][j];
            cout << "Time " << current_time << ": Process " << i + 1 << " CPU burst " << j + 1 << " completed" << endl;

            if (j < 3) {
                current_time += io_burst_times[i][j];
                cout << "Time " << current_time << ": Process " << i + 1 << " entered I/O burst " << j + 1 << endl;
            }
        }

        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - (3 * 3); // Total burst time

        cout << "Process " << i + 1 << " completed at time " << processes[i].completion_time << endl;
        cout << "Turnaround Time for Process " << i + 1 << ": " << processes[i].turnaround_time << endl;
        cout << "Waiting Time for Process " << i + 1 << ": " << processes[i].waiting_time << endl;
        cout << "Response Time for Process " << i + 1 << ": " << processes[i].response_time << endl;
    }
}

int main() {
    int num_processes = 3;

    int arrival_times[] = {2,3,1};

    int cpu_burst_times[][3] = {
        {1,2,3},
        {1,3,2},
        {3,1,2}
    };

    int io_burst_times[][2] = {
        {2,1},
        {1,1},
        {1,2}
    };

    FCFS_Scheduling(num_processes, arrival_times, cpu_burst_times, io_burst_times);

    return 0;
}
