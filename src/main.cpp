#include <iostream>
#include <fstream>

#include "linalg.h"
#include "layer.h"
#include "model.h"

#define out(x) std::cout << x << std::endl

typedef
std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>>
datatype;

datatype get_data(const std::string &filename) {
    std::ifstream datafile(filename);
    if (!datafile.is_open()) throw std::invalid_argument("Incorrect file name");
    size_t num_points;
    datafile >> num_points;

    datatype data;
    data.first.emplace_back();
    data.first.emplace_back();
    data.second.emplace_back();
    double x, y;
    for (size_t i = 0; i < num_points; ++i) {
//        if (i >= 5) {
//            continue;
//        }
        datafile >> x >> y;
        data.first[0].push_back(x);
        data.first[1].push_back(y);
        data.second[0].push_back(0);
    }
    for (size_t i = 0; i < num_points; ++i) {
//        if (i >= 5) {
//            continue;
//        }
        datafile >> x >> y;
        data.first[0].push_back(x);
        data.first[1].push_back(y);
        data.second[0].push_back(1);
    }
    return data;
}


double compare(const mdb &prediction, const mdb &Y) {
    size_t m = Y.get_cols();
    double coincide = 0.;
    for (size_t i = 0; i < m; ++i) {
        coincide += (double)(prediction(0, i) == Y(0, i));
    }
    return coincide / m;
}


int main() {


    // DEMO 1

//    auto train_data = get_data("data_generation/data_linear.txt");
//    mdb X_train_pts(train_data.first);
//    mdb Y_train_pts(train_data.second);
//    auto test_data = get_data("data_generation/data_linear_test.txt");
//    mdb X_test_pts(test_data.first);
//    mdb Y_test_pts(test_data.second);
//
//    def_layers_vector lin_reg_layers = {{1, "sigmoid"}};
//    Model linear_regression(2, lin_reg_layers, 0.01);
//
//    linear_regression.fit(X_train_pts, Y_train_pts, 4000, false);
//
//    mdb train_prediction = linear_regression.predict(X_train_pts);
//    mdb test_prediction = linear_regression.predict(X_test_pts);
//
//    std::cout.precision(5);
//    std::cout << "Accuracy on the train set: " << compare(train_prediction, Y_train_pts) * 100 << "%" << std::endl;
//    std::cout << "Accuracy on the test set: " << compare(test_prediction, Y_test_pts) * 100 << "%" << std::endl;


    // DEMO 2

//    auto train_data = get_data("data_generation/data_clumped_4_point.txt");
//    mdb X_train_pts(train_data.first);
//    mdb Y_train_pts(train_data.second);
//    auto test_data = get_data("data_generation/data_clumped_4_point_test.txt");
//    mdb X_test_pts(test_data.first);
//    mdb Y_test_pts(test_data.second);
//
//    def_layers_vector shallow_layers = {{3, "relu"}, {1, "sigmoid"}};
//    Model shallow_model(2, shallow_layers, 0.01);
//
//    shallow_model.fit(X_train_pts, Y_train_pts, 10000, false);
//
//    mdb train_prediction = shallow_model.predict(X_train_pts);
//    mdb test_prediction = shallow_model.predict(X_test_pts);
//
//    std::cout.precision(5);
//    std::cout << "Accuracy on the train set: " << compare(train_prediction, Y_train_pts) * 100 << "%" << std::endl;
//    std::cout << "Accuracy on the test set: " << compare(test_prediction, Y_test_pts) * 100 << "%" << std::endl;


    // DEMO 3

//    auto train_data = get_data("data_generation/data_noisy_4_point.txt");
//    mdb X_train_pts(train_data.first);
//    mdb Y_train_pts(train_data.second);
//    auto test_data = get_data("data_generation/data_noisy_4_point_test.txt");
//    mdb X_test_pts(test_data.first);
//    mdb Y_test_pts(test_data.second);
//
//    def_layers_vector deep_layers = {{3, "relu"}, {2, "relu"}, {1, "sigmoid"}};
//    Model deep_model(2, deep_layers, 0.01);
//
//    deep_model.fit(X_train_pts, Y_train_pts, 20000, false);
//
//    mdb train_prediction = deep_model.predict(X_train_pts);
//    mdb test_prediction = deep_model.predict(X_test_pts);
//
//    std::cout.precision(5);
//    std::cout << "Accuracy on the train set: " << compare(train_prediction, Y_train_pts) * 100 << "%" << std::endl;
//    std::cout << "Accuracy on the test set: " << compare(test_prediction, Y_test_pts) * 100 << "%" << std::endl;
}