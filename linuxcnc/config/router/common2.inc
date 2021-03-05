[HAL]
POSTGUI_HALFILE = postgui.hal

[INPUTS]
# DO NOT change the input text
INPUT_0 = Select
INPUT_JOINT_0 = False
INPUT_1 = Select
INPUT_JOINT_1 = False
INPUT_2 = Select
INPUT_JOINT_2 = False
INPUT_3 = Select
INPUT_JOINT_3 = False
INPUT_4 = Select
INPUT_JOINT_4 = False
INPUT_5 = Select
INPUT_JOINT_5 = False
INPUT_6 = Select
INPUT_JOINT_6 = False
INPUT_7 = Select
INPUT_JOINT_7 = False
INPUT_8 = Min Limit & Home
INPUT_JOINT_8 = 0
INPUT_9 = Max Limit
INPUT_JOINT_9 = 0
INPUT_10 = Max Limit & Home
INPUT_JOINT_10 = 1
INPUT_11 = Select
INPUT_JOINT_11 = False
INPUT_12 = Select
INPUT_JOINT_12 = False
INPUT_13 = Select
INPUT_JOINT_13 = False
INPUT_14 = Select
INPUT_JOINT_14 = False
INPUT_15 = Select
INPUT_JOINT_15 = False
INPUT_16 = Select
INPUT_JOINT_16 = False
INPUT_17 = Select
INPUT_JOINT_17 = False
INPUT_18 = Select
INPUT_JOINT_18 = False
INPUT_19 = Select
INPUT_JOINT_19 = False
INPUT_20 = Select
INPUT_JOINT_20 = False
INPUT_21 = Select
INPUT_JOINT_21 = False
INPUT_22 = Select
INPUT_JOINT_22 = False
INPUT_23 = Select
INPUT_JOINT_23 = False
INPUT_24 = Select
INPUT_JOINT_24 = False
INPUT_25 = Select
INPUT_JOINT_25 = False
INPUT_26 = Select
INPUT_JOINT_26 = False
INPUT_27 = Select
INPUT_JOINT_27 = False
INPUT_28 = Select
INPUT_JOINT_28 = False
INPUT_29 = Select
INPUT_JOINT_29 = False
INPUT_30 = Select
INPUT_JOINT_30 = False
INPUT_31 = Select
INPUT_JOINT_31 = False

[OUTPUTS]
# DO NOT change the output text
OUTPUT_0 = Select
OUTPUT_1 = Select
OUTPUT_2 = Select
OUTPUT_3 = Select
OUTPUT_4 = Select
OUTPUT_5 = Select
OUTPUT_6 = Digital Out 2
OUTPUT_7 = Digital Out 3
OUTPUT_8 = Select
OUTPUT_9 = Select
OUTPUT_10 = Select
OUTPUT_11 = Select
OUTPUT_12 = Select
OUTPUT_13 = Select
OUTPUT_14 = Select
OUTPUT_15 = Select

[OPTIONS]
MANUAL_TOOL_CHANGE = True
HALUI = False
PYVCP = False
GLADEVCP = False
LADDER = False

#
#	Automatic Tool Changer
#
#	X, Y, Z are the machine coordinates of the first pocket.
#	POCKET_SPACING is the distance between pockets. Negative
#	to increase pockets toward -X direction.
#
#	SPEED_APPROACH is speed to approach holder
#	SPEED_ENGAGE is speed to engage or disengage holder
#	SPEED_SLOT is speed to insert or remove from fork


[ATC]
X = 1054.0
Y_CLEAR = -42.0
Y_POCKET = -110.57
Z_POCKET = -283.88
Z_CLEAR = -200.0
POCKET_SPACING = -110.0
NUM_POCKETS = 9
SPEED_APPROACH = 5000
SPEED_ENGAGE = 3000
SPEED_SLOT = 3000

[TOOLSETTER]
X = 1210.465
Y = -187.821
Z = -270.153
