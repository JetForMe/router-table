# CNC Router Table

Bits and pieces (mostly LinuxCNC config) describing my router table.

### Components

| Component | Desc |
| --------- | ---- |
| Table     | [AvidCNC 4x8](https://www.avidcnc.com/pro4896-4-x-8-cnc-router-machine-p-1337.html) router, custom-ordered 4x9 (to make room for a rack-style tool changer). Only the mechanical components and limit switches from them, not their stepper motors, drives, or spindle. |
| Rotary Axis | [AvidCNC rotary axis](https://www.avidcnc.com/avid-cnc-rotary-axis-p-724.html) (rotary axis) |
| Spindle   | [HSD ES330](https://www.hsdmechatronics.com/en/products/es330/) 4 kW, 24 kRPM, ATC |
| VFD | Delta VFD-MS300 series, [VFD25AMS23ANSHA](https://deltaacdrives.com/delta-ms300-vfd25ams23ansha/)
| Servos    | 4x [CPM-SDSK-3411P-ELS](https://teknic.com/model-info/CPM-SDSK-3411P-ELS/) (linear axes), 1x [CPM-SDSK-3421S-RLS](https://teknic.com/model-info/CPM-SDSK-3421S-RLS/) |
| Power & Cables | All from Teknic, details to come |
| Z-axis Brake | Originally MPC034-24-500, but the distributor’s page for that no longer exists. Teknic offers a [similar one](https://teknic.com/products/spring-applied-power-off-brakes/NEMA-34-brake/) |
| Interface | [Mesa 7176e](http://store.mesanet.com/index.php?route=product/product&product_id=290) |

## Notes

### Fan and Z-Brake Relays

There are two Phoenix Contact DIN rail relays, DigiKey part [277-17665-ND](https://www.digikey.com/product-detail/en/phoenix-contact/2905657/277-17665-ND/9381938). One controls the spindle fan motor, the other disengages the z-axis brake. That one needs a flyback diode.

### Toolchanger

3D-printed risers do a decent job of holding the forks high enough to allow the dust collector shoe bristles to surround the tool during load and unlooad, when the forks are turnd around to face backward:

<a href="https://i.imgur.com/3V2IuPz.jpg"><img src="https://i.imgur.com/3V2IuPzl.jpg"></a>

### Toolsetter

`hm2_7i76e.0.7i76.0.0.input-14`

## Limit Switches

4-pin M12 panel [connectors](https://www.digikey.com/en/products/detail/te-connectivity-amp-connectors/1838891-2/1764162). These damn things are nearly $20 each.

Brown is +24V, black is signal (to 7i76e input), blue is ground. Most of the inputs are tied high through a 10kΩ resistor at the 7i76e input, but the rotary axis limit switch has the resistor at the connector. This is how I should have done them all, but I'm not prepared right now to redo the other ones.

<a href="https://i.imgur.com/Dny7TSk.jpg"><img src="https://i.imgur.com/Dny7TSkl.jpg"></a>
<a href="https://i.imgur.com/UmxeUWG.jpg"><img src="https://i.imgur.com/ROSZThol.jpg"></a>

## Networking

This CNC router uses a Mesa 7i76e card, connected on a second Ethernet interface. On my machine, this requires the second interface to be configured with a static IP address. The following lines are added to `/etc/network/interfaces/`:

```
# Second interface directly connected to Mesa card

auto enp5s0
iface enp5s0 inet static
    address 10.10.10.1
    netmask 255.255.255.0
```

Then

```bash
$ sudo ifup enp5s0
```

(Might need to take it down first, then bring it back up.)


# Miscellanea

[Etekcity Outdoor Smart Plug](https://etekcity.com/products/smart-outdoor-wifi-outlet-eso15-tb) uses an [ESP-01e](https://docs.ai-thinker.com/_media/esp8266/docs/esp-01e_product_specification_en.pdf) Wi-Fi controller and a [HLW8012](https://tinkerman.cat/post/hlw8012-ic-new-sonoff-pow) ([ESPHome](https://esphome.io/components/sensor/hlw8012.html)) with shunt resistor to measure power.
