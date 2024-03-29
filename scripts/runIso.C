#include "tdrstyle.h"

TGraphAsymmErrors* plotEfficiencyReturnASYM(TString variable, TString fileName, TString outFileName, TString l1Cut, TString recoCut, TString xaxis, TString text, TString treePath, int bins, float low, float high, Color_t color, bool variableBin, int markerstyle, int inputfitparam);

void plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp(TString variable, TString DM, TString xlabel, TString tree, TString denominatorCut, TString numeratorCut1,  TString numeratorCut2, TString numeratorCut3,  TString numeratorCut4, TString numeratorCut5, TString inFile, TString outFile, int bin, float xmin, float xmax, bool variableBin);
void setTDRStyle();

void runIso(){
  //gROOT->ProcessLine(".L plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp.C");
  /*
    Please note: Concatecating and reusing strings is 'dangerous'  make sure that 
    cuts from a previous selection are not accidentally making it into you next
    selection
   */


  // variable,Rel,DM
  //     variable can be 'pt'
  //     Rel can be 'Rel',''
  //     DM can be 'allDM', '1prong', '3prong', '1prongPi0',
  //     Last two options are inFile and outFile
  TString inFile = "/afs/hep.wisc.edu/home/skkwan/public/phase2-Apr11/dyll-nom.root";
  TString outFile = "efficiency";
  TString denominatorCut = "abs(genEta)<1.6&&genPt>20&&recoPt>10&&l1Pt>0";
  TString denominatorCut1 = "";
  TString numeratorCut = "";
  TString numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5;
  TString tree = "L1MTDAnalyzer/tauTree";
  TString xlabel = "Reco #tau_{h} p_{T} [GeV]";
  int bin = 20;
  float min = 0;
  float max = 200;
  bool variableBin = true;

  denominatorCut1 = denominatorCut;
  numeratorCut1   = denominatorCut1 + "&&l1Pt>10&&abs(l1Eta)<1.6";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>10&&(l1Iso-l1Pt)/l1Pt<1";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>10&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>10&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>10&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("genPt", "allDM",     xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut  + "&&l1DecayMode==0";
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "1prong",    xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut  + "&&l1DecayMode==1";
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "1prongPi0", xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut  + "&&l1DecayMode==10";
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "3prong",    xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut;
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "allDM",     xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut  + "&&l1DecayMode==0";
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "1prong",    xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut  + "&&l1DecayMode==1";
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "1prongPi0", xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);

  denominatorCut1 = denominatorCut  + "&&l1DecayMode==10";
  numeratorCut1   = denominatorCut1 + "&&l1Pt>20";   
  numeratorCut2   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.5";   
  numeratorCut3   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.25";   
  numeratorCut4   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.15";   
  numeratorCut5   = denominatorCut1 + "&&l1Pt>20&&(l1Iso-l1Pt)/l1Pt<0.1";   
  plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp("recoPt", "3prong",    xlabel, tree, denominatorCut1, numeratorCut1, numeratorCut2, numeratorCut3, numeratorCut4, numeratorCut5, inFile, outFile, bin, min, max, variableBin);


}


void setMaxErrorTo1(TGraphAsymmErrors * hist){

  for(int i = 1; i<hist->GetN(); i++){
    Double_t errorY = hist->GetErrorY(i);
    Double_t pointx, pointy;
    if(hist->GetPoint(i,pointx,pointy)<0)
      std::cout<<"error getting point "<<std::endl;
    Double_t errorUp = pointy+errorY;
    Double_t errorLow = pointy-errorY/2;
    //std::cout<<"error Low "<< errorLow<<" errorUp "<<errorUp<< " geterrory "<< hist->GetErrorY(i)<<" geterrorx "<< hist->GetErrorX(i)<<std::endl;
    if(errorUp>1){
      //hist->SetPointEYlow(i, errorLow);
      hist->SetPointEYhigh(i, 1-pointy);
    }
  }

}


void applyPadStyle(TPad* pad1){
  pad1->SetFillColor(0);
  pad1->Draw();  pad1->cd();  pad1->SetLeftMargin(0.2);  pad1->SetBottomMargin(0.13); pad1->SetRightMargin(0.1);
  //pad1->SetGrid(); 
  pad1->SetGrid(10,10); 
}
void applyLegStyle(TLegend *leg){
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetHeader("");
  leg->SetShadowColor(0);
}

using namespace std;



//added xaxis

TGraphAsymmErrors* plotEfficiencyReturnASYM(TString variable, TString fileName, TString outFileName, TString l1Cut, TString recoCut, TString xaxis, TString text, TString treePath, int bins, float low, float high, Color_t color, bool variableBin=false, int markerstyle = 20, int inputfitparam = 88){

  std::cout<<"variable "<<variable<<" filename "<<fileName<< " outFileName "<< outFileName<<std::endl;
  std::cout<<"l1Cut "<< l1Cut<<" recoCut " << recoCut <<" xaxis "<< xaxis <<" text "<< text << " treePath "<< treePath<< " bins "<< bins<<" low "<< low << " high "<< high <<" color "<< color <<std::endl;

  setTDRStyle();
  //tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");

  TFile *tauFile    = new TFile(fileName);

  if(!tauFile->IsOpen()||tauFile==0){
    std::cout<<"ERROR FILE "<< fileName<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0);

  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);

  applyPadStyle(pad1);
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);

  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);//  Leg = new TLegend(0.74,0.65,0.99,0.95);                                                                                                                                                 

  applyLegStyle(leg);

  TTree* tauTree = (TTree*)tauFile->Get(treePath);
  if(tauTree == 0){
    std::cout<<"ERROR Tau Tree is "<< tauTree<<" NOT FOUND; EXITING"<<std::endl;
    return 0;
  }

  TH1F* Denom;
  Float_t xbins[11]= {0,5,10,15,20,25,30,35,40,55,80};
  //Float_t xbins[14]= {0,12,18,22,26,30,34,38,42,52,60,76,100,140};
  float xmax = 140;
  //Float_t xbins[17]= {0,12,18,22,26,27,28,29,31,32,34,38,42,52,60,76,100};
  //Float_t xbins[23]= {0,12,18,22,26,30,34,38,42,52,60,76,100,140,180,220,260,300,340,380,420,460,750};
  if(variableBin){
    Denom = new TH1F("Denom","Denom",10,xbins);
  }
  else
    Denom = new TH1F("Denom","Denom",bins,low,high);

  Denom->Sumw2();
  tauTree->Draw(variable+">>+Denom",recoCut);
  
  TH1F* Num;
  if(variableBin){
     Num = new TH1F("Num","Num",10,xbins);

  }
  else
    Num = new TH1F("Num","Num",bins,low,high);


  tauTree->Draw(variable+">>+Num",l1Cut);

  Num->Divide(Denom);
  gStyle->SetErrorX(0.5);

  TGraphAsymmErrors* asym = new TGraphAsymmErrors(Num);

  asym->GetXaxis()->SetTitle(xaxis);
  asym->GetYaxis()->SetTitle("L1 Efficiency ");
  asym->GetYaxis()->SetTitleOffset(0.8);

  TPaveText *pt = new TPaveText(150,.05,250,0.15);
  pt->AddText(text);
  //pt->AddText(text1.c_str());
  //pt->AddText(text2.c_str());
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetBorderSize(0);
  pt->SetShadowColor(0);
  asym->SetMarkerStyle(markerstyle);
  asym->SetMarkerColor(color);
  asym->SetMarkerSize(1.5);
  asym->Draw("P");

  pt->Draw("E");

  if(color==0){
    asym->SetLineColorAlpha(color,1);  
    asym->SetMarkerColorAlpha(color,1);
    asym->SetFillColorAlpha(color,1);
    asym->SetMarkerStyle(1);
  }
  else{
    asym->SetLineColor(color);  
    asym->SetFillColor(color);
  }
  asym->SetFillStyle(1001);
  asym->SetLineWidth(2);
  asym->SetMaximum(1.1);
  asym->SetMinimum(0);
  setMaxErrorTo1(asym);

  /* NOW fit*/
  // par[0] * arctan( x[0]*par[3] + par[1] ) + par[2]


  //asym->Fit("fitarctan","","",0, xmax + 10 );
  //asym->Fit("fitarctan","","",0, 90 );
  //asym->Fit("pol1","","",60,xmax + 10);
  gStyle->SetOptStat(0);

  Tcan->cd();
  Tcan->SaveAs(outFileName+".pdf");

  return asym;
}



void plotEfficiencyPtASYM_VersionCompIsoASYM_VersionComp(TString variable, TString DM, TString xlabel, TString tree, TString denominatorCut, TString numeratorCut1,  TString numeratorCut2, TString numeratorCut3,  TString numeratorCut4, TString numeratorCut5, TString inFile, TString outFile, int bin, float xmin, float xmax, bool variableBin){
  //#include "CMS_lumi.h"
  //#include "setTDRStyle.h"
  //#include "plotEfficiencyReturnASYM.h"

  //gROOT->LoadMacro("CMS_lumi.C");
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
  TString l1Cut   = "recoPt>10&&abs(recoEta)<1.7&&l1Pt>0";//&&abs(recoEta)<2.1&&isoTauPt>30";
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
    l1Cut   = "recoPt>10&&abs(recoEta)<1&&l1Pt>20&&(recoDM==0||recoDM==1||recoDM==10)";
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
    l1Cut   = "recoPt>10&&abs(recoEta)<1&&l1Pt>20&&recoDM==0";
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
    l1Cut   = "recoPt>20&&abs(recoEta)<1&&l1Pt>20&&recoDM==10";
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
    l1Cut   = "recoPt>10&&abs(recoEta)<1.2&&l1Pt>20&&recoDM==1";
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
    l1Cut   = "recoPt>30&&l1Pt>0";
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
    l1Cut   = "recoPt>30&&l1Pt>0&&abs(recoEta)<1.1";
  //xlabel = "Reco #tau_{h} #eta";
  //xlabel = "Reco #tau_{h} #phi";
  }
  */

  TGraphAsymmErrors* eff_pt30_NoIso    = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1Pt"+DM,            numeratorCut1, denominatorCut, xlabel, "NoIso",  tree, bin, xmin, xmax, color0, variableBin);
  TGraphAsymmErrors* eff_pt30_VLoose   = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1PtVLoose_tmp_"+DM, numeratorCut2, denominatorCut, xlabel, "VLoose", tree, bin, xmin, xmax, 0     , variableBin);
  TGraphAsymmErrors* eff_pt30_VLoose_2 = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1PtVLoose"+DM,      numeratorCut2, denominatorCut, xlabel, "VLoose", tree, bin, xmin, xmax, color1, variableBin);
  TGraphAsymmErrors* eff_pt30_Loose    = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1PtLoose"+DM,       numeratorCut3, denominatorCut, xlabel, "Loose",  tree, bin, xmin, xmax, color2, variableBin);
  TGraphAsymmErrors* eff_pt30_Medium   = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1PtMedium"+DM,      numeratorCut4, denominatorCut, xlabel, "Medium", tree, bin, xmin, xmax, color3, variableBin);
  TGraphAsymmErrors* eff_pt30_Tight    = plotEfficiencyReturnASYM(variable, inFile, outFile+"/tmp/l1PtTight"+DM,       numeratorCut5, denominatorCut, xlabel, "Tight",  tree, bin, xmin, xmax, color4, variableBin);

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

void 
CMS_lumi( TPad* pad, int iPeriod, int iPosX )
{            
TString cmsText     = "CMS";
float cmsTextFont   = 61;  // default is helvetic-bold

bool writeExtraText = false;
TString extraText   = "Preliminary";
float extraTextFont = 52;  // default is helvetica-italics

// text sizes and text offsets with respect to the top frame
// in unit of the top margin size
float lumiTextSize     = 0.6;
float lumiTextOffset   = 0.2;
float cmsTextSize      = 0.75;
float cmsTextOffset    = 0.1;  // only used in outOfFrame version

float relPosX    = 0.045;
float relPosY    = 0.035;
float relExtraDY = 1.2;

// ratio of "CMS" and extra text size
float extraOverCmsTextSize  = 0.76;

TString lumi_13TeV = "20.1 fb^{-1}";
TString lumi_8TeV  = "19.7 fb^{-1}";
TString lumi_7TeV  = "5.1 fb^{-1}";
TString lumi_sqrtS = "";

bool drawLogo      = false;


  bool outOfFrame    = false;
  if( iPosX/10==0 ) 
    {
      outOfFrame = true;
    }
  int alignY_=3;
  int alignX_=2;
  if( iPosX/10==0 ) alignX_=1;
  if( iPosX==0    ) alignX_=1;
  if( iPosX==0    ) alignY_=1;
  if( iPosX/10==1 ) alignX_=1;
  if( iPosX/10==2 ) alignX_=2;
  if( iPosX/10==3 ) alignX_=3;
  //if( iPosX == 0  ) relPosX = 0.12;
  int align_ = 10*alignX_ + alignY_;

  float H = pad->GetWh();
  float W = pad->GetWw();
  float l = pad->GetLeftMargin();
  float t = pad->GetTopMargin();
  float r = pad->GetRightMargin();
  float b = pad->GetBottomMargin();
  //  float e = 0.025;

  pad->cd();

  TString lumiText;
  if( iPeriod==1 )
    {
      lumiText += lumi_7TeV;
      lumiText += " (7 TeV)";
    }
  else if ( iPeriod==2 )
    {
      lumiText += lumi_8TeV;
      lumiText += " (8 TeV)";
    }
  else if( iPeriod==3 ) 
    {
      lumiText = lumi_8TeV; 
      lumiText += " (8 TeV)";
      lumiText += " + ";
      lumiText += lumi_7TeV;
      lumiText += " (7 TeV)";
    }
  else if ( iPeriod==4 )
    {
      lumiText += lumi_13TeV;
      lumiText += " (13 TeV)";
    }
  else if ( iPeriod==7 )
    { 
      if( outOfFrame ) lumiText += "#scale[0.85]{";
      lumiText += lumi_13TeV; 
      lumiText += " (13 TeV)";
      lumiText += " + ";
      lumiText += lumi_8TeV; 
      lumiText += " (8 TeV)";
      lumiText += " + ";
      lumiText += lumi_7TeV;
      lumiText += " (7 TeV)";
      if( outOfFrame) lumiText += "}";
    }
  else if ( iPeriod==12 )
    {
      lumiText += "8 TeV";
    }
  else if ( iPeriod==0 )
    {
      lumiText += lumi_sqrtS;
    }
   
  std::cout << lumiText << endl;

  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);    

  float extraTextSize = extraOverCmsTextSize*cmsTextSize;

  latex.SetTextFont(42);
  latex.SetTextAlign(31); 
  latex.SetTextSize(lumiTextSize*t);    
  latex.DrawLatex(1-r,1-t+lumiTextOffset*t,lumiText);

  if( outOfFrame )
    {
      latex.SetTextFont(cmsTextFont);
      latex.SetTextAlign(11); 
      latex.SetTextSize(cmsTextSize*t);    
      latex.DrawLatex(l,1-t+lumiTextOffset*t,cmsText);
    }
  
  pad->cd();

  float posX_=0;
  if( iPosX%10<=1 )
    {
      posX_ =   l + relPosX*(1-l-r);
    }
  else if( iPosX%10==2 )
    {
      posX_ =  l + 0.5*(1-l-r);
    }
  else if( iPosX%10==3 )
    {
      posX_ =  1-r - relPosX*(1-l-r);
    }
  float posY_ = 1-t - relPosY*(1-t-b);
  if( !outOfFrame )
    {
      if( drawLogo )
	{
	  posX_ =   l + 0.045*(1-l-r)*W/H;
	  posY_ = 1-t - 0.045*(1-t-b);
	  float xl_0 = posX_;
	  float yl_0 = posY_ - 0.15;
	  float xl_1 = posX_ + 0.15*H/W;
	  float yl_1 = posY_;
	  TASImage* CMS_logo = new TASImage("CMS-BW-label.png");
	  TPad* pad_logo = new TPad("logo","logo", xl_0, yl_0, xl_1, yl_1 );
	  pad_logo->Draw();
	  pad_logo->cd();
	  CMS_logo->Draw("X");
	  pad_logo->Modified();
	  pad->cd();
	}
      else
	{
	  latex.SetTextFont(cmsTextFont);
	  latex.SetTextSize(cmsTextSize*t);
	  latex.SetTextAlign(align_);
	  latex.DrawLatex(posX_, posY_, cmsText);
	  if( writeExtraText ) 
	    {
	      latex.SetTextFont(extraTextFont);
	      latex.SetTextAlign(align_);
	      latex.SetTextSize(extraTextSize*t);
	      latex.DrawLatex(posX_, posY_- relExtraDY*cmsTextSize*t, extraText);
	    }
	}
    }
  else if( writeExtraText )
    {
      if( iPosX==0) 
	{
	  posX_ =   l +  relPosX*(1-l-r);
	  posY_ =   1-t+lumiTextOffset*t;
	}
      latex.SetTextFont(extraTextFont);
      latex.SetTextSize(extraTextSize*t);
      latex.SetTextAlign(align_);
      latex.DrawLatex(posX_, posY_, extraText);      
    }
  return;
}


void setTDRStyle() {

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

// For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

// For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

// For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
//  tdrStyle->SetErrorMarker(20);
  tdrStyle->SetErrorX(0.1);
  
  tdrStyle->SetMarkerStyle(20);

//For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

//For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

// Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.16);
  tdrStyle->SetPadRightMargin(0.02);

// For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

// For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  //tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.25);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

// For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

// Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

// Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();

}
