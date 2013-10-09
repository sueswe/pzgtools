#include <QtGui>
#include "pzgtools.h"
#include <QFSFileEngine>
#include <QFile>
#include <QTextStream>
#include <QLinkedList>

/*************************************************

#Copyright (C) 2007  Werner Riener
#
#This program is free software; you can redistribute it and/or
#modify it under the terms of the GNU General Public License
#as published by the Free Software Foundation; either
#version 2 of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be
#useful, but WITHOUT ANY WARRANTY; without even the
#implied warranty of MERCHANTABILITY or FITNESS FOR A
#PARTICULAR PURPOSE. See the GNU General Public License
#for more details.
#
#You should have received a copy of the GNU General
#Public License along with this program; if not, write
#to the Free Software Foundation, Inc.,
#51 Franklin St, Fifth Floor, Boston, MA 02110, USA



*******************************************************/


pzgtools::pzgtools(QWidget *parent)
{
	setupUi(this);
	
	// connections and slots
	
	//select
	connect( b_OpenDatafile, SIGNAL( clicked() ), this, SLOT( open_datafile() ) );
	connect( b_OpenWorkdir, SIGNAL( clicked() ), this, SLOT( open_workdir() ) );
	//extract
	connect( b_extract, SIGNAL( clicked() ), this, SLOT( extract() ) );
	//plotting:
	connect( b_openData1, SIGNAL( clicked() ), this, SLOT( opendata1() ) );
	connect( b_openData2, SIGNAL( clicked() ), this, SLOT( opendata2() ) );
	connect( b_openData3, SIGNAL( clicked() ), this, SLOT( opendata3() ) );
	connect( b_openData4, SIGNAL( clicked() ), this, SLOT( opendata4() ) );
	connect( b_openData5, SIGNAL( clicked() ), this, SLOT( opendata5() ) );
	connect( b_plot, SIGNAL( clicked() ), this, SLOT( plot() ) );
	
	connect( b_getClima, SIGNAL( clicked() ), this, SLOT (get_climate() ) );
	
	connect( e_workdir, SIGNAL( lostFocus() ), this, SLOT( set_wd() ) );
	
	connect( b_about, SIGNAL( clicked() ), this, SLOT( about() ) );
	
	
}

void pzgtools::about() 
{
	QMessageBox::about(this,
		tr("PZG-Tools"),
		tr("(c)2007 by Werner Riener\nWritten in QT4/C++ for i386-systems\nEmail: riener_w@mx.net")
		);
}

void pzgtools::set_wd() 
{
	e_climateWorkDir->setText( e_workdir->text() );
}

void pzgtools::open_datafile()
{
	//Opens a file by showing a filedialoge
	QFileDialog::Options options;
	QString selectedFilter;
	QString fileName = QFileDialog::getOpenFileName(
					this,
					tr("Datei öffen:"),
					e_PathFile->text(),
					tr("All Files (*);;Text Files (*.txt)"),
					&selectedFilter,
					options
				);
	if (!fileName.isEmpty()) 
		e_PathFile->setText(fileName);
		
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
	
	QFile file(fileName); 
	if (file.open(QIODevice::ReadOnly)) {
		QTextStream stream(&file);
		textEdit->setText(stream.readAll());
	}
	
	qWarning() << "done loading" << fileName;
	
	QApplication::restoreOverrideCursor();
	/***
	QMessageBox::warning(
		this,
		tr("Well ..."),
		tr("File loaded ..."),
		tr("OK")
		);
	***/
	
}


void pzgtools::open_workdir()
{
	QFileDialog::Options options;
	QString selectedFilter;
	QString workdir = QFileDialog::getExistingDirectory(
					this,
					tr("Pfad öffen:"),
					"c:/",
					//tr("All Files (*);;Text Files (*.txt)"),
					//&selectedFilter,
					options
				);
	if (!workdir.isEmpty()) {
		e_workdir->setText(workdir);
		e_climateWorkDir->setText(workdir);
	}
}


void pzgtools::extract() {
	
	
	
	QString program = "extract.pl";
	
	QStringList w;
	QString wd;
	QString workdir = e_workdir->text();
	if (workdir == "") 
		QMessageBox::warning(this,tr("Warning"),tr("No workdir spezified."),tr("OK"));
	
	// We define the workdir string for extract.pl:
	w << "-w=" << workdir;
	wd = w.join("");
	
	
	
	QString chk03;
	QString chk05;
	QString chk07;
	QString chk10;
	QString chk20;
	QString chk50;
	QString chk70;
	QString chk100;
	
	QLinkedList<QString> list;
	
	if (chk_03->isChecked()) 
		chk03 = "0.3";
		list << chk03;
	if (chk_05->isChecked()) 
		chk05 = "0.5";
		list << chk05;
	if (chk_07->isChecked()) 
		chk07 = "0.7";
		list << chk07;
	if (chk_10->isChecked()) 
		chk10 = "1.0";
		list << chk10;
	if (chk_20->isChecked()) 
		chk20 = "2.0";	
		list << chk20;
	if (chk_50->isChecked()) 
		chk50 = "5.0";	
		list << chk50;
	if (chk_70->isChecked()) 
		chk70 = "7.0";
		list << chk70;
	if (chk_100->isChecked()) 
		chk100 = "10.0";
		list << chk100;
	
	
	QProcess extract;
	
	QString str;
	foreach (str, list) {
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		
		if (str == "") {
			//nix zu tun
		} else {
			
			// We define the size string for extract.pl:
			QStringList s;
			s << "--size=";
			s << str;
			QString size = s.join("");
			
			// We define rowout for extract.pl:
			QStringList r;
			r << "-r=";
			r << str;
			r << "_";
			r << e_outfile->text();
			QString rowout = r.join("");
			//Run the program now
			qDebug() << program << wd << size << "-l=lineout" << rowout << e_PathFile->text();
			QStringList arguments;
			arguments << program << wd << size << "-l=lineout" << rowout << e_PathFile->text();
			
			//Process:
			extract.start(program,arguments);
			qDebug() << "starte!";
			if ( !extract.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				extract.waitForFinished();

				QApplication::restoreOverrideCursor();
				
				/***************************
				QMessageBox::information(
					this,
					tr("Information"),
					tr("String wurde gesendet." ),
					tr("OK")
					);
					**************************/
				qDebug() << "done: " << str;
			} // end if (process)
			QApplication::restoreOverrideCursor();
			
		} // end if (str found)
		QApplication::restoreOverrideCursor();
	} // end foreach
	
	
	
}




void pzgtools::opendata1() 
{
	QFileDialog::Options options;
	QString selectedFilter;
	QString datafileName = QFileDialog::getOpenFileName(
					this,
					tr("Datei öffen:"),
					e_workdir->text(),
					tr("All Files (*);;Text Files (*.txt)"),
					&selectedFilter,
					options
				);
	if (!datafileName.isEmpty()) 
		e_data1->setText(datafileName);
}

void pzgtools::opendata2() 
{
	QFileDialog::Options options;
	QString selectedFilter;
	QString datafileName = QFileDialog::getOpenFileName(
					this,
					tr("Datei öffen:"),
					e_workdir->text(),
					tr("All Files (*);;Text Files (*.txt)"),
					&selectedFilter,
					options
				);
	if (!datafileName.isEmpty()) 
		e_data2->setText(datafileName);
}

void pzgtools::opendata3() 
{
	QFileDialog::Options options;
	QString selectedFilter;
	QString datafileName = QFileDialog::getOpenFileName(
					this,
					tr("Datei öffen:"),
					e_workdir->text(),
					tr("All Files (*);;Text Files (*.txt)"),
					&selectedFilter,
					options
				);
	if (!datafileName.isEmpty()) 
		e_data3->setText(datafileName);
}

void pzgtools::opendata4()
{
	QFileDialog::Options options;
	QString selectedFilter;
	QString datafileName = QFileDialog::getOpenFileName(
					this,
					tr("Datei öffen:"),
					e_workdir->text(),
					tr("All Files (*);;Text Files (*.txt)"),
					&selectedFilter,
					options
				);
	if (!datafileName.isEmpty()) 
		e_data4->setText(datafileName);
}


void pzgtools::opendata5()
{
	QFileDialog::Options options;
	QString selectedFilter;
	QString datafileName = QFileDialog::getOpenFileName(
					this,
					tr("Datei öffen:"),
					e_workdir->text(),
					tr("All Files (*);;Text Files (*.txt)"),
					&selectedFilter,
					options
				);
	if (!datafileName.isEmpty()) 
		e_data5->setText(datafileName);
}




void pzgtools::plot()
{
	QString wd;
	QString pltfile;
	QString title;
	
	
	QString program = "plotter.pl";
	QProcess plot;
	
	//wd: the working directory
	QStringList w;
	QString workdir = e_workdir->text();
	if (workdir == "") 
		QMessageBox::warning(this,tr("Warning"),tr("No workdir spezified."),tr("OK"));
	w << "--workdir=" << workdir;
	wd = w.join("");
	
	//pltfile
	QStringList pf;
	pf << "--plotfile=" << e_plotfile->text();
	pltfile = pf.join("");
	
	//title
	QStringList t;
	t << "--title=" << e_title->text();
	title = t.join("");
	
	//qDebug() << program << wd << pltfile << title << e_data1->text() << e_data2->text() << e_data3->text() << e_data4->text() << e_data5->text();
	
	QStringList arguments;
	arguments << wd << pltfile << title << e_data1->text() << e_data2->text() << e_data3->text() << e_data4->text() << e_data5->text();
	
	
	//Process:
			QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
			plot.start(program,arguments);
			
			qDebug() << "starte!";
			qDebug() << program << wd << pltfile << title << e_data1->text() << e_data2->text() << e_data3->text() << e_data4->text() << e_data5->text();
			
			if ( !plot.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				plot.waitForFinished();

				QApplication::restoreOverrideCursor();
				
				/***************************
				QMessageBox::information(
					this,
					tr("Information"),
					tr("String wurde gesendet." ),
					tr("OK")
					);
					**************************/
				qDebug() << "done: " ;
			} // end if (process)
			QApplication::restoreOverrideCursor();
}



void pzgtools::get_climate()
{
	
	
	// - - - - - - TEMP- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	
	if (radio_temp->isChecked() ) {
		qDebug() << "getting temp ...";
		
		QString program1;
		program1 = "extract.pl";
		QProcess extract;
		
		QStringList arguments1;
		
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		
		QStringList w;
		QString wd;
		QString workdir = e_climateWorkDir->text();
		if (workdir == "") 
			QMessageBox::warning(this,tr("Warning"),tr("No workdir spezified."),tr("OK"));
		w << "--workdir=" << workdir;
		wd = w.join("");
		
		arguments1 << wd << "-temp" << "--title=Temperature" << e_PathFile->text();
		
			extract.start(program1,arguments1);
			qDebug() << "starting extract ... ";
			if ( !extract.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				extract.waitForFinished();

				QApplication::restoreOverrideCursor();
				
				qDebug() << "... done. ";
			} // end if (process)
			QApplication::restoreOverrideCursor();
		
			
			
			QString pltfile;
			QString title;
	
	
			QString program2 = "plotter.pl";
			QProcess plot;
	
			QString pf;
			pf = "--plotfile=temp.plt";
	
			QStringList t;
			t << "--title=Temperature_" << e_PathFile->text();
			title = t.join("");
	
			QStringList arguments2;
			arguments2 << wd << pf << title << "temperature.txt";
			
			//Process:
			QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
			plot.start(program2,arguments2);
			
			qDebug() << "starting plotter for temp ...";
			qDebug() << program2 << wd << pf << title << "temperature.txt";
			
			if ( !plot.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				plot.waitForFinished();
				QApplication::restoreOverrideCursor();
				qDebug() << "... done. " ;
			} // end if (process)
			QApplication::restoreOverrideCursor();
			
		
	} // END TEMP
	
	
	
	
	
	// - - - - - -HUMI - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	if (radio_humi->isChecked() ) {
		qDebug() << "humi";
		QString program1;
		program1 = "extract.pl";
		QProcess extract;
		
		QStringList arguments1;
		
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		
		QStringList w;
		QString wd;
		QString workdir = e_climateWorkDir->text();
		if (workdir == "") 
			QMessageBox::warning(this,tr("Warning"),tr("No workdir spezified."),tr("OK"));
		w << "--workdir=" << workdir;
		wd = w.join("");
		
		arguments1 << wd << "-humi" << "--title=Humidity" << e_PathFile->text();
		
			extract.start(program1,arguments1);
			qDebug() << "starting extract ... ";
			if ( !extract.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				extract.waitForFinished();

				QApplication::restoreOverrideCursor();
				
				qDebug() << "... done. ";
			} // end if (process)
			QApplication::restoreOverrideCursor();
		
			
			
			QString pltfile;
			QString title;
	
	
			QString program2 = "plotter.pl";
			QProcess plot;
	
			QString pf;
			pf = "--plotfile=humi.plt";
	
			QStringList t;
			t << "--title=Humidity_" << e_PathFile->text();
			title = t.join("");
	
			QStringList arguments2;
			arguments2 << wd << pf << title << "humidity.txt";
			
			//Process:
			QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
			plot.start(program2,arguments2);
			
			qDebug() << "starting plotter for humi ...";
			qDebug() << program2 << wd << pf << title << "humidity.txt";
			
			if ( !plot.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				plot.waitForFinished();
				QApplication::restoreOverrideCursor();
				qDebug() << "... done. " ;
			} // end if (process)
			QApplication::restoreOverrideCursor();
	}
	
	
	
	
	
	// - - - - - PRES(S)- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	if (radio_pres->isChecked() ) {
		qDebug() << "pres";
		
		QString program1;
		program1 = "extract.pl";
		QProcess extract;
		
		QStringList arguments1;
		
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		
		QStringList w;
		QString wd;
		QString workdir = e_climateWorkDir->text();
		if (workdir == "") 
			QMessageBox::warning(this,tr("Warning"),tr("No workdir spezified."),tr("OK"));
		w << "--workdir=" << workdir;
		wd = w.join("");
		
		arguments1 << wd << "-press" << "--title=Pressure" << e_PathFile->text();
		
			extract.start(program1,arguments1);
			qDebug() << "starting extract ... ";
			if ( !extract.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				extract.waitForFinished();

				QApplication::restoreOverrideCursor();
				
				qDebug() << "... done. ";
			} // end if (process)
			QApplication::restoreOverrideCursor();
		
			
			
			QString pltfile;
			QString title;
	
	
			QString program2 = "plotter.pl";
			QProcess plot;
	
			QString pf;
			pf = "--plotfile=press.plt";
	
			QStringList t;
			t << "--title=Pressure_" << e_PathFile->text();
			title = t.join("");
	
			QStringList arguments2;
			arguments2 << wd << pf << title << "pressure.txt";
			
			//Process:
			QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
			plot.start(program2,arguments2);
			
			qDebug() << "starting plotter for temp ...";
			qDebug() << arguments2;
			
			if ( !plot.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				plot.waitForFinished();
				QApplication::restoreOverrideCursor();
				qDebug() << "... done. " ;
			} // end if (process)
			QApplication::restoreOverrideCursor();
		
	}
	
	
	
	
	// - - - - -VELO - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	if (radio_velo->isChecked() ) {
		qDebug() << "velo";
		
		QString program1;
		program1 = "extract.pl";
		QProcess extract;
		
		QStringList arguments1;
		
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		
		QStringList w;
		QString wd;
		QString workdir = e_climateWorkDir->text();
		if (workdir == "") 
			QMessageBox::warning(this,tr("Warning"),tr("No workdir spezified."),tr("OK"));
		w << "--workdir=" << workdir;
		wd = w.join("");
		
		arguments1 << wd << "-velo" << "--title=Velocity" << e_PathFile->text();
		
			extract.start(program1,arguments1);
			qDebug() << "starting extract ... ";
			if ( !extract.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				extract.waitForFinished();

				QApplication::restoreOverrideCursor();
				
				qDebug() << "... done. ";
			} // end if (process)
			QApplication::restoreOverrideCursor();
		
			
			
			QString pltfile;
			QString title;
	
	
			QString program2 = "plotter.pl";
			QProcess plot;
	
			QString pf;
			pf = "--plotfile=velo.plt";
	
			QStringList t;
			t << "--title=Velocity_" << e_PathFile->text();
			title = t.join("");
	
			QStringList arguments2;
			arguments2 << wd << pf << title << "velocity.txt";
			
			//Process:
			QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
			plot.start(program2,arguments2);
			
			qDebug() << "starting plotter for temp ...";
			qDebug() << arguments2;
			
			if ( !plot.waitForStarted() ) {
				// failed.
				QApplication::restoreOverrideCursor();
				qWarning("failed.");
				QMessageBox::warning(
				this,
				tr("Failed!"),
				tr("Program not found." ),
				tr("OK")
				);
			} 
			else {
				//ok
				plot.waitForFinished();
				QApplication::restoreOverrideCursor();
				qDebug() << "... done. " ;
			} // end if (process)
			QApplication::restoreOverrideCursor();
	}
	
	
	
} // END get_climate()



//EOF

