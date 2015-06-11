#!/bin/tcsh -f

rm rootfiles/signal_limit_0.root
rm rootfiles/signal_limit_8.root


setenv dir1  ../results/yedek/AnaMonoJet/
setenv dir2  ../results/AnaMonoJet/

setenv dir3  ../results/yedek/AnaZ/
setenv dir4  ../results/yedek/AnaWminus/
setenv dir5  ../results/yedek/AnaWplus/


cp $dir2/$1_AnaMonoJet_0.root rootfiles/signal_limit_0.root
cp $dir2/$1_AnaMonoJet_8.root rootfiles/signal_limit_8.root

