#include<stdio.h>
#include<stdlib.h>

//USAGE: for an non-priv user to add new non-priv users to the system
//arguments are set for "useradd" and user added is not appended to sudoers file



int main(int argc, char **argv){

	//UID of user must be 0 to use required commands
	setuid(0);

	//create C variables to store both ags
	char *name     = argv[1];
	char *password = argv[2];

	//store result of getpwnam (returns 0 if user is not located)
	//used for error condition "user already exists" to break out of script
	int userLocated = getpwnam(name);
	

//ERROR CONDITIONS-----------------------------------------------------------------

//insufficient num of args
if (argc != 3){
	printf("\nERROR: Insufficient args provided... exiting\n");
	printf("usage: ./thisscriptname [desired_username] [desired_password]\n\n");
	return 1;
}//end if

//user already exists and script need not continue
if (userLocated != 0){
	printf("\nERROR: User [%s] already exists on this system... exiting\n\n" , name);
	return 1;
}//end if

//end ERROR COND-------------------------------------------------------------------


	//create command spaces in memory
	char command1[50];
	char command2[50];


	//build command1 so linux can understand it
	//use: adding user to system and setting password to second arg
	sprintf(command1, "/sbin/useradd %s -p %s" , name, password);
	system(command1);


	//build command2 so linux can understand it
	//use: create directory in users home for daily reports (standard practice for all users)
	sprintf(command2, "mkdir /home/%s/dailyReports.txt" , name); 
	system(command2);


	//print out welcome message to confirm user was added to system and inform them 
	//of admin accounts names/other misc. information they may need 
	//POSSIBLE MOTD implementation
	system("/usr/bin/cat /var/welcomeMessage.txt");

}//end main

