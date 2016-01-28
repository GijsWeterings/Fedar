#include <ros/ros.h>
#include <fedar_msgs/Job.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Bool.h>
#include <jobqueue/addJobToQueue.h>
#include <jobqueue/getAllJobs.h>
#include <jobqueue/task.h>
#include <jobqueue/nextjob.h>


std::vector<std::vector<int> > jobs;

std::vector<int> getNextJob() {
    if (jobs.size() > 1) {
        jobs.erase(jobs.begin());
        std::vector<int> next = jobs.front();
        return next;
    }
    else {
        usleep(15000);
        return getNextJob();
    }
}

bool addJobToQueue(jobqueue::addJobToQueue::Request  &req, jobqueue::addJobToQueue::Response &res) {
    ROS_INFO("Adding job");
    std::vector<int> j = req.job;
    jobs.push_back(j);
    res.success = true;
    return true;
}

bool getAllJobs(jobqueue::getAllJobs::Request  &req, jobqueue::getAllJobs::Response &res) {
    std::vector<jobqueue::task > tasks;
    for(int i = 0; i < jobs.size(); i++) {
        jobqueue::task t;
        t.ingredients = jobs[i];
        tasks.push_back(t);
    }

    res.items = tasks;
    return true;
}

bool nextjob(jobqueue::nextjob::Request  &req, jobqueue::nextjob::Response &res) {
    res.job = getNextJob();
    return true;
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "jobqueue");
    ros::NodeHandle nh;

    ros::Subscriber sub;
    ros::Rate rate(1);
    ROS_INFO("Hello!");


    // sub = nh.subscribe("ar_pose_marker", 10, &receivePoseMarker);
    ros::ServiceServer jobadder = nh.advertiseService("addJobToQueue", &addJobToQueue);
    ros::ServiceServer alljobs = nh.advertiseService("getAllJobs", &getAllJobs);
    ros::ServiceServer nextjb = nh.advertiseService("nextjob", &nextjob);

    ros::spin();

    return 0;
}
