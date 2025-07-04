# line-follower
simple example of code for a line-following robot using Arduino. This code assumes the robot has two motors controlled by an H-bridge or motor driver.
// Define motor pins
#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3
#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5

// Define sensor pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Define motor speeds
#define MAX_SPEED 255
#define BASE_SPEED 150
#define TURN_SPEED 100

void setup() {
  // Set motor pins as output
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
}

void loop() {
  int leftSensorValue = analogRead(LEFT_SENSOR);
  int rightSensorValue = analogRead(RIGHT_SENSOR);

  // Adjust motor speeds based on sensor readings
  if (leftSensorValue < 500 && rightSensorValue < 500) { // Both sensors detect the line
    // Move forward at maximum speed
    moveForward(MAX_SPEED);
  } else if (leftSensorValue < 500 && rightSensorValue >= 500) { // Only left sensor detects the line
    // Turn right
    turnRight();
  } else if (leftSensorValue >= 500 && rightSensorValue < 500) { // Only right sensor detects the line
    // Turn left
    turnLeft();
  } else { // Both sensors do not detect the line
    // Stop
    stopMoving();
  }
}

void moveForward(int speed) {
  analogWrite(MOTOR1_PIN1, speed);
  analogWrite(MOTOR1_PIN2, 0);
  analogWrite(MOTOR2_PIN1, speed);
  analogWrite(MOTOR2_PIN2, 0);
}

void turnRight() {
  analogWrite(MOTOR1_PIN1, TURN_SPEED);
  analogWrite(MOTOR1_PIN2, 0);
  analogWrite(MOTOR2_PIN1, 0);
  analogWrite(MOTOR2_PIN2, BASE_SPEED);
}

void turnLeft() {
  analogWrite(MOTOR1_PIN1, 0);
  analogWrite(MOTOR1_PIN2, BASE_SPEED);
  analogWrite(MOTOR2_PIN1, TURN_SPEED);
  analogWrite(MOTOR2_PIN2, 0);
}

void stopMoving() {
  analogWrite(MOTOR1_PIN1, 0);
  analogWrite(MOTOR1_PIN2, 0);
  analogWrite(MOTOR2_PIN1, 0);
  analogWrite(MOTOR2_PIN2, 0);
}


