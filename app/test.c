#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

#define MAX_LEN 1024
#if 0
/*Get the specified field in the string*/
char *GetFieldFromLine(const char *src,char *des,int n){
	int counter = 1;
	const char *tmpsrc = src;
	char *tmpdes = des;
	
	if(n < 1){
		//printf("Error:the number of specified field is too small\n");
		return NULL;
	}
	
	/*过滤空格*/
	while(*tmpsrc == ' '){
		tmpsrc++;
	}
	/*过滤空行*/
	if(*tmpsrc == '\r' || *tmpsrc == '\n' || *tmpsrc == '\0'){
		return NULL;
	}
	
	/*过滤前n-1个字段*/
	while(counter < n){
		/*空格为字段间隔符号，\r或\n或\0为行结束符号 */
		while(*tmpsrc != ' ' && (*tmpsrc != '\r' || *tmpsrc != '\n' || *tmpsrc != '\0')){
			tmpsrc++;
		}
		
		/*检测行是否结束，来判断是否有指定的字段存在*/
		if(*tmpsrc == '\r' || *tmpsrc == '\n' || *tmpsrc == '\0'){
			//printf("Error:the number of specified field is too big\n");
			return NULL;
		}
		
		/*过滤空格*/
		while(*tmpsrc == ' '){
			tmpsrc++;
		}
		
		counter++;
	}
	
	/*获取目标字段*/
	while(*tmpsrc != ' ' && *tmpsrc != '\r' && *tmpsrc != '\n' && *tmpsrc != '\0'){
		*tmpdes++ = *tmpsrc++;
	}
	
	*tmpdes = '\0';
	
	return des;
}
#endif

/*The 1th field is the parameter name*/
int GetParameterName(const char *linebuf,char *parameterbuf){
    return GetFieldFromLine(linebuf,parameterbuf,1);
}
/*The 2th field is the parameter value*/
int GetParameterValue(const char *linebuf,char *valuebuf){
    return GetFieldFromLine(linebuf,valuebuf,2);
}

int main(int argc,char **argv){
	char linebuf[MAX_LEN] = {0};
	char parameterbuf[50] = {0};
	char valuebuf[50] = {0};
	int ret = 0;
	FILE* fp;
	
	/*Usage*/
	if(argc != 2){
		printf("Error!Usage: %s [filename]\n",argv[0]);
		return -1;
	}
	
	/*File exists or not*/
	ret = access(argv[1],F_OK);
	if(-1 == ret){
		printf("%s is not found",argv[1]);
		return -1;
	}
	
	fp = fopen(argv[1],"r");
	if(NULL == fp){
		printf("Error:fopen %s fail!\n",argv[1]);
		return -1;
	}
	
	/*按行读取文件内容，并进行检测*/
	while(fgets(linebuf,MAX_LEN,fp)){
		if('#' == linebuf[0]){
			continue;
		}
		if(!GetParameterName(linebuf,parameterbuf)){
			GetParameterValue(linebuf,valuebuf);
		}else{
			continue;
		}
		/*这个位置可以添加转换成链表的功能，将parameter和value作为一个结构体的成员，添加到单链表中*/
		/*打印获取的信息，其中值可以用atoi转换为整型数据，可以根据实际情况来定*/
		printf("%s = %s\n",parameterbuf,valuebuf);
	}
	
	fclose(fp);

	return 0;
}
