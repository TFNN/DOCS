# How to use TFCNN

I'm going to keep this simple and only refer to the use of [FCNNv1.h](https://github.com/TFCNN/TFCNNv1), as [FCNNv2.h](https://github.com/TFCNN/TFCNNv2) is currently work-in-progress, although it is very similar; one can infer the differences autonomously. 

**Alright so lets set up a network:**
```
// let's create our network structure.
network net;

// and initialise the network ..
const uint number_of_inputs = 1;
const uint number_of_layers = 2;
const uint number_of_neurons_per_layer = 256;
createNetwork(&net, WEIGHT_INIT_UNIFORM_LECUN, number_of_inputs, number_of_layers, number_of_neurons_per_layer);

// maybe also you would like to change the default configured optimiser and activator
setOptimiser(&net, MOMENTUM);
setActivator(&net, TANH);
```

That's your network created! All you need to do now is train it.

Training the network is done using the multi-purpose function `float processNetwork(network* net, float* inputs, const learn_type learn);` which also performs queries on the network once it has been trained.

`processNetwork()` has three learning types;
- LEARN_MAX
- LEARN_MIN
- NO_LEARN

When training a network you either want to train towards your target, typically of 1, or away from your target 0.
- To train towards your target (1) you will use `LEARN_MAX` which will minimize the gradient descent, sloping down to a local minimum.
- To train away from your target (0) you will use `LEARN_MIN` which will maximize the gradient descent, sloping up away from a local minimum.

You can change the LEARN_MAX / LEARN_MIN target values via the hyperparameter accessors, eg;
```
void setTargetMin(&net, 0); // LEARN_MIN
void setTargetMax(&net, 1); // LEARN_MAX
```

Generally, for each training pass, you would train one epoch of your data using LEARN_MAX and then one epoch of random noise data using LEARN_MIN. This refines the network to only retrain details that are specific to the pattern you are teaching it to recognise.

For example; if you want to network to differentiate between words with positive or negative connotations you would LEARN_MAX the positive words and LEARN_MIN the negative.

The network is trained using floating-point data as input, as we set up the network with 1 input that means we need to feed in a vector of 1 floating-point numbers.

In this case, each number would represent the normalised index of a word in a dictionary or word list, I have not provided a word list below just some theoretical examples of floating-points that would reference such a list.
```
const float positive_words[10] = {0.9, 0.91, 0.8, 0.87, 0.73, 0.934, 0.67, 0.074, 0.703, 0.883};
const float negative_words[10] = {0.1, 0.01, 0.2, 0.13, 0.142, 0.056, 0.21, 0.023, 0.31, 0.312};

for(uint i = 0; i < 10; ++i)
{
  // learn to output 1 for positive words
  processNetwork(&net, positive_words[i], LEARN_MAX);

  // learn to output 0 for negative words
  processNetwork(&net, negative_words[i], LEARN_MIN);
}
```

**Once the network is trained we can test words against it using the `NO_LEARN` parameter.**
```
const float input = 0.9;
const float is_positive = processNetwork(&net, &input, NO_LEARN);

if(is_positive > 0.6)
  printf("Looks like the input was positive +\n");
else
  printf("Looks like the input was negative -\n");
```

**Once you are done you can clean up the network like so;**
```
destroyNetwork(&net);
```

**Or reset the network,** allowing you to retrain it from a fresh state. Resetting it will retain your configured hyperparameters but re-initialise the weights back to the configured method of initialisation. _(we specified `WEIGHT_INIT_UNIFORM_LECUN` in `createNetwork()` at the beginning of this document)_
```
resetNetwork(&net);
```

