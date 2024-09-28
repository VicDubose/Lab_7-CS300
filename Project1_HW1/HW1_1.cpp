// HW1 CS300 Palindrome Question 1
#include <iostream>
#include <string>
#include <algorithm>
std::string reverseString(const std::string& s) {
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {
    std::string s;
    std::cout << "Please give me a number: ";
    std::getline(std::cin, s);
    while (true) {
        // Remove commas because stoi has some issue with them and white space.
        s.erase(std::remove(s.begin(), s.end(), ','), s.end());

        // Convert string to integer (https://www.geeksforgeeks.org/stdstoi-function-in-cpp/)
        int number = std::stoi(s);
        
        // Reverse the string representation of the number
        std::string reversedStr = reverseString(s);
        int reversedNumber = std::stoi(reversedStr);
	 std::cout << "Reversed Number: " << reversedNumber << std::endl;
	  std::cout << " " << std::endl;

        // Check if the original number is equal to the reversed number
        if (number == reversedNumber) {
            std::cout << "\nBoth the numbers are equal. This is a palindrome Thank God: " << number << std::endl;
            break; // Exit the loop 
        } else {
            int combinedNumber = number + reversedNumber;
            std::cout << "Sum of original and reversed numbers: " << combinedNumber << std::endl;
            number = combinedNumber;
            s = std::to_string(number);
        }
    }
    return 0;
}
