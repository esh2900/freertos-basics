#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"


/* Task 1 */
static void sensor_task(void *pvParameters)
{
    (void) pvParameters;

    while (1)
    {
        printf("Sensor task running\n");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


/* Task 2 */
static void processing_task(void *pvParameters)
{
    (void) pvParameters;

    while (1)
    {
        printf("Processing task running\n");

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}


int main(void)
{
    printf("Starting FreeRTOS...\n");

    xTaskCreate(
        sensor_task,
        "Sensor",
        1024,
        NULL,
        2,
        NULL
    );

    xTaskCreate(
        processing_task,
        "Processing",
        1024,
        NULL,
        1,
        NULL
    );

    vTaskStartScheduler();

    /* We should never reach here. */
    return 0;
}