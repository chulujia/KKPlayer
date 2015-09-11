/*
��ԴС�����ֿ� KAuido
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
		char Title[31];   /*����*/
		char Artist[31];  /*������*/
		char Album[31];   /*ר��*/
		char Year[5];   /*���*/
	} MP3TAG;

	typedef struct
	{
		int m;/*��*/
		int s;/*��*/
		int ms;/*����*/

	}time_info;

	/*����*/
	class EXPORT Audio
	{
	public:

		/*���ʵ��*/
		static Audio*getInstance();

		/*���ļ� ����0�ɹ�*/
		int open(char*f);

		/*ֹͣ*/
		void stop();

		/*��ͣ*/
		void pause();

		/*�ر�*/
		void close();

		/*����*/
		void play();

		/*play with start*/
		void rewind();

		/*�ָ�*/
		void resume();

		/*�������� 0-100*/
		void setVolume(int _v = 0);

		/*��� mp3 tag*/
		const MP3TAG& getmp3Tag();
		MP3TAG getmp3Tag(char*file);
	
		/*���ʱ��*/
		const time_info &getTimeInfo();

		/*��õ�ǰʱ�� ms*/
		int getCurrentTime();

		/*���Kbps*/
		int getKbps( char*file);

		/*����ָ��λ�� ms*/
		void setSeekTo(int time_=0);

		/*��ӡ��Ϣ*/
		void priInfo();

		/*����ļ���С*/
		unsigned long getFileSize(char*file);

		/*������ɻص�*/
		std::function<void(void)> callback;

		Audio();
	private:
	
		/*��ȡMP3 TAG*/
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

