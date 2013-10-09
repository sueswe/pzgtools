#!/usr/bin/perl -w
#
#
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
#
#
use Getopt::Long;
use strict;

my $VERSION = "2.0.rc2-linux";
my $DATE = "22.Sep.2007";

print "This is $0, version $VERSION\n";

GetOptions(
    "workdir=s"         => \my $workdir,
    "plotfile=s"        => \my $plotfile,
    "title=s"           => \my $title,
    "help|?"            => \my $help,
);

if ($help) {
    help();
    #sleep(5);
    exit(0);
}
elsif (! $workdir) {
    print "No workdir definded.\n";
    print "Type '$0 -?' for help.\n";
    #sleep(2);
    exit(0);
}
elsif (! $plotfile) {
    print "No filename given.\n";
    print "Type '$0 -?' for help.\n";
    #sleep(2);
    exit(0);
}
elsif (! $title ) {
    print "No title defined\n";
    print "Type '$0 -?' for help\n";
    #sleep(2);
    exit(0);
}
elsif ($#ARGV < 0) {
    print "No datafiles included.\n";
    print "cat '$0 -?' for help.\n";
    #sleep(2);
    exit;
}
else {
	print "Create_plot_file...\n";
	Create_plot_file();
	print "Trying to plot...\n";
	plotter();
}


###############################################

sub Create_plot_file {
	
# Open plotfile
print "Creating the plotfile $plotfile ... \n";
chdir($workdir) || die "Cannot change to $workdir : $!\n";

# Exists already?
if (-e $plotfile) {
	
	print "\n!\n-> Warning: Plotfile $plotfile already exists.\n";
	#print "Should I continue and overwrite it? (y/n) :";
	#chomp(my $DEL = <STDIN>);
	#if ($DEL eq "y") {
		print "Deleting ... ";
		unlink($plotfile) || die "Cannot unlink $plotfile: $! \n";
		print "done.\n";
	#} else {
	#	print "Nothing deleted. Exit now.\n";
	#	sleep(5);
	#	exit(0);
	#}
}

open (PLOT, ">>$plotfile");

print PLOT "set title '$title' \n";
#print PLOT "set pointsize 0.5 \n";
print PLOT "set grid \n";
print PLOT "set xlabel 'Messungen/measurement' \n";
print PLOT "set ylabel '(not set, please edit in plotfile)' \n";
print PLOT "plot '$ARGV[0]' title \"$ARGV[0]\" with lines \n";

for (my $i=1; $i<=5; $i++) {
    if ( $ARGV[$i] ) {
        print PLOT "replot '$ARGV[$i]' title \"$ARGV[$i]\" with lines \n";
    }
}
close (PLOT);

print "done.\n";
# sleep(3);

} # end SUB
#######################################

sub help {

print <<EOT

Usage: $0 --workdir=DIR --plotfile=filename --title=title FILE1 FILE2 FILE3 FILE4 FILE5 FILE6

Creates a Plotfile for wgnuplot including datafiles FILE{1-6} and tries to plot it.

Example:
$0 -w=\data -p=Class-B.plt -t=Measure_Class-B_from 0.3-micrometer 0.5-micrometer 1.0-micrometer

Copyright (C) 2007  Werner Riener, GNU GPL
EOT

}#end SUB help

#######################################

sub plotter {
    chdir($workdir) || die "Cannot change to $workdir : $! \n";

    if (-e $plotfile) {
        empty_check($plotfile);
	#Win32
	#system("wgnuplot $plotfile - trailer");
	#Linux
	system("gnuplot $plotfile - ");
    } else {
        print "Could not find plotfile $plotfile for gnuplot.\n";
	print "Please get sure the file exists!\n";
        print "Type plot -h for help.\n";
        #sleep(5);
        exit(0);
    }
}

#######################################

sub empty_check {
	
	my $FILE_TO_CHECK = shift;
	if ( ! -z "$FILE_TO_CHECK" ) {
		#file is not empty
		#continueing without any message
	} else {
		print "Error: $FILE_TO_CHECK is empty! \n";
		print "Nothing to plot.\n";
		print "Exit in 10 second ...\n";
		#sleep(10);
		exit(0);
	}
	
} #end empty_check

#######################################
