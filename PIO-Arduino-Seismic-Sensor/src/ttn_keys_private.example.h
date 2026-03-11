/**
 * TTN LoRaWAN keys for baked-in default (USE_DEFAULT_TTN_KEYS).
 *
 * Copy this file to ttn_keys_private.h and replace the placeholder values
 * with your device's DevEUI, AppEUI, and AppKey from the TTN console.
 * Add ttn_keys_private.h to .gitignore so it is not committed.
 *
 * Build with -DUSE_DEFAULT_TTN_KEYS in platformio.ini to apply these at first boot.
 */
#ifndef TTN_KEYS_PRIVATE_EXAMPLE_H
#define TTN_KEYS_PRIVATE_EXAMPLE_H

/* Replace with your device's 8-byte DevEUI (MSB first, from TTN). */
static const uint8_t default_deveui[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* Replace with your application's 8-byte AppEUI / JoinEUI (MSB first, from TTN). */
static const uint8_t default_appeui[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* Replace with your 16-byte AppKey from TTN. */
static const uint8_t default_appkey[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif /* TTN_KEYS_PRIVATE_EXAMPLE_H */
