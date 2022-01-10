# CANU

## root파일 여는법

    root filename.root
    
## root console에서 파일 내용물 확인

    .ls
    
ex)

    root [1] .ls
    TFile**		mock_data.root
     TFile*		mock_data.root
      KEY: TTree	tree;1	tree
    
또는
    
    new TBrowser()
    
## TTree 변수 확인, tree는 TTree이름

    tree->Print()
    
ex)

    root [1] tree->Print()
    ******************************************************************************
    *Tree    :tree      : tree                                                   *
    *Entries :   100000 : Total =         2811854 bytes  File  Size =    1895866 *
    *        :          : Tree compression factor =   1.48                       *
    ******************************************************************************
    *Br    0 :isSignal  : isSignal/O                                             *
    *Entries :   100000 : Total  Size=     100791 bytes  File Size  =      22771 *
    *Baskets :        4 : Basket Size=      32000 bytes  Compression=   4.40     *
    *............................................................................*
    *Br    1 :x1        : x1/f                                                   *
    *Entries :   100000 : Total  Size=     301182 bytes  File Size  =     242109 *
    *Baskets :       10 : Basket Size=      32000 bytes  Compression=   1.24     *
    *............................................................................*
    
