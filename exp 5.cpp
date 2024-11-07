#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26
int modInverse(int a) {
    for (int x = 1; x < ALPHABET_SIZE; x++) {
        if ((a * x) % ALPHABET_SIZE == 1) {
            return x;
        }
    }
    return -1; 
}
char affineEncrypt(char p, int a, int b) {
    if (p >= 'A' && p <= 'Z') {
        return (a * (p - 'A') + b) % ALPHABET_SIZE + 'A';
    }
    return p;  
}

char affineDecrypt(char c, int a, int b) {
    if (c >= 'A' && c <= 'Z') {
        int a_inv = modInverse(a);
        if (a_inv == -1) {
            printf("Error: No modular inverse exists for 'a'.\n");
            exit(1);
        }
        return (a_inv * (c - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE + 'A';
    }
    return c;  
}
int isCoprimeWith26(int a) {
    return (a == 1 || a == 3 || a == 5 || a == 7 || a == 9 || a == 11 || a == 15 || a == 17 || a == 19 || a == 21 || a == 23 || a == 25);
}

int main() {
    int a, b;
    char choice;
    char input[100];
    printf("Enter value for a (should be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);
    if (!isCoprimeWith26(a)) {
        printf("Error: 'a' must be coprime with 26.\n");
        return 1;
    }
    printf("Do you want to encrypt (e) or decrypt (d)? ");
    scanf(" %c", &choice); 
    printf("Enter the text: ");
    getchar(); 
    fgets(input, 100, stdin);
    if (choice == 'e') {
        printf("Encrypted text: ");
        for (int i = 0; input[i] != '\0'; i++) {
            printf("%c", affineEncrypt(input[i], a, b));
        }
    } else if (choice == 'd') {
        printf("Decrypted text: ");
        for (int i = 0; input[i] != '\0'; i++) {
            printf("%c", affineDecrypt(input[i], a, b));
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

