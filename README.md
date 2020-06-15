# router-table
Bits and pieces (mostly LinuxCNC config) describing my router table.

## Notes

### Toolchanger

Well, crap. My plan to make a rack along the second-to-last cross beam ran into complications. Several things affixed to the spindle motor collide with nearby tools: the dust collector shoe, the mounting/adapter plate. This is largely mitigated by removing every other tool clip, but that halves the number of tools I can keep on-line.

<a href="https://i.imgur.com/UmxeUWG.jpg"><img src="https://i.imgur.com/UmxeUWGl.jpg"></a>

The new adapter plate must be made to not protrude below the z-axis mounting plate. The spindle motor should protrude as far as practical below this. The current adapter plate is flush with the bottom of the spindle motor and protrudes about 25 mm below the z-axis plate. The top of the adapter plate shouldn't go above the top of the spindle body (excluding the fan enclosure).

The dust collector shoe works if it sticks straight down the y-axis, but comes close to interfering with whatever’s set up on the table. It's also aesthetically more pleasing if it can go to the left, as well as making the hose stretch that much less. Perhaps, if it is shortened, it can avoid intefering with the tool to the left.

More complicated is dealing with the brush depth. The tool clip ends up _very_ close to the bottom of the upper shoe bracket, which means I’ll need very long bristles, rather than to make the brush bracket taller; if it’s any taller it will interfere with tool changes. Not sure how to address this, as I haven’t found a brush with bristles longer than 3". I did just see a video with a pneumatic retracting skirt. I’ll probably have to do something like that.

The middle tool clip appears to be at absolute coordinates x = 973.5, y = 2741.0, z = -108.0. The y-clearance position is about y = 2700. Note that axis 2 and 3 steppers were tripping the HLFB (“amplifier fault”), which means the z axis was probably pushing down too hard, and the y-axis was pushing too far toward positive.

The current logic shuts off the collet open command if a move is commanded. We can't have that, but the intent was to not allow the collet to open while the spindle was in motion. Perhaps I can set a “tool change mode” where this restriction is relaxed.
