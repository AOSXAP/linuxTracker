#include "sys_info.h"

#include <iostream>
#include <iomanip>
#include <fstream>

//LINUX GENERAL SYSTEM AND KERNEL INFO


linuxInfo::linuxInfo()
{
    uname(&uts);
}

void linuxInfo::KAV()
{
    //kernel and version
    std::cout << uts.sysname << " " << uts.release << " ";
}

void linuxInfo::Arhitecture()
{
    //arhitecture
    std::cout << uts.machine << " ";
}

void linuxInfo::distroName()
{
    //use command and store output in temp.txt
    system("cat /etc/os-release | grep -w 'NAME' > temp.txt");

    //init file and read everything from it
    std::ifstream f("temp.txt");

    std::string str((std::istreambuf_iterator<char>(f)),
                    std::istreambuf_iterator<char>());

    //close stream , remove the file and format output
    f.close();
    remove("temp.txt");
    std::cout << str.erase(0, 5);
}

//UPTIME , RAM , NUMBER OF PROCESSES


sysInfo::sysInfo()
{
    sysinfo(&info);
}

std::string sysInfo::uptime( int s )
{
    //seconds to time
    int minutes = 0, hours = 0;

    minutes = s / 60, s -= (minutes * 60);

    hours = minutes / 60, minutes -= (hours * 60);

    return std::to_string( hours ) + " hours " + std::to_string( minutes ) + " minutes " + std::to_string( s ) + " seconds ";

}

sysInfo::impSysInfo sysInfo::getValues()
{
    impSysInfo Container;

    Container.totalram = info.totalram;

    Container.procs = info.procs, Container.uptime = info.uptime;

    return Container;
}
