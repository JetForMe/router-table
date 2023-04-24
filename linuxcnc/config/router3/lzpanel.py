#
#	GTK Imports
#

# import gi
# gi.require_version("Gtk", "3.0")
# from gi.repository import GLib
# from gi.repository import GObject
# from gi.repository import Gtk

#
#	LinuxCNC Imports
#

import hal
from hal_glib import GStat
import linuxcnc



sStat = linuxcnc.stat()
sCommand = linuxcnc.command()

def mdiOK():
	sStat.poll()
	return not sStat.estop and sStat.enabled and sStat.homed and (sStat.interp_state == linuxcnc.INTERP_IDLE)

   
class HandlerClass:
	'''
	class with gladevcp callback handlers
	'''

	def moveToToolsetter(self,widget,data=None):
		print ("moveToToolsetter called")
		if mdiOK():
			saveMode = sStat.task_mode
			sCommand.mode(linuxcnc.MODE_MDI)
			sCommand.wait_complete()
			sCommand.mdi("o<tshome> call")
			sCommand.wait_complete()
			sCommand.mode(saveMode)

	def measureCurrentTool(self,widget,data=None):
		print ("measureCurrentTool called")
		if mdiOK():
			saveMode = sStat.task_mode
			saveCoordinates = sStat.g5x_index
			print("Current coordinate system: ", saveCoordinates)
			sCommand.mode(linuxcnc.MODE_MDI)
			sCommand.wait_complete()
			sCommand.mdi("o<tshome> call")
			sCommand.mdi("o<pz> call")
			sCommand.wait_complete()
			sCommand.mode(saveMode)


	def __init__(self, halcomp,builder,useropts):
		'''
		Handler classes are instantiated in the following state:
		- the widget tree is created, but not yet realized (no toplevel window.show() executed yet)
		- the halcomp HAL component is set up and the widhget tree's HAL pins have already been added to it
		- it is safe to add more hal pins because halcomp.ready() has not yet been called at this point.

		after all handlers are instantiated in command line and get_handlers() order, callbacks will be
		connected with connect_signals()/signal_autoconnect()

		The builder may be either of libglade or GtkBuilder type depending on the glade file format.
		'''

		self.halcomp = halcomp
		self.builder = builder




def get_handlers(halcomp,builder,useropts):
	'''
	this function is called by gladevcp at import time (when this module is passed with '-u <modname>.py')

	return a list of object instances whose methods should be connected as callback handlers
	any method whose name does not begin with an underscore ('_') is a	callback candidate

	the 'get_handlers' name is reserved - gladevcp expects it, so do not change
	'''
	print ("get_handlers called")
	return [HandlerClass(halcomp,builder,useropts)]
