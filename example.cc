#include "edgetpu.h"
#include "src/cpp/examples/model_utils.h"

int main(int argc, char* argv[]) {

}

/*
  // Load the compiled Edge Tpu model as a FlatBufferModel 
  if (argc != 2) {
    fprintf(stderr, "<tflite model>\n");
    return 1;
  }

  const std::string model_path = argv[1];
  // 1. Create tflite::FlatBufferModel which may contain edge TPU custom op.
  //
  //const std::string model_path = "/home/mendel/yolov3-tflite2-coral/checkpoints_tflite/yolov3_OSIZE_ncT_nquT.tflite";
  std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(model_path.c_str());

  // 2. Enumerate edge TPU devices.
  //
  /* EdgeTpuManager is responsible for instantiating TPUs. Usually, there is one EdgeTpu to work with *
   * so you can instantiate this with EdgeTpuManager::OpenDevice(). But it's possible to use multiple *
   * TPUs, so this method is overloaded so you can specify which Edge Tpu you want to use.            *
  std::shared_ptr<edgetpu::EdgeTpuContext> edgetpu_context = edgetpu::EdgeTpuManager::GetSingleton()->OpenDevice();
  edgetpu::EdgeTpuManager::SetVerbosity(10);

  // 3. Create and Build the Interpreter
  //
  std::unique_ptr<tflite::Interpreter> model_interpreter = BuildEdgeTpuInterpreter(model, edgetpu_context.get());

  // 4. Resize input tensors, if desired
  //
  model_interpreter->AllocateTensors();
  printf("=== Pre-invoke Interpreter State ===\n");
  tflite::PrintInterpreterState(model_interpreter.get());
  float* input = model_interpreter->typed_input_tensor<float>(0);
  // Fill 'input'.
  //TODO(Christos): Insert code to fill input tensors.
  model_interpreter->Invoke();
  printf("\n\n=== Post-invoke Interpreter State ===\n");
  tflite::PrintInterpreterState(model_interpreter.get());
  float* output = model_interpreter->typed_output_tensor<float>(0);
  // Fill 'output'.
  // TODO(Christos): Insert code to getting data out.

  model_interpreter.reset();
  edgetpu_context.reset();
  
*/