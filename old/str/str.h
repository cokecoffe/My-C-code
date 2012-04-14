#ifndef STR
#define STR

#include<stdio.h>
#define OK 1
#define ERR -1
extern char *str_cpy(char *,char *);
extern char *change(char *);//反转字符串
extern int in_change(char *,char *);//将第一个string1，放到string2 3个一空个
extern int choose_max(const char*,const char*,char *);

extern int str_len(char *);
extern char *str_cpy(char*,const char*);
extern int str_cmp(const char *,const char *);
extern char *str_cat(char*,const char*);
#endif
