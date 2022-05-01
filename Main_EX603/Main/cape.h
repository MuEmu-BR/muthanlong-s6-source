#pragma once

#define sub_4DB230					((LPVOID(*)())0x4DB230)
#define sub_402BC0					((LPVOID(*)())0x402BC0)
#define sub_57D9A0					((DWORD(__cdecl*)(DWORD)) 0x57D9A0)
#define sub_58AA80					((DWORD(__cdecl*)(DWORD)) 0x58AA80)

class CCapeAnimation
{
public:
	CCapeAnimation();
	virtual ~CCapeAnimation();
	void Load();
	static void ModelEffectRender(DWORD ObjectPointer,DWORD ObjectModel, DWORD a3);
	static void DrawViewPort(DWORD ObjectPointer, DWORD ModelPointer, DWORD a3);
	
};

extern CCapeAnimation gCapeAnimation;