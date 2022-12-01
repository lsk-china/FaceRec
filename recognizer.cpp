#include "recognizer.h"

Recognizer::Recognizer()
{
    if (access("haarcascade_frontalface_default.xml",  F_OK) != 0) {
        throw std::runtime_error("Face detector model doesn't exists.");
    }
    this->detector = new CascadeClassifier();
    this->detector->load("haarcascade_frontalface_default.xml");
    if (access(this->modelPath.c_str(), F_OK) == 0) {
        struct stat statbuf;
        stat(this->modelPath.c_str(), &statbuf);
        if (statbuf.st_size > 100) {
                this->modelTrained = true;
        }
        this->recoginzer = LBPHFaceRecognizer::create();
        this->recoginzer->read(this->modelPath);
    } else {
        this->recoginzer = LBPHFaceRecognizer::create();
    }
}

Mat Recognizer::faceDetect(Mat inp) {}

int Recognizer::recognize(Mat face, double &confidence) {}

void Recognizer::trainModel(vector<Mat> faces, vector<int> ids) {}

Recognizer::~Recognizer () {
    this->recoginzer->save(this->modelPath);
    delete recoginzer;
    delete detector;
}