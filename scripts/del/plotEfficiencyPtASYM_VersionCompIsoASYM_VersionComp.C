#include "TStyle.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TF1.h"
#include <math.h>
#include <TEfficiency.h>
#include <TMath.h>
#include <TFormula.h>
#include <iostream>
#include <string>

#include <iostream>
#include <cmath>
#include "TLegend.h"
#include "TPad.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2.h"
#include "TF1.h"
#include "THStack.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TPaveText.h"
//#include "tdrstyle.C"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TGraphAsymmErrors.h"

void plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp(TString variable, TString DM, TString xlabel, TString tree, TString denominatorCut, TString numeratorCut1,  TString numeratorCut2, TString numeratorCut3,  TString numeratorCut4, TString numeratorCut5, TString inFile, TString outFile, int bin, float xmin, float xmax){
  #include "CMS_lumi.h"
  #include "setTDRStyle.h"
  #include "plotEfficiencyReturnASYM.h"

  bool variableBin = false;
  gROOT->LoadMacro("CMS_lumi.C");
  //gROOT->LoadMacro("tdrstyle.C");
  //gROOT->ProcessLine(".L tdrstyle.C");
  //gROOT->ProcessLine(".L plotEfficiencyReturnASYM.C");
  setTDRStyle();

  TFile *tauFile    = new TFile("dummy");
  TCanvas *Tcan2= new TCanvas("Tcan2","",100,20,800,600); Tcan2->cd();  Tcan2->SetFillColor(0);
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);
  applyPadStyle(pad1);

  TLegend *leg = new TLegend(0.60,0.21,0.87,0.44);
  applyLegStyle(leg);

  //withIsolation
  TString recoCut = "recoPt>10&&abs(recoEta)<1.7";//&&abs(recoEta)<2.1";
  TString l1Cut   = "recoPt>10&&abs(recoEta)<1.7&&l1TauPt>0";//&&abs(recoEta)<2.1&&isoTauPt>30";
  TString file;
  TString optA = "L1 ";
  file="phase2-trigger-Oct-26/L1TauAnalyzer.root";

  Int_t color0 = TColor::GetColor("#C65D00"); //dark Orange
  Int_t color1 = TColor::GetColor("#283593"); //dark blue
  Int_t color2 = TColor::GetColor("#0288D1"); //medium blue

  Int_t color3 = TColor::GetColor("#00695C"); //green blue
  Int_t color4 = TColor::GetColor("#660066"); //Purple

  //TString inputVariable = "pt";//l1TauEta,eta,pt, phi
  //TString DM = "1prong";//1prong,allDM,3prong,1prongPi0

  //if(inputVariable!="pt"){
  //std::cout<<"InputVariable "<< inputVariable<<" not found!! Exiting...."<<std::endl;
  //exit(0);
  //}

  if(DM!="1prong"&&DM!="1prongPi0"&&DM!="3prong"&&DM!="allDM"){
    std::cout<<"Decay Mode "<< DM<<" not found!! Exiting...."<<std::endl;
    exit(0);
  }

  float ymax = 1.2;
  /*
  if(inputVariable=="pt"&&DM=="allDM"){
    variableBin=true;
    DM="allDM";
    variable = "recoPt";
    bin = 20;
    xmin = 0;
    xmax = 80; 
    xlabel = "Reco #tau_{h} p_{T} [GeV]";
    recoCut = "recoPt>10&&abs(recoEta)<1&&(recoDM==0||recoDM==1||recoDM==10)";
    l1Cut   = "recoPt>10&&abs(recoEta)<1&&l1TauPt>20&&(recoDM==0||recoDM==1||recoDM==10)";
  //xlabel = "Reco #tau_{h} #eta";
  //xlabel = "Reco #tau_{h} #phi";
  }

  if(inputVariable=="pt"&&DM=="1prong"){
    variableBin=true;
    variable = "recoPt";
    bin = 10;
    xmin = 0;
    xmax = 80; 
    xlabel = "Gen Visible #tau_{h} p_{T} [GeV]";
    xlabel = "Reco #tau_{h} p_{T} [GeV]";
    recoCut = "recoPt>10&&abs(recoEta)<1&&recoDM==0";
    l1Cut   = "recoPt>10&&abs(recoEta)<1&&l1TauPt>20&&recoDM==0";
  }

  if(inputVariable=="pt"&&DM=="3prong"){
    variable = "recoPt";
    variableBin=true;
    bin = 10;
    xmin = 0;
    xmax = 150; 
    xmax = 80; 
    xlabel = "Gen Visible #tau_{h} p_{T} [GeV]";
    xlabel = "Reco #tau_{h} p_{T} [GeV]";
    recoCut = "recoPt>20&&abs(recoEta)<1&&recoDM==10";
    l1Cut   = "recoPt>20&&abs(recoEta)<1&&l1TauPt>20&&recoDM==10";
  //xlabel = "Reco #tau_{h} #eta";
  //xlabel = "Reco #tau_{h} #phi";
  }


  if(inputVariable=="pt"&&DM=="1prongPi0"){
    variableBin=true;
    variable = "recoPt";
    variableBin=true;
    bin = 10;
    xmin = 0;
    xmax = 150; 
    xmax = 80; 
    xlabel = "Gen Visible #tau_{h} p_{T} [GeV]";
    xlabel = "Reco #tau_{h} p_{T} [GeV]";
    recoCut = "recoPt>10&&abs(recoEta)<1.2&&recoDM==1";
    l1Cut   = "recoPt>10&&abs(recoEta)<1.2&&l1TauPt>20&&recoDM==1";
  //xlabel = "Reco #tau_{h} #eta";
  //xlabel = "Reco #tau_{h} #phi";
  }


  if(inputVariable=="eta"&&DM=="allDM"){
    variable = "recoEta";
    bin = 10;
    xmin = -3;
    xmax = 3; 
    xlabel = "Reco #tau_{h} #eta";
    recoCut = "recoPt>30";
    l1Cut   = "recoPt>30&&l1TauPt>0";
  //xlabel = "Reco #tau_{h} #eta";
  //xlabel = "Reco #tau_{h} #phi";
  }

  if(inputVariable=="phi"&&DM=="allDM"){
    variable = "recoPhi";
    bin = 20;
    xmin = -3;
    xmax = 3; 
    xlabel = "Reco #tau_{h} #phi";
    recoCut = "recoPt>30&&abs(recoEta)<1.1";
    l1Cut   = "recoPt>30&&l1TauPt>0&&abs(recoEta)<1.1";
  //xlabel = "Reco #tau_{h} #eta";
  //xlabel = "Reco #tau_{h} #phi";
  }
  */

  TGraphAsymmErrors* eff_pt30_NoIso    = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1TauPt"+DM,            numeratorCut1, denominatorCut, xlabel, "NoIso",  tree, bin, xmin, xmax, color0, variableBin);
  TGraphAsymmErrors* eff_pt30_VLoose   = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1TauPtVLoose_tmp_"+DM, numeratorCut2, denominatorCut, xlabel, "VLoose", tree, bin, xmin, xmax, 0     , variableBin);
  TGraphAsymmErrors* eff_pt30_VLoose_2 = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1TauPtVLoose"+DM,      numeratorCut2, denominatorCut, xlabel, "VLoose", tree, bin, xmin, xmax, color1, variableBin);
  TGraphAsymmErrors* eff_pt30_Loose    = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1TauPtLoose"+DM,       numeratorCut3, denominatorCut, xlabel, "Loose",  tree, bin, xmin, xmax, color2, variableBin);
  TGraphAsymmErrors* eff_pt30_Medium   = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1TauPtMedium"+DM,      numeratorCut4, denominatorCut, xlabel, "Medium", tree, bin, xmin, xmax, color3, variableBin);
  TGraphAsymmErrors* eff_pt30_Tight    = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1TauPtTight"+DM,       numeratorCut5, denominatorCut, xlabel, "Tight",  tree, bin, xmin, xmax, color4, variableBin);

  Tcan2->cd();
  pad1->cd();
  pad1->SetGrid(5,5); 

  eff_pt30_VLoose->Draw();
  eff_pt30_NoIso->Draw("p");
  eff_pt30_Tight->Draw("p");
  eff_pt30_Medium->Draw("p");
  eff_pt30_Loose->Draw("p");
  eff_pt30_VLoose_2->Draw("p");

  eff_pt30_VLoose->SetMaximum(ymax);

  //leg->SetHeader("     1 prong Gen-Level Tau-Track Matching");
  leg->AddEntry(eff_pt30_NoIso,    "#bf{"+DM+"}","pe");
  leg->AddEntry(eff_pt30_VLoose_2, "#bf{"+DM+" VLoose}","pe");
  leg->AddEntry(eff_pt30_Loose,    "#bf{"+DM+" Loose}","pe");
  leg->AddEntry(eff_pt30_Medium,   "#bf{"+DM+" Medium}","pe");
  leg->AddEntry(eff_pt30_Tight,    "#bf{"+DM+" Tight}","pe");
  leg->SetFillColor(kWhite);
  leg->SetFillStyle(1001);  
  leg->SetMargin(0.1);
  leg->Draw();

  TPaveText *pt = new TPaveText(4,.95,40,1.05);
  pt->AddText("#splitline{CMS}{#bf{#it{Preliminary}}}");
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  //pt->Draw("E");

  eff_pt30_VLoose->GetXaxis()->SetRangeUser(0,eff_pt30_VLoose->GetXaxis()->GetXmax()-10);


  Tcan2->SaveAs(outFile+"/recoTau-"+variable+"_"+DM+".png");
  Tcan2->SaveAs(outFile+"/recoTau-"+variable+"_"+DM+".pdf");


}
