# Neural Network library for C++

## Authors

- [Yarema Mishchenko](https://github.com/RavenbornJB)
- [Bohdan Sydor](https://github.com/sydorbogdan)

## Project idea

TensorTorch is a C++ low-level framework that implements various deep learning tools.

We provide ways to create sequential models of arbitrary size, apply different optimizing strategies,
save and load models, and other things.

Our implementations use multiple C++-available parallelism techniques, which allows TensorTorch
to compete with modern open deep learning frameworks.

### In development
TensorTorch is still in development and a lot is currently missing from the library.
TensorTorch is also a production title, which may be changed at release.

Currently, there are no strict plans for the future of the library. The authors will continue to expand it, however,
there is no planned release date for now.

## Library

TensorTorch currently provides tools for creating sequential models of conventional networks and recurrent networks.

It uses Eigen as its main linear algebra base and ArrayFire as a secondary method.

We use our own .ttwf (TensorTorch Weight Format) format for storing models, which users can share and load at any time.

TensorTorch applies parallelism to improve its training and testing times. We use native threading tools and Eigen's
internal OpenMP structures to process data simultaneously. We also provide a version of our tools that uses ArrayFire
to utilize GPUs in parallelizing.

### Access and documentation

As of now (last update date below), TensorTorch does not yet have a website. Therefore, the only way to
use the library is to download the raw sources from this GitHub repository and compile it as a library
(without `src/main.cpp`, of course)

For the same reason, there is no actively maintained documentation for the project. This is coming to the website
in a later release.

### Eigen

Since Eigen is a header-only library, we provide its files in `/Eigen`. Upon release, this will be modified so that
an installation script downloads Eigen and puts it in your local include path,
instead of storing it with the library directly.

### Datasets

In the `/data_generation` directory we have presented a few sample datasets which could be used to test your library.
In a future release, we will add automatic testing that will use these to assess the quality of your installation.

There are also present python scripts that were, in one way or another, used to generate these datasets.

### Models

In the `/models` directory we have a few sample models saved with the .ttwf (TensorTorch Weight Format) extension.
You can try loading these with

    Model model = Model::Load(models/filename-without-extension)

### Features

#### Architectures
1. Classic (with dense layers)
2. RNN

#### Optimizers
1. GD
2. SGD
3. Batch GD

#### Parallelism
1. By batches
2. Forward and backward propagation operations
3. Model which uses GPU (with ArrayFire) 

#### Additional features
1. Model save and load
2. Batch normalization
3. Regularization

### Example
```
// Loads data
auto train_data = get_data("../data_generation/shuffled_data_noisy_4_point.txt");
MatrixXd X_train_pts = matrix_from_vector2d(train_data.first);
MatrixXd Y_train_pts = matrix_from_vector2d(train_data.second);
// Creates array of pointers to layers
std::vector<Layers::Layer *> layers = {
        new Layers::Dense(2, 500, new Activations::Relu, "he"),
        new Layers::Dense(500, 500, new Activations::Relu, "he"),
        new Layers::Dense(500, 50, new Activations::Relu, "he"),
        new Layers::Dense(50, 1, new Activations::Sigmoid, "he")};
// Model initialization
Model model(layers);
// Model compilation
model.compile(
        new Losses::BinaryCrossentropy(),
        new Optimizers::Parallel(128, 0.1));
// Model training
model.fit(X_train_pts, Y_train_pts, 100);
```
---

Last update date: June 11, 2021
