//
//  main.cpp
//  RocketTelemetry
//
//  Created by Matt Ahmad on 2022-11-19.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

int humidity;
int kPA;
int altitude;
int downrangeDistance;
float timeSeconds;
float distanceMeters;
float velocity;
float acceleration;
float jerk;
char type;

void checkHumidityAtLiftOff();
void checkExternalPressureAtLiftOff();
float checkTimeAtLiftOff();
float checkDistanceAtLiftOff();
float checkDownrangeDistanceAtLiftOff();
void checkPositionAtLiftOff();
void checkVelocityAtLiftOff();
void checkAccelerationAtLiftOff();
void checkJerkAtLiftOff();

void checkHumidityAtMaxQ();
void checkExternalPressureAtMaxQ();
float checkTimeAtMaxQ();
float checkDistanceAtMaxQ();
float checkDownrangeDistanceAtMaxQ();
void checkPositionAtMaxQ();
void checkVelocityAtMaxQ();
void checkAccelerationAtMaxQ();
void checkJerkAtMaxQ();

void checkAllSystemsAtLiftOff() {
  checkHumidityAtLiftOff();
  checkExternalPressureAtLiftOff();
  checkPositionAtLiftOff();
  checkVelocityAtLiftOff();
  checkAccelerationAtLiftOff();
  checkJerkAtLiftOff();
  std::cout << "All systems are nominal!\n";
}

void checkAllSystemsAtMaxQ() {
  checkHumidityAtMaxQ();
  checkExternalPressureAtMaxQ();
  checkPositionAtMaxQ();
  checkVelocityAtMaxQ();
  checkAccelerationAtMaxQ();
  checkJerkAtMaxQ();
  std::cout << "All systems are nominal!\n";
}

void checkHumidityAtLiftOff() {
    humidity = 80;
  std::cout << "Relative humidity is: " << humidity << " %\n";
}

void checkHumidityAtMaxQ() {
    humidity = 80;
  std::cout << "Relative humidity is: " << humidity << " %\n";
}

void checkExternalPressureAtLiftOff() {
    kPA = 100;
    std::cout << "External pressure is: " << kPA << " kPA\n";
}

void checkExternalPressureAtMaxQ() {
    kPA = 40;
    std::cout << "External pressure is: " << kPA << " kPA\n";
}

float checkTimeAtLiftOff() {
    return 10;
}

float checkDistanceAtLiftOff() {
    return 103;
}

float checkDownrangeDistanceAtLiftOff() {
    return 50;
}

float checkTimeAtMaxQ() {
    return 72;
}

float checkDistanceAtMaxQ() {
    return 14000;
}

float checkDownrangeDistanceAtMaxQ() {
    return 42600;
}

void checkPositionAtLiftOff() {
    altitude = checkDistanceAtLiftOff();
    downrangeDistance = checkDownrangeDistanceAtLiftOff();
    std::cout << "Altitude is: " << altitude << " meters\n";
    std::cout << "Downrange Distance is: " << downrangeDistance << " meters\n";
}

void checkPositionAtMaxQ() {
    altitude = checkDistanceAtMaxQ();
    downrangeDistance = checkDownrangeDistanceAtMaxQ();
    std::cout << "Altitude is: " << altitude << " meters\n";
    std::cout << "Downrange Distance is: " << downrangeDistance << " meters\n";
}


void checkVelocityAtLiftOff() {
    timeSeconds = checkTimeAtLiftOff();
    distanceMeters = checkDistanceAtLiftOff();
    velocity = std::round(distanceMeters/timeSeconds);
    std::cout << "Velocity is: " << velocity << " m/s\n";
}

void checkVelocityAtMaxQ() {
    timeSeconds = checkTimeAtMaxQ();
    distanceMeters = checkDistanceAtMaxQ();
    velocity = std::round(distanceMeters/timeSeconds);
    std::cout << "Velocity is: " << velocity << " m/s\n";
}

void checkAccelerationAtLiftOff() {
    timeSeconds = checkTimeAtLiftOff();
    distanceMeters = checkDistanceAtLiftOff();
    acceleration = std::round(distanceMeters/std::pow(timeSeconds,2));
    std::cout << "Acceleration is: " << acceleration << " m/s2\n";
}

void checkAccelerationAtMaxQ() {
    timeSeconds = checkDistanceAtMaxQ();
    distanceMeters = checkDistanceAtMaxQ();
    acceleration = std::round(distanceMeters/std::pow(timeSeconds,2));
    std::cout << "Acceleration is: " << acceleration << " m/s2\n";
}

void checkJerkAtLiftOff() {
    timeSeconds = checkDistanceAtLiftOff();
    distanceMeters = checkDistanceAtLiftOff();
    jerk = std::round(distanceMeters/std::pow(timeSeconds,3));
    std::cout << "Jerk is: " << jerk << " m/s3\n";
}

void checkJerkAtMaxQ() {
    timeSeconds = checkDistanceAtMaxQ();
    distanceMeters = checkDistanceAtMaxQ();
    jerk = std::round(distanceMeters/std::pow(timeSeconds,3));
    std::cout << "Jerk is: " << jerk << " m/s3\n";
}

int main(void) {
 

    std::cout << "Ready for take off in 10 seconds\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "10\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "9\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "8\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "7\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "6\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "5\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "4\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "3\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "2\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "1\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Lift off!\n";
    checkAllSystemsAtLiftOff();
    std::cout << "MaxQ is coming up in 72.2 seconds\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(72200));
    std::cout << "Entering MaxQ\n";
    checkAllSystemsAtMaxQ();
    return 0;
}
 
