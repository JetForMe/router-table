There are numerous behaviors and interlocks defined in the router table.

## I/O

LinuxCNC interfaces with the machine via a Mesa 7i76e I/O board. The following inputs and outputs are defined:

### Outputs

bearing-air			TB6-7	24		Bearing purge air
tool-release-out	TB6-6	23		Release tool in spindle
spindle-fan
open-tools							Uncover tool rack
button-light						Manual tool release button light
spindle-on-out
servo-enable

### Inputs

All inputs have optional signal conditioning. The HAL signals representing the raw input are always prefixed with `raw-`:

| Signal                        | HAL Signal Name            | Source Device     | Source Pin    | Mesa Pin Name                     |
|-------------------------------|----------------------------|-------------------|---------------|-----------------------------------|
| VFD at commanded speed        | `raw-spindle-at-speed`     | VFD               | MO1           | `hm2_7i76e.0.7i76.0.0.input-22`   |
| VFD at commanded zero speed   | `raw-spindle-zero-speed`   | VFD               | M02           | `hm2_7i76e.0.7i76.0.0.input-23`   |
|                               |                            |                 |              |                                   |
|                               |                            |                 |              |                                   |
|                               |                            |                 |              |                                   |
|                               |                            |                 |              |                                   |
|                               |                            |                 |              |                                   |                              	|

tool-button							Manual tool release button
spindle-temp-ok						Spindle temperature is okay
collet-locked						Spindle drawbar is closed & tool holder present (sensor S1)
drawbar-open						Spindle drawbar is open (sensor S2)
vfd-fault
servo-fault							HLFB from Teknic SDSK

Commands
--------
spindle-on						gcode is commanding the spindle on
tool-release


	spindle-open-collet-out = spindle-zero-speed-in && !program-running && pressure-ok && (program-open-collet || spindle-button-press-in)
	bearing-air = spindle-on || !spindle-temp-ok
	spindle-fan = spindle-on || !spindle-temp-ok
	spindle-on-out = spindle-on && collet-locked && spindle-temp-ok






Connections
-------------------
7i76e TB4			VFD
---------			-------
1					ACM
2					AVI
3					+10
5					DCM
6					MI1		(spindle enable)
7					DCM
8					MI2		(spindle dir)


7i76e TB6	I/O		Connected To
---------	-----	------------
14			Input	Toolsetter



VFD Params
--------------------
00-04	Content of MFD		6 Power in kW, 11: AVI input %, 2: actual output freq
00-20
00-21

02-00	2/3-wire function	2: M1: run/stop M2: fwd/rev
02-16	at speed			2: Operation speed attained
02-17	at zero speed		34: Zero speed include stop (actual output frequency)

03-00	AVI					1: frequency command
03-03?	AVI input bias		-100% - 100%
03-10	Reverse setting for analog input frequency	0: neg freq not allowed, dir set by digital input
03-15	analog input filter time constant		0.1?

01-00	Max output freq		800
