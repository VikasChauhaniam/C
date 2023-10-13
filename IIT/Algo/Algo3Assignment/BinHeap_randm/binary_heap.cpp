#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <chrono>
#include <fstream>
using namespace std;

void insert(vector<int> &heap, int x) 
{
    heap.push_back(x);
    int index = heap.size() - 1;
    while (index >= 1) 
    {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) 
        {
            swap(heap[parent], heap[index]);
            index = parent;
        } 
        else 
        {
            break;
        }
    }
}

void extract_min(vector<int> &heap) 
{
    if (heap.empty()) 
    {
        //cout << "Heap is empty in extract_min" << endl;
        return;
    }

    int size = heap.size();
    swap(heap[0], heap[size - 1]);
    heap.pop_back();
    size = heap.size();

    int index = 0;
    while (index < size / 2) 
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < size && (heap[index] > heap[left] || (right < size && heap[index] > heap[right] && heap[left] > heap[right]))) 
        {
            swap(heap[index], heap[left]);
            index = left;
        } 
        else if (right < size && heap[index] > heap[right]) 
        {
            swap(heap[index], heap[right]);
            index = right;
        } 
        else 
        {
            break;
        }
    }
}

void decrease_key(vector<int> &heap, int index, int x) 
{
    if (heap.empty()) 
    {
        //cout << "Heap is empty in decrease_key" << endl;
        return;
    }

    if (index < 0 || index >= heap.size()) 
    {
        //cout << "Invalid index in decrease_key" << endl;
        return;
    }

    heap[index] = x;
    while (index >= 1) 
    {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) 
        {
            swap(heap[parent], heap[index]);
            index = parent;
        } 
        else 
        {
            break;
        }
    }
}

void print(vector<int> heap) {
    if (heap.empty()) {
        cout << "Heap is empty" << endl;
        return;
    }
    for (int i = 0; i < heap.size(); i++) 
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> heap;
    int ti[10] = {0} ;
    int datai[10] = {0} ;
    srand(time(0));
    int random_int = rand() % 10; // Change this to the desired number of operations

	for(int k = 0 ; k < 10 ; k++)
	{
		cout << "Random integer is - " << random_int << endl ;
		auto start_time = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < random_int; i++) 
		{
		    int operation = rand() % 4; // Generate a random operation

		    if (operation == 0) 
		    {
		        int value = rand() % 100; // Generate a random value to insert
		        //cout << "Inserting value: " << value << endl;
		        insert(heap, value);
		    } 
		    else if (operation == 1 && !heap.empty()) 
		    {        
		        //cout << "Extracting min" << endl;
		        extract_min(heap);
		    } else if (operation == 2 && !heap.empty()) 
		    {
		        int index = rand() % heap.size(); // Generate a random index to delete
		        //cout << "Deleting value at index " << index << endl;
		        decrease_key(heap, index, INT_MIN);
		        extract_min(heap);
		    } 
		    else if (operation == 3 && !heap.empty()) 
		    {
		        int index = rand() % heap.size(); // Generate a random index to decrease
		        int value = rand() % 100; // Generate a random value to set
		        //cout << "Decreasing value at index " << index << " to " << value << endl;
		        decrease_key(heap, index, value);
		    }

		    //cout << "Heap: ";
		    //print(heap);
		}
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
		ti[k] = duration.count() ;
        datai[k] = random_int;
		random_int += 200 ;
	}
	
	cout << "Time array : \n" ;
	for(int i = 0 ; i < 10 ; i++)
	{
		cout << ti[i] << " " << "milisec" << "\n" ;
	}
	
	ofstream myfile ("Binary_Heap.txt");
    if (myfile.is_open())
    {
        for(int count = 0; count < 10; count ++)
        {
            myfile << ti[count] << " ";
        }
        myfile << "\n" ;
        for(int count = 0; count < 10; count ++)
        {
            myfile << datai[count] << " ";
        }
        myfile << "\n" ;
        myfile.close();
    }
    else 
    	cout << "Unable to open file";
	
    return 0;
}

