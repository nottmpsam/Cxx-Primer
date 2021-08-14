#ifndef HEADER
#define HEADER

namespace SALES
{
    class Sales
    {
        enum {QUARTES = 4};
        double sales[QUARTES];
        double average;
        double max;
        double min;
    public:
        Sales(const double *arr, int n);
        Sales();
        void showSales() const;
    };
}

#endif 
