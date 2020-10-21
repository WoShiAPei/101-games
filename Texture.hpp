//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        if(u<0)u = 0;
        if(u>1)u = 1;
        if(v<0)v = 0;
        if(v>1)v = 1;
        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        auto u_min = floor(u_img),v_min = floor(v_img);
        auto u_max = std::min(width*1.0f,ceil(u_img)),v_max = std::min(height*1.0f,ceil(v_img));
        auto rs = (u_img - u_min)/(u_max - u_min);
        auto rt = (v_img - v_min)/(v_max - v_min);
        auto ctop = image_data.at<cv::Vec3b>(v_max,u_min)*(1-rs) + image_data.at<cv::Vec3b>(v_max,u_max)*rs;
        auto cbot = image_data.at<cv::Vec3b>(v_min,u_min)*(1-rs) + image_data.at<cv::Vec3b>(v_min, u_max)*rs;
//        auto u_img2 = (1-u)*width;
//        auto v_img2 = v*height;
//        auto u_img = u*u_img1+(1-u)*u_img2;
//        auto v_img = v*v_img1+(1-v)*v_img2;
       // auto color = cbot*(1-rt)+ctop*rt;
        auto color = image_data.at<cv::Vec3b>(v_img,u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

};
#endif //RASTERIZER_TEXTURE_H
