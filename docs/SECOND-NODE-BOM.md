# Second Sensor Node: Weather + GPS (RAK19001, US915)

This node reuses the **RAK19001 Dual IO Base Board** that does not fit the
existing earthquake-kit enclosure (`100x75x38`). It goes into a larger
**Unify Enclosure IP67 150x100x45mm** with solar charging.

---

## Existing Inventory (already on hand)

| Module | Part | Role | Slot on RAK19001 |
|--------|------|------|------------------|
| RAK19001 | Dual IO Base Board (60x67 mm) | Base | — |
| RAK12500 | u-blox ZOE-M8Q GNSS | GPS fix | **Slot A** (UART+I2C) |
| RAK1901 | Sensirion SHTC3 | Temp / humidity | **Slot C** (I2C, 10 mm) |
| RAK13009 | Qwiic / STEMMA QT adapter | Future external I2C sensors | **Slot D** (I2C, 10 mm) |
| — | GPS ceramic patch antenna | Included with RAK12500 | MHF connector on module |
| — | Omron D7S earthquake module (RAK12027) | Stays in earthquake node | N/A |

> **RAK19001 slot map:** 1 CPU slot, 6 sensor slots (A–F, all 24-pin),
> 2 IO slots. Slot A provides UART+I2C (required for RAK12500 full
> functionality). Slots B–F are I2C-only sensor slots.

---

## Purchase List — Required

| # | Part | SKU | Variant / Notes | Price (USD) | Link |
|---|------|-----|-----------------|-------------|------|
| 1 | **RAK4631** WisBlock Core | 119000 | **US915 / Arduino** | $17.99 | [store.rakwireless.com](https://store.rakwireless.com/products/rak4631-lpwan-node) |
| 2 | **Unify Enclosure IP67 150x100x45mm** | 910226 | **Mounting Plate with Screw Bosses** / Light Gray or Pure White | $39.00 | [store.rakwireless.com](https://store.rakwireless.com/products/unify-enclosure-ip67-150-100-45mm) |
| 3 | **Solar Panel 80x45mm** | 920399 | 5 V / 90 mA, ZHR-2 1.5 mm plug | $3.50 | [store.rakwireless.com](https://store.rakwireless.com/products/solar-panel) |
| 4 | **Battery Connector Cable** (5 pcs) | 910115 | JST-PH 2.0 mm, 20 cm | $2.00 | [store.rakwireless.com](https://store.rakwireless.com/products/battery-connector-cable) |
| 5 | **3.7 V LiPo battery** | (third-party) | JST-PH 2.0 mm, flat profile ≤107x57x6 mm for under-plate fit; ≥1000 mAh recommended | ~$8–15 | Amazon / Adafruit / local supplier |

**Required subtotal (RAK parts only): ~$62.49 + shipping**

---

## Purchase List — Optional but Recommended

| # | Part | SKU | Why | Price (USD) | Link |
|---|------|-----|-----|-------------|------|
| 6 | **RAK19005** Sensor Extension Cable | 100025 | Relocate RAK1901 near a vented opening for accurate ambient readings | $4.50 | [store.rakwireless.com](https://store.rakwireless.com/products/fpc-extension-cable-for-slot-a-to-d-rak19005) |
| 7 | **RAK1906** BME680 Environment Sensor | 100008 | Adds barometric pressure + IAQ gas sensing (Slot E or F) | $15.20 | [store.rakwireless.com](https://store.rakwireless.com/products/rak1906-bme680-environment-sensor) |

---

## Sensor Placement Strategy (Outdoor)

### Problem

Temp/humidity sensors sealed inside an IP67 box read enclosure-internal
temperature, not ambient air. The box heats up in sun, and humidity
stays stale.

### Recommended approach

1. **Extension cable (RAK19005):** Plug the RAK1901 into the FPC cable
   instead of directly into Slot C. Route the cable so the sensor board
   sits near the enclosure lid gasket edge or a purpose-drilled vent.
2. **Vent port:** Drill a small hole (~6 mm) in the enclosure wall near
   the bottom. Cover it with a PTFE/Gore-Tex membrane vent
   (IP67-rated breather, available on Amazon/McMaster for ~$3). This
   allows air exchange while keeping water out.
3. **Keep GPS antenna near the lid:** The RAK12500 patch antenna needs
   sky view. Mount it facing up, attached to the inside of the lid with
   double-sided tape or the antenna's adhesive backing. Route the MHF
   cable from Slot A to the lid interior.
4. **Solar panel:** The `150x100x45` enclosure does **not** have a
   built-in solar panel (unlike the smaller solar variant). Mount the
   80x45 mm panel externally on the lid with outdoor adhesive or a
   small bracket, and route the cable through a sealed cable gland or
   the gasket edge. Alternatively, use a larger external panel with the
   RAK19004 Green Power Module if more charging current is needed.
5. **Battery placement:** The screw-boss mounting plate leaves
   ~107x57x6 mm underneath for a flat-profile LiPo. A 1000–2000 mAh
   cell fits easily.

### Sensor slot assignment (final)

| RAK19001 Slot | Module | Cable? |
|---------------|--------|--------|
| CPU | RAK4631 (US915) | — |
| A | RAK12500 (GNSS) | MHF antenna to lid |
| C | RAK1901 (temp/humid) | Via RAK19005 FPC to vent area |
| D | RAK13009 (Qwiic) | Qwiic cable to external breakout if needed |
| E | RAK1906 (BME680) — optional | Direct or via second RAK19005 |
| B, F | Available for future sensors | — |
| IO Slot 1/2 | Available | — |

---

## Checkout Summary

### Minimum viable order (RAK store)

| Qty | Item | Variant | Unit $ | Line $ |
|-----|------|---------|--------|--------|
| 1 | RAK4631 | US915 / Arduino | 17.99 | 17.99 |
| 1 | Unify Enclosure IP67 150x100x45mm | Screw Boss Plate | 39.00 | 39.00 |
| 1 | Solar Panel 80x45mm | — | 3.50 | 3.50 |
| 1 | Battery Connector Cable (5 pc) | — | 2.00 | 2.00 |
| | | | **Subtotal** | **$62.49** |

### Full order (RAK store, with recommended extras)

| Qty | Item | Variant | Unit $ | Line $ |
|-----|------|---------|--------|--------|
| 1 | RAK4631 | US915 / Arduino | 17.99 | 17.99 |
| 1 | Unify Enclosure IP67 150x100x45mm | Screw Boss Plate | 39.00 | 39.00 |
| 1 | Solar Panel 80x45mm | — | 3.50 | 3.50 |
| 1 | Battery Connector Cable (5 pc) | — | 2.00 | 2.00 |
| 1 | RAK19005 Extension Cable | — | 4.50 | 4.50 |
| 1 | RAK1906 BME680 | — | 15.20 | 15.20 |
| | | | **Subtotal** | **$82.19** |

### Third-party

| Qty | Item | Notes | Est. $ |
|-----|------|-------|--------|
| 1 | 3.7 V LiPo, ≥1000 mAh, JST-PH 2.0 | Flat profile ≤107x57x6 mm | ~$10 |
| 1 | PTFE breather vent (6 mm, IP67) | For temp/humidity accuracy | ~$3 |

---

## Assembly Order

1. Screw the **mounting plate** (screw-boss side up) into the enclosure
   base using the included M3 countersink screws.
2. Place the **LiPo battery** in the cavity underneath the plate; route
   the battery cable up through the plate slot.
3. Seat the **RAK19001** onto the plate screw bosses; secure with the
   included self-tapping screws.
4. Click the **RAK4631** into the CPU slot. Attach the LoRa and BLE
   antennas (included with RAK4631). Tuck antennas along the enclosure
   wall; do not pinch under the lid gasket.
5. Click the **RAK12500** into **Slot A**. Route the GPS patch antenna
   to the inside of the lid, adhesive side down.
6. Plug the **RAK19005 FPC cable** into **Slot C**; attach the
   **RAK1901** to the other end. Position the RAK1901 near the
   drilled/vented opening.
7. *(Optional)* Click the **RAK1906** into **Slot E**.
8. *(Optional)* Click the **RAK13009** into **Slot D** if using Qwiic
   breakout sensors.
9. Connect the **battery cable** to the base board battery connector
   (JST-PH 2.0, check polarity: red = +, black = GND).
10. Mount the **solar panel** on the enclosure lid exterior; route its
    ZHR-2 cable through a sealed entry point to the base board solar
    connector (JST 1.5 mm).
11. Close the lid, ensuring the silicone gasket seats evenly. Tighten
    the four corner screws.

---

## Firmware Notes

The existing earthquake-sensor firmware in this repo targets the
RAK19003 + RAK12027 combination. The second node will need separate
firmware that reads RAK12500 (GPS), RAK1901 (temp/humidity), and
optionally RAK1906 (BME680), then sends data over LoRaWAN.

RAKwireless provides ready-to-use Arduino examples:

- **GPS:** [`RAK12500_GPS_ZOE-M8Q_IIC`](https://github.com/RAKWireless/WisBlock/tree/master/examples/common/sensors/RAK12500_GPS_ZOE-M8Q/RAK12500_GPS_ZOE-M8Q_IIC)
- **Temp/Humidity:** [`Weather_Monitoring`](https://github.com/RAKWireless/WisBlock/tree/master/examples/RAK4630/solutions/Weather_Monitoring)
- **Environment (BME680):** [`Environment_Monitoring`](https://github.com/RAKWireless/WisBlock/tree/master/examples/RAK4630/solutions/Environment_Monitoring)

These can be combined into a single sketch for the second node.
