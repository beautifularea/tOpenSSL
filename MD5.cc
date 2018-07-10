#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    unsigned char in[] = "I am the codes.";
    unsigned char out[20];

    int n = strlen((const char*)in);
    MD5(in, n, out);
    
    printf("MD5: ");
    for(int i=0;i<strlen((const char*)out);i++)
    {
        printf("%x", out[i]);
    }
    printf("\n");
}
