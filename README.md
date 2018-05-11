# 第6周上机实验任务:

1. 下载opencv 2.x/3.x,  在VS201x，或其它C/C++编程语言中配置opencv编译参数；参考课件ppt中的例子，编写一个图片格式转换和特效显示程序。

   ![](https://ws2.sinaimg.cn/large/006tNc79gy1fqfq3j15taj31ig12itju.jpg)

#### 由于rpath（谷歌rpath是动态链接库，要在Xcode中改配置）环境问题，需要在每次编译前运行rpath.sh脚本

   <img src="https://ws4.sinaimg.cn/large/006tNc79gy1fqfrud20nej31bg122qto.jpg" width="550px"/>


   #### 在Clion中配置before launch,编译前运行sh脚本,即可一劳永逸~

   参照stackoverflow

   ![](https://ws3.sinaimg.cn/large/006tNc79gy1fqfrwji9b8j315y0c0gnz.jpg)

   ![](https://ws3.sinaimg.cn/large/006tNc79gy1fqfrt59bu5j31kw0zin9e.jpg)

   #### 运行程序，结果如下：

   [taaarannn_magic_IplImage.png](https://github.com/zhaoxuyan/openCV_Clion/blob/master/cmake-build-debug/taaarannn_magic_IplImage.png)

   ![](https://ws3.sinaimg.cn/large/006tNc79gy1fqfx52s4baj31b81cmwl1.jpg)

2. 将 IplImage 结构换成 Mat结构，重新改写任务1的程序。

   > 早期的OpenCV中，使用IplImage和CvMat数据结构来表示图像。IplImage和CvMat都是C语言的结构。使用这两个结构的问题是内存需要手动管理，开发者必须清楚的知道何时需要申请内存，何时需要释放内存。这个开发者带来了一定的负担，开发者应该将更多精力用于算法设计，因此在新版本的OpenCV中引入了Mat类。
   > 新加入的Mat类能够自动管理内存。使用Mat类，你不再需要花费大量精力在内存管理上。而且你的代码会变得很简洁，代码行数会变少。但C++接口唯一的不足是当前一些嵌入式开发系统可能只支持C语言，如果你的开发平台支持C++，完全没有必要再用IplImage和CvMat。在新版本的OpenCV中，开发者依然可以使用IplImage和CvMat，但是一些新增加的函数只提供了Mat接口。本书中的例程也都将采用新的Mat类，不再介绍IplImage和CvMat。

   ```C
   void MatDoThis(Mat mat) {
       CvPoint center;
       double scale = -3;
       if (mat.empty()) {
           exit(0);
       }

       center = cvPoint(mat.cols / 2, mat.rows / 2);
       for (int i = 0; i < mat.rows; i++) {
           for (int j = 0; j < mat.cols; j++) {
               double dx = (double) (j - center.x) / center.x;
               double dy = (double) (j - center.y) / center.y;
               double weight = exp((dx * dx + dy * dy) * scale);
               uchar *ptr_mat = &mat.at<uchar>(cvPoint(j * 3, i));
               ptr_mat[0] = static_cast<uchar>(cvRound(ptr_mat[0] * weight));
               ptr_mat[1] = static_cast<uchar>(cvRound(ptr_mat[1] * weight));
               ptr_mat[2] = static_cast<uchar>(cvRound(ptr_mat[2] * weight));
           }
       }
       imwrite("taaarannn_magic_Mat.png", mat);
       namedWindow("taaarannn_magic_Mat", 1);
       imshow("taaarannn_magic_Mat", mat);
       waitKey(0);
   }
   ```

   - 用Mat改写后，结果与上图相同。

     [taaarannn_magic_Mat.png](https://github.com/zhaoxuyan/openCV_Clion/blob/master/cmake-build-debug/taaarannn_magic_Mat.png)

3. 在Ubuntu系统中下载安装opencv2.x/3.x，编译运行任务1~2的代码。

   #### Mac OS中:

   ![](https://ws1.sinaimg.cn/large/006tNc79gy1fqfwu2ytivj31kw0upgw0.jpg)

4. 图文形式记录任务1~3的实验步骤。

   以上。
