#!/usr/bin/python
import roslib
import rospy
from sound_play.libsoundplay import SoundClient
from userInterface.srv       import sayTTS
from userInterface.srv       import sayTTSRequest
from userInterface.srv       import sayTTSResponse

def handle(req):
    sound_client = SoundClient()
    sound_client.say(req.words)
    return sayTTSResponse()

def sound_server():
    rospy.init_node('sound')
    sound_client = SoundClient()

    s = rospy.Service('sayTTS', sayTTS, handle)
    rospy.spin()

if __name__ == "__main__":
    sound_server()
