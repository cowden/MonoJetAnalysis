#!/bin/tcsh -f


SubmitCondor   met1            AnaZCutEff  0 cuteff
SubmitCondor   met2            AnaZCutEff  0 cuteff
SubmitCondor   met3            AnaZCutEff  0 cuteff
SubmitCondor   met4            AnaZCutEff  0 cuteff
SubmitCondor   met5            AnaZCutEff  0 cuteff
SubmitCondor   met6            AnaZCutEff  0 cuteff


SubmitCondor   wjets           AnaZCutEff  1 cuteff
SubmitCondor   ttbar           AnaZCutEff  1 cuteff
SubmitCondor   zjets           AnaZCutEff  1 cuteff
SubmitCondor   znunu100        AnaZCutEff  1 cuteff
SubmitCondor   znunu200        AnaZCutEff  1 cuteff

SubmitCondor   md2d2           AnaZCutEff  1 cuteff
SubmitCondor   qcd170          AnaZCutEff  1 cuteff
SubmitCondor   qcd300          AnaZCutEff  1 cuteff
SubmitCondor   qcd470          AnaZCutEff  1 cuteff
SubmitCondor   qcd600          AnaZCutEff  1 cuteff
SubmitCondor   qcd800          AnaZCutEff  1 cuteff
SubmitCondor   qcd1000         AnaZCutEff  1 cuteff
SubmitCondor   qcd1400         AnaZCutEff  1 cuteff
SubmitCondor   qcd1800         AnaZCutEff  1 cuteff
SubmitCondor   sintbars        AnaZCutEff  1 cuteff
SubmitCondor   sintbart        AnaZCutEff  1 cuteff
SubmitCondor   sintbartw       AnaZCutEff  1 cuteff
SubmitCondor   sintt           AnaZCutEff  1 cuteff
SubmitCondor   sinttw          AnaZCutEff  1 cuteff



























