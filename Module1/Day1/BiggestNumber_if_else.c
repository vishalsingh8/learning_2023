#include <stdio.h>

int findBiggest(int num1, int num2) {
    if (num1 > num2) 
    {
        return num1;
    } 
    else 
    {
        return num2;
    }
}

int main() {
    int a = 10;
    int b = 20;
    int result = findBiggest(a, b);
    
    printf("The biggest number is: %d\n", result);
    
    return 0;
}
