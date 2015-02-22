#include <EV3bytecode.h>

/*
*- Helper function to pack parameters - always to const parameters -
*- This is to pack parameters back into a string ready for Daisy
*- chain transmission
*
*  @param  (DATA8)   Val     - 32 bit value you would like to pack
*  @param  (DATA8*)  pStr    - String pointer where to pack the 32 bit Val
*/
UBYTE      cOutputPackParam(DATA32 Val, DATA8 *pStr) {
	DATA8   Len;

	Len = 0;
	if ((Val < 32) && (Val > -32)) {
		pStr[Len] = (DATA8)(Val & 0x0000003F);
		Len++;
	} else {
		if ((Val < DATA8_MAX) && (Val > DATA8_MIN)) {
			pStr[Len] = 0x81;
			Len++;
			pStr[Len] = (DATA8)Val;
			Len++;
		} else {
			if ((Val < DATA16_MAX) && (Val > DATA16_MIN)) {
				pStr[Len] = 0x82;
				Len++;
				((UBYTE*)pStr)[Len] = (UBYTE)(Val & 0x00FF);
				Len++;
				((UBYTE*)pStr)[Len] = (UBYTE)((Val >> 8) & 0x00FF);
				Len++;
			} else {
				pStr[Len] = 0x83;
				Len++;
				((UBYTE*)pStr)[Len] = (UBYTE)(Val & 0x000000FF);
				Len++;
				((UBYTE*)pStr)[Len] = (UBYTE)((Val >>  8) & 0x000000FF);
				Len++;
				((UBYTE*)pStr)[Len] = (UBYTE)((Val >> 16) & 0x000000FF);
				Len++;
				((UBYTE*)pStr)[Len] = (UBYTE)((Val >> 24) & 0x000000FF);
				Len++;
			}
		}
	}
	return Len;
}
