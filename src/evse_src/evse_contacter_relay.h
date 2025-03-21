#ifndef _EVSE_CONTACTER_RELAY_H
#define _EVSE_CONTACTER_RELAY_H
#include <Arduino.h>
#include "evse_config.h"

#if AC1_0_EVRE

#define RELAY_PIN (33) // ac1_0evre

#else

#define RELAY_PIN (18)
#endif

#define RELAY_WELD_PIN (25)

class RELAY
{
public:
    void evse_relay_init(void);
    void evse_relay_on(void);
    void evse_relay_off(void);
    void evse_relay_weld_detection_init(void);
    bool evse_relay_weld_detection(void);
    //RELAY 1
    void evse_relay1_pwm_init(void);
    void evse_relay1_pwm_100(void);
    void evse_relay1_pwm_75(void);
    void evse_relay1_pwm_50(void);
    void evse_relay1_pwm_25(void);
    void evse_relay1_pwm_0(void);
    void evse_relay1_pwm_on(void);
    void evse_relay1_pwm_off(void);
    //RELAY 2
    void evse_relay2_pwm_init(void);
    void evse_relay2_pwm_100(void);
    void evse_relay2_pwm_75(void);
    void evse_relay2_pwm_50(void);
    void evse_relay2_pwm_25(void);
    void evse_relay2_pwm_0(void);
    void evse_relay2_pwm_on(void);
    void evse_relay2_pwm_off(void);

    //RELAY 3

    void evse_relay3_pwm_init(void);
    void evse_relay3_pwm_100(void);
    void evse_relay3_pwm_75(void);
    void evse_relay3_pwm_50(void);
    void evse_relay3_pwm_25(void);
    void evse_relay3_pwm_0(void);
    void evse_relay3_pwm_on(void);
    void evse_relay3_pwm_off(void);




    void SetControlPilotDuty(uint32_t);
};

#endif