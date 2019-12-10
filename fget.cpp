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

void read_file(string file_name){
    file_data new_data;
    int uid = getuid();

    FILE *streaming = fopen(file_name.c_str(), "rb");

    if(streaming == NULL){
        cout<<"File not found\n";
        return;
    }

    fread(&new_data, sizeof(new_data), 1, streaming);

    for (int i = 0; i < new_data.acl_len; ++i)
    {
        if (uid == new_data.perm[i].user_id)
        {
            if (new_data.perm[i].permission >=4)
            {
                cout << "reading:\n";
                cout << new_data.data << endl;
                fclose(streaming);
                return;
            }
            else{
                cout << "Permission denied\n";
                fclose(streaming);
                return;
            }
        }
    }

    cout<<"Permission denied\n";
    // cout << new_data.data_len << endl;
    // cout << new_data.perm[0].user << endl;
    // cout << new_data.perm[0].permission << endl;
    // cout << new_data.perm[1].user << endl;
    // cout << new_data.perm[1].permission << endl;

    fclose(streaming);
}

int main(){
    string input;
    cout<<"Enter file name\n";
    getline(cin,input);
    read_file(input);
    //cout<<getuid();
    //cout<<geteuid();
    return 0;
}