void make_data() {
    TFile* outputFile = new TFile("mock_data.root", "RECREATE");
    TTree* outputTree = new TTree("tree", "tree");

    bool isSignal; outputTree->Branch("isSignal", &isSignal, "isSignal/O");
    float x1, y1, z1, t1;
    outputTree->Branch("x1", &x1, "x1/f");
    outputTree->Branch("y1", &y1, "y1/f");
    outputTree->Branch("z1", &z1, "z1/f");
    outputTree->Branch("t1", &t1, "t1/f");
    float x2, y2, z2, t2;
    outputTree->Branch("x2", &x2, "x2/f");
    outputTree->Branch("y2", &y2, "y2/f");
    outputTree->Branch("z2", &z2, "z2/f");
    outputTree->Branch("t2", &t2, "t2/f");
    float energy;
    outputTree->Branch("energy", &energy, "energy/f");

    TRandom* random = new TRandom();
    random->SetSeed(0);

    for (int i = 0; i < 100000; ++i) {
        double tempRandomNumber = random->Uniform(0,1);
        if (tempRandomNumber < 0.5) {
            isSignal = true;
        } else {
            isSignal = false;
        }
        if (isSignal) {
            x1 = random->Uniform(-100, 100);
            y1 = random->Uniform(-100, 100);
            z1 = random->Uniform(-100, 100);
            t1 = 0;
            x2 = x1 + random->Gaus(0,10); 
            y2 = y1 + random->Gaus(0,10); 
            z2 = z1 + random->Gaus(0,10); 
            t2 = random->Gaus(10, 1);
            energy = random->Gaus(100,1);
        } else {
            x1 = random->Uniform(-100, 100);
            y1 = random->Uniform(-100, 100);
            z1 = random->Uniform(-100, 100);
            t1 = 0;
            x2 = random->Uniform(-100, 100);
            y2 = random->Uniform(-100, 100);
            z2 = random->Uniform(-100, 100);
            t2 = random->Uniform(0, 20);
            energy = random->Gaus(80,10);
        }
        outputTree->Fill();
    }

    outputTree->Write();
    outputFile->Close();

    exit(0);
}
