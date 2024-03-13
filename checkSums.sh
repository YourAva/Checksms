#!/bin/bash
:
# ------ THANK YOU FOR USING CHKSMS, CONFIG BELOW --------
run_dir=~/Downloads # -- The file to run the check in. (Please get the directory from ~)
# --------------------------------------------------------

original_dir=$(pwd)

start_pos=0
end_pos=32

echo -e "\033[38;5;141m ______ _______ __  __ _______ _______ _______ "
echo -e "\033[38;5;129m|      |   |   |  |/  |     __|   |   |     __|"
echo -e "\033[38;5;93m|   ---|       |     <|__     |       |__     |"
echo -e "\033[38;5;85m|______|___|___|__|\__|_______|__|_|__|_______|"
echo -e "\033[0m             Made by AVALIKESBREAD             "
cd "$run_dir"
echo -e '\nStarting search...'

sudo find . -type f -exec md5sum {} + > "$original_dir/sumstemp.txt" || { echo -e "\033[31mCHKSMS Encountered an Error.\nEXITING PROGRAM\033[0m"; exit; }

while IFS= read -r line; do
  echo "${line:$start_pos:$end_pos}"
done < "$original_dir/sumstemp.txt" | sudo tee "$original_dir/checkSumsLog.txt" > /dev/null
rm "$original_dir/sumstemp.txt"

cd "$original_dir"
echo -e "\nCHKSMS has now compiled all your file tags, crossreferencing now..."

sudo ./crossReference

