#include "main.h"

int main()
{	
	int i = 0;
	int a = getFiles_path("C:\\Users\\Administrator\\Desktop\\work\\test\\LCS2003034");
	//printf("a = %d\n",a);
	excel_1_init();
	excel_2_init();
	for(i;i < a; i++)	
	{	
		log_to_excel_1(img_files[i]);
		printf("txtÂ·¾¶Îª£º%s\n",img_files[i]);
	}
	log_to_excel_2();
	printf("row = %d\n",row);
	printf("bin1 = %d\n",bin1);
	printf("bin2 = %d\n",bin2);
	printf("bin3 = %d\n",bin3);
	printf("bin4 = %d\n",bin4);
	while(1);
}