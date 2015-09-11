#include "mainwindow.h"
#include "ui_mainwindow.h"


#pragma comment(lib, "KAudio.lib")  


bool setCenter::is_load_play = 0;
bool setCenter::is_load_min = 0;
bool setCenter::is_play_auto_next = 0;
bool setCenter::is_load_con = 0;
bool setCenter::is_play_random = false;
bool setCenter::is_lrc_auto_download = false;
bool setCenter::is_lrc_show = false;
bool setCenter::is_download_covery = false;
bool setCenter::is_download_add_to_plist = false;
QString setCenter::path_to_download;
QString setCenter::path_to_cache;

bool slider_ = false;



QVariant setCenter::getRunTimes()
{
	QSettings settings("KKPlayer", "set");
	return settings.value("runtimes");/*程序运行次数*/

}


QVariant  setCenter::getDataByKey(QString va)
{
	QSettings settings("KKPlayer", "set");
	return settings.value(va);
}


ShareMem::ShareMem()
{

	share = new QSharedMemory("shareMem");

	data = 2;
	cout << " create shareMem status :  " << share->create(1, QSharedMemory::ReadWrite) << endl;;

	share->lock();

	memcpy((char*)share->data(), &data, qMin(1, share->size()));

	share->unlock();

	//share->detach();
	//delete share;

}

bool  ShareMem::isNotify()
{


	QSharedMemory share;
	share.setKey("shareMem");
	share.attach();
	share.lock();

	memcpy(&data, share.data(), 1);


	share.unlock();
	share.detach();

	if (data == 2)return false;


	share.attach();
	share.lock();

	data = 2;
	memcpy((char*)share.data(), &data, qMin(1, share.size()));
	share.unlock();
	share.detach();

	return true;

}





LrcNet::~LrcNet()
{

	delete mang;

	if (repp){ delete repp; }

	if (reply){ delete reply; }

	if (file){ delete file; }

}



void  LrcNet::download(QString title , QString art)
{

	cout << "check for lrc in net " << endl;
	this->title = title;
	this->art = art;

	QString s = "http://box.zhangmen.baidu.com/x?op=12&count=1&title=";
	s = s + title;
	s = s + "$$";
	s = s + art;
	s = s + "$$$$";

	url = s;

	reply = mang->get(QNetworkRequest(url));

	connect(reply, SIGNAL(readyRead()), this, SLOT(onReady()));
	connect(reply, SIGNAL(finished()), this, SLOT(onDone()));

}



void  LrcNet::download_lrc_by_id(int id)
{
	if (id == 0)
	{

		lab->setText("\346\234\252\346\211\276\345\210\260\346\255\214\350\257\215");/*未找到歌词*/
		return;
	}

	lab->setText("\346\255\214\350\257\215\344\270\213\350\275\275\344\270\255...");/*下载中*/

	QString s = "http://box.zhangmen.baidu.com/bdlrc/";

	s = s + QVariant(id / 100).toString() + "/" + QVariant(id).toString() + ".lrc";

	url = s;
	repp = mang->get(QNetworkRequest(url));

	connect(repp, SIGNAL(readyRead()), this, SLOT(onReady_d()));
	connect(repp, SIGNAL(finished()), this, SLOT(onDone_d()));

	QDir d;

	if (d.exists("Lyrics/") == false)
	{
		d.mkpath("Lyrics/");
	}

	QString path = "Lyrics/" + art + " - " + title + ".lrc";

	file = new QFile(path);
	file->open(QIODevice::WriteOnly);
	
}






LrcNet::LrcNet(QLabel*label,Lrc*lrc)
{
	lab = label;
	mang = new QNetworkAccessManager();
	this->lrc = lrc;
}


void  LrcNet:: onDone()/*下载分析文件完成*/
{
	string ss = s.toStdString();
	if (ss.size() < 5)return;
	int x = ss.find("<lrcid>");
	int y = ss.find("</lrcid>");

	cout << "lrc id = " << ss.substr(x + 7, y - x - 7) << endl;;
	//cout << ss;


	reply->close();
	delete reply;
	reply = nullptr;

	s.clear();


	download_lrc_by_id(QVariant(ss.substr(x + 7, y - x - 7).c_str()).toInt());

}


void  LrcNet::onReady()
{
	s = reply->readAll();

}


void  LrcNet::onDone_d()/*下载完毕*/
{

	file->flush();
	file->close();

	delete file;
	file = nullptr;

	repp->deleteLater();
	repp = nullptr;

	lab->setText("\346\255\214\350\257\215\344\270\213\350\275\275\345\256\214\346\210\220");/*下载完成*/
	lrc->isNet = false;
	lrc->load();

}


void  LrcNet::onReady_d()
{

	file->write(repp->readAll());


}









void  Lrc::setLrcBytime(int tim)
{
	if (is_load_succ == false)
	{
	/*	countTryTo++;
	//	if (countTryTo > 100)return;
		cout << "loading lrv" << endl;
		load();*/
	}
	if (data.contains(tim))
	{

		//lab->setVisible(setCenter::is_lrc_show);

		lab->setText(data[tim]);

	}

}




void  Lrc::loadFile(QString path)/*加载歌词文件 path位歌曲地址*/
{


	countTryTo = 0;
	isNet = false;

	data.clear();


	lab->setText("\346\237\245\346\211\276\346\255\214\350\257\215\344\270\255...");/*查找歌词中*/


	path = "Lyrics/" + FileManger::getFileNameNotEx(path);
	path += ".lrc";

	this->path = path;


	
	load();
}





Lrc::Lrc(QLabel* l, MainWindow*pp) :lab(l), p(pp)
{
	//	cout << "init Lrc" << endl;
	lab->setAlignment(Qt::AlignCenter);
	is_load_succ = false;
	isNet = false;



	lrcNet = new LrcNet(l,this);

}

void Lrc::load()
{
	if (isNet == true)return;
	QFile file(this->path);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		is_load_succ = false;

		lab->setText("\346\234\252\346\211\276\345\210\260\346\255\214\350\257\215");/*未找到歌词*/

		cout << "load lrc error" << endl;

		if (setCenter::is_lrc_auto_download == false)return;


		if (isNet == false)
		{
			if (p->play_mode == Playmode::cache)
			{

				lrcNet->download(
					p->yunDia->ui->input_title->text(),
					p->yunDia->ui->input_art->text()


					);

			}
			else
			{
				lrcNet->download(
					p->plist->plist->item(p->now_play_index, 0)->text(),
					p->plist->plist->item(p->now_play_index, 1)->text()
					);
			}

			isNet = true;
		}



		return;
	}

	QString time_, lrc, str;

	string tmp;

	int x;
	while (!file.atEnd())
	{
		str = QString::fromLocal8Bit(file.readLine().data());

		tmp = str.toStdString();
		time_ = tmp.substr(1, str.indexOf(']') - 1).c_str();

		lrc = tmp.substr(str.indexOf(']') + 1, -1).c_str();

		//cout << time_.toStdString().c_str() <<"   "<<lrc.toStdString()<< endl;
		tmp = time_.toStdString();

		x = QVariant(tmp.substr(0, 2).c_str()).toInt();
		x *= 60;

		x += QVariant(tmp.substr(tmp.find(':') + 1, 2).c_str()).toInt();

		data[x] = lrc;

		//	cout << time_.toStdString() << "  " << lrc.toStdString() << endl;
			
	}
	file.close();
	isNet = false;
	is_load_succ = true;
//	cout << "load lrc succ" << endl;

}




WAV  FileManger::getWavInfo(QString path)
{
	WAV wav;

	fstream fs;
	auto	code = QTextCodec::codecForName("gb18030");

	std::string name1;
	name1 = code->fromUnicode(path.toStdString().c_str()).data();

	char*name = (char*)name1.c_str();

	fs.open(name, ios::binary | ios::in);

	fs.seekg(0x18);
	fs.read((char*)&wav.hz, sizeof(wav.hz));

	fs.seekg(0x1c);
	fs.read((char*)&wav.bps, sizeof(wav.bps));

	fs.seekg(0x22);
	fs.read((char*)&wav.bits, sizeof(wav.bits));

	fs.close();
	return wav;

}





QVariant  FileManger::getFileSize(QString file)
{
	FILE * fp;
	auto	code = QTextCodec::codecForName("gb18030");
	std::string name1;
	name1 = code->fromUnicode(file.toStdString().c_str()).data();

	char*file1 = (char*)name1.c_str();

	fp = fopen(file1, "rb");

	if (fp == NULL)return 0;
	fseek(fp, 0, SEEK_END);
	unsigned int fileSize = ftell(fp);
	fclose(fp);
	return  QVariant(fileSize);
}




QString FileManger::getFileName(QString file)
{
	auto inf = QFileInfo(file);
	return inf.fileName();
}



QString  FileManger::getFileType(QString file)
{
	QString x = getFileName(file);
	QString l;

	for (int q = x.length() - 3; q < x.length(); q++)
	{
		l += x[q];
	}
	return l.toLower();
}




QString  FileManger::getFileArtist(QString file)
{
	QString name = getFileNameNotEx(file);
	string xx = name.toStdString();

	try
	{
		if (xx.find(" - ") >= 500)
		{
			return "\346\234\252\347\237\245";
		}

		name = xx.substr(0, xx.find(" - ")).c_str();
	}
	catch (...)
	{
		name = "\346\234\252\347\237\245";
	}

	return name;
}



QString FileManger::getFileTitle(QString file)
{

	QString name = getFileNameNotEx(file);
	string xx = name.toStdString();

	try
	{
		if (xx.find(" - ") >= 500)
		{

			return getFileNameNotEx(file);
		}

		name = xx.substr(xx.find(" - ") + 3, -1).c_str();

	}
	catch (...)
	{
		name = getFileNameNotEx(file);
	}
	return name;

}


QString  FileManger::getFileNameNotEx(QString file)
{
	QString name = getFileName(file);
	string xx = name.toStdString();
	name = xx.substr(0, xx.find_last_of('.')).c_str();
	return name;
}




slider::slider(QWidget*p, MainWindow *pp) :QProgressBar(p)
{
	this->p = pp;

	setObjectName(QStringLiteral("horizontalSlider"));
	setGeometry(QRect(200, 500, 450, 5));
	setMaximum(1000000);
	setMinimum(0);
	//setOrientation();
	setCursor(Qt::PointingHandCursor);
	setFormat("");
	setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\346\222\255\346\224\276\350\277\233\345\272\246</p></body></html>", 0));

}


void slider::mousePressEvent(QMouseEvent *ev)
{
	slider_ = true;

}
void  slider::mouseReleaseEvent(QMouseEvent *ev)
{

	float x = ev->localPos().x() / (this->width() + 0.0);
	if (x >= 1)x = 1;
	if (x <= 0)x = 0;
	Audio::getInstance()->setSeekTo(
		x  * Audio::getInstance()->getTimeInfo().ms

		);

	cout << this->value() / 1000000.0  *Audio::getInstance()->getTimeInfo().ms << "    ..." << Audio::getInstance()->getTimeInfo().ms << endl;

	if (p->plist->state == PlayState::playing)

	{
		Audio::getInstance()->play();

	}

	slider_ = false;
}



void   slider::mouseMoveEvent(QMouseEvent *ev)
{

	this->setValue(
		ev->localPos().x() / (this->width() + 0.0) *1000000.0
		);
}





void aboutDialog::openUrl(QString url)
{
	QDesktopServices::openUrl(QUrl(url));

}


void aboutDialog::mouseMoveEvent(QMouseEvent *e)
{
	this->move(e->globalPos().x() - _x, e->globalPos().y() - _y);
}


void aboutDialog::mousePressEvent(QMouseEvent *e)
{
	_x = e->localPos().x();
	_y = e->localPos().y();
}



aboutDialog::aboutDialog(QWidget*p) :QDialog(p)
{
	ui = new Ui::Dialog1;
	ui->setupUi(this);

	move(p->pos().x() + (p->width() - this->width()) / 2,
		p->pos().y() + (p->height() - this->width()));

	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));

	/*close*/
	ui->pushButton->setStyleSheet("QPushButton{border-image: url(icon/close2.png);}"
		"QPushButton:hover{border-image: url(icon/close1.png);}"
		"QPushButton:pressed{border-image: url(icon/close1.png);}");


	/*icon*/
	ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(icon/icon.png);}"
		"QPushButton:hover{border-image: url(icon/icon.png);}"
		"QPushButton:pressed{border-image: url(icon/icon.png);}");


	connect(ui->label_6, SIGNAL(linkActivated(QString)), this, SLOT(openUrl(QString)));

	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);



	ui->label_8->setText(setCenter::getRunTimes().toString());




}



infoDialog::infoDialog(QWidget*ppp, MainWindow*pp) :QDialog(ppp)
{
	ui = new Ui::Dialog3;

	ui->setupUi(this);
	this->p = pp;
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_close()));

	/*close*/
	ui->pushButton->setStyleSheet("QPushButton{border-image: url(icon/close2.png);}"
		"QPushButton:hover{border-image: url(icon/close1.png);}"
		"QPushButton:pressed{border-image: url(icon/close1.png);}");


	ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(icon/next1.png);}"
		"QPushButton:hover{border-image: url(icon/next2.png);}"
		"QPushButton:pressed{border-image: url(icon/next2.png);}");



	ui->pushButton_3->setStyleSheet("QPushButton{border-image: url(icon/las1.png);}"
		"QPushButton:hover{border-image: url(icon/las2.png);}"
		"QPushButton:pressed{border-image: url(icon/las2.png);}");




	move(p->pos().x() + (p->width() - this->width()) / 2,
		p->pos().y() + (p->height() - this->width()));


	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);

	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_next()));
	connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(slot_las()));


	syncByIndex(p->plist->plist->currentRow());



}

void infoDialog::slot_next()
{

	syncByIndex((index_1 + 1) % p->plist->plist->rowCount());

}

void infoDialog::slot_las()
{

	if (index_1 <= 0)
	{
		syncByIndex(p->plist->plist->rowCount() - 1);

		return;
	}

	syncByIndex((index_1 - 1) % p->plist->plist->rowCount());

}
void  infoDialog::syncByIndex(int index)
{


	index_1 = index;
	QString file = p->plist->plist->item(index, 4)->text();

	ui->label_18->setText(file);
	ui->label_18->setToolTip(file);








	/*int xqqqq= (FileManger::getFileSize(file).toInt());





	int xa = 0;
	while (xqqqq)
	{
	xqqqq/= 1024;
	xa++;
	}


	QString wq;

	switch (xa)
	{
	case  0:wq = " Bytes";break;
	case  1:wq = " KBytes"; break;
	case  2:wq = " MBytes"; break;
	case  3:wq = " GBytes"; break;
	case  4:wq = " TBytes"; break;

	default:
	break;
	}

	*/

	ui->label_5->setText(FileManger::getFileSize(file).toString() + "  Byte");
	ui->label_5->setToolTip(ui->label_5->text());





	ui->label_2->setText(FileManger::getFileName(file));
	ui->label_2->setToolTip(ui->label_2->text());




	if (FileManger::getFileType(file) == "mp3")
	{
		ui->label_9->setText("44100 Hz");/**/
		ui->label_9->setToolTip(ui->label_9->text());

		auto	code = QTextCodec::codecForName("gb18030");
		std::string name1;
		name1 = code->fromUnicode(file.toStdString().c_str()).data();

		char*file1 = (char*)name1.c_str();

		ui->label_24->setText(QString::fromLocal8Bit(p->plist->audio->getmp3Tag(file1).Year));

		if (ui->label_24->text() == "")
		{
			ui->label_24->setText("\346\234\252\347\237\245");
		}
		ui->label_24->setToolTip(ui->label_24->text());

		ui->label_23->setText(QString::fromLocal8Bit(p->plist->audio->getmp3Tag(file1).Album));/*专辑*/

		if (ui->label_23->text() == "")
		{
			ui->label_23->setText(p->plist->plist->item(index, 0)->text());
		}

		ui->label_23->setToolTip(ui->label_23->text());

		ui->label_27->setText("16 bits");

	}
	else 	if (FileManger::getFileType(file) == "wav")
	{
		WAV wav = FileManger::getWavInfo(file);

		QString xx;

		xx = QVariant((long)wav.hz).toString() + " Hz";
		ui->label_9->setText(xx);/**/
		ui->label_9->setToolTip(ui->label_9->text());


		ui->label_24->setText("\346\234\252\347\237\245");
		ui->label_24->setToolTip(ui->label_24->text());

		ui->label_23->setText(p->plist->plist->item(index, 0)->text());/*专辑*/
		ui->label_23->setToolTip(p->plist->plist->item(index, 0)->text());


		xx = QVariant((short)wav.bits).toString() + " Bits";

		ui->label_27->setText(xx);/**/
		ui->label_27->setToolTip(ui->label_9->text());

		// ui->label_27->setText("16 bits");

	}

	else/* general*/
	{



		ui->label_9->setText("44100 Hz");/**/
		ui->label_9->setToolTip(ui->label_9->text());


		ui->label_24->setText("\346\234\252\347\237\245");
		ui->label_24->setToolTip(ui->label_24->text());

		ui->label_23->setText(p->plist->plist->item(index, 0)->text());/*专辑*/
		ui->label_23->setToolTip(p->plist->plist->item(index, 0)->text());


		ui->label_27->setText("16 Bits");/**/
		ui->label_27->setToolTip(ui->label_9->text());


	}



	ui->label_19->setText(p->plist->plist->item(index, 2)->text());
	ui->label_19->setToolTip(p->plist->plist->item(index, 2)->text());

	ui->label_20->setText(p->plist->plist->item(index, 3)->text());
	ui->label_20->setToolTip(p->plist->plist->item(index, 3)->text());







	ui->label_22->setText(p->plist->plist->item(index, 0)->text());/*标题*/
	ui->label_22->setToolTip(p->plist->plist->item(index, 0)->text());

	ui->label_21->setText(p->plist->plist->item(index, 1)->text());/*艺术家*/
	ui->label_21->setToolTip(p->plist->plist->item(index, 0)->text());










	file = QVariant(index + 1).toString() + " / ";

	file += QVariant(p->plist->plist->rowCount()).toString();

	ui->label_25->setText(file);



}




/*
void my_thread(MainWindow *p)
{

Sleep(3000);

// load_mutex.lock();

p->plist->readPlist("");
// load_mutex.unlock();
return;

}

*/








MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow),
yunDia(0)
{


	ui->setupUi(this);
	this->setWindowTitle("KKPlayer");

	now_play_index = -200;
	//btnClick();
	initWithUi();


	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);


	processBar->setValue(0);

	ui->pushButton->setVisible(true);
	ui->pushButton_7->setVisible(false);




	//托盘  
	QIcon icon = QIcon("icon/icon.png");
	this->setWindowIcon(icon);
	tray = new QSystemTrayIcon(this);

	tray->setIcon(icon);
	tray->setToolTip("KKPlayer");

	connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slot_tray(QSystemTrayIcon::ActivationReason)));

	play_mode = Playmode::none;

	QSettings settings("KKPlayer", "set");/*条目*/
	now_play_index = settings.value("4").toInt();

	plist = new Plist((MainWindow*)this);



	shareMem = new ShareMem();




	timer = new QTimer;
	connect(this->timer, SIGNAL(timeout()), this, SLOT(slot_check_()));
	timer->start(300);

	lrc = new Lrc(ui->label_4, this);



	srand(time(0));



}





string  MainWindow::getTimeFormat(unsigned long ms)
{

	string  st;
	a = ms / 1000.0 / 60.0;
	if (a <= 9)
	{
		sprintf(str, "0%d", a);
		aa = str;
	}
	else
	{
		sprintf(str, "%d", a);
		aa = str;
	}

	b = ms / 1000 - ms / 1000 / 60 * 60;

	if (b <= 9)
	{
		sprintf(str, "0%d", b);
		bb = str;
	}
	else
	{
		sprintf(str, "%d", b);
		bb = str;
	}

	st = (aa + ":" + bb).c_str();

	return st;
}


void MainWindow::initWithUi()
{

	/*进度条*/
	processBar = new slider(ui->centralWidget, this);

	/*移动标签*/
	label = new Mlabel(ui->centralWidget);
	label->setObjectName(QStringLiteral("label"));
	label->setGeometry(QRect(0, 0, 480, 45));
	label->setText("");
	label->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\347\247\273\345\212\250</p></body></html>", 0));
	label->setCursor(Qt::SizeAllCursor);


	/*下一曲*/
	ui->pushButton_4->setStyleSheet("QPushButton{border-image: url(icon/ico_42x_Next_disabled.png);}"
		"QPushButton:hover{border-image: url(icon/ico_42x_Next_active.png);}"
		"QPushButton:pressed{border-image: url(icon/ico_42x_Next_active.png);}");

	/*上一曲*/
	ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(icon/ico_42x_Previous_disabled.png);}"
		"QPushButton:hover{border-image: url(icon/ico_42x_Previous_active.png);}"
		"QPushButton:pressed{border-image: url(icon/ico_42x_Previous_active.png);}");

	/*bof*/
	ui->pushButton->setStyleSheet("QPushButton{border-image: url(icon/ico_42x_Play_disabled.png);}"
		"QPushButton:hover{border-image: url(icon/ico_42x_Play_active.png);}"
		"QPushButton:pressed{border-image: url(icon/ico_42x_Play_active.png);}");


	/*pause*/
	ui->pushButton_7->setStyleSheet("QPushButton{border-image: url(icon/ico_42x_Pause_disabled.png);}"
		"QPushButton:hover{border-image: url(icon/ico_42x_Pause_active.png);}"
		"QPushButton:pressed{border-image: url(icon/ico_42x_Pause_active.png);}");



	/*close*/
	ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(icon/close2.png);}"
		"QPushButton:hover{border-image: url(icon/close1.png);}"
		"QPushButton:pressed{border-image: url(icon/close1.png);}");


	/*min*/
	ui->pushButton_3->setStyleSheet("QPushButton{border-image: url(icon/min1.png);}"
		"QPushButton:hover{border-image: url(icon/min2.png);}"
		"QPushButton:pressed{border-image: url(icon/min2.png);}");



	/*set*/
	ui->pushButton_6->setStyleSheet("QPushButton{border-image: url(icon/set1.png);}"
		"QPushButton:hover{border-image: url(icon/set2.png);}"
		"QPushButton:pressed{border-image: url(icon/set2.png);}");


	/*set*/
	ui->pushButton_8->setStyleSheet("QPushButton{border-image: url(icon/yun.png);}"
		"QPushButton:hover{border-image: url(icon/yun1.png);}"
		"QPushButton:pressed{border-image: url(icon/yun1.png);}");


	ui->label->setAlignment(Qt::AlignLeft);



	this->connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_play()));

	this->connect(this->ui->pushButton_4, SIGNAL(clicked()), this, SLOT(slot_next()));/*next*/
	this->connect(this->ui->pushButton_5, SIGNAL(clicked()), this, SLOT(slot_last()));/*lase*/

	this->connect(this->ui->pushButton_7, SIGNAL(clicked()), this, SLOT(slot_pause()));/*pause*/



	this->connect(this->ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_exit()));/*gclose*/
	this->connect(this->ui->pushButton_3, SIGNAL(clicked()), this, SLOT(slot_min_()));

	this->connect(this->ui->pushButton_8, SIGNAL(clicked()), this, SLOT(slot_yun()));



	about_action = new QAction("\345\205\263\344\272\216", this);

	auto set_action = new QAction("\350\256\276\347\275\256", this);


	connect(about_action, SIGNAL(triggered()), this, SLOT(slot_about_()));

	connect(set_action, SIGNAL(triggered()), this, SLOT(slot_set_()));



	//sub_menu = new QMenu(tr("control"), this);
	//sub_menu->addAction(add_action);
	//	sub_menu->addAction(about_action);



	//	ui->pushButton_6->setMenu(menu);

	menu = new QMenu(this);

	menu->addAction(set_action);
	menu->addAction(about_action);



	connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(slot_set()));



	connect(ui->label_5, SIGNAL(linkActivated(QString)), this, SLOT(openUrl(QString)));



	/*QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(ui->pushButton_6);

	setLayout(layout);
	*/

}


void  MainWindow::setLrcVisable(bool b)
{
	ui->label_4->setVisible(b);

}

void MainWindow::openUrl(QString url)
{
	QDesktopServices::openUrl(QUrl(url));

}


void MainWindow::slot_about_()
{
	aboutDialog*m_ = new aboutDialog(this);
	QApplication::alert(m_, 3000);
	m_->move(m_->pos().x(), m_->pos().y() + 50);
	m_->exec();

	delete m_;

}





void  MainWindow::slot_play(void)
{

	if (now_play_index <= -10)
	{
		if (plist->plist->rowCount() <= 0)return;
		plist->playSound(now_play_index);
		plist->state = PlayState::playing;
		setPlayStatus();
		return;
	}


	if (plist->state == PlayState::stop)
	{

		plist->playSound(now_play_index);
		plist->state = PlayState::playing;
		//setPlayStatus();

		return;

	}


	if (plist->state == PlayState::pause)
	{

		Audio::getInstance()->play();

		plist->state = PlayState::playing;
		setPlayStatus();

		return;

	}


	if (plist->plist->rowCount() > 0)

	{

		now_play_index %= plist->plist->rowCount();


		plist->playSound(now_play_index);


		setPlayStatus();



		plist->state = PlayState::playing;

		return;
	}



	setPauseStatus();

}


void MainWindow::slot_pause()
{

	if (plist->state == PlayState::stop)
	{
		Audio::getInstance()->stop();
		ui->pushButton->setVisible(true);
		ui->pushButton_7->setVisible(false);
		return;
	}


	Audio::getInstance()->pause();/*  bug*/

	ui->pushButton->setVisible(true);
	ui->pushButton_7->setVisible(false);
	plist->state = PlayState::pause;


}




void MainWindow::slot_min_()
{
	this->hide();
	tray->show();
}


void MainWindow::slot_set_()
{
	auto s = new setDialog(this);


	s->move(pos().x(), pos().y() + 40);

	s->exec();
	delete s;
}

void MainWindow::slot_set()
{
	menu->exec(QPoint(QCursor::pos().x(), QCursor::pos().y() + 15));

}


void MainWindow::slot_exit()
{
	QSettings settings("KKPlayer", "set");
	settings.setValue("4", now_play_index);

	settings.setValue("6", plist->audio->getCurrentTime());

	this->close();

}


void MainWindow::slot_next()
{
	if (plist->plist->rowCount() <= 0)return;

	if (setCenter::is_play_random == true)
	{

		plist->playSound(rand() % plist->plist->rowCount());

		return;
	}

	plist->playSound((now_play_index + 1) % plist->plist->rowCount());


}

void MainWindow::slot_last()
{
	if (plist->plist->rowCount() <= 0)return;
	cout << now_play_index << "  ";
	if (now_play_index <= 0)
	{
		plist->state = PlayState::stop;
		plist->playSound(plist->plist->rowCount() - 1);
		return;
	};
	plist->state = PlayState::stop;

	plist->playSound((now_play_index - 1));
}


void MainWindow::slot_yun()
{

	yunDia = new yunDialog(this);


	yunDia->move(pos().x() + 10, pos().y() + 45);

	yunDia->exec();
	delete yunDia;

	yunDia = nullptr;


}



void MainWindow::slot_tray(QSystemTrayIcon::ActivationReason reason)
{
	//触发后台图标执行相应事件  
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:/*单击*/
	{
									  tray->hide();
									  this->show();


	}
	default:
		break;
	}
}




















//setDialog *dia = nullptr;


void MainWindow::slot_check_()
{


	/* leak of mem test*/


	/*if (dia == nullptr)
	{
	dia = new setDialog(this);
	dia->show();


	}
	else
	{

	dia->close();
	delete dia;
	dia = nullptr;
	}

	*/

	/* end of mem*/


	if (shareMem->isNotify() == true)
	{

		slot_tray(QSystemTrayIcon::Trigger);

		QApplication::alert(this, 3000);
	}


	if (slider_ == false)
	{

		processBar->setValue(plist->audio->getCurrentTime() / (plist->audio->getTimeInfo().ms + 0.0) * 1000000.0);



	}

	if (plist->audio->getCurrentTime() <= 0)
	{
		processBar->setValue(0);

		ui->label->setText((getTimeFormat(0) + " / " + getTimeFormat(0)).c_str());

	}

	else
	{
		if (now_play_type == FileType::mid)
		{


			ui->label->setText((getTimeFormat(plist->audio->getCurrentTime() * 100) + " / " + getTimeFormat(plist->audio->getTimeInfo().ms * 100)).c_str());
		}
		else
		{
			ui->label->setText((getTimeFormat(plist->audio->getCurrentTime()) + " / " + getTimeFormat(plist->audio->getTimeInfo().ms)).c_str());
			lrc->setLrcBytime(plist->audio->getCurrentTime() / 1000);

		}
	}



	if (plist->audio->getTimeInfo().ms < 1)/**/
	{
		return;

	}


	if (plist->state != PlayState::playing)
	{
		tray->setToolTip("KKPlayer");

	}


	if (plist->audio->getCurrentTime() >= plist->audio->getTimeInfo().ms)/*播放完成*/
	{
		plist->state = PlayState::stop;


	}


	if (plist->state == PlayState::stop)/*已停止*/
	{
		if (play_mode == Playmode::cache)
		{
			if (yunDia)
			{
				yunDia->slot_stop();
			}

			return;
		}
		slot_pause();


		if (plist->plist->rowCount() <= 0)/*无列表*/
		{
			//	now_play_index = -222;
			slot_pause();
		}

		if (setCenter::is_play_auto_next == true && play_mode == Playmode::none)
		{
			plist->state = PlayState::pause;


			slot_play();
			slot_next();
		}

		return;
	}




}



void  MainWindow::setPauseStatus()
{
	ui->pushButton->setVisible(true);
	ui->pushButton_7->setVisible(false);


}
void   MainWindow::setPlayStatus()
{
	ui->pushButton->setVisible(false);
	ui->pushButton_7->setVisible(true);

}



Plist::Plist(MainWindow*pp)
{

	audio = Audio::getInstance();

	this->p = pp;

	state = PlayState::none;


	QTableWidget* table_widget = p->ui->tableWidget;

	plist = p->ui->tableWidget;

	table_widget->setColumnCount(5);/* 一首歌*/


	table_widget->horizontalHeader()->setDefaultSectionSize(150);
	table_widget->horizontalHeader()->setSectionsClickable(false); //设置表头不可点击（默认点击后进行排序）

	//设置表头内容
	QStringList header;
	header << "\346\240\207\351\242\230" << "\350\211\272\346\234\257\345\256\266" << "\346\257\224\347\211\271\347\216\207" << "\346\227\266\351\227\264" << "";


	table_widget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);



	table_widget->setHorizontalHeaderLabels(header);

	//设置表头字体
	QFont font = table_widget->horizontalHeader()->font();
	font.setBold(true);
	table_widget->horizontalHeader()->setFont(font);

	table_widget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);


	table_widget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度

	table_widget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	table_widget->verticalHeader()->setDefaultSectionSize(10); //设置行高
	table_widget->setFrameShape(QFrame::NoFrame); //设置无边框
	table_widget->setShowGrid(false); //设置不显示格子线
	table_widget->verticalHeader()->setVisible(false); //设置垂直头不可见

	//table_widget->setSelectionMode(QAbstractItemView::UNS);  //可多选（Ctrl、Shift、  Ctrl+A都可以）
	table_widget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行

	table_widget->horizontalHeader()->resizeSection(0, 300); //设置表头第一列的宽度为150
	table_widget->horizontalHeader()->resizeSection(1, 180); //设置表头第一列的宽度为150
	table_widget->horizontalHeader()->resizeSection(2, 100); //设置表头第一列的宽度为150
	table_widget->horizontalHeader()->resizeSection(3, 60); //设置表头第一列的宽度为150


	table_widget->setColumnWidth(0, 300);



	table_widget->horizontalHeader()->resizeSection(4, 0); //设置表头第一列的宽度为150

	table_widget->horizontalHeader()->setFixedHeight(30); //设置表头的高度
	table_widget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色

	//设置水平、垂直滚动条样式
	table_widget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");


	table_widget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	table_widget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");


	p->ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为，以行为单位
	p->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	p->ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


	table_widget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

	table_widget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	table_widget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);



	//	table_widget->verticalHeader()->setFixedHeight(100);


	table_widget->setRowCount(0);

	table_widget->horizontalScrollBar()->setVisible(false);

	table_widget->setShowGrid(false);

	table_widget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:silver;}"); //设置表头背景色
	table_widget->horizontalHeader()->setStyleSheet("QHeaderView::section{font-color:black;}"); //设置表头背景色




	//table_widget->horizontalHeader()->setStyleSheet("<font 10px> QHeaderView</font> "); //设置表头背景色


	connect(plist, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(plistClick(int, int)));


	plist_menu = new QMenu(plist);



	plist_rig_1 = new QAction("\346\222\255\346\224\276\346\255\214\346\233\262", plist);
	plist_menu->addAction(plist_rig_1);


	plist_rig_2 = new QAction("\347\247\273\351\231\244\346\255\214\346\233\262", plist);
	plist_menu->addAction(plist_rig_2);

	plist_rig_3 = new QAction("\346\270\205\347\251\272\345\210\227\350\241\250", plist);
	plist_menu->addAction(plist_rig_3);

	plist_rig_4 = new QAction("\346\226\207\344\273\266\345\261\236\346\200\247", plist);
	plist_menu->addAction(plist_rig_4);


	plist_rig_5 = new QAction("\346\267\273\345\212\240\346\226\207\344\273\266", plist);
	plist_menu->addAction(plist_rig_5);

	plist_rig_6 = new QAction("\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", plist);
	plist_menu->addAction(plist_rig_6);


	plist->setContextMenuPolicy(Qt::CustomContextMenu);




	connect(plist, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slot_plist_rig(QPoint)));
	connect(plist_rig_1, SIGNAL(triggered()), this, SLOT(slot_plist_rig_1()));
	connect(plist_rig_2, SIGNAL(triggered()), this, SLOT(slot_plist_rig_2()));
	connect(plist_rig_3, SIGNAL(triggered()), this, SLOT(slot_plist_rig_3()));
	connect(plist_rig_4, SIGNAL(triggered()), this, SLOT(slot_plist_rig_4()));
	connect(plist_rig_5, SIGNAL(triggered()), this, SLOT(slot_plist_rig_5()));
	connect(plist_rig_6, SIGNAL(triggered()), this, SLOT(slot_plist_rig_6()));

	readPlist("");


}


void Plist::plistClick(int row, int column)/*shuang击列表回调*/
{


	playSound(row);


	p->ui->pushButton->setVisible(false);
	p->ui->pushButton_7->setVisible(true);



}

/*

void Plist::addFileTOplist(char*name)
{
int xx = audio->open(name);

if (xx != 0)
{
cout << xx << endl;
return;
}


plist->setRowCount(plist->rowCount() + 1);
int cou = plist->rowCount() - 1;

plist->setItem(cou, 0, new QTableWidgetItem(audio->getmp3Tag(name).Title));
plist->setItem(cou, 1, new QTableWidgetItem(audio->getmp3Tag(name).Artist));

sprintf(str, "%d Kbps", audio->getKbps(name));
plist->setItem(cou, 2, new QTableWidgetItem(str));

strcpy(str, name);

plist->setItem(cou, 3, new QTableWidgetItem(p->getTimeFormat(audio->getTimeInfo().ms).c_str()));
plist->setItem(cou, 4, new QTableWidgetItem(str));

plist->setRowHeight(cou, 30);

cout << "scanf file : " << name << endl;

audio->close();


}
*/






void Plist::addFileTOplist(QString path)
{

	p->play_mode = Playmode::cache;


	p->setPauseStatus();


	auto	code = QTextCodec::codecForName("gb18030");

	std::string name1;
	name1 = code->fromUnicode(path.toStdString().c_str()).data();

	char*name = (char*)name1.c_str();


	audio->close();
	audio->stop();


	if (audio->open(name) != 0)
	{
		return;
	}

	plist->setRowCount(plist->rowCount() + 1);
	int cou = plist->rowCount() - 1;






	/*解决中文乱码*/

	if (FileManger::getFileType(path) == "mp3")
	{

		plist->setItem(cou, 0, new QTableWidgetItem(QString::fromLocal8Bit(audio->getmp3Tag(name).Title)));
		plist->setItem(cou, 1, new QTableWidgetItem(QString::fromLocal8Bit(audio->getmp3Tag(name).Artist)));

		if (plist->item(cou, 0)->text() == "")
		{
			plist->setItem(cou, 0, new QTableWidgetItem(FileManger::getFileTitle(path)));
			plist->setItem(cou, 1, new QTableWidgetItem(FileManger::getFileArtist(path)));

		}



	}
	else
	{
		plist->setItem(cou, 0, new QTableWidgetItem(FileManger::getFileTitle(path)));
		plist->setItem(cou, 1, new QTableWidgetItem(FileManger::getFileArtist(path)));



	}




	sprintf(str, "%d Kbps", audio->getKbps(name));
	plist->setItem(cou, 2, new QTableWidgetItem(str));

	strcpy(str, name);


	if (FileManger::getFileType(path) == "mid")
	{

		plist->setItem(cou, 2, new QTableWidgetItem(""));


		plist->setItem(cou, 3, new QTableWidgetItem(p->getTimeFormat(audio->getTimeInfo().ms * 100).c_str()));
	}

	else
	{
		sprintf(str, "%d Kbps", audio->getKbps(name));
		plist->setItem(cou, 2, new QTableWidgetItem(str));

		strcpy(str, name);

		plist->setItem(cou, 3, new QTableWidgetItem(p->getTimeFormat(audio->getTimeInfo().ms).c_str()));
	}


	plist->setItem(cou, 4, new QTableWidgetItem(path));

	plist->setRowHeight(cou, 30);

	cout << "scanf file : " << name << endl;
	audio->close();
	audio->stop();




	QString file1 = QVariant(p->now_play_index).toString() + " / ";

	file1 += QVariant(plist->rowCount()).toString();
	p->ui->label_3->setText(file1);



}


void Plist::play()
{
	audio->play();
}



void Plist::playSound()
{
	if (plist->rowCount() <= 0)

	{
		//p->setPauseStatus();

		return;
	}
	playSound(plist->selectedItems().toVector()[4]->text());


}



void Plist::playSound(int index)
{
	if (plist->rowCount() <= 0)return;
	plist->selectRow(index);
	if (playSound(plist->item(index, 4)->text()) != 0)
	{
		plist->removeRow(index);
		playSound(plist->currentRow());

		//	p->slot_next();


	}


}


int  Plist::playSound(QString path)
{


	auto	code = QTextCodec::codecForName("gb18030");

	std::string name1;
	name1 = code->fromUnicode(path.toStdString().c_str()).data();

	char*file = (char*)name1.c_str();


	cout << "platy file : ";
	cout << file << endl;
	audio->close();
	audio->stop();
	audio->close();
	int xx = audio->open(file);
	if (xx != 0)
	{
		p->slot_pause();
		state = PlayState::stop;

		p->setPauseStatus();

		cout << "error " << xx << endl;
		return xx;
	}

	state = PlayState::playing;
	audio->play();


	p->play_mode = Playmode::none;


	p->now_play_index = plist->currentRow();

	p->ui->label_2->setText(
		plist->selectedItems().toVector()[0]->text() + " - " +
		plist->selectedItems().toVector()[1]->text()
		);

	p->tray->setToolTip(p->ui->label_2->text());

	p->setPlayStatus();
	QString file1 = QVariant(p->now_play_index + 1).toString() + " / ";

	file1 += QVariant(plist->rowCount()).toString();

	p->ui->label_3->setText(file1);


	if (FileManger::getFileType(path) == "mid")
	{
		p->now_play_type = FileType::mid;
	}

	else
		p->now_play_type = FileType::non;

	p->lrc->loadFile(path);




	return 0;
}


int Plist::playCacheSound(QString path, QString lrc)
{


	p->play_mode = Playmode::cache;


	auto	code = QTextCodec::codecForName("gb18030");

	std::string name1;
	name1 = code->fromUnicode(path.toStdString().c_str()).data();



	char*file = (char*)name1.c_str();

	cout << "platy cache : ";
	cout << file << endl;
	audio->close();
	audio->stop();
	audio->close();

	int xx = audio->open(file);
	if (xx != 0)
	{
		p->slot_pause();
		state = PlayState::stop;
		cout << "error " << xx << endl;
		return xx;
	}

	state = PlayState::pause;
	audio->play();



	p->lrc->loadFile(lrc);

	//	p->timer->stop();

	p->ui->label_2->setText(p->yunDia->ui->input_title->text() + " - " +
		p->yunDia->ui->input_art->text()
		);


	return 0;
}



void Plist::savePlist()
{



	QDir d;

	if (d.exists("Plist/") == false)
	{
		d.mkpath("Plist/");
	}


	QSettings ini("Plist/001.kpl", QSettings::IniFormat);
	QVariant str;
	ini.clear();

	ini.setValue("count", plist->rowCount());

	for (int x = 0; x < plist->rowCount(); x++)
	{
		str = x;
		ini.setValue(str.toString(), plist->item(x, 4)->text());
	}


	ini.sync();
}

void Plist::readPlist(QString path)
{

	QDir d;

	if (d.exists("Plist/") == false)
	{
		d.mkpath("Plist/");
	}



	QSettings ini("Plist/001.kpl", QSettings::IniFormat);


	QVariant str;
	int count = ini.value("count").toInt();
	QString ss;
	for (int x = 0; x < count; x++)
	{
		str = x;

		ss = ini.value(str.toString()).toString();

		if (!FileManger::isExist(ss))continue;
		addFileTOplist(ss);

	}

	ini.sync();


}




void Plist::setSeekTo(int ms)
{
	audio->setSeekTo(ms);
	audio->play();
	audio->setSeekTo(audio->getCurrentTime());/*校验*/
	audio->play();
}



void Plist::slot_plist_rig(QPoint pos)
{
	plist_menu->exec(QCursor::pos());


}



void Plist::slot_plist_rig_1()
{
	playSound();
}



void Plist::slot_plist_rig_2()/*移除*/
{
	int index = plist->currentRow();



	if (index < p->now_play_index)
	{
		--p->now_play_index;
	}


	plist->removeRow(index);




}




void   Plist::slot_plist_rig_3()/*清空*/
{


	QDir d;

	if (d.exists("Plist/") == false)
	{
		d.mkpath("Plist/");
	}


	QSettings ini("Plist/001.kpl", QSettings::IniFormat);
	QVariant str;
	ini.clear();


	while (plist->rowCount())
	{
		plist->removeRow(0);

	}



	p->ui->label_3->setText("0 / 0");



}




void Plist::slot_plist_rig_4()/*属性*/
{


	if (plist->rowCount() <= 0)return;

	auto s = new infoDialog(p, p);

	s->move(p->pos().x() + 10, p->pos().y() + 50);
	s->exec();
	delete s;
}


void  Plist::slot_plist_rig_5()/*添加文件*/
{



	QString path = QFileDialog::getOpenFileName(p, "", setCenter::path_to_download, "Audio Files(*.mp3 *.wav *.wma *.mid)");
	if (path.length() != 0)
	{
		addFileTOplist(path);
		cout << "add file done!" << endl;
		savePlist();
	}

}


void Plist::slot_plist_rig_6()/*添加文件jia*/
{

	QString path_ = QFileDialog::getExistingDirectory(p, "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271", setCenter::path_to_download, QFileDialog::ShowDirsOnly);


	QDir *dir = new QDir(path_);
	QStringList filter;
	filter << "*.wav" << "*.mp3" << "*.wma" << "*.mid";

	//dir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));


	QString path;
	for (int xx = 0; xx < fileInfo->size(); xx++)
	{

		path = path_ + "/" + fileInfo->at(xx).fileName();
		addFileTOplist(path);
	}

	cout << "add folder done!" << endl;

	savePlist();
}











void yunDialog::setCacheStatus(Status_cache s)
{
	s_cache = s;
	switch (s)
	{
	case yunDialog::Status_cache::none:
	{

										  ui->btn_stop->setVisible(false);
										  ui->btn_try->setVisible(false);
										  ui->btn_search->setVisible(true);
										  ui->input_art->setEnabled(true);
										  ui->input_title->setEnabled(true);
										  ui->btn_stop->setVisible(false);


	}
		break;
	case yunDialog::Status_cache::caching:
	{
											 ui->btn_stop->setVisible(false);

											 /*	ui->label_3->setVisible(true);
											 ui->label_4->setVisible(true);
											 ui->progressBar->setVisible(true);
											 ui->btn_download->setVisible(false);

											 ui->label_4->setText("\344\270\213\350\275\275\344\270\255  0 Kb/s");
											 //downloading");
											 */
											 ui->btn_try->setVisible(false);

											 ui->btn_search->setVisible(false);
											 ui->input_art->setEnabled(false);
											 ui->input_title->setEnabled(false);
											 //		ui->btn_try->setEnabled(false);

											 ui->btn_download->setVisible(false);


	}
		break;
	case yunDialog::Status_cache::cached:
	{
											/*已缓存*/

											//	ui->btn_try->setText("play");

											ui->input_art->setEnabled(true);
											ui->input_title->setEnabled(true);
											ui->label_4->setText(
												"\347\274\223\345\255\230\345\256\214\346\257\225");
											/*completed");*/

											setSearchStatus(Status_search::none);

											ui->btn_try->setVisible(false);

											ui->btn_search->setVisible(true);


											/*if (FileManger::getFileSize(cacheFile) <= 102400)
											{
											setCacheStatus(Status_cache::none);
											return;

											}*/

											ui->btn_download->setVisible(true);


											if (p->plist->playCacheSound(cacheFile, fileName + ".mp3") != 0)
											{
												//	p->timer->stop();

												setCacheStatus(Status_cache::none);

												ui->label_4->setText("\347\274\223\345\255\230\345\244\261\350\264\245");
												/*缓存失败*/
												return;

											}
											p->setPlayStatus();

											//	p->timer->start(300);

											ui->btn_stop->setVisible(true);


											if (getDownloadStatus() == Status_download::completed)
											{
												ui->btn_download->setVisible(false);

											}
											if (getDownloadStatus() == Status_download::downloading)
											{
												ui->btn_download->setVisible(false);

											}

	}
		break;
	case  yunDialog::Status_cache::able:
	{

										   ui->btn_stop->setVisible(false);
										   ui->btn_search->setVisible(true);
										   ui->input_art->setEnabled(true);
										   ui->input_title->setEnabled(true);
										   ui->btn_try->setVisible(true);
	}

	default:
		break;
	}
}




void yunDialog::setDownloadStatus(Status_download s)
{
	s_download = s;
	switch (s)
	{
	case yunDialog::Status_download::none:
	{
											 ui->label_3->setVisible(false);
											 ui->label_4->setVisible(true);
											 ui->progressBar->setVisible(false);
											 ui->btn_download->setVisible(false);
											 // ui->label_4->setText("not fund");
											 ui->btn_search->setVisible(true);

											 ui->input_art->setEnabled(true);
											 ui->input_title->setEnabled(true);

	}
		break;
	case yunDialog::Status_download::downloading:
	{

													ui->btn_try->setVisible(false);



													ui->label_3->setVisible(true);
													ui->label_4->setVisible(true);
													ui->progressBar->setVisible(true);
													ui->btn_download->setVisible(false);

													ui->label_4->setText("\344\270\213\350\275\275\344\270\255  0 Kb/s");
													/*downloading");*/

													ui->btn_search->setVisible(false);
													ui->input_art->setEnabled(false);
													ui->input_title->setEnabled(false);


	}
		break;
	case yunDialog::Status_download::completed:
	{
												  download_speed = 0;
												  timer->stop();
												  ui->input_art->setEnabled(true);
												  ui->input_title->setEnabled(true);
												  slot_stop();


												  ui->label_3->setVisible(true);
												  ui->label_4->setVisible(true);
												  ui->progressBar->setVisible(true);
												  ui->btn_download->setVisible(false);
												  ui->label_4->setText("\344\270\213\350\275\275\345\256\214\346\210\220");
												  /*completed");*/
												  setSearchStatus(Status_search::none);

												  if (getCacheStaus() != Status_cache::cached)
												  {
													  //	ui->btn_try->setVisible(true);
													  setCacheStatus(Status_cache::able);


												  }
												  ui->btn_search->setVisible(true);

	}
		break;
	case  yunDialog::Status_download::able:
	{
											  ui->label_3->setVisible(false);
											  ui->label_4->setVisible(true);
											  ui->progressBar->setVisible(false);
											  ui->btn_download->setVisible(true);
											  //  ui->label_4->setText("");
											  ui->btn_search->setVisible(true);
											  ui->input_art->setEnabled(true);
											  ui->input_title->setEnabled(true);
											  ui->progressBar->setValue(0);
	}

	default:
		break;
	}

}




void yunDialog::setSearchStatus(Status_search s)
{
	s_search = s;
	switch (s)
	{
	case yunDialog::Status_search::none:
	{
										   //  ui->label_4->setText("");
										   ui->btn_search->setVisible(true);
										   ui->input_title->setEnabled(true);
										   ui->input_art->setEnabled(true);
										   ui->btn_try->setVisible(false);
										   ui->btn_download->setVisible(false);
										   ui->btn_stop->setVisible(false);
	}
		break;
	case yunDialog::Status_search::searching:
	{
												ui->label_4->setText("\346\255\243\345\234\250\346\237\245\346\211\276");
												ui->btn_search->setVisible(false);

												ui->input_title->setEnabled(false);
												ui->input_art->setEnabled(false);

	}
		break;
	case yunDialog::Status_search::fa:
	{
										 ui->label_4->setText("\346\237\245\346\211\276\345\244\261\350\264\245");
										 ui->btn_search->setVisible(true);
										 ui->input_title->setEnabled(true);
										 ui->input_art->setEnabled(true);

	}break;

	case  yunDialog::Status_search::succ:
	{


											ui->label_4->setText("\346\237\245\346\211\276\346\210\220\345\212\237");
											ui->btn_search->setVisible(true);
											ui->input_title->setEnabled(true);
											ui->input_art->setEnabled(true);

	}
		break;


	}

}




void   yunDialog::slot_stop()
{
	p->plist->audio->stop();
	p->plist->audio->close();

	p->setPauseStatus();

	p->plist->state = PlayState::none;

	/*if (getDownloadStatus() == Status_download::completed)
	{

	ui->btn_try->setVisible(true);
	ui->btn_stop->setVisible(false);

	}
	else
	{
	ui->btn_try->setVisible(false);
	ui->btn_stop->setVisible(false);
	}
	*/

	ui->btn_try->setVisible(true);


	ui->btn_stop->setVisible(false);
	p->play_mode = Playmode::none;

	p->ui->label_2->setText("");
	p->ui->label_4->setText("");
}



void  yunDialog::slot_close()
{

	if (p->play_mode == Playmode::none)
	{
		setCenter::is_play_auto_next = is_auto_pl_ne;

		close();
		return;
	}


	slot_stop();
	setCenter::is_play_auto_next = is_auto_pl_ne;
	//p->play_mode = Playmode::none;/*恢复*/
	close();

}





void  yunDialog::down_done()
{

	file->flush();

	if (getCacheStaus() == Status_cache::caching)
	{

		file->close();

		delete file;
		file = 0;
		setCacheStatus(Status_cache::cached);

		rep_dwn->deleteLater();
		rep_dwn = 0;
		return;
	}


	if (setCenter::is_download_covery)
	{
		QFile::remove(setCenter::path_to_download + fileName + ".mp3");/*删除文件*/
	}

	file->rename(setCenter::path_to_download + fileName + ".mp3");/*重命名*/

	if (setCenter::is_download_add_to_plist == true)
	{
		p->plist->addFileTOplist(setCenter::path_to_download + fileName + ".mp3");

	}

	file->close();





	delete file;
	file = 0;

	rep_dwn->deleteLater();
	rep_dwn = 0;

	//ui->btn_search->setVisible(true);

	setDownloadStatus(Status_download::completed);


}





void  yunDialog::checkForDir()
{
	QDir d;

	if (d.exists(setCenter::path_to_cache) == false)
	{
		d.mkpath(setCenter::path_to_cache);
	}


	if (d.exists(setCenter::path_to_download) == false)
	{
		d.mkpath(setCenter::path_to_download);
	}

}



yunDialog::yunDialog(QWidget*p) :QDialog(p)
{
	ui = new Ui::Dialog5;
	ui->setupUi(this);
	file = nullptr;
	is_auto_pl_ne = setCenter::is_play_auto_next;

	setCenter::is_play_auto_next = false;

	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_close()));

	/*close*/
	ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(icon/close2.png);}"
		"QPushButton:hover{border-image: url(icon/close1.png);}"
		"QPushButton:pressed{border-image: url(icon/close1.png);}");


	ui->btn_search->setStyleSheet("QPushButton{border-image: url(icon/s.png);}"
		"QPushButton:hover{border-image: url(icon/s1.png);}"
		"QPushButton:pressed{border-image: url(icon/s1.png);}");



	ui->btn_download->setStyleSheet("QPushButton{border-image: url(icon/d2.png);}"
		"QPushButton:hover{border-image: url(icon/d1.png);}"
		"QPushButton:pressed{border-image: url(icon/d1.png);}");


	ui->btn_try->setStyleSheet("QPushButton{border-image: url(icon/t2.png);}"
		"QPushButton:hover{border-image: url(icon/t1.png);}"
		"QPushButton:pressed{border-image: url(icon/t1.png);}");



	ui->btn_stop->setStyleSheet("QPushButton{border-image: url(icon/t22.png);}"
		"QPushButton:hover{border-image: url(icon/t11.png);}"
		"QPushButton:pressed{border-image: url(icon/t11.png);}");




	this->p = (MainWindow*)p;

	move(p->pos().x() + (p->width() - this->width()) / 2,
		p->pos().y() + (p->height() - this->width()));

	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);


	connect(ui->btn_search, SIGNAL(clicked()), this, SLOT(slot_search()));
	connect(ui->btn_download, SIGNAL(clicked()), this, SLOT(slot_download()));
	connect(ui->btn_try, SIGNAL(clicked()), this, SLOT(slot_try()));
	connect(ui->btn_stop, SIGNAL(clicked()), this, SLOT(slot_stop()));

	mang = new QNetworkAccessManager;


	ui->progressBar->setValue(0);

	setDownloadStatus(Status_download::none);
	setCacheStatus(Status_cache::none);

	ui->label_4->setText("");
	ui->btn_search->setFocus(Qt::MouseFocusReason);


	timer = new QTimer;

	connect(this->timer, SIGNAL(timeout()), this, SLOT(slot_timer()));

	//	setCacheStatus(Status_cache::none);
}

void yunDialog::search()
{

	setDownloadStatus(Status_download::none);
	setCacheStatus(Status_cache::none);
	setSearchStatus(Status_search::searching);
	reply_buff.clear();
	cout << "check for song in net " << endl;

	QString s = "http://box.zhangmen.baidu.com/x?op=12&count=1&title=";

	s = s + ui->input_title->text();
	s = s + "$$";
	s = s + ui->input_art->text();
	s = s + "$$$$";

	fileName = ui->input_art->text() + " - " + ui->input_title->text(); +".mp3";

	rep_search = mang->get(QNetworkRequest(QUrl(s)));
	connect(rep_search, SIGNAL(readyRead()), this, SLOT(onSearchReady()));
	connect(rep_search, SIGNAL(finished()), this, SLOT(onSearchDone()));
	connect(rep_search, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onSearchError(QNetworkReply::NetworkError)));

	/*ui->btn_download->setVisible(false);
	ui->btn_try->setVisible(false);*/


}

yunDialog::~yunDialog()
{
	//rep_search->deleteLater();
	/*leak*/

	if (file)
	{
		file->flush();
		file->close();
		delete file;
	}
	if (mang)delete mang;

	delete ui;


}


int  yunDialog::getCount()
{

	if (reply_buff.length() <= 3)return -1;/*link error*/

	int x = reply_buff.find("<count>");
	int y = reply_buff.find("</count>");

	return QVariant(reply_buff.substr(x + 7, y - x - 7).c_str()).toInt();


}


QString  yunDialog::getUrl()
{
	if (getCount() >= 1)
	{
		int x = reply_buff.find("http://");

		if (x <= 10)return "";

		int y = reply_buff.find("]]></decode>");
		return reply_buff.substr(x, y - x).c_str();

	}
	return "";
}


QString yunDialog::getDurl()
{
	if (getCount() >= 1)
	{
		int x = reply_buff.find("<durl><encode><![CDATA[");
		if (x <= 10)return "";

		int y = reply_buff.find("</durl>");
		string f = reply_buff.substr(x + 23, y - x);
		int z = f.find("]]></decode>");
		return f.substr(0, z).c_str();

	}
	return "";

}


yunDialog::Status_cache yunDialog::getCacheStaus()
{
	return s_cache;

}



yunDialog::Status_download   yunDialog::getDownloadStatus()
{
	return s_download;
}


yunDialog::Status_search yunDialog::getSearchStatus()
{
	return s_search;
}






void  yunDialog::start_download(QString &url, bool isCache)
{
	/*下载*/
	//QFileInfo info(fileName);
	checkForDir();

	if (isCache == true)
	{
		//file = new QFile(setCenter:: + "~ktmp");

		QString path = setCenter::path_to_cache + QVariant(Hash::getHashByKey(
			QVariant(fileName).toString().toStdString().c_str())).toString() + ".mp3";
		cacheFile = path;

		if (FileManger::isExist(path))
		{
			setCacheStatus(Status_cache::cached);
			return;



		}

		file = new QFile(path);

	}
	else
	{

		file = new QFile(setCenter::path_to_download + "~ktmp");
	}
	file->open(QIODevice::WriteOnly);

	rep_dwn = mang->get(QNetworkRequest(QUrl(url)));

	connect(rep_dwn, SIGNAL(readyRead()), this, SLOT(down_ready()));
	connect(rep_dwn, SIGNAL(finished()), this, SLOT(down_done()));

	if (isCache == true)
	{
		return;
	}

	connect(rep_dwn, SIGNAL(downloadProgress(qint64, qint64)),
		this, SLOT(updateDwn(qint64, qint64)));


	/*ui->btn_search->setVisible(false);
	ui->btn_try->setVisible(false);
	ui->label_4->setText("downloading");

	ui->btn_download->setVisible(false);
	ui->btn_try->setVisible(false);
	ui->label_3->setVisible(true);
	ui->label_4->setVisible(true);*/





	setDownloadStatus(Status_download::downloading);
	curentBytes = 0;
	download_speed = 0;
	timer->start(1000);

}



void  yunDialog::slot_timer()
{
	//	cout << "timer  "<<download_speed/1024<<endl;

	download_speed = (curentBytes - download_speed);

	ui->label_4->setText("\344\270\213\350\275\275\344\270\255  " + QVariant(download_speed / 1024).toString() + " Kb/s");
	/*downloading");*/

	download_speed = curentBytes;
}


void  yunDialog::updateDwn(qint64 c, qint64 m)
{

	if (c >= m)
	{
		//	ui->label_4->setText("download complete");
		setDownloadStatus(Status_download::completed);
	}
	curentBytes = c;


	QVariant ss = QVariant(c).toString() + "  Bytes " + "  /   " + QVariant(m).toString() + "  Bytes ";

	ui->label_3->setText(ss.toString());
	ui->progressBar->setMaximum(m);
	ui->progressBar->setValue(c);

}


void   yunDialog::down_ready()
{
	if (file)file->write(rep_dwn->readAll());

}


void   yunDialog::onSearchDone()
{
	cout << "yun search done" << endl;
	try_url = getUrl();
	d_url = getDurl();


	if (getCount() >= 1)
	{

		setDownloadStatus(Status_download::able);
		setCacheStatus(Status_cache::able);

		setSearchStatus(Status_search::succ);

	}
	else
	{

		setDownloadStatus(Status_download::none);
		setCacheStatus(Status_cache::none);

		setSearchStatus(Status_search::fa);

	}

	if (rep_search)
	{
		delete rep_search;
		rep_search = nullptr;

	}
}

void  yunDialog::onSearchReady()
{
	//	reply_buff.reserve(rep_search->readBufferSize() + 10);

	reply_buff = rep_search->readAll().data();

	cout << "yun search ready" << endl;
}

void   yunDialog::onSearchError(QNetworkReply::NetworkError code)
{
	cout << "yun  search error" << endl;
}



void  yunDialog::slot_search()
{
	/*	ui->btn_download->setVisible(false);
	ui->btn_try->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
	*/


	search();
}

void  yunDialog::slot_download()
{
	start_download(d_url);

}

void   yunDialog::slot_try()
{

	if (getUrl() != "")
	{
		setCacheStatus(Status_cache::caching);
		start_download(try_url, true);
	}
}







void   setDialog::slot_reset()
{

	ui->checkBox_6->setChecked(true);
	ui->checkBox_6->setEnabled(false);
	ui->checkBox->setChecked(false);
	ui->checkBox_2->setChecked(false);
	ui->checkBox_3->setChecked(true);
	ui->checkBox_4->setChecked(false);
	ui->checkBox_5->setChecked(false);
	ui->checkBox_7->setChecked(true);
	ui->checkBox_10->setChecked(false);
	ui->checkBox_8->setChecked(true);
	ui->checkBox_9->setChecked(true);

	QDir d;
	ui->label_2->setText(d.currentPath() + "/download/");
	ui->label_4->setText(d.currentPath() + "/cache/");

}


void  setDialog::slot_path()
{

	QString path_ = QFileDialog::getExistingDirectory(this, "\346\233\264\346\224\271\344\270\213\350\275\275\350\267\257\345\276\204", setCenter::path_to_download, QFileDialog::ShowDirsOnly);
	if (path_ == "")return;

	ui->label_2->setText(path_ + "/");
	setCenter::path_to_download = ui->label_2->text();
	setCenter::save_set();



}
void  setDialog::slot_path_to_cache()
{


	QString path_ = QFileDialog::getExistingDirectory(this, "\346\233\264\346\224\271\347\274\223\345\255\230\350\267\257\345\276\204", setCenter::path_to_cache, QFileDialog::ShowDirsOnly);
	if (path_ == "")return;

	ui->label_4->setText(path_ + "/");

	setCenter::path_to_cache = ui->label_4->text();
	setCenter::save_set();


}
void  setDialog::slot_sync()
{
	syncCacheSize();

}

void setDialog::slot_open_path()
{
	QString path = ui->label_2->text();
	path.replace("/", "\\");
	QProcess::startDetached("explorer " + path);

}


void  setDialog::slot_clearCache()
{

	QDir *dir = new QDir(setCenter::path_to_cache);

	QStringList filter;
	filter << "*.wav" << "*.mp3" << "*.wma" << "*.mid";

	//dir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));

	QString path;
	for (int xx = 0; xx < fileInfo->size(); xx++)
	{

		path = setCenter::path_to_cache + "/" + fileInfo->at(xx).fileName();
		QFile::remove(path);

	}

	syncCacheSize();
}








void  setDialog::slot_close()
{
	setCenter::is_load_play = ui->checkBox->isChecked();
	setCenter::is_load_min = ui->checkBox_2->isChecked();
	setCenter::is_play_auto_next = ui->checkBox_3->isChecked();
	setCenter::is_load_con = ui->checkBox_4->isChecked();
	setCenter::is_play_random = ui->checkBox_5->isChecked();
	setCenter::is_lrc_auto_download = ui->checkBox_7->isChecked();

	setCenter::is_lrc_show = ui->checkBox_8->isChecked();
	setCenter::path_to_download = ui->label_2->text();
	setCenter::path_to_cache = ui->label_4->text();


	setCenter::is_download_add_to_plist = ui->checkBox_9->isChecked();



	setCenter::is_download_covery = ui->checkBox_10->isChecked();
	p->ui->label_4->setVisible(setCenter::is_lrc_show);

	setCenter::save_set();

	close();

}







unsigned long long  setDialog::getCacheSize()
{
	unsigned long long  size = 0;

	QDir *dir = new QDir(setCenter::path_to_cache);

	QStringList filter;
	filter << "*.wav" << "*.mp3" << "*.wma" << "*.mid";

	//dir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));


	QString path;
	for (int xx = 0; xx < fileInfo->size(); xx++)
	{

		path = setCenter::path_to_cache + "/" + fileInfo->at(xx).fileName();
		QFileInfo info(path);
		size += info.size();

	}
	return size;

}

setDialog::setDialog(QWidget*p) :QDialog(p)
{
	ui = new Ui::Dialog;
	ui->setupUi(this);
	/*close*/
	ui->pushButton->setStyleSheet("QPushButton{border-image: url(icon/close2.png);}"
		"QPushButton:hover{border-image: url(icon/close1.png);}"
		"QPushButton:pressed{border-image: url(icon/close1.png);}");

	this->p = (MainWindow*)p;

	move(p->pos().x() + (p->width() - this->width()) / 2,
		p->pos().y() + (p->height() - this->width()));

	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);


	ui->checkBox_6->setChecked(true);
	ui->checkBox_6->setEnabled(false);
	ui->checkBox->setChecked(setCenter::is_load_play);
	ui->checkBox_2->setChecked(setCenter::is_load_min);
	ui->checkBox_3->setChecked(setCenter::is_play_auto_next);
	ui->checkBox_4->setChecked(setCenter::is_load_con);
	ui->checkBox_5->setChecked(setCenter::is_play_random);
	ui->checkBox_7->setChecked(setCenter::is_lrc_auto_download);
	ui->checkBox_10->setChecked(setCenter::is_download_covery);
	ui->checkBox_8->setChecked(setCenter::is_lrc_show);
	ui->label_2->setText(setCenter::path_to_download);
	ui->label_4->setText(setCenter::path_to_cache);

	ui->checkBox_9->setChecked(setCenter::is_download_add_to_plist);


	this->syncCacheSize();

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_close()));
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_path()));
	connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(slot_reset()));
	connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(slot_clearCache()));

	connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(slot_path_to_cache()));
	connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(slot_sync()));
	connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(slot_open_path()));


}






void  setDialog::syncCacheSize()
{

	long long xqqqq = getCacheSize();
	float size_ = xqqqq*1024.0;

	int xa = 0;
	while (xqqqq)
	{
		xqqqq /= 1024;
		size_ /= 1024.0;

		xa++;
	}

	QString wq;

	switch (xa)
	{
	case  1:wq = " Bytes"; break;
	case  2:wq = " KBytes"; break;
	case  3:wq = " MBytes"; break;
	case  4:wq = " GBytes"; break;
	case  5:wq = " TBytes"; break;
	default:wq = " Bytes"; break;
	}



	ui->label_6->setText(QVariant(size_).toString() + wq);

}












