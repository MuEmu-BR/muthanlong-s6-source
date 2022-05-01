#pragma once
#include "defines.h"
#include "Protocol.h"
#include "NewInterface.h"

struct PMSG_SERVER_INFO_RECV
{
	PSBMSG_HEAD	header;
	// ----
	int CustomCharInterface[MAX_ACCOUNT_LEVEL];
	int CanOpenSettings[MAX_ACCOUNT_LEVEL];
	int CanOpenMain[MAX_ACCOUNT_LEVEL];
	int MaxStatPoint[MAX_ACCOUNT_LEVEL];
	int DamageMasterReset;
	int DefenseMasterReset;
	int CustomWarehouseAnimated;
	int Strength;
	int Dexterity;
	int Vitality;
	int Energy;
	int Leadership;
	int PartyTeleportSwitch;
	int PartyTeleportMoney;
};

enum eSettingsValue
{
	/*SETTINGS_SEPARATE_CHAT = 0,
	SETTINGS_HEALTH_BAR = 1,
	SETTINGS_3D_CAMERA = 2,*/
	SETTINGS_MINI_MAP = 0,
	SETTINGS_GRAPHICS = 1,
	SETTINGS_TIME = 2,
	SETTINGS_FOG = 3,
	SETTINGS_QUEST_WINDOW = 4,
};

struct SETTINGS_INFO
{
	bool m_separate_chat;
	bool m_hp_bar;
	bool m_3d_camera;
	bool m_mini_map;
	bool m_graphics;
	bool m_time;
	bool m_fog;
	bool m_quest_window;
};

class CServerInfo
{
public:
	CServerInfo();
	void Load();
	void RecvServerInfo(PMSG_SERVER_INFO_RECV* Data);
	SETTINGS_INFO* get() { return &m_settings_; };
	int get_char_interface(int AccountLevel);
	int get_max_stat_point(int AccountLevel);

	int get_strength() const { return this->m_strength_; }
	int get_dexterity() const { return this->m_dexterity_; }
	int get_vitality() const { return this->m_vitality_; }
	int get_energy() const { return this->m_energy_; }
	int get_leadership() const { return this->m_leadership_; }

	int m_PartyTeleportSwitch;
	int m_PartyTeleportMoney;

	int AnimatedWarehouse;


	int DisableStaticEffect;
	int DisableDynamicEffect;
	int DisableSkillEffect;
	int DisableGlowEffect;

	MU_4float MenuBackground;
	MU_4float MenuButton;
	MU_4float MenuButtonHover;
	MU_4float MenuButtonClick;


private:
	SETTINGS_INFO m_settings_;
	/*int m_separate_chat_;
	int m_hp_bar_;
	int m_3d_camera_;
	int m_mini_map_;
	int m_graphics_;
	int m_time_;
	int m_fog_;*/
	int m_custom_char_interface_[MAX_ACCOUNT_LEVEL];
	int m_max_stat_point_[MAX_ACCOUNT_LEVEL];
	int m_strength_;
	int m_dexterity_;
	int m_vitality_;
	int m_energy_;
	int m_leadership_;
	long long m_time_diff_;

}; extern CServerInfo gServerInfo;