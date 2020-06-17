# Language: C++
# Input: TXT
# Output: TXT
# Tested with: PluMA 1.0, GCC 4.8.4

PluMA plugin to compute alpha-diversity of a set of samples using Qiime (Caporaso et al, 2010).

The plugin accepts as input a TXT file containing lines with keywords and values (whitespaced-delimited),
followed by the metrics you wish to use to compute alpha-diversity.

Alpha-diversity measures will then be output as a table, with one row per sample and one column per metric.

Note: This plugin works with Qiime 1, which is only compatible with Python 2.  Since PluMA has been
upgraded to use Python 3, you must set the following two environment variables for this to work:

PYTHON2_SITE_PACKAGES
PYTHON2_DIST_PACKAGES

This way the Python 2 environment can be loaded and unloaded properly at runtime.
