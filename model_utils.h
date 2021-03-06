#ifdef EDGETPU_CPP_EXAMPLES_MODEL
#define EDGETPU_CPP_EXAMPLES_MODEL

#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "edgetpu.h"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/model.h"

namespace coral {

std::unique_ptr<tflite::Interpreter> BuildEdgeTpuInterpreter(
    const tflite::FlatBufferModel& model,
    edgetpu::EdgeTpuContext* edgetpu_context
    );

//Runs inference using given interpreter.
std::vector<float> RunInference(
    const std::vector<uint8_t>& input_data,
    tflite::Interpreter* interpreter
    );

// Returns input tensor shape in the form {height, width, channels}.
std::array<int, 3> GetInputShape(
    const tflite::Interpreter& interpreter,
    int index
    );
                        
} // namespace coral
#endif // EDGETPU_CPP_EXAMPLES_MODEL