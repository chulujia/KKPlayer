#include <windows.h>





char* a[]=
{
	"icon/1.png",
	
	
	
	
};






int checkFile()
{
	
	
	
	MessageBox(0,a[0],"�Ҳ����ļ�",MB_OK);
	
	
	
	
	return true;
	
}



int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 
	if(checkFile()!=0)return 1;
	WinExec("KKPlayer.exe KKPlayer",0);


	return 0;
}



