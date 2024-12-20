#include <stdio.h>
int main() {
    char buffer[16];
    printf("Enter a string: ");
    gets(buffer); // 不安全：未限制輸入長度
    printf("You entered: %s\n", buffer);
    return 0;
}
