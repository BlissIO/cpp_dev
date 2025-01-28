// 1/23/25
#include <iostream>
#include <cstring>

using namespace std;

int strLen(char *s) {
    int i = 0;
    for ( ; *(s + i) != '\0'; i++);
    return i;
}

int strLen2(char *s) {
    int i = 0;
    while (*(s + i++));
    return --i;
}

char* strCpy(char* s1, char *s2){//s1 - destination, s2 - source;
    char *s = s1;
    for ( ; *s2 != '\0'; s1++, s2++)
        *s1 = *s2;
    *s1 = '\0';
    return s;
}

char* strCpy2(char* s1, char *s2){//s1 - destination, s2 - source;
    char *s = s1;
    while (*s1++ = *s2++);
    return s;
}

void testString(){
    char s1[5] = "ABCD", s2[5]{'A','B','C','D', '\0'}, *s3 = new char[5], *s4;
    cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    cout << s1 << ' '<< strlen(s1) << ' ' << strLen(s1) << ' '<< strLen2(s1) << endl;
    cout << strCpy(s3,s1) << endl;
    s1[2] = '\0';
    cout << s1 << ' ' << strLen(s1) << ' ' << strCpy(s3,s1) << endl;
}

int main() {
    testString();
    return 0;
}