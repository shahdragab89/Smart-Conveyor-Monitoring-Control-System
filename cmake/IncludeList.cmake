set(INCLUDE_LIST ${INCLUDE_LIST}
        ${PROJECT_PATH}/STM32-base/startup
        ${PROJECT_PATH}/STM32-base-STM32Cube/CMSIS/ARM/inc
        ${PROJECT_PATH}/STM32-base-STM32Cube/CMSIS/${SERIES_FOLDER}/inc
        ${PROJECT_PATH}/include
        ${PROJECT_PATH}/Motor
        ${PROJECT_PATH}/LIB
        ${PROJECT_PATH}/GPIO
        ${PROJECT_PATH}/lcd
        ${PROJECT_PATH}/RCC
)
set(SOURCES
        GPIO/Gpio.c
        RCC/RCC.C
        keypad/keypad.c
        segment/segment.c
        EXTI/EXTI.c

)

if (USE_HAL)
    set(INCLUDE_LIST ${INCLUDE_LIST} ${PROJECT_PATH}/STM32-base-STM32Cube/HAL/${SERIES_FOLDER}/inc)
endif ()