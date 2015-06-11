#!/bin/tcsh -f


source  /uscms_data/d2/lpcjm/DATA/RECENT_FILES.csh



AnaMonoJet  $md1d2_path  md1d2_p   $data  100000000   0&
AnaMonoJet  $md2d2_path  md2d2_p   $data  100000000   0&
AnaMonoJet  $md3d2_path  md3d2_p   $data  100000000   0&

AnaMonoJet  $md1d4_path  md1d4_p   $data  100000000   0&
AnaMonoJet  $md2d4_path  md2d4_p   $data  100000000   0&
AnaMonoJet  $md3d4_path  md3d4_p   $data  100000000   0&

AnaMonoJet  $md1d6_path  md1d6_p   $data  100000000   0&
AnaMonoJet  $md2d6_path  md2d6_p   $data  100000000   0&
AnaMonoJet  $md3d6_path  md3d6_p   $data  100000000   0&

