#include "edgetpu.h"

std::unique_ptr BuildEdgeTpuInterpreter(
    const tflite::FlatBufferModel& model,
    edgetpu::EdgeTpuContext* edgetpu_context
  )
{
  // Add custom op and Build interpreter.
  //
  tflite::ops::builtin::BuiltinOpResolver resolver;
  resolver.AddCustom(edgetpu::kCustomOp, edgetpu::RegisterCustomOp());
  std::unique_ptr interpreter;
  if (tflite::InterpreterBuilder(model, resolver)(&interpreter) != kTfLiteOk) {
    std::cerr << "Failed to build interpreter." << std.endl;
  }

  //Bind given context with intepreter.
  //
  interpreter->SetExternalContext(kTfLiteEdgeTpuContext, edgetpu_context);
  interpreter->SetNumThreads(1);
  if (interpreter->allocateTensors() != kTfliteOk) {
    std::cerr << "Failed to allocate tensors." << std::endl;
  }
  return interpreter;
}


