
/*


V1.1	2017-01-08 nightcat
1. Motors library version 1.1 . all motors add to here .

*/

#ifndef Motors_H
#define Motors_H


#define _CLUB_MOTOR 1  //Added by nightcat , for _CLUB_MOTOR 


#ifdef _NAMIKI_MOTOR
	#define	 TRIGGER CHANGE
	#define  CPR 4	// Namiki motor
	#define  DIR_INVERSE
	#define  REDUCTION_RATIO 80
//_NEXUS_MOTOR Added by nightcat 2017-01-3 	
#elif _NEXUS_MOTOR
	#define	 TRIGGER CHANGE
	#define  CPR 8	// nexus motor
	#define  DIR_INVERSE !
	#define  REDUCTION_RATIO 80
	
#elif _CLUB_MOTOR
	#define	 TRIGGER CHANGE
	#define  CPR 13	// 
	#define  DIR_INVERSE !
	#define  REDUCTION_RATIO 30
	#define  WHEELSPAN   650    //mm
	#define  WHEELDIAMETER  230 //mm
	
#elif _FAULHABER_MOTOR
	#define	 TRIGGER RISING
	#define  CPR 12	// Faulhaber motor
	#define  DIR_INVERSE !
	#define  REDUCTION_RATIO 64
	
#else                             //default as _CLUB_MOTOR
	#define  TRIGGER CHANGE
	#define  CPR 13  
	#define  DIR_INVERSE !
	#define  REDUCTION_RATIO 30
	#define WHEELSPAN        650   //mm
	#define WHEELDIAMETER    230   //mm
	

#endif


#endif

