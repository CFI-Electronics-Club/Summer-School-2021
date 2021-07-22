#include <TensorFlowLite_ESP32.h>
#include <analogWrite.h>

#include "output_handler.h"
#include "sine_model.h"
#include "tensorflow/lite/experimental/micro/kernels/all_ops_resolver.h"
#include "tensorflow/lite/experimental/micro/micro_error_reporter.h"
#include "tensorflow/lite/experimental/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

            
// Some settings
constexpr int led_pin = 2;
constexpr float pi = 3.14159265;                  // Some pi
constexpr float freq = 0.25;                       // Frequency (Hz) of sinewave
constexpr float period = (1 / freq) * (1000000);

// Globals, used for compatibility with Arduino-style sketches.
namespace {
tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

// Create an area of memory to use for input, output, and intermediate arrays.
// Finding the minimum value for your model may require some trial and error.
constexpr int kTensorArenaSize = 2 * 1024;
uint8_t tensor_arena[kTensorArenaSize];
}  // namespace

// The name of this function is important for Arduino compatibility.
void setup() {
  // NOLINTNEXTLINE(runtime-global-variables)
  static tflite::MicroErrorReporter micro_error_reporter;
  error_reporter = &micro_error_reporter;

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  model = tflite::GetModel(sine_model);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    error_reporter->Report(
        "Model provided is schema version %d not equal "
        "to supported version %d.",
        model->version(), TFLITE_SCHEMA_VERSION);
    return;
  }

  // This pulls in all the operation implementations we need.
  // NOLINTNEXTLINE(runtime-global-variables)
  static tflite::ops::micro::AllOpsResolver resolver;

  // Build an interpreter to run the model with.
  static tflite::MicroInterpreter static_interpreter(
      model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
  interpreter = &static_interpreter;

  // Allocate memory from the tensor_arena for the model's tensors.
  TfLiteStatus allocate_status = interpreter->AllocateTensors();
  if (allocate_status != kTfLiteOk) {
    error_reporter->Report("AllocateTensors() failed");
    return;
  }

  // Obtain pointers to the model's input and output tensors.
  input = interpreter->input(0);
  output = interpreter->output(0);

    // Let's make an LED vary in brightness
  pinMode(led_pin, OUTPUT);
  #if DEBUG
  while(!Serial);
#endif

  
}

// The name of this function is important for Arduino compatibility.
void loop() {
  // Get current timestampwith period
  unsigned long timestamp = micros();
  timestamp = timestamp % (unsigned long)period;

  // Calculate x value to feed to the model
  float x_val = ((float)timestamp * 2 * pi) / period;

  // Place our calculated x value in the model's input tensor
  input->data.f[0] = x_val;

  // Run inference, and report any error
  TfLiteStatus invoke_status = interpreter->Invoke();
  if (invoke_status != kTfLiteOk) {
    error_reporter->Report("Invoke failed on x_val: %f\n",
                           static_cast<double>(x_val));
    return;
  }
  

  // Read the predicted y value from the model's output tensor
  float y_val = output->data.f[0];
  
  // Translate to a PWM LED brightness
  int brightness = (int)(255 * y_val);
  analogWrite(led_pin, brightness);

  // Print value
  Serial.println(y_val);

#if DEBUG
  Serial.print("Time for inference (us): ");
  Serial.println(micros() - start_timestamp);
#endif

  // Output the results. A custom HandleOutput function can be implemented
  // for each supported hardware target.
  HandleOutput(error_reporter, x_val, y_val);

  
}
