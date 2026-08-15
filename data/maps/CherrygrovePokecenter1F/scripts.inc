CherrygrovePokecenter1F_MapScripts::
	.byte 0

CherrygrovePokecenter1F_EventScript_Nurse::
	msgbox CherrygrovePokecenter1F_Text_Nurse, MSGBOX_NPC
	end

CherrygrovePokecenter1F_EventScript_Fisher::
	msgbox CherrygrovePokecenter1F_Text_Fisher, MSGBOX_NPC
	end

CherrygrovePokecenter1F_EventScript_Gentleman::
	msgbox CherrygrovePokecenter1F_Text_Gentleman, MSGBOX_NPC
	end

CherrygrovePokecenter1F_EventScript_Teacher::
	msgbox CherrygrovePokecenter1F_Text_Teacher, MSGBOX_NPC
	end

CherrygrovePokecenter1F_Text_Nurse:
	.string "They say the HOENN champion's\njourney is just getting started.\lWonder where they'll go next.$"

CherrygrovePokecenter1F_Text_Fisher:
	.string "It's great. I can\nstore any number\pof POKéMON, and\nit's all free.$"

CherrygrovePokecenter1F_Text_Gentleman:
	.string "That PC is free\nfor any trainer\lto use.$"

CherrygrovePokecenter1F_Text_Teacher:
	.string "JOHTO's changed a lot since the\nHOENN champion opened the sea\lroutes here.$"
