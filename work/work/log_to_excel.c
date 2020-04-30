#include "log_to_excel.h"

int getFileSize(char * file)
{	
    int size = -1;
    FILE * path;
    path = fopen(file, "rb");
    if (NULL == path)
    {
        printf("文件打开失败！\n");
        return  size; //文件大小不可能为负数
    }
    else
    {
        while (!feof(path)) // 检测流文件指针是否已到达文件结尾     
        {
            if(fgetc(path) != '\n')//流文件指针向前移动,读取一个字符,指针向前移动一步
			
            size++;
        }
        fclose(path);
        path = NULL;
    }

    return size;

}


void excel_1_init()
{	
	char init1[43][20] = {"ALL","FAIL","PASS","DEVICE","PORT","TEST_TIME","TIME_STAMP","TEST_WAY","ERROR_CODE","TEST_STATUS","ERROR_NFO","BIN","FREQ","VCC1_VALUE","VCC2_VALUE","VCCQ_VALUE","VCC1_IDLE","VCC2_IDLE","VCCQ_IDLE","VCC1_WRITE","VCC2_WRITE","VCCQ_WRITE","VCC1_READ","VCC2_READ","VCCQ_READ","POWER","STM32_VERSION","PRELOADER_VERSION","RECOVERY_VERSION","EMMC_ID","DRAM_ID","DRAM_DIE","DRAM_MR8","DRAM_CHA_R0","DRAM_CHA_R1","DRAM_CHB_R0","DRAM_CHB_R1","DRAM_DENSITY","STM32_ID","SOCKET_COUNT","SOCKET_ID","AGENT_VERSION","AGENT_ID"};
	FILE *fp;
	int k;
	fp = fopen("C:\\Users\\Administrator\\Desktop\\1.xls","a+");
	row = 0;
	
	for(k = 0;k < 43;k++)
	{	
		if(k == 42)
		{	
			fprintf(fp,init1[k]);
			fprintf(fp,"\n");
		}
		else{
			fprintf(fp,init1[k]);
			fprintf(fp,"\t");
		}
		
	}
	fclose(fp);
}

void excel_3_init()
{	
	memset(pl_time,0,sizeof(pl_time));
	memset(pl_error[50],0,sizeof(pl_error[50]));
	memset(android_time,0,sizeof(android_time));
	memset(android_error[50],0,sizeof(android_error[50]));
	memset(common_time,0,sizeof(common_time));
	memset(common_error[50],0,sizeof(common_error[50]));
	common_flag = 0;
	common_type = 0;
	pl_flag = 0;
	pl_type = 0;
	android_flag = 0;
	android_type = 0;
	android = 0;
	common = 0;
	pl = 0;
}
int log_to_excel_1(char *path)
{	
	
	unsigned int z;
	int u;
	int cut_num = 0;
	char error_msg[50];
	char *bin_num = NULL;
	unsigned int k = 0;
	char *arry1 = NULL;
	char *arry = NULL;
	unsigned long i;
	unsigned long num;
	FILE *stream;
	FILE *fp;
	num = getFileSize(path);
	stream = fopen(path,"r");
	printf("log in \n");
	if(stream == NULL)
	{
		perror("open fail!");
		return 0;
	}
	arry = (char *)malloc(num+1);
	*(arry+num) = '\0';
	for(i=0;i<num;i++)
	{	
		arry[i] = fgetc(stream);
	}
	arry1 = strstr(arry,"AGENT_ID;");
	fp = fopen("C:\\Users\\Administrator\\Desktop\\1.xls","a+");
	
	for (k = 10;  k < strlen(arry1); k++)
	 {  
		  if (arry1[k] == ';')
		  {		
			
			  cut_num++;
			 // printf("cut_num = %d",cut_num);
			 if(cut_num == 10)
			 {	  u = 0;
				// printf("msg = %c",arry1[k]);
				memset(error_msg,0,sizeof(error_msg));
				for(z = k+1;arry1[z] != ',' && arry1[z] != ';';z++)
				{	
					//printf("msg = %c",arry1[z]);
					if(arry1[z] != ' ')
					{
						error_msg[u] = arry1[z];
						u++;
					}
					//printf("msg = %d\n",u);		
				}
				//printf("msg =%s\n",error_msg);
				if(strstr(error_msg,"no"));
				
				else if(strstr(error_msg,"PL") != NULL)
				{	
					pl++;
					if(pl_flag == 0)
					{
						strcpy(pl_error[0],error_msg);
						pl_flag = 1;
						pl_time[0]++;
						pl_type++;
					}
					if(pl_flag == 1)
					{
						for(i = 0; i < pl_type; i++)
						{
							if(strcmp(error_msg,pl_error[i]) == 0)
							{
								pl_time[i]++;
								break;
							}
						}
						if(i == pl_type)
						{
							strcpy(pl_error[pl_type],error_msg);
							pl_type++;
						}
					}
					
				}
				else if(((strstr(error_msg,"android") != NULL) )||((strstr(error_msg,"Android") != NULL)))
				{	
					android++;
					if(android_flag == 0)
					{
						strcpy(android_error[0],error_msg);
						android_flag = 1;
						android_time[0]++;
						android_type++;
					}
					if(android_flag == 1)
					{
						for(i = 0; i < android_type; i++)
						{
							if(strcmp(error_msg,android_error[i]) == 0)
							{
								android_time[i]++;
								break;
							}
						}
						if(i == android_type)
						{
							strcpy(android_error[android_type],error_msg);
							android_type++;
						}
					}
				}
				else 
				{	
					common++;
					if(common_flag == 0)
					{
						strcpy(common_error[0],error_msg);
						common_flag = 1;
						common_type++;
						common_time[0]++;
					}
					if(common_flag == 1)
					{
						for(i = 0; i < common_type; i++)
						{
							if(strcmp(error_msg,common_error[i]) == 0)
							{	
								
								common_time[i]++;
								//printf("cownwi = %d",common_time[i]);
								break;
							}
						}
						if(i == common_type)
						{
							strcpy(common_error[common_type],error_msg);
							common_type++;
						}
					}
				}
			 }
				fprintf(fp,"\t");
		  }
		  else if (arry1[k] == ' ')
		  {	  
			continue;
		  }
		  else if (arry1[k] == '\n')
		  {	
			  cut_num = 0;
			  row++;
			if(arry1[k+1] != '\0')
			{
				bin_num = strstr(&arry1[k],"BIN");
			//	printf("bin_num = %c\n",bin_num[3]);
				if(bin_num[3] == '1')
				{
					bin1++;
				}
				else if(bin_num[3] == '2')
				{
					bin2++;
				}
				else if(bin_num[3] == '3')
				{
					bin3++;
				}
				else
				{
					bin4++;
				}
			}
			
			  fprintf(fp,"\n");
		  }
		  else
		  {
		    fprintf(fp,"%c", arry1[k]);
		  }
  
	 }
	free(arry);
	fclose(fp);
	fclose(stream);
}

void excel_2_init()
{
	FILE *fp;
	int k;
	char init2[9][20] = {"total test number","bin1 number","bin2 number","bin3 number","bin4 number","bin1 ratio","bin2 ratio","bin3 ratio","bin4 ratio"};
	bin1 = 0;
	bin2 = 0;
	bin3 = 0;
	bin4 = 0;
	fp = fopen("C:\\Users\\Administrator\\Desktop\\2.xls","a+");
	for(k = 0;k < 9;k++)
	{	
		if(k == 8)
		{	
			fprintf(fp,init2[k]);
			fprintf(fp,"\n");
		}
		else{
			fprintf(fp,init2[k]);
			fprintf(fp,"\t");
		}		
	}
	fclose(fp);
}

void int_to_char(double data)
{	
	FILE *fp;
	char a[10] = {0};	
	fp = fopen("C:\\Users\\Administrator\\Desktop\\2.xls","a+");	
	gcvt(data,3,a);	
	fprintf(fp,a);
	fprintf(fp,"\t");
	fclose(fp);
}
void int_to_char1(int data)
{	
	FILE *fp;
	char a[10] = {0};	
	fp = fopen("C:\\Users\\Administrator\\Desktop\\2.xls","a+");	
	itoa(data,a,10);	
	fprintf(fp,a);
	fprintf(fp,"\t");
	fclose(fp);
}

void log_to_excel_2()
{		
	double bin1_ratio,bin2_ratio,bin3_ratio,bin4_ratio;
	int_to_char1(row);
	int_to_char1(bin1);
	int_to_char1(bin2);
	int_to_char1(bin3);
	int_to_char1(bin4);
	bin1_ratio = (double)bin1/(double)(bin2+bin1+bin3+bin4);
	bin2_ratio = (double)bin2/(double)(bin2+bin1+bin3+bin4);
	bin3_ratio = (double)bin3/(double)(bin2+bin1+bin3+bin4);
	bin4_ratio = (double)bin4/(double)(bin2+bin1+bin3+bin4);
	//printf("bin1 = %lf",bin1_ratio);
	int_to_char(bin1_ratio);
	int_to_char(bin2_ratio);
	int_to_char(bin3_ratio);
	int_to_char(bin4_ratio);
}


void log3(FILE *fp,int mode,int type,int  *time,char (*type_error)[50])
{	
	int i;
	int sum = 0;
	char a[10] = {0};
	char b[10] = {0};
	for(i = 0;i < type;i++)
	{	
		sum += time[i];
		fprintf(fp,type_error[i]);
		fprintf(fp,"\t");
	}
	fprintf(fp,"\n");
	fprintf(fp,"NUMBER");
	fprintf(fp,"\t");
	itoa(mode,b,10);
	fprintf(fp,b);
	fprintf(fp,"\t");
	for(i = 0;i < type;i++)
	{	
		memset(a,0,sizeof(b));
		itoa(time[i],b,10);
		fprintf(fp,b);
		fprintf(fp,"\t");
	}



	fprintf(fp,"\n");
	fprintf(fp,"RATIO");
	fprintf(fp,"\t");
	gcvt((double)mode/(double)(pl+android+common),3,a);	
	fprintf(fp,a);
	fprintf(fp,"\t");
	for(i = 0;i < type;i++)
	{	
		memset(a,0,sizeof(a));
		//ratio = (double)common_time[i]/(double)sum;
		gcvt((double)time[i]/(double)sum,3,a);	
		fprintf(fp,a);
		fprintf(fp,"\t");
	}
}
void log_to_excel_3()
{	
	FILE *fp;
	/*int i;
	int sum = 0;
	double ratio;*/
	char a[10] = {0};
	fp = fopen("C:\\Users\\Administrator\\Desktop\\3.xls","a+");
	fprintf(fp,"\t");
	fprintf(fp,"Common:");
	fprintf(fp,"\t");
	log3(fp,common,common_type,common_time,common_error);

	fprintf(fp,"\n");
	fprintf(fp,"\n");
	fprintf(fp,"\t");
	fprintf(fp,"PL:");
	fprintf(fp,"\t");
	log3(fp,pl,pl_type,pl_time,pl_error);

	fprintf(fp,"\n");
	fprintf(fp,"\n");
	fprintf(fp,"\t");
	fprintf(fp,"ANDROID:");
	fprintf(fp,"\t");
	log3(fp,android,android_type,android_time,android_error);
	fclose(fp);
}