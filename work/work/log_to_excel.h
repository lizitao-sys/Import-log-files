#ifndef _LOG_TO_EXCEL
#define _LOG_TO_EXCEL



#include <stdio.h>
#include "malloc.h"
#include "string.h"
#include <stdio.h>
#pragma warning(disable:4996)
#include<io.h>
#include <stdlib.h>
#include "list.h"


int getFileSize(char * file);
int log_to_excel_1(char *path);
void excel_1_init();
void excel_2_init();
void excel_3_init();
void log_to_excel_2();
void int_to_char(double data);
void int_to_char1(int data);
void log_to_excel_3();

unsigned int row;
unsigned int bin1;
unsigned int bin2;
unsigned int bin3;
unsigned int bin4;

char pl_error[50][50];
char android_error[50][50];
char common_error[50][50];
int pl_time[50],android_time[50],common_time[50];
int pl_flag,pl_type,android_flag,android_type,common_flag,common_type;
int pl,common,android;

#endif