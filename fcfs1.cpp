#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Task {
    std::string identifier;
    int initiateTime;
    std::vector<int> burstTime;
    std::vector<int> remainingBurstTime;

    int terminationTime;
    int currentIndex;
};

std::vector<Task> taskList;

Task generateTask(std::string line) {
    std::istringstream ss(line);
    std::vector<std::string> tokens;
    std::string token;
    
    while (ss >> token) {
        tokens.push_back(token);
    }

    Task newTask;
    newTask.identifier = tokens[0];
    newTask.initiateTime = std::stoi(tokens[1]);

    for (size_t i = 2; i < tokens.size(); ++i) {
        newTask.burstTime.push_back(std::stoi(tokens[i]));
        newTask.remainingBurstTime.push_back(std::stoi(tokens[i]));
    }

    newTask.terminationTime = -1;
    newTask.currentIndex = 0;

    return newTask;
}

int main() {
    std::ifstream input("input1.txt");
    std::string line;
    
    while (std::getline(input, line)) {
        Task newTask = generateTask(line);
        taskList.push_back(newTask);
    }
    
    input.close();

    std::sort(taskList.begin(), taskList.end(), [](const Task& a, const Task& b) {
        return a.initiateTime < b.initiateTime;
    });

    std::vector<int> IOQueue, readyQueue;
    int currentTime = 0, completedTaskCount = 0, nextTaskIndex = 0;

    while (completedTaskCount < taskList.size()) {
        if (!IOQueue.empty() && !taskList[IOQueue[0]].remainingBurstTime[taskList[IOQueue[0]].currentIndex]) {
            if (taskList[IOQueue[0]].remainingBurstTime.size() - 1 == taskList[IOQueue[0]].currentIndex) {
                taskList[IOQueue[0]].terminationTime = currentTime;
                IOQueue.erase(IOQueue.begin());
                completedTaskCount++;
            } else {
                taskList[IOQueue[0]].currentIndex++;
                readyQueue.push_back(IOQueue[0]);
                IOQueue.erase(IOQueue.begin());
            }
        }

        if (!readyQueue.empty() && !taskList[readyQueue[0]].remainingBurstTime[taskList[readyQueue[0]].currentIndex]) {
            if (taskList[readyQueue[0]].remainingBurstTime.size() - 1 == taskList[readyQueue[0]].currentIndex) {
                taskList[readyQueue[0]].terminationTime = currentTime;
                readyQueue.erase(readyQueue.begin());
                completedTaskCount++;
            } else {
                taskList[readyQueue[0]].currentIndex++;
                IOQueue.push_back(readyQueue[0]);
                readyQueue.erase(readyQueue.begin());
            }
        }

        if (!IOQueue.empty()) {
            taskList[IOQueue[0]].remainingBurstTime[taskList[IOQueue[0]].currentIndex]--;
        }

        while (nextTaskIndex < taskList.size() && taskList[nextTaskIndex].initiateTime == currentTime) {
            readyQueue.push_back(nextTaskIndex);
            nextTaskIndex++;
        }

        if (!readyQueue.empty()) {
            taskList[readyQueue[0]].remainingBurstTime[taskList[readyQueue[0]].currentIndex]--;
            
        }

        currentTime++;
    }

    float tat = 0, wat =0;

    std::cout << "Task " ;
    std::cout<< "\t Arri_Time: " ; 
    std::cout<< "\t Exit_Time: " ; 
    std::cout<< "\t TurnAroudT: " ; 
    std::cout<< "\t WaitTime: " ;  
    std::cout<< "\t IO_Time: " ; 
    std::cout<< "\t CPU_Time: " << std::endl ; 

    for (const Task& t : taskList) {
        int ioTime = 0, cpuTime = 0;
        for(int i=0; i<t.burstTime.size(); i++){
            if(i%2) ioTime += t.burstTime[i];
            else cpuTime += t.burstTime[i];
        }
        std::cout << t.identifier << "\t";
        std::cout << "\t" << t.initiateTime << "\t";
        std::cout << "\t" << t.terminationTime << "\t";
        std::cout << "\t" << t.terminationTime - t.initiateTime << "\t";
        std::cout << "\t" << t.terminationTime - t.initiateTime - cpuTime << "\t";
        std::cout << "\t" << cpuTime << "\t";
        std::cout << "\t" << ioTime << std::endl;

        tat += (t.terminationTime - t.initiateTime);
        wat += (t.terminationTime - t.initiateTime - cpuTime);
    }
    std::cout << "avg tat : " << tat / taskList.size() << std::endl;
    std::cout << "avg wat : " << wat / taskList.size() << std::endl << std::endl;

    return 0;
}