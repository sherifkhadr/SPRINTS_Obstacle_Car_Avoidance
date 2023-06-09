/*
* TIMER_Interface.h
*
*     Created on: Apr 11, 2023
*         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
*    Description: This file contains all Timers (TIMER) functions' prototypes and definitions (Macros) to avoid magic numbers.
*		MCU Datasheet: AVR ATmega32
*                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
*/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/* ****************************************************************/
/* TIMER Includes */

/* STD LIB */
#include <math.h>

/* Common */
#include "../../COMMON/BIT_Math.h"
#include "../../COMMON/STD_Types.h"
#include "../../COMMON/vect_table.h"
/* ****************************************************************/
/* TIMER Macros */

#define F_CPU								1000000UL
/* The 3 Timers counted from 0 to 2 */
#define TIMER_U8_TIMER0                            0
#define TIMER_U8_TIMER1                        1
#define TIMER_U8_TIMER2                        2

/* The 3 Timers Channels counted from 0 to 2 */
#define TIMER_U8_NO_CHANNEL                    0
#define TIMER_U8_TIMER_1_CHANNEL_A                1
#define TIMER_U8_TIMER_1_CHANNEL_B                2

/* The 3 Timers Interrupts counted from 0 to 2 */
#define TIMER_U8_CAPT_INTERRUPT                0
#define TIMER_U8_COMP_INTERRUPT                1
#define TIMER_U8_OVF_INTERRUPT                2

/* The 3 Timers Compare Match Output Modes counted from 0 to 2 */
#define TIMER_U8_TOG_OCR_PIN                    0
#define TIMER_U8_CLR_OCR_PIN                    1
#define TIMER_U8_SET_OCR_PIN                    2

/* ****************************************************************/

typedef enum {
	INTERRUPT,
	POLLING
}EN_TIMER_mode_T;

#define FACTOR								4
#define OC0_PIN_DIR                         DDRB
#define OC0_PIN                              3
#define GLOBAL_INTERRUPT_ENABLE_BIT			 7
/* timer 0 macros */
#define MAX_TIMER_DELAY                     (MAX_DELAY * 65535)
#define MAX_DELAY                         (0.262144f) // in sec
#define MAX_COUNTS                           256
#define TICK_TIME                         (0.001024f) // in sec


#define MAX_TIMER_DELAY_8_PRESCALLER     (MAX_DELAY_8_PRESCALLER * 65535)
#define MAX_DELAY_8_PRESCALLER             (0.000256f) // in sec
#define TICK_TIME_8_PRESCALLER            (0.000001f) // in sec
#define SECOND_OPERATOR                     (1000.0f)
#define MICRO_SECOND_OPERATOR				(1000000.0f)

#define NO_PRESCALER                        1
/* ****************************************************************/
/*error definitions*/
typedef enum {
	TIMER_OK, TIMER_ERROR
} EN_TIMER_ERROR_T;

typedef enum {
	ENABLED, DISABLED
} EN_TIMER_INTERRPUT_T;
/* **********************************************************************/
/*  TIMER Functions' prototypes                                         */
/* **********************************************************************/

/**
* @brief Initializes timer0 at normal mode
*
* This function initializes/selects the timer_0 normal mode for the timer, and enable the ISR for this timer.
* @param[in] EN_TIMER_INTERRPUT_T en_a_interrputEnable value to set the interrupt bit for timer_0 in the TIMSK reg.
* @param[in] **u8_a_shutdownFlag double pointer, acts as a main switch for timer 0 operations.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
EN_TIMER_ERROR_T TIMER_timer0NormalModeInit(EN_TIMER_INTERRPUT_T en_a_interrputEnable);

/**
* @brief Creates a delay using timer_0 in overflow mode
*
* This function Creates the desired delay on timer_0 normal mode.
* @param[in] Uint16_t u16_a_interval value to set the desired delay.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
EN_TIMER_ERROR_T TIMER_delay_ms(Uint16_t u16_a_interval);

/**
* @brief Start the timer by setting the desired prescaler.
*
* This function set the prescaler for timer_0.
* @param[in] Uint16_t u16_a_prescaler value to set the desired prescaler.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
EN_TIMER_ERROR_T TIMER_timer0Start(Uint16_t u16_a_prescaler);

/**
* @brief Stop the timer by setting the prescaler to be 000--> timer is stopped.
*
* This function Clear the prescaler for timer_0.
* @param[in] void.
*
* @return void
*/
void TIMER_timer0Stop(void);

/* ****************************************************************/
/**
* @brief timer compare match mode.
*
* This function set the compare value for timer_0.
* @param[in] Uchar8_t u8_a_outCompValue value at which the matching will occur.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
//EN_TIMER_ERROR_T TIMER_timer0CleareCompMatInit(Uchar8_t u8_a_outCompValue );




/**
* @brief Initializes timer2 at normal mode
*
* This function initializes/selects the timer_2 normal mode for the timer, and enable the ISR for this timer.
* @param[in] EN_TIMER_INTERRPUT_T en_a_interrputEnable value to set the interrupt bit for timer_2 in the TIMSK reg.
* @param[in] **u8_a_shutdownFlag double pointer, acts as a main switch for timer 2 operations.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
EN_TIMER_ERROR_T TIMER_TMR2NormalModeInit(EN_TIMER_INTERRPUT_T en_a_interrputEnable);

/**
* @brief Stop the timer by setting the prescaler to be 000--> timer is stopped.
*
* This function Clear the prescaler for timer_2.
* @param[in] void.
*
* @return void
*/
void TIMER_timer2Stop(void);

/**
* @brief Start the timer by setting the desired prescaler.
*
* This function set the prescaler for timer_2.
* @param[in] Uint16_t u16_a_prescaler value to set the desired prescaler.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
EN_TIMER_ERROR_T TIMER_TMR2Start(Uint16_t u16_a_prescaler);

/**
* @brief Creates a delay using timer_2 in overflow mode
*
* This function Creates the desired delay on timer_2 normal mode.
* @param[in] Uint16_t u16_a_interval value to set the desired delay.
*
* @return An EN_TIMER_ERROR_T value indicating the success or failure of the operation
*         (TIMER_OK if the operation succeeded, TIMER_ERROR otherwise)
*/
EN_TIMER_ERROR_T TMR_delay_us(Uint16_t u16_a_interval);

EN_TIMER_ERROR_T TMR_intDelay_ms(Uint16_t u16_a_interval);

/**
* @brief Set callback function for timer overflow interrupt
*
* @param void_a_pfOvfInterruptAction Pointer to the function to be called on timer overflow interrupt
* @return EN_TIMER_ERROR_T Returns TIMER_OK if callback function is set successfully, else returns TIMER_ERROR
*/
EN_TIMER_ERROR_T TMR_ovfSetCallback(void (*void_a_pfOvfInterruptAction)(void));

/* ***********************************************************************************************/

#endif /* TIMER_INTERFACE_H_ */