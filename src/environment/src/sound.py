#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from sound_play.msg import SoundRequest
from sound_play.libsoundplay import SoundClient

def playSound(data):
    soundhandle.say(data.data)

def listen():
    rospy.init_node('environment', anonymous=False)

    rospy.Subscriber("someEvent", String, playSound)

    soundhandle = SoundClient()


    rospy.spin()

if __name__ == '__main__':
    listen()
