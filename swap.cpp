#include <iostream>
using namespace std;

// Function to reverse a string using pointers
void reverseString(char* str) {
    char* end = str;
    char temp;

    // Move the 'end' pointer to the last character of the string
    while (*end != '\0') {
        end++;
    }
    end--; // Move back to the last valid character (excluding '\0')

    // Swap the characters using the two pointers
    while (str < end) {
        temp = *str;  // Store the character at the start pointer
        *str = *end;  // Assign the character at the end pointer to the start
        *end = temp;  // Assign the stored character to the end pointer

        // Move the pointers closer to the center
        str++;
        end--;
    }
}

int main() {
    char str[100];

    // Input the string
    cout << "Enter a string: ";
    cin.getline(str, 100);

    // Reverse the string
    reverseString(str);

    // Output the reversed string
    cout << "Reversed string: " << str << endl;

    return 0;
}