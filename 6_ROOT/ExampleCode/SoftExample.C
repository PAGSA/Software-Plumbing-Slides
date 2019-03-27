#define SoftExample_cxx
#include "SoftExample.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <iostream>

void SoftExample::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L SoftExample.C
//      Root > SoftExample t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   	if (fChain == 0) return;

   	Long64_t nentries = fChain->GetEntriesFast();
   	Long64_t nbytes = 0, nb = 0;
	TGraph *corr = new TGraph();     //Graph of gaus vs gaus2
	TGraph *offset = new TGraph();	 //Same graph but with entries from different events
	TH1F *times = new TH1F("times","time modulo 2",2,0,2); //histogram of the time modulo 2
   	for (Long64_t jentry=0; jentry<nentries;jentry++) 
	{
		Long64_t ientry = LoadTree(jentry);
      		if (ientry < 0) break;
      		nb = fChain->GetEntry(jentry);   nbytes += nb;
		

		times->Fill(time%2); 
		corr->SetPoint(jentry,gaus,gaus2);
		/*
 		INSERT OFFSET CODE HERE
  		*/
	}
	
	TFile *fout = new TFile("CorrPlots.root","RECREATE");
	corr->Write();
	offset->Write();
	times->Write();
	fout->Close();	
}
