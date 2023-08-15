#include <iostream>
#include <string>

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString); // Read an entire line, including spaces

    // Store the input string in a variable
    std::string storedString = inputString;

    // Convert the stored string into an array of characters
    const int arraySize = storedString.size();
    char charArray[arraySize + 1]; // +1 for the null terminator

    // Copy the characters from the stored string to the char array
    for (int i = 0; i < arraySize; ++i) {
        charArray[i] = storedString[i];
    }
    charArray[arraySize] = '\0'; // Add null terminator to make it a valid C-style string

    // Display the original string and the converted array
    std::cout << "Original string: " << storedString << std::endl;
    std::cout << "Array of characters: " << charArray << std::endl;

    return 0;
}
