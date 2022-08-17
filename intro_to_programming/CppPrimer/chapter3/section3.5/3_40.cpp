#include <iostream>
#include <cstring>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    const char *s1 = "Hello";
    const char *s2 = " World!";
    char *s3 = (char *)std::malloc(std::strlen(s1) + std::strlen(s2) + 1);
    std::strcpy(s3, s1);
    std::strcat(s3, s2);
    std::cout << s3;
    return 0;
}
