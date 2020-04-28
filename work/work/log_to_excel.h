#ifndef _LOG_TO_EXCEL
#define _LOG_TO_EXCEL



#include <stdio.h>
#include "malloc.h"
#include "string.h"
#include <stdio.h>
#pragma warning(disable:4996)
#include<io.h>
#include <stdlib.h>



int getFileSize(char * file);
int log_to_excel_1(char *path);
void excel_1_init();
void excel_2_init();
void log_to_excel_2();
void int_to_char(double data);
void int_to_char1(int data);

unsigned int row;
unsigned int bin1;
unsigned int bin2;
unsigned int bin3;
unsigned int bin4;

#endif