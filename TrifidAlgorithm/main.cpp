#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
class trifid
{
  char str[30];
  char str1[30];
  static char l1[3][3],l2[3][3],l3[3][3];
public:
  void cipher();
  void decipher();
}a5;
char trifid::l1[3][3]={'a','b','c'
                      ,'d','e','f'
                      ,'g','h','i'};
char trifid::l2[3][3]={'j','k','l'
                      ,'m','n','o'
                      ,'p','q','r'};
char trifid::l3[3][3]={'s','t','u'
                      ,'v','w','x'
                      ,'y','z','.'};
void trifid::cipher()
{
  int x,y,z;
  int a[30],b[30],c[30];
  int h[90];
  int f=0,g=0;
  cout<<"Enter a message to encipher: ";
  cin.getline(str,30);
  for(int i=0;i<strlen(str);++i)
  {
    for(int j=0;j<3;++j)
      for(int k=0;k<3;++k)
      {
        if(str[i]==l1[j][k])
        {
          a[i]=0;
          b[i]=k;
          c[i]=j;
        }
        else if(str[i]==l2[j][k])
        {
          a[i]=1;
          b[i]=k;
          c[i]=j;
        }
        else if(str[i]==l3[j][k])
        {
          a[i]=2;
          b[i]=k;
          c[i]=j;
        }
      }
  }
  for(int i=0;i<strlen(str);++i)
  {
    h[i]=a[i];
  }
  for(int i=strlen(str);i<2*strlen(str);++i)
  {
    h[i]=b[f];
    ++f;
  }
  for(int j=2*strlen(str);j<3*strlen(str);++j)
  {
    h[j]=c[g];
    ++g;
  }
  cout<<"The enciphered string: ";
  for(int w=0;w<3*strlen(str);w+=3)
  {
    x=h[w+1];
    y=h[w+2];
    if(h[w]==0)
    {
      cout<<l1[y][x];
    }
    else if(h[w]==1)
    {
      cout<<l2[y][x];
    }
    else if(h[w]==2)
    {
      cout<<l3[y][x];
    }
  }
}
void trifid::decipher()
{
  int w,z=0;
  cout<<"Enter a string to decipher: ";
  cin.getline(str1,30);
  short a[30],b[30],c[30],h[90];
  for(int i=0;i<strlen(str1);++i)
  {
    for(int j=0;j<3;++j)
      for(int k=0;k<3;++k)
      {
        if(str1[i]==l1[j][k])
        {
          h[z]=0;
          h[z+1]=k;
          h[z+2]=j;
          z+=3;
        }
        else if(str1[i]==l2[j][k])
        {
          h[z]=1;
          h[z+1]=k;
          h[z+2]=j;
          z+=3;
        }
        else if(str1[i]==l3[j][k])
        {
          h[z]=2;
          h[z+1]=k;
          h[z+2]=j;
          z+=3;
        }
      }

  }
  for(int i=0;i<strlen(str1);++i)
  {
    a[i]=h[i];
    cout<<a[i];
  }
  cout<<endl;
  int f=0;
  for(int i=strlen(str1);i<2*strlen(str1);++i)
  {
    b[f]=h[i];
    cout<<b[f];
    ++f;
  }
  cout<<endl;
  int g=0;
  for(int i=2*strlen(str1);i<3*strlen(str1);++i)
  {
    c[g]=h[i];
    cout<<c[g];
    ++g;
  }
  cout<<endl;
  int x,y;
  cout<<"The decihered string: ";
  for(int i=0;i<z/3;++i)
  {
    x=b[i];
    y=c[i];
    if(a[i]==0)
    {
      cout<<l1[y][x];
    }
    else if(a[i]==1)
    {
      cout<<l2[y][x];
    }
    else if(a[i]==2)
    {
      cout<<l3[y][x];
    }
  }
}
int main()
{
  a5.decipher();
  getch();
  return 0;
}
