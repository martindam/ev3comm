#ifndef LMSTYPES_H_
#define LMSTYPES_H_

//        BASIC DATA TYPES
typedef   unsigned char         	UBYTE;  		//!< Basic Type used to symbolise 8  bit unsigned values
typedef   unsigned short        	UWORD;  	//!< Basic Type used to symbolise 16 bit unsigned values
typedef   unsigned int          		ULONG;  	//!< Basic Type used to symbolise 32 bit unsigned values

typedef   signed char          		 SBYTE;  		//!< Basic Type used to symbolise 8  bit signed values
typedef   signed short         	 	 SWORD;  	//!< Basic Type used to symbolise 16 bit signed values
typedef   signed int            		 SLONG;  	//!< Basic Type used to symbolise 32 bit signed values

typedef   float                 			 FLOAT;  		//!< Basic Type used to symbolise 32 bit floating point values

//        VM DATA TYPES
typedef   SBYTE                 			DATA8;  		//!< VM Type for 1 byte signed value
typedef   SWORD                 		DATA16; 	//!< VM Type for 2 byte signed value
typedef   SLONG                 			DATA32; 	//!< VM Type for 4 byte signed value
typedef   FLOAT                 			DATAF;  		//!< VM Type for 4 byte floating point value

#endif
