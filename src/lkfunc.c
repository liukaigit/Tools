/*
 *filename:lkfunc.c
 *author:liukai
 *version:1.0.0.1
 *description:This document is mainly for commom string operations,reduce repetitive works.Each 
 *function to realize a single function,flexibility and versatility.
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_LEN 1024

/*Print the error information.*/
void print_error(const char *error){
    printf("-_-! \033[1;31mError:\033[0m\n");
}

/*Get the specified field in the string.*/
int GetFieldFromLine(const char *src,char *des,int nth){
	int cnt = 1;
	const char *tmpsrc = src;
	char *tmpdes = des;
	if(nth < 1){
		print_error("the number of specified field is too small\n");
		return -1;
	}
	/*Filter the blank space.*/
	while(*tmpsrc == ' '){
		tmpsrc++;
	}
	/*Filter the blank line.*/
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
			print_error("the number of specified field is too big\n");
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

