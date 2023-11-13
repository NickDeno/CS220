#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* print_any_base(unsigned long num, unsigned int base){
    if(base < 2 || base > 36){
        char* result = (char*)malloc((sizeof(char)) * 13);   
        strcpy(result,"Illegal Base\0");
        return result;
    }
    unsigned long temp = num;
    int count = 0;
    while(temp > 0){
        temp = temp/base;
        count++;
    }
    char* result = (char*)malloc((sizeof(char)) * (++count));
    result[count--] = '\0';
    while(count > 0){
        temp = num%base;
        num = num/base;
        count--;
        if(temp <=9){
            result[count] = '0' + temp;
        } else {
            result[count] = 'A' + (temp-10);
        }
    }
    return result;
}
unsigned int count_vowels(const char *str) {
    unsigned int count = 0;
    while (*str != '\0') {
        char c = *str;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        str++;
    }
    return count;
}

char* reverse_words(char *str){
    int length = strlen(str);
    char *result = (char *)malloc((length + 1) * sizeof(char));
    int count = 0;
    int position = length - 1;
    while (position >= 0) {
        while (position >= 0 && str[position] == ' ') position--;
        int end = position;
        while (position >= 0 && str[position] != ' ') position--;
        int start = position + 1;
        for (int i = start; i <= end; i++) {
            result[count++] = str[i];
        }
        if (position >= 0) {
            result[count++] = ' ';
        }
    }
    result[count] = '\0'; 
    return result;
}

void rotate_string_in_place(char *str, unsigned int disp){
    int position = 0;
    while(str[position] != '\0'){
        char curr = str[position];
        if(curr >= 'a' && curr <= 'z'){
            curr = 'a' + ((curr - 'a' + disp)%26);
        } else if(curr >= 'A' && curr <= 'Z'){
            curr = 'A' + ((curr - 'A' + disp)%26);
        }
        str[position++] = curr;
    }
}

int main(){
    return 0;
}

