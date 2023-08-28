import matplotlib.pyplot as plt

def read_integers_from_file(file_path):
    list1 = []
    list2 = []
    list3 = []

    with open(file_path, 'r') as file:
        lines = file.readlines()
        if len(lines) >= 3:
            list1 = [int(x) for x in lines[0].strip().split(' ')]
            list2 = [int(x) for x in lines[1].strip().split(' ')]
            list3 = [int(x) for x in lines[2].strip().split(' ')]

    return list1, list2, list3

file_path = '/home/vikas/MyWorkSpace/CPP/IIT/Algo/Example.txt'  # Replace with the path to your .txt file
list1, list2, list3 = read_integers_from_file(file_path)

print("List 1:", list1)
print("List 2:", list2)
print("List 3:", list3)



def plot_lists(list1, list2, list3):
    # Create the plot
    plt.plot(list1, list2, marker='o', linestyle='-', color='b', label='AVL')
    plt.plot(list1, list3, marker='x', linestyle='--', color='r', label='Splay')
    
    # Add labels and title
    plt.xlabel('No. of Operations')
    plt.ylabel('No.of Rotations')
    plt.title('Comparison of AVL  and Splay tree')
    
    # Add a legend
    plt.legend()
    
    # Display the plot
    plt.show()


plot_lists(list1, list2, list3)




