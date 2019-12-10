#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

using namespace std;

struct acl{
    int user_id;
    int permission;
};

struct file_data{
    int acl_len;
    char data[10000];
    int data_len;
    struct acl perm[256];
};

uid_t getuid_byName(const char *name){
    if(name) {
        struct passwd *pwd = getpwnam(name); /* don't free, see getpwnam() for details */
        if(pwd) return pwd->pw_uid;
    }
  return -1;
}

int check_perm(string file_name){
	file_data new_data;    
	int uid = getuid();
	string user_name;
	int perm;
	int i = 0;

    FILE *streaming = fopen(file_name.c_str(), "rb");

    if(streaming == NULL){
        cout<<"File not found\n";
        return 0;
    }

    fread(&new_data, sizeof(new_data), 1, streaming);
    fclose(streaming);

    if(uid == new_data.perm[0].user_id){
    	//seteuid(getuid());
    	cout<<"Enter username\n";
		cin>>user_name;
		cout<<"Enter permission\n";
		cin>>perm;
		if (perm<0 || perm>7)
		{
			cout<<"Invalid permission";
			return 0;
		}
		uid = getuid_byName(user_name.c_str());
		for(i = 0;i<new_data.acl_len;i++){
    		if(new_data.perm[i].user_id == uid){
    			new_data.perm[i].permission = perm;
    			perm = -1;
    			//cout<<perm<<","<<uid;
    		}
    	}
    	if (perm != -1)
    	{
    		i = new_data.acl_len;
    		new_data.perm[i].user_id = uid;
    		new_data.perm[i].permission = perm;
    		new_data.acl_len += 1;
    		//cout<<perm<<uid;
    	}
    	//cout<<1;
    	seteuid(getuid());
    	FILE *streaming = fopen(file_name.c_str(), "wb");
    	fwrite(&new_data, sizeof(new_data), 1, streaming);
    	fclose(streaming);
    	return 1;
    }
    else{
    	//cout<<"reached\n";
    	return 0;
    }

    
}


int main(){
	cout<<"Enter file name\n";
	string input;
	cin>> input;
	if(check_perm(input)){

	}
	else{
		cout<<"Permission Denied\n";
	}
	
	return 0;
}