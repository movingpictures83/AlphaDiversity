#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "AlphaDiversityPlugin.h"

void AlphaDiversityPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if ((key != "biomfile") && (key != "tree") && (key.length() > 0)) {
      metrics.push_back(key);
      if (key == "PD_whole_tree")
         treeflag = true;
   }
   else {
   ifile >> value;
   parameters[key] = value;
   }
 }
 
}

void AlphaDiversityPlugin::run() {
   
}

void AlphaDiversityPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   //std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; alpha_diversity.py ";
   std::string command = "alpha_diversity.py ";
 command += "-i "+parameters["biomfile"]+" -m ";
 for (int i = 0; i < metrics.size(); i++) {
    command += metrics[i];
    if (i != metrics.size()-1){command += ",";}
    else {command += " ";}
 }
 if (treeflag) {
 command += "-t "+parameters["tree"]+" ";
 }
 command += "-o "+file;//+"; export PYTHONPATH=OLDPATH";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<AlphaDiversityPlugin> AlphaDiversityPluginProxy = PluginProxy<AlphaDiversityPlugin>("AlphaDiversity", PluginManager::getInstance());
