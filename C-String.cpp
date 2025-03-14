#include <iostream>
#include <cstring> // Include for strlen

using namespace std;

int StrCmp( const char* s1, const char* s2){
    if (s1 == s2) return 0;
    if (s1 < s2) return -1;
    if (s1 > s2) return 1;
    return 0;
}

char* strPbrk(const char* s1, const char* s2){
    if (s1 == nullptr || s2 == nullptr) return nullptr;
    while (*s1 != '\0'){
        const char* temp = s2;
        while (*temp != '\0'){
            if (*s1 == *temp){
                return (char*)s1;
            }
            temp++;
        }
        s1++;
    }
    return nullptr;

}



char* ItoA(int n, char* s){
    int i = 0;
    
    // Handle zero case
    if (n == 0) {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    
    // Convert each digit to character
    while (n > 0) {
        s[i++] = (n % 10) + '0';
        n = n / 10;
    }
    s[i] = '\0';
    
    // Reverse using library function
    strrev(s);
    
    return s;
}

int main() {
// Test StrCmp
    const char* str1 = "Hello World";   
    const char* str2 = "o";  // characters to search for
    int result = StrCmp(str1, str2);
    cout << result << endl;

    // Test strPbrk
    const char* s1 = "Hello World";
    const char* s2 = "o";  // characters to search for

    char* result1 = strPbrk(s1, s2);
    cout << result1 << endl; 

    // Test ItoA
    int n = 123;
    char s[10];
    char* result2 = ItoA(n, s);
    cout << result2 << endl;

    char str[20];
    ItoA(123, str);  // str will contain "123"


    return 0;


}


