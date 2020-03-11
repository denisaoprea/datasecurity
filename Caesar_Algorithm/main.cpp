#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char* argv[]) {
    int key;
    int result;
    char input[100];
    printf("Textul pe care doriti sa il criptati \n");
    scanf("%[^\n]s", input);
    printf("Cheia de criptare:  \n");
    scanf("%d", &key);

    //daca key contine cel putin un caracter, programul se opreste
    if (isdigit(key)==0) {
        printf("Cheia trebuie sa aiba valoare strict numerica!\n");
        return 0;
    } else {
        if (key >=26) { // daca key este mai mare decat numarul literelor din alfabet o ia de la capat cu restul corespunzator literei din alfabet
            key = (key % 26);
        }

        for (int i = 0, length = strlen(input); i < length; i++) {
            result = (input[i] + key);
            if (isupper(input[i]) && (result > 'Z')) {
                result = (result - 26);
            }
            if (islower(input[i]) && (result > 'z')) {
                result = (result - 26);
            }
            //daca e alfanumeric printeaza varianta criptata
            if (isalpha(input[i])) {
                printf("%c", result);
            }
            //daca nu e alfanumeric printeaza caracterul
            else {
                printf("%c", input[i]);
            }
        }
        printf("\n");
        return 0;
    }
}