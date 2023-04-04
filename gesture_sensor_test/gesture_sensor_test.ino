#include <DFRobot_PAJ7620U2.h>

DFRobot_PAJ7620U2 paj;

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println("Gesture recognition system base on PAJ7620U2");
  while (paj.begin() != 0) {
    Serial.println("initial PAJ7620U2 failure! Please check if all the connections are fine, or if the wire sequence is correct?");
    delay(500);
  }
  Serial.println("PAJ7620U2 init completed, start to test the gesture recognition function");
  paj.setGestureHighRate(true);
}

void loop() {
  DFRobot_PAJ7620U2::eGesture_t gesture = paj.getGesture();
  if (gesture != paj.eGestureNone) {
    String description = paj.gestureDescription(gesture);//Convert gesture number into string description
    Serial.print("gesture code = ");Serial.println(gesture);
    Serial.print("gesture description = ");Serial.println(description);
    Serial.println();
    posljiKretnjo(gesture, description);
  }
}

void posljiKretnjo(int gesture, String description) {
  // Koda da poslje na server skoz WI-FI modul
}