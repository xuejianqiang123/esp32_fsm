/********************************************************************************
* @file    board_config.h
* @author  jianqiang.xue
* @version V1.0.0
* @date    2026-02-13
* @brief   业务类--板级配置(硬件参数的 “统一管理处”)
           把和具体板子相关的参数（如 GPIO 引脚、UART 波特率、I2C 时钟频率）抽离到这里，
           避免硬编码在 BSP 实现中，更换板子时只需修改这个文件。
********************************************************************************/

#ifndef __BOARD_CONFIG_H
#define __BOARD_CONFIG_H


//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
// <h> Board Config

//  <h> 3P5MM
// =======================
//
//   <o> ADC_CHAN
#define ADC_3P5MM_CHAN                                             (1)

//    <o> ADC_ATTEN
//     <i> 模数转换器（ADC）衰减参数。不同的参数决定 ADC 的范围。
//     <i> 默认: 3 (12dB)，范围为 0-3 [1-->2.5db  2-->6db  3-->12db] 
#define ADC_3P5MM_ATTEN                                            (3)
//  </h>

//  <h> Battery
// =======================
//
//   <o> ADC_CHAN
#define ADC_BAT_CHAN                                               (2)

//   <o> ADC_ATTEN
//    <i> 模数转换器（ADC）衰减参数。不同的参数决定 ADC 的范围。
//    <i> 默认: 3 (12dB)，范围为 0-3 [1-->2.5db  2-->6db  3-->12db] 
#define ADC_BAT_ATTEN                                              (3)

//   <o> ADC_BATTERY_COEFF
//    <i> 电阻分压系数
#define ADC_BATTERY_COEFF                                          (4.421f)
//  </h>

//  <h> rhythm(节拍)
// =======================
//
//   <o> ADC_CHAN
#define ADC_RHYTHM_CHAN                                            (3)

//   <o> ADC_ATTEN
//    <i> 模数转换器（ADC）衰减参数。不同的参数决定 ADC 的范围。
//    <i> 默认: 3 (12dB)，范围为 0-3 [1-->2.5db  2-->6db  3-->12db] 
#define ADC_BAT_ATTEN                                              (3)

//   <o> ADC_RHYTHM_VALUE
//    <i> 节拍触发阈值
#define ADC_RHYTHM_VALUE                                           (4.421f)
//  </h>

/*************************************BOOT************************************/
// <h> BootLoader
// =======================
//   <s> chip ic
#define CHIP_IC                                                    "ESP32S3"
//   <s> version info
#define VERSION_INFO                                               "1.0"
// </h>

// </h>
//------------- <<< end of configuration section >>> -----------------------

/*********************************[引脚宏名称]*******************************/
/*******************************[引脚宏名称END]*****************************/

#endif
