/********************************************************************************
** Form generated from reading ui file 'pzgtools.ui'
**
** Created: Sat Sep 22 21:14:52 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PZGTOOLS_H
#define UI_PZGTOOLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

class Ui_objectPZGtools
{
public:
    QPushButton *cmdExit;
    QPushButton *b_about;
    QLabel *label_7;
    QTabWidget *tabWidget;
    QWidget *tabDatafile;
    QLineEdit *e_PathFile;
    QPushButton *b_OpenDatafile;
    QTextBrowser *textEdit;
    QLineEdit *e_workdir;
    QPushButton *b_OpenWorkdir;
    QWidget *tabExtract;
    QCheckBox *chk_03;
    QLabel *label;
    QCheckBox *chk_05;
    QCheckBox *chk_07;
    QCheckBox *chk_10;
    QCheckBox *chk_20;
    QCheckBox *chk_50;
    QCheckBox *chk_70;
    QCheckBox *chk_100;
    QPushButton *b_extract;
    QLineEdit *e_outfile;
    QLabel *label_2;
    QWidget *tabPlot;
    QLineEdit *e_plotfile;
    QLineEdit *e_title;
    QGroupBox *groupBox;
    QPushButton *b_openData1;
    QPushButton *b_openData2;
    QPushButton *b_openData3;
    QPushButton *b_openData4;
    QPushButton *b_openData5;
    QLineEdit *e_data1;
    QLineEdit *e_data2;
    QLineEdit *e_data3;
    QLineEdit *e_data4;
    QLineEdit *e_data5;
    QPushButton *b_plot;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tabClimate;
    QLabel *label_5;
    QPushButton *b_getClima;
    QLineEdit *e_climateWorkDir;
    QRadioButton *radio_temp;
    QRadioButton *radio_humi;
    QRadioButton *radio_pres;
    QRadioButton *radio_velo;
    QLabel *label_6;

    void setupUi(QWidget *objectPZGtools)
    {
    objectPZGtools->setObjectName(QString::fromUtf8("objectPZGtools"));
    objectPZGtools->setWindowModality(Qt::NonModal);
    objectPZGtools->setWindowIcon(QIcon(QString::fromUtf8(":/new/prefix1/icons/Settings2.png")));
    cmdExit = new QPushButton(objectPZGtools);
    cmdExit->setObjectName(QString::fromUtf8("cmdExit"));
    cmdExit->setGeometry(QRect(540, 560, 75, 24));
    b_about = new QPushButton(objectPZGtools);
    b_about->setObjectName(QString::fromUtf8("b_about"));
    b_about->setGeometry(QRect(10, 560, 111, 20));
    label_7 = new QLabel(objectPZGtools);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(140, 560, 101, 19));
    tabWidget = new QTabWidget(objectPZGtools);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 30, 601, 511));
    tabDatafile = new QWidget();
    tabDatafile->setObjectName(QString::fromUtf8("tabDatafile"));
    e_PathFile = new QLineEdit(tabDatafile);
    e_PathFile->setObjectName(QString::fromUtf8("e_PathFile"));
    e_PathFile->setGeometry(QRect(10, 50, 471, 21));
    b_OpenDatafile = new QPushButton(tabDatafile);
    b_OpenDatafile->setObjectName(QString::fromUtf8("b_OpenDatafile"));
    b_OpenDatafile->setGeometry(QRect(490, 50, 75, 20));
    textEdit = new QTextBrowser(tabDatafile);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setGeometry(QRect(10, 90, 561, 231));
    e_workdir = new QLineEdit(tabDatafile);
    e_workdir->setObjectName(QString::fromUtf8("e_workdir"));
    e_workdir->setGeometry(QRect(10, 370, 461, 20));
    b_OpenWorkdir = new QPushButton(tabDatafile);
    b_OpenWorkdir->setObjectName(QString::fromUtf8("b_OpenWorkdir"));
    b_OpenWorkdir->setGeometry(QRect(484, 370, 91, 20));
    tabWidget->addTab(tabDatafile, QApplication::translate("objectPZGtools", "Data-file", 0, QApplication::UnicodeUTF8));
    tabExtract = new QWidget();
    tabExtract->setObjectName(QString::fromUtf8("tabExtract"));
    chk_03 = new QCheckBox(tabExtract);
    chk_03->setObjectName(QString::fromUtf8("chk_03"));
    chk_03->setGeometry(QRect(30, 60, 70, 19));
    label = new QLabel(tabExtract);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 30, 301, 16));
    chk_05 = new QCheckBox(tabExtract);
    chk_05->setObjectName(QString::fromUtf8("chk_05"));
    chk_05->setGeometry(QRect(30, 90, 70, 19));
    chk_07 = new QCheckBox(tabExtract);
    chk_07->setObjectName(QString::fromUtf8("chk_07"));
    chk_07->setGeometry(QRect(30, 120, 70, 19));
    chk_10 = new QCheckBox(tabExtract);
    chk_10->setObjectName(QString::fromUtf8("chk_10"));
    chk_10->setGeometry(QRect(30, 150, 70, 19));
    chk_20 = new QCheckBox(tabExtract);
    chk_20->setObjectName(QString::fromUtf8("chk_20"));
    chk_20->setGeometry(QRect(140, 60, 70, 19));
    chk_50 = new QCheckBox(tabExtract);
    chk_50->setObjectName(QString::fromUtf8("chk_50"));
    chk_50->setGeometry(QRect(140, 90, 70, 19));
    chk_70 = new QCheckBox(tabExtract);
    chk_70->setObjectName(QString::fromUtf8("chk_70"));
    chk_70->setGeometry(QRect(140, 120, 70, 19));
    chk_100 = new QCheckBox(tabExtract);
    chk_100->setObjectName(QString::fromUtf8("chk_100"));
    chk_100->setGeometry(QRect(140, 150, 70, 19));
    b_extract = new QPushButton(tabExtract);
    b_extract->setObjectName(QString::fromUtf8("b_extract"));
    b_extract->setGeometry(QRect(20, 300, 151, 31));
    e_outfile = new QLineEdit(tabExtract);
    e_outfile->setObjectName(QString::fromUtf8("e_outfile"));
    e_outfile->setGeometry(QRect(20, 230, 341, 20));
    label_2 = new QLabel(tabExtract);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(20, 210, 311, 16));
    tabWidget->addTab(tabExtract, QApplication::translate("objectPZGtools", "Extract", 0, QApplication::UnicodeUTF8));
    tabPlot = new QWidget();
    tabPlot->setObjectName(QString::fromUtf8("tabPlot"));
    e_plotfile = new QLineEdit(tabPlot);
    e_plotfile->setObjectName(QString::fromUtf8("e_plotfile"));
    e_plotfile->setGeometry(QRect(30, 40, 191, 20));
    e_title = new QLineEdit(tabPlot);
    e_title->setObjectName(QString::fromUtf8("e_title"));
    e_title->setGeometry(QRect(30, 100, 281, 20));
    groupBox = new QGroupBox(tabPlot);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(30, 160, 541, 311));
    b_openData1 = new QPushButton(groupBox);
    b_openData1->setObjectName(QString::fromUtf8("b_openData1"));
    b_openData1->setGeometry(QRect(20, 30, 111, 24));
    b_openData2 = new QPushButton(groupBox);
    b_openData2->setObjectName(QString::fromUtf8("b_openData2"));
    b_openData2->setGeometry(QRect(20, 70, 111, 24));
    b_openData3 = new QPushButton(groupBox);
    b_openData3->setObjectName(QString::fromUtf8("b_openData3"));
    b_openData3->setGeometry(QRect(20, 110, 111, 24));
    b_openData4 = new QPushButton(groupBox);
    b_openData4->setObjectName(QString::fromUtf8("b_openData4"));
    b_openData4->setGeometry(QRect(20, 150, 111, 24));
    b_openData5 = new QPushButton(groupBox);
    b_openData5->setObjectName(QString::fromUtf8("b_openData5"));
    b_openData5->setGeometry(QRect(20, 190, 111, 24));
    e_data1 = new QLineEdit(groupBox);
    e_data1->setObjectName(QString::fromUtf8("e_data1"));
    e_data1->setGeometry(QRect(170, 30, 351, 20));
    e_data2 = new QLineEdit(groupBox);
    e_data2->setObjectName(QString::fromUtf8("e_data2"));
    e_data2->setGeometry(QRect(170, 70, 351, 20));
    e_data3 = new QLineEdit(groupBox);
    e_data3->setObjectName(QString::fromUtf8("e_data3"));
    e_data3->setGeometry(QRect(170, 110, 351, 20));
    e_data4 = new QLineEdit(groupBox);
    e_data4->setObjectName(QString::fromUtf8("e_data4"));
    e_data4->setGeometry(QRect(170, 150, 351, 20));
    e_data5 = new QLineEdit(groupBox);
    e_data5->setObjectName(QString::fromUtf8("e_data5"));
    e_data5->setGeometry(QRect(170, 190, 351, 20));
    b_plot = new QPushButton(groupBox);
    b_plot->setObjectName(QString::fromUtf8("b_plot"));
    b_plot->setGeometry(QRect(440, 270, 75, 24));
    label_3 = new QLabel(tabPlot);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(30, 20, 231, 19));
    label_4 = new QLabel(tabPlot);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(30, 80, 261, 19));
    tabWidget->addTab(tabPlot, QApplication::translate("objectPZGtools", "Plotting", 0, QApplication::UnicodeUTF8));
    tabClimate = new QWidget();
    tabClimate->setObjectName(QString::fromUtf8("tabClimate"));
    label_5 = new QLabel(tabClimate);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(30, 30, 301, 16));
    b_getClima = new QPushButton(tabClimate);
    b_getClima->setObjectName(QString::fromUtf8("b_getClima"));
    b_getClima->setGeometry(QRect(30, 280, 111, 31));
    e_climateWorkDir = new QLineEdit(tabClimate);
    e_climateWorkDir->setObjectName(QString::fromUtf8("e_climateWorkDir"));
    e_climateWorkDir->setEnabled(true);
    e_climateWorkDir->setGeometry(QRect(30, 230, 311, 20));
    radio_temp = new QRadioButton(tabClimate);
    radio_temp->setObjectName(QString::fromUtf8("radio_temp"));
    radio_temp->setGeometry(QRect(70, 60, 121, 19));
    radio_humi = new QRadioButton(tabClimate);
    radio_humi->setObjectName(QString::fromUtf8("radio_humi"));
    radio_humi->setGeometry(QRect(70, 90, 121, 19));
    radio_pres = new QRadioButton(tabClimate);
    radio_pres->setObjectName(QString::fromUtf8("radio_pres"));
    radio_pres->setGeometry(QRect(70, 120, 121, 19));
    radio_velo = new QRadioButton(tabClimate);
    radio_velo->setObjectName(QString::fromUtf8("radio_velo"));
    radio_velo->setGeometry(QRect(70, 150, 131, 19));
    label_6 = new QLabel(tabClimate);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(30, 210, 121, 16));
    tabWidget->addTab(tabClimate, QApplication::translate("objectPZGtools", "Climate data", 0, QApplication::UnicodeUTF8));

    retranslateUi(objectPZGtools);

    QSize size(631, 597);
    size = size.expandedTo(objectPZGtools->minimumSizeHint());
    objectPZGtools->resize(size);

    QObject::connect(cmdExit, SIGNAL(clicked()), objectPZGtools, SLOT(close()));

    tabWidget->setCurrentIndex(3);


    QMetaObject::connectSlotsByName(objectPZGtools);
    } // setupUi

    void retranslateUi(QWidget *objectPZGtools)
    {
    objectPZGtools->setWindowTitle(QApplication::translate("objectPZGtools", "PZG-Tools 2", 0, QApplication::UnicodeUTF8));
    cmdExit->setText(QApplication::translate("objectPZGtools", "Exit", 0, QApplication::UnicodeUTF8));
    b_about->setText(QApplication::translate("objectPZGtools", "About PZGTools", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("objectPZGtools", "v2.0rc2-Linux", 0, QApplication::UnicodeUTF8));
    b_OpenDatafile->setText(QApplication::translate("objectPZGtools", "open ...", 0, QApplication::UnicodeUTF8));
    b_OpenWorkdir->setText(QApplication::translate("objectPZGtools", "set WorkDir", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tabDatafile), QApplication::translate("objectPZGtools", "Data-file", 0, QApplication::UnicodeUTF8));
    chk_03->setText(QApplication::translate("objectPZGtools", "0.3", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("objectPZGtools", "Select particle size you want to extract (particle size in \302\265m):", 0, QApplication::UnicodeUTF8));
    chk_05->setText(QApplication::translate("objectPZGtools", "0.5", 0, QApplication::UnicodeUTF8));
    chk_07->setText(QApplication::translate("objectPZGtools", "0.7", 0, QApplication::UnicodeUTF8));
    chk_10->setText(QApplication::translate("objectPZGtools", "1.0", 0, QApplication::UnicodeUTF8));
    chk_20->setText(QApplication::translate("objectPZGtools", "2.0", 0, QApplication::UnicodeUTF8));
    chk_50->setText(QApplication::translate("objectPZGtools", "5.0", 0, QApplication::UnicodeUTF8));
    chk_70->setText(QApplication::translate("objectPZGtools", "7.0", 0, QApplication::UnicodeUTF8));
    chk_100->setText(QApplication::translate("objectPZGtools", "10.0", 0, QApplication::UnicodeUTF8));
    b_extract->setText(QApplication::translate("objectPZGtools", "Extract ", 0, QApplication::UnicodeUTF8));
    e_outfile->setText(QApplication::translate("objectPZGtools", "out.dat", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("objectPZGtools", "Name of the output data-file prefix:", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tabExtract), QApplication::translate("objectPZGtools", "Extract", 0, QApplication::UnicodeUTF8));
    e_plotfile->setText(QApplication::translate("objectPZGtools", "myplot.plt", 0, QApplication::UnicodeUTF8));
    e_title->setToolTip(QApplication::translate("objectPZGtools", "Do not use spaces for the title name, use _ or - , for example: laminarflow_0.3um_roomnumber_346", 0, QApplication::UnicodeUTF8));
    e_title->setText(QApplication::translate("objectPZGtools", "title_of_the_plot", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("objectPZGtools", "Select data-files from extraction:", 0, QApplication::UnicodeUTF8));
    b_openData1->setText(QApplication::translate("objectPZGtools", "Data-file 1", 0, QApplication::UnicodeUTF8));
    b_openData2->setText(QApplication::translate("objectPZGtools", "Data-file 2", 0, QApplication::UnicodeUTF8));
    b_openData3->setText(QApplication::translate("objectPZGtools", "Data-file 3", 0, QApplication::UnicodeUTF8));
    b_openData4->setText(QApplication::translate("objectPZGtools", "Data-file 4", 0, QApplication::UnicodeUTF8));
    b_openData5->setText(QApplication::translate("objectPZGtools", "Data-file 5", 0, QApplication::UnicodeUTF8));
    b_plot->setText(QApplication::translate("objectPZGtools", "Plot!", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("objectPZGtools", "Name of the plotfile to create:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("objectPZGtools", "Title of the plot (do NOT use spaces!) :", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tabPlot), QApplication::translate("objectPZGtools", "Plotting", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("objectPZGtools", "Select climate data you want to plot:", 0, QApplication::UnicodeUTF8));
    b_getClima->setText(QApplication::translate("objectPZGtools", "Show", 0, QApplication::UnicodeUTF8));
    radio_temp->setText(QApplication::translate("objectPZGtools", "Temperature", 0, QApplication::UnicodeUTF8));
    radio_humi->setText(QApplication::translate("objectPZGtools", "Humidity", 0, QApplication::UnicodeUTF8));
    radio_pres->setText(QApplication::translate("objectPZGtools", "Pressure", 0, QApplication::UnicodeUTF8));
    radio_velo->setText(QApplication::translate("objectPZGtools", "Gas-Velocity", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("objectPZGtools", "Working-directory:", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tabClimate), QApplication::translate("objectPZGtools", "Climate data", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(objectPZGtools);
    } // retranslateUi

};

namespace Ui {
    class objectPZGtools: public Ui_objectPZGtools {};
} // namespace Ui

#endif // UI_PZGTOOLS_H
