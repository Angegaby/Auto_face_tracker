#include <Stepper.h>

#define STEPS 2048  // 28BYJ-48 steps/rev
Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(12);  // RPM; adjust to taste
}

void loop() {
  static String buffer = "";
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      String cmd = buffer; buffer = "";
      cmd.trim();
      if (cmd.length() == 0) continue;
      // Expect commands like: L120 or R80 (case-insensitive)
      char dir = toupper(cmd.charAt(0));
      long steps = 0;
      if (cmd.length() > 1) {
        steps = cmd.substring(1).toInt();
      }
      if (steps <= 0) steps = 50; // default nudge if missing/invalid

      if (dir == 'L') {
        stepper.step(steps);
        Serial.println("OK");
      } else if (dir == 'R') {
        stepper.step(-steps);
        Serial.println("OK");
      } else {
        Serial.print("ERR:UnknownCmd ");
        Serial.println(cmd);
      }
    } else {
      if (buffer.length() < 64) buffer += c; else buffer = "";
    }
  }
}