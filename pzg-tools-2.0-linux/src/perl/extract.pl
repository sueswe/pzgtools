#!/usr/bin/perl -w
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
#

use Getopt::Long;
use strict;
my $VERSION = "2.0.rc2-linux";
my $DATE = "22.Sep.2007";


GetOptions (
	"temp"		=>\my $temp,
	"press"		=>\my $press,
	"velo"		=>\my $velo,
	"humi"		=>\my $humi,
	"workdir=s"		=>\my $workdir,
	"size=s"		=>\my $size,
	"line_output=s"	=>\my $line_output,
	"row_output=s"	=>\my $row_output,
	"help|?"		=>\my $help,
);

help() and exit(0) if defined $help;



if ($workdir && $temp) {
	get_temp();
}
if ($workdir && $press) {
	get_press();
}
if ($workdir && $velo) {
	get_velo();
}
if ($workdir && $humi) {
	get_humi();
}




get_lines();
get_rows();
#show_w32();
show_unix();

##################################################

sub get_lines {
	
help() and exit(0) if defined $help;

if (! $workdir) {
    print "Need a working directory.\n";
    print "Try -? for help.\n";
    exit(0);
}
elsif (! $size ) {
    print "No particle size defined.\n";
    print "Try -? for help\n";
    exit(0);
}
elsif (! $line_output) {
    print "No output-file defined.\n";
    print "Try -? for help\n";
    exit(0);
}
elsif  (! @ARGV ) {
	print "*** Need a datafile.\n";
	help();
	exit();
}	
else {

	# OUTPUT �ffnen zum Schreiben
	my $micrometer = "um";
	open (OUTPUT, ">$workdir//$line_output") || die "Could not open $workdir//$line_output : $!\n";
	chdir($workdir)||die"chdir: $!\n";
	while (<>) {
		if( $_ =~ /$size$micrometer/ ) {
		print OUTPUT "$_";
		}
	}
	close(OUTPUT);
} #end ELSE

} #end sub 

##################################################



sub get_rows {
	
	
if (! $workdir) {
    print "Need a working directory.\n";
    print "Try -? for help.\n";
    exit(0);
}
elsif (! $row_output) {
    print "No filename given.\n";
    print "Try -? for help.\n";
    exit(0);
} else {

	$, = ' ';               # set output field separator
	$\ = "\n";              # set output record separator

	my $Fld1 = "";
	my $Fld2 = "";
	my $Fld3 = "";

	
	print "Using: $line_output \n";
	
	if (-e $row_output) {
		print "deleting old $row_output ... \n";
		unlink($row_output);
	}
	
	open (IN,"<$line_output");
	
	while (<IN>) {
		open (OUTPUT, ">>$workdir//$row_output") || die "Could not open $workdir//$row_output: $!\n";
		($Fld1,$Fld2,$Fld3) = split(' ', $_, 9999);
		#we don't want any other output than field 3
		print OUTPUT $Fld3;
	}
	close(OUTPUT);
}#end ELSE
} #end SUB get_row


##################################################

sub get_temp {
	
	chdir($workdir)||die"chdir: $!\n";
	
	my $TEMP_LINES = "temp_lines";
	my $TEMP_DATA = "temperature.txt";
	
	print "Extracting temperature ...\n";
	if  (! @ARGV ) {
		print "*** Need a datafile.\n";
		help();
		exit(0);
	}	
	
	#
	# First, we try to get the lines that including Temp
	#
	
	my $TEMP_CHAR = "Temp";
	open (OUTPUT_1, ">$workdir//$TEMP_LINES") || die "Could not open $workdir//$TEMP_LINES : $!\n";
	# we do this at the beginning ... :
	#chdir($workdir)||die"chdir: $!\n";
	while (<>) {
		if( $_ =~ /$TEMP_CHAR/ ) {
		print OUTPUT_1 "$_";
		}
	}
	close(OUTPUT_1);
	system("cat $TEMP_LINES");
	print "done getting lines with 'Temp' ...\n";
	
	
	#
	# Now, we extract field 2
	#
	
	$, = ' ';               # set output field separator
	$\ = "\n";              # set output record separator

	my $Fld1 = "";
	my $Fld2 = "";
	my $Fld3 = "";

	
	open (IN,"<$TEMP_LINES");
	
	# we have to remove old files if exist
	if (-e $TEMP_DATA) {
		print "deleting old $TEMP_DATA...\n";
		unlink($TEMP_DATA);
	}
	
	while (<IN>) {
		open (OUTPUT_2, ">>$TEMP_DATA") || die "Could not open $workdir//$TEMP_DATA: $!\n";
		($Fld1,$Fld2,$Fld3) = split(' ', $_, 9999);
		#we don't want any other output than field 2
		print OUTPUT_2 $Fld2;
	}
	close(OUTPUT_2);
	
	system("cat $TEMP_DATA");
	
	print "ready extracting temperature.\n";
	
	# Ok, lets quit. Job done.
	exit(0);
	
}


###################################################

sub get_press {
	
	chdir($workdir)||die"chdir: $!\n";
	
	my $PRES_LINES = "pres_lines";
	my $PRES_DATA = "pressure.txt";
	
	print "Extracting pressure ...\n";
	if  (! @ARGV ) {
		print "*** Need a datafile.\n";
		help();
		exit(0);
	}	
	
	#
	# First, we try to get the lines that including Temp
	#
	
	my $PRES_CHAR = "Pres";
	open (OUTPUT_1, ">$workdir//$PRES_LINES") || die "Could not open $workdir//$PRES_LINES : $!\n";
	# we do this at the beginning ... :
	#chdir($workdir)||die"chdir: $!\n";
	while (<>) {
		if( $_ =~ /$PRES_CHAR/ ) {
		print OUTPUT_1 "$_";
		}
	}
	close(OUTPUT_1);
	system("cat $PRES_LINES");
	print "done getting lines with 'Pres' ...\n";
	
	
	#
	# Now, we extract field 2
	#
	
	$, = ' ';               # set output field separator
	$\ = "\n";              # set output record separator

	my $Fld1 = "";
	my $Fld2 = "";
	my $Fld3 = "";

	
	open (IN,"<$PRES_LINES");
	
	# we have to remove old files if exist
	if (-e $PRES_DATA) {
		print "deleting old $PRES_DATA...\n";
		unlink($PRES_DATA);
	}
	
	while (<IN>) {
		open (OUTPUT_2, ">>$PRES_DATA") || die "Could not open $workdir//$PRES_DATA: $!\n";
		($Fld1,$Fld2,$Fld3) = split(' ', $_, 9999);
		#we don't want any other output than field 2
		print OUTPUT_2 $Fld2;
	}
	close(OUTPUT_2);
	
	system("cat $PRES_DATA");
	
	print "ready extracting pressure.\n";
	
	# Ok, lets quit. Job done.
	exit(0);
	
	
	
}


###################################################

sub get_velo {
	
	chdir($workdir)||die"chdir: $!\n";
	
	my $VELO_LINES = "velo_lines";
	my $VELO_DATA = "velocity.txt";
	
	print "Extracting velocity ...\n";
	if  (! @ARGV ) {
		print "*** Need a datafile.\n";
		help();
		exit(0);
	}	
	
	#
	# First, we try to get the lines that including Temp
	#
	
	my $VELO_CHAR = "Velo";
	open (OUTPUT_1, ">$workdir//$VELO_LINES") || die "Could not open $workdir//$VELO_LINES : $!\n";
	# we do this at the beginning ... :
	#chdir($workdir)||die"chdir: $!\n";
	while (<>) {
		if( $_ =~ /$VELO_CHAR/ ) {
		print OUTPUT_1 "$_";
		}
	}
	close(OUTPUT_1);
	system("cat $VELO_LINES");
	print "done getting lines with 'Velo' ...\n";
	
	
	#
	# Now, we extract field 2
	#
	
	$, = ' ';               # set output field separator
	$\ = "\n";              # set output record separator

	my $Fld1 = "";
	my $Fld2 = "";
	my $Fld3 = "";

	
	open (IN,"<$VELO_LINES");
	
	# we have to remove old files if exist
	if (-e $VELO_DATA) {
		print "deleting old $VELO_DATA...\n";
		unlink($VELO_DATA);
	}
	
	while (<IN>) {
		open (OUTPUT_2, ">>$VELO_DATA") || die "Could not open $workdir//$VELO_DATA: $!\n";
		($Fld1,$Fld2,$Fld3) = split(' ', $_, 9999);
		#we don't want any other output than field 2
		print OUTPUT_2 $Fld2;
	}
	close(OUTPUT_2);
	
	system("cat $VELO_DATA");
	
	print "ready extracting velocity.\n";
	
	# Ok, lets quit. Job done.
	exit(0);
	
	
}


###################################################


sub get_humi {
	
	
	chdir($workdir)||die"chdir: $!\n";
	
	my $HUMI_LINES = "humi_lines";
	my $HUMI_DATA = "humidity.txt";
	
	print "Extracting humidity ...\n";
	if  (! @ARGV ) {
		print "*** Need a datafile.\n";
		help();
		exit(0);
	}	
	
	#
	# First, we try to get the lines that including Temp
	#
	
	my $HUMI_CHAR = "Humi";
	open (OUTPUT_1, ">$workdir//$HUMI_LINES") || die "Could not open $workdir//$HUMI_LINES : $!\n";
	# we do this at the beginning ... :
	#chdir($workdir)||die"chdir: $!\n";
	while (<>) {
		if( $_ =~ /$HUMI_CHAR/ ) {
		print OUTPUT_1 "$_";
		}
	}
	close(OUTPUT_1);
	system("cat $HUMI_LINES");
	print "done getting lines with 'Humi' ...\n";
	
	
	#
	# Now, we extract field 2
	#
	
	$, = ' ';               # set output field separator
	$\ = "\n";              # set output record separator

	my $Fld1 = "";
	my $Fld2 = "";
	my $Fld3 = "";

	
	open (IN,"<$HUMI_LINES");
	
	# we have to remove old files if exist
	if (-e $HUMI_DATA) {
		print "deleting old $HUMI_DATA...\n";
		unlink($HUMI_DATA);
	}
	
	while (<IN>) {
		open (OUTPUT_2, ">>$HUMI_DATA") || die "Could not open $workdir//$HUMI_DATA: $!\n";
		($Fld1,$Fld2,$Fld3) = split(' ', $_, 9999);
		#we don't want any other output than field 2
		print OUTPUT_2 $Fld2;
	}
	close(OUTPUT_2);
	
	system("cat $HUMI_DATA");
	
	print "ready extracting humidity.\n";
	
	# Ok, lets quit. Job done.
	exit(0);
	
	
}



###################################################
###################################################



sub help {
print qq
( Usage: $0 [OPTIONS]
Copyright (C) 2007  Werner Riener, GNU GPL
Version : $VERSION

Options:
 --workdir=DIR      	: The working directory where the datafiles are stored.
 --size=n           	: Where n is the size of the particles in micrometer.
 --line_output=file 	: Name of the first output file.
 --row_output=file	: Name of the final output file.
 --help             	: Displays this screen.
 --temp			: Extracts temperature (always use with --workdir)
 --press			: Extracts pressure (always use with --workdir)
 --velo			: Extracts velocity (always use with --workdir)
 --humi			: Extracts humidity (always use with --workdir)
 
All options can be passed in the short form, too
(e.g. -h for --help, -s for --size and so on).

Example:
 
 $0 -w=d:\\home\\data -s=5.0 -l=5.0_micrometer.txt -r=5.0_dat Prg020_20060105_849588
 
Example: extracting temperature data:

 $0 -w=/home/user/data/ --temp Prg020_20060105_849588
 
)

} #end sub Help



##################################################

sub show_w32 {
	#W32
	system("type $workdir\\$row_output");
}


##################################################

sub show_unix {
	#UNIX
	system("cat $workdir//$row_output");
}

__END__;
