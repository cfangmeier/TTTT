/**
 * @file
 * @author  Caleb Fangmeier <caleb@fangmeier.tech>
 * @version 0.1
 *
 * @section LICENSE
 *
 *
 * MIT License
 *
 * Copyright (c) 2017 Caleb Fangmeier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @section DESCRIPTION
 * A short example demonstrating some of the basic functionality of the FilVal
 * Value system.
 */

#include <iostream>
#include <utility>

#include "filval/filval.hpp"

int main(int argc, const char* argv[]){
    // Initialize logging. Let's not worry about what is being logged right now
    // and just redirect it to /dev/null so it doesn't appear on the screen.
    fv::util::Log::init_logger("/dev/null", fv::util::LogPriority::kLogDebug);

    // declare a helper function to print out a std::pair object
    auto print_pair = [](fv::Value<std::pair<double, double>>* dp){
        std::pair<double, double> p = dp->get_value();
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    };

    // These variables are the "Values" that will be observed. Think of these
    // as sources of data that will be updated as new observations are loaded.
    double x = 12;
    double y = 13;

    // This is where the fun begins. Here we declare a couple ObservedValue
    // objects. these are basically just fancy wrappers around the x, and y
    // variables declared above. They have the job of supplying the value
    // stored by x and y when requested.
    fv::ObservedValue<double> x_val("x", &x);
    fv::ObservedValue<double> y_val("y", &y);

    // Now that we have a few source values, let's compose them together into a
    // pair. The fv api defines a function to do this: fv::pair. This function
    // takes pointers to two Value objects and creates a new value that is a
    // std::pair of these objects.
    fv::Value<std::pair<double, double>>* dp = fv::pair(&x_val, &y_val);

    // If we call the print_pair function that we declared earlier with the new
    // value object, we can see that, indeed, we see the correct output
    // (12, 13)
    print_pair(dp);

    // Now let's update the values of x and y to both be 2. Normally this job
    // will be handled by a DataSet object which manages these variables, but
    // we can do it here for now.
    x = 2;
    y = 2;

    // Before we can access these new values through our value chain, we need
    // to tell the values to "reset". One of the main features of FV is that
    // each value is only calculated at most once per observation, regardless
    // of how many times it is accessed. However, this means that we have to
    // tell the objects when a new object has been loaded so it will actually
    // do a re-calculation. In the case of dp, this means that it will
    // re-access the values of x and y and create a new pair with the updated
    // values.
    fv::GenValue::reset();

    // Call print_pair again just to verify that it gives the updated values,
    // and indeed it does.
    // (2, 2)
    print_pair(dp);

    return 0;
}
