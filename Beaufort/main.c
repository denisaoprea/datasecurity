#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[500], keyText[30];
    int i, poz=0;

    //read cipher text
    FILE *file1;

    if ((file1 = fopen("in.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(file1,"%[^\n]", text);

    //read the key
    FILE *file2;

    if ((file2 = fopen("keyText.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    fscanf(file2,"%[^\n]", keyText);

    //convert in lowercase
    strlwr(text);
    printf("Cipher text : %s \n",text);
    strlwr(keyText);
    printf("Key text : %s \n",keyText);

    //algorithm
    for(i = 0; text[i] != '\0'; ++i)
    {
        int temp =0;

        if(keyText[poz] >= text[i])
        {
            temp += ((keyText[poz] - text[i])%26 + 'a');
        }
        else
        {
            temp += ((keyText[poz] - text[i] + 26)%26 + 'a');
        }

        poz = (poz + 1)%strlen(keyText);

        text[i] = temp;


    }
    printf("\nDecrypted text with key \"%s\"  is: %s \n" ,keyText,text );

    fclose(file1);
    fclose(file2);

    return 0;
}
