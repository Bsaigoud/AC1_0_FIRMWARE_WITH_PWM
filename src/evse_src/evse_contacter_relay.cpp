#include "evse_contacter_relay.h"

#include "MCP23008.h"

#include "evse_config.h"

#if RELAY_DROP
#define RELAY1_PWM_GPIO_PIN (33)// GPIO for PWM
#define RELAY2_PWM_GPIO_PIN (26)// GPIO for PWM
#define RELAY3_PWM_GPIO_PIN (27)// GPIO for PWM
// #define RELAY_GPIO_PIN 32         // GPIO for relay
// #define ADC_PIN 34                // ADC pin for reading values
// #define RELAY_PWM_FREQUENCY (1000) // 1kHz PWM frequency
#define RELAY_PWM_FREQUENCY (20000) // 20kHz PWM frequency
#define RELAY_PWM_RESOLUTION (8)   // 8-bit resolution (0-255)
#define RELAY1_PWM_CHANNEL (5)       // PWM channel
#define RELAY2_PWM_CHANNEL (9)       // PWM channel
#define RELAY3_PWM_CHANNEL (7)       // PWM channel

// Global Variables

// uint32_t duty = 100; // Initial duty cycle in percentage

bool relay_dropflag = 0;

extern uint32_t timer;
volatile int relay_duty = 100;
#else

#define RELAY1_PWM_GPIO_PIN (33)// GPIO for PWM
#define RELAY2_PWM_GPIO_PIN (26)// GPIO for PWM
#define RELAY3_PWM_GPIO_PIN (27)// GPIO for PWM

#endif

/*******************************************************************************
 *
 * program : evse_gfci.cpp
 * author  : rakesh
 *
 *
 * Description :
 *
 *
 *******************************************************************************/
RELAY evse_relay;
/*
 * @brief: evse_relay_init(void)
 * This function is used to initialtion of the relay.
 */

void RELAY::evse_relay_init(void)
{
  // pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY1_PWM_GPIO_PIN, OUTPUT);
  pinMode(RELAY2_PWM_GPIO_PIN, OUTPUT);
  pinMode(RELAY3_PWM_GPIO_PIN, OUTPUT);
}
/*
*@brief: evse_relay_on


*/


void RELAY::evse_relay_on(void)
{
  // #if RELAY_DROP
  //   ledcWrite(RELAY_PWM_CHANNEL, 1024);
  //   relay_dropflag = 1;
  // #endif
  // relay_dropflag = 1;
  // digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(RELAY1_PWM_GPIO_PIN, HIGH);
  digitalWrite(RELAY2_PWM_GPIO_PIN, HIGH);
  digitalWrite(RELAY3_PWM_GPIO_PIN, HIGH);

  // ptr_evse_relay->SetControlPilotDuty(duty);

  // delay(1000);

  // mcp.digitalWrite(RELAY_DROP_PIN, HIGH); // Turn ON pin 1
   Serial.println("Relay_ON");
}

/*
*@brief: evse_relay_on


*/
void RELAY::evse_relay_off(void)
{
  // #if RELAY_DROP
  //   ledcWrite(RELAY_PWM_CHANNEL, 0);
  //   relay_dropflag = 0;
  //   timer = 0;
  // #endif
  // relay_dropflag = 0;
  // Serial.println("relay off called");
  // digitalWrite(RELAY_PIN, LOW);
  digitalWrite(RELAY1_PWM_GPIO_PIN, LOW);
  digitalWrite(RELAY2_PWM_GPIO_PIN, LOW);
  digitalWrite(RELAY3_PWM_GPIO_PIN, LOW);

  // delay(1000);
  // mcp.digitalWrite(RELAY_DROP_PIN, LOW); // Turn ON pin 1
  //  Serial.println("Relay_OFF");
}

void RELAY::evse_relay_weld_detection_init(void)
{

  pinMode(RELAY_WELD_PIN, INPUT);
}

bool RELAY::evse_relay_weld_detection(void)
{
  return digitalRead(RELAY_WELD_PIN);
}

#if RELAY_DROP

//RELAY 1
void RELAY::evse_relay1_pwm_init(void)
{
  ledcSetup(RELAY1_PWM_CHANNEL, RELAY_PWM_FREQUENCY, RELAY_PWM_RESOLUTION);
  ledcAttachPin(RELAY1_PWM_GPIO_PIN, RELAY1_PWM_CHANNEL);
  // ledcWrite(RELAY_PWM_CHANNEL, 255);
}

void RELAY::evse_relay1_pwm_100(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY1_PWM_CHANNEL, 255);        // set the Duty cycle to 50 out of 255
  // delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 100");
}

void RELAY::evse_relay1_pwm_75(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY1_PWM_CHANNEL, 190);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 75");
}

void RELAY::evse_relay1_pwm_50(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY1_PWM_CHANNEL, 125);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 50");
}

void RELAY::evse_relay1_pwm_25(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY1_PWM_CHANNEL, 63);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 25");
}

void RELAY::evse_relay1_pwm_0(void)
{
  relay_duty = 100;
  timer = 0;
  relay_dropflag = 0;
  ledcWrite(RELAY1_PWM_CHANNEL, 0);
  // delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 0");
}

void RELAY::evse_relay1_pwm_on(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY1_PWM_CHANNEL, 255);
}

void RELAY::evse_relay1_pwm_off(void)
{
  ledcWrite(RELAY1_PWM_CHANNEL, 0);
  relay_dropflag = 0;
}
//RELAY 2
void RELAY::evse_relay2_pwm_init(void)
{
  ledcSetup(RELAY2_PWM_CHANNEL, RELAY_PWM_FREQUENCY, RELAY_PWM_RESOLUTION);
  ledcAttachPin(RELAY2_PWM_GPIO_PIN, RELAY2_PWM_CHANNEL);
  // ledcWrite(RELAY_PWM_CHANNEL, 255);
}

void RELAY::evse_relay2_pwm_100(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY2_PWM_CHANNEL, 255);        // set the Duty cycle to 50 out of 255
  // delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 100");
}

void RELAY::evse_relay2_pwm_75(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY2_PWM_CHANNEL, 190);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 75");
}

void RELAY::evse_relay2_pwm_50(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY2_PWM_CHANNEL, 125);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 50");
}

void RELAY::evse_relay2_pwm_25(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY2_PWM_CHANNEL, 63);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 25");
}

void RELAY::evse_relay2_pwm_0(void)
{
  relay_duty = 100;
  timer = 0;
  relay_dropflag = 0;
  ledcWrite(RELAY2_PWM_CHANNEL, 0);
  // delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 0");
}

void RELAY::evse_relay2_pwm_on(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY2_PWM_CHANNEL, 255);
}

void RELAY::evse_relay2_pwm_off(void)
{
  ledcWrite(RELAY2_PWM_CHANNEL, 0);
  relay_dropflag = 0;
}
//RELAY 3
void RELAY::evse_relay3_pwm_init(void)
{
  ledcSetup(RELAY3_PWM_CHANNEL, RELAY_PWM_FREQUENCY, RELAY_PWM_RESOLUTION);
  ledcAttachPin(RELAY3_PWM_GPIO_PIN, RELAY3_PWM_CHANNEL);
  // ledcWrite(RELAY_PWM_CHANNEL, 255);
}

void RELAY::evse_relay3_pwm_100(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY3_PWM_CHANNEL, 255);        // set the Duty cycle to 50 out of 255
  // delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 100");
}

void RELAY::evse_relay3_pwm_75(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY3_PWM_CHANNEL, 190);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 75");
}

void RELAY::evse_relay3_pwm_50(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY3_PWM_CHANNEL, 125);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 50");
}

void RELAY::evse_relay3_pwm_25(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY3_PWM_CHANNEL, 63);
  delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 25");
}

void RELAY::evse_relay3_pwm_0(void)
{
  relay_duty = 100;
  timer = 0;
  relay_dropflag = 0;
  ledcWrite(RELAY3_PWM_CHANNEL, 0);
  // delay(50);                       // Wait for 15 mS
  Serial.println("RELAY duty: 0");
}

void RELAY::evse_relay3_pwm_on(void)
{
  relay_dropflag = 1;
  ledcWrite(RELAY3_PWM_CHANNEL, 255);
}

void RELAY::evse_relay3_pwm_off(void)
{
  ledcWrite(RELAY3_PWM_CHANNEL, 0);
  relay_dropflag = 0;
}


void RELAY::SetControlPilotDuty(uint32_t duty)
{
  relay_dropflag = 1;
  uint32_t percentage = duty;
  if ((percentage <= 100) && (percentage >= 0))
  {
    // percentage = 100;                              // Clamp to 100%
    int dutyValue = map(percentage, 0, 100, 0, 255); // Map to 8-bit resolution
    // int dutyValue = map(percentage, 0, 100, 0, 1024); // Map to 8-bit resolution
    ledcWrite(RELAY1_PWM_CHANNEL, dutyValue);
    ledcWrite(RELAY2_PWM_CHANNEL, dutyValue);
    ledcWrite(RELAY3_PWM_CHANNEL, dutyValue);
  }
}

#endif