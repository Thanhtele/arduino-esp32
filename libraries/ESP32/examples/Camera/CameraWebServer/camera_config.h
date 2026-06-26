#ifndef CAMERA_CONFIG_H
#define CAMERA_CONFIG_H

#include "esp_camera.h"

/**************************************************************
 * Camera Image
 *************************************************************/
#define CAM_FRAMESIZE          FRAMESIZE_VGA
#define CAM_JPEG_QUALITY       12

/**************************************************************
 * Image Adjust
 *************************************************************/
#define CAM_BRIGHTNESS         0      // -2 ~ 2
#define CAM_CONTRAST           1      // -2 ~ 2
#define CAM_SATURATION         0      // -2 ~ 2
#define CAM_SHARPNESS          0      // -2 ~ 2

/**************************************************************
 * Orientation
 *************************************************************/
#define CAM_HMIRROR            0
#define CAM_VFLIP              0

/**************************************************************
 * White Balance
 *************************************************************/
#define CAM_AWB                1
#define CAM_AWB_GAIN           1
#define CAM_WB_MODE            0

/*
0 Auto
1 Sunny
2 Cloudy
3 Office
4 Home
*/

/**************************************************************
 * Exposure
 *************************************************************/
#define CAM_AEC                1
#define CAM_AEC2               0
#define CAM_AEC_VALUE          300
#define CAM_AE_LEVEL           0

/**************************************************************
 * Gain
 *************************************************************/
#define CAM_AGC                1
#define CAM_AGC_GAIN           0

#define CAM_GAINCEILING        GAINCEILING_2X

/*
GAINCEILING_2X
GAINCEILING_4X
GAINCEILING_8X
GAINCEILING_16X
GAINCEILING_32X
GAINCEILING_64X
GAINCEILING_128X
*/

/**************************************************************
 * Image Processing
 *************************************************************/
#define CAM_COLORBAR           0
#define CAM_SPECIAL_EFFECT     0

/*
0 Normal
1 Negative
2 Grayscale
3 Red Tint
4 Green Tint
5 Blue Tint
6 Sepia
*/

/**************************************************************
 * DSP
 *************************************************************/
#define CAM_BPC                0
#define CAM_WPC                1
#define CAM_RAW_GMA            1
#define CAM_LENC               1
#define CAM_DCW                1

/**************************************************************
 * Flash LED
 *************************************************************/
#define CAM_LED_INTENSITY      0

/**************************************************************
 * Apply configuration
 *************************************************************/
static inline void applyCameraConfig()
{
    sensor_t *s = esp_camera_sensor_get();

    if (!s) return;

    s->set_framesize(s, CAM_FRAMESIZE);
    s->set_quality(s, CAM_JPEG_QUALITY);

    s->set_brightness(s, CAM_BRIGHTNESS);
    s->set_contrast(s, CAM_CONTRAST);
    s->set_saturation(s, CAM_SATURATION);
    s->set_sharpness(s, CAM_SHARPNESS);

    s->set_hmirror(s, CAM_HMIRROR);
    s->set_vflip(s, CAM_VFLIP);

    s->set_whitebal(s, CAM_AWB);
    s->set_awb_gain(s, CAM_AWB_GAIN);
    s->set_wb_mode(s, CAM_WB_MODE);

    s->set_exposure_ctrl(s, CAM_AEC);
    s->set_aec2(s, CAM_AEC2);
    s->set_aec_value(s, CAM_AEC_VALUE);
    s->set_ae_level(s, CAM_AE_LEVEL);

    s->set_gain_ctrl(s, CAM_AGC);
    s->set_agc_gain(s, CAM_AGC_GAIN);
    s->set_gainceiling(s, CAM_GAINCEILING);

    s->set_colorbar(s, CAM_COLORBAR);
    s->set_special_effect(s, CAM_SPECIAL_EFFECT);

    s->set_bpc(s, CAM_BPC);
    s->set_wpc(s, CAM_WPC);
    s->set_raw_gma(s, CAM_RAW_GMA);
    s->set_lenc(s, CAM_LENC);
    s->set_dcw(s, CAM_DCW);
}

#endif
