#ifndef __LINUX_TRACKER_SYS_INFO_H_
#define __LINUX_TRACKER_SYS_INFO_H_

#include <string>

//LINUX GENERAL SYSTEM AND KERNEL INFO

#include <sys/utsname.h>

class linuxInfo
{
private:
    struct utsname uts;

public:
    linuxInfo();

    //kernel and version
    void KAV();

    //arhitecture
    void Arhitecture();

    void distroName();
};

//UPTIME , RAM , NUMBER OF PROCESSES

#include <sys/sysinfo.h>

class sysInfo
{
public:
    struct sysinfo info;

    struct impSysInfo
    {
        unsigned long totalram;
        unsigned long procs;
        long uptime;
    };

    sysInfo();

    std::string uptime(int s);

    impSysInfo getValues();

};

#endif
