#include <stdio.h>
#include <stdlib.h>

int main()
{
    char plainText[500], ch, keyText[30];;
    int i, poz=0;

    FILE *file1;

    if ((file1 = fopen("in.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(file1,"%[^\n]", plainText);

    FILE *file2;

    if ((file2 = fopen("keyText.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(file2,"%[^\n]", keyText);

    strlwr(plainText);

    strlwr(keyText);

    for(i = 0; plainText[i] != '\0'; ++i){
        ch = plainText[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - keyText[poz++] + 'a';

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            if (poz >= strlen(keyText))
                poz = 0;

            plainText[i] = ch;
        }
    }
    printf("Decrypted text with key \"%s\"  is: %s \n" ,keyText,plainText );

    fclose(file1);
    fclose(file2);

    return 0;
}
