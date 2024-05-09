class Solution {
public:
    string reverseOnlyLetters(string s) {
        // Convert the string to a character array
        char arr[s.length() + 1];
        strcpy(arr, s.c_str());

        // Get the left and right pointers
        int left = 0;
        int right = s.length() - 1;

        // Start a loop and compare characters
        while (left < right) {
            // If left is not a letter, move right
            if (!isalpha(arr[left])) left++;

            // If right is not a letter, move left
            else if (!isalpha(arr[right])) right--;

            // If both are letters, swap them
            else {
                char temp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = temp;
            }
        }

        // Convert the character array to a string
        return string(arr);
    }
};