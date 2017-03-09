
#include "opencv2/imgproc/imgproc.hpp"    
#include "opencv2/highgui/highgui.hpp"    
#include <math.h>    
#include <stdlib.h>    
#include <stdio.h>   
#include <iostream>
#include <string>

#include </home/wjx/study/jiazhuangxian/workspace/getSubFiles.h>

using namespace cv;  
using namespace std;
  
//全局变量    
Mat src, dst, tmp;  
const string window_name = "pyrDown and pyrUp Demo";  
 
int sub_sample(const string filePath, int minWith, int minHeight, bool both);

int main(int argc, char** argv)  
{  
  
	const string filePath = "../data/fluor1_Apple_003.jpg";
	int minWidth = 20;
	int minHeight = 20;
	bool both = true;

	sub_sample(filePath, minWidth, minHeight, both);

    return 0; 
}


// 把原始图片压缩到指定大小，both表示是都width和height都要满足达到min
int sub_sample(string filePath, int minWith, int minHeight, bool both){
    
	//测试图像  
    src = imread(filePath, 0);  
    if (!src.data)  
    {  
        printf(" No data! -- Exiting the program \n");  
        return -1;  
    }  
    
	tmp = src;
    dst = tmp;  
	cout << dst.rows << ", " << dst.cols << endl;
    
	//创建显示窗口    
    namedWindow(window_name, CV_WINDOW_AUTOSIZE);  
    imshow(window_name, dst);  

	waitKey(0);
    //循环    
    while (true)  
    {  
		if((both && dst.rows <= minHeight && dst.cols << minWith) || 
				(!both && (dst.rows <= minHeight || dst.cols << minWith))){
			break;
		}

        pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));  
        cout << "pryDown : Image / 2" << endl;  
		cout << dst.rows << ", " << dst.cols << endl;
        
		tmp = dst;  
    }  
    imshow(window_name, dst);

	waitKey(0);
	return 0;
}
