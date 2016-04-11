#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>

#define MAX_LEN 1024

/*Get the specified field in the string*/
int GetFieldFromLine(const char *src,char *des,int nth){
	int cnt = 1;
	const char *tmpsrc = src;
	char *tmpdes = des;
	if(nth < 1){
		//printf("Error:the number of specified field is too small\n");
		return -1;
	}
	/*过滤空格*/
	while(*tmpsrc == ' '){
		tmpsrc++;
	}
	/*过滤空行*/
	if(*tmpsrc == '\r' || *tmpsrc == '\n' || *tmpsrc == '\0'){
		return -1;
	}
	/*过滤前n-1个字段*/
	while(cnt < nth){
		/*空格为字段间隔符号，\r或\n或\0为行结束符号 */
		while(*tmpsrc != ' ' && (*tmpsrc != '\r' || *tmpsrc != '\n' || *tmpsrc != '\0')){
			tmpsrc++;
		}
		/*检测行是否结束，来判断是否有指定的字段存在*/
		if(*tmpsrc == '\r' || *tmpsrc == '\n' || *tmpsrc == '\0'){
			//printf("Error:the number of specified field is too big\n");
			return -1;
		}
		/*过滤空格*/
		while(*tmpsrc == ' '){
			tmpsrc++;
		}
		cnt++;
	}
	/*获取目标字段*/
	while(*tmpsrc != ' ' && *tmpsrc != '\r' && *tmpsrc != '\n' && *tmpsrc != '\0'){
		*tmpdes++ = *tmpsrc++;
	}
	*tmpdes = '\0';
	return 0;
}

