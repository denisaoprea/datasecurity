#include<iostream>
#include<string>

using namespace std;

char fs[10][10],c[1000],ans[1000],decy[1000];;

struct index
{
       int x,y;
};

void table(string key1, string key2)
{
       int i,j,k=65,lkey1=0,lkey2=0,vkey1[26]={0},vkey2[26]={0},lv1=0,lv2=0,m=65;
       for(i=0;i<10;i++)
       {
              for(j=0;j<10;j++)
              {
                     if(i<5)
                     {
                           if(j<5)
                           {
                                  fs[i][j] = k;
                                  k++;
                           }
                           else
                           {
                                  if(lkey1<key1.size())
                                  {
                                         fs[i][j] = key1[lkey1];
                                         vkey1[key1[lkey1]-97] = 1;
                                         lkey1++;
                                  }
                                  else
                                  {
                                         while(vkey1[lvey1]==1)
                                         {
                                                lvey1++;
                                         }
                                         fs[i][j] = lv1 + 97;
                                         lv1++;
                                  }

                           }
                     }
                     else
                     {
                           if(j<5)
                           {
                                  if(lkey2<key2.size())
                                  {
                                         fs[i][j] = k2[lkey2];
                                         vkey2[key2[lkey2]-97] = 1;
                                         lkey2++;
                                  }
                                  else
                                  {
                                         while(vkey2[lv2]==1)
                                         {
                                                lv2++;
                                         }
                                         fs[i][j] = lv2 + 97;
                                         lv2++;
                                  }
                           }
                           else
                           {
                                  fs[i][j] = m;
                                  m++;
                           }
                     }
                     cout<<fs[i][j]<<" ";
              }
              cout<<endl;
       }

}

int convert(string s)
{
       int i,j = 0,f=0;
       for(i=0;i<s.size();i++)
       {
              if( (s[i]>47 && s[i]<58) || (s[i]>96 && s[i]<123) )
              {
                     if((i+f)%2!=0 && c[j-1]==s[i])
                     {
                           c[j] = 'x';
                     }
                     else
                     {
                           c[j] = s[i];
                     }
                     cout<<c[j];
                     j++;
              }
              else
              {
                     f++;
              }
       }
       if(j%2!=0)
       {
              c[j] = 'x';
              cout<<c[j];
              j++;
       }
       return j;
}

//first matrix
struct index Index1(char ch)
{
       int i,j;
       struct index f;
       for(i=0;i<5;i++)
       {
              for(j=5;j<10;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=5;
                           j=10;;
                     }
              }
       }
       return f;
}

//second matrix
struct index Index2(char ch)
{
       int i,j;
       struct index f;
       for(i=5;i<10;i++)
       {
              for(j=0;j<5;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=10;
                           j=5;
                     }
              }
       }
       return f;
}

// function for Encrypted message
void encrypt(int l)
{
       int i,ax,ay,bx,by;
       struct index f;
       for(i=0;i<l;i=i+2)
       {
              f = Index1(c[i]);
              ax = f.x;
              ay = f.y;
              f = Index2(c[i+1]);
              bx = f.x;
              by = f.y;
              ans[i] = fs[ax][by];
                      ans[i+1] = fs[bx][ay];
              cout<<ans[i]<<ans[i+1];
       }
}

//third matrix
struct index Index3(char ch)
{
       int i,j;
       struct index f;
       for(i=0;i<5;i++)
       {
              for(j=0;j<5;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=5;
                           j=10;;
                     }
              }
       }
       return f;
}

//fourth matrix
struct index Index4(char ch)
{
       int i,j;
       struct index f;
       for(i=5;i<10;i++)
       {
              for(j=5;j<10;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=10;
                           j=5;
                     }
              }
       }
       return f;
}

// function for Decrypted message
void decrypt(int l)
{
       int i,ax,ay,bx,by;
       struct index f;
       for(i=0;i<l;i=i+2)
       {
              f = Index3(ans[i]);
              ax = f.x;
              ay = f.y;
              f = Index4(ans[i+1]);
              bx = f.x;
              by = f.y;
                     decy[i] = fs[ax][by];
                     decy[i+1] = fs[bx][ay];
              cout<<decy[i]<<decy[i+1];
       }
}

int main()
{
       string s,key1,key2;
       cout<<"Enter the String to be Ciphered"<<endl;
       getline(cin,s);
       cout<<"Enter the Keys : "<<endl;
       cin>>key1>>key2;
       int i,j,f=0;
       cout<<"Four Square Matrix : "<<endl;
       table(key1,key2);
       cout<<"Message : ";
       f = convert(s);
       cout<<"\nEncrypted Message : ";
       encrypt(f);
       cout<<"\nDecrypted Message : ";
       decrypt(f);
       return  0;
}
