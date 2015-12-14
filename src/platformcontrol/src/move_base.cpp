#include <ros/ros.h>
#include <moveit/controller_manager/controller_manager.h>
#include <sensor_msgs/JointState.h>
#include <pluginlib/class_list_macros.h>
#include <map>

namespace my_moveit_controller_manager
{

    class MotionControllerHandle : public moveit_controller_manager::MoveItControllerHandle
    {
    public:
        MotionControllerHandle(const std::string &name) : moveit_controller_manager::MoveItControllerHandle(name) {}

        virtual bool sendTrajectory(const moveit_msgs::RobotTrajectory &t)
        {
            // do whatever is needed to actually execute this trajectory
            motorPublish.publish(t.joint_trajectory);
            return true;
        }

        virtual bool cancelExecution()
        {
            // do whatever is needed to cancel execution
            ROS_INFO("Execution should be cancelled");
            return true;
        }

        virtual bool waitForExecution(const ros::Duration &)
        {
            // wait for the current execution to finish
            sleep(3);
            return true;
        }

        virtual moveit_controller_manager::ExecutionStatus getLastExecutionStatus()
        {
            return moveit_controller_manager::ExecutionStatus(moveit_controller_manager::ExecutionStatus::SUCCEEDED);
        }

        ros::NodeHandle node_handle_;
        ros::Publisher motorPublish = node_handle_.advertise<trajectory_msgs::JointTrajectory>("motorcontrol", 1000);

    };


    class MoveItControllerManager : public moveit_controller_manager::MoveItControllerManager
    {
    public:

        MoveItControllerManager() {}

        virtual ~MoveItControllerManager() {}

        virtual moveit_controller_manager::MoveItControllerHandlePtr getControllerHandle(const std::string &name)
        {
            return moveit_controller_manager::MoveItControllerHandlePtr(new MotionControllerHandle(name));
        }

        /*
        * Get the list of controller names.
        */
        virtual void getControllersList(std::vector<std::string> &names)
        {
            names.resize(1);
            names[0] = "base_controller";
        }

        /*
        * This plugin assumes that all controllers are already active -- and if they are not, well, it has no way to deal with it anyways!
        */
        virtual void getActiveControllers(std::vector<std::string> &names)
        {
            getControllersList(names);
        }

        /*
        * Controller must be loaded to be active, see comment above about active controllers...
        */
        virtual void getLoadedControllers(std::vector<std::string> &names)
        {
            getControllersList(names);
        }

        /*
        * Get the list of joints that a controller can control.
        */
        virtual void getControllerJoints(const std::string &name, std::vector<std::string> &joints)
        {
            joints.clear();
            if (name == "base_controller")
            {
                // declare which joints this controller actuates
                joints.push_back("left_drive_wheel_joint");
                joints.push_back("right_drive_wheel_joint");
            }
        }

        /*
        * Controllers are all active and default.
        */
        virtual moveit_controller_manager::MoveItControllerManager::ControllerState getControllerState(const std::string &name)
        {
            moveit_controller_manager::MoveItControllerManager::ControllerState state;
            state.active_ = true;
            state.default_ = true;
            return state;
        }

        /* Cannot switch our controllers */
        virtual bool switchControllers(const std::vector<std::string> &activate, const std::vector<std::string> &deactivate) { return false; }

    protected:

        ros::NodeHandle node_handle_;

        std::map<std::string, moveit_controller_manager::MoveItControllerHandlePtr> controllers_;

    };

} // end namespace my_moveit_controller_manager

PLUGINLIB_EXPORT_CLASS(my_moveit_controller_manager::MoveItControllerManager,
    moveit_controller_manager::MoveItControllerManager);
