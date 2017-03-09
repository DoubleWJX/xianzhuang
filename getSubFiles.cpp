
/**************************  
 * File Name: getSubFiles.cpp
 * Author: No One  
 * E-mail: 1130395634@qq.com  
 * Created Time: 2017-03-09 14:02:15
**************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

#include </home/wjx/study/jiazhuangxian/workspace/getSubFiles.h>

using namespace std;


int main(){

	string folder = "/home/wjx/study/jiazhuangxian/data/re_SIVAL/";
	vector<string> files;
	getFiles(folder.c_str(), files);

	for_each(files.begin(), files.end(), [](const string &s){cout << s << endl; });
    

    cout << endl;
}

