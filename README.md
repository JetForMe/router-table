# router-table
Bits and pieces (mostly LinuxCNC config) describing my router table.

## Notes

### Fan and Z-Brake Relays

There are two Phoenix Contact DIN rail relays, DigiKey part [277-17665-ND](https://www.digikey.com/product-detail/en/phoenix-contact/2905657/277-17665-ND/9381938). One controls the spindle fan motor, the other disengages the z-axis brake. That one needs a flyback diode.

### Toolchanger

3D-printed risers do a decent job of holding the forks high enough to allow the dust collector shoe bristles to surround the tool during load and unlooad:

<a href="https://i.imgur.com/3V2IuPz.jpg"><img src="https://i.imgur.com/3V2IuPzl.jpg"></a>

#### Issues

* The dust shoe gets in the way. One possibility: https://www.youtube.com/watch?v=XIUp3J-6hyI
* The adapter plate strikes the top of the tool to the left. Adjusting the positioning of the spindle up (i.e. with the new adapter plate I'm thinking of cutting) will prevent it from reaching the forks at this level. For now, just notch out the left corner.
* Raising the forks a bit might give more room for bristles, and will allow for the spindle to be mounted a bit higher.

### Toolsetter

`hm2_7i76e.0.7i76.0.0.input-14`

## Limit Switches

4-pin M12 panel [connectors](https://www.digikey.com/en/products/detail/te-connectivity-amp-connectors/1838891-2/1764162). These damn things are nearly $20 each.

Brown is +24V, black is signal (to 7i76e input), blue is ground. Most of the inputs are tied high through a 10kΩ resistor at the 7i76e input, but the rotary axis limit switch has the resistor at the connector. This is how I should have done them all, but I'm not prepared right now to redo the other ones.

<a href="https://i.imgur.com/Dny7TSk.jpg"><img src="https://i.imgur.com/Dny7TSkl.jpg"></a>
<a href="https://i.imgur.com/UmxeUWG.jpg"><img src="https://i.imgur.com/ROSZThol.jpg"></a>


# Miscellanea

[Etekcity Outdoor Smart Plug](https://www.etekcity.com/product/100344) uses an [ESP-01e](https://docs.ai-thinker.com/_media/esp8266/docs/esp-01e_product_specification_en.pdf) Wi-Fi controller and a [HLW8012](https://tinkerman.cat/post/hlw8012-ic-new-sonoff-pow) ([ESPHome](https://esphome.io/components/sensor/hlw8012.html)) with shunt resistor to measure power.
