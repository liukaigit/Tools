/*
 *filename:lkfunc.c
 *author:liukai
 *version:1.0.0.1
 *dstcription:This document is mainly for commom string operations,reduce repetitive works.Each 
 *function to realize a single function,flexibility and versatility.
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_LEN 1024

/*打印带error标志的错误信息，该函数有点鸡肋，只能输入固定的字符串*/
void print_error(const char *error){
    printf("-_-! \033[1;31mError:\033[0m%s\n",error);
}

/*功能:从给定的字符串src中获取目标字段nth,存储在dst中,一般在按行提取配置文件信息是使用;
 *输入:src->"This is a test file." nth->4;获取src的第4个字段"test"
 *输出:dst->"test";
 *返回值:成功返回0，失败返回-1.
 * */
int GetStrFromLine(const char *src,char *dst,int nth){
	int cnt = 1;
	const char *tmpsrc = src;
	char *tmpdst = dst;
	if(nth < 1){
		print_error("the argument nth is too small.\n");
		return -1;
	}
	/*过滤掉开始的空格*/
	while(*tmpsrc == ' '){
		tmpsrc++;
	}
	/*过滤掉空行*/
	if(*tmpsrc == '\r' || *tmpsrc == '\n' || *tmpsrc == '\0'){
		return -1;
	}
	/*过滤前n-1个字段*/
	while(cnt < nth){
		/*空格为字段间隔符号，\r或\n或\0为行结束符号 */
		while(*tmpsrc != ' ' && *tmpsrc != '\r' && *tmpsrc != '\n' && *tmpsrc != '\0'){
			tmpsrc++;
		}
		/*检测行是否结束，来判断是否有指定的字段存在*/
		if(*tmpsrc == '\r' || *tmpsrc == '\n' || *tmpsrc == '\0'){
			print_error("the argument nth is too big\n");
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
		*tmpdst++ = *tmpsrc++;
	}
	*tmpdst = '\0';
	return 0;
}

/*功能:从给定带全路径的文件字符串中获取文件名;
 *输入:path->“/home/cyren/checkfile/a.txt”，
 *输出:name->“a.txt”;
 *返回值:成功返回0，失败返回-1
 * */
int GetNameFromPath(const char *path,char *name){
    const char *tmp = path;    
    const char *mark = NULL;
    char *tmp_name = name;
    while(*tmp != '\0'){
        if(*tmp == '/'){
            mark = tmp;
        }
        tmp++;
    }
    if(mark != NULL){
        mark++;
        if(*mark != '\0'){
            while(*mark != '\0'){
                *tmp_name++ = *mark++;
            }
            *tmp_name = '\0';
            return 0;
        }
        else return -1;
    }
    else return -1;
}
