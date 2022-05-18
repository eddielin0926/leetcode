#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define REVERSE

#ifdef BRUTE_FORCE
bool isPalindrome(int x){
    if (x < 0)
        return false;
    char str[11];
    int len = snprintf(str, 11, "%d", x);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}
#endif

#ifdef REVERSE
bool isPalindrome(int x) {
    int64_t revertX = 0;    /* aware of overflow while 10 * revertX */
    int64_t orgX = x;
    while(x > 0) {
        revertX = 10 * revertX + x % 10;
        x = x / 10;
    }
    
    return revertX == orgX;
}
#endif

int main(int argc, char const *argv[])
{
    printf("%s\n", isPalindrome(1234567899)? "true" : "false");
    return 0;
}
