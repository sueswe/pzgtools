#ifndef pzgtools_H
#define pzgtools_H
#include "ui_pzgtools.h"

/**

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

**/

class pzgtools : public QWidget, private Ui::objectPZGtools
{
    Q_OBJECT

    public:
        pzgtools(QWidget *parent = 0);

    public slots:
	// Select:
        void open_datafile();
	void open_workdir();
    
	//Extract:
	void extract();
    
	//Plotting:
	void opendata1();
	void opendata2();
	void opendata3();
	void opendata4();
	void opendata5();
	void plot();
    
	//climate:
	void get_climate();
    
	//diverse
	void set_wd();
	void about();
	
    
    
    
};

#endif

