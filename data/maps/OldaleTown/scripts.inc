OldaleTown_EventScript_Rayquaza::
# 2 "data/maps/OldaleTown/scripts.pory"
	lock
# 3 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 4 "data/maps/OldaleTown/scripts.pory"
	message OldaleTown_EventScript_Rayquaza_Text_0
# 5 "data/maps/OldaleTown/scripts.pory"
	waitmessage
# 6 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_HM_FLY
# 7 "data/maps/OldaleTown/scripts.pory"
	release
	end


# 11 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_MART_EMPLOYEE, 2
# 12 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_FOOTPRINTS_MAN, 3
# 13 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_RIVAL, 4
# 14 "data/maps/OldaleTown/scripts.pory"

# 15 "data/maps/OldaleTown/scripts.pory"
OldaleTown_MapScripts::
# 16 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
# 17 "data/maps/OldaleTown/scripts.pory"
	.byte 0
# 18 "data/maps/OldaleTown/scripts.pory"

# 19 "data/maps/OldaleTown/scripts.pory"
OldaleTown_OnTransition:
# 20 "data/maps/OldaleTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 21 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
# 22 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
# 23 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 24 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 25 "data/maps/OldaleTown/scripts.pory"
	end
# 26 "data/maps/OldaleTown/scripts.pory"

# 27 "data/maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
# 28 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState::
# 29 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 30 "data/maps/OldaleTown/scripts.pory"
	return
# 31 "data/maps/OldaleTown/scripts.pory"

# 32 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance::
# 33 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 34 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 35 "data/maps/OldaleTown/scripts.pory"
	return
# 36 "data/maps/OldaleTown/scripts.pory"

# 37 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee::
# 38 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
# 39 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 40 "data/maps/OldaleTown/scripts.pory"
	return
# 41 "data/maps/OldaleTown/scripts.pory"

# 42 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_TownSign::
# 43 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
# 44 "data/maps/OldaleTown/scripts.pory"
	end
# 45 "data/maps/OldaleTown/scripts.pory"

# 46 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Girl::
# 47 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
# 48 "data/maps/OldaleTown/scripts.pory"
	end
# 49 "data/maps/OldaleTown/scripts.pory"

# 50 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee::
# 51 "data/maps/OldaleTown/scripts.pory"
	lock
# 52 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 53 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 54 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 55 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 56 "data/maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 57 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 58 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 59 "data/maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 60 "data/maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 61 "data/maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 62 "data/maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 63 "data/maps/OldaleTown/scripts.pory"
	end
# 64 "data/maps/OldaleTown/scripts.pory"

# 65 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth::
# 66 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 67 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
# 68 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 69 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 70 "data/maps/OldaleTown/scripts.pory"
	end
# 71 "data/maps/OldaleTown/scripts.pory"

# 72 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth::
# 73 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 74 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
# 75 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 76 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 77 "data/maps/OldaleTown/scripts.pory"
	end
# 78 "data/maps/OldaleTown/scripts.pory"

# 79 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast::
# 80 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
# 81 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 82 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 84 "data/maps/OldaleTown/scripts.pory"
	end
# 85 "data/maps/OldaleTown/scripts.pory"

# 86 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart::
# 87 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 88 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_POTION
# 89 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
# 90 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 91 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 92 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 93 "data/maps/OldaleTown/scripts.pory"
	release
# 94 "data/maps/OldaleTown/scripts.pory"
	end
# 95 "data/maps/OldaleTown/scripts.pory"

# 96 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion::
# 97 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 98 "data/maps/OldaleTown/scripts.pory"
	release
# 99 "data/maps/OldaleTown/scripts.pory"
	end
# 100 "data/maps/OldaleTown/scripts.pory"

# 101 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull::
# 102 "data/maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 103 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 104 "data/maps/OldaleTown/scripts.pory"
	release
# 105 "data/maps/OldaleTown/scripts.pory"
	end
# 106 "data/maps/OldaleTown/scripts.pory"

# 107 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast:
# 108 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 109 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 110 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 111 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 112 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 113 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 114 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 116 "data/maps/OldaleTown/scripts.pory"
	step_end
# 117 "data/maps/OldaleTown/scripts.pory"

# 118 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth:
# 119 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 120 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 121 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 122 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 123 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 124 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 125 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 126 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 127 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 129 "data/maps/OldaleTown/scripts.pory"
	step_end
# 130 "data/maps/OldaleTown/scripts.pory"

# 131 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth:
# 132 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 133 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 135 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 136 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 137 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 138 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 139 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 140 "data/maps/OldaleTown/scripts.pory"
	step_end
# 141 "data/maps/OldaleTown/scripts.pory"

# 142 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown1:
# 143 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 144 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 145 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 146 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 147 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 148 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 149 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 150 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 151 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 152 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 153 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 154 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 155 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 156 "data/maps/OldaleTown/scripts.pory"
	step_end
# 157 "data/maps/OldaleTown/scripts.pory"

# 158 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast:
# 159 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 160 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 161 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 162 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 163 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 164 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 165 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 166 "data/maps/OldaleTown/scripts.pory"
	step_end
# 167 "data/maps/OldaleTown/scripts.pory"

# 168 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth:
# 169 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 170 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 171 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 172 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 173 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 174 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 175 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 176 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 177 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 178 "data/maps/OldaleTown/scripts.pory"
	step_end
# 179 "data/maps/OldaleTown/scripts.pory"

# 180 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth:
# 181 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 182 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 183 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 184 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 185 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 186 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 187 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 188 "data/maps/OldaleTown/scripts.pory"
	step_end
# 189 "data/maps/OldaleTown/scripts.pory"

# 190 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2:
# 191 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 192 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 193 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 194 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 195 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 196 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 197 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 198 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 199 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 200 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 201 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 202 "data/maps/OldaleTown/scripts.pory"
	step_end
# 203 "data/maps/OldaleTown/scripts.pory"

# 204 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan::
# 205 "data/maps/OldaleTown/scripts.pory"
	lock
# 206 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 207 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 208 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 209 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 210 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 211 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 212 "data/maps/OldaleTown/scripts.pory"
	release
# 213 "data/maps/OldaleTown/scripts.pory"
	end
# 214 "data/maps/OldaleTown/scripts.pory"

# 215 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath::
# 216 "data/maps/OldaleTown/scripts.pory"
	lockall
# 217 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 218 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 219 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 220 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 221 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 222 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 223 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 224 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 225 "data/maps/OldaleTown/scripts.pory"
	end
# 226 "data/maps/OldaleTown/scripts.pory"

# 227 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath::
# 228 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 229 "data/maps/OldaleTown/scripts.pory"
	release
# 230 "data/maps/OldaleTown/scripts.pory"
	end
# 231 "data/maps/OldaleTown/scripts.pory"

# 232 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival::
# 233 "data/maps/OldaleTown/scripts.pory"
	lockall
# 234 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 235 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 236 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 237 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 238 "data/maps/OldaleTown/scripts.pory"
	end
# 239 "data/maps/OldaleTown/scripts.pory"

# 240 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1::
# 241 "data/maps/OldaleTown/scripts.pory"
	lockall
# 242 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 243 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 244 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 245 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 246 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 247 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 248 "data/maps/OldaleTown/scripts.pory"
	end
# 249 "data/maps/OldaleTown/scripts.pory"

# 250 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2::
# 251 "data/maps/OldaleTown/scripts.pory"
	lockall
# 252 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 253 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 254 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 255 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 256 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 257 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 258 "data/maps/OldaleTown/scripts.pory"
	end
# 259 "data/maps/OldaleTown/scripts.pory"

# 260 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3::
# 261 "data/maps/OldaleTown/scripts.pory"
	lockall
# 262 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 263 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 264 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 265 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 266 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 267 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 268 "data/maps/OldaleTown/scripts.pory"
	end
# 269 "data/maps/OldaleTown/scripts.pory"

# 270 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage::
# 271 "data/maps/OldaleTown/scripts.pory"
	checkplayergender
# 272 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
# 273 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
# 274 "data/maps/OldaleTown/scripts.pory"
	end
# 275 "data/maps/OldaleTown/scripts.pory"

# 276 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage::
# 277 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 278 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 279 "data/maps/OldaleTown/scripts.pory"
	end
# 280 "data/maps/OldaleTown/scripts.pory"

# 281 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage::
# 282 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 283 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 284 "data/maps/OldaleTown/scripts.pory"
	end
# 285 "data/maps/OldaleTown/scripts.pory"

# 286 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish::
# 287 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 288 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
# 289 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
# 290 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 291 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 292 "data/maps/OldaleTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 293 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 294 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 295 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 296 "data/maps/OldaleTown/scripts.pory"
	end
# 297 "data/maps/OldaleTown/scripts.pory"

# 298 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1::
# 299 "data/maps/OldaleTown/scripts.pory"
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
# 300 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 301 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 302 "data/maps/OldaleTown/scripts.pory"
	return
# 303 "data/maps/OldaleTown/scripts.pory"

# 304 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2::
# 305 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 306 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 307 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 308 "data/maps/OldaleTown/scripts.pory"
	return
# 309 "data/maps/OldaleTown/scripts.pory"

# 310 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1:
# 311 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 312 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 313 "data/maps/OldaleTown/scripts.pory"
	step_end
# 314 "data/maps/OldaleTown/scripts.pory"

# 315 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2:
# 316 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 317 "data/maps/OldaleTown/scripts.pory"
	step_end
# 318 "data/maps/OldaleTown/scripts.pory"

# 319 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3:
# 320 "data/maps/OldaleTown/scripts.pory"
	face_left
# 321 "data/maps/OldaleTown/scripts.pory"
	step_end
# 322 "data/maps/OldaleTown/scripts.pory"

# 323 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit:
# 324 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 325 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 326 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 327 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 328 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 329 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 330 "data/maps/OldaleTown/scripts.pory"
	step_end
# 331 "data/maps/OldaleTown/scripts.pory"

# 332 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit:
# 333 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 334 "data/maps/OldaleTown/scripts.pory"
	delay_4
# 335 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 336 "data/maps/OldaleTown/scripts.pory"
	step_end
# 337 "data/maps/OldaleTown/scripts.pory"

# 338 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack:
# 339 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 340 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 341 "data/maps/OldaleTown/scripts.pory"
	step_end
# 342 "data/maps/OldaleTown/scripts.pory"

# 343 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp:
# 344 "data/maps/OldaleTown/scripts.pory"
	walk_fast_up
# 345 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_left
# 346 "data/maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 347 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 348 "data/maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 349 "data/maps/OldaleTown/scripts.pory"
	step_end
# 350 "data/maps/OldaleTown/scripts.pory"

# 351 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition:
# 352 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 353 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 354 "data/maps/OldaleTown/scripts.pory"
	step_end
# 355 "data/maps/OldaleTown/scripts.pory"

# 356 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_SavingMyProgress:
# 357 "data/maps/OldaleTown/scripts.pory"
	.string "I want to take a rest, so I'm saving my\n"
# 358 "data/maps/OldaleTown/scripts.pory"
	.string "progress.$"
# 359 "data/maps/OldaleTown/scripts.pory"

# 360 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart:
# 361 "data/maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 362 "data/maps/OldaleTown/scripts.pory"
	.string "I work at a POKéMON MART.\p"
# 363 "data/maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 364 "data/maps/OldaleTown/scripts.pory"

# 365 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 366 "data/maps/OldaleTown/scripts.pory"
	.string "This is a POKéMON MART.\n"
# 367 "data/maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 368 "data/maps/OldaleTown/scripts.pory"
	.string "We sell a variety of goods including\n"
# 369 "data/maps/OldaleTown/scripts.pory"
	.string "POKé BALLS for catching POKéMON.\p"
# 370 "data/maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 371 "data/maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 372 "data/maps/OldaleTown/scripts.pory"

# 373 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation:
# 374 "data/maps/OldaleTown/scripts.pory"
	.string "A POTION can be used anytime, so it's\n"
# 375 "data/maps/OldaleTown/scripts.pory"
	.string "even more useful than a POKéMON CENTER\l"
# 376 "data/maps/OldaleTown/scripts.pory"
	.string "in certain situations.$"
# 377 "data/maps/OldaleTown/scripts.pory"

# 378 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere:
# 379 "data/maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 380 "data/maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 381 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 382 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 383 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 384 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 385 "data/maps/OldaleTown/scripts.pory"

# 386 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints:
# 387 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 388 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 389 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 390 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 391 "data/maps/OldaleTown/scripts.pory"

# 392 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints:
# 393 "data/maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 394 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 395 "data/maps/OldaleTown/scripts.pory"
	.string "But it turns out they were only my\n"
# 396 "data/maps/OldaleTown/scripts.pory"
	.string "own footprints…$"
# 397 "data/maps/OldaleTown/scripts.pory"

# 398 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack:
# 399 "data/maps/OldaleTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 400 "data/maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 401 "data/maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 402 "data/maps/OldaleTown/scripts.pory"

# 403 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack:
# 404 "data/maps/OldaleTown/scripts.pory"
	.string "BRENDAN: I'm heading back to my dad's\n"
# 405 "data/maps/OldaleTown/scripts.pory"
	.string "LAB now.\l"
# 406 "data/maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 407 "data/maps/OldaleTown/scripts.pory"

# 408 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_TownSign:
# 409 "data/maps/OldaleTown/scripts.pory"
	.string "OLDALE TOWN\n"
# 410 "data/maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"

OldaleTown_EventScript_Rayquaza_Text_0:
# 4 "data/maps/OldaleTown/scripts.pory"
	.string "Keine Ahnung, ob das bei deinem\nGewicht überhaupt funktioniert.\p$"
