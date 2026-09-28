#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

static QueueHandle_t sensor_queue;

/* Task 1 */
static void sensor_task(void *pvParameters)
{
    (void) pvParameters;

    int sensor_value=0;

    while (1)
    {
        sensor_value++;

        xQueueSend(sensor_queue,&sensor_value,portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


/* Task 2 */
static void processing_task(void *pvParameters)
{
    (void) pvParameters;

    int received_value;

    while (1)
    {
        
        xQueueReceive(sensor_queue,&received_value,portMAX_DELAY);
        
        printf("Processing received: %d\n", received_value);

    }
}


int main(void)
{
    printf("Starting FreeRTOS...\n");
    
    sensor_queue = xQueueCreate(5,sizeof(int));

    if(sensor_queue == NULL){
        printf("Failed to Create Queue\n");
        return 1;
    }

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

    /* Never reach here. */
    return 0;
}