
#include "opencv2/imgproc/imgproc.hpp"    
#include "opencv2/highgui/highgui.hpp"    
#include <math.h>    
#include <stdlib.h>    
#include <stdio.h>   
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#include </home/wjx/study/jiazhuangxian/workspace/getSubFiles.h>

using namespace cv;  
using namespace std;
  
//全局变量    
const string window_name = "pyrDown and pyrUp Demo";  
 
int sub_sample(const string filePath, Mat& dst, int minWith, int minHeight, bool both);
int checkAndCreateFile(const string filePath, bool rewrite);

int main(int argc, char** argv)  
{  
  
	string folderFrom = "/home/wjx/study/jiazhuangxian/data/re_SIVAL/";
	string folderTo = "/home/wjx/study/jiazhuangxian/data/re_SIVAL_after_sample/";
	vector<string> files;
	int minWidth = 20;
	int minHeight = 20;
	bool both = true;

	Mat dst;

	if(getFiles(folderFrom.c_str(), files)){
		cout << "get sub files error: " << folderFrom << endl;
		return 0;
	}

	vector<string>::iterator a = files.begin(), b = files.end();
    checkAndCreateFile(folderTo, false);


	int iSub_1 = 0;
	for(; a != b; ++a){
		string pathSub_1 = folderFrom + *a;
		string pathSub_1_to = folderTo + *a;
        checkAndCreateFile(pathSub_1_to, false);

		cout << ++iSub_1 << ": " << pathSub_1 << endl;
	
		vector<string> filesSub_1;
		
		
		getFiles(pathSub_1.c_str(), filesSub_1);
		
	    vector<string>::iterator aSub_1 = filesSub_1.begin(), bSub_1 = filesSub_1.end();

		int iSub_2 = 0;
		for(; aSub_1 != bSub_1; ++aSub_1){
			string pathSub_2 = pathSub_1 + "/" + *aSub_1;
			string pathSub_2_to = pathSub_1_to + "/" + *aSub_1;
			cout << iSub_1 << "\t" << ++iSub_2 << pathSub_2 << endl;
			cout << iSub_1 << "\t" << iSub_2 << pathSub_2_to << endl;

	        int ir = sub_sample(pathSub_2, dst, minWidth, minHeight, both);
	        if(!ir){
		        imwrite(pathSub_2_to, dst);

	        }else{
	     	    cout << "sub_sample error: " << ir << endl;
	        }

		}

	}

    return 0; 
}


// 把原始图片压缩到指定大小，both表示是都width和height都要满足达到min
int sub_sample(string filePath, Mat& dst, int minWith, int minHeight, bool both){
    
	//测试图像  
    Mat src = imread(filePath, 0);  
    if (!src.data)  
    {  
        printf(" No data! -- Exiting the program \n");  
        return -1;  
    }  
    
	Mat tmp = src;
    dst = tmp;  
	cout << dst.rows << ", " << dst.cols << endl;
    
	//创建显示窗口    
    namedWindow(window_name, CV_WINDOW_AUTOSIZE);  

    //循环    
    while (true)  
    {  
		if((both && dst.rows <= minHeight && dst.cols << minWith) || 
				(!both && (dst.rows <= minHeight || dst.cols << minWith))){
			break;
		}

        pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));  
		cout << dst.rows << ", " << dst.cols << endl;
        
		tmp = dst;  
    }  

	return 0;
}

int checkAndCreateFile(const string filePath, bool rewrite){

	if(access(filePath.c_str(), F_OK) == 0){
		// cout << "file exists: " << filePath << endl;
		if(rewrite){
			rmdir(filePath.c_str());
	        mkdir(filePath.c_str(), S_IRWXU);
		}
		return 0;
	}
	
	// cout << "file not exists: " << filePath << endl;

	mkdir(filePath.c_str(), S_IRWXU);

	return 0;

}
