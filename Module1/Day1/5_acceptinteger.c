#include <stdio.h>

int bit_operations(int num, int oper_type) {
    int result = num;  // Initialize the result with the original number
    
    switch (oper_type) {
        case 1:
            result |= 1 << 0;  // Set the 1st bit
            break;
        case 2:
            result &= ~(1 << 31);  // Clear the 31st bit
            break;
        case 3:
            result ^= 1 << 15;  // Toggle the 16th bit
            break;
        default:
            printf("Invalid operation type.\n");
            break;
    }
    
    return result;
}

int main() {
    int num, oper_type;
    
    printf("Enter an integer (32 bits): ");
    scanf("%d", &num);
    
    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);
    
    int result = bit_operations(num, oper_type);
    
    printf("Result: %d\n", result);
    
    return 0;
}
