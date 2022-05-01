#pragma once

#if(DKTK1 == 1)

class CTextBoxController
{
public:
	static short GetSymbolFromVK(WPARAM wParam);
	bool ControlTextBox(KBDLLHOOKSTRUCT Hook);
}; extern CTextBoxController gTextBoxController;

#endif