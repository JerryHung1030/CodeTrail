// unsafe_functions.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// 函式1：gets() 不安全用法
void example_gets_unsafe() {
    char buffer[10];
    printf("Example: gets() - Unsafe Usage\n");
    printf("Enter a string: ");
    gets(buffer); // 不安全：無限制輸入長度
    printf("You entered: %s\n\n", buffer);
}

// 函式1：fgets() 安全替代方案
void example_gets_safe() {
    char buffer[10];
    printf("Example: gets() - Safe Replacement with fgets()\n");
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin); // 安全：限制輸入長度
    printf("You entered: %s\n\n", buffer);
}

// 函式2：strcpy() 不安全用法
void example_strcpy_unsafe() {
    char src[] = "This is a very long source string that exceeds the destination buffer size.";
    char dest[20];
    printf("Example: strcpy() - Unsafe Usage\n");
    strcpy(dest, src); // 不安全：無邊界檢查
    printf("Destination: %s\n\n", dest);
}

// 函式2：strncpy() 安全替代方案
void example_strcpy_safe() {
    char src[] = "This is a very long source string that exceeds the destination buffer size.";
    char dest[20];
    printf("Example: strcpy() - Safe Replacement with strncpy()\n");
    strncpy(dest, src, sizeof(dest) - 1); // 安全：限制拷貝長度
    dest[sizeof(dest) - 1] = '\0'; // 確保字串結尾
    printf("Destination: %s\n\n", dest);
}

// 函式3：sprintf() 不安全用法
void example_sprintf_unsafe() {
    char buffer[20];
    int number = 12345;
    printf("Example: sprintf() - Unsafe Usage\n");
    sprintf(buffer, "Number: %d", number); // 不安全：無邊界檢查
    printf("Buffer: %s\n\n", buffer);
}

// 函式3：snprintf() 安全替代方案
void example_sprintf_safe() {
    char buffer[20];
    int number = 12345;
    printf("Example: sprintf() - Safe Replacement with snprintf()\n");
    snprintf(buffer, sizeof(buffer), "Number: %d", number); // 安全：限制輸出長度
    printf("Buffer: %s\n\n", buffer);
}

// 函式4：strcat() 不安全用法
void example_strcat_unsafe() {
    char src[] = "World!";
    char dest[10] = "Hello ";
    printf("Example: strcat() - Unsafe Usage\n");
    strcat(dest, src); // 不安全：無邊界檢查
    printf("Concatenated String: %s\n\n", dest);
}

// 函式4：strncat() 安全替代方案
void example_strcat_safe() {
    char src[] = "World!";
    char dest[10] = "Hello ";
    printf("Example: strcat() - Safe Replacement with strncat()\n");
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1); // 安全：限制追加長度
    printf("Concatenated String: %s\n\n", dest);
}

// 函式5：scanf() 不安全用法
void example_scanf_unsafe() {
    char buffer[10];
    printf("Example: scanf() - Unsafe Usage\n");
    printf("Enter a string: ");
    scanf("%s", buffer); // 不安全：無限制輸入長度
    printf("You entered: %s\n\n", buffer);
}

// 函式5：scanf() 安全替代方案
void example_scanf_safe() {
    char buffer[10];
    printf("Example: scanf() - Safe Usage with Field Width Limitation\n");
    printf("Enter a string: ");
    scanf("%9s", buffer); // 安全：限制輸入長度
    printf("You entered: %s\n\n", buffer);
}

// 函式6：memcpy() 不安全用法
void example_memcpy_unsafe() {
    char src[] = "This is a very long source string that exceeds the destination buffer size.";
    char dest[20];
    printf("Example: memcpy() - Unsafe Usage\n");
    memcpy(dest, src, strlen(src)); // 不安全：拷貝長度未檢查
    dest[strlen(src)] = '\0'; // 可能寫出陣列界限
    printf("Destination: %s\n\n", dest);
}

// 函式6：memmove() 安全替代方案
void example_memcpy_safe() {
    char src[] = "This is a very long source string that exceeds the destination buffer size.";
    char dest[20];
    size_t copy_len = sizeof(dest) - 1;
    printf("Example: memcpy() - Safe Replacement with memmove()\n");
    if (strlen(src) < copy_len) {
        memmove(dest, src, strlen(src));
        dest[strlen(src)] = '\0';
    } else {
        memmove(dest, src, copy_len); // 限制拷貝長度
        dest[copy_len] = '\0'; // 確保字串結尾
    }
    printf("Destination: %s\n\n", dest);
}

// 函式7：system() 不安全用法
void example_system_unsafe() {
    char command[100];
    printf("Example: system() - Unsafe Usage\n");
    printf("Enter a shell command: ");
    fgets(command, sizeof(command), stdin);
    system(command); // 不安全：可能被注入
    printf("\n");
}

// 函式7：使用更安全的子程序呼叫 (如execvp())
void example_system_safe() {
    printf("Example: system() - Safe Replacement with execvp()\n");
    printf("Demonstration only: execvp() requires separate handling and is not directly replaceable.\n\n");
}

// 函式8：fscanf() 不安全用法
void example_fscanf_unsafe() {
    FILE *file = fopen("input_files/sample.csv", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    char buffer[10];
    printf("Example: fscanf() - Unsafe Usage\n");
    fscanf(file, "%s", buffer); // 不安全：無限制輸入長度
    printf("Read String: %s\n\n", buffer);
    fclose(file);
}

// 函式8：fscanf() 安全替代方案
void example_fscanf_safe() {
    FILE *file = fopen("input_files/sample.csv", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    char buffer[10];
    printf("Example: fscanf() - Safe Usage with Field Width Limitation\n");
    fscanf(file, "%9s", buffer); // 安全：限制輸入長度
    printf("Read String: %s\n\n", buffer);
    fclose(file);
}

// 函式9：strtok() 不安全用法
void example_strtok_unsafe() {
    char str[] = "This,is,a,test,string";
    char *token;
    printf("Example: strtok() - Unsafe Usage\n");
    token = strtok(str, ","); // 不安全：非重入函式
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }
    printf("\n");
}

// 函式9：strtok_r() 安全替代方案
void example_strtok_safe() {
    char str[] = "This,is,a,test,string";
    char *token;
    char *saveptr;
    printf("Example: strtok() - Safe Replacement with strtok_r()\n");
    token = strtok_r(str, ",", &saveptr); // 安全：重入函式
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok_r(NULL, ",", &saveptr);
    }
    printf("\n");
}

// 函式10：strncat() 不安全用法
void example_strncat_unsafe() {
    char src[] = "World!";
    char dest[10] = "Hello ";
    printf("Example: strncat() - Unsafe Usage\n");
    strncat(dest, src, strlen(src)); // 不安全：未嚴謹檢查
    printf("Concatenated String: %s\n\n", dest);
}

// 函式10：strncat() 安全替代方案
void example_strncat_safe() {
    char src[] = "World!";
    char dest[10] = "Hello ";
    printf("Example: strncat() - Safe Usage with Proper Length Limitation\n");
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1); // 安全：嚴謹檢查
    printf("Concatenated String: %s\n\n", dest);
}

int main() {
    int choice;
    while (1) {
        printf("=== Unsafe Functions Analysis ===\n");
        printf("Select an example to run:\n");
        printf("1. gets() - Unsafe Usage\n");
        printf("2. gets() - Safe Replacement with fgets()\n");
        printf("3. strcpy() - Unsafe Usage\n");
        printf("4. strcpy() - Safe Replacement with strncpy()\n");
        printf("5. sprintf() - Unsafe Usage\n");
        printf("6. sprintf() - Safe Replacement with snprintf()\n");
        printf("7. strcat() - Unsafe Usage\n");
        printf("8. strcat() - Safe Replacement with strncat()\n");
        printf("9. scanf() - Unsafe Usage\n");
        printf("10. scanf() - Safe Usage with Field Width Limitation\n");
        printf("11. memcpy() - Unsafe Usage\n");
        printf("12. memcpy() - Safe Replacement with memmove()\n");
        printf("13. system() - Unsafe Usage\n");
        printf("14. system() - Safe Replacement with execvp()\n");
        printf("15. fscanf() - Unsafe Usage\n");
        printf("16. fscanf() - Safe Usage with Field Width Limitation\n");
        printf("17. strtok() - Unsafe Usage\n");
        printf("18. strtok() - Safe Replacement with strtok_r()\n");
        printf("19. strncat() - Unsafe Usage\n");
        printf("20. strncat() - Safe Usage with Proper Length Limitation\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // 清除換行符

        switch (choice) {
            case 1:
                example_gets_unsafe();
                break;
            case 2:
                example_gets_safe();
                break;
            case 3:
                example_strcpy_unsafe();
                break;
            case 4:
                example_strcpy_safe();
                break;
            case 5:
                example_sprintf_unsafe();
                break;
            case 6:
                example_sprintf_safe();
                break;
            case 7:
                example_strcat_unsafe();
                break;
            case 8:
                example_strcat_safe();
                break;
            case 9:
                example_scanf_unsafe();
                break;
            case 10:
                example_scanf_safe();
                break;
            case 11:
                example_memcpy_unsafe();
                break;
            case 12:
                example_memcpy_safe();
                break;
            case 13:
                example_system_unsafe();
                break;
            case 14:
                example_system_safe();
                break;
            case 15:
                example_fscanf_unsafe();
                break;
            case 16:
                example_fscanf_safe();
                break;
            case 17:
                example_strtok_unsafe();
                break;
            case 18:
                example_strtok_safe();
                break;
            case 19:
                example_strncat_unsafe();
                break;
            case 20:
                example_strncat_safe();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}
