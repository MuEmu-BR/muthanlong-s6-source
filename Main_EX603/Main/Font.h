#pragma once

class CFont
{
public:
	CFont(TCHAR* Name, int Size, int Weight, BOOL bItalic, BOOL bUnderline);
	~CFont();
	HGDIOBJ m_Font;
};

extern CFont* gFont[100];

void InitFonts();

enum FONT_TYPE {
	ARIAL_8,
	ARIAL_10,
	ARIAL_12,
	ARIAL_14,
	ARIAL_15,
	ARIAL_16,
	ARIAL_20,
	ARIAL_22,
	ARIAL_24,

	ARIAL_BLACK_10,
	ARIAL_BLACK_11,
	ARIAL_BLACK_12,
	ARIAL_BLACK_13,
	ARIAL_BLACK_14,
	ARIAL_BLACK_15,
	ARIAL_BLACK_16,
	ARIAL_BLACK_24,

	ARIAL_UNDERLINE_10,
	ARIAL_UNDERLINE_12,
	ARIAL_UNDERLINE_14,
	ARIAL_UNDERLINE_15,
	ARIAL_UNDERLINE_16,

	ARIAL_ITALIC_10,
	ARIAL_ITALIC_12,
	ARIAL_ITALIC_14,
	ARIAL_ITALIC_15,
	ARIAL_ITALIC_16,
};