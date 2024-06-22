//libraries included via NuGet
#include "inference.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    //there's a couple of ways to go on about file handling, either use argv to link them via CLI or declare
    //the absolute path in code. Here argv is prefered. Trigger error if model_path or image_path is not specified. 
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <model_path> <image_path>" << std::endl;
        return 1;
    }
    //Here's a little change from the main branch, the model path is handled like a wchar_t in the onnxruntime_cxx_api.h document
    //so we a char to point to the model_path. 
    const char* model_path = argv[1];
    std::wostringstream wss;
    wss << model_path;
    //opencv has no trouble handling strings, so I decided to keep it the same:
    std::string image_path = argv[2];

    try
    {
        InferenceEngine engine(wss);


        cv::Mat image = cv::imread(image_path);
        int orig_width = image.cols;
        int orig_height = image.rows;
        std::vector<float> input_tensor_values = engine.preprocessImage(image);

        std::vector<float> results = engine.runInference(input_tensor_values);

        float confidence_threshold = 0.5;


        std::vector<Detection> detections = engine.filterDetections(results, confidence_threshold, engine.input_shape[2], engine.input_shape[3], orig_width, orig_height);

        cv::Mat output = engine.draw_labels(image, detections);
        //the result file will be saved in the build folder:
        cv::imwrite("result.jpg", output);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
