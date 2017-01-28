#include <iostream>
#include <vector>
#include <utility>

#include "value.hpp"

using namespace std;


void print_pair(DerivedPair<double, double> p){
    pair<double, double> pr = p.get_value();
    cout << "(" << pr.first << ", " << pr.second << ")\n";
}

int main(int argc, const char* argv[]){
    /* Value<int, int> v; */
    double x = 12;
    double y = 12;

    ObservedValue<double> x_val(&x);
    ObservedValue<double> y_val(&y);

    DerivedPair<double, double> dp(&x_val, &y_val);
    print_pair(dp);
    x = 2;
    y = 2;
    print_pair(dp);

    ContainerVector<double> cont(&x_val);
    x = 12;
    cont.fill();
    x = 2;
    cont.fill();
    auto *container = cont.get_container();

    for( auto v: *container )
        cout << v << ", ";
    cout << endl;
    /* ValA val; */
    /* val.reset(); */
    /* Address x = val.get_value(); */
    /* cout << "Hello World " << x.street_address << "\n"; */
    /* x = val.get_value(); */
    /* cout << "Hello World " << x.street_address << "\n"; */
}
