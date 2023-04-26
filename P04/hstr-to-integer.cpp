#include <iostream>

unsigned long hstr_to_integer(const char hstr[]) {
    unsigned long result = 0;
    while (*hstr != '\0') {
        if (*hstr >= '0' && *hstr <= '9') {
            result = result * 16 + (*hstr - '0');
        }
        else if (*hstr >= 'A' && *hstr <= 'F') {
            result = result * 16 + (*hstr - 'A' + 10);
        }
        else if (*hstr >= 'a' && *hstr <= 'f') {
            result = result * 16 + (*hstr - 'a' + 10);
        }
        hstr++;
    }
    return result;
}







