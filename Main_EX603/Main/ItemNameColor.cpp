#include "stdafx.h"
#include "Item.h"
#include "TMemory.h"
#include "Import.h"
#include "ItemNameColor.h"
#include "Util.h"
#include "Defines.h"
//--
DWORD DivineWeapon_Buff = 0;
DWORD DivineWeapon_Pointer = 0;
//--
__declspec(naked)void DivineWeapon()
{
	static DWORD DivineWeaponAdress1 = 0x007E785F;
	static DWORD DivineWeaponAdress2 = 0x007E7866;
	_asm
	{
		Mov DivineWeapon_Buff, Edx
			MOVSX EDX, WORD PTR SS : [EBP + 0x8]
			mov DWORD PTR SS : [EBP + 0x8], Edx
			mov DivineWeapon_Pointer, Edx
			Mov Edx, DivineWeapon_Buff
	}
	if (DivineWeapon_Pointer == 0x13
		|| DivineWeapon_Pointer == 0x812
		|| DivineWeapon_Pointer == 0x0A0A
		|| DivineWeapon_Pointer == 0x40D
		|| DivineWeapon_Pointer == 0x0A24
		//--
		//--
		|| DivineWeapon_Pointer == ITEM(0, 51)	//->
		|| DivineWeapon_Pointer == ITEM(0, 53)	//->
		|| DivineWeapon_Pointer == ITEM(0, 106)	//->
		|| DivineWeapon_Pointer == ITEM(0, 412)	//->
		|| DivineWeapon_Pointer == ITEM(0, 413)	//->
		|| DivineWeapon_Pointer == ITEM(2, 25)	//->
		|| DivineWeapon_Pointer == ITEM(4, 30)	//->
		|| DivineWeapon_Pointer == ITEM(4, 33)	//->
		|| DivineWeapon_Pointer == ITEM(5, 49)	//->
		|| DivineWeapon_Pointer == ITEM(5, 50)	//->

		)
	{
		_asm{Jmp DivineWeaponAdress1}
	}
	else
	{
		_asm{Jmp DivineWeaponAdress2}
	}
}
//--
DWORD DropColorProtect;
DWORD DropColorPointer;
//--
__declspec(naked)void DropColor()
{
	_asm
	{
		Mov DropColorProtect, Eax
			MOV EDX, DWORD PTR SS : [EBP - 0x18]
			Mov Eax, DWORD PTR DS : [EDX + 0x30]
			Mov DropColorPointer, Eax
			Mov Eax, DropColorProtect
	}
	if (DropColorPointer == 0x253B)
	{
		_asm{
			Mov DropColorPointer, 0x005F47AA // Orange
				Jmp DropColorPointer
		}
	}
	//----
	else if (DropColorPointer == ITEM2(5, 49))
	{		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer ==  ITEM2(0, 51))
	{		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer == ITEM2(0, 53))
	{
		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer == ITEM2(4, 30))
	{		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer == ITEM2(4, 33))
	{
		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer == ITEM2(2, 25))
	{		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer == ITEM2(5, 50))
	{		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if (DropColorPointer == ITEM2(0, 106))
	{
		_asm		{
			Mov DropColorPointer, 0x005F4918 // Purple
				Jmp DropColorPointer		}
	}
	//----
	else if
		(DropColorPointer == ITEM2(14, 14))
	{		_asm		{
			mov DropColorPointer, 0x005F439E//Yellow
				jmp DropColorPointer		}
	}
	else
	{
		_asm{
			Mov DropColorPointer, 0x005F47BC//Next
				Jmp DropColorPointer
		}
	}
}
//--
void InitCustomNameColor()
{
	SetRange((LPVOID)0x007E7827, 4, ASM::NOP);
	SetOp((LPVOID)0x007E7827, (LPVOID)DivineWeapon, ASM::JMP);
	//--
	SetRange((LPVOID)0x005F479E, 10, ASM::NOP);
	SetOp((LPVOID)0x005F479E, (LPVOID)DropColor, ASM::JMP);
}