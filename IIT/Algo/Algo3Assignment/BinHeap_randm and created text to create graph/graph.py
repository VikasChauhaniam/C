import matplotlib.pyplot as plt

def read_integers_from_file(file_path):
    list1 = []
    list2 = []


    with open(file_path, 'r') as file:
        lines = file.readlines()
        if len(lines) >= 1:
            list1 = [int(x) for x in lines[0].strip().split(' ')]
            list2 = [int(x) for x in lines[1].strip().split(' ')]

    return list1, list2

file_path = '/home/vikas/Desktop/CPP/IIT/Algo/Algo3Assignment/BinHeap_randm/Binary_Heap.txt'  # Replace with the path to your .txt file
list1, list2 = read_integers_from_file(file_path)


print("List 1:", list1)
print("List 2:", list2)




def plot_lists(list1, list2):
    # Create the plot
    plt.plot(list1, list2, marker='o', linestyle='-', color='b', label='AVL')
   # plt.plot(list1, list3, marker='x', linestyle='--', color='r', label='Splay')
   # plt.plot(list1, list4, marker='+', linestyle='--', color='y', label='Red black')
    
    # Add labels and title
    plt.xlabel('time stamp')
    plt.ylabel('No. of Operations')
    plt.title('binary_heap')
    
    # Add a legend
    plt.legend()
    
    # Display the plot
    plt.show()


plot_lists(list1, list2)




