# RAK12027 WisBlock Seismic Sensor

This fork adds **RAK19003-specific** notes below. For full documentation (assembly, building, flashing, how it works, data format, Datacake, etc.), see the **original README**:  
**[beegee-tokyo/WisBlock-Seismic-Sensor — README](https://github.com/beegee-tokyo/WisBlock-Seismic-Sensor/blob/main/README.md)**

---

## TTN keys and LoRaWAN defaults

**Private keys (OTAA):** Edit `PIO-Arduino-Seismic-Sensor/src/ttn_keys_private.h` with your DevEUI, AppEUI, and AppKey from the TTN console. That file is in `.gitignore` and is not committed. If it doesn’t exist, copy from `ttn_keys_private.example.h` and replace the placeholder arrays (`default_deveui`, `default_appeui`, `default_appkey`) with your device’s values (MSB first, as in TTN).

**First-boot defaults:** When the device is not already set to US915 + subband 2, the firmware applies and saves: **US915**, **FSB 2** (subband 2), **OTAA**, **Class A**, **TXP 10**, **unconfirmed**, **auto-join**, **5 join trials**, **5 min** send interval, and the keys from `ttn_keys_private.h`. So after flashing, the device will join TTN with those keys without AT commands.

**Subband:** For TTN United States 902–928 MHz with FSB 2, the firmware sets subband 2 so uplink/downlink use the same channels. If the device previously joined with a different subband, in TTN use **Reset session and MAC state** for the device after it joins with the new config.

**Changing settings over serial:** You can still use AT commands (e.g. `AT+MASK=2` for subband 2); WisBlock-API saves after changes.

---

## RAK19003 base board (two slots)

The [_**RAK19003**_](https://docs.rakwireless.com/Product-Categories/WisBlock/RAK19003/Overview) WisBlock Mini Base has **two sensor slots only: C and D** (Slot C = 10 mm modules, Slot D = up to 23 mm). **Each slot holds exactly one module.** If you use RAK19003 with the RAK12027 in **Slot C** (e.g. `RAK12027_SLOT=2` in `platformio.ini`), **Slot D is the only free slot** — one module only. You cannot put both RAK12002 and RAK1901 on the board; choose one.

| Module   | Works on RAK19003 with RAK12027 in Slot C? | Fits in free slot D? | Firmware ready? |
|----------|---------------------------------------------|----------------------|-----------------|
| [RAK12002](https://docs.rakwireless.com/Product-Categories/WisBlock/RAK12002/Overview) (RTC) | Yes | Yes (if you choose this one) | Yes |
| [RAK1901](https://docs.rakwireless.com/Product-Categories/WisBlock/RAK1901/Overview) (temp/humidity) | Yes | Yes (if you choose this one) | Yes |
| [RAK12500](https://docs.rakwireless.com/Product-Categories/WisBlock/RAK12500/Overview) (GNSS) | No | No — Slot C only on RAK19003; C is occupied | No (no driver) |
| [RAK12501](https://docs.rakwireless.com/Product-Categories/WisBlock/RAK12501/Overview) (GNSS, Quectel L76K) | Yes | Yes (if you choose this one) | No — driver not yet in this repo |

**Pick one:** Install **either** RAK12002, **or** RAK1901, **or** RAK12501 in Slot D. RAK12500 and RAK1910 are Slot C only on RAK19003, so they conflict with RAK12027. RAK12501 is the GNSS module that fits Slot D; this firmware does not yet include a RAK12501 driver (LPP channel 10 for GPS exists; init/read code would need to be added).

---

## Downlink (config over the air)

The device listens for downlinks on **FPort 3**. Two commands are supported. In TTN Console go to your device → **Downlink** → FPort **3**, payload type **Hex**, enter the payload → Send. The device applies the change and persists it.

| Command | Payload (hex) | Meaning |
|---------|----------------|---------|
| **Set reporting interval** | `AA 55` + 4-byte big-endian interval in **seconds** | How often the device sends the "I am alive" packet. |
| **Set seismic threshold** | `AA 55 02 00` (high) or `AA 55 02 01` (low) | High = less sensitive, fewer triggers. Low = more sensitive. Same as AT+SENS. |

**Reporting interval examples:**  
1 min = `AA550000003C` · 5 min = `AA550000012C` · 10 min = `AA5500000258` · 1 hour = `AA5500000E10`

**Threshold examples:**  
High sensitivity threshold = `AA550200` · Low sensitivity threshold = `AA550201`

Other LoRaWAN settings (DR, TXP, etc.) are not changed by these downlinks.
