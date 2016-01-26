// #include <ros/ros.h>
// #include <fedar_msgs/Job.h>
// #include <std_msgs/Bool.h>
//
// class JobQueue {
// private:
//     std::vector<fedar_msgs::Job> jobs;
// public:
//     JobQueue () {}
//     virtual ~JobQueue ();
//
//     bool addJobToQueue(fedar_msgs::Job job, std_msgs::Bool resp) {
//         jobs.push_back(job);
//         resp.data = true;
//         return true;
//     }
//
//     fedar_msgs::Job getNextJob() {
//         if (jobs.size() > 1) {
//             jobs.erase(jobs.begin());
//             fedar_msgs::Job next = jobs.front();
//             return next;
//         }
//         else {
//             rate.sleep();
//             return getNextJob();
//         }
//     }
//
// };
//
//
// int main(int argc, char *argv[]) {
//     ros::init(argc, argv, "jobqueue");
//     ros::NodeHandle nh;
//
//     ros::Subscriber sub;
//     ros::Rate rate(30);
//
//     JobQueue queue;
//
//     // sub = nh.subscribe("ar_pose_marker", 10, &receivePoseMarker);
//     ros::ServiceServer jobadder = nh.advertiseService("add_job_to_queue", &JobQueue::addJobToQueue, &queue);
//
//     ros::spin();
//
//     return 0;
// }
