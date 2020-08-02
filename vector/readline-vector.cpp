#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool getFileConents(string filename, vector<string>& strv){
    ifstream in(filename.c_str());
    if(!in){
        cerr<<"Can't open the file : "<<filename<<endl;
        return false;
    }

    string str;
    //Read the next line from File until it reaches the end.
    while(std::getline(in, str)){
        if(str.size()>0){
            strv.push_back(str);
        }
    }
    in.close();
    return true;
}

int main(){
    vector<string> strv;
    string filename = "pushkin.txt";
    bool ret = getFileConents(filename, strv);

    if(ret==true){
        for(string& line :strv)
            cout<<line<<endl;
    }else{
        cout<<"Fail to read "<<filename<<endl;
    }
    return 0;
}