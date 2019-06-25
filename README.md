# README.md

This repo contains scripts to plot efficiencies. It is in development.

## runIso.C

The important functions are:

1. ```TGraphAsymmErrors* plotEfficiencyReturnASYM(TString variable, TString fileName, TString outFileName, TString l1Cut, TString recoCut, TString xaxis, TString text, TString treePath, int bins, float low, float high, Color_t color, bool variableBin=false, int markerstyle = 20, int inputfitparam = 88)``` 

(line 142). Some comments on the parameters:
  - `l1Cut` is the numeratorCut. `recoCut` is the denominator cut.
  - `text` is currently varied among "NoIso", "VLoose", "Loose", "Medium", or "Tight" (no requirement on isolation coefficient, then < 1, < 0.25, < 0.15, and < 0.1). 

1. ```void plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp(TString variable, TString DM, TString xlabel, TString tree, TString denominatorCut, TString numeratorCut1,  TString numeratorCut2, TString numeratorCut3,  TString numeratorCut4, TString numeratorCut5, TString inFile, TString outFile, int bin, float xmin, float xmax, bool variableBin)```

which takes the parameters:
 - `variable`, e.g. `pT`
 - `DM`: decay mode. 'allDM', '1prong', '1prongPi0', or '3prong'.
 - `xlabel`: label for the x-axis. e.g. "Reco #tau_{h} p_{T} [GeV]".
 - `tree`: directory/name of the tree in the ROOT file. e.g. `L1MTDAnalyzer/tauTree`.
 - `denominatorCut`: The baseline cut of variables to be applied to the denominator of the efficiency. e;.g. `abs(genEta)<1.6 && genPt>20 && recoPt>10 && l1Pt>0`. (pT above a certain threshold is a common cut for objects)
 - `numeratorCut`: The cut of variables, in addition to `denominatorCut`, to use in the numerator of the efficiency (this is the cut-based selection).
  - `bin` is passed to the `bins` argument `plotEfficiencyReturnASYM`.
  - `variableBin` is `True`/`False` and is passed to `plotEfficiencyReturnASYM`: if `True`, `Num = new TH1F("Num","Num",10,xbins);`, if `False`, `Num = new TH1F("Num","Num",bins,low,high);`. (Gives option to define custom binning?)
 
1. The `runIso()` function calls `plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp` once for each decay mode: the denominator cut consists of `denominatorCut` and the decay mode. For all-DM, the `numeratorCut` requires `l1Pt > 10` always, and then varies the max value of an isolation coefficient. For specific decay modes, the `numeratorCut` requires `l1Pt >20`, and then also varies the max value of an isolation coefficient.


