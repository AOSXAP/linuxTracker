#ifndef __LINUX_TRACKER_USAGE_CPU_H_
#define __LINUX_TRACKER_USAGE_CPU_H_

namespace helper
{
    
    struct Vals
    {
        double val1;
        double val2;
    };
    
    void stringCounter(int &c, char x[]);
    void concateArray(char x[], int i, int j);

    Vals monitor();
    void cpuTracker();

    class linuxInfo; class sysInfo;
}

#endif