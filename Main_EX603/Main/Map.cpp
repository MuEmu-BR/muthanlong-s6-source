#include "stdafx.h"
#include "Map.h"
#include "CustomMap.h"
#include "Offset.h"
#include "Util.h"
#include "import.h"
#include "TMemory.h"
#include "Defines.h"

DWORD MapTextOffset        = 0x00402320;
DWORD MapJumpOffset        = 0x005D3027;
DWORD MapJumpOffset2        = 0x005D2D19;
DWORD MapReturnOffset    = 0x005D2C32;

_declspec(naked) void LoadNewTextMapName()
{
    _asm
    {
		CMP DWORD PTR SS:[EBP+0x8],0x22
		JNZ NextMapText1
		PUSH 0x73B
		MOV ECX,0x08128ADC
		CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
        // ---
        NextMapText1:
        // ---
        CMP DWORD PTR SS:[EBP+0x8],0x53       // Arkania MapId: 83
        JNZ NextMapText2
        PUSH 0xC65           // Text.bmd number line: 3160
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText2:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x54       // Arkania MapId: 84
        JNZ NextMapText3
        PUSH 0xC66           // Text.bmd number line: 3161
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText3:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x55       // Arkania MapId: 85
        JNZ NextMapText4
        PUSH 0xC67           // Text.bmd number line: 3162
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText4:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x56       // Arkania MapId: 86
        JNZ NextMapText5
        PUSH 0xC68           // Text.bmd number line: 3163
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText5:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x57       // Arkania MapId: 87
        JNZ NextMapText6
        PUSH 0xC69           // Text.bmd number line: 3164
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText6:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x58       // Arkania MapId: 88
        JNZ NextMapText7
        PUSH 0xC71           // Text.bmd number line: 3165
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText7:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x59       // Arkania MapId: 89
        JNZ NextMapText8
        PUSH 0xC72           // Text.bmd number line: 3166
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText8:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x5A       // Arkania MapId: 90
        JNZ NextMapText9
        PUSH 0xC73           // Text.bmd number line: 3167
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText9:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x5B       // Arkania MapId: 91
        JNZ NextMapText10
        PUSH 0xC74           // Text.bmd number line: 3168
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText10:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x5C       // Arkania MapId: 92
        JNZ NextMapText11
        PUSH 0xC75           // Text.bmd number line: 3169
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText11:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x5D       // Arkania MapId: 93
        JNZ NextMapText12
        PUSH 0xC76           // Text.bmd number line: 3170
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText12:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x5E       // Arkania MapId: 94
        JNZ NextMapText13
        PUSH 0xC77           // Text.bmd number line: 3171
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText13:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x5F       // Arkania MapId: 95
        JNZ NextMapText14
        PUSH 0xC78           // Text.bmd number line: 3172
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText14:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x60       // Arkania MapId: 96
        JNZ NextMapText15
        PUSH 0xC79           // Text.bmd number line: 3173
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText15:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x61       // Arkania MapId: 97
        JNZ NextMapText16
        PUSH 0xC80           // Text.bmd number line: 3174
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText16:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x62       // Arkania MapId: 98
        JNZ NextMapText17
        PUSH 0xC81           // Text.bmd number line: 3175
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText17:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x63       // Arkania MapId: 99
        JNZ NextMapText103
        PUSH 0xC82           // Text.bmd number line: 3176
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		// ---
		NextMapText103:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x67       // Arkania MapId: 103
        JNZ NextMapText104
        PUSH 0xC83           // Text.bmd number line: 3177
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
		NextMapText104:
        // ---
		CMP DWORD PTR SS:[EBP+0x8],0x68       // Arkania MapId: 104
        JNZ NextMapText18
        PUSH 0xC84           // Text.bmd number line: 3176
        MOV ECX,0x08128ADC
        CALL MapTextOffset
		JMP MapJumpOffset
		JMP MapJumpOffset2
		// ---
	NextMapText18:

		// ---
		CMP DWORD PTR SS : [EBP + 0x8], 0x64       // Arkania MapId: 100
			JNZ ReturnMapLoad
			PUSH 0xC85           // Text.bmd number line: 3177
			MOV ECX, 0x08128ADC
			CALL MapTextOffset
			JMP MapJumpOffset
			JMP MapJumpOffset2
		ReturnMapLoad :
		// ---

		//// ---
		//CMP DWORD PTR SS : [EBP + 0x8], 0x69       // 105
		//	JNZ NextMapText105
		//	PUSH 0xC86           // Text.bmd number line: 3177
		//	MOV ECX, 0x08128ADC
		//	CALL MapTextOffset
		//	JMP MapJumpOffset
		//	JMP MapJumpOffset2
		//	// ---
		//NextMapText105 :
  //      // ---



        JMP MapReturnOffset
    }
}

char * Map82 = "CustomMap1.tga";
char * Map83 = "CustomMap2.tga";
char * Map84 = "CustomMap3.tga";
char * Map85 = "CustomMap4.tga";
char * Map86 = "CustomMap5.tga";
char * Map87 = "CustomMap6.tga";
char * Map88 = "CustomMap7.tga";
char * Map89 = "CustomMap8.tga";
char * Map90 = "CustomMap9.tga";
char * Map91 = "CustomMap10.tga";
char * Map92 = "CustomMap11.tga";
char * Map93 = "CustomMap12.tga";
char * Map94 = "CustomMap13.tga";
char * Map95 = "CustomMap14.tga";
char * Map96 = "CustomMap15.tga";
char * Map97 = "CustomMap16.tga";
char * Map98 = "CustomMap17.tga";
char * Map99 = "CustomMap18.tga";
char * Map100 = "CustomMap19.tga";
char * Map103 = "CustomMap19.tga";
char * Map104 = "losttower.tga";
//char * Map105 = "CustomMap19.tga";

__declspec(naked) void LoadInterfaceMapName() // OK
{
	_asm
	{
			MOV DWORD PTR SS : [EBP - 0x848], 0x51
			PUSH 0x00D25498
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//--
			MOV DWORD PTR SS : [EBP - 0x848], 0x52
			PUSH Map82
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x53		// 83 Arkania Custom Map
			PUSH Map83								// Interface Name
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x54		// 84 Arkania Custom Map
			PUSH Map84								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x55		// 85 Arkania Custom Map
			PUSH Map85								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x56		// 86 Arkania Custom Map
			PUSH Map86								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x57		// 87 Arkania Custom Map
			PUSH Map87								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x58		// 88 Arkania Custom Map
			PUSH Map88								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x59		// 89 Arkania Custom Map
			PUSH Map89								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5A		// 90 Arkania Custom Map
			PUSH Map90								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5B		// 91 Arkania Custom Map
			PUSH Map91								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5C		// 92 Arkania Custom Map
			PUSH Map92								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5D		// 93 Arkania Custom Map
			PUSH Map93								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5E		// 94 Arkania Custom Map
			PUSH Map94								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5F		// 95 Arkania Custom Map
			PUSH Map95								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x60		// 96 Arkania Custom Map
			PUSH Map96								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x61		// 97 Arkania Custom Map
			PUSH Map97								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x62		// 98 Arkania Custom Map
			PUSH Map98								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x63		// 99 Arkania Custom Map
			PUSH Map99								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x64		// 100 Arkania Custom Map
			PUSH Map100								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			// ----
		//----
			MOV DWORD PTR SS:[EBP-0x848],0x67		// 103 Arkania Custom Map
			PUSH Map103								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			// ----
		//----
			MOV DWORD PTR SS:[EBP-0x848],0x68		// 104 Arkania Custom Map
			PUSH Map104								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			// ----
			////----
			//MOV DWORD PTR SS : [EBP - 0x848], 0x69		// 105
			//PUSH Map105								    // Interface Name 
			//LEA EAX, DWORD PTR SS : [EBP - 0x28]
			//PUSH EAX
			//LEA ECX, DWORD PTR SS : [EBP - 0x864]
			//PUSH ECX
			//CALL InterfaceLoad1
			//ADD ESP, 0x0C
			//MOV DWORD PTR SS : [EBP - 0xA74], EAX
			//MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			//MOV DWORD PTR SS : [EBP - 0xA78], EDX
			//MOV BYTE PTR SS : [EBP - 0x4], 0x43
			//MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			//PUSH EAX
			//LEA ECX, DWORD PTR SS : [EBP - 0x848]
			//PUSH ECX
			//MOV ECX, DWORD PTR SS : [EBP - 0x868]
			//ADD ECX, 0x4
			//CALL InterfaceLoad2
			//MOV ECX, EAX
			//CALL InterfaceLoad3
			//MOV BYTE PTR SS : [EBP - 0x4], 0x2
			//LEA ECX, DWORD PTR SS : [EBP - 0x864]
			//CALL InterfaceLoad4
			//MOV DWORD PTR SS : [EBP - 0x4], -0x1
			//LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//// ----

		CALL InterfaceLoad4
		MOV ECX, DWORD PTR SS : [EBP - 0xC]
		MOV DWORD PTR FS : [0x0], ECX

		MOV EDI, 0x0047FD08
			JMP EDI

		InterfaceLoad1 :
		MOV EDI, 0x0047C220
			JMP EDI

		InterfaceLoad2 :
		MOV EDI, 0x00480160
			JMP EDI

		InterfaceLoad3 :
		MOV EDI, 0x00409AF0
			JMP EDI

		InterfaceLoad4 :
		MOV EDI, 0x00409AD0
			JMP EDI

			MOV ESP, EBP
			POP EBP
			RETN
		}
}

char* LoadMapName(signed int MapNumber) //OK
{
	if (MapNumber >= 82)
	{
		CUSTOM_MAPS_INFO* lpInfo = gCustomMap.GetInfo(MapNumber);

		if(lpInfo != 0)
		{
			return lpInfo->Name;
		}
	}

	return pMapName(MapNumber);
}

void LoadMapMusic(HDC Arg1)  // OK
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		CUSTOM_MAPS_INFO* lpInfo = gCustomMap.GetInfo(pMapNumber);

		if(lpInfo != 0)
		{
			pWzAudioPlay(lpInfo->MusicFile,0);
		}
	}

	pLoadGameStuffs(Arg1);
}

void InitMap()  // OK
{
	SetCompleteHook(0xE8,0x00520ECF, &LoadMapName);
	SetCompleteHook(0xE8,0x00520F1F, &LoadMapName);
	SetCompleteHook(0xE8,0x0063E743, &LoadMapName);
	SetCompleteHook(0xE8,0x00640EB2, &LoadMapName);
	SetCompleteHook(0xE8,0x007D2DD9, &LoadMapName);
	SetCompleteHook(0xE8,0x007E6C0F, &LoadMapName);
	SetCompleteHook(0xE8,0x0084AEF7, &LoadMapName);

	SetCompleteHook(0xE9,0x005D2C13,&LoadNewTextMapName);

	SetRange((LPVOID)0x0047FC85, 131, ASM::NOP);
	SetCompleteHook(0xE9,0x0047FC85, &LoadInterfaceMapName);

	SetByte(0x0062EBF8,0xEB);
	SetByte(0x0062EBFE,0xEB);
	SetByte(0x0062EE42,0xEB);
	SetByte(0x0062EE48,0xEB);
	SetByte(0x0062EEE5,0xEB);
	SetByte(0x0062EEEB,0xEB);	
	SetByte(0x0062EBF7,0x69);
	SetByte(0x0062EE41,0x69);
	SetByte(0x0062EEE4,0x69);

	SetCompleteHook(0xE8,0x004DADA4,&LoadMapMusic);
}