
#include <Arduino.h>

// =============================================
// MOTOR 2 MANUAL CPR TEST
// ESP32 - Existing wiring
// =============================================

const int ENC2_A = 34;
const int ENC2_B = 35;

const float CURRENT_CPR = 2475.0;

volatile int32_t encoderCount = 0;
volatile uint8_t previousState = 0;

portMUX_TYPE encoderMux = portMUX_INITIALIZER_UNLOCKED;

const int8_t encoderTable[16] = {
   0, -1,  1,  0,
   1,  0,  0, -1,
  -1,  0,  0,  1,
   0,  1, -1,  0
};

// =============================================
// ENCODER INTERRUPT
// =============================================

void IRAM_ATTR encoderISR() {

  portENTER_CRITICAL_ISR(&encoderMux);

  uint8_t currentState =
    (digitalRead(ENC2_A) << 1) |
    digitalRead(ENC2_B);

  uint8_t index =
    (previousState << 2) | currentState;

  encoderCount += encoderTable[index];

  previousState = currentState;

  portEXIT_CRITICAL_ISR(&encoderMux);
}

// =============================================
// SETUP
// =============================================

void setup() {

  Serial.begin(115200);

  pinMode(ENC2_A, INPUT);
  pinMode(ENC2_B, INPUT);

  previousState =
    (digitalRead(ENC2_A) << 1) |
    digitalRead(ENC2_B);

  attachInterrupt(
    digitalPinToInterrupt(ENC2_A),
    encoderISR,
    CHANGE
  );

  attachInterrupt(
    digitalPinToInterrupt(ENC2_B),
    encoderISR,
    CHANGE
  );

  Serial.println();
  Serial.println("================================");
  Serial.println(" MOTOR 2 MANUAL CPR TEST");
  Serial.println("================================");

  Serial.print("Current assumed CPR: ");
  Serial.println(CURRENT_CPR);

  Serial.println();
  Serial.println("1. Mark the wheel at a reference point.");
  Serial.println("2. Send S to reset the encoder count.");
  Serial.println("3. Rotate the wheel manually.");
  Serial.println("4. Complete 20 full revolutions.");
  Serial.println("5. Send E to calculate CPR.");
}

// =============================================
// MAIN LOOP
// =============================================

void loop() {

  if (Serial.available()) {

    char command = Serial.read();

    if (command == 'S' || command == 's') {

      portENTER_CRITICAL(&encoderMux);

      encoderCount = 0;

      previousState =
        (digitalRead(ENC2_A) << 1) |
        digitalRead(ENC2_B);

      portEXIT_CRITICAL(&encoderMux);

      Serial.println();
      Serial.println("COUNT RESET. START ROTATING THE WHEEL.");
    }

    else if (command == 'E' || command == 'e') {

      int32_t finalCount;

      portENTER_CRITICAL(&encoderMux);

      finalCount = encoderCount;

      portEXIT_CRITICAL(&encoderMux);

      Serial.println();
      Serial.println("Enter the number of complete revolutions:");

      while (!Serial.available()) {
        delay(10);
      }

      int revolutions = Serial.parseInt();

      if (revolutions > 0) {

        float measuredCPR =
          abs(finalCount) / (float)revolutions;

        Serial.println();
        Serial.println("========== RESULTS ==========");

        Serial.print("Total encoder counts: ");
        Serial.println(finalCount);

        Serial.print("Wheel revolutions: ");
        Serial.println(revolutions);

        Serial.print("Measured CPR: ");
        Serial.println(measuredCPR, 2);

        Serial.print("Current CPR: ");
        Serial.println(CURRENT_CPR, 2);

        Serial.print("Difference: ");

        Serial.print(
          ((measuredCPR - CURRENT_CPR) /
           CURRENT_CPR) * 100.0,
          2
        );

        Serial.println("%");

        Serial.println("=============================");
        Serial.println("Send S to perform another test.");
      }
      else {
        Serial.println("Invalid revolution count.");
      }
    }
  }
}
