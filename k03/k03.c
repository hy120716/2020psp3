#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start;
    int pos;
    int find;
    int text_len = strlen(text);
    int key_len = strlen(key);

    for(start=0;start<=(text_len - key_len);start++){
        for(pos=0,find=0;pos<key_len;pos++){
            if(text[start+pos]==key[pos]){
                find++;
            }
            if(find==key_len){
                return text+start;
            }
        }
        
    }
    return NULL;
}


char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int index;
    int key_index;
    int i;

    int text_len = strlen(text);
    int key_len = strlen(key);
    int table[256];

    for(i=0;i<256;i++){
        table[i]=key_len;
    }
    for(i=0;i<key_len;i++){
        table[(int)key[i]]=key_len-(1+i);
    }

    index=key_len-1;
    while(index<text_len){
        for(key_index=key_len-1;key_index>=0;key_index--,index--){
            if (text[index] == key[key_index]){
                if(key_index==0){
                return text+index;
                }
            } else{
                break;
            }
        }
        index=index+table[(int)text[index]];
    }
    return NULL;
}

int main(void)
{
    char*  str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}