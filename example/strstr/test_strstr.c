#include <stdio.h>
#include <string.h>

int main(void){
    char *src = "This is a test file.Use the strstr to find the dststr from srcstr.";
    char *dst = "find";
    char *result = NULL;

    if((result = strstr(src,dst)) != NULL){
        printf("result->...=%s\n",result);
    }else{
        printf("Not found dst in src!\n");
    }
        
    return 0;
}
