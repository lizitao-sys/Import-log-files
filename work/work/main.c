#include "main.h"

int main()
{	
	int i = 0;
	int a = getFiles_path("C:\\Users\\Administrator\\Desktop\\work\\test\\LCS2003034");
	//printf("a = %d\n",a);
	excel_init();
	for(i;i < a; i++)	
	{	
		log_to_excel(img_files[i]);
		printf("txtÂ·¾¶Îª£º%s\n",img_files[i]);
	}
	//while(1);
}