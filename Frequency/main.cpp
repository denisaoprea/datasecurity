#include <iostream>
#include <iomanip>

using namespace std;

int alphabet[26] = {0};

int main(void)//doar pentru engleza
{
    string text;

    printf("Introduceti textul pe care doriti sa il criptati \n");
    getline(cin, text);

    for (int i = 0; i < text.length(); i++)
    {
        int a = text[i];

        if (a >= 'A' && a <= 'Z')
        {
            alphabet[a - 'A']++;
        }
        else if (a >= 'a' && a <= 'z')
        {
            alphabet[a - 'a']++;
        }
    }

    printf("Frecventa literelor: \n");

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i])
        {
            cout << right << char('a' + i) << setw(2) << right << alphabet[i] << endl;
        }
    }
    return 0;
}