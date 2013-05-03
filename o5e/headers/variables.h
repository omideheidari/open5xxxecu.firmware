 
/**************************************************************************************************

        @file           variables.h
        @author         Jon Zeeff
        @date           December, 2011
        @brief          System variables that the tuner will read or write
        @copyright      MIT license
        @warning        needs more testing - send results to jon at zeeff.com
        @version        1.2
        
        @note 		parts of this are created from a TunerStudio .ini file with the program format_ini.c
        
****************************************************************************************************/

/* Copyright (c) 2011 Jon Zeeff 
   Copyright 2012, Sean Stasiak <sstasiak at gmail dot com> */

#ifndef variables_h
#define variables_h

// these are what the tuner uses
#define U08 uint8_t
#define S08 int8_t
#define U16 uint16_t
#define S16 int16_t
#define U32 uint32_t
#define S32 int32_t

// subroutines related to this file
void init_variables(void);
void Set_Page_Locations(uint8_t block);

//************************************************************************************

// **** below is manually mantained from the .ini file
// !!!! YES, change these things if you change the .ini file !!!!

// Change this every time you modify the .ini
#define VERSION  "O5e1.0.0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
//               "12345678 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9"

#define SIGNATURE "MShift 2.111       "
//                "1234567890123456789"

#define PROTOCOL  "001"
//

#define  NPAGES  	15

extern uint16_t const pageSize[NPAGES];

//*************************************

// All variables that may be sent to the tuner must be defined here and in the tuner.ini file with the exact same layout

// Output_Channels is special in that it is always in a fixed location in ram.  This allows us to define variables differently.
// Note, we trust that the compiler will keep these in order and not do any padding.  
// If not, then we will have to use a block of ram instead of a struct

// This list is maintained *manually* and must match the .ini file exactly - same size, number and order

//[Output_Channels]
struct Outputs {

uint16_t RPM;
int16_t RPM_Dot;
uint16_t Reference_VE;
int16_t Reference_VE_Dot;
int16_t V_MAP[4];
int16_t V_Batt;
int16_t V_CLT;
int16_t V_IAT;
int16_t V_TPS;
int16_t V_MAF[2];
int16_t V_O2_UA[2];
int16_t V_O2_UR[2];
int16_t V_P[14];
int16_t TPS;
int16_t AFR[2];
int16_t MAP[4];
int16_t MAP_Dot[4];
int16_t MAF[2];
int16_t MAF_Dot[2];
int16_t CLT;
int16_t IAT;
int16_t Injection_Time;
int16_t Spark_Advance;
int16_t Inj_End_Angle;
int16_t Eng_Model_Corr;
uint16_t Post_Start_Time;
uint16_t Post_Start_Cycles;
uint16_t Post_Start_Cylinder;
uint32_t Last_Error;            // error code for last system error
int16_t Dwell;
int16_t TPS_Dot;
int16_t Sync_Status;            // see Freescale code for values 
int16_t Cam_Errors;             // count of errors seen
int16_t Crank_Errors;           // count of errors seen
int16_t Pot_RPM;
uint32_t Last_Error_Time;       // time that Last_Error or Crank or Cam error occured
uint32_t  seconds ;
uint8_t Spares[24];
};

// this must match the offsets in the .ini file AND must be a multiple of 4
#define OUTPUT_CHANNELS_SIZE  160        // don't use sizeof() here


// these are for convenience and more readable code - must match above
#define RPM Output_Channels.RPM
#define RPM_Dot Output_Channels.RPM_Dot
#define Reference_VE Output_Channels.Reference_VE
#define Reference_VE_Dot Output_Channels.Reference_VE_Dot
#define V_MAP Output_Channels.V_MAP
#define V_Batt Output_Channels.V_Batt
#define V_CLT Output_Channels.V_CLT
#define V_IAT Output_Channels.V_IAT
#define V_TPS Output_Channels.V_TPS
#define V_MAF Output_Channels.V_MAF
#define V_O2_UA Output_Channels.V_O2_UA
#define V_O2_UR Output_Channels.V_O2_UR
#define V_P Output_Channels.V_P
#define TPS Output_Channels.TPS
#define AFR Output_Channels.AFR
#define MAP Output_Channels.MAP
#define MAP_Dot Output_Channels.MAP_Dot
#define MAF Output_Channels.MAF
#define MAF_Dot Output_Channels.MAF_Dot
#define CLT Output_Channels.CLT
#define IAT Output_Channels.IAT
#define Injection_Time Output_Channels.Injection_Time
#define Spark_Advance Output_Channels.Spark_Advance
#define Inj_End_Angle Output_Channels.Inj_End_Angle
#define Eng_Model_Corr Output_Channels.Eng_Model_Corr
#define Post_Start_Time Output_Channels.Post_Start_Time
#define Post_Start_Cycles Output_Channels.Post_Start_Cycles
#define Post_Start_Cylinders Output_Channels.Post_Start_Cylinders
#define Last_Error Output_Channels.Last_Error
#define Dwell Output_Channels.Dwell
#define TPS_Dot Output_Channels.TPS_Dot
#define Sync_Status Output_Channels.Sync_Status
#define Cam_Errors Output_Channels.Cam_Errors
#define Pot_RPM Output_Channels.Pot_RPM
#define Crank_Errors Output_Channels.Crank_Errors
#define Last_Error_Time Output_Channels.Last_Error_Time
#define seconds Output_Channels.seconds

//*******************************************************
// initialized to all zeros
extern struct Outputs Output_Channels;

// allow writing to config variables for testing - see variables.c
#define CONST   /**< TODO: rip out FAST! - this needs to be checked though */
//#define CONST const

// Flash Variables from .ini - auto generated, do not edit
// Cast the flash memory pages into variable names
// Note: some of these could have ram copies for speed reasons
//--------------------------------------------------------

#define Version_Array ((CONST U08 * )(&Page_Ptr[0][0]))
#define N_Cyl (*(CONST U08 * )(&Page_Ptr[0][20]) & ((2<<3)-1))
#define N_Teeth (*(CONST U08 * )(&Page_Ptr[0][21]))
#define Missing_Teeth (*(CONST U08 * )(&Page_Ptr[0][22]) & ((2<<2)-1))
#define Cam_Lobe_Pos (*(CONST S16 * )(&Page_Ptr[0][24]))
#define Load_Sense (*(CONST U08 * )(&Page_Ptr[0][26]) & ((2<<2)-1))
#define Cyl_Offset_1 (*(CONST S16 * )(&Page_Ptr[0][28]))
#define Cyl_Offset_Array ((CONST S16 * )(&Page_Ptr[0][28]))
#define Cyl_Offset_2 (*(CONST S16 * )(&Page_Ptr[0][30]))
#define Cyl_Offset_3 (*(CONST S16 * )(&Page_Ptr[0][32]))
#define Cyl_Offset_4 (*(CONST S16 * )(&Page_Ptr[0][34]))
#define Cyl_Offset_5 (*(CONST S16 * )(&Page_Ptr[0][36]))
#define Cyl_Offset_6 (*(CONST S16 * )(&Page_Ptr[0][38]))
#define Cyl_Offset_7 (*(CONST S16 * )(&Page_Ptr[0][40]))
#define Cyl_Offset_8 (*(CONST S16 * )(&Page_Ptr[0][42]))
#define Cyl_Offset_9 (*(CONST S16 * )(&Page_Ptr[0][44]))
#define Cyl_Offset_10 (*(CONST S16 * )(&Page_Ptr[0][46]))
#define Cyl_Offset_11 (*(CONST S16 * )(&Page_Ptr[0][48]))
#define Cyl_Offset_12 (*(CONST S16 * )(&Page_Ptr[0][50]))
#define Config_Ign_1 (*(CONST U08 * )(&Page_Ptr[0][52]))
#define Config_Ign_Array ((CONST U08 * )(&Page_Ptr[0][52]))
#define Config_Ign_2 (*(CONST U08 * )(&Page_Ptr[0][53]) & ((2<<3)-1))
#define Config_Ign_3 (*(CONST U08 * )(&Page_Ptr[0][54]) & ((2<<3)-1))
#define Config_Ign_4 (*(CONST U08 * )(&Page_Ptr[0][55]) & ((2<<3)-1))
#define Config_Ign_5 (*(CONST U08 * )(&Page_Ptr[0][56]) & ((2<<3)-1))
#define Config_Ign_6 (*(CONST U08 * )(&Page_Ptr[0][57]) & ((2<<3)-1))
#define Config_Ign_7 (*(CONST U08 * )(&Page_Ptr[0][58]) & ((2<<3)-1))
#define Config_Ign_8 (*(CONST U08 * )(&Page_Ptr[0][59]) & ((2<<3)-1))
#define Config_Ign_9 (*(CONST U08 * )(&Page_Ptr[0][60]) & ((2<<3)-1))
#define Config_Ign_10 (*(CONST U08 * )(&Page_Ptr[0][61]) & ((2<<3)-1))
#define Config_Ign_11 (*(CONST U08 * )(&Page_Ptr[0][62]) & ((2<<3)-1))
#define Config_Ign_12 (*(CONST U08 * )(&Page_Ptr[0][63]) & ((2<<3)-1))
#define Config_Inj_1 (*(CONST U08 * )(&Page_Ptr[0][64]))
#define Config_Inj_Array ((CONST U08 * )(&Page_Ptr[0][64]))
#define Config_Inj_2 (*(CONST U08 * )(&Page_Ptr[0][65]) & ((2<<3)-1))
#define Config_Inj_3 (*(CONST U08 * )(&Page_Ptr[0][66]) & ((2<<3)-1))
#define Config_Inj_4 (*(CONST U08 * )(&Page_Ptr[0][67]) & ((2<<3)-1))
#define Config_Inj_5 (*(CONST U08 * )(&Page_Ptr[0][68]) & ((2<<3)-1))
#define Config_Inj_6 (*(CONST U08 * )(&Page_Ptr[0][69]) & ((2<<3)-1))
#define Config_Inj_7 (*(CONST U08 * )(&Page_Ptr[0][70]) & ((2<<3)-1))
#define Config_Inj_8 (*(CONST U08 * )(&Page_Ptr[0][71]) & ((2<<3)-1))
#define Config_Inj_9 (*(CONST U08 * )(&Page_Ptr[0][72]) & ((2<<3)-1))
#define Config_Inj_10 (*(CONST U08 * )(&Page_Ptr[0][73]) & ((2<<3)-1))
#define Config_Inj_11 (*(CONST U08 * )(&Page_Ptr[0][74]) & ((2<<3)-1))
#define Config_Inj_12 (*(CONST U08 * )(&Page_Ptr[0][75]) & ((2<<3)-1))
#define Config_Inj_13 (*(CONST U08 * )(&Page_Ptr[0][76]) & ((2<<3)-1))
#define Config_Inj_14 (*(CONST U08 * )(&Page_Ptr[0][77]) & ((2<<3)-1))
#define Config_Inj_15 (*(CONST U08 * )(&Page_Ptr[0][78]) & ((2<<3)-1))
#define Config_Inj_16 (*(CONST U08 * )(&Page_Ptr[0][79]) & ((2<<3)-1))
#define Config_Inj_17 (*(CONST U08 * )(&Page_Ptr[0][80]) & ((2<<3)-1))
#define Config_Inj_18 (*(CONST U08 * )(&Page_Ptr[0][81]) & ((2<<3)-1))
#define Config_Inj_19 (*(CONST U08 * )(&Page_Ptr[0][82]) & ((2<<3)-1))
#define Config_Inj_20 (*(CONST U08 * )(&Page_Ptr[0][83]) & ((2<<3)-1))
#define Config_Inj_21 (*(CONST U08 * )(&Page_Ptr[0][84]) & ((2<<3)-1))
#define Config_Inj_22 (*(CONST U08 * )(&Page_Ptr[0][85]) & ((2<<3)-1))
#define Config_Inj_23 (*(CONST U08 * )(&Page_Ptr[0][86]) & ((2<<3)-1))
#define Config_Inj_24 (*(CONST U08 * )(&Page_Ptr[0][87]) & ((2<<3)-1))
#define Config_LS_1 (*(CONST U08 * )(&Page_Ptr[0][88]))
#define Config_LS_Array ((CONST U08 * )(&Page_Ptr[0][88]))
#define Config_LS_2 (*(CONST U08 * )(&Page_Ptr[0][89]) & ((2<<0)-1))
#define Config_LS_3 (*(CONST U08 * )(&Page_Ptr[0][90]) & ((2<<1)-1))
#define Config_LS_4 (*(CONST U08 * )(&Page_Ptr[0][91]) & ((2<<1)-1))
#define Config_LS_5 (*(CONST U08 * )(&Page_Ptr[0][92]) & ((2<<1)-1))
#define Config_LS_6 (*(CONST U08 * )(&Page_Ptr[0][93]) & ((2<<1)-1))
#define Config_HS_1 (*(CONST U08 * )(&Page_Ptr[0][94]))
#define Config_HS_Array ((CONST U08 * )(&Page_Ptr[0][94]))
#define Config_HS_2 (*(CONST U08 * )(&Page_Ptr[0][95]) & ((2<<1)-1))
#define Config_HS_3 (*(CONST U08 * )(&Page_Ptr[0][96]) & ((2<<1)-1))
#define Config_HS_4 (*(CONST U08 * )(&Page_Ptr[0][97]) & ((2<<1)-1))
#define Config_Stepper (*(CONST U08 * )(&Page_Ptr[0][98]) & ((2<<1)-1)) 
#define Engine_Position (*(CONST S16 * )(&Page_Ptr[0][100]))
#define Drop_Dead_Angle (*(CONST S16 * )(&Page_Ptr[0][102]))
#define Ignition_Type (*(CONST U08 * )(&Page_Ptr[0][104]) & ((2<<0)-1))
#define Test_Enable (*(CONST U08 * )(&Page_Ptr[0][105]) & ((2<<0)-1))
#define Test_Value (*(CONST U08 * )(&Page_Ptr[0][106]) & ((2<<0)-1))
#define Test_RPM (*(CONST S16 * )(&Page_Ptr[0][108]))
#define Test_TPS (*(CONST S16 * )(&Page_Ptr[0][110]))
#define Test_AFR_1 (*(CONST S16 * )(&Page_Ptr[0][112]))
#define Test_AFR_Array ((CONST S16 * )(&Page_Ptr[0][112]))
#define Test_AFR_2 (*(CONST S16 * )(&Page_Ptr[0][114]))
#define Test_MAP_1 (*(CONST S16 * )(&Page_Ptr[0][116]))
#define Test_MAP_Array ((CONST S16 * )(&Page_Ptr[0][116]))
#define Test_MAP_2 (*(CONST S16 * )(&Page_Ptr[0][118]))
#define Test_MAF_1 (*(CONST S16 * )(&Page_Ptr[0][120]))
#define Test_MAF_Array ((CONST S16 * )(&Page_Ptr[0][120]))
#define Test_MAF_2 (*(CONST S16 * )(&Page_Ptr[0][122]))
#define Test_CLT (*(CONST S16 * )(&Page_Ptr[0][124]))
#define Test_IAT (*(CONST S16 * )(&Page_Ptr[0][126]))
#define Test_V_MAP_1 (*(CONST S16 * )(&Page_Ptr[0][128]))
#define Test_V_MAP_Array ((CONST S16 * )(&Page_Ptr[0][128]))
#define Test_V_MAP_2 (*(CONST S16 * )(&Page_Ptr[0][130]))
#define Test_V_Batt (*(CONST S16 * )(&Page_Ptr[0][132]))
#define Test_V_CLT (*(CONST S16 * )(&Page_Ptr[0][134]))
#define Test_V_IAT (*(CONST S16 * )(&Page_Ptr[0][136]))
#define Test_V_TPS (*(CONST S16 * )(&Page_Ptr[0][138]))
#define Test_V_MAF_1 (*(CONST S16 * )(&Page_Ptr[0][140]))
#define Test_V_MAF_Array ((CONST S16 * )(&Page_Ptr[0][140]))
#define Test_V_MAF_2 (*(CONST S16 * )(&Page_Ptr[0][142]))
#define Test_V_O2_UA_1 (*(CONST S16 * )(&Page_Ptr[0][144]))
#define Test_V_O2_UA_Array ((CONST S16 * )(&Page_Ptr[0][144]))
#define Test_V_O2_UA_2 (*(CONST S16 * )(&Page_Ptr[0][146]))
#define Test_V_O2_UR_1 (*(CONST S16 * )(&Page_Ptr[0][148]))
#define Test_V_O2_UR_Array ((CONST S16 * )(&Page_Ptr[0][148]))
#define Test_V_O2_UR_2 (*(CONST S16 * )(&Page_Ptr[0][150]))
#define Pulses_Per_Rev (*(CONST U08 * )(&Page_Ptr[0][152]) & ((2<<3)-1))
#define Crank_Edge_Select (*(CONST U08 * )(&Page_Ptr[0][154]) & ((2<<0)-1))
#define Cam_Edge_Select (*(CONST U08 * )(&Page_Ptr[0][155]) & ((2<<0)-1))
#define Sync_Mode_Select (*(CONST U08 * )(&Page_Ptr[0][156]) & ((2<<0)-1))
#define Engine_Type_Select (*(CONST U08 * )(&Page_Ptr[0][157]) & ((2<<1)-1))
#define Cam_Window_Open_Set (*(CONST S16 * )(&Page_Ptr[0][158]))
#define Cam_Window_Width_Set (*(CONST S16 * )(&Page_Ptr[0][160]))
#define Odd_Fire_Sync_Threshold (*(CONST S16 * )(&Page_Ptr[0][162]))
#define Odd_Fire_Sync_Angle (*(CONST S16 * )(&Page_Ptr[0][164]))
#define Ignition_Invert (*(CONST U08 * )(&Page_Ptr[0][166]) & ((2<<0)-1))
#define N_Coils_Per_Cylinder (*(CONST U08 * )(&Page_Ptr[0][166]) & ((2<<0)-1))
#define Jitter (*(CONST S16 * )(&Page_Ptr[0][168]))
#define RPM_Pot (*(CONST S16 * )(&Page_Ptr[0][170]))
#define crank_windowing_ratio_normal_set (*(CONST U32 * )(&Page_Ptr[0][172]))
#define crank_windowing_ratio_after_gap_set (*(CONST U32 * )(&Page_Ptr[0][176])) 
#define crank_windowing_ratio_across_gap_set (*(CONST U32 * )(&Page_Ptr[0][180]))
#define crank_windowing_ratio_timeout_set (*(CONST U32 * )(&Page_Ptr[0][184]))
#define crank_gap_ratio_set  (*(CONST U32 * )(&Page_Ptr[0][188]))
#define RPM_Change_Rate_1  (*(CONST U32 * )(&Page_Ptr[0][192]))
#define RPM_Change_Rate_Array ((CONST U32 * )(&Page_Ptr[0][192]))
#define RPM_Change_Rate_2  (*(CONST U32 * )(&Page_Ptr[0][196]))
#define RPM_Change_Rate_3  (*(CONST U32 * )(&Page_Ptr[0][200]))
#define RPM_Change_Rate_4  (*(CONST U32 * )(&Page_Ptr[0][204]))
#define Test_RPM_1  (*(CONST U16 * )(&Page_Ptr[0][208]))
#define Test_RPM_Array  (*(CONST U16 * )(&Page_Ptr[0][208]))
#define Test_RPM_2  (*(CONST U16 * )(&Page_Ptr[0][210]))
#define Test_RPM_3  (*(CONST U16 * )(&Page_Ptr[0][212]))
#define Test_RPM_4  (*(CONST U16 * )(&Page_Ptr[0][214]))
#define Test_RPM_Dwell_1  (*(CONST S16 * )(&Page_Ptr[0][216]))
#define Test_RPM_Dwell_Array  (*(CONST S16 * )(&Page_Ptr[0][216]))
#define Test_RPM_Dwell_2  (*(CONST S16 * )(&Page_Ptr[0][218]))
#define Test_RPM_Dwell_3  (*(CONST S16 * )(&Page_Ptr[0][220]))
#define Test_RPM_Dwell_4  (*(CONST S16 * )(&Page_Ptr[0][222]))
#define Test_RPM_Type (*(CONST U08 * )(&Page_Ptr[0][224]) & ((2<<1)-1))
#define Displacement  (*(CONST U16 * )(&Page_Ptr[0][226])) 
#define Injector_Size (*(CONST U16 * )(&Page_Ptr[0][228]))
#define Rating_Fuel_Presure  (*(CONST U16 * )(&Page_Ptr[0][230]))
#define Fuel_Presure   (*(CONST U16 * )(&Page_Ptr[0][232])) 


// Page 2
#define Fuel_Temp_Corr_Table ((CONST struct table_jz * )(&Page_Ptr[1][0]))
#define IAT_Fuel_Corr_Table ((CONST struct table_jz * )(&Page_Ptr[1][648]))
#define Inj_Dead_1 (*(CONST S16 * )(&Page_Ptr[1][816]))
#define Inj_Dead_Array ((CONST S16 * )(&Page_Ptr[1][816]))
#define Inj_Dead_2 (*(CONST S16 * )(&Page_Ptr[1][818]))
#define Inj_Dead_3 (*(CONST S16 * )(&Page_Ptr[1][820]))
#define Inj_Dead_4 (*(CONST S16 * )(&Page_Ptr[1][822]))
#define Inj_Dead_5 (*(CONST S16 * )(&Page_Ptr[1][824]))
#define Inj_Dead_6 (*(CONST S16 * )(&Page_Ptr[1][826]))
#define Inj_Dead_7 (*(CONST S16 * )(&Page_Ptr[1][828]))
#define Inj_Dead_8 (*(CONST S16 * )(&Page_Ptr[1][830]))
#define Inj_Dead_9 (*(CONST S16 * )(&Page_Ptr[1][832]))
#define Inj_Dead_10 (*(CONST S16 * )(&Page_Ptr[1][834]))
#define Inj_Dead_11 (*(CONST S16 * )(&Page_Ptr[1][836]))
#define Inj_Dead_12 (*(CONST S16 * )(&Page_Ptr[1][838]))
#define Inj_Dead_13 (*(CONST S16 * )(&Page_Ptr[1][840]))
#define Inj_Dead_14 (*(CONST S16 * )(&Page_Ptr[1][842]))
#define Inj_Dead_15 (*(CONST S16 * )(&Page_Ptr[1][844]))
#define Inj_Dead_16 (*(CONST S16 * )(&Page_Ptr[1][846]))
#define Inj_Dead_17 (*(CONST S16 * )(&Page_Ptr[1][848]))
#define Inj_Dead_18 (*(CONST S16 * )(&Page_Ptr[1][850]))
#define Inj_Dead_19 (*(CONST S16 * )(&Page_Ptr[1][852]))
#define Inj_Dead_20 (*(CONST S16 * )(&Page_Ptr[1][854]))
#define Inj_Dead_21 (*(CONST S16 * )(&Page_Ptr[1][856]))
#define Inj_Dead_22 (*(CONST S16 * )(&Page_Ptr[1][858]))
#define Inj_Dead_23 (*(CONST S16 * )(&Page_Ptr[1][860]))
#define Inj_Dead_24 (*(CONST S16 * )(&Page_Ptr[1][862]))
#define Enable_Ignition (*(CONST U08 * )(&Page_Ptr[1][864]) & ((2<<0)-1))
#define Enable_Map_Control (*(CONST U08 * )(&Page_Ptr[1][865]) & ((2<<0)-1))
#define Enable_Inj (*(CONST U08 * )(&Page_Ptr[1][866]) & ((2<<0)-1))
#define Dwell_Table ((CONST struct table_jz * )(&Page_Ptr[1][868]))
#define Dwell_Set (*(CONST S16 * )(&Page_Ptr[1][1020]))
#define Dead_Time_Set (*(CONST S16 * )(&Page_Ptr[1][1022]))
#define Rev_Limit (*(CONST S16 * )(&Page_Ptr[1][1024]))
#define Soft_Rev_Limit (*(CONST S16 * )(&Page_Ptr[1][1026]))
#define Rev_Limit_Type (*(CONST U08 * )(&Page_Ptr[1][1028]) & ((2<<2)-1))
#define Max_Inj_Time (*(CONST S16 * )(&Page_Ptr[1][1030]))
#define Inj_Dead_Time_Table ((CONST struct table_jz * )(&Page_Ptr[1][1032]))
#define Eng_Model_Table ((CONST struct table_jz * )(&Page_Ptr[1][1184]))
#define Staged_Inj (*(CONST U08 * )(&Page_Ptr[1][1384]) & ((2<<1)-1))
#define Stage_Load (*(CONST U08 * )(&Page_Ptr[1][1385]))
#define staged_Load_Dead (*(CONST U08 * )(&Page_Ptr[1][1386]))
#define Stage_RPM (*(CONST S16 * )(&Page_Ptr[1][1388]))
#define Staged_RPM_Dead (*(CONST S16 * )(&Page_Ptr[1][1390]))
#define Enable_Accel_Decel (*(CONST U08 * )(&Page_Ptr[1][1392]) & ((2<<0)-1))
#define IAC_Enable (*(CONST U08 * )(&Page_Ptr[1][1393]) & ((2<<1)-1))
#define Warm_Idle_RPM (*(CONST S16 * )(&Page_Ptr[1][1394]))
#define Cold_Idle_RPM (*(CONST S16 * )(&Page_Ptr[1][1396]))
#define Warm_Start_IAC (*(CONST U08 * )(&Page_Ptr[1][1398]))
#define Cold_start_IAC (*(CONST U08 * )(&Page_Ptr[1][1399]))
#define Warm_IAC (*(CONST U08 * )(&Page_Ptr[1][1400]))
#define Cold_IAC (*(CONST U08 * )(&Page_Ptr[1][1401]))
#define Warm_Idle_Temp (*(CONST S16 * )(&Page_Ptr[1][1402]))
#define Warm_Start_Temp (*(CONST S16 * )(&Page_Ptr[1][1404]))
#define MAP_Angle_Table ((CONST struct table_jz * )(&Page_Ptr[1][1406]))
#define Dwell_Min (*(CONST U08 * )(&Page_Ptr[1][1606]))
#define Dwell_Max (*(CONST U08 * )(&Page_Ptr[1][1607]))
#define sqrt_Table ((CONST struct table_jz * )(&Page_Ptr[1][1608]))
#define Password (*(CONST U32 * )(&Page_Ptr[1][1808]))
#define Model_Tuning_Enable (*(CONST U08 * )(&Page_Ptr[1][1812]) & ((2<<0)-1))
#define Spare9 (*(CONST U08 * )(&Page_Ptr[1][1813]) & ((2<<0)-1))
#define Spare10 (*(CONST S16 * )(&Page_Ptr[1][1814]))
#define Fuel_Pump_Prime_Time (*(CONST S32 * )(&Page_Ptr[1][1816])) 
#define Spare12 (*(CONST S32 * )(&Page_Ptr[1][1820]))

// Page 3
#define Dummy_Corr_Table ((CONST struct table_jz * )(&Page_Ptr[2][0]))
#define Accel_Limit_Table ((CONST struct table_jz * )(&Page_Ptr[2][168]))
#define Accel_Decay_Table ((CONST struct table_jz * )(&Page_Ptr[2][320]))
#define Accel_Sensativity_Table ((CONST struct table_jz * )(&Page_Ptr[2][472]))
#define Decel_Limit_Table ((CONST struct table_jz * )(&Page_Ptr[2][624]))
#define Decel_Decay_Table ((CONST struct table_jz * )(&Page_Ptr[2][776]))
#define Decel_Sensativity_Table ((CONST struct table_jz * )(&Page_Ptr[2][928]))
#define Prime_Decay_Table ((CONST struct table_jz * )(&Page_Ptr[2][1080]))
#define Man_Crank_Corr_Table ((CONST struct table_jz * )(&Page_Ptr[2][1232]))
#define Prime_Corr_Table ((CONST struct table_jz * )(&Page_Ptr[2][1374]))
// Page 4
#define CLT_Table ((CONST struct table_jz * )(&Page_Ptr[3][0]))
#define CLT_Cal_Array ((CONST S16 * )(&Page_Ptr[3][136]))
#define IAT_Table ((CONST struct table_jz * )(&Page_Ptr[3][168]))
#define IAT_Cal_Array ((CONST S16 * )(&Page_Ptr[3][304]))
#define TPS_Table ((CONST struct table_jz * )(&Page_Ptr[3][336]))
#define TPS_Flow_Cal_On (*(CONST U08 * )(&Page_Ptr[3][476]) & ((2<<0)-1))
#define TPS_Flow_Table ((CONST struct table_jz * )(&Page_Ptr[3][478]))
#define AFR_1_Table ((CONST struct table_jz * )(&Page_Ptr[3][646]))
#define AFR_2_Table ((CONST struct table_jz * )(&Page_Ptr[3][814]))
#define MAF_1_Table ((CONST struct table_jz * )(&Page_Ptr[3][982]))
#define MAF_1_Cal_Array ((CONST S16 * )(&Page_Ptr[3][1118]))
#define MAF_2_Table ((CONST struct table_jz * )(&Page_Ptr[3][1150]))
#define MAF_2_Cal_Array ((CONST S16 * )(&Page_Ptr[3][1286]))
#define MAP_1_Table ((CONST struct table_jz * )(&Page_Ptr[3][1318]))
#define MAP_1_Cal_Array ((CONST S16 * )(&Page_Ptr[3][1454]))
#define MAP_2_Table ((CONST struct table_jz * )(&Page_Ptr[3][1486]))
#define MAP_2_Cal_Array ((CONST S16 * )(&Page_Ptr[3][1622]))
#define MAP_3_Table ((CONST struct table_jz * )(&Page_Ptr[3][1654]))
#define MAP_3_Cal_Array ((CONST S16 * )(&Page_Ptr[3][1790]))
#define MAP_4_Table ((CONST struct table_jz * )(&Page_Ptr[3][1822]))
#define MAP_4_Cal_Array ((CONST S16 * )(&Page_Ptr[3][1958]))
// Page 5
#define Inj_Time_Corr_Table ((CONST struct table_jz * )(&Page_Ptr[4][0]))
// Page 6
#define Inj_End_Angle_Table ((CONST struct table_jz * )(&Page_Ptr[5][0]))
// Page 7
#define Spark_Advance_Table ((CONST struct table_jz * )(&Page_Ptr[6][0]))
// Page 8
#define AFR_Set_Point_Table ((CONST struct table_jz * )(&Page_Ptr[7][0]))
// Page 9
#define Cyl_Trim_1_Table ((CONST struct table_jz * )(&Page_Ptr[8][0]))
#define Cyl_Trim_2_Table ((CONST struct table_jz * )(&Page_Ptr[8][488]))
#define Cyl_Trim_3_Table ((CONST struct table_jz * )(&Page_Ptr[8][976]))
#define Cyl_Trim_4_Table ((CONST struct table_jz * )(&Page_Ptr[8][1464]))
// Page 10
#define Cyl_Trim_5_Table ((CONST struct table_jz * )(&Page_Ptr[9][0]))
#define Cyl_Trim_6_Table ((CONST struct table_jz * )(&Page_Ptr[9][488]))
#define Cyl_Trim_7_Table ((CONST struct table_jz * )(&Page_Ptr[9][976]))
#define Cyl_Trim_8_Table ((CONST struct table_jz * )(&Page_Ptr[9][1464]))
// Page 11
#define Cyl_Trim_9_Table ((CONST struct table_jz * )(&Page_Ptr[10][0]))
#define Cyl_Trim_10_Table ((CONST struct table_jz * )(&Page_Ptr[10][488]))
#define Cyl_Trim_11_Table ((CONST struct table_jz * )(&Page_Ptr[10][976]))
#define Cyl_Trim_12_Table ((CONST struct table_jz * )(&Page_Ptr[10][1464]))
// Page 12
#define Coil_Trim_1_Table ((CONST struct table_jz * )(&Page_Ptr[11][0]))
#define Coil_Trim_2_Table ((CONST struct table_jz * )(&Page_Ptr[11][488]))
#define Coil_Trim_3_Table ((CONST struct table_jz * )(&Page_Ptr[11][976]))
#define Coil_Trim_4_Table ((CONST struct table_jz * )(&Page_Ptr[11][1464]))
// Page 13
#define Coil_Trim_5_Table ((CONST struct table_jz * )(&Page_Ptr[12][0]))
#define Coil_Trim_6_Table ((CONST struct table_jz * )(&Page_Ptr[12][488]))
#define Coil_Trim_7_Table ((CONST struct table_jz * )(&Page_Ptr[12][976]))
#define Coil_Trim_8_Table ((CONST struct table_jz * )(&Page_Ptr[12][1464]))
// Page 14
#define Coil_Trim_9_Table ((CONST struct table_jz * )(&Page_Ptr[13][0]))
#define Coil_Trim_10_Table ((CONST struct table_jz * )(&Page_Ptr[13][488]))
#define Coil_Trim_11_Table ((CONST struct table_jz * )(&Page_Ptr[13][976]))
#define Coil_Trim_12_Table ((CONST struct table_jz * )(&Page_Ptr[13][1464]))
// Page 15
#define Generic_Output_1_Link_1 (*(CONST U08 * )(&Page_Ptr[14][0]) & ((2<<2)-1))
#define Generic_Output_1_Link_1_on (*(CONST U08 * )(&Page_Ptr[14][1]) & ((2<<1)-1))
#define Generic_Output_1_Link_1_on_set (*(CONST S16 * )(&Page_Ptr[14][2]))
#define Generic_Output_1_Link_1_off (*(CONST U08 * )(&Page_Ptr[14][4]) & ((2<<1)-1))
#define Generic_Output_1_type (*(CONST U08 * )(&Page_Ptr[14][5]) & ((2<<3)-1))
#define Generic_Output_1_Link_1_off_set (*(CONST S16 * )(&Page_Ptr[14][6]))
#define Generic_Output_1_Link_2 (*(CONST U08 * )(&Page_Ptr[14][8]) & ((2<<2)-1))
#define Generic_Output_1_Link_2_on (*(CONST U08 * )(&Page_Ptr[14][9]) & ((2<<1)-1))
#define Generic_Output_1_Link_2_on_set (*(CONST S16 * )(&Page_Ptr[14][10]))
#define Generic_Output_1_Link_2_off (*(CONST U08 * )(&Page_Ptr[14][12]) & ((2<<1)-1))
#define Generic_Output_1_Link_2_off_set (*(CONST S16 * )(&Page_Ptr[14][14]))
#define Generic_Output_1_Link_3 (*(CONST U08 * )(&Page_Ptr[14][16]) & ((2<<2)-1))
#define Generic_Output_1_Link_3_on (*(CONST U08 * )(&Page_Ptr[14][17]) & ((2<<1)-1))
#define Generic_Output_1_Link2_3_on_set (*(CONST S16 * )(&Page_Ptr[14][18]))
#define Generic_Output_1_Link_3_off (*(CONST U08 * )(&Page_Ptr[14][20]) & ((2<<1)-1))
#define Generic_Output_1_Link_3_off_set (*(CONST S16 * )(&Page_Ptr[14][22]))
#define Generic_Output_1_Link_4 (*(CONST U08 * )(&Page_Ptr[14][24]) & ((2<<2)-1))
#define Generic_Output_1_Link_4_on (*(CONST U08 * )(&Page_Ptr[14][25]) & ((2<<1)-1))
#define Generic_Output_1_Link_4_on_set (*(CONST S16 * )(&Page_Ptr[14][26]))
#define Generic_Output_1_Link_4_off (*(CONST U08 * )(&Page_Ptr[14][28]) & ((2<<1)-1))
#define Generic_Output_1_Link_4_off_set (*(CONST S16 * )(&Page_Ptr[14][30]))
#define Generic_Output_1_PWM_Table ((CONST struct table_jz * )(&Page_Ptr[14][32]))
#define Generic_Output_1_Link_1_PWM_Frequency (*(CONST S16 * )(&Page_Ptr[14][200])) 
#define Generic_Output_1_Link_1_PWM_Dutycycle (*(CONST S16 * )(&Page_Ptr[14][202]))
#define Generic_Output_1_Link_1_PWM_setpoint (*(CONST S16 * )(&Page_Ptr[14][204]))
#define Generic_Output_1_Link_1_PWM_proportional (*(CONST S16 * )(&Page_Ptr[14][206]))
#define Generic_Output_1_Link_1_PWM_integral (*(CONST S16 * )(&Page_Ptr[14][208]))
#define Generic_Output_1_Link_1_PWM_differential (*(CONST S16 * )(&Page_Ptr[14][210])) 
#define Generic_Output_1_Link_1_PWM_hysteresis (*(CONST S16 * )(&Page_Ptr[14][212]))
#define Generic_Output_2_Link_1 (*(CONST U08 * )(&Page_Ptr[14][214]) & ((2<<2)-1))
#define Generic_Output_2_Link_1_on (*(CONST U08 * )(&Page_Ptr[14][215]) & ((2<<1)-1))
#define Generic_Output_2_Link_1_on_set (*(CONST S16 * )(&Page_Ptr[14][216]))
#define Generic_Output_2_Link_1_off (*(CONST U08 * )(&Page_Ptr[14][218]) & ((2<<1)-1))
#define Generic_Output_2_type (*(CONST U08 * )(&Page_Ptr[14][219]) & ((2<<3)-1))
#define Generic_Output_2_Link_1_off_set (*(CONST S16 * )(&Page_Ptr[14][220]))
#define Generic_Output_2_Link_2 (*(CONST U08 * )(&Page_Ptr[14][222]) & ((2<<2)-1))
#define Generic_Output_2_Link_2_on (*(CONST U08 * )(&Page_Ptr[14][223]) & ((2<<1)-1))
#define Generic_Output_2_Link_2_on_set (*(CONST S16 * )(&Page_Ptr[14][224]))
#define Generic_Output_2_Link_2_off (*(CONST U08 * )(&Page_Ptr[14][226]) & ((2<<1)-1))
#define Generic_Output_2_Link_2_off_set (*(CONST S16 * )(&Page_Ptr[14][228]))
#define Generic_Output_2_Link_3 (*(CONST U08 * )(&Page_Ptr[14][230]) & ((2<<2)-1))
#define Generic_Output_2_Link_3_on (*(CONST U08 * )(&Page_Ptr[14][231]) & ((2<<1)-1))
#define Generic_Output_2_Link2_3_on_set (*(CONST S16 * )(&Page_Ptr[14][232]))
#define Generic_Output_2_Link_3_off (*(CONST U08 * )(&Page_Ptr[14][234]) & ((2<<1)-1))
#define Generic_Output_2_Link_3_off_set (*(CONST S16 * )(&Page_Ptr[14][236]))
#define Generic_Output_2_Link_4 (*(CONST U08 * )(&Page_Ptr[14][238]) & ((2<<2)-1))
#define Generic_Output_2_Link_4_on (*(CONST U08 * )(&Page_Ptr[14][239]) & ((2<<1)-1))
#define Generic_Output_2_Link_4_on_set (*(CONST S16 * )(&Page_Ptr[14][240]))
#define Generic_Output_2_Link_4_off (*(CONST U08 * )(&Page_Ptr[14][242]) & ((2<<1)-1))
#define Generic_Output_2_Link_4_off_set (*(CONST S16 * )(&Page_Ptr[14][244]))
#define Generic_Output_2_PWM_Table ((CONST struct table_jz * )(&Page_Ptr[14][246]))
#define Generic_Output_2_Link_1_PWM_Frequency (*(CONST S16 * )(&Page_Ptr[14][414])) 
#define Generic_Output_2_Link_1_PWM_Dutycycle (*(CONST S16 * )(&Page_Ptr[14][416]))
#define Generic_Output_2_Link_1_PWM_setpoint (*(CONST S16 * )(&Page_Ptr[14][418]))
#define Generic_Output_2_Link_1_PWM_proportional (*(CONST S16 * )(&Page_Ptr[14][420]))
#define Generic_Output_2_Link_1_PWM_integral (*(CONST S16 * )(&Page_Ptr[14][422]))
#define Generic_Output_2_Link_1_PWM_differential (*(CONST S16 * )(&Page_Ptr[14][424])) 
#define Generic_Output_2_Link_1_PWM_hysteresis (*(CONST S16 * )(&Page_Ptr[14][426]))
#define Generic_Output_3_Link_1 (*(CONST U08 * )(&Page_Ptr[14][428]) & ((2<<2)-1))
#define Generic_Output_3_Link_1_on (*(CONST U08 * )(&Page_Ptr[14][429]) & ((2<<1)-1))
#define Generic_Output_3_Link_1_on_set (*(CONST S16 * )(&Page_Ptr[14][430]))
#define Generic_Output_3_Link_1_off (*(CONST U08 * )(&Page_Ptr[14][432]) & ((2<<1)-1))
#define Generic_Output_3_type (*(CONST U08 * )(&Page_Ptr[14][433]) & ((2<<3)-1))
#define Generic_Output_3_Link_1_off_set (*(CONST S16 * )(&Page_Ptr[14][434]))
#define Generic_Output_3_Link_2 (*(CONST U08 * )(&Page_Ptr[14][436]) & ((2<<2)-1))
#define Generic_Output_3_Link_2_on (*(CONST U08 * )(&Page_Ptr[14][437]) & ((2<<1)-1))
#define Generic_Output_3_Link_2_on_set (*(CONST S16 * )(&Page_Ptr[14][438]))
#define Generic_Output_3_Link_2_off (*(CONST U08 * )(&Page_Ptr[14][440]) & ((2<<1)-1))
#define Generic_Output_3_Link_2_off_set (*(CONST S16 * )(&Page_Ptr[14][442]))
#define Generic_Output_3_Link_3 (*(CONST U08 * )(&Page_Ptr[14][444]) & ((2<<2)-1))
#define Generic_Output_3_Link_3_on (*(CONST U08 * )(&Page_Ptr[14][445]) & ((2<<1)-1))
#define Generic_Output_3_Link2_3_on_set (*(CONST S16 * )(&Page_Ptr[14][446]))
#define Generic_Output_3_Link_3_off (*(CONST U08 * )(&Page_Ptr[14][448]) & ((2<<1)-1))
#define Generic_Output_3_Link_3_off_set (*(CONST S16 * )(&Page_Ptr[14][450]))
#define Generic_Output_3_Link_4 (*(CONST U08 * )(&Page_Ptr[14][452]) & ((2<<2)-1))
#define Generic_Output_3_Link_4_on (*(CONST U08 * )(&Page_Ptr[14][453]) & ((2<<1)-1))
#define Generic_Output_3_Link_4_on_set (*(CONST S16 * )(&Page_Ptr[14][454]))
#define Generic_Output_3_Link_4_off (*(CONST U08 * )(&Page_Ptr[14][456]) & ((2<<1)-1))
#define Generic_Output_3_Link_4_off_set (*(CONST S16 * )(&Page_Ptr[14][458]))
#define Generic_Output_3_PWM_Table ((CONST struct table_jz * )(&Page_Ptr[14][460]))
#define Generic_Output_3_Link_1_PWM_Frequency (*(CONST S16 * )(&Page_Ptr[14][628])) 
#define Generic_Output_3_Link_1_PWM_Dutycycle (*(CONST S16 * )(&Page_Ptr[14][630]))
#define Generic_Output_3_Link_1_PWM_setpoint (*(CONST S16 * )(&Page_Ptr[14][632]))
#define Generic_Output_3_Link_1_PWM_proportional (*(CONST S16 * )(&Page_Ptr[14][634]))
#define Generic_Output_3_Link_1_PWM_integral (*(CONST S16 * )(&Page_Ptr[14][636]))
#define Generic_Output_3_Link_1_PWM_differential (*(CONST S16 * )(&Page_Ptr[14][638])) 
#define Generic_Output_3_Link_1_PWM_hysteresis (*(CONST S16 * )(&Page_Ptr[14][640]))
#define Generic_Output_4_Link_1 (*(CONST U08 * )(&Page_Ptr[14][642]) & ((2<<2)-1))
#define Generic_Output_4_Link_1_on (*(CONST U08 * )(&Page_Ptr[14][643]) & ((2<<1)-1))
#define Generic_Output_4_Link_1_on_set (*(CONST S16 * )(&Page_Ptr[14][644]))
#define Generic_Output_4_Link_1_off (*(CONST U08 * )(&Page_Ptr[14][646]) & ((2<<1)-1))
#define Generic_Output_4_type (*(CONST U08 * )(&Page_Ptr[14][647]) & ((2<<3)-1))
#define Generic_Output_4_Link_1_off_set (*(CONST S16 * )(&Page_Ptr[14][648]))
#define Generic_Output_4_Link_2 (*(CONST U08 * )(&Page_Ptr[14][650]) & ((2<<2)-1))
#define Generic_Output_4_Link_2_on (*(CONST U08 * )(&Page_Ptr[14][651]) & ((2<<1)-1))
#define Generic_Output_4_Link_2_on_set (*(CONST S16 * )(&Page_Ptr[14][652]))
#define Generic_Output_4_Link_2_off (*(CONST U08 * )(&Page_Ptr[14][654]) & ((2<<1)-1))
#define Generic_Output_4_Link_2_off_set (*(CONST S16 * )(&Page_Ptr[14][656]))
#define Generic_Output_4_Link_3 (*(CONST U08 * )(&Page_Ptr[14][658]) & ((2<<2)-1))
#define Generic_Output_4_Link_3_on (*(CONST U08 * )(&Page_Ptr[14][659]) & ((2<<1)-1))
#define Generic_Output_4_Link2_3_on_set (*(CONST S16 * )(&Page_Ptr[14][660]))
#define Generic_Output_4_Link_3_off (*(CONST U08 * )(&Page_Ptr[14][666]) & ((2<<1)-1))
#define Generic_Output_4_Link_3_off_set (*(CONST S16 * )(&Page_Ptr[14][667]))
#define Generic_Output_4_Link_4 (*(CONST U08 * )(&Page_Ptr[14][668]) & ((2<<2)-1))
#define Generic_Output_4_Link_4_on (*(CONST U08 * )(&Page_Ptr[14][670]) & ((2<<1)-1))
#define Generic_Output_4_Link_4_on_set (*(CONST S16 * )(&Page_Ptr[14][672]))
#define Generic_Output_4_Link_4_off (*(CONST U08 * )(&Page_Ptr[14][674]) & ((2<<1)-1))
#define Generic_Output_4_Link_4_off_set (*(CONST S16 * )(&Page_Ptr[14][676]))
#define Generic_Output_4_PWM_Table ((CONST struct table_jz * )(&Page_Ptr[14][678]))
#define Generic_Output_4_Link_1_PWM_Frequency (*(CONST S16 * )(&Page_Ptr[14][842])) 
#define Generic_Output_4_Link_1_PWM_Dutycycle (*(CONST S16 * )(&Page_Ptr[14][844]))
#define Generic_Output_4_Link_1_PWM_setpoint (*(CONST S16 * )(&Page_Ptr[14][846]))
#define Generic_Output_4_Link_1_PWM_proportional (*(CONST S16 * )(&Page_Ptr[14][848]))
#define Generic_Output_4_Link_1_PWM_integral (*(CONST S16 * )(&Page_Ptr[14][850]))
#define Generic_Output_4_Link_1_PWM_differential (*(CONST S16 * )(&Page_Ptr[14][852])) 
#define Generic_Output_4_Link_1_PWM_hysteresis (*(CONST S16 * )(&Page_Ptr[14][854]))
// ---------------------------------------------------
// Below here does not come from the .ini file

// A page is 2048 bytes, a block is 128K.  
// Only one block is in use at a time. This allows a flip/flop use/erase & burn strategy

#define MAX_PAGE_SIZE 2048    /**< self imposed. tuner has no say in this */

// Current flash or ram location of each page
extern volatile uint8_t *Page_Ptr[NPAGES];
extern int8_t Ram_Page_Buffer_Page;	// which page # is in the buffer (-1 means none)
extern int Flash_OK;		// is flash empty or has values
extern uint8_t Burn_Count;		// how many flash burns 

// This 8 byte (not counting directory) structure is written as a header to the beginning of a used flash block
struct Flash_Header {
    uint8_t Cookie[4];          // set to ABCD to indicate block is not blank
    uint8_t Burn_Count;        	// how many flash burns, used to pick 'newest' on powerup
} ;

#define BLOCK_HEADER_SIZE       1024U    // bigger than needed

extern uint8_t Flash_Block;		// flash block currently being used
extern uint8_t *Flash_Addr[2];

// ------------------

#endif

