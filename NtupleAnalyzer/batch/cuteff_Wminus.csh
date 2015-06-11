#!/bin/tcsh -f


SubmitCondor   met1            AnaWminusCutEff  0 cuteff
SubmitCondor   met2            AnaWminusCutEff  0 cuteff
SubmitCondor   met3            AnaWminusCutEff  0 cuteff
SubmitCondor   met4            AnaWminusCutEff  0 cuteff
SubmitCondor   met5            AnaWminusCutEff  0 cuteff
SubmitCondor   met6            AnaWminusCutEff  0 cuteff

SubmitCondor   wjets           AnaWminusCutEff  1 cuteff
SubmitCondor   ttbar           AnaWminusCutEff  1 cuteff
SubmitCondor   zjets           AnaWminusCutEff  1 cuteff
SubmitCondor   znunu100        AnaWminusCutEff  1 cuteff
SubmitCondor   znunu200        AnaWminusCutEff  1 cuteff

SubmitCondor   md2d2           AnaWminusCutEff  0 cuteff
SubmitCondor   qcd170          AnaWminusCutEff  1 cuteff
SubmitCondor   qcd300          AnaWminusCutEff  1 cuteff
SubmitCondor   qcd470          AnaWminusCutEff  1 cuteff
SubmitCondor   qcd600          AnaWminusCutEff  1 cuteff
SubmitCondor   qcd800          AnaWminusCutEff  1 cuteff
SubmitCondor   qcd1000         AnaWminusCutEff  1 cuteff
SubmitCondor   qcd1400         AnaWminusCutEff  1 cuteff
SubmitCondor   qcd1800         AnaWminusCutEff  1 cuteff
SubmitCondor   sintbars        AnaWminusCutEff  1 cuteff
SubmitCondor   sintbart        AnaWminusCutEff  1 cuteff
SubmitCondor   sintbartw       AnaWminusCutEff  1 cuteff
SubmitCondor   sintt           AnaWminusCutEff  1 cuteff
SubmitCondor   sinttw          AnaWminusCutEff  1 cuteff



























