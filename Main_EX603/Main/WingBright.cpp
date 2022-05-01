#include "stdafx.h"
#include "WingBright.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "Import.h"
#include "Defines.h"
// ---------------------------------------------------------------------------------------------

Wings gWings;
// ---------------------------------------------------------------------------------------------

DWORD dwItemId;
DWORD dwWingThis;
DWORD dwWingStyle;
DWORD dwWingEff;
// ----
DWORD mdTmpEax;
DWORD mdTmpEsi;
DWORD mdTmpEdi;
DWORD mdTmpEcx;
DWORD mdTmpEdx;
DWORD mdTmpEbx;
DWORD mdTmpEbp;
DWORD mdTmpEsp;
// ---------------------------------------------------------------------------------------------
Naked(HieuUngBufferGlow)
{
	DWORD dwItem;
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x10]
			MOV dwItem, EAX
			// ----
			// wing 2.5
			CMP dwItem, ITEM2(12, 150)
			JE Return
			CMP dwItem, ITEM2(12, 151)
			JE Return
			CMP dwItem, ITEM2(12, 152)
			JE Return
			CMP dwItem, ITEM2(12, 153)
			JE Return
			// ----
			// wing 4
			CMP dwItem, ITEM2(12, 154)
			JE Return
			CMP dwItem, ITEM2(12, 155)
			JE Return
			CMP dwItem, ITEM2(12, 156)
			JE Return
			CMP dwItem, ITEM2(12, 157)
			JE Return
			CMP dwItem, ITEM2(12, 158)
			JE Return
			CMP dwItem, ITEM2(12, 159)
			JE Return
			CMP dwItem, ITEM2(12, 160)
			JE Return
			// ----
			// wing season 8
			CMP dwItem, ITEM2(12, 161)
			JE Return
			CMP dwItem, ITEM2(12, 162)
			JE Return
			// ----
		Return :
		MOV EAX, 0x005FF983
			JMP EAX
	}
}

void Wings::Load()
{
	//SetRange((LPVOID)0x005FAA38, 7, ASM::NOP);
	//SetOp((LPVOID)0x005FAA38, (LPVOID)CustomItemGlow, ASM::JMP);
	SetRange((LPVOID)0x005FF97C, 1, ASM::NOP);
	SetOp((LPVOID)0x005FF97C, HieuUngBufferGlow, ASM::JMP);
}
// ---------------------------------------------------------------------------------------------

