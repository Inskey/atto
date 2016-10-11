#!/usr/bin/perl

use strict;
use warnings;

use File::Copy qw(copy);


# Compile to /bin/atto


# Create /etc/atto and copy some files
my $gconf = '/etc/atto';
unless (-d $gconf)
{
	mkdir $gconf, 0755; # rwxr-xr-x
}
unless (-f $gconf . 'atto.conf')
{
	copy 'config/atto.conf', $gconf . 'atto.conf';
}
my @files = <config/syntax-highlighting/*>;
foreach my $file (@files)
{
	my $gconffile = $gconf . '/syntax-hightlighting/' . $file;
	unless (-f $gconffile)
	{
		copy $file, $gconffile;
	}
}
