MAKEFILE_DIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))
TENSORFLOW_DIR ?= $(MAKEFILE_DIR)/../tensorflow
SRC := example.cc
IFLAGS := -I$(MAKEFILE_DIR)/../edgetpu/ \
		  -I$(MAKEFILE_DIR)/../edgetpu/libedgetpu/ \
		  -I$(TENSORFLOW_DIR) \
		  -I$(TENSORFLOW_DIR)/tensorflow/lite/tools/make/downloads/flatbuffers/include
LDFLAGS := -L$(TENSORFLOW_DIR)/tensorflow/lite/tools/make/gen/linux_aarch64/lib \
		  -L$(MAKEFILE_DIR)/../edgetpu/libedgetpu/direct/aarch64/ \
		  -ltensorflow-lite -l:libedgetpu.so.1.0 -lpthread -lm -ldl
 
customOp: $(SRC)
		 aarch64-linux-gnu-g++ -std=c++11 $^ -o $@  $(IFLAGS) $(LDFLAGS)

printss:
		 @echo "make dir: ${MAKEFILE_DIR}"
		 @echo "tensorfow dir: ${TENSORFLOW_DIR}"
		 @echo "src: $(SRC)"
		 @echo "instr flags: $(IFLAGS)"
		 @echo "lib flags: $(LFLAGS)"

clean:
		rm -f customOp
