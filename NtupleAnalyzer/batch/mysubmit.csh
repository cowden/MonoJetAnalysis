#!/bin/tcsh -f


SubmitCondor    met1           AnaMonoJet  0  cutorder
SubmitCondor    met2           AnaMonoJet  0  cutorder
SubmitCondor    met3           AnaMonoJet  0  cutorder
SubmitCondor    met4           AnaMonoJet  0  cutorder
SubmitCondor    met5           AnaMonoJet  0  cutorder
SubmitCondor    met6           AnaMonoJet  0  cutorder
SubmitCondor    met7           AnaMonoJet  0  cutorder


SubmitCondor    wjets1          AnaMonoJet  1  cutorder
SubmitCondor    wjets2          AnaMonoJet  1  cutorder
SubmitCondor    wjets3          AnaMonoJet  1  cutorder

SubmitCondor    ttbar          AnaMonoJet  1  cutorder
SubmitCondor    zjets          AnaMonoJet  1  cutorder

SubmitCondor    znunu50        AnaMonoJet  1  cutorder
SubmitCondor    znunu100       AnaMonoJet  1  cutorder
SubmitCondor    znunu200       AnaMonoJet  1  cutorder
SubmitCondor    znunu400       AnaMonoJet  1  cutorder


SubmitCondor    qcd300         AnaMonoJet  1  cutorder
SubmitCondor    qcd470         AnaMonoJet  1  cutorder
SubmitCondor    qcd600         AnaMonoJet  1  cutorder
SubmitCondor    qcd800         AnaMonoJet  1  cutorder
SubmitCondor    qcd1000        AnaMonoJet  1  cutorder
SubmitCondor    qcd1400        AnaMonoJet  1  cutorder
SubmitCondor    qcd1800        AnaMonoJet  1  cutorder

SubmitCondor    sintbars       AnaMonoJet  1  cutorder
SubmitCondor    sintbart       AnaMonoJet  1  cutorder
SubmitCondor    sintbartw      AnaMonoJet  1  cutorder
SubmitCondor    sints          AnaMonoJet  1  cutorder
SubmitCondor    sintt          AnaMonoJet  1  cutorder
SubmitCondor    sinttw         AnaMonoJet  1  cutorder


SubmitCondor    md2d3          AnaMonoJet  1  cutorder
SubmitCondor    dmavd1         AnaMonoJet  1  cutorder



------------------------------------------------------------------


SubmitCondor    met1           AnaMuon  0  cutorder
SubmitCondor    met2           AnaMuon  0  cutorder
SubmitCondor    met3           AnaMuon  0  cutorder
SubmitCondor    met4           AnaMuon  0  cutorder
SubmitCondor    met5           AnaMuon  0  cutorder
SubmitCondor    met6           AnaMuon  0  cutorder
SubmitCondor    met7           AnaMuon  0  cutorder


SubmitCondor    wjets1          AnaMuon  1  cutorder
SubmitCondor    wjets2          AnaMuon  1  cutorder
SubmitCondor    wjets3          AnaMuon  1  cutorder


SubmitCondor    ttbar          AnaMuon  1  cutorder
SubmitCondor    zjets          AnaMuon  1  cutorder

SubmitCondor    znunu50        AnaMuon  1  cutorder
SubmitCondor    znunu100       AnaMuon  1  cutorder
SubmitCondor    znunu200       AnaMuon  1  cutorder
SubmitCondor    znunu400       AnaMuon  1  cutorder


SubmitCondor    qcd170         AnaMuon  1  cutorder
SubmitCondor    qcd300         AnaMuon  1  cutorder
SubmitCondor    qcd470         AnaMuon  1  cutorder
SubmitCondor    qcd600         AnaMuon  1  cutorder
SubmitCondor    qcd800         AnaMuon  1  cutorder
SubmitCondor    qcd1000        AnaMuon  1  cutorder
SubmitCondor    qcd1400        AnaMuon  1  cutorder
SubmitCondor    qcd1800        AnaMuon  1  cutorder

SubmitCondor    sintbars       AnaMuon  1  cutorder
SubmitCondor    sintbart       AnaMuon  1  cutorder
SubmitCondor    sintbartw      AnaMuon  1  cutorder
SubmitCondor    sints          AnaMuon  1  cutorder
SubmitCondor    sintt          AnaMuon  1  cutorder
SubmitCondor    sinttw         AnaMuon  1  cutorder



