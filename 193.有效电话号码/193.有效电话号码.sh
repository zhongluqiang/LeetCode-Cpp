#
# @lc app=leetcode.cn id=193 lang=bash
#
# [193] 有效电话号码
#

# @lc code=start
# Read from the file file.txt and output all valid phone numbers to stdout.
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
# @lc code=end

