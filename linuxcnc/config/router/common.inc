[EMC]
VERSION = 1.1
MACHINE = router
DEBUG = 0x00000000

[HOSTMOT2]
DRIVER = hm2_eth
IPADDRESS = "10.10.10.10"
BOARD = 7i76e
STEPGENS = 5
ENCODERS = 0
SSERIAL_PORT = 1

[DISPLAY]
DISPLAY = axis
GLADEVCP= ./lzpanel.ui
POSITION_OFFSET = RELATIVE
POSITION_FEEDBACK = COMMANDED
MAX_FEED_OVERRIDE = 2.0
DEFAULT_LINEAR_VELOCITY = 100
DEFAULT_ANGULAR_VELOCITY = 360
CYCLE_TIME = 0.1
INTRO_GRAPHIC = emc2.gif
INTRO_TIME = 0
OPEN_FILE = ""

[KINS]
KINEMATICS = trivkins coordinates=XYYZA kinstype=BOTH
JOINTS = 5

[EMCIO]
EMCIO = io
CYCLE_TIME = 0.100
TOOL_TABLE = tool.tbl
RANDOM_TOOLCHANGER = 0
TOOL_CHANGE_WITH_SPINDLE_ON = 0

[RS274NGC]
PARAMETER_FILE = router.var
SUBROUTINE_PATH = nc_subroutines:/usr/share/linuxcnc/ncfiles/remap_lib/common_nc_subs/
LOGLEVEL=9
REMAP= M6 modalgroup=6 prolog=change_prolog ngc=auto_tool_change epilog=change_epilog

[PYTHON]
# where to find Python code
# code specific for this configuration
PATH_PREPEND= ./python
# generic support code
PATH_APPEND= ../../nc_files/remap_lib/python-stdglue

# import the following Python module
TOPLEVEL= python/toplevel.py

# the higher the more verbose tracing of the Python plugin
LOG_LEVEL = 0

[MANUAL_TOOL_CHANGE_POSITION]
X = 100
Y = -200
Z = -0.001

[EMCMOT]
EMCMOT = motmod
SERVO_PERIOD = 1000000

[TASK]
TASK = milltask
CYCLE_TIME = 0.010

[TRAJ]
AXES=4
JOINTS=5
COORDINATES = XYYZA
LINEAR_UNITS = metric
ANGULAR_UNITS = degree
MAX_ANGULAR_VELOCITY = 360
MAX_LINEAR_VELOCITY = 600

[HAL]
#TWOPASS = on			Doesn't work, causes load errors
HALUI = halui
HALFILE = router.hal
HALFILE = io.hal
HALFILE = custom.hal
POSTGUI_HALFILE = postgui.hal

[HALUI]

