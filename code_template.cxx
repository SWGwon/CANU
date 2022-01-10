//void 파일이름.cxx로 사용
void code_template() {
    //input.root 에 root 파일명 
    TFile* inputFile = new TFile("mock_data.root", "READ");
    //root 파일 구조:
    //******************************************************************************
    //*Tree    :tree      : tree                                                   *
    //*Entries :   100000 : Total =         2811854 bytes  File  Size =    1895866 *
    //*        :          : Tree compression factor =   1.48                       *
    //******************************************************************************
    //*Br    0 :isSignal  : isSignal/O                                             *
    //*Entries :   100000 : Total  Size=     100791 bytes  File Size  =      22771 *
    //*Baskets :        4 : Basket Size=      32000 bytes  Compression=   4.40     *
    //*............................................................................*
    //*Br    1 :x1        : x1/f                                                   *
    //*Entries :   100000 : Total  Size=     301182 bytes  File Size  =     242109 *
    //*Baskets :       10 : Basket Size=      32000 bytes  Compression=   1.24     *
    //*............................................................................*
    //tree에 root 파일 안에 있는 Tree이름 사용
    TTree* inputTree = (TTree*)inputFile->Get("tree");

    //a는 이 코드에서 사용할 변수이름 
    //variable은 root 파일 안에 있는 Tree안의 변수 이름
    //float은 그 Tree 안의 변수의 데이터 타입 ex) x1/f = float
    float a; inputTree->SetBranchAddress("x1", &a);

    //TH1D* hist = new TH1D("asdf", 
    //        "histogram title;x title;y title",
    //        100, bin개수
    //        0, minimum
    //        0);  maximum
    TH1D* hist = new TH1D("asdf", "histogram title;x title;y title", 100, 0, 0); 


    for (int i = 0; i < inputTree->GetEntries(); ++i) {
        //i번째 entry를 불러옴
        inputTree->GetEntry(i);
        std::cout << "event: " << i << std::endl;

        std::cout << "x1: " << a << std::endl;
        hist->Fill(a);
    }

    TCanvas* can = new TCanvas();
    hist->Draw();
}
