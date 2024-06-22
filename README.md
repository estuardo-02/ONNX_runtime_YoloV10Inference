# ONNX_runtime_YoloV10Inference
Here's an example on how to implement yolov10 inference using cpp for image labeling. It is a modified version of the following repo: https://github.com/DanielSarmiento04/yolov10cpp

## Dependencies
Visual Studio 22
ONNX runtime
OpenCV

## How to install
Use NuGet to install the following packages:
- Microsoft.ML.OnnxRuntime   tested => version=1.18.0
- OpenCV.Win.Core            tested => version=310.6.1
- OpenCV.Win.ImgCodecs       tested => version=310.6.1
- OpenCV.Win.ImgProc         tested => version=310.6.1

## Load the model: 
Download the onnx model here: https://github.com/rlggyp/YOLOv10-OpenVINO-CPP-Inference/raw/model/assets/yolov10n.onnx

## Usage 
run the generated .exe file using visual studio developer PowerShell

./OnnxRuntimeResNet <model_path.onnx> <video_path>
