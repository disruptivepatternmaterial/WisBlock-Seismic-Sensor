# RAK12027 WisBlock Seismic Sensor

This fork adds **RAK19003-specific** notes below. For full documentation (assembly, building, flashing, how it works, data format, Datacake, etc.), see the **original README**:  
**[beegee-tokyo/WisBlock-Seismic-Sensor — README](https://github.com/beegee-tokyo/WisBlock-Seismic-Sensor/blob/main/README.md)**

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
