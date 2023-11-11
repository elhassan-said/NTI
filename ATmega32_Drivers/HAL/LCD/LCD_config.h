/*
 * LCD_config.h
 *
 * Created: 11/8/2023 10:14:25 AM
 *  Author: Hassan Said
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_D0_PORT         PORTA_ID
#define LCD_D0_PIN          PIN0
#define LCD_D1_PORT         PORTA_ID
#define LCD_D1_PIN          PIN1
#define LCD_D2_PORT         PORTA_ID
#define LCD_D2_PIN          PIN2
#define LCD_D3_PORT         PORTA_ID
#define LCD_D3_PIN          PIN3

#define LCD_D4_PORT         PORTB_ID
#define LCD_D4_PIN          PIN0
#define LCD_D5_PORT         PORTB_ID
#define LCD_D5_PIN          PIN1
#define LCD_D6_PORT         PORTB_ID
#define LCD_D6_PIN          PIN2
#define LCD_D7_PORT         PORTB_ID
#define LCD_D7_PIN          PIN4

#define LCD_RS_PORT         PORTA_ID
#define LCD_RS_PIN          PIN3
#define LCD_EN_PORT         PORTA_ID
#define LCD_EN_PIN          PIN2

/*
 * LCD_MODE OPTIONS : [ LCD_8_BIT_MODE - LCD_4_BIT_MODE ]
 */
#define LCD_MODE LCD_4_BIT_MODE



#endif /* LCD_CONFIG_H_ */