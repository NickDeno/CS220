#include <stdio.h>
unsigned long swap_bytes(unsigned long n) {
    unsigned char *ptr = (unsigned char *)&n; // Treat the input as an array of bytes
    unsigned char temp;
    
    // Swap adjacent pairs of bytes
    temp = ptr[0];
    ptr[0] = ptr[1];
    ptr[1] = temp;
    
    temp = ptr[2];
    ptr[2] = ptr[3];
    ptr[3] = temp;
    
    temp = ptr[4];
    ptr[4] = ptr[5];
    ptr[5] = temp;
    
    temp = ptr[6];
    ptr[6] = ptr[7];
    ptr[7] = temp;
    
    return n;
}

int main() {
    unsigned long n = 0x12345678deadbeef;
    printf("Orignal = %x",n);
    printf(", new = %x", swap_bytes(n));
    return 0;
}