/*
开源小型音乐库 KAuido
designed by hekun 2014-11-27
lib KAudio version 1.0

designed by hekun 2015-08-04
lib KAudio version 1.1

*/
#pragma  once
#ifdef _DLLLL
#define EXPORT    _declspec(dllexport) 
#else 
#define EXPORT   _declspec(dllimport)
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include <Digitalv.h>
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "functional"
using namespace std;
namespace KAudio
{
	typedef struct
	{
		char Title[31];   /*标题*/
		char Artist[31];  /*艺术家*/
		char Album[31];   /*专辑*/
		char Year[5];   /*年份*/
	} MP3TAG;

	typedef struct
	{
		int m;/*分*/
		int s;/*秒*/
		int ms;/*毫秒*/

	}time_info;

	/*单例*/
	class EXPORT Audio
	{
	public:

		/*获得实例*/
		static Audio*getInstance();

		/*打开文件 返回0成功*/
		int open(char*f);

		/*停止*/
		void stop();

		/*暂停*/
		void pause();

		/*关闭*/
		void close();

		/*播放*/
		void play();

		/*play with start*/
		void rewind();

		/*恢复*/
		void resume();

		/*设置音量 0-100*/
		void setVolume(int _v = 0);

		/*获得 mp3 tag*/
		const MP3TAG& getmp3Tag();
		MP3TAG getmp3Tag(char*file);
	
		/*获得时间*/
		const time_info &getTimeInfo();

		/*获得当前时间 ms*/
		int getCurrentTime();

		/*获得Kbps*/
		int getKbps( char*file);

		/*跳到指定位置 ms*/
		void setSeekTo(int time_=0);

		/*打印信息*/
		void priInfo();

		/*获得文件大小*/
		unsigned long getFileSize(char*file);

		/*播放完成回调*/
		std::function<void(void)> callback;

		Audio();
	private:
	
		/*读取MP3 TAG*/
		bool readmp3Tag();
		MP3TAG readmp3Tag(char*file);

		unsigned long fileSize;

		static LRESULT WINAPI _Proc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		HINSTANCE s_hInstance;

		static Audio*_audio;

		MP3TAG mp3info;
		time_info timeinfo;

		HWND _wnd;
		MCIDEVICEID device;
		MCI_OPEN_PARMS mciOpen;
		MCIERROR mciError;
		char*file;
	};

}

