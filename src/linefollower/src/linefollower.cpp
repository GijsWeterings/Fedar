//#include <ros.h>
//#include <std_msgs/float_msg.h>
#include <iostream>
#include <vector>

int calcError(std::vector< int > arr) {

    return 0;
}

////Call Back getting IR 'pinArray'
//void getIrValue(const std_msgs::Float32MultiArray& float_msg){
//  float[] data = float_msg->data;
//
// }
//    ros::Subscriber<std_msgs::Float32MultiArray> sub("pinArray", &getIrValue);

// TEST VALUES
//
//
int main(){

int pinArray [16] = {300, 400, 20, 100, 50, 30, 700, 800, 300, 400, 20, 100, 50, 30, 700, 800};
std::vector< int > bwArr;
std::cout << "Left or Right? L/R";
std::string direction;
std::cin >> direction; // direction given by user

int _Kp, _Ki, _Kd, _dt; // PID values
std::cout << "Kp = ";
std::cin >> _Kp;
std::cout << "Ki = ";
std::cin >> _Ki;
std::cout << "Kd = ";
std::cin >> _Kd;
std::cout << "dt = ";
std::cin >> _dt;

// array splitting front and back
// 0 is leftmost sensor, 7 = rightmost sensor

if ( direction == "R" ){
    for (int i = 0; i < 8; i++) // front sensors 0-7
    {
        int value = pinArray[i];
        if (value <= 150) //black surface  // FIX VALUE BELOW
          value = 0;
        else
          value = 1; // white surface
        bwArr.push_back(value);
    }
    std::cout << "Forward R";
}
else { // direction L
    for (int i = 8; i < 16; i++) // back sensors, 8-15
    {
        int value = pinArray[i];
        if (value <= 150) //black surface
          value = 0;
        else
          value = 1; // white surface
       bwArr.push_back(value);
    }
    std::cout << "Backwards L";
}

// all black surface
if (pinArray[0] > 600 && pinArray[1] > 600 && pinArray[2] > 600 && pinArray[3] > 600 &&pinArray[4] > 600 && pinArray[5] > 600 && pinArray[6] > 600 && pinArray[7] > 600)
{
  std::cout << "Place me on a line";
 // motors stop and user is needed?
}


// error calculation
int error;

error = _preverror;  // prev error is now old value
error = 0;           // reset for new error


 //switch(bwArr){
   if( bwArr == [1, 0, 0, 0, 0, 0, 0, 0]) // <<<
    error = 7;
    break;
   else if ( bwArr == {1, 1, 0, 0, 0, 0, 0, 0})
    error = 6;
    break;
    else if ( bwArr == {1, 1, 1, 0, 0, 0, 0, 0})
    error = 5;
    break;
    ( bwArr == {1, 1, 1, 1, 0, 0, 0, 0})
    error = 4;
    break;
   else if ( bwArr == {0, 1, 1, 1, 0, 0, 0, 0})
    error = 3;
    break;
   else if ( bwArr == {0, 1, 1, 1, 1, 0, 0, 0})
    error = 2;
    break;
   else if ( bwArr == {0, 0, 1, 1, 1, 0, 0, 0})
    error = 1;
    break;
   else if ( bwArr == {0, 0, 1, 1, 1, 1, 0, 0}) // ideal else if
    error = 0;
    break;
   else if ( bwArr == {0, 0, 0, 1, 1, 1, 0, 0})
    error = -1;
    break;
   else if ( bwArr == {0, 0, 0, 1, 1, 1, 1, 0})
   error = -2;
   break;
   else if ( bwArr == {0, 0, 0, 0, 1, 1, 1, 0})
    error = -3;
    break;
   else if ( bwArr == {0, 0, 0, 0, 1, 1, 1, 1})
    error = -4;
    break;
   else if ( bwArr == {0, 0, 0, 0, 0, 1, 1, 1})
    error = -5;
    break;
   else if ( bwArr == {0, 0, 0, 0, 0, 0, 1, 1})
    error = -6;
    break;
   else if ( bwArr == {0, 0, 0, 0, 0, 0, 0, 1}) // >>>>
    error = -7;
    break;
   else if ( bwArr == {0, 0, 0, 0, 0, 0, 0, 0})
    if (_preverror = 7){
        error = 8;
        break;
    }
    else {
        error = -8;
        break;
    }
   else // in Default sensor are probably tripping, just let it drive forwards untill next measurement.
    error = 0;
    break;
 }


////PID VARIABLES
//_Kp = 1;
//_Ki = 1;
//_Kd = 1;
//_dt = 1;

// Calculate error

//    double _error = error;

    // Proportional term
    double Pout = _Kp * error;

    // Integral term
    _integral += error * _dt;
    double Iout = _Ki * _integral;

    // Derivative term
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout; // negative if error = -


int motor_L, motor_R;
if (direction == "R") {
    motor_L = -output;
    motor_R = output;
}
else {
    motor_L = output;
    motor_R = -output;
}

std::cout << "Motor values:";
std::cout << motor_L;
std::cout << motor_R;

}
