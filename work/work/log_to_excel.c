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
void excel_init()
{	
	char init[43][20] = {"ALL","FAIL","PASS","DEVICE","PORT","TEST_TIME","TIME_STAMP","TEST_WAY","ERROR_CODE","TEST_STATUS","ERROR_NFO","BIN","FREQ","VCC1_VALUE","VCC2_VALUE","VCCQ_VALUE","VCC1_IDLE","VCC2_IDLE","VCCQ_IDLE","VCC1_WRITE","VCC2_WRITE","VCCQ_WRITE","VCC1_READ","VCC2_READ","VCCQ_READ","POWER","STM32_VERSION","PRELOADER_VERSION","RECOVERY_VERSION","EMMC_ID","DRAM_ID","DRAM_DIE","DRAM_MR8","DRAM_CHA_R0","DRAM_CHA_R1","DRAM_CHB_R0","DRAM_CHB_R1","DRAM_DENSITY","STM32_ID","SOCKET_COUNT","SOCKET_ID","AGENT_VERSION","AGENT_ID"};
	FILE *fp;
	int k;
	fp = fopen("C:\\Users\\Administrator\\Desktop\\1.xls","a+");
	for(k = 0;k < 43;k++)
	{	
		if(k == 42)
		{	
			fprintf(fp,init[k]);
			fprintf(fp,"\n");
		}
		else{
			fprintf(fp,init[k]);
			fprintf(fp,"\t");
		}
		
	}
	fclose(fp);
}
int log_to_excel(char *path)
{	
	
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
				fprintf(fp,"\t");
		  }
		  else if (arry1[k] == ' ')
		  {	  
			continue;
		  }
		   else if (arry1[k] == '\n')
		  {	
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
