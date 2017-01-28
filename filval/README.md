A FILter-VALue System
=====================
This is a header-only, generic, data analysis system that allows for creating performant generation of *Plots*. *Plots* contain *Values* and can make use of *Filters*.
*Filters* can also depend of *Values*, and *Values* can depend on other *Values*. A *Dataset* is a generic object that contains a series of observations. The individual observations
consist of a series of *Observed Values*. One can also define *Derived Values* which are calculated from *Observed Values* or other *Derived Values*. Care is taken automatically 
so *Derived Values* are calculated at most once per observation.



```C++
MyDataSet myDataSet("somefile.root", "tree"); // MyDataSet subclasses DataSet
TTreeValue<int> countmyDataSet;
myDataSet.addValue

Hist1D myplot(count, myDataSet, ); // Hist1D subclasses Plot
```
