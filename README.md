# CHKSMS 🔎
CHKSMS is a simple program that I wrote, it combines the use of both shell and C to crossreference hashes of files with a [known list of malicious hashes](https://github.com/eminunal1453/Various-Malware-Hashes). This is a pretty simple project that i've thrown together and I plan to do a little bit more with this program

## How to use
If you wish to use this program, it's quite simple. Enter wherever you've downloaded the directory and enter it. Once there, run bash ./checkSums.sh, it may ask for sudo privelages, if so, allow it.
If you wish to change the directory it scans in, there's a simple variable you can change at the very top of the sh script, just open it with nano or vim and edit it and you're good to go!

## Final notes
Obviously, **THIS WILL ONLY WORK ON LINUX**. It runs inside of an SH script and uses linux commands, therefore, if you're running this on a windows machine it will not work. I've tried this on two OS' so far, both Kali Linux and Ubuntu server and they both seem to run the script perfectly.

For any extra support or notes, feel free to DM me on Discord ``@avalikesbread_``
