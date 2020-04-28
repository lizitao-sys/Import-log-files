#include  "search_dir.h"

int num_of_img = 0;
int getFiles_path(char* path)
{	
	
	
	char files_name[100];
	int flag = 0;
	
	long   hFile = 0;
	struct _finddata_t fileinfo;
	char p[700] = { 0 };
	strcpy(p, path);
	strcat(p, "\\*");
	if ((hFile = _findfirst(p, &fileinfo)) != -1)
	{	
		do
		{
		if ((fileinfo.attrib & _A_SUBDIR))
		{
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
			{
				continue;
			}
			else
			{
				strcpy( files_name, path);
				strcat(files_name,"\\");
				strcat(files_name,fileinfo.name);
				//printf("files_name = %s\n",files_name);
				getFiles_path(files_name);
			}
		}
		else
		{
			strcpy(img_files[num_of_img], path);
			strcat(img_files[num_of_img], "\\");
			strcat(img_files[num_of_img], fileinfo.name);
			
			num_of_img++;
			
			}
			} while (_findnext(hFile, &fileinfo) == 0);
			_findclose(hFile);
		}
		return num_of_img;
	}

