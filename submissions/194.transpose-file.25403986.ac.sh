#
# [194] Transpose File
#
# https://leetcode.com/problems/transpose-file/description/
#
# shell
# Medium (21.74%)
# Total Accepted:    7.3K
# Total Submissions: 33.4K
# Testcase Example:  'a'
#
# Given a text file file.txt, transpose its content.
# 
# You may assume that each row has the same number of columns and each field is
# separated by the ' ' character.
# 
# Example:
# 
# If file.txt has the following content:
# 
# 
# name age
# alice 21
# ryan 30
# 
# 
# Output the following:
# 
# 
# name alice ryan
# age 21 30
# 
# 
# 
# 
#
# Read from the file file.txt and print its transposed content to stdout.
gawk 'BEGIN{FS="\n";RS="";ORS=""} {lines[1]="";for(i=1;i<=NF;i++){count=split($i,var,/ /);for(j=1;j<=count;j++){lines[j]=lines[j]" "var[j];}}for(v in lines){print substr(lines[v],2)"\n";}}' file.txt
