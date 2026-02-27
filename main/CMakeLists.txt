# 收集当前根目录源文件
file(GLOB_RECURSE SOURCES  ./*.c)
file(GLOB_RECURSE HAL  ../components/hal/esp32/*.c)

# set(requires
#             esp_driver_gpio
#             esp_driver_i2c
#             esp_driver_uart
#             esp_timer
#             esp_driver_rmt
#             esp_driver_i2s
#             )
    # REQUIRES
    #     ${requires}
idf_component_register(
    SRCS 
        ${SOURCES}
        ${HAL}
    INCLUDE_DIRS 
        "."
        "../components/hal/include"
        )

