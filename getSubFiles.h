
/**************************  
 * File Name: getSubFiles.h
 * Author: No One  
 * E-mail: 1130395634@qq.com  
 * Created Time: 2017-03-09 14:02:15
**************************/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

using namespace std;


int getFiles(const char* path, vector<string>& files){

	files.clear();
	const string path0 = path;
	DIR* pDir;
	struct dirent* ptr;

	struct stat s;
	lstat(path, &s);

	if(!S_ISDIR(s.st_mode)){
		cout << "not a valid directory: " << path << endl;
		return -1;
	}
	
	if(!(pDir = opendir(path))){
		cout << "opendir error: " << path << endl;
		return -2;
	}
	int i = 0;
	string subFile;
	while((ptr = readdir(pDir)) != 0){
		subFile = ptr -> d_name;
		if(subFile == "." || subFile == "..")
			continue;
		files.push_back(subFile);
	}
	closedir(pDir);

	return 0;
}

