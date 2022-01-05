TH2F *hUnifiedZY = new TH2F("unified ZY view", "sfgd+usj ZY view; Z position [cm];Y position [cm]; Hit charge [pe]", 48+112+32, 0, 48+112+32, 24, -8, 16);
TH2F *hUnifiedZX = new TH2F("unified ZX view", "sfgd+usj ZX view; Z position [cm];X position [cm]; Hit charge [pe]", 48+112+32, 0, 48+112+32, 24, 0, 24);

void display() {
    TLine* zy1 = new TLine(48,0, 48,8);
    TLine* zy2 = new TLine(0,0, 48,0);
    TLine* zy3 = new TLine(0,8, 48,8);
    TLine* zy4 = new TLine(48+112,0, 48+112,8);
    TLine* zy5 = new TLine(48+112,0, 48+112+32,0);
    TLine* zy6 = new TLine(48+112,8, 48+112+32,8);
    TArrow* zyArrow1 = new TArrow(0,4, 48+112+32,4, 0.01, "|>");
    zyArrow1->SetLineColor(2);
    zyArrow1->SetFillColor(2);
    TText* zyText1 = new TText(-10, 3.5, "beam");
    TText* zyText2 = new TText(20, 9, "sfgd");
    TText* zyText3 = new TText(48+112+16, 9, "usj");

    TLine* zx1 = new TLine(48,0, 48,24);
    TLine* zx2 = new TLine(48+112,16, 48+112+32,16);
    TLine* zx3 = new TLine(48+112,8, 48+112+32,8);
    TLine* zx4 = new TLine(48+112,8, 48+112,16);
    TArrow* zxArrow1 = new TArrow(0,12, 48+112+32,12, 0.01, "|>");
    zxArrow1->SetLineColor(2);
    zxArrow1->SetFillColor(2);
    TText* zxText1 = new TText(-10, 11.5, "beam");
    TText* zxText2 = new TText(20, 23, "sfgd");
    TText* zxText3 = new TText(48+112+16, 17, "usj");

    TFile* inputFile = new TFile("MC_neutron.root", "READ");
    TTree* inputTree = (TTree*)inputFile->Get("tree");

    float neutronHitX[1000] = {}; inputTree->SetBranchAddress("neutronHitX", &neutronHitX);
    float neutronHitY[1000] = {}; inputTree->SetBranchAddress("neutronHitY", &neutronHitY);
    float neutronHitZ[1000] = {}; inputTree->SetBranchAddress("neutronHitZ", &neutronHitZ);
    float neutronHitE[1000] = {}; inputTree->SetBranchAddress("neutronHitE", &neutronHitE);

    for (int event = 0; event < inputTree->GetEntries(); ++event) {
        inputTree->GetEntry(event);
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "event: " << event << std::endl;

        for (int hitLoop = 0; hitLoop < 1000; ++hitLoop) {
            if (neutronHitX[hitLoop] == 0) continue;
            std::cout << "hit: " << neutronHitX[hitLoop] << ", " << neutronHitY[hitLoop] << ", " << neutronHitZ[hitLoop] << std::endl;
                hUnifiedZY->Fill(neutronHitZ[hitLoop]+24, neutronHitY[hitLoop]+4, neutronHitE[hitLoop]);
                hUnifiedZX->Fill(neutronHitZ[hitLoop]+24, neutronHitX[hitLoop]+12, neutronHitE[hitLoop]);
        }

        auto unifiedCan = std::make_unique<TCanvas> ("unifiedCan", "unifiedCan", 1600, 900);
        unifiedCan->Divide(1,2);
        unifiedCan->cd(1);
        hUnifiedZY->SetStats(0);
        hUnifiedZY->Draw("colz");
        zy1->Draw();
        zy2->Draw("same");
        zy3->Draw("same");
        zy4->Draw("same");
        zy5->Draw("same");
        zy6->Draw("same");
        zyArrow1->Draw();
        zyText1->Draw();
        zyText2->Draw("same");
        zyText3->Draw("same");

        unifiedCan->cd(2);
        hUnifiedZX->SetStats(0);
        hUnifiedZX->Draw("colz");
        zx1->Draw();
        zx2->Draw("same");
        zx3->Draw("same");
        zx4->Draw("same");
        zxArrow1->Draw();
        zxText1->Draw();
        zxText2->Draw("same");
        zxText3->Draw("same");

        unifiedCan->Update();
        unifiedCan->WaitPrimitive();
        hUnifiedZX->Reset();
        hUnifiedZY->Reset();
    }
}
