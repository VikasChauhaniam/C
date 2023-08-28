#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Set the seed for reproducibility
    unsigned int seed1;

    cout<< "Enter Seed1 for range : ";
    cin>>seed1;

    std::mt19937 rng(seed1);

    int min_value = 5;
    int max_value = 10;

    // Define the distribution
    std::uniform_int_distribution<int> dist(min_value, max_value);

    // Generate and print random integer
    int random_int = dist(rng);

    cout << "random int is : " << random_int<<endl;

    int* operationArray = new int[random_int]; 

    int seed2;
    cout << "Enter a seed2 value for 012: ";
    cin >> seed2;

    srand(seed2); // Set the seed for the random number generator

    // Fill the array with random values of 0, 1, and 2
    for (int i = 0; i < random_int; ++i) {
        operationArray[i] = rand() % 3; // Generate a random value between 0 and 2
    }

    // Display the array elements
    cout << "Array elements: ";

    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < random_int; ++i) {
        cout << operationArray[i] << " ";
        if (operationArray[i]  == 0) {
            count0++;
        } else if (operationArray[i]  == 1) {
            count1++;
        } else if (operationArray[i]  == 2) {
            count2++;
        }
    }
    cout << endl;

    std::cout << "Count of 0s: " << count0 << std::endl;
    std::cout << "Count of 1s: " << count1 << std::endl;
    std::cout << "Count of 2s: " << count2 << std::endl;

    int* searchArray = new int[count0];
    int* insertArray = new int[count1];
    int* deleteArray = new int[count2]; 

    for (int i = 0; i < count0; ++i) {
        searchArray[i] = rand() % 100; // Generate a random value between 0 and 99
        
    }

    cout << "--------------------------SearchArray-----------------"<<endl;
    for (int i = 0; i < count0; ++i) {
        cout << searchArray[i] << " ";  
    }

     for (int i = 0; i < count1; ++i) {
        insertArray[i] = rand() % 100; // Generate a random value between 0 and 99
    }cout<<endl;

    cout << "--------------------------InsertArray-----------------"<<endl;
    for (int i = 0; i < count1; ++i) {
        cout << insertArray[i] << " ";  
    }

     for (int i = 0; i < count2; ++i) {
        deleteArray[i] = rand() % 100; // Generate a random value between 0 and 99
    }cout<<endl;

    cout << "--------------------------DeleteArray-----------------"<<endl;
    for (int i = 0; i < count2; ++i) {
        cout << deleteArray[i] << " ";  
    }cout<<endl;



//---------------------------------------------------------------HERE WE CAN ADD OUR CALLING FXNS-------------------------
    for (int i = 0; i < random_int; ++i) {
        if (operationArray[i]  == 0) {
            //SearchFUNCTION(searchArray[i])
        } else if (operationArray[i]  == 1) {
            //InsertFUNCTION(insertArray[i])
        } else if (operationArray[i]  == 2) {
            //DeletionFUNCTION(deletionArray[i])
        }
    }

    // Don't forget to delete the dynamically allocated array
    delete[] operationArray;

    return 0;
}
