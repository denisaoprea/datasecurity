#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cipherText[500], ch, keyText[500];
    int i, poz=0;

    FILE *file1;

    if ((file1 = fopen("in.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(file1,"%[^\n]", cipherText);

    FILE *file2;

    if ((file2 = fopen("keyText.txt", "a+")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(file2,"%[^\n]", keyText);
    fputs("WMPMMXXAEYHBR", file2);

    strlwr(cipherText);

    strlwr(keyText);

    for(i = 0; cipherText[i] != '\0'; ++i){
        ch = cipherText[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - keyText[poz++] + 'a';

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            cipherText[i] = ch;
        }
    }
    printf("Decrypted text is: %s \n" ,cipherText );

    fclose(file1);
    fclose(file2);

    return 0;
}
