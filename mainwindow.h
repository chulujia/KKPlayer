#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMouseEvent"
namespace Ui {
	class MainWindow;
}

#include "QTableWidget.h"
#include "QProgressBar.h"
#include "QSlider.h"
#include "QLabel.h"
#include <QDialog>
#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QTimer>
#include "QMessageBox.h"
#include <QVBoxLayout>
#include "QTableWidget.h"
#include "qtablewidget.h"
#include "QScrollBar.h"
#include "QTableView.h"
#include "QFileDialog.h"
#include "QHeaderView.h"
#include "QTableWidgetItem"
#include"QSystemTrayIcon.h"
#include "QTextCodec.h"
#include "QSettings.h"
#include "QDesktopServices.h"
#include "QDesktopWidget.h"
#include "QBuffer.h"
#include"QSharedMemory.h"
#include "fstream"
#include "stdlib.h"
#include "QtNetwork/qnetworkaccessmanager.h"
#include "QtNetwork/qnetworkreply.h"
#include "time.h"
#include "QProcess.h"

#include "ui_set.h"
#include "ui_about.h"
#include "ui_info.h"
#include "Audio.h"
#include "ui_yun.h"

using namespace  KAudio;


class MainWindow;
class setCenter;

class setDialog;
class aboutDialog;
class infoDialog;
class yunDialog;


class slider;
class Mlabel;

class FileManger;

class Lrc;

typedef struct
{
	unsigned long hz;
	unsigned short bits;
	unsigned long bps;
}WAV;


enum class    PlayState
{
	pause,
	playing,
	stop,
	none
};

enum class FileType
{
	mp3,
	wav,
	mid,
	wma,
	non,
};

enum class PlayMode
{
	random,
	list,

};



class TableWidget :public QTableWidget
{






};



class  Hash
{
public:
	static unsigned int getHashByKey(const char *key)
	{
		unsigned int len = strlen(key);
		const char *end = key + len;
		unsigned int hash;

		for (hash = 0; key < end; key++)
		{
			hash *= 16777619;
			hash ^= (unsigned int)(unsigned char)toupper(*key);
		}
		return (hash);
	}

};



class setCenter
{


private:
	static void setDefault()
	{
		is_lrc_auto_download = true;
		is_play_auto_next = true;
		is_lrc_show = true;
		is_download_add_to_plist = true;

	}


public:
	static QVariant getRunTimes();/*程序运行次数*/

	static QVariant getDataByKey(QString va);


	static void load_set()
	{

		QSettings settings("KKPlayer", "set");
		is_load_play = settings.value("1").toBool();
		is_load_min = settings.value("2").toBool();
		is_play_auto_next = settings.value("3").toBool();
		is_load_con = settings.value("5").toBool();
		is_play_random = settings.value("7").toBool();
		is_lrc_auto_download = settings.value("8").toBool();
		is_lrc_show = settings.value("9").toBool();
		is_download_covery = settings.value("11").toBool();

		is_download_add_to_plist = settings.value("13").toBool();

		QDir d;

		path_to_download = settings.value("10").toString();
		path_to_cache = settings.value("12").toString();



		if (settings.value("10").toString() == "")/*第一次启动*/
		{
			setDefault();
			path_to_download = d.currentPath() + "/download/";
			if (d.exists(path_to_download) == false)
			{
				d.mkpath(path_to_download);

			}

		}
		if (d.exists(path_to_download) == false)
		{
			d.mkpath(path_to_download);

		}


		if (settings.value("12").toString() == "")/*第一次启动*/
		{

			setDefault();
			path_to_cache = d.currentPath() + "/cache/";
			if (d.exists(path_to_cache) == false)
			{
				d.mkpath(path_to_cache);

			}

		}
		if (d.exists(path_to_cache) == false)
		{
			d.mkpath(path_to_cache);
		}


	}

	static void save_set()
	{

		QSettings settings("KKPlayer", "set");

		settings.setValue("1", is_load_play);
		settings.setValue("2", is_load_min);
		settings.setValue("3", is_play_auto_next);
		settings.setValue("5", is_load_con);
		settings.setValue("7", is_play_random);
		settings.setValue("8", is_lrc_auto_download);
		settings.setValue("9", is_lrc_show);
		settings.setValue("10", path_to_download);
		settings.setValue("12", path_to_cache);

		settings.setValue("13", is_download_add_to_plist);


		settings.setValue("11", is_download_covery);


		settings.sync();

	}


	static bool is_load_play;
	static bool is_load_min;
	static bool is_play_auto_next;
	static bool is_load_con;/*继续上次进度播放*/
	static bool is_play_random;
	static bool is_lrc_auto_download;
	static bool is_lrc_show;
	static bool is_download_covery;
	static bool is_download_add_to_plist;

	static QString path_to_download;
	static QString path_to_cache;

};






class ShareMem
{

public:
	QSharedMemory*share;

	char data;

	~ShareMem()
	{
		share->detach();
		delete share;
	}

	ShareMem();

	bool isNotify();

};


class FileManger
{

public:

	static WAV getWavInfo(QString path);

	static QVariant getFileSize(QString file);

	static QString getFileName(QString file);

	static QString getFileType(QString file);

	static QString getFileArtist(QString file);

	static QString getFileTitle(QString file);
	static QString getFileNameNotEx(QString file);

	static  bool isExist(QString path)
	{
		auto inf = QFileInfo(path);
		return inf.exists();
	}

};




class LrcNet :public  QObject
{
	Q_OBJECT;


private:
	Lrc*lrc;
	QNetworkReply*reply;/* 获取XML*/

	QNetworkReply *repp;/* 获取LRC*/

	QNetworkAccessManager*mang;

	QUrl url;

	QString art;
	QString title;
	QString s;/*存放XML 分析文件*/
	QLabel *lab;/*歌词*/
	QFile *file;/*歌词文件*/


	void download_lrc_by_id(int id);


public:

	~LrcNet();


	void download(QString title = "Dirty Dancer", QString art = "Enrique Iglesias");

	LrcNet(QLabel*label,Lrc*);



	private slots :

	void onDone();

	void onReady();

	void onDone_d();


	void onReady_d();
};


class Lrc
{

public:
	void load();
	bool isNet;/*是否已经启动下载*/
private:

	QMap<int, QString> data;

	QLabel*lab;

	LrcNet *lrcNet;
	bool is_load_succ;/*加载本地文件*/

	MainWindow*p;

	QString path;



	int countTryTo;

public:
	~Lrc()
	{
		delete lrcNet;

	}

	Lrc(QLabel* l, MainWindow*pp);

	void setLrcBytime(int tim);

	void loadFile(QString path);


};






class slider :public  QProgressBar/*进度条*/
{
protected:
	void mousePressEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent *ev);

	MainWindow *p;

public:
	slider(QWidget*p, MainWindow *pp);

};



class Mlabel :public QLabel/*移动窗体*/
{
public:
	Mlabel(QWidget*p = 0) :QLabel(p)
	{
	}
protected:
	int _x;
	int _y;
	void mouseMoveEvent(QMouseEvent *e)
	{
		this->window()->move(e->globalPos().x() - _x, e->globalPos().y() - _y);
	}
	void mousePressEvent(QMouseEvent *e)
	{
		_x = e->localPos().x();
		_y = e->localPos().y();
	}
};





class Plist :public QObject
{
	Q_OBJECT;
public:
	PlayState state;
	Plist();
	Plist(MainWindow*pp);



	QMenu *plist_menu;
	QAction *plist_rig_1;/*播放*/
	QAction*plist_rig_2;/*移除*/
	QAction*plist_rig_3;/*清空*/
	QAction*plist_rig_4;/*属性*/
	QAction*plist_rig_5;/*添加文件*/
	QAction*plist_rig_6;/*添加文件jia*/


	public slots :
	void plistClick(int row, int column);/*shuang击列表回调*/
	void slot_plist_rig(QPoint pos);
	void slot_plist_rig_1();/*播放*/
	void slot_plist_rig_2();/*移除*/
	void slot_plist_rig_3();/*清空*/
	void slot_plist_rig_4();/*属性*/
	void slot_plist_rig_5();/*添加文件*/
	void slot_plist_rig_6();/*添加文件jia*/


public:
	char str[200];
	void play();

	Audio*audio;

	void setSeekTo(int ms);
	void savePlist();/*保存播放列表*/
	void readPlist(QString path);/*读取播放列表*/

	void playSound();
	int playSound(QString file);
	void playSound(int index);
	int  playCacheSound(QString path, QString);


	QTableWidget*plist;/*列表*/
	MainWindow *p;/*父窗体*/
	void addFileTOplist(char*name);/*列表添加文件*/
	void addFileTOplist(QString name);/*列表添加文件 乱码*/

};







class infoDialog :public QDialog
{
	Q_OBJECT;


private:
	int index_1;
	Ui::Dialog3 *ui;
	MainWindow*p;

public:

	~infoDialog()
	{
		delete ui;
	}

	infoDialog(QWidget*ppp = 0, MainWindow*pp = 0);


	void syncByIndex(int index);

	public slots:
	void slot_close()
	{
		close();
	}

	void slot_next();

	void slot_las();

};



enum class Playmode
{
	cache,
	none,
};


class setDialog :public QDialog
{
	Q_OBJECT;

private:

	Ui::Dialog *ui;
	MainWindow *p;

	void syncCacheSize();


public:

	~setDialog()
	{
		delete ui;
	}

	unsigned long long  getCacheSize();

	setDialog(QWidget*p = 0);

	public slots:
	void slot_close();

	void slot_reset();

	void slot_path();
	void slot_path_to_cache();
	void slot_sync();

	void slot_open_path();
	void slot_clearCache();


};







class yunDialog :public QDialog
{
	Q_OBJECT;

	enum class  Status_search
	{
		none,
		searching,/*搜索中*/
		fa,/*搜索失败*/
		succ,
	};

	enum class  Status_download
	{
		none,/*不可见*/
		able,
		downloading,
		completed,
	};

	enum class Status_cache
	{
		none,
		able,
		caching,
		cached,

	};

	Status_download s_download;
	Status_search s_search;
	Status_cache s_cache;

	Status_cache getCacheStaus();

	void setCacheStatus(Status_cache s);


	void setDownloadStatus(Status_download s);

	Status_download getDownloadStatus();

	void setSearchStatus(Status_search s);

	Status_search getSearchStatus();



public:
	QTimer*timer;

	Ui::Dialog5 *ui;
	MainWindow *p;
	void checkForDir();


public:
	bool is_auto_pl_ne;
	yunDialog(QWidget*p = 0);

	void search();
	QNetworkReply*rep_search;
	QNetworkReply*rep_dwn;
	QNetworkAccessManager*mang;

	string reply_buff;

	~yunDialog();

	int getCount();

	QString getUrl();
	QString getDurl();
	QString try_url;
	QString d_url;
	QBuffer buff;
	QString fileName;


private:
	int curentBytes;
	int download_speed;/*b/s*/
	QString cacheFile;

	void start_download(QString &url, bool isCache = false);

	QFile *file;

	public slots:



	void slot_timer();


	void updateDwn(qint64 c, qint64 m);

	void down_done();

	void down_ready();


	void onSearchDone();

	void onSearchReady();

	void onSearchError(QNetworkReply::NetworkError code);

	void slot_close();
	void slot_stop();

	void slot_search();

	void slot_download();

	void slot_try();


};






class aboutDialog :public QDialog
{
	Q_OBJECT;

private:

	Ui::Dialog1 *ui;

public:


	~aboutDialog()
	{
		delete ui;
	}
	aboutDialog(QWidget*p = 0);

	public slots:
	void openUrl(QString url);


protected:
	int _x;
	int _y;

	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);

};







class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	void setPauseStatus();/*设置按钮状态*/
	void setPlayStatus();

	yunDialog*yunDia;

	int now_play_index;

	Lrc *lrc;

	FileType now_play_type;
	Playmode play_mode;

	ShareMem*shareMem;


	explicit MainWindow(QWidget *parent = 0);

	slider *processBar;/*进度条*/
	Mlabel*label;/*移动标签*/
	QTimer *timer;/*定时器*/
	QSystemTrayIcon*tray;
	Plist*plist;


	string getTimeFormat(unsigned long ms);

	public slots:
	void slot_play(void);/*播放回调*/
	void slot_check_(void);/*定时器回调*/
	void slot_min_(void);/*最小化*/
	void slot_about_();
	void slot_set_();
	void slot_set();
	void slot_pause();
	void slot_next();
	void slot_last();
	void slot_tray(QSystemTrayIcon::ActivationReason reason);
	void slot_exit();
	void slot_yun();
	void openUrl(QString url);


private:


	void initWithUi();/*初始化UI*/


	char str[200];
	int a, b, c, d;//time
	string aa, bb, cc, dd;//time
	QString timeString;/*时间*/

	QMenu *menu;/*设置菜单*/

	QAction *about_action;

public:

	void setLrcVisable(bool b);

	~MainWindow()
	{
		delete about_action;
		delete menu;
		delete timer;
		delete label;
		delete processBar;


		delete plist;


		delete ui;

		/*  leak of mem*/
	}


	Ui::MainWindow *ui;
};








#endif // MAINWINDOW_H
