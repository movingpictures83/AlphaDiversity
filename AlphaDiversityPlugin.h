#ifndef ALPHADIVERSITYPLUGIN_H
#define ALPHADIVERSITYPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class AlphaDiversityPlugin : public Plugin
{
public: 
 std::string toString() {return "AlphaDiversity";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
 std::vector<std::string> metrics;
 bool treeflag;
};

#endif
