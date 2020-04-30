#include "main.h"


int main()
{	
	
	int a = getFiles_path(LOG_PATH);
	int i = 0;

	excel_1_init();
	excel_2_init();
	excel_3_init();

	for(i;i < a; i++)	
	{	
		log_to_excel_1(img_files[i]);
	}
	log_to_excel_2();
	log_to_excel_3();

	while(1);
}