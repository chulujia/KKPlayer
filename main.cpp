#include "mainwindow.h"
#include <QApplication>

#include <windows.h>  

#include "thread"
using namespace std;



bool  is_KDaemon(int argc, char*ar[])
{

	if (argc != 2)return false;
	string s = ar[1];
	if (s!="KKPlayer")return false;

	return true;
}


int main(int argc, char *argv[])
{


	/*守护进程*/
	/*if (is_KDaemon(argc,argv)==false)
	{
		return 1;
	}
	*/



	/*唯一进程*/
	HANDLE m_Mutex = CreateMutex(NULL, FALSE, L"KKPlayer.exec");
	if (GetLastError() == ERROR_ALREADY_EXISTS)  
	{
		CloseHandle(m_Mutex);
		m_Mutex = NULL;


	
		QSharedMemory share;
		share.setKey("shareMem");


		share.attach();

		share.lock();

		char data=80;

		memcpy((char*)share.data(), &data, qMin(1, share.size()));

		share.unlock();
		share.detach();

		return  1;
	}








	/*注册表*/
	QApplication a(argc, argv);

	{
		QSettings settings("KKPlayer", "set");
		int x = settings.value("runtimes").toInt();/*程序运行次数*/
		settings.setValue("runtimes", ++x);
		settings.sync();
	}


	/*config.ini*/
	{
		QSettings settings("config.ini", QSettings::IniFormat);

		settings.setValue("Version", "1.0 beta");
		settings.setValue("Kernel", "KAudio.dll");
		settings.setValue("SRVport", "80810");
		settings.setValue("IP", "127.0.0.1");
		settings.sync();
	}






	MainWindow w;



	/*加载启动设置*/
	setCenter::load_set();


	if (setCenter::is_load_play == true)
	{
		w.slot_play();
		if (setCenter::is_load_con == true )
		{
			w.plist->setSeekTo(setCenter::getDataByKey("6").toInt());
		}
	}

	if (setCenter::is_load_min == true)
	{
		w.slot_min_();
	}
	else w.show();

	


	w.setLrcVisable(setCenter::is_lrc_show);


	/*运行猪窗口*/
	a.exec();




	CloseHandle(m_Mutex);
	m_Mutex = NULL;
	return 0;
}





