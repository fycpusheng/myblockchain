#################################################
# Checks if myblockchaind_safe is installed in the path
# specified by MTR. myblockchaind_safe is obsolete on
# platforms that use systemd to monitor myblockchaind.
#################################################

--disable_query_log
--let $temp_inc=$MYBLOCKCHAIN_TMP_DIR/tmp.inc
let inc_tmp=$temp_inc;

--perl
use strict;
my $is_myblockchaind_safe_present=0;
$is_myblockchaind_safe_present=1 if -e $ENV{'MYBLOCKCHAIND_SAFE'};

my $temp_inc= $ENV{'inc_tmp'} or die "temp_inc not set";
open(FILE_INC, ">", "$temp_inc") or die("can't open file \"$temp_inc\": $!");
print FILE_INC '--let $is_found= '.$is_myblockchaind_safe_present;

EOF

--source $temp_inc

if (!$is_found)
{
--skip Tests using myblockchaind_safe skipped.
}

--remove_file $temp_inc
--enable_query_log
