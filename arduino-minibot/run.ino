void run_forward(){
  Serial.println("forward");
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW); 
  
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);  
}

void run_backward(){
  Serial.println("backward");
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH); 
  
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void run_stop(){
  Serial.println("stop");
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW); 
  
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void turn_right(){
  Serial.println("right");
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW); 
  
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void turn_left(){
  Serial.println("left");
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH); 
  
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void set_speed(int _speed_left, int _speed_right){
  analogWrite(leftMotorSpeed, _speed_left);
  analogWrite(rightMotorSpeed, _speed_right);
}
