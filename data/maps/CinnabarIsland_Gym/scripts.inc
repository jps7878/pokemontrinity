CinnabarIsland_Gym_MapScripts::
	.byte 0

CinnabarIsland_Gym_EventScript_Quinn::
	trainerbattle_single TRAINER_KANTO_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnSeen, CinnabarIsland_Gym_Text_QuinnBeaten
	msgbox CinnabarIsland_Gym_Text_QuinnBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Erik::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_ERIK, CinnabarIsland_Gym_Text_ErikSeen, CinnabarIsland_Gym_Text_ErikBeaten
	msgbox CinnabarIsland_Gym_Text_ErikBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Avery::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AverySeen, CinnabarIsland_Gym_Text_AveryBeaten
	msgbox CinnabarIsland_Gym_Text_AveryBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Ramon::
	trainerbattle_single TRAINER_KANTO_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonSeen, CinnabarIsland_Gym_Text_RamonBeaten
	msgbox CinnabarIsland_Gym_Text_RamonBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Derek::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekSeen, CinnabarIsland_Gym_Text_DerekBeaten
	msgbox CinnabarIsland_Gym_Text_DerekBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Dusty::
	trainerbattle_single TRAINER_KANTO_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustySeen, CinnabarIsland_Gym_Text_DustyBeaten
	msgbox CinnabarIsland_Gym_Text_DustyBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_Zac::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacSeen, CinnabarIsland_Gym_Text_ZacBeaten
	msgbox CinnabarIsland_Gym_Text_ZacBeaten, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_GymGuy::
	msgbox CinnabarIsland_Gym_Text_GymGuy, MSGBOX_NPC
	end

CinnabarIsland_Gym_EventScript_GymStatue::
	msgbox CinnabarIsland_Gym_Text_GymStatue, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_GymStatue_2::
	msgbox CinnabarIsland_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz1Left::
	msgbox CinnabarIsland_Gym_Text_Quiz1Left, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz1Right::
	msgbox CinnabarIsland_Gym_Text_Quiz1Right, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz2Left::
	msgbox CinnabarIsland_Gym_Text_Quiz2Left, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz2Right::
	msgbox CinnabarIsland_Gym_Text_Quiz2Right, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz3Left::
	msgbox CinnabarIsland_Gym_Text_Quiz3Left, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz3Right::
	msgbox CinnabarIsland_Gym_Text_Quiz3Right, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz4Left::
	msgbox CinnabarIsland_Gym_Text_Quiz4Left, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz4Right::
	msgbox CinnabarIsland_Gym_Text_Quiz4Right, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz5Left::
	msgbox CinnabarIsland_Gym_Text_Quiz5Left, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz5Right::
	msgbox CinnabarIsland_Gym_Text_Quiz5Right, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz6Left::
	msgbox CinnabarIsland_Gym_Text_Quiz6Left, MSGBOX_SIGN
	end

CinnabarIsland_Gym_EventScript_Quiz6Right::
	msgbox CinnabarIsland_Gym_Text_Quiz6Right, MSGBOX_SIGN
	end

CinnabarIsland_Gym_Text_QuinnSeen:
	.string "…$"

CinnabarIsland_Gym_Text_QuinnBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_ErikSeen:
	.string "…$"

CinnabarIsland_Gym_Text_ErikBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_AverySeen:
	.string "…$"

CinnabarIsland_Gym_Text_AveryBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_RamonSeen:
	.string "…$"

CinnabarIsland_Gym_Text_RamonBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_DerekSeen:
	.string "…$"

CinnabarIsland_Gym_Text_DerekBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_DustySeen:
	.string "…$"

CinnabarIsland_Gym_Text_DustyBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_ZacSeen:
	.string "…$"

CinnabarIsland_Gym_Text_ZacBeaten:
	.string "…$"

CinnabarIsland_Gym_Text_GymGuy:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

CinnabarIsland_Gym_Text_GymStatue:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CinnabarIsland_Gym_Text_GymStatue_2:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CinnabarIsland_Gym_Text_Quiz1Left:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CinnabarIsland_Gym_Text_Quiz1Right:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CinnabarIsland_Gym_Text_Quiz2Left:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CinnabarIsland_Gym_Text_Quiz2Right:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CinnabarIsland_Gym_Text_Quiz3Left:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

CinnabarIsland_Gym_Text_Quiz3Right:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

CinnabarIsland_Gym_Text_Quiz4Left:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CinnabarIsland_Gym_Text_Quiz4Right:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CinnabarIsland_Gym_Text_Quiz5Left:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CinnabarIsland_Gym_Text_Quiz5Right:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

CinnabarIsland_Gym_Text_Quiz6Left:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CinnabarIsland_Gym_Text_Quiz6Right:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"
