#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);  // Stop if no connection
  }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert raw values to g's (approximate)
  float accX = ax / 16384.0;
  float accY = ay / 16384.0;
  float accZ = az / 16384.0;

  // Calculate pitch and roll in degrees (simplified)
  float pitch = atan2(accY, sqrt(accX * accX + accZ * accZ)) * 180 / PI;
  float roll  = atan2(-accX, accZ) * 180 / PI;
  float yaw   = 0.0; // Yaw can't be reliably calculated without a magnetometer

  Serial.print("ArduinoUno-1,");
  Serial.print(pitch); Serial.print(",");
  Serial.print(roll);  Serial.print(",");
  Serial.print(yaw);   Serial.print(",");
  Serial.print(accX);  Serial.print(",");
  Serial.print(accY);  Serial.print(",");
  Serial.println(accZ);

  delay(1000);  // 10 Hz
}