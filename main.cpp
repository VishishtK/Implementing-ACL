#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
	string input;
	int pid;
	int status;
	while(1){
		cout<<"==>";
		cin>>input;
		if (input.compare("fput")==0)
		{
			pid = fork();
			if (pid==0)
			{
				execl("/home/vishisht/Desktop/SE-1/fput","null",(char*)NULL);
			}
			else if(pid<0){
				cout<<"fork failed";
			}
			else{
				wait(&status);
			}
		}

		else if (input.compare("fget")==0)
		{
			pid = fork();
			if (pid==0)
			{
				execl("/home/vishisht/Desktop/SE-1/fget","null",(char*)NULL);
			}
			else if(pid<0){
				cout<<"fork failed";
			}
			else{
				wait(&status);
			}
		}

		else if (input.compare("getacl")==0)
		{
			pid = fork();
			if (pid==0)
			{
				execl("/home/vishisht/Desktop/SE-1/getacl","null",(char*)NULL);
			}
			else if(pid<0){
				cout<<"fork failed";
			}
			else{
				wait(&status);
			}
		}

		else if (input.compare("setacl")==0)
		{
			pid = fork();
			if (pid==0)
			{
				execl("/home/vishisht/Desktop/SE-1/setacl","null",(char*)NULL);
			}
			else if(pid<0){
				cout<<"fork failed";
			}
			else{
				wait(&status);
			}
		}

		else if (input.compare("create_dir")==0)
		{
			pid = fork();
			if (pid==0)
			{
				execl("/home/vishisht/Desktop/SE-1/create_dir","null",(char*)NULL);
			}
			else if(pid<0){
				cout<<"fork failed";
			}
			else{
				wait(&status);
			}
		}


		else if (input.compare("exit")==0)
		{
			break;
		}

		else{
			cout<<"Commnd not found\n";
		}
		
	}
	return 0;
}