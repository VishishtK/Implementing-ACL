How to run the system
1. Go inside the SE-1 directory which contains the makefile
2. in the terminal run the command sudo -i to login as root
3. run the makefile
4. Logout from root
5. Login with any userid.
6. run ./main to use the commands
7. write the command you want to run (fget,fput,getacl, etc)
8. You will be prompted to enter the file name or enter the data according to the command you run.
9. Also create the home directories in simple_slash/home for every user.(home/azim, home/bill etc).


Assumptions:
Only the owner of the file can edit the acl entries of the file.
The permissions entered are in the form of numbers. 4 for read , 2 for write, 1 for exec , 4 + 2 = 6 for read and write and so on.
When the file is created the permission by default is 7 for the owner.
Any user without an acl entry will have permission 0.
ACl entries are of the form user_id->permission.

Defence against three attacks.
Owner will always be able to use setacl even if the permission is 0.
Permission under 0 and over 7 are not accepted.
Data with size greater than 10000 chars is gracefully rejected as the array szie is 10000.
Owner's acl enrty cannot be removed.
Only owner is allowed to change acl entries to avoid malicious changes.
The system does not crash because of an invalid input. It rejects the input gracefully.
If the file is not found then the system handles the event gracefully.