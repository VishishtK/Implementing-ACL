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

void write_file(string file_name){
	string input;
	cout<<"Enter data\n";
	getline(cin,input);
	if (input.size()>=10000)
	{
		cout<<"Invalid input too long";
		return;
	}
    file_data data;

    FILE *streaming = fopen(file_name.c_str(), "wb");
    if (streaming==NULL)
    {
    	cout<<"Could not write\n";
    	return;
    }

    strcpy(data.data, input.c_str());
    data.data_len = input.size();
    data.perm[0].user_id = getuid();
    data.perm[0].permission = 7;
    data.acl_len = 1;

    fwrite(&data, sizeof(data), 1, streaming);
    chown(file_name.c_str(),getuid(),getgid());

    fclose(streaming);
}



void update_file(string file_name){
	file_data new_data;    
	int uid = getuid();

    FILE *streaming = fopen(file_name.c_str(), "rb");

    if(streaming == NULL){
        cout<<"File not found\n";
        return ;
    }

    fread(&new_data, sizeof(new_data), 1, streaming);
    fclose(streaming);

    for (int i = 0; i < new_data.acl_len; ++i)
    {
    	if (new_data.perm[i].user_id==uid)
    	{
    		/* code */
    		int perm = new_data.perm[i].permission;
    		if (perm == 2 || perm == 3 || perm > 5 )
    		{
    			string temp;
    			cout<<"Enter new data\n";
    			getline(cin,temp);
    			if (temp.size()>=10000)
    			{
    				cout<<"Input too long";
    				return;
    			}
    			strcpy(new_data.data,temp.c_str());
    			FILE *streaming = fopen(file_name.c_str(), "wb");
    			fwrite(&new_data, sizeof(new_data), 1, streaming);
    			fclose(streaming);
    			return;
    		}
    		else{
    			cout<<"permission denied\n";
    			return;
    		}
    	}
    }
    cout<<"permission denied\n";
    return;
}

int check(string file_name){
	//cout<<"re";
	FILE *streaming = fopen(file_name.c_str(), "rb");
    if (streaming==NULL)
    {
    	write_file(file_name);
    	//cout<<"1\n";
    	fclose(streaming);
    	return 1;
    }
    fclose(streaming);
    update_file(file_name);
    return 0;
}

int main(){
	cout<<"Enter file name\n";
	string input;
	getline(cin,input);
	int temp = check(input);
	return 0;
	
}