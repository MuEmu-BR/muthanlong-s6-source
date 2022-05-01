#include "stdafx.h"
#include "CustomNpcName.h"
#include "Offset.h"
#include "User.h"
#include "TMemory.h"
#include "Interface.h"
#include "Protocol.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "Util.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Camera.h"
#include "ServerInfo.h"
#include "Common.h"
#include "HealthBar.h"

User gObjUser;

DWORD LastTime = 0;

void User::Load()
{
	#if(DEV_DAMAGE_TABLE)
	this->m_SecondDamageMax = 0;
	this->m_SecondDamage = 0;
	this->m_SecondDefence = 0;
	this->m_SecondReflect = 0;
	#endif
	this->m_TargetUpdateTick	= 0;
	this->m_TargetType			= false;
	this->m_CursorX				= -1;
	this->m_CursorY				= -1;
	this->m_MapNumber			= -1;
	//Auto Move
	this->IsSendMove = 0;
	this->MoveToX = 0;
	this->MoveToY = 0;
	this->KhongDiDuoc = 0;
	//===========================
	this->m_QuestStat			= 0;
	ZeroMemory(this->m_reset_item_check, sizeof(this->m_reset_item_check));

	SetCompleteHook(0xFF, 0x0077F822, &this->ChangeCharInfo);

	SetCompleteHook(0xFF, 0x00520ECF, &this->GetMapName);
	SetCompleteHook(0xFF, 0x00520F1F, &this->GetMapName);
	SetCompleteHook(0xFF, 0x0063E743, &this->GetMapName);
	SetCompleteHook(0xFF, 0x00640EB2, &this->GetMapName);
	SetCompleteHook(0xFF, 0x007D2DD9, &this->GetMapName);
	SetCompleteHook(0xFF, 0x007E6C0F, &this->GetMapName);
	SetCompleteHook(0xFF, 0x0084AEF7, &this->GetMapName);
	//==========

	SetOp((LPVOID)0x0057D513, (LPVOID)this->ShowModelBMD, ASM::CALL); //An NHan Vat
	SetOp((LPVOID)0x0057D4FF, (LPVOID)this->ShowModelBMD, ASM::CALL);//An NHan Vat

	SetOp((LPVOID)0x00588511, (LPVOID)User::HoolCreateManyFlay, ASM::CALL);
}
#define preturnModel						((bool(__cdecl*)(int a1, int a2, int a3)) 0x0056F210)
bool User::ShowModelBMD(int a1, int a2, int a3) //An Nguoi Choi OK
{
	int result; // eax

	if (DisablePlayer == 1 && pPlayerState == 5 && oUserPreviewStruct != a1 && (*(BYTE *)(a2 + 24) == 1))
		result = 0;
	else
		result = preturnModel(a1, a2, a3);
	return result;
}
void User::Refresh()
{
	
	this->lpPlayer			= &*(ObjectCharacter*)oUserObjectStruct;
	this->lpViewPlayer		= &*(ObjectPreview*)oUserPreviewStruct;
	this->GetTarget();

	this->m_CursorX			= pCursorX;
	this->m_CursorY			= pCursorY;
	this->m_MapNumber		= pMapNumber;

	if (pMapNumber == 62)
	{
		//gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}

	this->CoordenadaX = this->lpViewPlayer->MapPosX;
	this->CoordenadaY = this->lpViewPlayer->MapPosY;
	this->getLevel = gObjUser.lpPlayer->Level;
	this->GetPet = this->lpViewPlayer->PetSlot;


	this->InSafeZone = this->lpViewPlayer->InSafeZone;

	sprintf(this->getName,"%s",gObjUser.lpPlayer->Name);

	if ( gObjUser.GetActiveSkill() == 261 || 
		gObjUser.GetActiveSkill() == 552 || 
		gObjUser.GetActiveSkill() == 555 )
	{
		SetDouble(&pFrameSpeed1, 0.0004000);
		SetDouble(&pFrameSpeed2, 0.0002000);
	}
	else
	{
		SetDouble(&pFrameSpeed1, 0.0040000);
		SetDouble(&pFrameSpeed2, 0.0020000);
	}

	if (gProtect.m_MainInfo.AntiHackOnOff == 1)
	{
		if (GetModuleHandle(gProtect.m_MainInfo.HackName) == 0)
		{
			ExitProcess(100); // 5 giây
		}
	}
}

bool User::GetTarget()
{
	if( pViewNPCTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID);

		this->m_TargetType	= 1;
		return true;
	}
	else if( pViewAttackTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);
		this->m_TargetType	= 2;
		return true;
	}
	
	if( this->lpViewTarget != 0 )
	{
		ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	}
	
	this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
 lpCharObj lpPlayer  = &*(ObjectCharacter*)*(int*)(MAIN_CHARACTER_STRUCT);
 lpViewObj lpViewPlayer  = &*(ObjectPreview*)*(int*)(MAIN_VIEWPORT_STRUCT);
 return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
}

void User::SetEventEffect(int PreviewStruct)
{

	lpViewObj lpPreview = &*(ObjectPreview*)PreviewStruct;

	if(lpPreview)
	{
		if(*(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
		{
			if (lpPreview->m_Model.ObjectType == emPlayer)
			{
					VAngle Angle;
					int PosX;
					int PosY;

					Angle.X = *(float*)(PreviewStruct+0x404);

					Angle.Y = *(float*)(PreviewStruct+0x408);

					Angle.Z = *(float*)(PreviewStruct+0x40C) + *(float*)(PreviewStruct+0x3E8) + 100.0f;

					pGetPosFromAngle(&Angle, &PosX, &PosY);
			}
		}
	}

	// ----
	if( lpPreview->CtlCode == 32 )
	{
		if( *(DWORD*)(PreviewStruct + 672) && lpPreview->Unknown23 != 5 )
		{
			pInitEventStatus(PreviewStruct);
		}
		// ----
		lpPreview->Unknown23 = 5;
	}
	// ----
	if( *(DWORD*)(PreviewStruct + 672) != 0 || !lpPreview->Unknown23 )
	{
		return;
	}
	// ----
	switch(lpPreview->Unknown23)
	{
	case 5:	//-> GM
		{
			if( pEventEffectThis(668) )
			{
				DWORD ModelID = 349;
				// ----
				if( !strncmp(lpPreview->Name, "[GM]", 4) )
				{
					ModelID = 406;
				}
				else if( !strncmp(lpPreview->Name, "[EM]", 4) )
				{
					ModelID = 407;
				}
				else if( !strcmp(lpPreview->Name, "Admin") )
				{
					ModelID = 408;
				}

				// ----
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect(pEventEffectThis(668), ModelID, 20, 1, 70.0, -5.0, 0.0, 0.0, 0.0, 45.0);
			}
		}
		break;
		// --
	case 6:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 0, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 7:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 1, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 8:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 2, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 9:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 3, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 10:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 4, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 11:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 5, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 12:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 6, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 13:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 7, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
	default:
		{
			lpPreview->Unknown23 = 0;
		}
		break;
	}
}

char* User::GetMapName(int MapNumber)
{
	if (MapNumber >= 83 && MapNumber <= 100)
	{
		return pGetTextLine(pTextLineThis, (3160 + MapNumber - 83));
	}
	return pGetMapName(MapNumber);
}

void User::ChangeCharInfo(LPVOID This)
{
	if (!gInterface.CheckWindow(Character))
	{
		return;
	}
	if (gServerInfo.get_char_interface(ViewAccountLevel))
	{
		gInterface.DrawText(eShinyGreen, 470, 58, 100, 1, "Level: %d", gObjUser.lpPlayer->Level);
		gInterface.DrawText(eExcellent, 470, 75, 100, 1, "Reset: %d", ViewReset);
		gInterface.DrawText(eExcellent, 470, 90, 100, 1, "Grand Reset: %d", ViewGReset);

		char Value[50];
		ZeroMemory(Value, sizeof(Value));
		pGetMoneyFormat((double)ViewPoint, Value, 0);
		GetFormat(Value, ',', ' ');

		gInterface.DrawFormat(eYellow, 500, 58, 100, 3, "Điểm : %s", Value);

	}
	else
	{
		((BOOL(__thiscall*)(LPVOID This))0x0077FAE0)(This);
	}
}

//User.cpp
void User::RenderRuneEffect(DWORD ObjectModel, int ID, int Type, float Z, float Size)
{
	MU3Float lBone;

	MU3Float lBone2;

	vec3_t Color;

	vec3_t ColorRandom;

	Vector(0.0, 0.8, 0.0, Color);

	Vector(((float)(rand() % 100) / 100), ((float)(rand() % 100) / 100), ((float)(rand() % 100) / 100), ColorRandom);

	lBone.X = *(float*)(ObjectModel + 252);

	lBone.Y = *(float*)(ObjectModel + 256);

	lBone.Z = *(float*)(ObjectModel + 260);

	lBone2.X = *(float*)(ObjectModel + 264);

	lBone2.Y = *(float*)(ObjectModel + 268);

	lBone2.Z = *(float*)(ObjectModel + 272);

	lBone.Z = lBone.Z + (float)(Z);

	lBone2.Z = lBone2.Z + (float)(Z);
	//32404 : Vong Xoay
	//32378 : AAA
	pSkillEffect(ID, (int)&lBone, (int)&lBone2, ColorRandom, Type, 0, -1, 0, 0, 0, Size, -1);

	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 0, 0, -1, 0, 0, 0, 2.0, -1);
	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 2, 0, -1, 0, 0, 0, 1.0, -1);
	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 2, 0, -1, 0, 0, 0, 0.2, -1);
	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 2, 0, -1, 0, 0, 0, 0.1, -1);
	//pCreateEffec(439, (int)&lBone, (int)&lBone2, ColorRandom, 1, 0, -1, 0, 0, 0, 0.60000002, -1);
	//pCreateEffec(440, (int)&lBone, (int)&lBone2, ColorRandom, 1, 0, -1, 0, 0, 0, 0.60000002, -1);
	//pCreateEffec(441, (int)&lBone, (int)&lBone2, ColorRandom, 1, 0, -1, 0, 0, 0, 0.60000002, -1);
	//pCreateEffec(32119, (int)&lBone, (int)&lBone2, ColorRandom, 0, 0, -1, 0, 0, 0, 0.5, -1);
	//pCreateEffec(32376, (int)&lBone, (int)&lBone2, ColorRandom, 0, 0, -1, 0, 0, 0, 1.0, -1);
}
bool User::UseHasMagicRing()
{
	DWORD  pCharData = *(DWORD*)MAIN_CHARACTER_STRUCT;
	if (pCharData)
	{
		for (size_t i = 0; i < 2; i++)
		{
				ObjectItem2* VuKhiRong = (ObjectItem2*)GetCharacterItem(i);
				//if (VKRONG->ItemID == ITEM(13, 20) && VKRONG->Opt.opt_level == 3)
				if (VuKhiRong->ItemID == ITEM(0, 51)
					|| VuKhiRong->ItemID == ITEM(0, 53)
					|| VuKhiRong->ItemID == ITEM(0, 106)
					|| VuKhiRong->ItemID == ITEM(2, 25)
					|| VuKhiRong->ItemID == ITEM(4, 30)
					|| VuKhiRong->ItemID == ITEM(4, 33)
					|| VuKhiRong->ItemID == ITEM(5, 49)
					|| VuKhiRong->ItemID == ITEM(5, 50))
				{
					return true;
				}
		}
	}
	return false;
}
bool User::CreateManyFlag(ObjectPreview * pChar)
{
	if (!pChar->Unknown764 && (pChar == (ObjectPreview *)*(DWORD*)MAIN_VIEWPORT_STRUCT && UseHasMagicRing() || PlayerHasManyFlag(pChar->aIndex)))
	{
		void* pMem = ((void*(__cdecl*)(int))(0x9D00C5))(668);
		pChar->Unknown764 = (DWORD)((void*(__thiscall*)(void *this1, int modeType, int ParentBoneIndex, bool bFllowParentRotate, float ox, float oy, float oz, float rx, float ry, float rz))(0x4EFFF0))
			(
			pMem, 348, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
		return true;
	}

	return false;
}
void User::HoolCreateManyFlay(ObjectPreview*  pChar)
{
	User::CreateManyFlag(pChar);
	((void(__cdecl*)(ObjectPreview*))(0x4EF9A0))(pChar);
}


