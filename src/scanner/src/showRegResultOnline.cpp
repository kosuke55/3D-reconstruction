#include <iostream>
#include <string>
#include <sstream>

#include <ros/ros.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/visualization/pcl_visualizer.h>

typedef pcl::PointXYZRGBA PointT;

void viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{

	//设置背景颜色
	viewer.setBackgroundColor (255.0, 255.0, 255.0);
	
	//球体坐标
 //   pcl::PointXYZ o;
 //   o.x = 0;
 //   o.y = 0;
 //   o.z = 0;
	////添加球体
 //   viewer.addSphere (o, 1, "sphere", 0);
 //   std::cout << "i only run once" << std::endl;

}



// ********************
// ******** Cloudviewer
// ********************

int
main (int argc, char **argv)
{
    ros::init (argc, argv, "showRegResultOnline");
    ros::NodeHandle nh;
    std::string filename = "/home/kosuke/catkin_ws/src/scanner/data/result/registerResult.pcd";
    pcl::PointCloud<PointT>::Ptr cloud_ptr (new pcl::PointCloud<PointT>);
    pcl::visualization::CloudViewer viewer("viewer");
    viewer.runOnVisualizationThreadOnce (viewerOneOff);//调用相应函数执行

    ros::Rate loop_rate(0.5);
    loop_rate.sleep();              // sleep two second at the beginning
    ros::Rate loop_rate_runtime(2);

    while (ros::ok())
    {
        // pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr);
        if (pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr) == -1){
          // PCL_ERROR ("Couldn't read PCD file \n");
          continue;
        }
        viewer.showCloud( cloud_ptr );
        loop_rate_runtime.sleep();
    }

    return 0;
}




