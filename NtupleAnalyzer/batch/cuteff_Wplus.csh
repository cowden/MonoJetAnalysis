#!/bin/tcsh -f


SubmitCondor   met1             AnaWplusCutEff  0 cuteff
SubmitCondor   met2             AnaWplusCutEff  0 cuteff
SubmitCondor   met3             AnaWplusCutEff  0 cuteff
SubmitCondor   met4             AnaWplusCutEff  0 cuteff
SubmitCondor   met5             AnaWplusCutEff  0 cuteff
SubmitCondor   met6             AnaWplusCutEff  0 cuteff



SubmitCondor   wjets           AnaWplusCutEff  1 cuteff
SubmitCondor   ttbar           AnaWplusCutEff  1 cuteff
SubmitCondor   zjets           AnaWplusCutEff  1 cuteff
SubmitCondor   znunu50         AnaWplusCutEff  1 cuteff
SubmitCondor   znunu100        AnaWplusCutEff  1 cuteff
SubmitCondor   znunu200        AnaWplusCutEff  1 cuteff


SubmitCondor   md2d2           AnaWplusCutEff  1 cuteff
SubmitCondor   qcd170          AnaWplusCutEff  1 cuteff
SubmitCondor   qcd300          AnaWplusCutEff  1 cuteff
SubmitCondor   qcd470          AnaWplusCutEff  1 cuteff
SubmitCondor   qcd600          AnaWplusCutEff  1 cuteff
SubmitCondor   qcd800          AnaWplusCutEff  1 cuteff
SubmitCondor   qcd1000         AnaWplusCutEff  1 cuteff
SubmitCondor   qcd1400         AnaWplusCutEff  1 cuteff
SubmitCondor   qcd1800         AnaWplusCutEff  1 cuteff
SubmitCondor   sintbars        AnaWplusCutEff  1 cuteff
SubmitCondor   sintbart        AnaWplusCutEff  1 cuteff
SubmitCondor   sintbartw       AnaWplusCutEff  1 cuteff
SubmitCondor   sintt           AnaWplusCutEff  1 cuteff
SubmitCondor   sinttw          AnaWplusCutEff  1 cuteff



























