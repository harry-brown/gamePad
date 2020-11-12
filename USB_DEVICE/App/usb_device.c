/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usb_device.c
  * @version        : v1.0_Cube
  * @brief          : This file implements the USB Device
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h"
#include "usb_hid_keys.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USB Device Core handle declaration. */
USBD_HandleTypeDef hUsbDeviceFS;

/*
 * -- Insert your variables declaration here --
 */
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*
 * -- Insert your external function declaration here --
 */
/* USER CODE BEGIN 1 */

struct mouseHID_t {
	  uint8_t buttons;
	  int8_t x;
	  int8_t y;
	  int8_t wheel;
};

uint8_t HIDkbBuffer[12] = {0};

struct mouseHID_t mouseHID;

void usbInit(void)
{
	mouseHID.buttons = 0;
	mouseHID.x = 10;
	mouseHID.y = 0;
	mouseHID.wheel = 0;
}

void usbSend(uint16_t status)
{
	// Send HID report
	HIDkbBuffer[2] = (status & 1 << 9) ? KEY_W : 0;
	HIDkbBuffer[3] = (status & 1 << 8) ? KEY_A : 0;
	HIDkbBuffer[4] = (status & 1 << 7) ? KEY_S : 0;
	HIDkbBuffer[5] = (status & 1 << 6) ? KEY_D : 0;
	HIDkbBuffer[6] = (status & 1 << 5) ? KEY_P : 0;
	HIDkbBuffer[7] = (status & 1 << 4) ? KEY_M : 0;
	HIDkbBuffer[8] = (status & 1 << 3) ? KEY_X : 0;
	HIDkbBuffer[9] = (status & 1 << 2) ? KEY_B : 0;
	HIDkbBuffer[10] = (status & 1 << 1) ? KEY_Y : 0;
	HIDkbBuffer[11] = (status & 1 << 0) ? KEY_A : 0;

	USBD_HID_SendReport(&hUsbDeviceFS, HIDkbBuffer, 8);
}

/* USER CODE END 1 */

/**
  * Init USB device Library, add supported class and start the library
  * @retval None
  */
void MX_USB_DEVICE_Init(void)
{
  /* USER CODE BEGIN USB_DEVICE_Init_PreTreatment */

  /* USER CODE END USB_DEVICE_Init_PreTreatment */

  /* Init Device Library, add supported class and start the library. */
  if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_HID) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN USB_DEVICE_Init_PostTreatment */

  /* USER CODE END USB_DEVICE_Init_PostTreatment */
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
