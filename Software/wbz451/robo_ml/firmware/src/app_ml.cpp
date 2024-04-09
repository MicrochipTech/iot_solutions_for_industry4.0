/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ml.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_ml.h"
#include "app.h"
#include <math.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE

#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "model.h"
#include "gesture_predictor.h"
//#include "constants.h"




// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define INPUT_SHAPE     3
#define OUTPUT_SHAPE    2

const tflite::Model* model = nullptr;
tflite::ErrorReporter* error_reporter = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;

extern int8_t accData[];
const char* labels[OUTPUT_SHAPE] = {   
        "PICK",			 // 0
        "DP",			 // 1
//        "Side_Back",                 // 2
//        "Side_Front",                // 3
//        "Vertical_Down",			 // 4
//        "Vertical_Up"			     // 5
};
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_ML_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

uint8_t VectorMagnitude(const int8_t *vec)
{
    return sqrt((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]));
}

void handle_output(tflite::ErrorReporter* error_reporter, int index)
{
    // Log the current X and Y values
    TF_LITE_REPORT_ERROR(error_reporter, "gesture index: %d\n", index);

}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

// Create an area of memory to use for input, output, and intermediate arrays.
// The size of this will depend on the model you're using, and may need to be
// determined by experimentation.
constexpr int kTensorArenaSize = 40*1024;
__attribute__((__aligned__(16))) uint8_t tensor_arena[kTensorArenaSize];

void tflite_setup(void)
{

    static tflite::MicroErrorReporter micro_error_reporter;  
    error_reporter = &micro_error_reporter;

    // Load a model from an array of bytes
    model = tflite::GetModel(g_model);
    printf("Version:%d\r\n",model->version());
    if (model->version() != TFLITE_SCHEMA_VERSION) {
        printf("Not Supported Version\r\n");
      TF_LITE_REPORT_ERROR(error_reporter,
                           "Model provided is schema version %d not equal "
                           "to supported version %d.",
                           model->version(), TFLITE_SCHEMA_VERSION);
      return;
    }

    // Pull in only the operation implementations we need.
    // This relies on a complete list of all the ops needed by this graph.
    // An easier approach is to just use the AllOpsResolver, but this will
    // incur some penalty in code space for op implementations that are not
    // needed by this graph.
    static tflite::MicroMutableOpResolver<3> micro_op_resolver;  // NOLINT
    micro_op_resolver.AddFullyConnected();
//    micro_op_resolver.AddRelu();
//    micro_op_resolver.AddTanh();
    micro_op_resolver.AddLeakyRelu();
    micro_op_resolver.AddSoftmax();
    
//    static tflite::AllOpsResolver micro_op_resolver;

    // Build an interpreter to run the model with.
    static tflite::MicroInterpreter static_interpreter(
        model, micro_op_resolver, tensor_arena, kTensorArenaSize, error_reporter);
    interpreter = &static_interpreter;
  
    // Allocate memory from the tensor_arena for the model's tensors.
    TfLiteStatus allocate_status = interpreter->AllocateTensors();
    if (allocate_status != kTfLiteOk) {
        printf("AllocateTensors() failed");
      TF_LITE_REPORT_ERROR(error_reporter, "AllocateTensors() failed");
      return;
    }

    // Set model input settings'
    TfLiteTensor* model_input = interpreter->input(0);
    printf(" Input Dim Size: %d\r\n Input Shape: (%d, %d)\r\n Input Type: %d\r\n", model_input->dims->size, model_input->dims->data[0],
            model_input->dims->data[1], model_input->dims->data[2], model_input->dims->data[3]);

    if ((model_input->dims->size != 2) || (model_input->dims->data[0] != 1) ||
           (model_input->dims->data[1] != INPUT_SHAPE) || (model_input->type != kTfLiteInt8)) 
    {
            printf("Bad input tensor parameters in model\r\n");
            TF_LITE_REPORT_ERROR(error_reporter,
                    "Bad input tensor parameters in model");
             return;
    }

    // Set model output settings
    TfLiteTensor* model_output = interpreter->output(0);
    printf("\r\n Output Dim Size: %d\r\n Output Shape: (%d, %d)\r\n",model_output->dims->size, model_output->dims->data[0], model_output->dims->data[1]);
            
    if ((model_output->dims->size != 2) || (model_output->dims->data[0] != 1) ||
        (model_output->dims->data[1] != OUTPUT_SHAPE) ||
        (model_output->type != kTfLiteInt8)) 
    {
        printf("Bad input tensor parameters in model\r\n");
        TF_LITE_REPORT_ERROR(error_reporter,
                           "Bad output tensor parameters in model");
        return;
    }
}


bool tflite_runInference(void)
{
     APP_Msg_T appTFLite;

    // Obtain pointers to the model's input and output tensors.
    TfLiteTensor* input = interpreter->input(0);
    for (int i = 0; i < INPUT_SHAPE; i++) 
    {
//        input->data.int8[i] = test_data[i];
        input->data.int8[i] = accData[i];
    }
    
    // Run inference, and report any error
    TfLiteStatus invoke_status = interpreter->Invoke();
//     //Analyze the results to obtain a prediction
//    int gesture_index = PredictGesture(interpreter->output(0)->data.int8);
//    printf("Gesture: %d\r\n", gesture_index);
    
    // Parse the model output
    TfLiteTensor* output = interpreter->output(0);
//    float max_score = 0, score = 0;
    int8_t max_score = 0, score = 0;
    uint8_t max_index = 0;
    for (int i = 0; i < OUTPUT_SHAPE; ++i) 
    {
        score = output->data.int8[i];
        //out[i] = score;
        if ((i == 0) || (score > max_score))
        {
            max_score = score;
            max_index = i;
        }
    }

    appTFLite.msgId = APP_MSG_BLE_TRPS_SEND;
    appTFLite.msgData[0] = max_index;
//    appTFLite.msgData[1] = (int8_t)(max_score*127);
    appTFLite.msgData[1] = (int8_t)(max_score);
    appTFLite.msgData[2] = (uint8_t)VectorMagnitude(&accData[3]);
    OSAL_QUEUE_Send(&appData.appQueue, &appTFLite, 0);
//    printf("%s (%d - %d)\r\n", labels[max_index], max_index, max_score);
//    printf("%d ; %d ; %d ; %d\r\n",output->data.int8[0],output->data.int8[1],output->data.int8[2],output->data.int8[3]);

    if (invoke_status != kTfLiteOk) {
        TF_LITE_REPORT_ERROR(error_reporter, "Invoke failed ");
        return false;
    }


    return true;
}



