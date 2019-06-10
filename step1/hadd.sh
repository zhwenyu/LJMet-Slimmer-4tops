#!/bin/bash

echo "HADDING NOMINAL"

python -u haddoutput.py LJMet94X_1lep_013019_step1 LJMet94X_1lep_013019_step1_hadds nominal

# echo "HADDING JECUP"
# 
# python -u haddoutput.py LJMet94X_1lep_013019_step1 LJMet94X_1lep_013019_step1_hadds JECup
# 
# echo "HADDING JECDOWN"
# python -u haddoutput.py LJMet94X_1lep_013019_step1 LJMet94X_1lep_013019_step1_hadds JECdown
# 
# echo "HADDING JERUP"
# 
# python -u haddoutput.py LJMet94X_1lep_013019_step1 LJMet94X_1lep_013019_step1_hadds JERup
# 
# echo "HADDING JERDOWN"
# 
# python -u haddoutput.py LJMet94X_1lep_013019_step1 LJMet94X_1lep_013019_step1_hadds JERdown

echo "DONE"
