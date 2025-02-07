//************************************************************
// This program implements various string manipulation functions:
// - strCmp: Compares two strings
// - strPbrk: Finds first matching character between strings
// - strrev: Reverses a string
// - ltoA: Converts integer to string
//************************************************************
#include <iostream>

using namespace std;

// Returns 0 if strings are equal, -1 if s1 precedes s2, 1 if s1 follows s2
int strCmp(const char *s1, const char *s2) {
    while (*s1 || *s2) {
        int diff = *s1 - *s2;
        if (diff != 0) {
            return (diff > 0) ? 1 : -1;
        }
        if (*s1 == '\0' || *s2 == '\0') break;
        s1++;
        s2++;
    }
    return 0;
}

char* strPbrk(const char *s1, const char *s2) {
    if (!s1 || !s2) return nullptr;
    
    cout << "Finding first of '" << s2 << "' in '" << s1 << "'" << endl;
    cout << "Found word: ";
    
    // We start from the end of s1 and work to the beginning
    const char* end = s1;
    while (*end) end++;  // until we find the end of s1
    end--;  // To move back from null terminator
    
    // Search from both ends of s1 simultaneously
    const char* front = s1;
    while (front <= end) {
        // Check front character
        const char* curr_s2 = s2;
        while (*curr_s2) {
            if (*front == *curr_s2) {
                // Find start of word
                const char* word_start = front;
                while (word_start > s1 && *(word_start - 1) != ' ') {
                    word_start--;
                }
                
                // Find end of word
                const char* word_end = front;
                while (*word_end && *word_end != ' ') {
                    word_end++;
                }
                
                // Print the word
                const char* temp = word_start;
                while (temp < word_end) {
                    cout << *temp;
                    temp++;
                }
                cout << endl;
                
                return (char*)word_start;
            }
            curr_s2++;
        }
        
        // If front and end point to same character, we're done with this iteration
        if (front == end) break;
        
        // Check end character
        curr_s2 = s2;
        while (*curr_s2) {
            if (*end == *curr_s2) {
                // Find start of word
                const char* word_start = end;
                while (word_start > s1 && *(word_start - 1) != ' ') {
                    word_start--;
                }
                
                // Find end of word
                const char* word_end = end;
                while (*word_end && *word_end != ' ') {
                    word_end++;
                }
                
                // Print the word
                const char* temp = word_start;
                while (temp < word_end) {
                    cout << *temp;
                    temp++;
                }
                cout << endl;
                
                return (char*)word_start;
            }
            curr_s2++;
        }
        
        // Move pointers towards each other
        front++;
        end--;
    }
    
    cout << "nullptr" << endl;
    return nullptr;
}

// Reverses a string
char* strrev(char *s) {
    // Initialize pointers to the start and end of the string
    char *start = s;
    char *end = s;

    // Move end pointer to the last character of the string 
    while (*(end + 1)) end++;

    // Swap characters from start and end until pointers meet
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return s;
}

// Converts integer to string
char* ltoA(int n, char *s) {
    char *ptr = s;
    bool negative = n < 0;

    // Handle zero case
    if (n == 0) {
        *ptr = '0';
        *(ptr + 1) = '\0';
        return s;
    }

    // Handle negative numbers
    if (negative) n = -n;
    
    // Convert digits to string
    while (n > 0) {
        *ptr = (n % 10) + '0';
        ptr++;
        n /= 10;
    }
    
    // Add negative sign if necessary
    if (negative) {
        *ptr = '-';
        ptr++;
    }

    *ptr = '\0';
    
    return strrev(s);
}

// Test functions
int main() {
    // Test strCmp
    const char *test1 = "Mom";
    const char *test2 = "dad";
   
    cout << "Testing strCmp:" << endl;
    cout << "mom vs dad: " << strCmp(test1, test2) << endl;
    cout << "dad vs mom: " << strCmp(test2, test1) << endl;
    cout << "mom vs mom: " << strCmp(test1, test1) << endl;
   
    // Test strPbrk
    
    const char *str = "Hot dog math";
    const char *chars = "d";
    strPbrk(str, chars);
     
    // Test with non-existent character
    const char *chars2 = "z";
    strPbrk(str, chars2);
   
    // Test ltoA
    char numStr[20];
    int num = -18739;
   
    cout << endl <<"Testing ltoA:" << endl;
    cout << "Converting " << num << " to string: ";
    cout << ltoA(num, numStr) << endl;
   
    return 0;
}
