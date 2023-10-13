#include<iostream>
#include<vector>
#include <climits>
using namespace std ;

void insert(vector<int> &heap , int x)
{
	//insert element at end
	heap.push_back(x) ;

	//adjust the tree
	int index = heap.size()-1 ; 
	while(index >= 1)
	{
		int parent = (index-1)/2 ; 
		
		if(heap[parent] > heap[index])
		{
			int temp = heap[parent] ;
			heap[parent] = heap[index] ;
			heap[index] = temp ;
			index = parent ;
		}
		else
			return ;
	}
}

void extract_min(vector<int> &heap)
{
	//swap first node with last node
	int size = heap.size() ;

	//check for empty heap
	if(size == 0)
	{
		cout << "Heap is empty" << endl ;
		return ;
	}

	int temp = heap[0] ;
	heap[0] = heap[size-1] ;
	heap[size-1] = temp ;
	
	//pop last element
	heap.pop_back() ;
	size = heap.size() ;

	//adjust the tree
	int index = 0 ;
	
	while(index < (size/2))
	{
		int left = 2*index + 1 ;
		int right = 2*index + 2 ;
		if(left < size && (heap[index] > heap[left] || heap[index] > heap[right]) && (heap[left] < heap[right])) 
		{
			int t = heap[index] ;
			heap[index] = heap[left] ;
			heap[left] = t ; 
			index = left ;
		} 
		else if(right < size && (heap[index] > heap[left] || heap[index] > heap[right]) && (heap[left] > heap[right]))
		{
			int t = heap[index] ;
			heap[index] = heap[right] ;
			heap[right] = t ; 
			index = right ;
		}
		else
			return ;
	}
	return ;
}

void decrease_key(vector<int> &heap , int index , int x)
{
	if(index >= heap.size())
		return ;
	heap[index] = x ;

	//adjust the tree
	while(index >= 1)
	{
		int parent = (index-1)/2 ; 
		
		if(heap[parent] > heap[index])
		{
			int temp = heap[parent] ;
			heap[parent] = heap[index] ;
			heap[index] = temp ;
			index = parent ;
		}
		else
			return ;
	}
}

void delete_val(vector<int> &heap , int index)
{
	decrease_key(heap , index , INT_MIN) ;
	extract_min(heap) ;
}

void print(vector<int> heap)
{
	if(heap.size() == 0)
	{
		cout << "Heap is empty" << endl ;
		return ;
	}
	for(int i=0 ; i<heap.size() ; i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl ;
}

int main()
{
	vector<int> heap ;
	while(1)
	{
		cout << "Enter operation to perform \n 1.Insertion \n 2.Print \n 3.Extract_min \n 4.Decrease_key \n 5.Delete \n 6.Exit" << endl ;
		int n ;
		cin >> n ;
		if(n == 1)
		{
			int x ;
			cout << "Enter element to insert : " ;
			cin >> x ;
			insert(heap , x) ;
		}
		else if(n == 2)
			print(heap) ;
		else if(n == 3)
		{
			extract_min(heap) ;
			cout << "Heap after extracting min = " << endl ;
			print(heap) ;
		}
		else if(n == 4)
		{
			int index , x ; 
			cout << "Enter the index : " ;
			cin >> index ;
			cout << "Enter the value to decrease : " ;
			cin >> x ;
			decrease_key(heap , index , x) ;
		}
		else if(n == 5)
		{
			int index ;
			cout << "Enter the index : " ;
			cin >> index ;
			delete_val(heap , index) ;
		}
		else
			break ;
	}
}