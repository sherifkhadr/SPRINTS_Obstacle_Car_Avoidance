/*
 * car_operations.c
 *
 * Created: 16/05/2023 22:27:10
 *  Author: 20101
 */ 

#include "car_operations.h"

<<<<<<< HEAD
EN_speed en_g_speed = SPEED_0;
EN_Rotation en_g_rotation = ROTATION_R;
EN_direction en_g_direction = DIRECTION_F;
EN_carState en_g_state = STATE_IDLE;
extern Uchar8_t u8_g_timeOut;
Uchar8_t u8_g_timeOutFlag = 0 , u8_g_rotationFlag = 0;
EN_PUSH_BTN_state_t en_g_rotationBtnState = PUSH_BTN_STATE_PRESSED;
float64_t f64_g_obstcaleDistance = 0;

Uchar8_t u8_g_moreThan70Flag = 0;
Uchar8_t u8_g_lessThan20Flag = 0;
=======
EN_speed speed = SPEED_0;
EN_Rotation rotation = ROTATION_R;
EN_direction direction = DIRECTION_F;
EN_carState state = STATE_IDLE;
extern u8 u8_g_timeOut;
EN_PUSH_BTN_state_t rotationBtnState = PUSH_BTN_STATE_PRESSED;
float64_t obstcaleDistance = 0;

Uchar8_t moreThan70Flag = 0;
Uchar8_t lessThan20Flag = 0;
Uchar8_t moreThan30Flag = 0;
Uchar8_t u8_g_rot360Flag= 0;
>>>>>>> 63217c544e9b093926dfac603afa83f679efc408



void setDefaultRotation()
{
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString((Uchar8_t*)"Set Def. Rot.");
	LCD_SetCursor(1,0);
	LCD_WriteString((Uchar8_t*)"Right");
	TMR_intDelay_ms(5000);
	
	while(u8_g_timeOut != 1)
	{
		PUSH_BTN_read_state(0,&en_g_rotationBtnState);
		if(en_g_rotationBtnState == PUSH_BTN_STATE_RELEASED)
		{
			while(en_g_rotationBtnState == PUSH_BTN_STATE_RELEASED)
			{
				PUSH_BTN_read_state(0,&en_g_rotationBtnState);
			}
<<<<<<< HEAD
			if(u8_g_rotationFlag == 0)
			{
				u8_g_rotationFlag = 1;
				en_g_rotation = ROTATION_L;
=======
			if(rotation == ROTATION_R)
			{
				rotation = ROTATION_L;
>>>>>>> 63217c544e9b093926dfac603afa83f679efc408
				LCD_SetCursor(1,0);
				LCD_WriteString((Uchar8_t*)"Left ");
				
			}
<<<<<<< HEAD
			else if(u8_g_rotationFlag == 1)
			{
				u8_g_rotationFlag = 0;
				en_g_rotation = ROTATION_R;
=======
			else if(rotation == ROTATION_L)
			{
				rotation = ROTATION_R;
>>>>>>> 63217c544e9b093926dfac603afa83f679efc408
				LCD_SetCursor(1,0);
				LCD_WriteString((Uchar8_t*)"Right ");
			}
		}
	}
	u8_g_timeOut = 0;
	TMR_intDelay_ms(2000);
	while(u8_g_timeOut !=1);
	LCD_Clear();
	u8_g_timeOut = 0;
}



void obstcaleMoreThan70()
{
	
	
	if(u8_g_moreThan70Flag == 0)
	{
		u8_g_moreThan70Flag = 1;
		DCM_MoveForward(30);
		en_g_speed = SPEED_30;
		en_g_direction = DIRECTION_F;
		TMR_intDelay_ms(5000);
		
	}
	else if(u8_g_moreThan70Flag == 1 && u8_g_timeOut == 1)
	{
		
		DCM_MoveForward(50);
		en_g_speed = SPEED_50;
		u8_g_timeOut =0;
	}
 
    LCD_update(en_g_speed,en_g_direction,f64_g_obstcaleDistance);
}

void obstcaleMoreThan30()
{
<<<<<<< HEAD
	DCM_MoveForward(30);
	en_g_speed = SPEED_30;
	en_g_direction = DIRECTION_F;
	LCD_update(en_g_speed,en_g_direction,f64_g_obstcaleDistance);
=======
	if(moreThan30Flag == 0 )
	{
		DCM_MoveForward(30);
		speed = SPEED_30;
		direction = DIRECTION_F;
		moreThan30Flag = 1;
	}
	LCD_update(speed,direction,obstcaleDistance);
>>>>>>> 63217c544e9b093926dfac603afa83f679efc408
}


void obstcaleMoreThan20()
{
	DCM_vdStopDCM();
	LCD_update(SPEED_0,DIRECTION_S,f64_g_obstcaleDistance);
	TMR_intDelay_ms(1000);
	while(u8_g_timeOut == 0 );
	u8_g_timeOut = 0;
	if(u8_g_rot360Flag < 4)
	{
		LCD_update(SPEED_50,DIRECTION_R,obstcaleDistance);
		DCM_rotateDCM(rotation,50);
		u8_g_rot360Flag++;
	}
	
	else 
	{
		LCD_update(SPEED_0,DIRECTION_S,obstcaleDistance);
		TMR_intDelay_ms(3000);
		while(u8_g_timeOut == 0 );
		u8_g_timeOut = 0;
		u8_g_rot360Flag=0;
		
	}
	
<<<<<<< HEAD
	//en_g_rotation
	LCD_update(SPEED_50,DIRECTION_R,f64_g_obstcaleDistance);
	DCM_rotateDCM(en_g_rotation,50);	
=======
>>>>>>> 63217c544e9b093926dfac603afa83f679efc408
}

void obstcaleLessThan20()
{
	if(u8_g_lessThan20Flag == 0 )
	{
		DCM_vdStopDCM();
		LCD_update(SPEED_0,DIRECTION_S,f64_g_obstcaleDistance);
		TMR_intDelay_ms(1000);
		while(u8_g_timeOut == 0 );
		u8_g_timeOut = 0;
		u8_g_lessThan20Flag = 1;
	}
	
	else {
		LCD_update(SPEED_30,DIRECTION_B,f64_g_obstcaleDistance);
		DCM_MoveBackward(30);
	}
	
	
}
void LCD_update(EN_speed en_a_speed,EN_direction en_a_direction,float64_t f64_a_distance)
{
	
	
	LCD_SetCursor(0,0);
	LCD_WriteString((Uchar8_t*)"en_g_speed:");
    LCD_SetCursor(0,7);
	if(en_a_speed == SPEED_0 )
	{
		LCD_WriteString((Uchar8_t*)"00% ");
	}
	else if (en_a_speed == SPEED_30)
	{
		LCD_WriteString((Uchar8_t*)"30% ");
	}
	else 
	{
		LCD_WriteString((Uchar8_t*)"50% ");
	}
	LCD_SetCursor(0,11);
	LCD_WriteString((Uchar8_t*)"Dir:");
	LCD_SetCursor(0,15);
	if(en_a_direction == DIRECTION_F)
	{
		LCD_WriteString((Uchar8_t*)"F");
	}
	else if(en_a_direction == DIRECTION_B)
	{
		LCD_WriteString((Uchar8_t*)"B");
	}
	else if(en_a_direction == DIRECTION_R)
	{
		LCD_WriteString((Uchar8_t*)"R");
	}
    else
	{
		LCD_WriteString((Uchar8_t*)"S");
	}
	
	LCD_SetCursor(1,0);
	LCD_WriteString((Uchar8_t*)"Dist:");
	LCD_SetCursor(1,5);
	LCD_WriteNumber(f64_a_distance);
	LCD_WriteString((Uchar8_t*)" Cm");
	
}


void Car_Stop()
{
	DCM_vdStopDCM();
	LCD_SetCursor(0,0);
<<<<<<< HEAD
	LCD_WriteString((Uchar8_t *)"ROBOT STOPED");
}


void LCD_update_stop()
{
	LCD_SetCursor(0,0);
	LCD_WriteString((Uchar8_t *)"Press Key 1");
	LCD_SetCursor(1,0);
	LCD_WriteString((Uchar8_t *)"to start");
=======
	LCD_WriteString((Uchar8_t*)"ROBOT STOPED");
>>>>>>> 63217c544e9b093926dfac603afa83f679efc408
}