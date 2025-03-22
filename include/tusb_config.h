#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#include "pico/stdlib.h"

// Enable device mode
#define CFG_TUSB_MCU OPT_MCU_RP2040
#define CFG_TUSB_RHPORT0_MODE OPT_MODE_DEVICE
#define CFG_TUD_ENABLED 1
#define CFG_TUD_HID 1   // Enable HID

// HID Report settings
#define CFG_TUD_HID_EP_BUFSIZE 16

#endif /* _TUSB_CONFIG_H_ */
