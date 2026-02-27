# 克隆时自动初始化和更新每一个子模块
git clone --recurse-submodules https://github.com/xuejianqiang123/esp32_fsm.git

components：V1.0.0 (依赖版本需要手动切换子仓库版本 todo 后面自动匹配)


# 项目架构目录
```
.
|-- main
|   |-- app                        # 【应用层】 负责实现具体业务功能（如数据处理、用户交互、任务调度），直接对接需求场景。
|   |-- bll_guitar (子仓库)         # 【业务逻辑层】 产品业务功能模块，仅提供接口给应用层调用。（方便同类产品复用）
|   |-- unit_test                  # 【单元测试】
|   `-- main.c
|-- components (子仓库)
|   |-- common                     # 【通用基础服务层】 提供全局通用的基础定义（数据类型别名\通用常量\通用宏定义等）以及工具函数等。
|   |   |-- algorithm                # 基础通用算法服务(CRC32、SHA256、快速排序、均值滤波、哈希...)
|   |-- service                    # 【服务层】 为应用层提供通用服务（如通信协议封装、数据解析、资源管理），解耦应用与底层。
|   |   |-- algorithm                # 业务相关算法服务(PID算法、FOC算法、温度补偿滤波...)
|   |   |-- fsm                      # 有限状态机服务
|   |   |-- protocol                 # 协议服务(UDS协议\CAN协议\WiFi协议...)
|   |   `-- system                   # 系统服务(电源管理状态机\安全服务\中断管理器...)
|   |-- device~                    # 【设备服务】 (电机服务\传感器服务\显示服务...)
|   |-- driver                     # 【驱动层】 对接硬件外设（如传感器、接口芯片、执行器），提供标准化操作接口，屏蔽硬件差异。
|   |   |-- actuator                 # 执行器驱动(电机驱动\LED驱动\PWM驱动...)
|   |   |-- bus                      # 总线驱动(UART驱动\I2C驱动\SPI驱动\CAN驱动...)
|   |   |-- communication            # 通信驱动(WiFi驱动\BLE驱动、子卡...)
|   |   |-- display                  # 显示驱动(OLED驱动...)
|   |   |-- sensor                   # 传感器驱动(IMU驱动\按键驱动\温度驱动\ADC驱动...)
|   |   `-- storage                  # 存储驱动(24C02驱动\Flash驱动\SD卡驱动...)
|   |-- bsp                        # [板级别支持包] 抽象硬件板机接口，方便改板使用。
|   |   |-- platforms                # 特定名称函数，由board_config.h进行宏定义。
|   |   |   |-- guitar               # todo 这一块偏向业务命名，可能会移动到业务子仓库
|   |   |   |   `-- bsp_led.c           bsp_led_init() bsp_led_on() bsp_led_off() bsp_led_deinit()
|   |   |   |-- bsp_gpio.c  
|   |   |   |-- bsp_adc.c         
|   |   |   |-- bsp_uart.c           bsp_uart0_init() bsp_uart0_send_data(*data, len) bsp_uart0_receive_data() bsp_uart0_set_baud(115200)
|   |   |   `-- bsp_i2c.c
|   |   `-- interface                # 通用接口头文件(GPIO通用接口\UART通用接口\I2C通用接口\ADC通用接口...)
|   |   |   |-- bsp_gpio.h
|   |   |   |-- bsp_uart.h
|   |   |   `-- bsp_i2c.h
|   |-- HAL                        # [硬件抽象层] 隔离驱动层与硬件，使上层软件可跨硬件平台移植（如 MCU、SOC 开发）。
|   |   |-- platforms                # 平台具体实现(ESP32平台\STM32平台)
|   |   |   |-- esp32
|   |   |   |   |-- hal_gpio.c       hal_gpio_init(io_num) hal_gpio_set_level(io_num) hal_gpio_read_level(io_num)
|   |   |   |   |-- hal_uart.c
|   |   |   |   `-- hal_i2c.c
|   |   `-- interface                # 通用接口头文件(GPIO通用接口\UART通用接口\I2C通用接口\ADC通用接口...)
|   |   |   |-- hal_gpio.h
|   |   |   |-- hal_uart.h
|   |   |   `-- hal_i2c.h
|   `-- tools
`-- Docs
    |-- 架构文档
    |-- 设计文档
    |-- 移植指南
    `-- API文档
```

# 新项目绑定子仓库
git submodule add https://github.com/xuejianqiang123/components.git