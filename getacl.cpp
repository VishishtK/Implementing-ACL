#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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

void get_acl(string file_name){
    file_data new_data;    

    FILE *streaming = fopen(file_name.c_str(), "rb");

    if(streaming == NULL){
        cout<<"File not found\n";
        return;
    }

    fread(&new_data, sizeof(new_data), 1, streaming);

    for(int i = 0;i<new_data.acl_len;i++){
    	cout << new_data.perm[i].user_id << "->" << new_data.perm[i].permission<<endl;
    }

    fclose(streaming);
}

int main(){
	string input;
	cout<<"Enter file name\n";
	cin>>input;
	get_acl(input);
	return 0;
}