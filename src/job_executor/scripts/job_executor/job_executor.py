#!/usr/bin/env python
import roslib
import rospy
import smach
# import smach_ros

from armcontrol.srv      import armInitializeMotors
from armcontrol.srv      import armPosition
from platedetector.srv   import assertNoPlate
from platedetector.srv   import assertPlate
from platformcontrol.srv import findLeftBoundary
from platformcontrol.srv import findRightBoundary
from platformcontrol.srv import platformHome
from platformcontrol.srv import platformInitializeMotors
from platformcontrol.srv import platformPosition
from userInterface.srv   import sayTTS
from wristcontrol.srv    import scoopPosition
from wristcontrol.srv    import wristInitializeMotors



class Statehelper():
    @staticmethod
    def callService(serviceName, service, arguments):
        rospy.wait_for_service(serviceName)
        try:
            srv = rospy.ServiceProxy(serviceName, service)
            resp = srv(*arguments)
            if not resp:
                rospy.logerror("State machine failed call to  " + serviceName)
                sys.exit(1)
        except rospy.ServiceException, e:
            rospy.logerror("State machine failed call to  " + serviceName)
            sys.exit(1)

# Initialize motors in platformcontrol, armcontrol and wristcontrol.
# Performs EXTERNAL_INIT using Hall sensors in arm and wrist
class MotorInitialization(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['motorsInitialized'])

    def execute(self, userdata):
        rospy.loginfo('Initializing motors')
        Statehelper.callService("platformInitializeMotors", platformInitializeMotors(), [])
        Statehelper.callService("armInitializeMotors", armInitializeMotors(), [])
        Statehelper.callService("wristInitializeMotors", wristInitializeMotors(), [])
        return 'motorsInitialized'

# Drives base to the left edge of the working area.
# Set position MIN
class EdgeDetectLeft(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['workspaceLeftEdgeSet'])

    def execute(self, userdata):
        rospy.loginfo('Finding Left edge of working area')
        Statehelper.callService("findLeftBoundary", findLeftBoundary(), [])
        return 'workspaceLeftEdgeSet'

# Drives base to the right edge of the working area.
# Set position MAX
class EdgeDetectRight(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['workspaceRightEdgeSet'])

    def execute(self, userdata):
        rospy.loginfo('Finding Right edge of working area')
        Statehelper.callService("findRightBoundary", findRightBoundary(), [])
        return 'workspaceRightEdgeSet'

# Polls Jobqueue node for a new job.
# This state can take a while, as it is dependent on customers
# If we send a shutdown command here, go to the shutdown subroutine
class WaitForNextJob(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['jobAquired', 'shutdown'])

    def execute(self, userdata):
        rospy.loginfo('Waiting for next job')
        if True:
            return 'shutdown'
        else:
            return 'jobAquired'

# Checks current job.
# If we have no ingredients left, signal the customer he can retrieve its plate.
class CheckJobStatus(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['jobUnfinished','jobDone'])

    def execute(self, userdata):
        rospy.loginfo('Checking if job is finished')
        if False:
            return 'jobDone'
        else:
            userdata.currIngredient = 1 #FIXME
            return 'jobUnfinished'

# Tell customer he can retrieve his plate, and wait for them to do so.
class WaitForCustomerCompletion(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['plateRetrieved'])

    def execute(self, userdata):
        rospy.loginfo('Job done! Waiting for pickup')
        Statehelper.callService("sayTTS", sayTTS(), ["I am done with this task, you may take the plate. Enjoy your meal!"])
        Statehelper.callService("assertNoPlate", assertNoPlate(), [])
        return 'plateRetrieved'

# Move base to the next ingredient location
class MovingToIngredient(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['arrivedAtIngredient'])

    def execute(self, userdata):
        rospy.loginfo('Moving to next ingredient')
        Statehelper.callService("platformPosition", platformPosition(), [userdata.currIngredient])
        return 'arrivedAtIngredient'

# Open the scoop and move the arm to grasping state
class PreIngredientGrasp(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['readyForGrasp'])

    def execute(self, userdata):
        rospy.loginfo('Positioning arm for ingredient pickup')
        Statehelper.callService("scoopPosition", scoopPosition(), ["open"])
        Statehelper.callService("armPosition", armPosition(), ["extend", userdata.currIngredient])

        return 'readyForGrasp'

# Close the scoop
class IngredientGrasp(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['graspedIngredient'])

    def execute(self, userdata):
        rospy.loginfo('Grasping ' + userdata.currIngredient)
        Statehelper.callService("scoopPosition", scoopPosition, ["close"])
        return 'graspedIngredient'

# Move arm to resting position
class PostIngredientGrasp(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['graspComplete'])

    def execute(self, userdata):
        rospy.loginfo('Moving arm to holding position')
        Statehelper.callService("armPosition", armPosition(), ["retract"]) #FIXME do different # of args matter?
        return 'graspComplete'

# Move platform to plate location
class MovingToDeposit(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['atDeposit'])

    def execute(self, userdata):
        rospy.loginfo('Moving to deposit location')
        Statehelper.callService("platformPosition", platformPosition(), [userdata.currIngredient])
        return 'atDeposit'

# Ensures plate is present
class SafetyDepositCheck(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['allSafe'])

    def execute(self, userdata):
        rospy.loginfo('Let\'s see, do we have a plate?')
        Statehelper.callService("assertPlate", assertPlate(), [])
        return 'allSafe'

# Position arm above plate
class PreDepositGrasp(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['armExtended'])

    def execute(self, userdata):
        rospy.loginfo('Extending arm above plate')
        Statehelper.callService("armPosition", armPosition(), ["extend", userdata.currIngredient])
        return 'armExtended'

# Open the scoop
class DepositGrasp(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['depositedIngredient'])

    def execute(self, userdata):
        rospy.loginfo('Depositing ingredient in scoop on plate')
        Statehelper.callService("scoopPosition", scoopPosition, ["open"])
        return 'depositedIngredient'

# Move arm to resting position and close scoop
class PostDepositGrasp(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['restState'])

    def execute(self, userdata):
        rospy.loginfo('Returning arm to resting state')
        Statehelper.callService("armPosition", armPosition(), ["retract", userdata.currIngredient])
        Statehelper.callService("scoopPosition", scoopPosition(), ["close"])
        return 'restState'

# Arm to resting position, close scoop and drive to left edge of working area.
class PerformingShutDown(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['shutdown'])

    def execute(self, userdata):
        rospy.loginfo('Shutting down. Please plug me in after sequence')
        Statehelper.callService("armPosition", armPosition(), ["retract", userdata.currIngredient])
        Statehelper.callService("scoopPosition", scoopPosition(), ["close"])
        Statehelper.callService("platformHome", platformHome(), [])
        return 'shutdown'

# main
def main():
    rospy.init_node('job_executor')

    # Create a SMACH state machine
    sm = smach.StateMachine(outcomes=['shutdown'])

    # Open the container
    with sm:
        smach.StateMachine.add('MotorInitialization', MotorInitialization(),
        transitions={
            'motorsInitialized':'EdgeDetectLeft'
        })
        smach.StateMachine.add('EdgeDetectLeft', EdgeDetectLeft(),
        transitions={
            'workspaceLeftEdgeSet':'EdgeDetectRight'
        })
        smach.StateMachine.add('EdgeDetectRight', EdgeDetectRight(),
        transitions={
            'workspaceRightEdgeSet':'WaitForNextJob'
        })
        smach.StateMachine.add('WaitForNextJob', WaitForNextJob(),
        transitions={
            'jobAquired':'CheckJobStatus',
            'shutdown':'PerformingShutDown'
        })
        smach.StateMachine.add('CheckJobStatus', CheckJobStatus(),
        transitions={
            'jobDone':'WaitForCustomerCompletion',
            'jobUnfinished':'MovingToIngredient'
        })
        smach.StateMachine.add('WaitForCustomerCompletion', WaitForCustomerCompletion(),
        transitions={
            'plateRetrieved':'WaitForNextJob'
        })
        smach.StateMachine.add('MovingToIngredient', MovingToIngredient(),
        transitions={
            'arrivedAtIngredient':'PreIngredientGrasp'
        })
        smach.StateMachine.add('PreIngredientGrasp', PreIngredientGrasp(),
        transitions={
            'readyForGrasp':'IngredientGrasp'
        })
        smach.StateMachine.add('IngredientGrasp', IngredientGrasp(),
        transitions={
            'graspedIngredient':'PostIngredientGrasp'
        })
        smach.StateMachine.add('PostIngredientGrasp', PostIngredientGrasp(),
        transitions={
            'graspComplete':'MovingToDeposit'
        })
        smach.StateMachine.add('MovingToDeposit', MovingToDeposit(),
        transitions={
            'atDeposit':'SafetyDepositCheck'
        })
        smach.StateMachine.add('SafetyDepositCheck', SafetyDepositCheck(),
        transitions={
            'allSafe':'PreDepositGrasp'
        })
        smach.StateMachine.add('PreDepositGrasp', PreDepositGrasp(),
        transitions={
            'armExtended':'DepositGrasp'
        })
        smach.StateMachine.add('DepositGrasp', DepositGrasp(),
        transitions={
            'depositedIngredient':'PostDepositGrasp'
        })
        smach.StateMachine.add('PostDepositGrasp', PostDepositGrasp(),
        transitions={
            'restState':'CheckJobStatus'
        })
        smach.StateMachine.add('PerformingShutDown', PerformingShutDown(),
        transitions={
            'shutdown':'shutdown'
        })

    # sis = smach_ros.IntrospectionServer('job_executor', sm, '/SM_ROOT')
    # sis.start()

    # Execute SMACH plan
    outcome = sm.execute()

    rospy.spin()
    # sis.stop()

if __name__ == '__main__':
    main()
